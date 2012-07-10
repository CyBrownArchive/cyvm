
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LITERAL_INTEGER = 258,
     LITERAL_FLOAT = 259,
     LITERAL_STRING = 260,
     LITERAL_ASSEMBLY = 261,
     TOK_IDENTIFIER = 262,
     TOK_IF = 263,
     TOK_ELSE = 264,
     TOK_SWITCH = 265,
     TOK_CASE = 266,
     TOK_WHILE = 267,
     TOK_DO = 268,
     TOK_FOR = 269,
     TOK_ASM = 270,
     TOK_CHAR = 271,
     TOK_BYTE = 272,
     TOK_SHORT = 273,
     TOK_INT = 274,
     TOK_LONG = 275,
     TOK_FLOAT = 276,
     TOK_DOUBLE = 277,
     TOK_STRING = 278,
     TOK_VOID = 279,
     TOK_RETURN = 280,
     TOK_ASSIGN = 281,
     TOK_ADD_ASSIGN = 282,
     TOK_SUB_ASSIGN = 283,
     TOK_MUL_ASSIGN = 284,
     TOK_DIV_ASSIGN = 285,
     TOK_MOD_ASSIGN = 286,
     TOK_AND_ASSIGN = 287,
     TOK_OR_ASSIGN = 288,
     TOK_XOR_ASSIGN = 289,
     TOK_LEFT_ASSIGN = 290,
     TOK_RIGHT_ASSIGN = 291,
     TOK_INC = 292,
     TOK_DEC = 293,
     TOK_EQ = 294,
     TOK_NEQ = 295,
     TOK_LT = 296,
     TOK_LTE = 297,
     TOK_GT = 298,
     TOK_GTE = 299,
     TOK_AND = 300,
     TOK_OR = 301,
     TOK_LEFT = 302,
     TOK_RIGHT = 303,
     IFX = 304
   };
#endif
/* Tokens.  */
#define LITERAL_INTEGER 258
#define LITERAL_FLOAT 259
#define LITERAL_STRING 260
#define LITERAL_ASSEMBLY 261
#define TOK_IDENTIFIER 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_SWITCH 265
#define TOK_CASE 266
#define TOK_WHILE 267
#define TOK_DO 268
#define TOK_FOR 269
#define TOK_ASM 270
#define TOK_CHAR 271
#define TOK_BYTE 272
#define TOK_SHORT 273
#define TOK_INT 274
#define TOK_LONG 275
#define TOK_FLOAT 276
#define TOK_DOUBLE 277
#define TOK_STRING 278
#define TOK_VOID 279
#define TOK_RETURN 280
#define TOK_ASSIGN 281
#define TOK_ADD_ASSIGN 282
#define TOK_SUB_ASSIGN 283
#define TOK_MUL_ASSIGN 284
#define TOK_DIV_ASSIGN 285
#define TOK_MOD_ASSIGN 286
#define TOK_AND_ASSIGN 287
#define TOK_OR_ASSIGN 288
#define TOK_XOR_ASSIGN 289
#define TOK_LEFT_ASSIGN 290
#define TOK_RIGHT_ASSIGN 291
#define TOK_INC 292
#define TOK_DEC 293
#define TOK_EQ 294
#define TOK_NEQ 295
#define TOK_LT 296
#define TOK_LTE 297
#define TOK_GT 298
#define TOK_GTE 299
#define TOK_AND 300
#define TOK_OR 301
#define TOK_LEFT 302
#define TOK_RIGHT 303
#define IFX 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 74 "parser.y"
int num; char* str; N_expr *expr; N_arg *arg; N_stm *stm; N_stm_compound *stm_compound; N_arg_def *argdef;


/* Line 1676 of yacc.c  */
#line 154 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


