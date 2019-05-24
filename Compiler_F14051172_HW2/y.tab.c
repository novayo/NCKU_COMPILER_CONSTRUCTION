/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     I_CONST = 258,
     F_CONST = 259,
     STR_CONST = 260,
     IDENTIFIER = 261,
     INC_OP = 262,
     DEC_OP = 263,
     LE_OP = 264,
     GE_OP = 265,
     EQ_OP = 266,
     NE_OP = 267,
     AND_OP = 268,
     OR_OP = 269,
     MUL_ASSIGN = 270,
     DIV_ASSIGN = 271,
     MOD_ASSIGN = 272,
     ADD_ASSIGN = 273,
     SUB_ASSIGN = 274,
     INT = 275,
     FLOAT = 276,
     VOID = 277,
     BOOL = 278,
     STRING = 279,
     IF = 280,
     ELSE = 281,
     WHILE = 282,
     FOR = 283,
     RETURN = 284,
     PRINT = 285,
     TRUE = 286,
     FALSE = 287,
     IFX = 288
   };
#endif
/* Tokens.  */
#define I_CONST 258
#define F_CONST 259
#define STR_CONST 260
#define IDENTIFIER 261
#define INC_OP 262
#define DEC_OP 263
#define LE_OP 264
#define GE_OP 265
#define EQ_OP 266
#define NE_OP 267
#define AND_OP 268
#define OR_OP 269
#define MUL_ASSIGN 270
#define DIV_ASSIGN 271
#define MOD_ASSIGN 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define INT 275
#define FLOAT 276
#define VOID 277
#define BOOL 278
#define STRING 279
#define IF 280
#define ELSE 281
#define WHILE 282
#define FOR 283
#define RETURN 284
#define PRINT 285
#define TRUE 286
#define FALSE 287
#define IFX 288




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw2.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(char *);
void create_symbol();
void insert_symbol(char *, char *, char *, char *);
void dump_symbol();
void yyerror(char *);

