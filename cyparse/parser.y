%{
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

extern int current_line;
extern int current_char;
extern FILE *out_debug;
void yyerror(char *s, ...)
{
    fprintf(stderr, "Parse ERROR line %d (%d): %s\n", current_line, current_char, s);
}

%}

%token <str> LITERAL_INTEGER
%token <str> LITERAL_FLOAT
%token <str> LITERAL_STRING

%token <str> LITERAL_ASSEMBLY

%token <str> TOK_IDENTIFIER

%token <str> TOK_IF
%token <str> TOK_ELSE
%token <str> TOK_SWITCH
%token <str> TOK_CASE
%token <str> TOK_WHILE
%token <str> TOK_DO
%token <str> TOK_FOR
%token <str> TOK_ASM

%token <str> TOK_CHAR
%token <str> TOK_BYTE
%token <str> TOK_SHORT
%token <str> TOK_INT
%token <str> TOK_LONG
%token <str> TOK_FLOAT
%token <str> TOK_DOUBLE
%token <str> TOK_STRING
%token <str> TOK_VOID

%token <str> TOK_RETURN

%token <str> TOK_ASSIGN

%token <str> TOK_ADD_ASSIGN
%token <str> TOK_SUB_ASSIGN
%token <str> TOK_MUL_ASSIGN
%token <str> TOK_DIV_ASSIGN
%token <str> TOK_MOD_ASSIGN
%token <str> TOK_AND_ASSIGN
%token <str> TOK_OR_ASSIGN
%token <str> TOK_XOR_ASSIGN
%token <str> TOK_LEFT_ASSIGN
%token <str> TOK_RIGHT_ASSIGN

%token <str> TOK_INC
%token <str> TOK_DEC

%token <str> TOK_EQ
%token <str> TOK_NEQ
%token <str> TOK_LT
%token <str> TOK_LTE
%token <str> TOK_GT
%token <str> TOK_GTE

%token <str> TOK_AND
%token <str> TOK_OR

%token <str> TOK_LEFT
%token <str> TOK_RIGHT

%union {int num; char* str; N_expr *expr; N_arg *arg; N_stm *stm; N_stm_compound *stm_compound; N_arg_def *argdef;};

%nonassoc IFX
%nonassoc TOK_ELSE

%type <str> type_specifier
%type <str> type_primary

%type <expr> expr_primary
%type <expr> expr_postfix
%type <expr> expr_unary
%type <expr> expr_mul
%type <expr> expr_add
%type <expr> expr_shift
%type <expr> expr_comparison
%type <expr> expr_equal
%type <expr> expr_bitwise_and
%type <expr> expr_bitwise_xor
%type <expr> expr_bitwise_or
%type <expr> expr_logical_and
%type <expr> expr_logical_or
%type <expr> expr_conditional
%type <expr> expr_assign
%type <expr> expression

%type <arg> argument_list

%type <stm> statement
%type <stm> stm_compound
%type <stm> stm_expr
%type <stm> stm_if
%type <stm> stm_do
%type <stm> stm_for
%type <stm> stm_while
%type <stm> declaration
%type <stm> error
%type <stm> stm_return
%type <stm> stm_asm

%type <stm_compound> stm_list

%%

program
    : program statement {printf(",\n"); do_stm($2);}
    | statement    {do_stm($1);}
    ;

stm_if
    : TOK_IF '(' expression ')' statement %prec IFX                {$$ = new_stm_if($3, $5, NULL);}
    | TOK_IF '(' expression ')' statement TOK_ELSE statement       {$$ = new_stm_if($3, $5, $7);}
    
stm_while
    : TOK_WHILE '(' expression ')' statement                       {$$ = new_stm_while($3, $5);}
    ;
    
stm_do
    : TOK_DO statement TOK_WHILE '(' expression ')' ';'            {$$ = new_stm_do($5, $2);}
    ;
    
stm_for
    : TOK_FOR '(' stm_expr stm_expr expression ')' statement       {$$ = new_stm_for($3, $4, $5, $7);}
    ;

stm_compound
    : '{' stm_list '}'                                             {$$ = new_stm_compound($2);}
    ;

stm_list
    : statement                                {$$ = new_stm_compound_pure($1);}
    | stm_list statement                       {
                                                   N_stm_compound* current = $1;
                                                   while (current->next)
                                                       current = current->next;
                                                   current->next = new_stm_compound_pure($2);
                                                   $$ = $1;
                                               }
    ;

stm_expr
    : ';'                                      {$$ = new_stm_nop();}
    | expression ';'                           {$$ = new_stm_expr($1);}
    ;
    
stm_return
    : TOK_RETURN expression ';'                {$$ = new_stm_return($2);}
    | TOK_RETURN ';'                           {$$ = new_stm_return(NULL);}
    ;

