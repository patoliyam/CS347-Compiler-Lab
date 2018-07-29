/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bisonfinal.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "utility.cpp"
void yyerror(string s)
{

    //fprintf(stderr,"Unknown errors detected.\n");
    extern int yylineno;
}
using namespace std;
int yylex(void);
extern int  yylex();
extern int yylineno;
extern int lineno;
int flag=0;

#line 87 "bisonfinal.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bisonfinal.tab.h".  */
#ifndef YY_YY_BISONFINAL_TAB_H_INCLUDED
# define YY_YY_BISONFINAL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    FOR = 261,
    SWITCH = 262,
    CASE = 263,
    DEFAULT = 264,
    LP = 265,
    RP = 266,
    LCP = 267,
    RCP = 268,
    LSP = 269,
    RSP = 270,
    SEMI = 271,
    COLON = 272,
    LT = 273,
    GT = 274,
    EQ = 275,
    PLUS = 276,
    MINUS = 277,
    MULTIPLY = 278,
    DIVIDE = 279,
    BITOR = 280,
    BITAND = 281,
    NOT = 282,
    ID = 283,
    NUM = 284,
    DOT = 285,
    COMMA = 286,
    PROCESSOR = 287,
    LINK = 288,
    MEMORY = 289,
    JOB = 290,
    CLUSTER = 291,
    ISA = 292,
    CLOCK_SPEED = 293,
    L1_MEMORY = 294,
    L2_MEMORY = 295,
    NAME = 296,
    START_POINT = 297,
    END_POINT = 298,
    BANDWIDTH = 299,
    CHANNEL_CAPACITY = 300,
    MEMORY_TYPE = 301,
    MEM_SIZE = 302,
    JOB_ID = 303,
    FLOPS_REQUIRED = 304,
    DEADLINE = 305,
    MEM_REQUIRED = 306,
    PROCESSORS = 307,
    TOPOLOGY = 308,
    LINK_BANDWIDTH = 309,
    LINK_CAPACITY = 310,
    IS_RUNNING = 311,
    SUBMIT_JOBS = 312,
    OR = 313,
    AND = 314,
    PLUSEQ = 315,
    MINUSEQ = 316,
    MULTIPLYEQ = 317,
    DIVIDEEQ = 318,
    MINUSMINUS = 319,
    PLUSPLUS = 320,
    GET_CLOCK_SPEED = 321,
    RUN = 322,
    DISCARD_JOB = 323,
    GET_AVAILABLE_MEMORY = 324,
    GET_MEMORY = 325,
    ELSEIF = 326,
    AFFINITY = 327,
    EQEQ = 328,
    DQUOTE = 329,
    SQUOTE = 330,
    ARCHITECTURE_TYPE = 331,
    WAIT = 332,
    SCHEDULER = 333,
    JOB_ARRAY = 334,
    PROCESSOR_ARRAY = 335,
    SET_JOB_AFFINITY = 336,
    MAX_JOBS = 337,
    GET_LOAD = 338,
    SET_ALGO = 339,
    INTEGER_LITERAL = 340
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "bisonfinal.y" /* yacc.c:355  */

	node *Node;