void getFuncItem(char *, char *);
void getVarItem(char *, char *);
int table_index[30] = {0};
int table_scope = 0;
struct symbol_table{
	int index;
	char name[30];
	char entry_type[30];
	char data_type[30];
	int scope;
	char formal_parameters[100];
} symbol_table[30][30];
struct symbol_table original_symbol_table;


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "compiler_hw2.y"
{
    int i_val;
    double f_val;
    char* string;
}
/* Line 193 of yacc.c.  */
#line 200 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 213 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   631

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNRULES -- Number of states.  */
#define YYNSTATES  248

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,    55,     2,     2,    44,    38,     2,
      34,    35,    39,    40,    37,    41,    36,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    52,
      45,    51,    46,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    48,    54,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    17,    19,
      21,    23,    27,    32,    36,    39,    42,    44,    48,    50,
      53,    56,    59,    61,    63,    65,    67,    69,    71,    76,
      78,    82,    86,    90,    92,    96,   100,   102,   106,   110,
     114,   118,   120,   124,   128,   130,   134,   136,   140,   142,
     146,   148,   152,   154,   158,   160,   166,   168,   172,   174,
     176,   178,   180,   182,   184,   186,   190,   193,   197,   199,
     203,   205,   209,   211,   213,   215,   217,   219,   222,   224,
     226,   230,   232,   236,   239,   242,   244,   246,   250,   252,
     255,   259,   262,   266,   270,   275,   277,   279,   283,   288,
     292,   294,   297,   301,   306,   309,   311,   314,   317,   319,
     321,   323,   325,   327,   330,   334,   336,   339,   341,   343,
     345,   347,   350,   356,   364,   370,   377,   385,   392,   400,
     403,   407,   409,   412,   414,   416,   418,   424,   430,   437,
     443,   450,   456,   462,   467,   470,   472
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
     102,     0,    -1,     3,    -1,     4,    -1,     6,    -1,    57,
      -1,     5,    -1,    34,    76,    35,    -1,    31,    -1,    32,
      -1,    58,    -1,    59,    34,    35,    -1,    59,    34,    60,
      35,    -1,    59,    36,     6,    -1,    59,     7,    -1,    59,
       8,    -1,    74,    -1,    60,    37,    74,    -1,    59,    -1,
       7,    61,    -1,     8,    61,    -1,    62,    63,    -1,    38,
      -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,    61,
      -1,    34,    86,    35,    63,    -1,    63,    -1,    64,    39,
      63,    -1,    64,    43,    63,    -1,    64,    44,    63,    -1,
      64,    -1,    65,    40,    64,    -1,    65,    41,    64,    -1,
      65,    -1,    66,    45,    65,    -1,    66,    46,    65,    -1,
      66,     9,    65,    -1,    66,    10,    65,    -1,    66,    -1,
      67,    11,    66,    -1,    67,    12,    66,    -1,    67,    -1,
      68,    38,    67,    -1,    68,    -1,    69,    47,    68,    -1,
      69,    -1,    70,    48,    69,    -1,    70,    -1,    71,    13,
      70,    -1,    71,    -1,    72,    14,    71,    -1,    72,    -1,
      72,    49,    76,    50,    73,    -1,    73,    -1,    61,    75,
      74,    -1,    51,    -1,    15,    -1,    16,    -1,    17,    -1,
      18,    -1,    19,    -1,    74,    -1,    76,    37,    74,    -1,
      80,    52,    -1,    80,    78,    52,    -1,    79,    -1,    78,
      37,    79,    -1,    82,    -1,    82,    51,    88,    -1,    22,
      -1,    20,    -1,    21,    -1,    23,    -1,    24,    -1,    80,
      81,    -1,    80,    -1,     6,    -1,    34,    82,    35,    -1,
      84,    -1,    83,    37,    84,    -1,    80,    82,    -1,    80,
      87,    -1,    80,    -1,     6,    -1,    85,    37,     6,    -1,
      81,    -1,    81,    87,    -1,    34,    87,    35,    -1,    34,
      35,    -1,    34,    83,    35,    -1,    87,    34,    35,    -1,
      87,    34,    83,    35,    -1,    74,    -1,    89,    -1,    53,
      90,    54,    -1,    53,    90,    37,    54,    -1,    55,     5,
      55,    -1,    88,    -1,    91,    88,    -1,    90,    37,    88,
      -1,    90,    37,    91,    88,    -1,    92,    51,    -1,    93,
      -1,    92,    93,    -1,    36,     6,    -1,    95,    -1,    98,
      -1,    99,    -1,   100,    -1,   101,    -1,    53,    54,    -1,
      53,    96,    54,    -1,    97,    -1,    96,    97,    -1,    77,
      -1,    94,    -1,   104,    -1,    52,    -1,    76,    52,    -1,
      25,    34,    76,    35,    94,    -1,    25,    34,    76,    35,
      94,    26,    94,    -1,    27,    34,    76,    35,    94,    -1,
      28,    34,    98,    98,    35,    94,    -1,    28,    34,    98,
      98,    76,    35,    94,    -1,    28,    34,    77,    98,    35,
      94,    -1,    28,    34,    77,    98,    76,    35,    94,    -1,
      29,    52,    -1,    29,    76,    52,    -1,   103,    -1,   102,
     103,    -1,   105,    -1,    77,    -1,   104,    -1,    30,    34,
       6,    35,    52,    -1,    30,    34,    89,    35,    52,    -1,
      80,   106,    83,    35,   107,    95,    -1,    80,   106,    83,
      35,    95,    -1,    80,   106,    85,    35,   107,    95,    -1,
      80,   106,    85,    35,    95,    -1,    80,   106,    35,   107,
      95,    -1,    80,   106,    35,    95,    -1,     6,    34,    -1,
      77,    -1,   107,    77,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    70,    74,    75,    76,    77,    78,    79,
      83,    84,    85,    86,    87,    88,    92,    93,    97,    98,
      99,   100,   104,   105,   106,   107,   108,   112,   113,   117,
     118,   119,   120,   124,   125,   126,   130,   131,   132,   133,
     134,   138,   139,   140,   144,   145,   149,   150,   154,   155,
     159,   160,   164,   165,   169,   170,   174,   175,   179,   180,
     181,   182,   183,   184,   188,   189,   193,   194,   198,   199,
     203,   204,   208,   209,   210,   211,   212,   216,   217,   221,
     222,   226,   227,   231,   232,   233,   237,   238,   242,   243,
     247,   248,   249,   250,   251,   255,   256,   257,   258,   262,
     266,   267,   268,   269,   273,   277,   278,   282,   286,   287,
     288,   289,   290,   294,   295,   299,   300,   304,   305,   306,
     310,   311,   315,   316,   320,   321,   322,   323,   324,   328,
     329,   333,   334,   338,   339,   340,   344,   345,   349,   350,
     351,   352,   353,   354,   358,   362,   363
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "I_CONST", "F_CONST", "STR_CONST",
  "IDENTIFIER", "INC_OP", "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "INT", "FLOAT", "VOID", "BOOL", "STRING",
  "IF", "ELSE", "WHILE", "FOR", "RETURN", "PRINT", "TRUE", "FALSE", "IFX",
  "'('", "')'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'",
  "'}'", "'\"'", "$accept", "constant", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "declaration", "init_declarator_list", "init_declarator",
  "type_specifier", "specifier_qualifier_list", "declarator",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "initializer", "string",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "print_func", "function_definition", "id", "declaration_list", 0
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
     285,   286,   287,   288,    40,    41,    46,    44,    38,    42,
      43,    45,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    61,    59,   123,   125,    34
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      61,    61,    62,    62,    62,    62,    62,    63,    63,    64,
      64,    64,    64,    65,    65,    65,    66,    66,    66,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      75,    75,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    87,    87,    88,    88,    88,    88,    89,
      90,    90,    90,    90,    91,    92,    92,    93,    94,    94,
      94,    94,    94,    95,    95,    96,    96,    97,    97,    97,
      98,    98,    99,    99,   100,   100,   100,   100,   100,   101,
     101,   102,   102,   103,   103,   103,   104,   104,   105,   105,
     105,   105,   105,   105,   106,   107,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     4,     3,     2,     2,     1,     3,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     2,     1,     1,
       3,     1,     3,     2,     2,     1,     1,     3,     1,     2,
       3,     2,     3,     3,     4,     1,     1,     3,     4,     3,
       1,     2,     3,     4,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     2,     3,     1,     2,     1,     1,     1,
       1,     2,     5,     7,     5,     6,     7,     6,     7,     2,
       3,     1,     2,     1,     1,     1,     5,     5,     6,     5,
       6,     5,     5,     4,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    73,    74,    72,    75,    76,     0,   134,     0,     0,
     131,   135,   133,     0,    79,     0,    66,     0,    68,    70,
       0,     1,   132,     0,     0,     0,   144,    79,     0,     0,
      67,     0,    86,     0,    85,     0,    81,     0,     0,     0,
       0,    80,    69,     2,     3,     6,     4,     0,     0,     8,
       9,     0,    22,    23,    24,    25,    26,     0,     5,    10,
      18,    27,     0,    29,    33,    36,    41,    44,    46,    48,
      50,    52,    54,    56,    95,    71,    96,     0,   145,     0,
     143,     0,     0,    83,    84,     0,     0,     0,     0,   136,
      99,   137,     0,    19,    20,    64,     0,    78,    88,     0,
       0,   100,     0,     0,     0,   105,    14,    15,     0,     0,
      59,    60,    61,    62,    63,    58,     0,    27,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   113,     0,   117,   118,   108,     0,   115,   109,   110,
     111,   112,   119,   146,   142,    91,     0,     0,     0,   139,
       0,    82,   141,     0,    87,     7,     0,    77,     0,    89,
       0,   107,     0,    97,   101,   104,   106,    11,     0,    16,
      13,    57,    30,    31,    32,    34,    35,    39,    40,    37,
      38,    42,    43,    45,    47,    49,    51,    53,     0,     0,
       0,     0,   129,     0,   121,   114,   116,    92,    90,    93,
       0,   138,   140,    65,    28,    98,   102,     0,    12,     0,
       0,     0,     0,     0,     0,   130,    94,   103,    17,    55,
       0,     0,     0,     0,   122,   124,     0,     0,     0,     0,
       0,   127,     0,   125,     0,   123,   128,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    58,    59,    60,   178,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    95,   116,
     142,    78,    17,    18,    79,    98,    19,   156,    36,    37,
      99,   157,    75,    76,   102,   103,   104,   105,   144,   145,
     146,   147,   148,   149,   150,   151,     9,    10,    11,    12,
      20,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -163
