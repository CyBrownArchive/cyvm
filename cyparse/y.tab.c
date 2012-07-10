
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

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



/* Line 189 of yacc.c  */
#line 89 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 74 "parser.y"
int num; char* str; N_expr *expr; N_arg *arg; N_stm *stm; N_stm_compound *stm_compound; N_arg_def *argdef;


/* Line 214 of yacc.c  */
#line 227 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 239 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   370

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNRULES -- Number of states.  */
#define YYNSTATES  196

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,     2,     2,    67,    68,     2,
      50,    51,    65,    61,    55,    62,    60,    66,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    72,    52,
      56,     2,    57,    71,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    70,    54,    63,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    14,    22,    28,    36,    44,
      48,    50,    53,    55,    58,    62,    65,    68,    70,    72,
      74,    76,    78,    80,    82,    84,    86,    89,    92,    96,
     102,   109,   116,   119,   124,   126,   131,   133,   135,   137,
     139,   141,   143,   145,   147,   149,   151,   153,   157,   159,
     163,   165,   170,   175,   179,   183,   186,   189,   191,   194,
     197,   200,   203,   206,   209,   211,   215,   219,   223,   225,
     229,   233,   235,   239,   243,   245,   249,   253,   257,   261,
     263,   267,   271,   273,   277,   279,   283,   285,   289,   291,
     295,   297,   301,   303,   309,   311,   315,   319,   323,   327,
     331,   335,   339,   343,   347,   351,   355
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      74,     0,    -1,    74,    84,    -1,    84,    -1,     8,    50,
     105,    51,    84,    -1,     8,    50,   105,    51,    84,     9,
      84,    -1,    12,    50,   105,    51,    84,    -1,    13,    84,
      12,    50,   105,    51,    52,    -1,    14,    50,    81,    81,
     105,    51,    84,    -1,    53,    80,    54,    -1,    84,    -1,
      80,    84,    -1,    52,    -1,   105,    52,    -1,    25,   105,
      52,    -1,    25,    52,    -1,    15,     6,    -1,    79,    -1,
      81,    -1,    75,    -1,    77,    -1,    78,    -1,    76,    -1,
      82,    -1,    83,    -1,    85,    -1,     1,    52,    -1,     1,
      54,    -1,    87,     7,    52,    -1,    87,     7,    50,    51,
      84,    -1,    87,     7,    50,    24,    51,    84,    -1,    87,
       7,    50,    86,    51,    84,    -1,    87,     7,    -1,    86,
      55,    87,     7,    -1,    88,    -1,    87,    56,     3,    57,
      -1,    24,    -1,    17,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,     3,    -1,     4,    -1,     5,
      -1,     7,    -1,    50,   105,    51,    -1,   105,    -1,    90,
      55,   105,    -1,    89,    -1,    91,    58,   105,    59,    -1,
      91,    50,    90,    51,    -1,    91,    50,    51,    -1,    91,
      60,     7,    -1,    91,    37,    -1,    91,    38,    -1,    91,
      -1,    37,    92,    -1,    38,    92,    -1,    61,    92,    -1,
      62,    92,    -1,    63,    92,    -1,    64,    92,    -1,    92,
      -1,    93,    65,    92,    -1,    93,    66,    92,    -1,    93,
      67,    92,    -1,    93,    -1,    94,    61,    93,    -1,    94,
      62,    93,    -1,    94,    -1,    95,    47,    94,    -1,    95,
      48,    94,    -1,    95,    -1,    96,    41,    95,    -1,    96,
      42,    95,    -1,    96,    43,    95,    -1,    96,    44,    95,
      -1,    96,    -1,    97,    39,    96,    -1,    97,    40,    96,
      -1,    97,    -1,    98,    68,    97,    -1,    98,    -1,    99,
      69,    98,    -1,    99,    -1,   100,    70,    99,    -1,   100,
      -1,   101,    45,   100,    -1,   101,    -1,   102,    46,   101,
      -1,   102,    -1,   102,    71,   105,    72,   103,    -1,   103,
      -1,    92,    26,   104,    -1,    92,    27,   104,    -1,    92,
      28,   104,    -1,    92,    29,   104,    -1,    92,    30,   104,
      -1,    92,    31,   104,    -1,    92,    32,   104,    -1,    92,
      33,   104,    -1,    92,    34,   104,    -1,    92,    35,   104,
      -1,    92,    36,   104,    -1,   104,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   119,   123,   124,   127,   131,   135,   139,
     143,   144,   154,   155,   159,   160,   164,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   181,   182,
     183,   184,   188,   189,   202,   203,   204,   208,   209,   210,
     211,   212,   213,   217,   218,   219,   220,   221,   225,   226,
     236,   237,   238,   239,   240,   241,   242,   246,   247,   248,
     249,   250,   251,   252,   256,   257,   258,   259,   263,   264,
     265,   269,   270,   271,   275,   276,   277,   278,   279,   283,
     284,   285,   289,   290,   294,   295,   299,   300,   304,   305,
     309,   310,   314,   315,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   334
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LITERAL_INTEGER", "LITERAL_FLOAT",
  "LITERAL_STRING", "LITERAL_ASSEMBLY", "TOK_IDENTIFIER", "TOK_IF",
  "TOK_ELSE", "TOK_SWITCH", "TOK_CASE", "TOK_WHILE", "TOK_DO", "TOK_FOR",
  "TOK_ASM", "TOK_CHAR", "TOK_BYTE", "TOK_SHORT", "TOK_INT", "TOK_LONG",
  "TOK_FLOAT", "TOK_DOUBLE", "TOK_STRING", "TOK_VOID", "TOK_RETURN",
  "TOK_ASSIGN", "TOK_ADD_ASSIGN", "TOK_SUB_ASSIGN", "TOK_MUL_ASSIGN",
  "TOK_DIV_ASSIGN", "TOK_MOD_ASSIGN", "TOK_AND_ASSIGN", "TOK_OR_ASSIGN",
  "TOK_XOR_ASSIGN", "TOK_LEFT_ASSIGN", "TOK_RIGHT_ASSIGN", "TOK_INC",
  "TOK_DEC", "TOK_EQ", "TOK_NEQ", "TOK_LT", "TOK_LTE", "TOK_GT", "TOK_GTE",
  "TOK_AND", "TOK_OR", "TOK_LEFT", "TOK_RIGHT", "IFX", "'('", "')'", "';'",
  "'{'", "'}'", "','", "'<'", "'>'", "'['", "']'", "'.'", "'+'", "'-'",
  "'~'", "'!'", "'*'", "'/'", "'%'", "'&'", "'^'", "'|'", "'?'", "':'",
  "$accept", "program", "stm_if", "stm_while", "stm_do", "stm_for",
  "stm_compound", "stm_list", "stm_expr", "stm_return", "stm_asm",
  "statement", "declaration", "argument_definition_list", "type_specifier",
  "type_primary", "expr_primary", "argument_list", "expr_postfix",
  "expr_unary", "expr_mul", "expr_add", "expr_shift", "expr_comparison",
  "expr_equal", "expr_bitwise_and", "expr_bitwise_xor", "expr_bitwise_or",
  "expr_logical_and", "expr_logical_or", "expr_conditional", "expr_assign",
  "expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      40,    41,    59,   123,   125,    44,    60,    62,    91,    93,
      46,    43,    45,   126,    33,    42,    47,    37,    38,    94,
     124,    63,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    74,    75,    75,    76,    77,    78,    79,
      80,    80,    81,    81,    82,    82,    83,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    85,    85,
      85,    85,    86,    86,    87,    87,    87,    88,    88,    88,
      88,    88,    88,    89,    89,    89,    89,    89,    90,    90,
      91,    91,    91,    91,    91,    91,    91,    92,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    94,    94,
      94,    95,    95,    95,    96,    96,    96,    96,    96,    97,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     5,     7,     5,     7,     7,     3,
       1,     2,     1,     2,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     5,
       6,     6,     2,     4,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     4,     4,     3,     3,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    43,    44,    45,    46,     0,     0,     0,     0,
       0,    37,    38,    39,    40,    41,    42,    36,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,    19,
      22,    20,    21,    17,    18,    23,    24,     3,    25,     0,
      34,    50,    57,    64,    68,    71,    74,    79,    82,    84,
      86,    88,    90,    92,    94,   106,     0,    26,    27,     0,
       0,     0,     0,    16,    15,     0,    58,    59,     0,     0,
      10,    60,    61,    62,    63,     1,     2,     0,     0,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     0,     0,    14,
      47,     9,    11,     0,    28,     0,    53,     0,    48,     0,
      54,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    65,    66,    67,    64,    69,    70,    72,    73,
      75,    76,    77,    78,    80,    81,    83,    85,    87,    89,
      91,     0,     0,     0,     0,     0,    36,     0,     0,     0,
      35,    52,     0,    51,     0,     4,     6,     0,     0,     0,
      29,     0,     0,    32,    49,    93,     0,     0,     0,    30,
      31,     0,     5,     7,     8,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    30,    31,    32,    33,    69,    34,    35,
      36,    37,    38,   168,    39,    40,    41,   127,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -121