#line 217 "bisonfinal.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISONFINAL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 234 "bisonfinal.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   835

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  344

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    39,    39,    56,    61,    65,    69,    73,    77,    81,
      86,    90,    95,    99,   103,   107,   112,   116,   120,   124,
     128,   133,   138,   142,   147,   151,   156,   160,   164,   168,
     172,   176,   180,   185,   190,   194,   198,   203,   207,   211,
     215,   219,   223,   227,   234,   238,   244,   248,   254,   258,
     262,   267,   271,   275,   281,   285,   290,   294,   298,   302,
     306,   312,   316,   320,   324,   328,   332,   338,   343,   348,
     353,   358,   363,   368,   374,   379,   384,   390,   395,   400,
     405,   410,   415,   420,   425,   430,   434,   438,   442,   446,
     450,   454,   459,   464,   468,   473,   478,   482,   487,   493,
     497,   501,   505,   509,   513,   518,   523,   527,   531,   536,
     541,   546,   551,   555,   559,   563,   567,   572,   577,   581,
     585,   589,   593,   597,   602,   607,   611,   615,   619,   624,
     629,   633,   637,   641,   645,   649,   653,   658,   663,   667,
     672,   677,   681,   685,   689,   696,   700,   708,   712,   720,
     724
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "FOR", "SWITCH",
  "CASE", "DEFAULT", "LP", "RP", "LCP", "RCP", "LSP", "RSP", "SEMI",
  "COLON", "LT", "GT", "EQ", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "BITOR", "BITAND", "NOT", "ID", "NUM", "DOT", "COMMA", "PROCESSOR",
  "LINK", "MEMORY", "JOB", "CLUSTER", "ISA", "CLOCK_SPEED", "L1_MEMORY",
  "L2_MEMORY", "NAME", "START_POINT", "END_POINT", "BANDWIDTH",
  "CHANNEL_CAPACITY", "MEMORY_TYPE", "MEM_SIZE", "JOB_ID",
  "FLOPS_REQUIRED", "DEADLINE", "MEM_REQUIRED", "PROCESSORS", "TOPOLOGY",
  "LINK_BANDWIDTH", "LINK_CAPACITY", "IS_RUNNING", "SUBMIT_JOBS", "OR",
  "AND", "PLUSEQ", "MINUSEQ", "MULTIPLYEQ", "DIVIDEEQ", "MINUSMINUS",
  "PLUSPLUS", "GET_CLOCK_SPEED", "RUN", "DISCARD_JOB",
  "GET_AVAILABLE_MEMORY", "GET_MEMORY", "ELSEIF", "AFFINITY", "EQEQ",
  "DQUOTE", "SQUOTE", "ARCHITECTURE_TYPE", "WAIT", "SCHEDULER",
  "JOB_ARRAY", "PROCESSOR_ARRAY", "SET_JOB_AFFINITY", "MAX_JOBS",
  "GET_LOAD", "SET_ALGO", "INTEGER_LITERAL", "$accept", "grammar_start",
  "stmtlist", "stmt", "elsestmt", "exprc", "A", "switchstmt", "exprfor",
  "expression", "init", "mathexpr", "assignexpr", "arithexpr", "expr1",
  "expr2", "expr3", "expr4", "factor", "constructor",
  "proc_parameter_list", "C", "link_parameter_list", "D",
  "memory_parameter_list", "E", "job_parameter_list", "F",
  "cluster_parameter_list", "G", "scheduler_parameter_list", "Z",
  "proc_parameter", "argument", "valuearray", "H", "link_parameter",
  "memory_parameter", "job_parameter", "cluster_parameter",
  "scheduler_parameter", "function", "func_arg_list", "I", "value", "semi",
  "rp", "rsp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
};
# endif

#define YYPACT_NINF -191

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-191)))