static const yytype_int16 yypact[] =
{
     230,  -163,  -163,  -163,  -163,  -163,    -8,  -163,     4,   158,
    -163,  -163,  -163,     5,    -1,    11,  -163,    -6,  -163,   -29,
     596,  -163,  -163,    12,    58,    41,  -163,  -163,    49,    11,
    -163,   224,  -163,   106,    18,    48,  -163,    53,    86,    99,
      89,  -163,  -163,  -163,  -163,  -163,  -163,   545,   545,  -163,
    -163,   465,  -163,  -163,  -163,  -163,  -163,   206,  -163,  -163,
       7,   105,   567,  -163,    69,   -11,     9,   122,   119,   129,
     135,   178,     2,  -163,  -163,  -163,  -163,   264,  -163,     6,
    -163,   106,   590,  -163,   160,   106,   202,   106,   189,  -163,
    -163,  -163,   567,  -163,  -163,  -163,    74,   202,   165,   168,
     210,  -163,   -12,   224,    38,  -163,  -163,  -163,   487,   212,
    -163,  -163,  -163,  -163,  -163,  -163,   567,  -163,  -163,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   200,   205,   207,   406,
    -163,  -163,    -3,  -163,  -163,  -163,   304,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,   102,    83,    47,  -163,
     106,  -163,  -163,   106,  -163,  -163,   567,  -163,   569,   160,
     567,  -163,   166,  -163,  -163,  -163,  -163,  -163,   118,  -163,
    -163,  -163,  -163,  -163,  -163,    69,    69,   -11,   -11,   -11,
     -11,     9,     9,   122,   119,   129,   135,   178,   -14,   567,
     567,   384,  -163,    79,  -163,  -163,  -163,  -163,  -163,  -163,
     130,  -163,  -163,  -163,  -163,  -163,  -163,   224,  -163,   567,
     567,   131,   140,   425,   425,  -163,  -163,  -163,  -163,  -163,
     344,   344,   505,   527,   217,  -163,   344,   155,   344,   180,
     344,  -163,   344,  -163,   344,  -163,  -163,  -163
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,  -163,  -163,   -27,  -163,   -55,    22,    23,
      33,   127,   142,   104,   116,   141,  -163,    54,   -30,  -163,
     -48,     0,  -163,   247,    28,   181,    -2,   -18,   194,  -163,
    -163,   -26,   -53,   268,  -163,   110,  -163,   179,   123,   -28,
    -163,   144,  -162,  -163,  -163,  -163,  -163,   288,   -71,  -163,
    -163,   148
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       7,    74,    35,    96,   101,    80,   152,   118,    84,     7,
      14,    23,    27,    28,   106,   107,   134,    27,   124,   125,
      93,    94,    31,   166,    27,   172,    13,    74,     8,   122,
     123,    29,    83,    26,   166,   117,   220,     8,    15,   224,
      15,   108,   173,   109,    96,    15,    30,    38,    34,   204,
     174,   135,    82,   154,   126,   127,    16,   159,    16,   162,
      24,   232,   233,    39,   182,   183,   184,     1,     2,     3,
       4,     5,   169,    74,   100,   152,    40,   143,   179,    97,
      28,   153,   209,    85,    41,    86,   181,   198,    87,   175,
      88,   203,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   119,   165,
      34,   166,   120,   121,    34,   214,   166,   158,   208,   216,
     110,   111,   112,   113,   114,    97,     1,     2,     3,     4,
       5,   225,   211,   128,   129,   212,   213,   207,    89,    86,
     210,    91,    74,   117,   185,   186,   143,   187,   188,   189,
     190,   221,   222,   218,    90,   219,   115,   130,    21,    77,
     153,   191,   192,   153,   227,   226,   230,    86,   166,    43,
      44,    45,    46,    47,    48,   231,   131,   166,     1,     2,
       3,     4,     5,   132,   237,   239,    34,    74,     6,   228,
     242,   133,   166,   117,   158,   164,    34,    49,    50,   168,
      51,   223,   100,   170,    52,    53,    54,    55,    56,    43,
      44,    45,    46,    47,    48,   244,   171,   166,   180,    57,
     215,    24,     1,     2,     3,     4,     5,    43,    44,    45,
      46,    47,    48,   160,   199,   163,   195,    49,    50,   200,
      51,   201,   100,   240,    52,    53,    54,    55,    56,   196,
       1,     2,     3,     4,     5,    49,    50,   193,    51,    57,
       6,    24,    52,    53,    54,    55,    56,    43,    44,    45,
      46,    47,    48,   194,   229,   197,    42,    57,   167,    24,
     161,    25,   217,   176,     1,     2,     3,     4,     5,   136,
     206,   137,   138,   139,     6,    49,    50,    22,    51,     0,
       0,     0,    52,    53,    54,    55,    56,    43,    44,    45,
      46,    47,    48,     0,     0,     0,   140,    77,   141,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,   136,
       0,   137,   138,   139,     6,    49,    50,     0,    51,     0,
       0,     0,    52,    53,    54,    55,    56,    43,    44,    45,
      46,    47,    48,   234,   235,     0,   140,    77,   205,   241,
       0,   243,     0,   245,     0,   246,     0,   247,     0,   136,
       0,   137,   138,   139,     0,    49,    50,     0,    51,     0,
       0,     0,    52,    53,    54,    55,    56,    43,    44,    45,
      46,    47,    48,     0,     0,     0,   140,    77,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,    43,
      44,    45,    46,    47,    48,    49,    50,     0,    51,     0,
       0,     0,    52,    53,    54,    55,    56,     0,    43,    44,
      45,    46,    47,    48,     0,     0,   140,    49,    50,     0,
      51,     0,     0,     0,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,    49,    50,   202,    51,
       0,     0,     0,    52,    53,    54,    55,    56,    43,    44,
      45,    46,    47,    48,     0,     0,     0,   140,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
      43,    44,    45,    46,    47,    48,    49,    50,     0,    51,
       0,     0,     0,    52,    53,    54,    55,    56,    43,    44,
      45,    46,    47,    48,     0,     0,     0,     0,    49,    50,
       0,    51,   177,     0,     0,    52,    53,    54,    55,    56,
      43,    44,    45,    46,    47,    48,    49,    50,     0,    51,
     236,     0,     0,    52,    53,    54,    55,    56,    43,    44,
      45,    46,    47,    48,     0,     0,     0,     0,    49,    50,
       0,    51,   238,     0,     0,    52,    53,    54,    55,    56,
      43,    44,    45,    46,    47,    48,    49,    50,     0,    92,
       0,     0,     0,    52,    53,    54,    55,    56,     0,     1,
       2,     3,     4,     5,     0,     0,    27,     0,    49,    50,
       0,    51,    32,   168,   155,    52,    53,    54,    55,    56,
       1,     2,     3,     4,     5,     0,     1,     2,     3,     4,
       5,     0,     0,     0,    82,   155,     0,     0,     0,     0,
       0,    33
};

