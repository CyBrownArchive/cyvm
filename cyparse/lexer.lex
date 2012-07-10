%{
#include <string.h>
#include "node.h"
#include "y.tab.h"
int current_char = 0;
int current_line = 0;
char str_buffer[1024] = {'\0'};
FILE *out_debug;

int is_keyword(char *str)
{
	/* STATEMENTS */
	if (!strcmp(str, "if"))
		return TOK_IF;
	else if (!strcmp(str, "else"))
		return TOK_ELSE;
	else if (!strcmp(str, "for"))
		return TOK_FOR;
	else if (!strcmp(str, "while"))
		return TOK_WHILE;
	else if (!strcmp(str, "do"))
		return TOK_DO;
	else if (!strcmp(str, "switch"))
		return TOK_FLOAT;
	else if (!strcmp(str, "case"))
		return TOK_FLOAT;
	else if (!strcmp(str, "return"))
		return TOK_RETURN;
	else if (!strcmp(str, "asm"))
		return TOK_ASM;
	/* TYPES */
	else if (!strcmp(str, "byte"))
		return TOK_BYTE;
	else if (!strcmp(str, "short"))
		return TOK_SHORT;
	else if (!strcmp(str, "int"))
		return TOK_INT;
	else if (!strcmp(str, "long"))
		return TOK_LONG;
	else if (!strcmp(str, "float"))
		return TOK_FLOAT;
	else if (!strcmp(str, "double"))
		return TOK_DOUBLE;
	else if (!strcmp(str, "string"))
		return TOK_STRING;
	else if (!strcmp(str, "void"))
		return TOK_VOID;
	return 0;
}

%}

digit [0-9]
octdigit [0-7]
hexdigit [0-9a-fA-F]
alpha [a-zA-Z]
blank [\t]|" "

alnum {alpha}|{digit}

%s STRING
%s COMMENT
%s COMMENT_ONELINE
%s ASM

%%

<INITIAL>0{octdigit}*   {fprintf(out_debug, "Octal integer: %s\n", yytext); current_char += yyleng; yylval.str = strdup(yytext); return LITERAL_INTEGER;}
<INITIAL>[1-9]{digit}*  {fprintf(out_debug, "Decimal integer: %s\n", yytext); current_char += yyleng; yylval.str = strdup(yytext); return LITERAL_INTEGER;}
<INITIAL>0x{hexdigit}*  {fprintf(out_debug, "Hexadecimal integer: %s\n", yytext); current_char += yyleng; yylval.str = strdup(yytext); return LITERAL_INTEGER;}

<INITIAL>{digit}+"."{digit}* {fprintf(out_debug, "Float: %s\n", yytext); current_char += yyleng; yylval.str = strdup(yytext); return LITERAL_FLOAT;}
<INITIAL>{digit}*"."{digit}+ {fprintf(out_debug, "Float: %s\n", yytext); current_char += yyleng; yylval.str = strdup(yytext); return LITERAL_FLOAT;}

<INITIAL>\"				{current_char += yyleng; fprintf(out_debug, "\""); current_char += yyleng; BEGIN STRING;}

<INITIAL>"="            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_ASSIGN;}
<INITIAL>"+="            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_ADD_ASSIGN;}
<INITIAL>"-="            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_SUB_ASSIGN;}
<INITIAL>"*="            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_MUL_ASSIGN;}
<INITIAL>"/="            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_DIV_ASSIGN;}
<INITIAL>"%="            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_MOD_ASSIGN;}
<INITIAL>"&="            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_AND_ASSIGN;}
<INITIAL>"|="            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_OR_ASSIGN;}
<INITIAL>"^="            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_XOR_ASSIGN;}
<INITIAL>"<<="            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_LEFT_ASSIGN;}
<INITIAL>">>="            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_RIGHT_ASSIGN;}


<INITIAL>"++"           {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_INC;}
<INITIAL>"--"           {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_DEC;}

<INITIAL>"+"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return '+';}
<INITIAL>"-"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return '-';}
<INITIAL>"*"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return '*';}
<INITIAL>"/"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return '/';}
<INITIAL>"%"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return '%';}

<INITIAL>"<<"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_LEFT;}
<INITIAL>">>"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_RIGHT;}