stm_asm
    : TOK_ASM LITERAL_ASSEMBLY                 {$$ = new_stm_asm($2);}

statement
    : stm_compound
    | stm_expr
    | stm_if
    | stm_do
    | stm_for
    | stm_while
    | stm_return
    | stm_asm
    | declaration
    | error ';'
    | error '}'
    ;

declaration
    : type_specifier TOK_IDENTIFIER ';'                                           {$$ = new_stm_decl($1, $2, NULL, NULL);}
    | type_specifier TOK_IDENTIFIER '(' ')' statement                             {$$ = new_stm_decl($1, $2, $5, NULL);}
    | type_specifier TOK_IDENTIFIER '(' TOK_VOID ')' statement                    {$$ = new_stm_decl($1, $2, $6, NULL);}
    | type_specifier TOK_IDENTIFIER '(' argument_definition_list ')' statement    {$$ = new_stm_decl($1, $2, $6, $<argdef>4);}
    ;

argument_definition_list
    : type_specifier TOK_IDENTIFIER                                 {$<argdef>$ = new_arg_def($2, $1);}
    | argument_definition_list ',' type_specifier TOK_IDENTIFIER    {
                                                                        N_arg_def* current;
                                                                        current = $<argdef>1;
                                                                        while (current->next != NULL)
                                                                        {
                                                                            current = current->next;
                                                                        }
                                                                        current->next = new_arg_def($4, $3);
                                                                        $<argdef>$ = $<argdef>1;
                                                                    }
    ;

type_specifier
    : type_primary
    | type_specifier '<' LITERAL_INTEGER '>'
    | TOK_VOID
    ;

type_primary
    : TOK_BYTE                                 {$$ = $1;}
    | TOK_SHORT                                {$$ = $1;}
    | TOK_INT                                  {$$ = $1;}
    | TOK_LONG                                 {$$ = $1;}
    | TOK_FLOAT                                {$$ = $1;}
    | TOK_DOUBLE                               {$$ = $1;}
    ;

expr_primary
    : LITERAL_INTEGER                           {$$ = new_val_int(atoi($1));}
    | LITERAL_FLOAT                             {$$ = new_val_float(atof($1));}
    | LITERAL_STRING                            {$$ = new_val_string($1);}
    | TOK_IDENTIFIER                            {$$ = new_val_id($1);}
    | '(' expression ')'                        {$$ = $2;}
    ;

argument_list
    : expression                                {$$ = new_arg($1);}
    | argument_list ',' expression    {
        N_arg* current = $1;
        while (current->next != NULL)
            current = current->next;
        current->next = new_arg($3);
        $$ = $1;
        }
    ;
    
expr_postfix
    : expr_primary
    | expr_postfix '[' expression ']'            {$$ = new_op2(current_line, current_char, OP_ARRAY, $1, $3);}
    | expr_postfix '(' argument_list ')'         {$$ = new_op_call($1); ((N_OP_Call*)$$->node)->args = $3;}
    | expr_postfix '(' ')'                       {$$ = new_op_call($1);}
    | expr_postfix '.' TOK_IDENTIFIER            {$$ = new_op2(current_line, current_char, OP_DOT, $1, $<expr>3);}
    | expr_postfix TOK_INC                       {$$ = new_op1(current_line, current_char, OP_POST_INC, $1);}
    | expr_postfix TOK_DEC                       {$$ = new_op1(current_line, current_char, OP_POST_DEC, $1);}
    ;
    
expr_unary
    : expr_postfix
    | TOK_INC expr_unary                         {$$ = new_op1(current_line, current_char, OP_PRE_INC, $2);}
    | TOK_DEC expr_unary                         {$$ = new_op1(current_line, current_char, OP_PRE_DEC, $2);}
    | '+'     expr_unary                         {$$ = new_op1(current_line, current_char, OP_POS, $2);}
    | '-'     expr_unary                         {$$ = new_op1(current_line, current_char, OP_NEG, $2);}
    | '~'     expr_unary                         {$$ = new_op1(current_line, current_char, OP_B_NOT, $2);}
    | '!'     expr_unary                         {$$ = new_op1(current_line, current_char, OP_NOT, $2);}
    ;

expr_mul
    : expr_unary
    | expr_mul '*' expr_unary                    {$$ = new_op2(current_line, current_char, OP_MUL, $1, $3);}
    | expr_mul '/' expr_unary                    {$$ = new_op2(current_line, current_char, OP_DIV, $1, $3);}
    | expr_mul '%' expr_unary                    {$$ = new_op2(current_line, current_char, OP_MOD, $1, $3);}
    ;

