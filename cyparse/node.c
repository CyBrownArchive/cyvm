#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* ###################################################################################################### */
/* ###################################################################################################### */
/* Functions to process expressions */

/* EXPRESSION NODES:
type: type of node:
	op1: unary operation
		op: operator used
		expr: expression passed to the operator
	op2: binary operation
		op: operator used
		left: left side expression
		right: right side expression
	op3: ternery operation
		condition: condition
		if_true: expression if condition succeed
		if_false: expression if condition failed
	call: function call
		caller: expression that is a function
		args: array of expressions
	literal: a constant value
		data_type: data type of the node (int, string, float)
		value: value of constant
	identifier: a link to a variable
		value: name of the variable
*/

void calc_val(N_val *node)
{
	printf("{");
	if (node->type ==  V_ID)
		printf("\"type\":\"identifier\",\"name\": \"%s\"", node->node.Str);
	else
	{
		printf("\"type\":\"literal\",");
		if (node->type == V_INT)
			printf("\"data_type\":\"int\",\"value\": %d", node->node.Int);
		else if (node->type ==  V_STR)
			printf("\"data_type\":\"string\",\"value\": \"%s\"", node->node.Str);
		else if (node->type ==  V_FLOAT)
			printf("\"data_type\":\"float\",\"value\": %f", node->node.Float);
		else
			printf("\nUNKNOW VAL %d\n", node->type);
	}
	printf("}");
}

void calc_op3(N_OP3 *node)
{
	printf("{\"type\":\"op3\",\"condition\":");
	calc_expr(node->condition);
	printf(",\"if_true\":");
	calc_expr(node->if_true);
	printf(",\"if_false\":");
	calc_expr(node->if_false);
	printf("}");
}

void calc_op2(N_OP2 *node)
{
	printf("{\"type\":\"op2\",\"line\":%d, \"col\":%d,\"op\":\"", node->line, node->col);
	switch (node->type)
	{
		// Arithmetic
		case OP_ADD: printf("add"); break;
		case OP_SUB: printf("sub"); break;
		case OP_MUL: printf("mul"); break;
		case OP_DIV: printf("div"); break;
		case OP_MOD: printf("mod"); break;

		case OP_ARRAY: printf("array"); break;

		case OP_DOT: printf("dot"); break;

		// Comparison
		case OP_LT: printf("lt"); break;
		case OP_LTE: printf("lte"); break;
		case OP_GT: printf("gt"); break;
		case OP_GTE: printf("gte"); break;

		// Equality
		case OP_EQ: printf("eq"); break;
		case OP_NEQ: printf("neq"); break;

		// Binary
		case OP_B_AND: printf("b_and"); break;
		case OP_B_XOR: printf("b_xor"); break;
		case OP_B_OR: printf("b_or"); break;
		case OP_LEFT: printf("left"); break;
		case OP_RIGHT: printf("right"); break;

		// Logical
		case OP_AND: printf("and"); break;
		case OP_OR: printf("or"); break;

		// Assignment
		case OP_ASSIGN: printf("assign"); break;
		case OP_ADD_ASSIGN: printf("add_assign"); break;
		case OP_SUB_ASSIGN: printf("sub_assign"); break;
		case OP_MUL_ASSIGN: printf("mul_assign"); break;
		case OP_DIV_ASSIGN: printf("div_assign"); break;
		case OP_MOD_ASSIGN: printf("mod_assign"); break;
		case OP_AND_ASSIGN: printf("and_assign"); break;
		case OP_OR_ASSIGN: printf("or_assign"); break;
		case OP_XOR_ASSIGN: printf("xor_assign"); break;
		case OP_LEFT_ASSIGN: printf("left_assign"); break;
		case OP_RIGHT_ASSIGN: printf("right_assign"); break;

		default: printf("\nUNKNOWN OP2\n"); break;
	}
	printf("\",\"left\":");
	calc_expr(node->left);
	printf(",\"right\":");
	calc_expr(node->right);
	printf("}");
}