static const yytype_int16 yypact[] =
{
     242,    57,  -121,  -121,  -121,  -121,   -37,   -11,   242,     7,
      13,  -121,  -121,  -121,  -121,  -121,  -121,  -121,   270,   306,
     306,   306,  -121,   242,   306,   306,   306,   306,   100,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,    -2,
    -121,  -121,   -20,    15,   -31,     2,    96,    54,   106,   -36,
      30,    32,    27,   -34,  -121,  -121,    24,  -121,  -121,   306,
     306,    98,   278,  -121,  -121,    64,  -121,  -121,    72,   178,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,     6,   144,  -121,
    -121,   286,   306,   153,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,  -121,   119,   121,   101,   278,  -121,
    -121,  -121,  -121,     4,  -121,   117,  -121,   -24,  -121,   116,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,   -31,   -31,     2,     2,
      96,    96,    96,    96,    54,    54,   106,   -36,    30,    32,
      27,   104,   242,   242,   306,   306,   126,   242,   -22,     3,
    -121,  -121,   306,  -121,   306,   175,  -121,   136,   137,   242,
    -121,   242,    49,  -121,  -121,  -121,   242,   142,   242,  -121,
    -121,     9,  -121,  -121,  -121,  -121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,   -58,  -121,
    -121,    -8,  -121,  -121,  -120,  -121,  -121,  -121,  -121,   -18,
      50,    66,    37,    62,    81,    92,    94,    95,    93,  -121,
      33,    42,    -7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      61,    66,    67,   169,   118,    77,    71,    72,    73,    74,
     183,    65,   112,    59,    68,    70,   195,    79,    80,    63,
      76,    11,    12,    13,    14,    15,    16,   171,   166,   181,
      81,   172,   108,   182,    95,    96,    97,   113,    82,    60,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,   115,   116,    78,   167,   123,    62,   124,    78,
     165,   122,   191,    98,    99,    78,    11,    12,    13,    14,
      15,    16,   111,    17,   128,   129,   114,   142,   143,   144,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   102,   103,   104,   105,   109,
      75,     1,   110,     2,     3,     4,   161,     5,     6,    57,
     117,    58,     7,     8,     9,    10,   119,    11,    12,    13,
      14,    15,    16,   120,    17,    18,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    19,    20,   150,
     151,   152,   153,   100,   101,   106,   107,   125,   146,   147,
      21,   164,    22,    23,   175,   176,   145,   177,   178,   180,
     130,    24,    25,    26,    27,   184,   148,   149,   154,   155,
     162,   189,   163,   190,   170,   173,   174,   179,   192,     1,
     194,     2,     3,     4,   186,     5,     6,   187,   188,   156,
       7,     8,     9,    10,   193,    11,    12,    13,    14,    15,
      16,   157,    17,    18,   158,   160,   159,   185,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
      22,    23,   121,     0,     0,     0,     0,     0,     0,    24,
      25,    26,    27,     1,     0,     2,     3,     4,     0,     5,
       6,     0,     0,     0,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,     0,    17,    18,     0,     0,
       0,     0,     0,     2,     3,     4,     0,     5,     0,    19,
      20,     2,     3,     4,     0,     5,     0,     0,     0,     2,
       3,     4,    21,     5,    22,    23,     0,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    19,    20,     2,
       3,     4,     0,     5,     0,    19,    20,     0,     0,     0,
      21,     0,    64,    19,    20,     0,     0,     0,    21,     0,
      22,    24,    25,    26,    27,     0,    21,   126,     0,    24,
      25,    26,    27,    19,    20,     0,     0,    24,    25,    26,
      27,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27
};

