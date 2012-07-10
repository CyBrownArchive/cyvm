/*

## TYPES:
N_E_OP2
N_E_OP1
N_E_INT
N_E_STRING
N_E_CALL
N_E_IDENTIFIER
N_E_CLASS
N_E_OBJECT
N_E_NAMESPACE

N_S_EXPR
N_S_COMPOUND
N_S_IF
N_S_SWITCH
N_S_FOR
N_S_WHILE
N_S_DO


## expression
operator (type, which operator, left operand, right operand)
identifier (type, name)
function call (type, function id, argument count, argument value)
literral value (type, value)

## statements
STM_NOOP:     ;
STM_EXPR:     expression;
STM_COMPOUND: {S_statement S_Statement ...}

STM_IF:       if (E_condition) S_statement
              else if (E_condition) S_statement
              else S_statement
STM_SWITCH:   switch (E_value) { case CONSTANT: S_statement case CONSTANT: S_statement ... default: S_statement}

STM_FOR:      for (E_init; E_condition; E_each iteration) S_statement
STM_FOREACH:  foreach (E_iterable: var_name) S_statement
STM_WHILE:    while (E_condition) S_statement
STM_DO:       do S_statement while(E_condition);

## declarations
DECL_NAME:    namespace (name)
DECL_VAR:     variable (name, type, flags)
DECL_CLASS:   class (name, class_definition)
DECL_FUNC:    function (name, func_definition)
DECL_ARRAY:   array (size, content type)
DECL_MAP:     map (size, content type)

*/

/* Operations */

/* EXPRESSION Structures */

/* Value */
#define V_CHAR 401
#define V_BYTE 402
#define V_SHORT 403
#define V_INT 404
#define V_LONG 405
#define V_FLOAT 406
#define V_DOUBLE 407
#define V_STR 408
#define V_ID 409
typedef struct {
	int type;
	union {
		char Char;
		char Byte;
		short Short;
		int Int;
		long Long;
		float Float;
		double Double;
		char* Str;
	} node;
} N_val;

/* Expression */
#define E_OP1 301
#define E_OP2 302
#define E_VAL 303
#define E_CALL 304
#define E_OP3 305
typedef struct {
	int type;
	void* node;
} N_expr;

/* Binary operator */
#define OP_ADD 201
#define OP_SUB 202
#define OP_MUL 203
#define OP_DIV 204
#define OP_MOD 205
#define OP_ARRAY 206
#define OP_DOT 207
#define OP_LEFT 208
#define OP_RIGHT 209
#define OP_LT 2010
#define OP_LTE 2011
#define OP_GT 2012
#define OP_GTE 2013
#define OP_EQ 2014
#define OP_NEQ 2015
#define OP_B_AND 2016
#define OP_B_XOR 2017
#define OP_B_OR 2018
#define OP_AND 2019
#define OP_OR 2020
#define OP_ASSIGN 2030
#define OP_ADD_ASSIGN 2031
#define OP_SUB_ASSIGN 2032
#define OP_MUL_ASSIGN 2033
#define OP_DIV_ASSIGN 2034
#define OP_MOD_ASSIGN 2035
#define OP_AND_ASSIGN 2036
#define OP_OR_ASSIGN 2037
#define OP_XOR_ASSIGN 2038
#define OP_LEFT_ASSIGN 2039
#define OP_RIGHT_ASSIGN 2040
typedef struct {
	int type;
	int line;
	int col;
	N_expr* left;
	N_expr* right;
} N_OP2;

/* Unary operator */
#define OP_NEG 101
#define OP_PRE_INC 102
#define OP_PRE_DEC 103
#define OP_POS 104
#define OP_B_NOT 105
#define OP_NOT 106
#define OP_POST_INC 107
#define OP_POST_DEC 108
typedef struct {
	int type;
	int line;
	int col;
	N_expr *expr;
} N_OP1;

/* Ternery operator */
typedef struct {
	N_expr *condition;
	N_expr *if_true;
	N_expr *if_false;
} N_OP3;

/* Call argument */
typedef struct STRUCT_N_arg {
	N_expr* node;
	struct STRUCT_N_arg* next;	/* Last if next == NULL */
} N_arg;

/* Function call */
typedef struct {
	N_expr* caller;
	N_arg* args;	/* No args if args == NULL */
} N_OP_Call;