#define YYTABLE_NINF -35

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     419,     8,    46,    54,    81,   308,   243,   296,  -191,    89,
     100,   101,   107,   110,   111,   119,   120,   121,   129,   131,
     132,  -191,   434,    10,  -191,  -191,  -191,  -191,   117,     2,
       7,  -191,  -191,     9,   602,   602,   602,   308,   114,    74,
    -191,   335,   245,   335,   335,   335,   335,  -191,  -191,   661,
     447,   730,   677,    73,   746,   746,   746,    44,   746,   746,
    -191,  -191,  -191,  -191,  -191,   308,   308,   308,   308,   308,
     308,   245,    31,     1,    31,    74,    10,    74,  -191,  -191,
    -191,   484,  -191,    58,   135,   136,   139,   140,   142,   143,
     144,  -191,  -191,  -191,  -191,  -191,   757,   146,   147,   150,
     152,   153,   134,   154,   158,  -191,     9,    74,   155,  -191,
    -191,   163,   164,   169,   171,   172,    74,   173,  -191,   175,
     180,   182,    74,   174,  -191,   183,   188,   190,   191,   192,
      74,  -191,   185,   194,   197,   200,   201,   202,    74,  -191,
     187,   193,    74,    74,    74,    72,   203,   207,    74,  -191,
     210,    74,    74,  -191,     7,     7,  -191,  -191,  -191,  -191,
     602,   602,   162,   523,   582,   602,  -191,   216,   231,   602,
      85,   335,   227,  -191,   746,   746,   746,   746,   746,   746,
     746,    48,   219,   757,   757,   757,   757,   757,   189,   179,
     757,  -191,   661,  -191,   757,   757,   757,   757,   757,  -191,
     447,  -191,   757,   757,   757,  -191,   730,  -191,   757,   757,
     757,   757,   746,  -191,   677,  -191,   757,   746,   757,   757,
     757,  -191,    73,  -191,   746,  -191,  -191,  -191,  -191,   757,
     746,   746,  -191,    44,  -191,  -191,  -191,     1,     1,   503,
     602,  -191,   602,  -191,  -191,   503,   503,    39,   247,   255,
    -191,   123,    74,    74,    74,    74,    74,    74,    74,  -191,
    -191,  -191,   757,  -191,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,   246,  -191,  -191,   256,   269,   602,   308,   503,
     240,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,    13,
    -191,  -191,  -191,    74,   270,   272,   275,  -191,   274,  -191,
     503,   602,   503,   277,    31,   278,  -191,   276,    85,   503,
    -191,   279,    13,  -191
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      34,     0,     0,     0,     0,     0,     0,    59,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     4,     0,    31,    32,    35,    36,    45,    47,
      50,    53,    55,     0,    34,    34,    34,     0,    59,     0,
      54,     0,     0,     0,     0,     0,     0,    42,    43,    92,
     105,   110,   117,   124,   138,   138,   138,   129,   138,   138,
       1,     3,   146,   145,     9,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,   148,   147,
      60,    59,    37,    34,     0,     0,     0,     0,     0,     0,
       0,    57,    38,    39,    40,    41,    96,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   144,     0,    69,    91,
      93,     0,     0,     0,     0,     0,     0,    72,   104,     0,
       0,     0,     0,    75,   109,     0,     0,     0,     0,     0,
       0,   116,    78,     0,     0,     0,     0,     0,     0,   123,
      81,   140,     0,     0,     0,     0,     0,     0,     0,   128,
      84,     0,     0,    44,    48,    49,    46,    51,    52,    58,
      34,    34,     0,    34,    34,    34,    15,     0,     0,    34,
      24,     0,     0,    33,   138,   138,   138,   138,   138,   138,
     138,     0,    98,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    92,    67,     0,     0,     0,     0,     0,    62,
     105,    70,     0,     0,     0,    63,   110,    73,     0,     0,
       0,     0,     0,    64,   117,    76,     0,     0,     0,     0,
       0,    65,   124,    79,   138,   137,    26,    29,    30,     0,
       0,     0,    66,   129,    82,    27,    28,    21,    21,    34,
      34,    16,    34,    17,    18,    34,    34,     0,     0,     0,
       8,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     149,    94,    96,    95,    86,    87,    88,    89,    90,   142,
     141,    85,    68,   103,    99,   100,   101,   102,    71,   108,
     106,   107,    74,   111,   112,   113,   114,   115,    77,   122,
     118,   119,   120,   121,    80,   139,   125,   126,   127,    83,
      13,    14,     0,    20,    19,     0,     0,    34,     0,    34,
      34,   130,   131,   132,   133,   134,   136,   135,    97,    12,
       6,     7,    25,     0,     0,     0,     0,     5,     0,    23,
      34,    34,    34,     0,     0,     0,    11,     0,    24,    34,
      22,     0,    12,    10
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -191,  -191,   -20,  -191,   -55,   -34,  -190,   -45,  -191,   -27,
     -80,   -31,  -191,    16,   228,  -191,    29,    34,   289,     0,
     106,  -191,    99,  -191,    94,  -191,    91,  -191,    84,  -191,
      70,  -191,  -191,   -24,    51,  -191,  -191,  -191,  -191,  -191,
    -191,   249,    57,  -191,   198,   -72,   122,  -191
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,   327,    72,   166,   250,    75,    23,
      24,    25,    26,   105,    28,    29,    30,    31,    32,   106,
     107,   193,   116,   201,   122,   207,   130,   215,   138,   223,
     148,   234,   108,   141,   181,   263,   117,   123,   132,   140,
     150,    91,   142,   225,   110,    64,    80,   261
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    74,    61,   173,   169,    33,    33,    73,    73,    76,
      82,    62,    92,    93,    94,    95,    27,   325,    34,   163,
     164,    39,    33,    66,    67,   109,    63,    68,   131,   139,
      69,    70,    78,   149,    33,    33,    33,    33,    27,    71,
      62,    83,    79,    33,    33,    33,    33,   300,   301,   259,
      27,    27,    27,    77,     5,    63,    35,    27,    96,    27,
      27,    27,    27,   260,    36,    33,    33,    33,    33,    33,
      33,     6,    38,     8,   165,    78,     9,    10,    11,    12,
     145,   153,    53,     5,   326,    79,   172,    96,    71,   160,
     161,    37,   229,   248,   249,   154,   155,   160,   161,    49,
       6,    38,     8,   157,   158,     9,    10,    11,    12,    13,
      50,    51,   143,   144,   133,   151,   152,    52,   102,   103,
      53,    54,    17,   146,   147,   134,   135,   136,   137,    55,
      56,    57,    60,   237,   238,   247,   241,   243,   244,    58,
      82,    59,    73,    65,    42,   174,   175,   102,   103,   176,
     177,    17,   178,   179,   180,     9,    10,    11,    12,    13,
      33,    33,   188,    33,    33,    33,   183,   184,   109,    33,
     185,    33,   186,   187,   239,   307,    27,    27,   190,    27,
      27,    27,   189,   194,   195,    27,   192,    27,   287,   196,
     131,   197,   198,   290,   162,   202,   167,   168,   139,   170,
     203,    17,   204,   208,   200,   206,   297,   298,   209,   149,
     210,   211,   212,   303,   216,   304,   214,   217,   222,   302,
     218,   219,   220,   230,   224,   305,   306,   231,   245,   191,
     173,   252,   253,   254,   255,   256,   257,   258,   199,    33,
      33,   233,    33,   246,   205,    33,    33,   251,   118,   124,
     262,   310,   213,     5,   270,    27,    27,   308,    27,   319,
     221,    27,    27,   269,   226,   227,   228,   309,   172,   320,
     232,    38,     8,   235,   236,     9,    10,    11,    12,    13,
     322,   295,   321,   329,   330,   331,   332,   343,   339,   324,
     336,   338,   342,   340,   182,    40,   156,   334,   272,   278,
     282,    84,    85,   299,    73,   288,   294,    33,    33,    33,
     333,    86,   335,   318,    87,    88,    41,     0,     5,   341,
     159,    17,     0,    27,   323,    27,    42,    89,    90,     0,
      33,    33,    33,     0,     0,     6,    38,     8,     0,    33,
       9,    10,    11,    12,    13,     5,    27,    27,    27,     0,
       0,     0,     0,     0,     0,    27,    43,    44,    45,    46,
      47,    48,     6,    81,     8,     0,     0,     9,    10,    11,
      12,    13,     0,     0,   311,   312,   313,   314,   315,   316,
     317,   264,   265,   266,   267,   268,    17,     0,   271,     0,
       0,     0,   273,   274,   275,   276,   277,     0,   118,     0,
     279,   280,   281,     0,   124,     0,   283,   284,   285,   286,
       0,     0,     0,    17,   289,     0,   291,   292,   293,    -4,
       0,     0,     1,     0,     2,     3,     4,   296,     0,     5,
       0,     0,     0,     0,     0,   -34,     0,     1,     0,     2,
       3,     4,     0,     0,     5,   328,     6,     7,     8,     0,
     -34,     9,    10,    11,    12,    13,   337,     5,     0,     0,
     182,     6,     7,     8,     0,     0,     9,    10,    11,    12,
      13,     0,     0,     0,     6,    38,     8,     0,     0,     9,
      10,    11,    12,    13,     0,     0,    14,    15,   111,   112,
     113,   114,   115,     0,     0,     0,    16,    17,     0,     0,
      18,    14,    15,    19,   171,     0,     1,     0,     2,     3,
       4,    16,    17,     5,    42,    18,    -4,     0,    19,     0,
       0,   102,   103,     0,     0,    17,     0,     0,     0,     0,
       6,     7,     8,     5,     0,     9,    10,    11,    12,    13,
       0,     0,     0,   240,    43,    44,    45,    46,    47,    48,
       6,     7,     8,     0,     0,     9,    10,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,     0,     0,    18,     0,     0,    19,     0,     0,
      14,    15,     5,     0,     0,     0,     0,     0,     0,     0,
      16,    17,   242,     0,    18,     0,     0,    19,     0,     6,
       7,     8,     5,     0,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     8,     0,     0,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,     0,    18,     0,     0,    19,     0,     0,    14,
      15,     5,     0,     0,     0,    96,     0,     0,     0,    16,
      17,     0,     0,    18,     0,     0,    19,     5,     6,    38,
       8,    96,     0,     9,    10,    11,    12,    13,    97,    98,
      99,   100,   101,     0,     6,    38,     8,     0,     0,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,   126,   127,   128,     0,
       0,     0,     0,     0,     0,   102,   103,   104,     0,    17,
       5,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   102,   103,     0,     0,    17,     5,     6,    38,     8,
      96,     0,     9,    10,    11,    12,    13,     5,     0,     0,
       0,   119,     0,     6,    38,     8,   120,   121,     9,    10,
      11,    12,    13,     0,     6,    38,     8,     0,     0,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,   103,     0,     0,    17,     0,     0,     0,     0,     0,
       0,   102,   103,     0,     0,    17
};