static const yytype_int16 yycheck[] =
{
       8,    19,    20,   123,    62,     7,    24,    25,    26,    27,
       7,    18,    46,    50,    21,    23,     7,    37,    38,     6,
      28,    17,    18,    19,    20,    21,    22,    51,    24,    51,
      50,    55,    68,    55,    65,    66,    67,    71,    58,    50,
      60,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    59,    60,    56,    51,    50,    50,    52,    56,
     118,    69,   182,    61,    62,    56,    17,    18,    19,    20,
      21,    22,    45,    24,    81,    82,    52,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    41,    42,    43,    44,    69,
       0,     1,    70,     3,     4,     5,   113,     7,     8,    52,
      12,    54,    12,    13,    14,    15,    52,    17,    18,    19,
      20,    21,    22,    51,    24,    25,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    37,    38,   102,
     103,   104,   105,    47,    48,    39,    40,     3,    98,    99,
      50,    50,    52,    53,   162,   163,   174,   164,   165,   167,
       7,    61,    62,    63,    64,   172,   100,   101,   106,   107,
      51,   179,    51,   181,    57,    59,    72,    51,   186,     1,
     188,     3,     4,     5,     9,     7,     8,    51,    51,   108,
      12,    13,    14,    15,    52,    17,    18,    19,    20,    21,
      22,   109,    24,    25,   110,   112,   111,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    64,     1,    -1,     3,     4,     5,    -1,     7,
       8,    -1,    -1,    -1,    12,    13,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,    37,
      38,     3,     4,     5,    -1,     7,    -1,    -1,    -1,     3,
       4,     5,    50,     7,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    37,    38,     3,
       4,     5,    -1,     7,    -1,    37,    38,    -1,    -1,    -1,
      50,    -1,    52,    37,    38,    -1,    -1,    -1,    50,    -1,
      52,    61,    62,    63,    64,    -1,    50,    51,    -1,    61,
      62,    63,    64,    37,    38,    -1,    -1,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     7,     8,    12,    13,    14,
      15,    17,    18,    19,    20,    21,    22,    24,    25,    37,
      38,    50,    52,    53,    61,    62,    63,    64,    74,    75,
      76,    77,    78,    79,    81,    82,    83,    84,    85,    87,
      88,    89,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    52,    54,    50,
      50,    84,    50,     6,    52,   105,    92,    92,   105,    80,
      84,    92,    92,    92,    92,     0,    84,     7,    56,    37,
      38,    50,    58,    60,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    65,    66,    67,    61,    62,
      47,    48,    41,    42,    43,    44,    39,    40,    68,    69,
      70,    45,    46,    71,    52,   105,   105,    12,    81,    52,
      51,    54,    84,    50,    52,     3,    51,    90,   105,   105,
       7,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,    92,    92,    92,    92,    93,    93,    94,    94,
      95,    95,    95,    95,    96,    96,    97,    98,    99,   100,
     101,   105,    51,    51,    50,    81,    24,    51,    86,    87,
      57,    51,    55,    59,    72,    84,    84,   105,   105,    51,
      84,    51,    55,     7,   105,   103,     9,    51,    51,    84,
      84,    87,    84,    52,    84,     7
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    {printf(",\n"); do_stm((yyvsp[(2) - (2)].stm));}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {do_stm((yyvsp[(1) - (1)].stm));}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {(yyval.stm) = new_stm_if((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stm), NULL);}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {(yyval.stm) = new_stm_if((yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].stm), (yyvsp[(7) - (7)].stm));}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    {(yyval.stm) = new_stm_while((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stm));}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {(yyval.stm) = new_stm_do((yyvsp[(5) - (7)].expr), (yyvsp[(2) - (7)].stm));}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {(yyval.stm) = new_stm_for((yyvsp[(3) - (7)].stm), (yyvsp[(4) - (7)].stm), (yyvsp[(5) - (7)].expr), (yyvsp[(7) - (7)].stm));}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    {(yyval.stm) = new_stm_compound((yyvsp[(2) - (3)].stm_compound));}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {(yyval.stm_compound) = new_stm_compound_pure((yyvsp[(1) - (1)].stm));}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {
                                                   N_stm_compound* current = (yyvsp[(1) - (2)].stm_compound);
                                                   while (current->next)
                                                       current = current->next;
                                                   current->next = new_stm_compound_pure((yyvsp[(2) - (2)].stm));
                                                   (yyval.stm_compound) = (yyvsp[(1) - (2)].stm_compound);
                                               }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {(yyval.stm) = new_stm_nop();}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {(yyval.stm) = new_stm_expr((yyvsp[(1) - (2)].expr));}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {(yyval.stm) = new_stm_return((yyvsp[(2) - (3)].expr));}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    {(yyval.stm) = new_stm_return(NULL);}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {(yyval.stm) = new_stm_asm((yyvsp[(2) - (2)].str));}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {(yyval.stm) = new_stm_decl((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), NULL, NULL);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {(yyval.stm) = new_stm_decl((yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(5) - (5)].stm), NULL);}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {(yyval.stm) = new_stm_decl((yyvsp[(1) - (6)].str), (yyvsp[(2) - (6)].str), (yyvsp[(6) - (6)].stm), NULL);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {(yyval.stm) = new_stm_decl((yyvsp[(1) - (6)].str), (yyvsp[(2) - (6)].str), (yyvsp[(6) - (6)].stm), (yyvsp[(4) - (6)].argdef));}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    {(yyval.argdef) = new_arg_def((yyvsp[(2) - (2)].str), (yyvsp[(1) - (2)].str));}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {
                                                                        N_arg_def* current;
                                                                        current = (yyvsp[(1) - (4)].argdef);
                                                                        while (current->next != NULL)
                                                                        {
                                                                            current = current->next;
                                                                        }
                                                                        current->next = new_arg_def((yyvsp[(4) - (4)].str), (yyvsp[(3) - (4)].str));
                                                                        (yyval.argdef) = (yyvsp[(1) - (4)].argdef);
                                                                    }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    {(yyval.expr) = new_val_int(atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {(yyval.expr) = new_val_float(atof((yyvsp[(1) - (1)].str)));}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {(yyval.expr) = new_val_string((yyvsp[(1) - (1)].str));}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {(yyval.expr) = new_val_id((yyvsp[(1) - (1)].str));}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    {(yyval.expr) = (yyvsp[(2) - (3)].expr);}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    {(yyval.arg) = new_arg((yyvsp[(1) - (1)].expr));}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    {
        N_arg* current = (yyvsp[(1) - (3)].arg);
        while (current->next != NULL)
            current = current->next;
        current->next = new_arg((yyvsp[(3) - (3)].expr));
        (yyval.arg) = (yyvsp[(1) - (3)].arg);
        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_ARRAY, (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    {(yyval.expr) = new_op_call((yyvsp[(1) - (4)].expr)); ((N_OP_Call*)(yyval.expr)->node)->args = (yyvsp[(3) - (4)].arg);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    {(yyval.expr) = new_op_call((yyvsp[(1) - (3)].expr));}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_DOT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 241 "parser.y"
    {(yyval.expr) = new_op1(current_line, current_char, OP_POST_INC, (yyvsp[(1) - (2)].expr));}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    {(yyval.expr) = new_op1(current_line, current_char, OP_POST_DEC, (yyvsp[(1) - (2)].expr));}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    {(yyval.expr) = new_op1(current_line, current_char, OP_PRE_INC, (yyvsp[(2) - (2)].expr));}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    {(yyval.expr) = new_op1(current_line, current_char, OP_PRE_DEC, (yyvsp[(2) - (2)].expr));}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    {(yyval.expr) = new_op1(current_line, current_char, OP_POS, (yyvsp[(2) - (2)].expr));}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    {(yyval.expr) = new_op1(current_line, current_char, OP_NEG, (yyvsp[(2) - (2)].expr));}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    {(yyval.expr) = new_op1(current_line, current_char, OP_B_NOT, (yyvsp[(2) - (2)].expr));}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 252 "parser.y"
    {(yyval.expr) = new_op1(current_line, current_char, OP_NOT, (yyvsp[(2) - (2)].expr));}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_MUL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_DIV, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_MOD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_ADD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 265 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_SUB, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 270 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_LEFT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_RIGHT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_LT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 277 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_LTE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_GT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_GTE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_EQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 285 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_NEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 290 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_B_AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 295 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_B_XOR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 300 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_B_OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 310 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 315 "parser.y"
    {(yyval.expr) = new_op3((yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr));}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_ADD_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 322 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_SUB_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_MUL_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_DIV_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_MOD_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 326 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_AND_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 327 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_OR_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 328 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_XOR_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_LEFT_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 330 "parser.y"
    {(yyval.expr) = new_op2(current_line, current_char, OP_RIGHT_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;



/* Line 1455 of yacc.c  */
#line 2211 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 337 "parser.y"


int main()
{
    out_debug = fopen("/dev/null", "rw");
    printf("[");
    yyparse();
    printf("]\n");
    return 0;
}

