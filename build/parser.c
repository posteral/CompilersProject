/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 1 "parser.y"

//#define YYDEBUG 1 
#include <stdio.h>
#include "main.h"

//yydebug = 1;


/* Line 268 of yacc.c  */
#line 80 "/home/ingrid/Desktop/CompilersProject/build/parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     TK_PR_INT = 258,
     TK_PR_FLOAT = 259,
     TK_PR_BOOL = 260,
     TK_PR_CHAR = 261,
     TK_PR_STRING = 262,
     TK_PR_IF = 263,
     TK_PR_THEN = 264,
     TK_PR_ELSE = 265,
     TK_PR_WHILE = 266,
     TK_PR_DO = 267,
     TK_PR_INPUT = 268,
     TK_PR_OUTPUT = 269,
     TK_PR_RETURN = 270,
     TK_OC_LE = 271,
     TK_OC_GE = 272,
     TK_OC_EQ = 273,
     TK_OC_NE = 274,
     TK_OC_AND = 275,
     TK_OC_OR = 276,
     TK_LIT_INT = 277,
     TK_LIT_FLOAT = 278,
     TK_LIT_FALSE = 279,
     TK_LIT_TRUE = 280,
     TK_LIT_CHAR = 281,
     TK_LIT_STRING = 282,
     TK_IDENTIFICADOR = 283,
     TOKEN_ERRO = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 12 "parser.y"
 
  struct comp_dict_item_t *symbol; 


/* Line 293 of yacc.c  */
#line 17 "parser.y"

 struct comp_tree_t *tree_node;