expr_add
    : expr_mul
    | expr_add '+' expr_mul                      {$$ = new_op2(current_line, current_char, OP_ADD, $1, $3);}
    | expr_add '-' expr_mul                      {$$ = new_op2(current_line, current_char, OP_SUB, $1, $3);}
    ;

expr_shift
    : expr_add
    | expr_shift TOK_LEFT  expr_add              {$$ = new_op2(current_line, current_char, OP_LEFT, $1, $3);}
    | expr_shift TOK_RIGHT expr_add              {$$ = new_op2(current_line, current_char, OP_RIGHT, $1, $3);}
    ;
    
expr_comparison
    : expr_shift
    | expr_comparison TOK_LT  expr_shift         {$$ = new_op2(current_line, current_char, OP_LT, $1, $3);}
    | expr_comparison TOK_LTE expr_shift         {$$ = new_op2(current_line, current_char, OP_LTE, $1, $3);}
    | expr_comparison TOK_GT  expr_shift         {$$ = new_op2(current_line, current_char, OP_GT, $1, $3);}
    | expr_comparison TOK_GTE expr_shift         {$$ = new_op2(current_line, current_char, OP_GTE, $1, $3);}
    ;
    
expr_equal
    : expr_comparison
    | expr_equal TOK_EQ  expr_comparison         {$$ = new_op2(current_line, current_char, OP_EQ, $1, $3);}
    | expr_equal TOK_NEQ expr_comparison         {$$ = new_op2(current_line, current_char, OP_NEQ, $1, $3);}
    ;
    
expr_bitwise_and
    : expr_equal
    | expr_bitwise_and '&' expr_equal            {$$ = new_op2(current_line, current_char, OP_B_AND, $1, $3);}
    ;
    
expr_bitwise_xor
    : expr_bitwise_and
    | expr_bitwise_xor '^' expr_bitwise_and      {$$ = new_op2(current_line, current_char, OP_B_XOR, $1, $3);}
    ;
    
expr_bitwise_or
    : expr_bitwise_xor
    | expr_bitwise_or '|' expr_bitwise_xor       {$$ = new_op2(current_line, current_char, OP_B_OR, $1, $3);}
    ;
    
expr_logical_and
    : expr_bitwise_or
    | expr_logical_and TOK_AND expr_bitwise_or   {$$ = new_op2(current_line, current_char, OP_AND, $1, $3);}
    ;
    
expr_logical_or
    : expr_logical_and
    | expr_logical_or TOK_OR expr_logical_and    {$$ = new_op2(current_line, current_char, OP_OR, $1, $3);}
    ;
    
expr_conditional
    : expr_logical_or
    | expr_logical_or '?' expression ':' expr_conditional    {$$ = new_op3($1, $3, $5);}
    ;
    
expr_assign
    : expr_conditional
    | expr_unary TOK_ASSIGN       expr_assign    {$$ = new_op2(current_line, current_char, OP_ASSIGN, $1, $3);}
    | expr_unary TOK_ADD_ASSIGN   expr_assign    {$$ = new_op2(current_line, current_char, OP_ADD_ASSIGN, $1, $3);}
    | expr_unary TOK_SUB_ASSIGN   expr_assign    {$$ = new_op2(current_line, current_char, OP_SUB_ASSIGN, $1, $3);}
    | expr_unary TOK_MUL_ASSIGN   expr_assign    {$$ = new_op2(current_line, current_char, OP_MUL_ASSIGN, $1, $3);}
    | expr_unary TOK_DIV_ASSIGN   expr_assign    {$$ = new_op2(current_line, current_char, OP_DIV_ASSIGN, $1, $3);}
    | expr_unary TOK_MOD_ASSIGN   expr_assign    {$$ = new_op2(current_line, current_char, OP_MOD_ASSIGN, $1, $3);}
    | expr_unary TOK_AND_ASSIGN   expr_assign    {$$ = new_op2(current_line, current_char, OP_AND_ASSIGN, $1, $3);}
    | expr_unary TOK_OR_ASSIGN    expr_assign    {$$ = new_op2(current_line, current_char, OP_OR_ASSIGN, $1, $3);}
    | expr_unary TOK_XOR_ASSIGN   expr_assign    {$$ = new_op2(current_line, current_char, OP_XOR_ASSIGN, $1, $3);}
    | expr_unary TOK_LEFT_ASSIGN  expr_assign    {$$ = new_op2(current_line, current_char, OP_LEFT_ASSIGN, $1, $3);}
    | expr_unary TOK_RIGHT_ASSIGN expr_assign    {$$ = new_op2(current_line, current_char, OP_RIGHT_ASSIGN, $1, $3);}
    ;
    
expression
    : expr_assign
    ;

%%

int main()
{
    out_debug = fopen("/dev/null", "rw");
    printf("[");
    yyparse();
    printf("]\n");
    return 0;
}