void calc_op1(N_OP1 *node)
{
	printf("{\"type\":\"op1\",\"line\":%d, \"col\":%d,\"op\":\"", node->line, node->col);
	switch(node->type)
	{
		case OP_NEG: printf("neg"); break;
		case OP_PRE_INC: printf("pre_inc"); break;
		case OP_PRE_DEC: printf("pre_dec"); break;
		case OP_POS: printf("pos"); break;
		case OP_B_NOT: printf("b_not"); break;
		case OP_NOT: printf("not"); break;
		case OP_POST_INC: printf("post_inc"); break;
		case OP_POST_DEC: printf("post_dec"); break;
		default: printf("\nUNKNOWN OP1\n"); break;
	}
	printf("\",\"expr\":");
	calc_expr(node->expr);
	printf("}");
}

void calc_arg(N_arg* arg)
{
	N_arg* current = arg;
	char first = 1;
	do
	{
		if (!first)
		{
			printf(",");
		}
		else
		{
			first = 0;
		}
		calc_expr(current->node);
	} while((current = current->next));
}

void calc_call(N_OP_Call* node)
{
	printf("{\"type\":\"call\",\"op\":\"call\",\"caller\":");
	calc_expr(node->caller);
	printf(",\"args\":[");
	if (node->args != NULL)
	{
		calc_arg(node->args);
	}
	printf("]}");
}

void calc_expr(N_expr* node)
{
	if (node->type == E_VAL)
		calc_val((N_val*)node->node);
	else if (node->type == E_OP2)
		calc_op2((N_OP2*)node->node);
	else if (node->type == E_OP1)
		calc_op1((N_OP1*)node->node);
	else if (node->type == E_OP3)
		calc_op3((N_OP3*)node->node);
	else if (node->type == E_CALL)
		calc_call((N_OP_Call*)node->node);
	else
		printf("\nUNKNOWN NODE\n");
}

/* ###################################################################################################### */
/* ###################################################################################################### */
/* Function to create expression nodes */

/* Generic expression */
N_expr* new_expr(int type, void* node)
{
	N_expr* e = malloc(sizeof(N_expr));
	e->type = type;
	e->node = node;
	return e;
}

/* Integer values */
N_expr* new_val_int(int int_value)
{
	N_val* n = malloc(sizeof(N_val));
	n->type = V_INT;
	n->node.Int = int_value;
	return new_expr(E_VAL, n);
}

/* Float values */
N_expr* new_val_float(float float_value)
{
	N_val* n = malloc(sizeof(N_val));
	n->type = V_FLOAT;
	n->node.Float = float_value;
	return new_expr(E_VAL, n);
}

/* String values */
N_expr* new_val_string(char* string_value)
{
	N_val* n = malloc(sizeof(N_val));
	n->type = V_STR;
	n->node.Str = string_value;
	return new_expr(E_VAL, n);
}

/* Identifiers */
N_expr* new_val_id(char* name)
{
	N_val* n = malloc(sizeof(N_val));
	n->type = V_ID;
	n->node.Str = name;
	return new_expr(E_VAL, n);
}

/* Unary operators */
N_expr* new_op1(int line, int col, int type, N_expr* expr)
{
	N_OP1* n = malloc(sizeof(N_OP1));
	n->line = line;
	n->col = col;
	n->type = type;
	n->expr = expr;
	return new_expr(E_OP1, n);
}

/* Binary operatos */
N_expr* new_op2(int line, int col, int type, N_expr* left, N_expr* right)
{
	N_OP2* n = malloc(sizeof(N_OP2));
	n->line = line;
	n->col = col;
	n->type = type;
	n->left = left;
	n->right = right;
	return new_expr(E_OP2, n);
}

/* Ternary operator  */
N_expr* new_op3(N_expr* condition, N_expr* if_true, N_expr* if_false)
{
	N_OP3* n = malloc(sizeof(N_OP3));
	n->condition = condition;
	n->if_true = if_true;
	n->if_false = if_false;
	return new_expr(E_OP3, n);
}