static const yytype_int16 yycheck[] =
{
       0,    31,    20,    51,    57,    33,    77,    62,    34,     9,
       6,     6,     6,    15,     7,     8,    14,     6,     9,    10,
      47,    48,    51,    37,     6,    37,    34,    57,     0,    40,
      41,    37,    34,    34,    37,    62,    50,     9,    34,   201,
      34,    34,    54,    36,    92,    34,    52,    35,    20,    52,
     103,    49,    34,    81,    45,    46,    52,    85,    52,    87,
      55,   223,   224,     5,   119,   120,   121,    20,    21,    22,
      23,    24,    98,   103,    36,   146,    35,    77,   108,    51,
      82,    81,    35,    35,    35,    37,   116,   135,    35,    51,
      37,   139,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    39,    35,
      82,    37,    43,    44,    86,   170,    37,    34,    35,   172,
      15,    16,    17,    18,    19,    97,    20,    21,    22,    23,
      24,    52,   160,    11,    12,   163,   166,    35,    52,    37,
     158,    52,   172,   170,   122,   123,   146,   124,   125,   126,
     127,   199,   200,    35,    55,    37,    51,    38,     0,    53,
     160,   128,   129,   163,   217,    35,    35,    37,    37,     3,
       4,     5,     6,     7,     8,    35,    47,    37,    20,    21,
      22,    23,    24,    48,   232,   233,   158,   217,    30,   219,
      35,    13,    37,   220,    34,     6,   168,    31,    32,    34,
      34,   201,    36,    35,    38,    39,    40,    41,    42,     3,
       4,     5,     6,     7,     8,    35,     6,    37,     6,    53,
      54,    55,    20,    21,    22,    23,    24,     3,     4,     5,
       6,     7,     8,    85,    34,    87,   132,    31,    32,    34,
      34,    34,    36,    26,    38,    39,    40,    41,    42,   133,
      20,    21,    22,    23,    24,    31,    32,   130,    34,    53,
      30,    55,    38,    39,    40,    41,    42,     3,     4,     5,
       6,     7,     8,   131,   220,   134,    29,    53,    97,    55,
      86,    13,   172,   104,    20,    21,    22,    23,    24,    25,
     146,    27,    28,    29,    30,    31,    32,     9,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,     3,     4,     5,
       6,     7,     8,   230,   231,    -1,    52,    53,    54,   236,
      -1,   238,    -1,   240,    -1,   242,    -1,   244,    -1,    25,
      -1,    27,    28,    29,    -1,    31,    32,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,     3,
       4,     5,     6,     7,     8,    31,    32,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,    52,    31,    32,    -1,
      34,    -1,    -1,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    52,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
       3,     4,     5,     6,     7,     8,    31,    32,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    -1,    -1,    38,    39,    40,    41,    42,
       3,     4,     5,     6,     7,     8,    31,    32,    -1,    34,
      35,    -1,    -1,    38,    39,    40,    41,    42,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    -1,    -1,    38,    39,    40,    41,    42,
       3,     4,     5,     6,     7,     8,    31,    32,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    -1,    20,
      21,    22,    23,    24,    -1,    -1,     6,    -1,    31,    32,
      -1,    34,     6,    34,    35,    38,    39,    40,    41,    42,
      20,    21,    22,    23,    24,    -1,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    23,    24,    30,    77,    80,   102,
     103,   104,   105,    34,     6,    34,    52,    78,    79,    82,
     106,     0,   103,     6,    55,    89,    34,     6,    82,    37,
      52,    51,     6,    35,    80,    83,    84,    85,    35,     5,
      35,    35,    79,     3,     4,     5,     6,     7,     8,    31,
      32,    34,    38,    39,    40,    41,    42,    53,    57,    58,
      59,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    88,    89,    53,    77,    80,
      95,   107,    34,    82,    87,    35,    37,    35,    37,    52,
      55,    52,    34,    61,    61,    74,    76,    80,    81,    86,
      36,    88,    90,    91,    92,    93,     7,     8,    34,    36,
      15,    16,    17,    18,    19,    51,    75,    61,    63,    39,
      43,    44,    40,    41,     9,    10,    45,    46,    11,    12,
      38,    47,    48,    13,    14,    49,    25,    27,    28,    29,
      52,    54,    76,    77,    94,    95,    96,    97,    98,    99,
     100,   101,   104,    77,    95,    35,    83,    87,    34,    95,
     107,    84,    95,   107,     6,    35,    37,    81,    34,    87,
      35,     6,    37,    54,    88,    51,    93,    35,    60,    74,
       6,    74,    63,    63,    63,    64,    64,    65,    65,    65,
      65,    66,    66,    67,    68,    69,    70,    71,    76,    34,
      34,    34,    52,    76,    52,    54,    97,    35,    35,    35,
      83,    95,    95,    74,    63,    54,    88,    91,    35,    37,
      50,    76,    76,    77,    98,    52,    35,    88,    74,    73,
      35,    35,    98,    98,    94,    94,    35,    76,    35,    76,
      26,    94,    35,    94,    35,    94,    94,    94
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 4:
#line 74 "compiler_hw2.y"
    { /*不用理他，不是宣告部分*/ }
    break;

  case 67:
#line 194 "compiler_hw2.y"
    { getVarItem((yyvsp[(1) - (3)].string), (yyvsp[(2) - (3)].string)); }
    break;

  case 68:
#line 198 "compiler_hw2.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 70:
#line 203 "compiler_hw2.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 72:
#line 208 "compiler_hw2.y"
    {(yyval.string) = "void";}
    break;

  case 73:
#line 209 "compiler_hw2.y"
    {(yyval.string) = "int";}
    break;

  case 74:
#line 210 "compiler_hw2.y"
    {(yyval.string) = "float";}
    break;

  case 75:
#line 211 "compiler_hw2.y"
    {(yyval.string) = "bool";}
    break;

  case 76:
#line 212 "compiler_hw2.y"
    {(yyval.string) = "string";}
    break;

  case 79:
#line 221 "compiler_hw2.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 80:
#line 222 "compiler_hw2.y"
    {}
    break;

  case 138:
#line 349 "compiler_hw2.y"
    {printf("%d: }\n", yylineno+1); getFuncItem((yyvsp[(1) - (6)].string), (yyvsp[(2) - (6)].string)); dump_symbol();}
    break;

  case 139:
#line 350 "compiler_hw2.y"
    {printf("%d: }\n", yylineno+1); getFuncItem((yyvsp[(1) - (5)].string), (yyvsp[(2) - (5)].string)); dump_symbol();}
    break;

  case 140:
#line 351 "compiler_hw2.y"
    {printf("%d: }\n", yylineno+1); getFuncItem((yyvsp[(1) - (6)].string), (yyvsp[(2) - (6)].string)); dump_symbol();}
    break;

  case 141:
#line 352 "compiler_hw2.y"
    {printf("%d: }\n", yylineno+1); getFuncItem((yyvsp[(1) - (5)].string), (yyvsp[(2) - (5)].string)); dump_symbol();}
    break;

  case 142:
#line 353 "compiler_hw2.y"
    {printf("%d: }\n", yylineno+1); table_scope--;getFuncItem((yyvsp[(1) - (5)].string), (yyvsp[(2) - (5)].string)); table_scope++;dump_symbol();}
    break;

  case 143:
#line 354 "compiler_hw2.y"
    {printf("%d: }\n", yylineno+1); table_scope--;getFuncItem((yyvsp[(1) - (4)].string), (yyvsp[(2) - (4)].string)); table_scope++;dump_symbol();}
    break;

  case 144:
#line 358 "compiler_hw2.y"
    {(yyval.string) = (yyvsp[(1) - (2)].string); table_scope++;}
    break;


/* Line 1267 of yacc.c.  */
#line 1822 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 367 "compiler_hw2.y"


/* C code section */
int main(int argc, char** argv)
{
	create_symbol();
    yylineno = 0;
    yyparse();
	while (table_scope >= 0) {
		dump_symbol();
		table_scope--;
	}
	printf("\nTotal lines: %d \n", yylineno);

    return 0;
}

void getFuncItem(char * str_type, char * str){
	char p[30][30] = {'\0'};
	int p_count = 0;
	char strbuf[1000] = {'\0'};
	for (int i=0; i<strlen(str); i++) strbuf[i] = str[i];

    char * func = strtok(strbuf, "(");

	char strbuf1[1000] = {'\0'};
	for (int i=0; i<strlen(str); i++) strbuf1[i] = str[i];
	char * pars = strtok(strbuf1, ")");


	char * subpar = NULL;
	subpar = strtok(pars, "(");
	subpar = strtok(NULL, "(");
	if (subpar == NULL){
		insert_symbol(func, "function", str_type, "");
		return;
	}
	
	char strbuf2[1000] = {'\0'};
	for (int i=0; i<strlen(subpar); i++) strbuf2[i] = subpar[i];
	char * subpar2 = strtok(strbuf2, " ");
	char func_pars[100] = {'\0'};

	do {
		if (subpar2[strlen(subpar2)-1] == ',') subpar2[strlen(subpar2)-1] = '\0';
		for (int i=0; i<strlen(subpar2); i++) p[p_count][i] = subpar2[i];
		if (++p_count % 2 == 0){
			insert_symbol(p[p_count-1], "parameter", p[p_count-2], "");
			int tmp = strlen(func_pars);
			for (int i=tmp; i<strlen(p[p_count-2]) + tmp; i++) func_pars[i] = p[p_count-2][i - tmp];
			tmp = strlen(func_pars);
			func_pars[tmp] = ',';
			func_pars[tmp+1] = ' ';
		}
        subpar2 = strtok(NULL, " ");
    } while (subpar2);
	int tmp = strlen(func_pars);
	func_pars[tmp-1] = '\0';
	func_pars[tmp-2] = '\0';

	table_scope--;
	insert_symbol(func, "function", str_type, func_pars);
	table_scope++;
}

void getVarItem(char * stype, char * sname){
	int tmp = strlen(sname);
	if (sname[tmp-1] == '=') {
		sname[tmp-1] = '\0';
		sname[tmp-2] = '\0';
	}

	char strbuf[1000] = {'\0'};
	for (int i=0; i<strlen(sname); i++) strbuf[i] = sname[i];

    char * var = strtok(strbuf, " =");
	if (var[strlen(var)-1] == ';') var[strlen(var)-1] = '\0';
 
	insert_symbol(var, "variable", stype, "");
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
	exit(0);
}

void create_symbol() {
	for (int i=0; i<30; i++) 
		for (int j=0; j<30; j++) 
			symbol_table[i][j] = original_symbol_table;
}

void insert_symbol(char * sname, char * sentry_type, char * sdata_type, char * sformal_parameter) {
	symbol_table[table_scope][table_index[table_scope]].index = table_index[table_scope];
	for (int i=0; i<strlen(sname); i++) symbol_table[table_scope][table_index[table_scope]].name[i] = sname[i];
	for (int i=0; i<strlen(sentry_type); i++) symbol_table[table_scope][table_index[table_scope]].entry_type[i] = sentry_type[i];
	for (int i=0; i<strlen(sdata_type); i++) symbol_table[table_scope][table_index[table_scope]].data_type[i] = sdata_type[i];
	symbol_table[table_scope][table_index[table_scope]].scope = table_scope;
	for (int i=0; i<strlen(sformal_parameter); i++) symbol_table[table_scope][table_index[table_scope]].formal_parameters[i] = sformal_parameter[i];
	table_index[table_scope]++;
}
int lookup_symbol(char *sname) {
	int isExist = 0;
	for (int i=0; i<table_index[table_scope]; i++) {
		if (strcmp(symbol_table[table_scope][i].name, sname) == 0){
			isExist = 1;
			break;
		}
	}
	if (isExist == 0) return 0;
	else return 1;
}

void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	for (int i=0; i<table_index[table_scope]; i++){
		printf("%-10d%-10s%-12s%-10s%-10d%-10s\n",
		   symbol_table[table_scope][i].index, symbol_table[table_scope][i].name, symbol_table[table_scope][i].entry_type,
		   symbol_table[table_scope][i].data_type, symbol_table[table_scope][i].scope, symbol_table[table_scope][i].formal_parameters);
		symbol_table[table_scope][i] = original_symbol_table;
	}
	
	table_index[table_scope] = 0;
	table_scope--;
	printf("\n\n");
}