/* Line 293 of yacc.c  */
#line 157 "/home/ingrid/Desktop/CompilersProject/build/parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 169 "/home/ingrid/Desktop/CompilersProject/build/parser.c"

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   309

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,     2,     2,     2,     2,     2,
      42,    43,    34,    32,    44,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      30,    45,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    37,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    12,    15,    18,    21,
      27,    29,    31,    33,    35,    37,    41,    47,    49,    50,
      54,    56,    59,    63,    64,    68,    70,    74,    76,    78,
      80,    82,    84,    86,    88,    90,    92,    93,    97,   104,
     107,   110,   114,   116,   119,   124,   126,   128,   132,   134,
     135,   137,   144,   153,   160,   167,   169,   174,   176,   178,
     180,   182,   184,   186,   190,   194,   197,   200,   203,   207,
     211,   215,   219,   223,   227,   231,   235,   239,   243,   247
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    48,    -1,    53,    48,
      -1,    -1,    50,    36,    -1,    51,    36,    -1,    52,    28,
      -1,    52,    28,    40,    75,    41,    -1,     3,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,    54,    58,    59,
      -1,    52,    28,    42,    55,    43,    -1,    56,    -1,    -1,
      57,    44,    56,    -1,    57,    -1,    52,    28,    -1,    50,
      36,    58,    -1,    -1,    38,    60,    37,    -1,    61,    -1,
      61,    36,    60,    -1,    62,    -1,    63,    -1,    59,    -1,
      69,    -1,    74,    -1,    64,    -1,    65,    -1,    66,    -1,
      68,    -1,    -1,    28,    45,    75,    -1,    28,    40,    75,
      41,    45,    75,    -1,    13,    28,    -1,    14,    67,    -1,
      75,    44,    67,    -1,    75,    -1,    15,    75,    -1,    28,
      42,    70,    43,    -1,    71,    -1,    72,    -1,    73,    44,
      71,    -1,    73,    -1,    -1,    75,    -1,     8,    42,    75,
      43,     9,    62,    -1,     8,    42,    75,    43,     9,    62,
      10,    62,    -1,    11,    42,    75,    43,    12,    62,    -1,
      12,    62,    11,    42,    75,    43,    -1,    28,    -1,    28,
      40,    75,    41,    -1,    22,    -1,    23,    -1,    24,    -1,
      25,    -1,    26,    -1,    27,    -1,    75,    32,    75,    -1,
      75,    33,    75,    -1,    39,    75,    -1,    32,    75,    -1,
      33,    75,    -1,    75,    34,    75,    -1,    75,    35,    75,
      -1,    75,    30,    75,    -1,    75,    31,    75,    -1,    42,
      75,    43,    -1,    75,    16,    75,    -1,    75,    17,    75,
      -1,    75,    18,    75,    -1,    75,    19,    75,    -1,    75,
      20,    75,    -1,    75,    21,    75,    -1,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    97,   101,   110,   114,   114,   115,   116,
     117,   117,   117,   117,   117,   119,   129,   130,   130,   131,
     131,   132,   133,   133,   135,   144,   145,   154,   154,   155,
     155,   155,   155,   155,   155,   155,   156,   157,   169,   187,
     197,   205,   211,   212,   221,   235,   235,   237,   243,   244,
     245,   247,   257,   269,   279,   290,   296,   309,   318,   327,
     336,   345,   354,   360,   370,   380,   388,   389,   397,   407,
     417,   427,   437,   438,   448,   458,   468,   478,   488,   498
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_STRING", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE",
  "TK_PR_WHILE", "TK_PR_DO", "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN",
  "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR",
  "TK_LIT_INT", "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE",
  "TK_LIT_CHAR", "TK_LIT_STRING", "TK_IDENTIFICADOR", "TOKEN_ERRO", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "';'", "'}'", "'{'", "'!'", "'['",
  "']'", "'('", "')'", "','", "'='", "$accept", "s", "program",
  "global_var_declaration", "var_declaration", "vector_declaration",
  "var_type", "function_declaration", "header", "parameter_list",
  "non_void_parameter_list", "parameter", "local_var_declaration",
  "command_block", "command_sequence", "statement", "non_void_command",
  "void_command", "assignment", "input", "output",
  "non_void_expression_list", "return", "func_call", "arg_list",
  "non_void_arg_list", "void_arg_list", "arg", "control_flow",
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
      60,    62,    43,    45,    42,    47,    59,   125,   123,    33,
      91,    93,    40,    41,    44,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    49,    50,    51,
      52,    52,    52,    52,    52,    53,    54,    55,    55,    56,
      56,    57,    58,    58,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    63,    64,    64,    65,
      66,    67,    67,    68,    69,    70,    70,    71,    71,    72,
      73,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     2,     2,     2,     5,
       1,     1,     1,     1,     1,     3,     5,     1,     0,     3,
       1,     2,     3,     0,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     6,     2,
       2,     3,     1,     2,     4,     1,     1,     3,     1,     0,
       1,     6,     8,     6,     6,     1,     4,     1,     1,     1,
       1,     1,     1,     3,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    10,    11,    12,    13,    14,     0,     2,     5,     0,
       0,     0,     5,    23,     1,     3,     6,     7,     8,     4,
       0,     0,     0,     0,    18,    23,     8,    36,    15,    57,
      58,    59,    60,    61,    62,    55,     0,     0,     0,     0,
      79,     0,     0,     0,    17,    20,    22,     0,     0,     0,
       0,     0,     0,     0,    29,     0,    25,    27,    28,    32,
      33,    34,    35,    30,    31,     0,    49,    66,    67,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    21,    16,     0,     0,     0,     0,
      39,    40,    42,    43,     0,     0,    24,    36,     0,     0,
      45,    46,    48,    50,    72,    73,    74,    75,    76,    77,
      78,    70,    71,    63,    64,    68,    69,    19,     0,     0,
       0,     0,     0,    37,    26,    56,    44,     0,     0,     0,
       0,    41,     0,    47,     0,     0,     0,     0,    51,    53,
      54,    38,     0,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    43,
      44,    45,    22,    54,    55,    56,    57,    58,    59,    60,
      61,    91,    62,    40,    99,   100,   101,   102,    64,    92
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -49
static const yytype_int16 yypact[] =
{
      34,   -49,   -49,   -49,   -49,   -49,     4,   -49,    34,   -29,
     -22,    -4,    34,    34,   -49,   -49,   -49,   -49,   -37,   -49,
      -1,    15,    -6,   247,    34,    34,   -49,    -2,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -13,   247,   247,   247,   247,
     -49,   175,    36,    25,   -49,    21,   -49,     0,    27,    -2,
      43,   247,   247,   -17,   -49,    35,    39,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   247,   247,    28,    28,   -49,
     107,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   -49,   -49,   -49,    34,   247,   247,    65,
     -49,   -49,   101,   274,   247,   247,   -49,    -2,   201,    37,
     -49,   -49,    33,   274,   -49,    14,    14,    14,    14,    66,
     221,    14,    14,    28,    28,   -49,   -49,   -49,   135,   141,
      46,   247,   227,   274,   -49,   -49,   -49,   247,    69,    67,
     247,   -49,    44,   -49,    -2,    -2,   169,   247,    80,   -49,
     -49,   274,    -2,   -49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,    22,   -49,     8,   -49,    -5,   -49,   -49,   -49,
       5,   -49,    68,    70,     6,   -49,   -48,   -49,   -49,   -49,
     -49,   -26,   -49,   -27,   -49,   -25,   -49,   -49,   -49,   -21
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      63,    89,    41,    23,    14,    24,    47,    16,    21,    48,
      49,    50,    51,    52,    17,    67,    68,    69,    70,    42,
      21,    20,    63,    94,    18,    66,    53,    65,    95,    66,
      15,    93,    27,    20,    19,    25,    27,     1,     2,     3,
       4,     5,    87,    26,    98,   103,    79,    80,    81,    82,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    81,    82,    84,    86,   118,   119,    85,    88,
      63,    90,    96,   122,   123,    97,   120,   127,   134,   135,
     126,    42,    71,    72,    73,    74,   138,   139,   130,   137,
     142,   117,    28,    46,   143,   131,    77,    78,    79,    80,
      81,    82,   133,   124,     0,     0,   103,    63,    63,   136,
       0,     0,     0,     0,     0,    63,   141,    71,    72,    73,
      74,    75,    76,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,    79,    80,    81,    82,    77,    78,    79,
      80,    81,    82,     0,     0,   121,     0,     0,     0,     0,
     104,    71,    72,    73,    74,    75,    76,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,    79,    80,    81,
      82,    77,    78,    79,    80,    81,    82,     0,   128,     0,
       0,     0,     0,     0,   129,    71,    72,    73,    74,    75,
      76,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,    79,    80,    81,    82,    77,    78,    79,    80,    81,
      82,     0,   140,     0,     0,     0,    83,    71,    72,    73,
      74,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    71,    72,    73,
      74,    75,   125,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,    79,    80,    81,    82,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,     0,   132,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,    36,
      37,     0,     0,     0,     0,     0,    38,     0,     0,    39,
      71,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-49))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      27,    49,    23,    40,     0,    42,     8,    36,    13,    11,
      12,    13,    14,    15,    36,    36,    37,    38,    39,    24,
      25,    13,    49,    40,    28,    42,    28,    40,    45,    42,
       8,    52,    38,    25,    12,    36,    38,     3,     4,     5,
       6,     7,    42,    28,    65,    66,    32,    33,    34,    35,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    34,    35,    28,    44,    87,    88,    43,    42,
      97,    28,    37,    94,    95,    36,    11,    44,     9,    12,
      43,    86,    16,    17,    18,    19,   134,   135,    42,    45,
      10,    86,    22,    25,   142,   121,    30,    31,    32,    33,
      34,    35,   127,    97,    -1,    -1,   127,   134,   135,   130,
      -1,    -1,    -1,    -1,    -1,   142,   137,    16,    17,    18,
      19,    20,    21,    16,    17,    18,    19,    20,    21,    -1,
      -1,    30,    31,    32,    33,    34,    35,    30,    31,    32,
      33,    34,    35,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      43,    16,    17,    18,    19,    20,    21,    16,    17,    18,
      19,    20,    21,    -1,    -1,    30,    31,    32,    33,    34,
      35,    30,    31,    32,    33,    34,    35,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    43,    16,    17,    18,    19,    20,
      21,    16,    17,    18,    19,    20,    21,    -1,    -1,    30,
      31,    32,    33,    34,    35,    30,    31,    32,    33,    34,
      35,    -1,    43,    -1,    -1,    -1,    41,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    16,    17,    18,
      19,    20,    41,    16,    17,    18,    19,    20,    21,    -1,
      -1,    30,    31,    32,    33,    34,    35,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    41,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    32,
      33,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    47,    48,    49,    50,
      51,    52,    53,    54,     0,    48,    36,    36,    28,    48,
      50,    52,    58,    40,    42,    36,    28,    38,    59,    22,
      23,    24,    25,    26,    27,    28,    32,    33,    39,    42,
      69,    75,    52,    55,    56,    57,    58,     8,    11,    12,
      13,    14,    15,    28,    59,    60,    61,    62,    63,    64,
      65,    66,    68,    69,    74,    40,    42,    75,    75,    75,
      75,    16,    17,    18,    19,    20,    21,    30,    31,    32,
      33,    34,    35,    41,    28,    43,    44,    42,    42,    62,
      28,    67,    75,    75,    40,    45,    37,    36,    75,    70,
      71,    72,    73,    75,    43,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    56,    75,    75,
      11,    44,    75,    75,    60,    41,    43,    44,    43,    43,
      42,    67,    41,    71,     9,    12,    75,    45,    62,    62,
      43,    75,    10,    62
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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