/* Function call */
N_expr* new_op_call(N_expr* caller)
{
	N_OP_Call* n = malloc(sizeof(N_OP_Call));
	n->caller = caller;
	n->args = NULL;
	return new_expr(E_CALL, n);
}

/* Function call argument */
N_arg* new_arg(N_expr* node)
{
	N_arg* n = malloc(sizeof(N_arg));
	n->node = node;
	n->next = NULL;
	return n;
}

/* ###################################################################################################### */
/* ###################################################################################################### */
/* Functions to process statements */

/* STATEMENT Nodes
type: type of statement
	expr: simple expression statement
		expr: expression node
	while: while statement
		condition: expression node
		body: body of while structure
	if: if statement, with one else optionaly
		condition: expression node
		if_true: statement if condition is true
		if_false: statement if condition is false
	do: do statement
		condition: expression node
		body: body of do structure
	switch: switch statement (not designed)
	for: for statement
		init: statement expression node, executed first
		condition: statement expression node, executed before body each loop, breaks if false
		loop: expression node, executed after body each loop
		body: body of for statement
	compound: multiple statements
		statements: array of statements
	nop: empty statement
*/

void do_stm(N_stm* n)
{
	switch (n->type)
	{
		case S_EXPR: do_stm_expr(n->node); break;
		case S_COMPOUND: do_stm_compound(n->node); break;
		case S_IF: do_stm_if(n->node); break;
		case S_SWITCH: do_stm_switch(n->node); break;
		case S_FOR: do_stm_for(n->node); break;
		case S_WHILE: do_stm_while(n->node); break;
		case S_DO: do_stm_do(n->node); break;
		case S_DECL: do_stm_decl(n->node); break;
		case S_RETURN: do_stm_return(n->node); break;
		case S_ASM: do_stm_asm(n->node); break;
		case S_NOP: break;
		default: printf("\nUNKNOWN STM %d\n", n->type); break;
	}
}

void do_stm_expr(N_stm_expr* node) {
	printf("{\"type\":\"expr\",\"value\":");
	calc_expr(node->expr);
	printf("}");
}

void do_stm_compound(N_stm_compound* node) {
	N_stm_compound* current = node;
	printf("{\"type\":\"compound\",\"statements\":[");
	do_stm(current->stm);
	while ((current = current->next))
	{
		printf(",");
		do_stm(current->stm);
	}
	printf("]}");
}

void do_stm_if(N_stm_if* node) {
	printf("{\"type\":\"if\",\"condition\":");
	calc_expr(node->condition);
	printf(",\"if_true\":");
	do_stm(node->if_true);
	if (node->if_false != NULL)
	{
		printf(",\"if_false\":");
		do_stm(node->if_false);
	}
	printf("}");
}

void do_stm_switch(N_stm_switch* node) {
	printf("\ndo_stm_switch NOT IMPLEMENTED\n");
}

void do_stm_for(N_stm_for* node) {
	printf("{\"type\":\"for\",\"condition\":");
	do_stm(node->condition);
	printf(",\"init\":");
	do_stm(node->init);
	printf(",\"loop\":");
	calc_expr(node->loop);
	printf(",\"body\":");
	do_stm(node->body);
	printf("}");
}

void do_stm_while(N_stm_while* node) {
	printf("{\"type\":\"while\",\"condition\":");
	calc_expr(node->condition);
	printf(",\"body\":");
	do_stm(node->body);
	printf("}");
}

void do_stm_do(N_stm_do* node) {
	printf("{\"type\":\"do\",\"condition\":");
	calc_expr(node->condition);
	printf(",\"body\":");
	do_stm(node->body);
	printf("}");
}