static const yytype_int16 yycheck[] =
{
       0,    35,    22,    83,    76,     5,     6,    34,    35,    36,
      41,     1,    43,    44,    45,    46,     0,     4,    10,    18,
      19,     5,    22,    21,    22,    49,    16,    25,    52,    53,
      23,    24,     1,    57,    34,    35,    36,    37,    22,    30,
       1,    41,    11,    43,    44,    45,    46,   237,   238,     1,
      34,    35,    36,    37,    10,    16,    10,    41,    14,    43,
      44,    45,    46,    15,    10,    65,    66,    67,    68,    69,
      70,    27,    28,    29,    73,     1,    32,    33,    34,    35,
      36,    65,    10,    10,    71,    11,    28,    14,    30,    58,
      59,    10,    20,     8,     9,    66,    67,    58,    59,    10,
      27,    28,    29,    69,    70,    32,    33,    34,    35,    36,
      10,    10,    55,    56,    41,    58,    59,    10,    74,    75,
      10,    10,    78,    79,    80,    52,    53,    54,    55,    10,
      10,    10,     0,   160,   161,   169,   163,   164,   165,    10,
     171,    10,   169,    26,    30,    10,    10,    74,    75,    10,
      10,    78,    10,    10,    10,    32,    33,    34,    35,    36,
     160,   161,    28,   163,   164,   165,    20,    20,   192,   169,
      20,   171,    20,    20,    12,   247,   160,   161,    20,   163,
     164,   165,    28,    20,    20,   169,    31,   171,   212,    20,
     214,    20,    20,   217,    72,    20,    74,    75,   222,    77,
      20,    78,    20,    20,    31,    31,   230,   231,    20,   233,
      20,    20,    20,   240,    20,   242,    31,    20,    31,   239,
      20,    20,    20,    20,    31,   245,   246,    20,    12,   107,
     310,   174,   175,   176,   177,   178,   179,   180,   116,   239,
     240,    31,   242,    12,   122,   245,   246,    20,    50,    51,
      31,   251,   130,    10,    75,   239,   240,    10,   242,    13,
     138,   245,   246,    74,   142,   143,   144,    12,    28,    13,
     148,    28,    29,   151,   152,    32,    33,    34,    35,    36,
     307,   224,    13,    13,    12,    10,    12,   342,    12,   309,
      13,    13,    13,   338,    96,     6,    68,   331,   192,   200,
     206,    56,    57,   233,   331,   214,   222,   307,   308,   309,
     330,    66,   332,   262,    69,    70,    20,    -1,    10,   339,
      71,    78,    -1,   307,   308,   309,    30,    82,    83,    -1,
     330,   331,   332,    -1,    -1,    27,    28,    29,    -1,   339,
      32,    33,    34,    35,    36,    10,   330,   331,   332,    -1,
      -1,    -1,    -1,    -1,    -1,   339,    60,    61,    62,    63,
      64,    65,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    -1,   252,   253,   254,   255,   256,   257,
     258,   183,   184,   185,   186,   187,    78,    -1,   190,    -1,
      -1,    -1,   194,   195,   196,   197,   198,    -1,   200,    -1,
     202,   203,   204,    -1,   206,    -1,   208,   209,   210,   211,
      -1,    -1,    -1,    78,   216,    -1,   218,   219,   220,     0,
      -1,    -1,     3,    -1,     5,     6,     7,   229,    -1,    10,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,    -1,     5,
       6,     7,    -1,    -1,    10,   323,    27,    28,    29,    -1,
      16,    32,    33,    34,    35,    36,   334,    10,    -1,    -1,
     262,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    67,    68,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    77,    78,    -1,    -1,
      81,    67,    68,    84,    20,    -1,     3,    -1,     5,     6,
       7,    77,    78,    10,    30,    81,    13,    -1,    84,    -1,
      -1,    74,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      27,    28,    29,    10,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    20,    60,    61,    62,    63,    64,    65,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,
      67,    68,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    20,    -1,    81,    -1,    -1,    84,    -1,    27,
      28,    29,    10,    -1,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    67,
      68,    10,    -1,    -1,    -1,    14,    -1,    -1,    -1,    77,
      78,    -1,    -1,    81,    -1,    -1,    84,    10,    27,    28,
      29,    14,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,    78,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    74,    75,    -1,    -1,    78,    10,    27,    28,    29,
      14,    -1,    32,    33,    34,    35,    36,    10,    -1,    -1,
      -1,    41,    -1,    27,    28,    29,    46,    47,    32,    33,
      34,    35,    36,    -1,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    78
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,    10,    27,    28,    29,    32,
      33,    34,    35,    36,    67,    68,    77,    78,    81,    84,
      87,    88,    89,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    10,    10,    10,    10,    28,    99,
     104,    20,    30,    60,    61,    62,    63,    64,    65,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
       0,    88,     1,    16,   131,    26,    21,    22,    25,    23,
      24,    30,    91,    95,    91,    94,    95,    99,     1,    11,
     132,    28,    97,   105,    56,    57,    66,    69,    70,    82,
      83,   127,    97,    97,    97,    97,    14,    37,    38,    39,
      40,    41,    74,    75,    76,    99,   105,   106,   118,   119,
     130,    41,    42,    43,    44,    45,   108,   122,   130,    41,
      46,    47,   110,   123,   130,    48,    49,    50,    51,    72,
     112,   119,   124,    41,    52,    53,    54,    55,   114,   119,
     125,   119,   128,   128,   128,    36,    79,    80,   116,   119,
     126,   128,   128,    99,   102,   102,   100,   103,   103,   127,
      58,    59,   132,    18,    19,    73,    92,   132,   132,   131,
     132,    20,    28,    96,    10,    10,    10,    10,    10,    10,
      10,   120,   130,    20,    20,    20,    20,    20,    28,    28,
      20,   132,    31,   107,    20,    20,    20,    20,    20,   132,
      31,   109,    20,    20,    20,   132,    31,   111,    20,    20,
      20,    20,    20,   132,    31,   113,    20,    20,    20,    20,
      20,   132,    31,   115,    31,   129,   132,   132,   132,    20,
      20,    20,   132,    31,   117,   132,   132,    95,    95,    12,
      20,    95,    20,    95,    95,    12,    12,    91,     8,     9,
      93,    20,   128,   128,   128,   128,   128,   128,   128,     1,
      15,   133,    31,   121,   130,   130,   130,   130,   130,    74,
      75,   130,   106,   130,   130,   130,   130,   130,   108,   130,
     130,   130,   110,   130,   130,   130,   130,   119,   112,   130,
     119,   130,   130,   130,   114,   128,   130,   119,   119,   116,
      92,    92,    88,    95,    95,    88,    88,   131,    10,    12,
     105,   132,   132,   132,   132,   132,   132,   132,   120,    13,
      13,    13,    95,    99,    88,     4,    71,    90,   132,    13,
      12,    10,    12,    88,    91,    88,    13,   132,    13,    12,
      93,    88,    13,    90
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    89,    89,    89,    89,    89,
      90,    90,    90,    91,    91,    91,    92,    92,    92,    92,
      92,    92,    93,    93,    93,    94,    95,    95,    95,    95,
      95,    95,    95,    96,    96,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    99,    99,   100,   100,   101,   101,
     101,   102,   102,   102,   103,   103,   104,   104,   104,   104,
     104,   105,   105,   105,   105,   105,   105,   106,   107,   107,
     108,   109,   109,   110,   111,   111,   112,   113,   113,   114,
     115,   115,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   123,   123,   123,   123,
     123,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   126,   126,   126,   126,   126,
     127,   127,   127,   127,   127,   127,   127,   128,   128,   129,
     129,   130,   130,   130,   130,   131,   131,   132,   132,   133,
     133
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     8,     7,     7,     5,     2,
       8,     4,     0,     4,     4,     2,     2,     2,     2,     3,
       3,     0,     8,     4,     0,     5,     4,     4,     4,     4,
       4,     1,     1,     4,     0,     1,     1,     3,     3,     3,
       3,     3,     2,     2,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     1,     2,     1,     1,     3,     3,     1,
       3,     4,     4,     4,     4,     4,     4,     2,     2,     0,
       2,     2,     0,     2,     2,     0,     2,     2,     0,     2,
       2,     0,     2,     2,     0,     3,     3,     3,     3,     3,
       3,     1,     0,     1,     3,     2,     0,     2,     0,     3,
       3,     3,     3,     3,     1,     0,     3,     3,     3,     1,
       0,     3,     3,     3,     3,     3,     1,     0,     3,     3,
       3,     3,     3,     1,     0,     3,     3,     3,     1,     0,
       4,     4,     4,     4,     4,     4,     4,     2,     0,     2,
       0,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 40 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("grammar_start",(yyvsp[0].Node));
	if(flag==0){
		printf("Compilation successful.\n");
		ofstream output;
		output.open("parsetree.txt");
		print_nodes((yyval.Node),output);	
		//print_nodes_node_num($$,output);
		output.close();	
	}
	else{
		printf("Error encountered\n");
	}
}
#line 1673 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 57 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmtlist",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 1681 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 61 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmtlist");	
}
#line 1689 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 66 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt",(yyvsp[-7].Node),(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));			
}
#line 1697 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 70 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt",(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1705 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 74 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt",(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1713 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 78 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt",(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1721 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt",(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1729 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 87 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("elsestmt",(yyvsp[-7].Node),(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node));	
}
#line 1737 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 91 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("elsestmt",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1745 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 95 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("elsestmt");	
}
#line 1753 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 100 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("exprc",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1761 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 104 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("exprc",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1769 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 108 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("exprc",(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1777 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 113 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("A",(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1785 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 117 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("A",(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1793 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 121 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("A",(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1801 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 125 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("A",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1809 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 129 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("A",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1817 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 133 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("A");	
}
#line 1825 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 139 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("switchstmt",(yyvsp[-7].Node),(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1833 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 143 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("switchstmt",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1841 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 147 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("switchstmt");	
}
#line 1849 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 152 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("exprfor",(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1857 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1865 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 161 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1873 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 165 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1881 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 169 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1889 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 173 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1897 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 177 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[0].Node));	
}
#line 1905 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 181 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[0].Node));	
}
#line 1913 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 186 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("init",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1921 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 190 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("init");	
}
#line 1929 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 195 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("mathexpr",(yyvsp[0].Node));	
}
#line 1937 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 199 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("mathexpr",(yyvsp[0].Node));	
}
#line 1945 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 204 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1953 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 208 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1961 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 212 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1969 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 216 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1977 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 220 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1985 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 224 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 1993 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 228 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 2001 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 235 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("arithexpr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 2009 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 239 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("arithexpr",(yyvsp[0].Node));	
}
#line 2017 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 245 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr1",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2025 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 249 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr1",(yyvsp[0].Node));
}
#line 2033 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 255 "bisonfinal.y" /* yacc.c:1646  */
    {	
	(yyval.Node) = add_new_node("expr2",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2041 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 259 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr2",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2049 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 263 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr2",(yyvsp[0].Node));
}
#line 2057 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 268 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr3",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2065 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 272 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr3",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2073 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 276 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr3",(yyvsp[0].Node));
}
#line 2081 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 282 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr4",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2089 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 286 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr4",(yyvsp[0].Node));
}
#line 2097 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 291 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("factor",(yyvsp[0].Node));
}
#line 2105 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 295 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("factor",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 2113 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 299 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("factor",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));	
}
#line 2121 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 303 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("factor",(yyvsp[0].Node));
}
#line 2129 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 307 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("factor",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2137 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 313 "bisonfinal.y" /* yacc.c:1646  */
    {
 	(yyval.Node) = add_new_node("constructor",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2145 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 317 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("constructor",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2153 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 321 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("constructor",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2161 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 325 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("constructor",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2169 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 329 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("constructor",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2177 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 333 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("constructor",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2185 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 339 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2193 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 344 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("C",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2201 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 348 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("C");
}
#line 2209 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 354 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2217 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 359 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("D",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2225 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 363 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("D");
}
#line 2233 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 369 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("memory_parameter_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2241 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 375 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("E",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2249 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 379 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("E");
}
#line 2257 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 385 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2265 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 391 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("F",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2273 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 395 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("F");
}
#line 2281 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 401 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2289 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 406 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("G",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2297 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 410 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("G");
}
#line 2305 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 416 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("scheduler_parameter_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2313 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 421 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("Z",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2321 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 425 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("Z");
}
#line 2329 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 431 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2337 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 435 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2345 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 439 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2353 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 443 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2361 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 447 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2369 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 451 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2377 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 455 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[0].Node));
}
#line 2385 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 459 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter");
}
#line 2393 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 465 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("argument",(yyvsp[0].Node));
}
#line 2401 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 469 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("argument",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2409 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 474 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("valuearray",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2417 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 478 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("valuearray");
}
#line 2425 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 483 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("H",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2433 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 487 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("H");
}
#line 2441 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 494 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2449 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 498 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2457 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 502 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2465 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 506 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2473 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 510 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2481 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 514 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter",(yyvsp[0].Node));
}
#line 2489 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 518 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter");
}
#line 2497 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 524 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("memory_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2505 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 528 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("memory_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2513 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 532 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("memory_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));

}
#line 2522 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 537 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("memory_parameter",(yyvsp[0].Node));
}
#line 2530 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 541 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("memory_parameter");
}
#line 2538 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 547 "bisonfinal.y" /* yacc.c:1646  */
    {	
	printf("JOB ID FOUND\n");
	(yyval.Node) = add_new_node("job_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2547 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 552 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2555 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 556 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2563 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 560 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2571 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 564 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2579 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 568 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter",(yyvsp[0].Node));
}
#line 2587 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 572 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter");
}
#line 2595 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 578 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2603 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 582 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2611 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 586 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2619 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 590 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2627 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 594 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2635 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 598 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter",(yyvsp[0].Node));
}
#line 2643 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 602 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter");
}
#line 2651 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 608 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("scheduler_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2659 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 612 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("scheduler_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2667 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 616 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("scheduler_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2675 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 620 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("scheduler_parameter",(yyvsp[0].Node));
}
#line 2683 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 624 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("scheduler_parameter");
}
#line 2691 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 630 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2699 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 634 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2707 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 638 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2715 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 642 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2723 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 646 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2731 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 650 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2739 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 654 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2747 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 659 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("func_arg_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2755 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 663 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("func_arg_list");
}
#line 2763 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 668 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("I",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2771 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 672 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("func_arg_list");
}
#line 2779 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 678 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("value",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2787 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 682 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("value",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2795 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 686 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("value",(yyvsp[0].Node));
}
#line 2803 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 690 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("value",(yyvsp[0].Node));
}
#line 2811 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 697 "bisonfinal.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_new_node("semi",(yyvsp[0].Node));
}
#line 2819 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 701 "bisonfinal.y" /* yacc.c:1646  */
    {
	printf("Error: Missing ';' in line no %d\n", lineno); 
	flag = 1; 
	(yyval.Node) = NULL;
}
#line 2829 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 709 "bisonfinal.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_new_node("rp",(yyvsp[0].Node));
}
#line 2837 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 713 "bisonfinal.y" /* yacc.c:1646  */
    {
	printf("Error: Missing ')' in line no %d\n", lineno); 
	flag = 1; 
	(yyval.Node) = NULL;
}
#line 2847 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 721 "bisonfinal.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_new_node("rsp",(yyvsp[0].Node));
}
#line 2855 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 725 "bisonfinal.y" /* yacc.c:1646  */
    {
	printf("Error: Missing ']' in line no %d\n", lineno); 
	flag = 1; 
	(yyval.Node) = NULL;
}
#line 2865 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;


#line 2869 "bisonfinal.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 734 "bisonfinal.y" /* yacc.c:1906  */

int main()
{
    yyparse();
}
 