<INITIAL>"=="           {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_EQ;}
<INITIAL>"!="           {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_NEQ;}
<INITIAL>"<"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_LT;}
<INITIAL>"<="           {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_LTE;}
<INITIAL>">"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_GT;}
<INITIAL>">="           {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_GTE;}

<INITIAL>"&&"           {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_AND;}
<INITIAL>"||"           {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return TOK_OR;}
<INITIAL>"!"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return '!';}

<INITIAL>"&"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return '&';}
<INITIAL>"|"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return '|';}
<INITIAL>"^"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return '^';}
<INITIAL>"~"            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return '~';}

<INITIAL>"("			{fprintf(out_debug, "Par open\n"); current_char += yyleng; return '(';}
<INITIAL>")"      		{fprintf(out_debug, "Par close\n"); current_char += yyleng; return ')';}
<INITIAL>"{"			{fprintf(out_debug, "Bloc open\n"); current_char += yyleng; return '{';}
<INITIAL>"}"      		{fprintf(out_debug, "Bloc close\n"); current_char += yyleng; return '}';}
<INITIAL>"["			{fprintf(out_debug, "Array open\n"); current_char += yyleng; return '[';}
<INITIAL>"]"      		{fprintf(out_debug, "Array close\n"); current_char += yyleng; return ']';}

<INITIAL>"?"			{fprintf(out_debug, "Question mark\n"); current_char += yyleng; return '?';}
<INITIAL>":"      		{fprintf(out_debug, "Colon\n"); current_char += yyleng; return ':';}

<INITIAL>","      		{fprintf(out_debug, "Comma\n"); current_char += yyleng; return ',';}
<INITIAL>"."            {fprintf(out_debug, "Operator %s\n", yytext); current_char += yyleng; return '.';}
<INITIAL>";"            {fprintf(out_debug, "Semi colon\n"); current_char += yyleng; return ';';}

<INITIAL>({alpha}|[_$])({alnum}|_)* {
		if (is_keyword(yytext))
		{
			fprintf(out_debug, "Keyword %d %s\n", is_keyword(yytext), yytext);
			current_char += yyleng;
			yylval.str = strdup(yytext);
			if (is_keyword(yytext) == TOK_ASM)
			{
				BEGIN ASM;
			}
			return is_keyword(yytext);
		}
		else
		{
			current_char += yyleng;
			fprintf(out_debug, "Identifier: %s\n", yytext);
			yylval.str = strdup(yytext);
			return TOK_IDENTIFIER;
		}
	}

<INITIAL>"/*"           {fprintf(out_debug, "Begin comment\n"); current_char += yyleng; BEGIN COMMENT;}
<INITIAL>"//"           {fprintf(out_debug, "Begin comment\n"); current_char += yyleng; BEGIN COMMENT_ONELINE;}

<INITIAL>" "|blank      {current_char++;}
<INITIAL>\r?\n          {current_line++; current_char = 0;}
<INITIAL>.              {current_char++; fprintf(out_debug, "Unknown char \"%s\"\n", yytext);}

<STRING>\\\"		    {current_char += yyleng;}
<STRING>\"              {current_char += yyleng; fprintf(out_debug, "\"\n"); yylval.str = strdup(str_buffer); str_buffer[0] = '\0'; BEGIN INITIAL; return LITERAL_STRING;}
<STRING>\r?\n           {strcat(str_buffer, yytext); current_char = 0; current_line++;}
<STRING>.               {strcat(str_buffer, yytext); current_char += yyleng;}

<COMMENT>"*/"           {fprintf(out_debug, "End comment\n"); current_char += yyleng; BEGIN INITIAL;}
<COMMENT>.              {current_char += yyleng;}
<COMMENT>\r?\n          {current_char = 0; current_line++;}

<COMMENT_ONELINE>.		{current_char++;}
<COMMENT_ONELINE>\n 	{current_line++; current_char = 0; BEGIN INITIAL;}

<ASM>";"				{yylval.str = strdup(str_buffer); str_buffer[0] = '\0'; BEGIN INITIAL; return LITERAL_ASSEMBLY;}
<ASM>\r?\n 				{strcat(str_buffer, yytext); current_line++; current_char = 0;}
<ASM>.                  {strcat(str_buffer, yytext); current_char += yyleng;}

%%