/* STATEMENT Structures */

/* Statements */
#define S_EXPR 501
#define S_COMPOUND 502
#define S_IF 503
#define S_SWITCH 504
#define S_FOR 505
#define S_WHILE 506
#define S_DO 507
#define S_NOP 508
#define S_DECL 509
#define S_RETURN 5010
#define S_ASM 5011

/* Statement */
typedef struct {
	int type;
	void* node;
} N_stm;

/* Statement expression */
typedef struct {
	N_expr* expr;
} N_stm_expr;

/* Statement if */
typedef struct {
	N_expr* condition;
	N_stm* if_true;
	N_stm* if_false;
} N_stm_if;

/* Statement while */
typedef struct {
	N_expr* condition;
	N_stm* body;
} N_stm_while;

/* Statement for */
typedef struct {
	N_stm* init;
	N_stm* condition;
	N_expr* loop;
	N_stm* body;
} N_stm_for;

/* Statement compound */
typedef struct STRUCT_N_stm {
	N_stm* stm;
	struct STRUCT_N_stm* next;
} N_stm_compound;

/* Statement switch */
typedef struct {
	N_expr* condition;
	N_stm* stm;
} N_stm_switch;

/* Statement do */
typedef struct {
	N_expr* condition;
	N_stm* body;
} N_stm_do;

/* Structure for argument definition linked list */
typedef struct _STRUCT_ARG_DEF {
	char* name;
	char* type;
	struct _STRUCT_ARG_DEF* next;
} N_arg_def;

/* Statement declaration */
typedef struct {
	char* type;
	char* identifier;
	int is_func;
	N_stm* body;
	N_arg_def *args;
} N_stm_decl;

/* Statement return */
typedef struct {
	N_expr* return_value;
} N_stm_return;

/* Statement asm */
typedef struct {
	char* assembly;
} N_stm_asm;

/* Expression nodes constructors */
N_expr* new_expr(int type, void* node);
N_expr* new_val_int(int int_value);
N_expr* new_val_float(float float_value);
N_expr* new_val_string(char* string_value);
N_expr* new_op1(int line, int col, int type, N_expr* expr);
N_expr* new_op2(int line, int col, int type, N_expr* left, N_expr* right);
N_expr* new_op3(N_expr* condition, N_expr* if_true, N_expr* if_false);
N_expr* new_val_id(char* name);
N_arg* new_arg(N_expr* node);
N_expr* new_op_call(N_expr* caller);

/*Expression processors */
void calc_expr(N_expr* node);
void calc_val(N_val *node);
void calc_op1(N_OP1 *node);
void calc_op2(N_OP2 *node);
void calc_op3(N_OP3 *node);
void calc_call(N_OP_Call* node);

/* Statement nodes constructors */
N_stm* new_stm(int type, void* node);
N_stm* new_stm_nop();
N_stm* new_stm_while(N_expr* condition, N_stm* body);
N_stm* new_stm_do(N_expr* condition, N_stm* body);
N_stm* new_stm_expr(N_expr* expr);
N_stm* new_stm_for(N_stm* init, N_stm* condition, N_expr* loop, N_stm* body);
N_stm* new_stm_compound(N_stm_compound* sc);
N_stm_compound* new_stm_compound_pure(N_stm* stm);
N_stm* new_stm_if(N_expr* condition, N_stm* if_true, N_stm* if_false);
N_stm* new_stm_nop();
N_stm* new_stm_return(N_expr* return_value);
N_stm* new_stm_asm(char* assembly);

/* Statement processors */
void do_stm(N_stm* n);
void do_stm_expr(N_stm_expr* node);
void do_stm_compound(N_stm_compound* node);
void do_stm_if(N_stm_if* node);
void do_stm_switch(N_stm_switch* node);
void do_stm_for(N_stm_for* node);
void do_stm_while(N_stm_while* node);
void do_stm_do(N_stm_do* node);
void do_stm_decl(N_stm_decl* node);
void do_stm_return(N_stm_return* node);
void do_stm_asm(N_stm_asm* node);


/* Declaration structures */
N_stm* new_stm_decl(char* type, char* identifier, N_stm* body, N_arg_def *args);

N_arg_def* new_arg_def(char* name, char* type);