void do_stm_decl(N_stm_decl* node) {
	N_arg_def* cur;
	int first = 1;
	printf("{\"type\":\"decl\"");
	printf(",\"data_type\":\"%s\"", node->type);
	printf(",\"name\":\"%s\"", node->identifier);
	if (node->body != NULL)
	{
		printf(",\"body\":");
		do_stm(node->body);
		printf(",\"args\":[");
		cur = node->args;
		while (cur != NULL)
		{
			if (!first)
				printf(",");
			// TODO ECHO ARGUMENT LIST
			printf("{\"name\":\"%s\",\"type\":\"%s\"}", cur->name, cur->type);
			cur = cur->next;
			first = 0;
		}
		printf("]");
	}
	else
	{
		printf(",\"body\":null, \"args\":[]");
	}
	printf("}");
}

void do_stm_return(N_stm_return* node) {
	printf("{\"type\":\"return\"");
	if (node->return_value != NULL)
	{
		printf(",\"return_value\":");
		calc_expr(node->return_value);
	}
	printf("}");
}

void do_stm_asm(N_stm_asm* node) {
	printf("{\"type\":\"asm\"");
	printf(",\"assembly\": \"%s\"", node->assembly);
	printf("}");
}

/* ###################################################################################################### */
/* ###################################################################################################### */
/* Function to create statements */

N_stm* new_stm(int type, void* node)
{
	N_stm* n = malloc(sizeof(N_stm));
	n->type = type;
	n->node = node;
	return n;
}

N_stm* new_stm_while(N_expr* condition, N_stm* body)
{
	N_stm_while* n = malloc(sizeof(N_stm_while));
	n->condition = condition;
	n->body = body;
	return new_stm(S_WHILE, n);
}

N_stm* new_stm_if(N_expr* condition, N_stm* if_true, N_stm* if_false)
{
	N_stm_if* n = malloc(sizeof(N_stm_if));
	n->condition = condition;
	n->if_true = if_true;
	n->if_false = if_false;
	return new_stm(S_IF, n);
}

N_stm* new_stm_for(N_stm* init, N_stm* condition, N_expr* loop, N_stm* body)
{
	N_stm_for* n = malloc(sizeof(N_stm_for));
	n->init = init;
	n->condition = condition;
	n->loop = loop;
	n->body = body;
	return new_stm(S_FOR, n);
}

N_stm* new_stm_do(N_expr* condition, N_stm* body)
{
	N_stm_do* n = malloc(sizeof(N_stm_do));
	n->condition = condition;
	n->body = body;
	return new_stm(S_DO, n);
}

N_stm* new_stm_nop()
{
	return new_stm(S_NOP, NULL);
}

N_stm* new_stm_expr(N_expr* expr)
{
	N_stm_expr* n = malloc(sizeof(N_stm_expr));
	n->expr = expr;
	return new_stm(S_EXPR, n);
}

N_stm* new_stm_compound(N_stm_compound* sc)
{
	return new_stm(S_COMPOUND, sc);
}

N_stm_compound* new_stm_compound_pure(N_stm* stm)
{
	N_stm_compound* n = malloc(sizeof(N_stm_compound));
	n->stm = stm;
	n->next = NULL;
	return n;
}

N_stm* new_stm_return(N_expr* return_value)
{
	N_stm_return* n = malloc(sizeof(N_stm_return));
	n->return_value = return_value;
	return new_stm(S_RETURN, n);
}

/* #################################################################################################### */
/* #################################################################################################### */
/* Declarations */

N_stm* new_stm_decl(char* type, char* identifier, N_stm* body, N_arg_def *args)
{
	N_stm_decl* n = malloc(sizeof(N_stm_decl));
	n->type = type;
	n->identifier = identifier;
	n->is_func = (body != NULL);
	n->body = body;
	n->args = args;
	return new_stm(S_DECL, n);
}

N_arg_def* new_arg_def(char* name, char* type)
{
	N_arg_def* n = malloc(sizeof(N_arg_def));
	n->name = name;
	n->type = type;
	n->next = NULL;
	return n;
}

N_stm* new_stm_asm(char* assembly)
{
	N_stm_asm* n = malloc(sizeof(N_stm_asm));
	n->assembly = assembly;
	return new_stm(S_ASM, n);
}