/* Line 1806 of yacc.c  */
#line 88 "parser.y"
    {	
			(yyval.tree_node) = treeCreateNode(1, IKS_AST_PROGRAMA, NULL);
			//printf("\nprogram\n");
			treeAppendNode((yyval.tree_node), (yyvsp[(1) - (1)].tree_node));
			gv_declare(IKS_AST_PROGRAMA, (const void*)(yyval.tree_node), NULL);
			if((yyvsp[(1) - (1)].tree_node)!=NULL)
				gv_connect((yyval.tree_node), (yyvsp[(1) - (1)].tree_node));			
		}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 98 "parser.y"
    {
				(yyval.tree_node) = (yyvsp[(2) - (2)].tree_node);
			}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 102 "parser.y"
    {
				if((yyvsp[(2) - (2)].tree_node)!=NULL)
					{
						treeAppendNode((yyvsp[(1) - (2)].tree_node), (yyvsp[(2) - (2)].tree_node));
						gv_connect((yyvsp[(1) - (2)].tree_node), (yyvsp[(2) - (2)].tree_node));
					}
				(yyval.tree_node) = (yyvsp[(1) - (2)].tree_node);		
			}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 110 "parser.y"
    {
				(yyval.tree_node) = NULL;
			}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 115 "parser.y"
    { }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 120 "parser.y"
    {		
						//printf("\nfunction_declaration");	
						(yyval.tree_node) = treeCreateNode(2, IKS_AST_FUNCAO, (yyvsp[(1) - (3)].symbol));
						if((yyvsp[(3) - (3)].tree_node)!=NULL)
							treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
						gv_declare(IKS_AST_FUNCAO, (const void*)(yyval.tree_node), ((comp_dict_item_t*)(yyvsp[(1) - (3)].symbol))->data.identifier_type);
						if((yyvsp[(3) - (3)].tree_node)!=NULL)
							gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));
					}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 129 "parser.y"
    { (yyval.symbol)=(yyvsp[(2) - (5)].symbol); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 136 "parser.y"
    {
	                    (yyval.tree_node) = treeCreateNode(1, IKS_AST_BLOCO, NULL);
	                    if((yyvsp[(2) - (3)].tree_node)!=NULL)
							          treeAppendNode((yyval.tree_node),(yyvsp[(2) - (3)].tree_node));
							        gv_declare(IKS_AST_BLOCO, (const void*)(yyval.tree_node), NULL);
							        if((yyvsp[(2) - (3)].tree_node)!=NULL)
							          gv_connect((yyval.tree_node), (yyvsp[(2) - (3)].tree_node));
	                  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 146 "parser.y"
    {				
						if((yyvsp[(3) - (3)].tree_node)!=NULL)
						{
							treeAppendNode((yyvsp[(1) - (3)].tree_node), (yyvsp[(3) - (3)].tree_node));
							gv_connect((yyvsp[(1) - (3)].tree_node), (yyvsp[(3) - (3)].tree_node));
						}
						(yyval.tree_node) = (yyvsp[(1) - (3)].tree_node);
					}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 156 "parser.y"
    { (yyval.tree_node) = NULL; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 158 "parser.y"
    {
					//printf("\natribution");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_ATRIBUICAO, NULL);
					comp_tree_t* son = treeCreateNode(1, IKS_AST_IDENTIFICADOR, (yyvsp[(1) - (3)].symbol));
					treeAppendNode((yyval.tree_node),son);	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_ATRIBUICAO, (const void*)(yyval.tree_node), NULL);
					gv_declare(IKS_AST_IDENTIFICADOR, (const void*)(yyvsp[(1) - (3)].symbol), ((comp_dict_item_t*)(yyvsp[(1) - (3)].symbol))->data.identifier_type);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].symbol));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));
				}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 170 "parser.y"
    {
					//printf("\natribution");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_ATRIBUICAO, NULL);
					comp_tree_t* son = treeCreateNode(1, IKS_AST_VETOR_INDEXADO, NULL);	
					comp_tree_t* grand_son = treeCreateNode(1, IKS_AST_IDENTIFICADOR, (yyvsp[(1) - (6)].symbol));
					treeAppendNode(son,grand_son);	
					treeAppendNode(son,(yyvsp[(3) - (6)].tree_node));
					treeAppendNode((yyval.tree_node),son);	
					treeAppendNode((yyval.tree_node),(yyvsp[(6) - (6)].tree_node));
					gv_declare(IKS_AST_ATRIBUICAO, (const void*)(yyval.tree_node), NULL);
					gv_declare(IKS_AST_VETOR_INDEXADO, (const void*)son, NULL);
					gv_declare(IKS_AST_IDENTIFICADOR, (const void*)(yyvsp[(1) - (6)].symbol), ((comp_dict_item_t*)(yyvsp[(1) - (6)].symbol))->data.identifier_type);
					gv_connect((yyval.tree_node), son);
					gv_connect((yyval.tree_node), (yyvsp[(6) - (6)].tree_node));
					gv_connect(son, (yyvsp[(1) - (6)].symbol));
					gv_connect(son, (yyvsp[(3) - (6)].tree_node));
				}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 188 "parser.y"
    {
			//printf("\ninput");
			(yyval.tree_node) = treeCreateNode(1, IKS_AST_INPUT, NULL);
			comp_tree_t* son = treeCreateNode(1, IKS_AST_IDENTIFICADOR, (yyvsp[(2) - (2)].symbol));
			treeAppendNode((yyval.tree_node),son);
			gv_declare(IKS_AST_INPUT, (const void*)(yyval.tree_node), NULL);
			gv_declare(IKS_AST_IDENTIFICADOR, (const void*)(yyvsp[(2) - (2)].symbol), ((comp_dict_item_t*)(yyvsp[(2) - (2)].symbol))->data.identifier_type);
			gv_connect((yyval.tree_node), (yyvsp[(2) - (2)].symbol));						
		}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 198 "parser.y"
    {
			//printf("\noutput");
			(yyval.tree_node) = treeCreateNode(1, IKS_AST_OUTPUT, NULL);
			treeAppendNode((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
			gv_declare(IKS_AST_OUTPUT, (const void*)(yyval.tree_node), NULL);
			gv_connect((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));						
		}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 206 "parser.y"
    {				
							treeAppendNode((yyvsp[(1) - (3)].tree_node), (yyvsp[(3) - (3)].tree_node));
							gv_connect((yyvsp[(1) - (3)].tree_node), (yyvsp[(3) - (3)].tree_node));
							(yyval.tree_node) = (yyvsp[(1) - (3)].tree_node);
						}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 213 "parser.y"
    {
			//printf("\nreturn");
			(yyval.tree_node) = treeCreateNode(1, IKS_AST_RETURN, NULL);
			treeAppendNode((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
			gv_declare(IKS_AST_RETURN, (const void*)(yyval.tree_node), NULL);
			gv_connect((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));						
		}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 222 "parser.y"
    {
					//printf("\nfunc_call: identifier(arg_list)");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_CHAMADA_DE_FUNCAO, NULL);
					comp_tree_t* son = treeCreateNode(1, IKS_AST_IDENTIFICADOR, (yyvsp[(1) - (4)].symbol));
					treeAppendNode((yyval.tree_node),son);
					if((yyvsp[(3) - (4)].tree_node) != NULL) 
					  treeAppendNode((yyval.tree_node),(yyvsp[(3) - (4)].tree_node));
					gv_declare(IKS_AST_CHAMADA_DE_FUNCAO, (const void*)(yyval.tree_node), NULL);
					gv_declare(IKS_AST_IDENTIFICADOR, (const void*)(yyvsp[(1) - (4)].symbol), ((comp_dict_item_t*)(yyvsp[(1) - (4)].symbol))->data.identifier_type);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (4)].symbol));
					if((yyvsp[(3) - (4)].tree_node) != NULL) 
						gv_connect((yyval.tree_node), (yyvsp[(3) - (4)].tree_node));
				}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 238 "parser.y"
    {
					treeAppendNode((yyvsp[(1) - (3)].tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_connect((yyvsp[(1) - (3)].tree_node), (yyvsp[(3) - (3)].tree_node));
					(yyval.tree_node)=(yyvsp[(1) - (3)].tree_node);		
				}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 244 "parser.y"
    { (yyval.tree_node) = NULL; }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 248 "parser.y"
    {
					//printf("\nif then");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_IF_ELSE, NULL);							
					gv_declare(IKS_AST_IF_ELSE, (const void*)(yyval.tree_node), NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (6)].tree_node));
					treeAppendNode((yyval.tree_node),(yyvsp[(6) - (6)].tree_node));
					gv_connect((yyval.tree_node),(yyvsp[(3) - (6)].tree_node));
					gv_connect((yyval.tree_node),(yyvsp[(6) - (6)].tree_node));	
				}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 258 "parser.y"
    {
					//printf("\nif then else");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_IF_ELSE, NULL);							
					gv_declare(IKS_AST_IF_ELSE, (const void*)(yyval.tree_node), NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (8)].tree_node));
					treeAppendNode((yyval.tree_node),(yyvsp[(6) - (8)].tree_node));
					treeAppendNode((yyval.tree_node),(yyvsp[(8) - (8)].tree_node));
					gv_connect((yyval.tree_node),(yyvsp[(3) - (8)].tree_node));
					gv_connect((yyval.tree_node),(yyvsp[(6) - (8)].tree_node));
					gv_connect((yyval.tree_node),(yyvsp[(8) - (8)].tree_node));	
				}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 270 "parser.y"
    {
					//printf("\nwhile do");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_WHILE_DO, NULL);							
					gv_declare(IKS_AST_WHILE_DO, (const void*)(yyval.tree_node), NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (6)].tree_node));
					treeAppendNode((yyval.tree_node),(yyvsp[(6) - (6)].tree_node));
					gv_connect((yyval.tree_node),(yyvsp[(3) - (6)].tree_node));
					gv_connect((yyval.tree_node),(yyvsp[(6) - (6)].tree_node));	
				}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 280 "parser.y"
    {
					//printf("\nwhile do");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_DO_WHILE, NULL);							
					gv_declare(IKS_AST_DO_WHILE, (const void*)(yyval.tree_node), NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(2) - (6)].tree_node));
					treeAppendNode((yyval.tree_node),(yyvsp[(5) - (6)].tree_node));
					gv_connect((yyval.tree_node),(yyvsp[(2) - (6)].tree_node));
					gv_connect((yyval.tree_node),(yyvsp[(5) - (6)].tree_node));	
				}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 291 "parser.y"
    {
					//printf("\nidentifier");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_IDENTIFICADOR, (yyvsp[(1) - (1)].symbol));							
					gv_declare(IKS_AST_IDENTIFICADOR, (const void*)(yyval.tree_node), ((comp_dict_item_t*)(yyvsp[(1) - (1)].symbol))->data.identifier_type);
				}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 297 "parser.y"
    {
					printf("\nvector_identifier");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_VETOR_INDEXADO, NULL);
					comp_tree_t* son = treeCreateNode(1, IKS_AST_IDENTIFICADOR, (yyvsp[(1) - (4)].symbol));
					treeAppendNode((yyval.tree_node),son);	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (4)].tree_node));
					gv_declare(IKS_AST_VETOR_INDEXADO, (const void*)(yyval.tree_node), NULL);
					gv_declare(IKS_AST_IDENTIFICADOR, (const void*)(yyvsp[(1) - (4)].symbol), ((comp_dict_item_t*)(yyvsp[(1) - (4)].symbol))->data.identifier_type);
					printf("identificador: %s", ((comp_dict_item_t*)(yyvsp[(1) - (4)].symbol))->data.identifier_type);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (4)].symbol));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (4)].tree_node));
				}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 310 "parser.y"
    {
					//printf("\nTK_LIT_INT");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_LITERAL, (yyvsp[(1) - (1)].symbol));	

					char int_literal[15];
					sprintf(int_literal, "%d", ((comp_dict_item_t*)(yyvsp[(1) - (1)].symbol))->data.int_type);						
					gv_declare(IKS_AST_LITERAL, (const void*)(yyval.tree_node), int_literal);
				}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 319 "parser.y"
    {
					//printf("\nTK_LIT_FLOAT");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_LITERAL, (yyvsp[(1) - (1)].symbol));

					char float_literal[15];
					sprintf(float_literal, "%.2f", ((comp_dict_item_t*)(yyvsp[(1) - (1)].symbol))->data.float_type);;							
					gv_declare(IKS_AST_LITERAL, (const void*)(yyval.tree_node), float_literal);
				}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 328 "parser.y"
    {
					//printf("\nTK_LIT_FALSE", $1);
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_LITERAL, (yyvsp[(1) - (1)].symbol));

					char false_literal[15];
					sprintf(false_literal, "%d", ((comp_dict_item_t*)(yyvsp[(1) - (1)].symbol))->data.bool_type);							
					gv_declare(IKS_AST_LITERAL, (const void*)(yyval.tree_node), false_literal);				
				}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 337 "parser.y"
    {
					//printf("\nTK_LIT_TRUE");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_LITERAL, (yyvsp[(1) - (1)].symbol));						

					char true_literal[15];
					sprintf(true_literal, "%d", ((comp_dict_item_t*)(yyvsp[(1) - (1)].symbol))->data.bool_type);							
					gv_declare(IKS_AST_LITERAL, (const void*)(yyval.tree_node), true_literal);
				}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 346 "parser.y"
    {
					//printf("\nTK_LIT_CHAR");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_LITERAL, (yyvsp[(1) - (1)].symbol));							
					
					char char_literal[15];
					sprintf(char_literal, "%c", ((comp_dict_item_t*)(yyvsp[(1) - (1)].symbol))->data.char_type);							
					gv_declare(IKS_AST_LITERAL, (const void*)(yyval.tree_node), char_literal);
				}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 355 "parser.y"
    {
					//printf("\nTK_LIT_STRING");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_LITERAL, (yyvsp[(1) - (1)].symbol));							
					gv_declare(IKS_AST_LITERAL, (const void*)(yyval.tree_node), ((comp_dict_item_t*)(yyvsp[(1) - (1)].symbol))->data.string_type);
				}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 361 "parser.y"
    {
					//printf("\nexpression + expression");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_ARIM_SOMA, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_ARIM_SOMA, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].tree_node));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));	
				}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 371 "parser.y"
    {
					//printf("\nexpression - expression");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_ARIM_SUBTRACAO, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_ARIM_SUBTRACAO, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].tree_node));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));	
				}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 381 "parser.y"
    {
					//printf("\n!expression");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_LOGICO_COMP_NEGACAO, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
					gv_declare(IKS_AST_LOGICO_COMP_NEGACAO, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(2) - (2)].tree_node));	
				}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 388 "parser.y"
    { (yyval.tree_node)=(yyvsp[(2) - (2)].tree_node); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 390 "parser.y"
    {
			  	//printf("\n-expression");
					(yyval.tree_node) = treeCreateNode(1, IKS_AST_ARIM_INVERSAO, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
					gv_declare(IKS_AST_ARIM_INVERSAO, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(2) - (2)].tree_node));	
				}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 398 "parser.y"
    {
					//printf("\nexpression * expression");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_ARIM_MULTIPLICACAO, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_ARIM_MULTIPLICACAO, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].tree_node));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));	
				}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 408 "parser.y"
    {
					//printf("\nexpression / expression");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_ARIM_DIVISAO, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_ARIM_DIVISAO, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].tree_node));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));	
				}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 418 "parser.y"
    {
					//printf("\nexpression < expression");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_LOGICO_COMP_L, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_LOGICO_COMP_L, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].tree_node));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));	
				}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 428 "parser.y"
    {
					//printf("\nexpression > expression");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_LOGICO_COMP_G, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_LOGICO_COMP_G, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].tree_node));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));	
				}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 437 "parser.y"
    { (yyval.tree_node)=(yyvsp[(2) - (3)].tree_node); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 439 "parser.y"
    {
					//printf("\nexpression <= expression");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_LOGICO_COMP_LE, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_LOGICO_COMP_LE, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].tree_node));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));	
				}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 449 "parser.y"
    {
					//printf("\nexpression >= expression");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_LOGICO_COMP_GE, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_LOGICO_COMP_GE, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].tree_node));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));	
				}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 459 "parser.y"
    {
					//printf("\nexpression == expression");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_LOGICO_COMP_IGUAL, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_LOGICO_COMP_IGUAL, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].tree_node));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));	
				}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 469 "parser.y"
    {
					//printf("\nexpression != expression");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_LOGICO_COMP_DIF, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_LOGICO_COMP_DIF, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].tree_node));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));	
				}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 479 "parser.y"
    {
					//printf("\nexpression && expression");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_LOGICO_E, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_LOGICO_E, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].tree_node));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));	
				}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 489 "parser.y"
    {
					//printf("\nexpression || expression");
					(yyval.tree_node) = treeCreateNode(2, IKS_AST_LOGICO_OU, NULL);
					treeAppendNode((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));	
					treeAppendNode((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
					gv_declare(IKS_AST_LOGICO_OU, (const void*)(yyval.tree_node), NULL);
					gv_connect((yyval.tree_node), (yyvsp[(1) - (3)].tree_node));
					gv_connect((yyval.tree_node), (yyvsp[(3) - (3)].tree_node));	
				}
    break;



/* Line 1806 of yacc.c  */
#line 2188 "/home/ingrid/Desktop/CompilersProject/build/parser.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 501 "parser.y"


