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

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "utility.cpp"
void yyerror(string s)
{
    extern int yylineno;
}

using namespace std;
int yylex(void);
extern int  yylex();
extern int yylineno;
extern int lineno;
int flag=0;
int level=0;
int label=0;
long long int offset=268500992;

int noelseflag = 1;

struct id_name
{
	string name;
	string type;
	string eletype;
	vector<int> dimlist;
};

vector<id_name> namelist;

struct sym_tab_entry{
	string name,type,eletype;
	int level,size;
	long long int offset;
	vector<int> dimlist;
};

struct func_tab_entry{
	string name,rettype,code;
	vector<sym_tab_entry> paramlist;
};

vector<func_tab_entry> func_tab;

func_tab_entry* active_function_ptr = NULL;

vector<int> dim_list;

vector<sym_tab_entry> param_list;

vector<sym_tab_entry> sym_tab;

struct sym_tab_entry * search_sym_tab_decl(string var_name, int level)
{
	if(active_function_ptr != NULL)
	{
		for(int i = 0; i < active_function_ptr->paramlist.size(); i++)
		{
			if(active_function_ptr->paramlist[i].name == var_name)
			{
				printf("Var name already found in parameter list.\n");
				return &(active_function_ptr->paramlist[i]);
			}
		}
	}
	for(int i = 0; i<sym_tab.size();i++)
	{
		if((sym_tab[i].name == var_name) && (sym_tab[i].level == level))
		{
			cout<<"found "<<var_name<<" in sym_tab\n";
			return &(sym_tab[i]);
		}
	}
	return NULL;
}

struct sym_tab_entry * search_sym_tab_use(string var_name, int level,int* func_flag,int* index)
{
	if(active_function_ptr != NULL)
	{
		for(int i = 0; i < active_function_ptr->paramlist.size(); i++)
		{
			if(active_function_ptr->paramlist[i].name == var_name)
			{
				*func_flag=1;
				*index=i;
				return &(active_function_ptr->paramlist[i]);
			}
		}
	}
	for(int i = level; i>=0 ; i--)
	{
		for(int j = 0; j<sym_tab.size();j++)
		{
			if((sym_tab[j].name == var_name) && (sym_tab[j].level == i))
			{
				cout<<"found "<<var_name<<" in sym_tab\n";
				return &(sym_tab[j]);
			}
		}
	}
	return NULL;
}


struct func_tab_entry * search_func_tab(string var_name)
{
	for(int i = 0; i<func_tab.size();i++)
	{
		if(func_tab[i].name == var_name)
		{
			cout<<"found "<<var_name<<" in func_tab\n";
			return &(func_tab[i]);
		}
	}
	return NULL;
}

void print_sym_table()
{
	cout<<endl<<"***********Printing sym_table*****************"<<endl;
	for(int i = 0; i < sym_tab.size(); i++)
	{
		cout<<"Name : "<<sym_tab[i].name<<" Level : "<<sym_tab[i].level<<"  Type : "<<sym_tab[i].type<<"  Eletype : "<<sym_tab[i].eletype<<" Size : "<<sym_tab[i].size<<" Dimlist : ";
		for(int j = 0; j < sym_tab[i].dimlist.size(); j++)
		{
			cout<<" "<<sym_tab[i].dimlist[j]<<" ";
		}
		cout<<"Offest :"<<sym_tab[i].offset<<endl;
		cout<<endl;
	}
	cout<<endl;
}

void print_func_table()
{
	cout<<endl<<"***********Printing func_table*****************"<<endl;
	for(int i = 0; i < func_tab.size(); i++)
	{
		cout<<"Name : "<<func_tab[i].name<<" retype : "<<func_tab[i].rettype<<" Paramlist : ";
		for(int j = 0; j < func_tab[i].paramlist.size(); j++)
		{
			cout<<"["<<func_tab[i].paramlist[j].name<<","<<func_tab[i].paramlist[j].type<<func_tab[i].paramlist[j].eletype<<"]  ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void clear_sym_tab(int level)
{
	for(int i = 0; i<sym_tab.size();i++)
	{
		if(sym_tab[i].level == level)
		{
			sym_tab.erase(sym_tab.begin()+i);
		}
	}
}

sym_tab_entry* check_id_arr(string name,int level,int* var,int* func_flag,int* index, vector<int> dimlist)
{
	sym_tab_entry* temp = search_sym_tab_use(name,level,func_flag,index);
	if(temp!=NULL)
	{
		if(temp->type == "arraytype")
		{
			*var=-1;
			if(temp->dimlist.size() == dimlist.size())
			{
				int size=temp->size;
				for(int i=0;i<dimlist.size();i++)
				{
					if(*var == -1)
					{
						(*var)=dimlist[i]*(size/(temp->dimlist[i]));
					}
					else
					{
						(*var)+=dimlist[i]*(size/(temp->dimlist[i]));
					}
					size=size/(temp->dimlist[i]);
				}
				dimlist.clear();
				return temp;
			}
			else
			{
				printf("Incorrect Dimensions. Array declared is of dimension : %ld\n", temp->dimlist.size());
			}
		}
		else if(temp->type == "simple" && dimlist.size() != 0)
		{
			cout<<"Variable is of type simple but used as an array"<<endl;
		}
		{

		}
		dimlist.clear();
		return temp;
	}
	else
	{
		printf("Variable undeclared\n");
	}
	return NULL;
}

bool coercible(string type1, string type2)
{
	if( (type1 == "int" || type1 == "float") &&  (type2 == "int" || type2 == "float") )
	{
		return true;
	}
	if( (type1 == "int" || type1 == "char") &&  (type2 == "int" || type2 == "char") )
	{
		return true;
	}
	return false;
}

int compatible_arithop(string type1, string type2)
{
	if( (type1 == "int" || type1 == "float") &&  (type2 == "int" || type2 == "float") )
	{
		return true;
	}
	else if(type1 == "int" && type2=="char" || type1 == "char" && type2=="int")
	{
		return true;
	}
	return false;
}

int compatible_assign(string type1, string type2)
{
	if( (type1 == "int" || type1 == "float") &&  (type2 == "int" || type2 == "float") )
	{
		return true;
	}
	else if(type1 == "int" && type2=="char")
	{
		return true;
	}
	else if(type1 == "char" && type2=="char")
	{
		return true;
	}
	return false;
}

string compare_types(string type1,string type2)
{
	if(type1=="int" && type2=="int")
	{
		return "int";
	}
	if(type1=="float" && type2=="int")
	{
		return "float";
	}
	if(type1=="int" && type2=="float")
	{
		return "float";
	}
	if(type1=="float" && type2=="float")
	{
		return "float";
	}
	if(type1=="float" && type2=="char")
	{
		return "float";
	}
	if(type1=="int" && type2=="char")
	{
		return "int";
	}
	if(type1=="char" && type2=="int")
	{
		return "int";
	}
	if(type1=="char" && type2=="char")
	{
		return "char";
	}
	return "errortype";
}




#line 362 "bisonfinal.tab.c" /* yacc.c:339  */

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
    INT = 340,
    FLOAT = 341,
    VOID = 342,
    CHAR = 343,
    CHARACTER = 344,
    RETURN = 345,
    BREAK = 346,
    CONTINUE = 347,
    INTEGER_LITERAL = 348
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 297 "bisonfinal.y" /* yacc.c:355  */

	node *Node;

#line 500 "bisonfinal.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISONFINAL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 517 "bisonfinal.tab.c" /* yacc.c:358  */

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
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1250

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  215
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  452

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   348

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
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   312,   312,   341,   346,   352,   352,   352,   362,   362,
     387,   387,   413,   418,   423,   428,   433,   438,   443,   450,
     455,   460,   488,   488,   488,   498,   498,   498,   508,   514,
     588,   605,   628,   636,   642,   650,   660,   665,   672,   677,
     682,   687,   695,   704,   714,   727,   747,   766,   785,   804,
     823,   834,   834,   834,   842,   849,   853,   857,   861,   865,
     869,   873,   880,   885,   891,   896,   902,   907,   917,   959,
    1006,  1051,  1096,  1147,  1190,  1236,  1250,  1260,  1274,  1284,
    1300,  1315,  1323,  1338,  1360,  1370,  1386,  1396,  1411,  1418,
    1422,  1426,  1473,  1481,  1490,  1494,  1498,  1502,  1506,  1510,
    1516,  1521,  1526,  1531,  1536,  1541,  1546,  1552,  1557,  1562,
    1568,  1573,  1578,  1583,  1588,  1593,  1598,  1603,  1608,  1612,
    1616,  1620,  1624,  1628,  1632,  1637,  1642,  1646,  1651,  1656,
    1660,  1665,  1671,  1675,  1679,  1683,  1687,  1691,  1696,  1701,
    1705,  1709,  1714,  1719,  1724,  1729,  1733,  1737,  1741,  1745,
    1750,  1755,  1759,  1763,  1767,  1771,  1775,  1780,  1785,  1789,
    1793,  1797,  1802,  1807,  1811,  1815,  1819,  1823,  1827,  1831,
    1836,  1841,  1845,  1850,  1855,  1859,  1863,  1867,  1874,  1878,
    1886,  1890,  1898,  1902,  1910,  1910,  1937,  1937,  1976,  1985,
    1990,  1995,  1999,  2005,  2014,  2027,  2032,  2038,  2038,  2038,
    2048,  2048,  2073,  2073,  2099,  2104,  2109,  2114,  2119,  2124,
    2133,  2181,  2188,  2193,  2202,  2212
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
  "GET_LOAD", "SET_ALGO", "INT", "FLOAT", "VOID", "CHAR", "CHARACTER",
  "RETURN", "BREAK", "CONTINUE", "INTEGER_LITERAL", "$accept",
  "grammar_start", "stmtlist", "stmt", "$@1", "$@2", "$@3", "$@4",
  "break_stmt", "continue_stmt", "return_stmt", "elsestmt", "$@5", "$@6",
  "$@7", "$@8", "d", "list_var", "X", "id_arr", "br_dimlist", "type",
  "exprc", "A", "switchstmt", "$@9", "$@10", "expression", "initial",
  "init", "mathexpr", "assignexpr", "arithexpr", "expr1", "expr2", "expr3",
  "expr4", "factor", "constructor", "proc_parameter_list", "C",
  "link_parameter_list", "D", "memory_parameter_list", "E",
  "job_parameter_list", "F", "cluster_parameter_list", "G",
  "scheduler_parameter_list", "Z", "proc_parameter", "argument",
  "valuearray", "H", "link_parameter", "memory_parameter", "job_parameter",
  "cluster_parameter", "scheduler_parameter", "function", "func_arg_list",
  "I", "value", "semi", "rp", "rsp", "func_decl", "$@11", "func_head",
  "$@12", "res_id", "decl_plist", "decl_pl", "decl_param", "stmtlist_body",
  "stmt_body", "$@13", "$@14", "$@15", "$@16", "func_call", "paramlist",
  "plist", "empty", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348
};
# endif

#define YYPACT_NINF -427

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-427)))

#define YYTABLE_NINF -216

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     774,    -6,    12,    18,    33,    30,   159,    21,  -427,    36,
      41,    61,    63,    78,    81,    93,    99,   114,   116,   121,
    -427,  -427,  -427,  -427,  -427,  1102,  -427,  -427,     7,  -427,
     737,  -427,  -427,  -427,     2,   212,   113,     2,  -427,  -427,
    -427,  -427,   131,    27,    55,  -427,  -427,   128,  -427,   147,
     151,  -427,  -427,  1102,  1102,  1102,    30,   132,   109,  -427,
      30,    30,   149,   943,   111,   261,   975,  1002,   803,   803,
     803,  1130,   803,   803,     2,  -427,  -427,  -427,  -427,  -427,
      30,    66,    30,    30,    30,    30,  -427,  -427,    62,  -427,
     145,  -427,    30,    30,    30,    30,    30,    30,    66,  -427,
    -427,    31,  -427,     8,    31,     2,   109,  -427,  -427,  -427,
    -427,   156,   137,   479,   160,    30,  1161,   154,   157,   158,
     161,   162,   148,   148,   164,  -427,   128,   109,   165,  -427,
    -427,   177,   178,   187,   189,   193,   109,   183,  -427,   195,
     203,   204,   109,   194,  -427,   206,   207,   208,   209,   211,
     109,  -427,   202,   214,   216,   221,   223,   225,   109,  -427,
     227,   228,   109,   109,   109,    57,   232,   234,   109,  -427,
     231,   109,   109,  -427,  -427,  -427,  -427,   128,   169,   170,
     251,   253,   254,   255,   257,  -427,  -427,  -427,  -427,  -427,
      30,   237,  -427,    55,    55,  -427,  -427,  -427,  -427,   840,
      85,  1102,  1102,   258,  1038,  1065,  1102,   266,  1102,   271,
    -427,    30,    30,  -427,   265,    32,   238,  1161,  1161,  1161,
    1161,  1161,   267,   213,   224,  1161,  -427,   943,  -427,  1161,
    1161,  1161,  1161,  1161,  -427,   111,  -427,  1161,  1161,  1161,
    -427,   261,  -427,  1161,  1161,  1161,  1161,   803,  -427,   975,
    -427,  1161,   803,  1161,  1161,  1161,  -427,  1002,  -427,   803,
    -427,  -427,  -427,  -427,  1161,   803,   803,  -427,  1130,  -427,
    -427,  -427,   803,   803,   803,   803,   803,   803,   803,  -427,
     148,   272,   276,   288,   290,  -427,  -427,  -427,     2,   148,
       2,   291,   840,  -427,   277,   295,   278,  -427,  -427,  -427,
    -427,  1102,  -427,  1102,  -427,  -427,  -427,    28,   301,  -427,
    -427,  -427,  -427,  -427,  -427,  1161,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,   109,   109,   109,   109,   109,   109,   109,
    -427,  1102,  1102,  1102,    30,  -427,  -427,  -427,  -427,   302,
    -427,    85,   877,  -427,  -427,   877,  1102,    30,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,    31,    31,     2,   109,
     304,  -427,  -427,   307,   109,   109,   309,   310,  1102,   271,
    -427,   311,  -427,   314,   316,  -427,  -427,    28,  -427,    -3,
    -427,  -427,   877,   877,  1102,   317,   313,  -427,   877,   877,
    -427,   318,   109,  -427,  1102,   319,  -427,   320,  -427,   322,
     877,    31,  -427,   325,    -3,  -427,  -427,   328,   271,  -427,
     877,   330,  -427,  -427,   334,  -427,   877,  -427,  -427,   336,
      -3,  -427
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      62,     0,     0,     0,     0,     0,     0,    34,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    41,    40,    88,    62,    19,    20,     0,     2,
      62,    17,    18,    16,     0,    91,     0,     0,    60,    61,
      66,    67,    76,    78,    81,    84,    86,     0,    15,     0,
       0,    93,     4,    62,    62,    62,     0,    91,     0,    85,
     212,     0,    35,   125,   138,   143,   150,   157,   171,   171,
     171,   162,   171,   171,     0,     1,     3,   179,   178,    14,
       0,     0,     0,     0,     0,     0,    73,    74,    34,    29,
      33,    13,     0,     0,     0,     0,     0,     0,     0,   184,
     186,     0,    42,    50,     0,     0,     0,   181,   180,    92,
     214,     0,   211,    91,     0,     0,   129,     0,     0,     0,
       0,     0,     0,     0,     0,   176,   177,     0,   102,   124,
     126,     0,     0,     0,     0,     0,     0,   105,   137,     0,
       0,     0,     0,   108,   142,     0,     0,     0,     0,     0,
       0,   149,   111,     0,     0,     0,     0,     0,     0,   156,
     114,   173,     0,     0,     0,     0,     0,     0,     0,   161,
     117,     0,     0,    21,    65,    63,    68,    64,     0,     0,
       0,     0,     0,     0,     0,    89,    69,    70,    71,    72,
       0,    30,    75,    79,    80,    77,    82,    83,    90,    62,
     190,    62,    62,     0,    62,    62,    62,     0,    62,    54,
     210,     0,     0,    36,     0,     0,   131,     0,     0,     0,
       0,     0,    34,     0,     0,     0,    94,   125,   100,     0,
       0,     0,     0,     0,    95,   138,   103,     0,     0,     0,
      96,   143,   106,     0,     0,     0,     0,     0,    97,   150,
     109,     0,     0,     0,     0,     0,    98,   157,   112,   171,
     170,    55,    58,    59,     0,     0,     0,    99,   162,   115,
      56,    57,   171,   171,   171,   171,   171,   171,   171,    32,
       0,     0,     0,     0,     0,   208,   209,   207,     0,     0,
       0,     0,    62,   196,     0,     0,   189,   192,    43,    44,
       5,    62,    45,    62,    46,    47,     8,     0,     0,    12,
     213,    37,   183,   182,   127,   129,   128,   119,   120,   121,
     122,   123,   175,   174,   118,   101,   136,   132,   133,   134,
     135,   104,   141,   139,   140,   107,   144,   145,   146,   147,
     148,   110,   155,   151,   152,   153,   154,   113,   172,   158,
     159,   160,   116,     0,     0,     0,     0,     0,     0,     0,
      31,    62,    62,    62,     0,   206,   205,   185,   195,   193,
     187,     0,    62,    48,    49,    62,    62,     0,   130,   163,
     164,   165,   166,   167,   169,   168,     0,     0,     0,     0,
       0,   191,     6,     0,     0,     0,     0,     0,    62,    54,
     194,     0,     9,     0,     0,   197,   200,     0,   204,    28,
      10,    51,    62,    62,    62,     0,     0,     7,    62,    62,
     198,     0,     0,    25,    62,     0,    52,     0,   201,     0,
      62,     0,    11,     0,    28,   202,    26,     0,    54,   199,
      62,     0,    22,    53,     0,    27,    62,   203,    23,     0,
      28,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -427,  -427,    77,  -427,  -427,  -427,  -427,  -427,  -190,  -180,
    -179,  -426,  -427,  -427,  -427,  -427,  -178,    50,  -427,   230,
    -427,  -188,   -44,   -84,  -397,  -427,  -427,   185,   262,  -427,
     -46,  -427,    45,   246,  -427,    40,    54,   345,     0,   129,
    -427,   120,  -427,   117,  -427,   108,  -427,   102,  -427,    92,
    -427,  -427,   329,    51,  -427,  -427,  -427,  -427,  -427,  -427,
     269,   -56,  -427,   448,    37,   366,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,    -2,    73,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -176
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    30,   372,   401,   375,   418,    31,    32,
      33,   417,   446,   449,   430,   441,    34,    89,   191,    57,
      62,    36,   101,   102,   309,   419,   433,    37,    38,   175,
      39,    40,   125,    42,    43,    44,    45,    46,   126,   127,
     228,   136,   236,   142,   242,   150,   250,   158,   258,   168,
     269,   128,   161,   215,   316,   137,   143,   152,   160,   170,
     185,   162,   260,   130,    79,   109,   314,    48,   199,    49,
     200,    50,   295,   296,   297,   291,   292,   412,   427,   413,
     440,    51,   111,   112,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,   415,   408,    77,    53,    47,    47,    75,   439,   285,
     104,   289,   294,   163,   164,   114,   171,   172,    78,   286,
     287,   288,    54,   293,   451,    47,   204,   205,    55,    77,
      47,    60,   107,   312,   176,    61,   186,   187,   188,   189,
       5,   443,   108,    56,    78,    41,    63,   313,    93,    94,
      58,    64,    95,    47,    47,    47,    47,     6,     7,     8,
      47,    47,     9,    10,    11,    12,    13,    67,   416,   214,
      41,    65,  -188,    66,    91,    41,    61,   264,    96,    97,
     177,   206,    47,    47,    47,    47,   201,   202,    67,   201,
     202,    68,    47,    47,    47,    47,    47,    47,    41,    41,
      41,   106,   285,    69,   289,   110,    41,    76,    17,    70,
     107,   173,   286,   287,   288,    47,   293,   298,   299,    24,
     108,     5,   178,   179,    71,    41,    72,    41,    41,    41,
      41,    73,   180,   193,   194,   181,   182,   192,     6,     7,
       8,    88,   208,     9,    10,    11,    12,    13,   183,   184,
     196,   197,   131,   132,   133,   134,   135,    92,    98,    99,
      41,   100,    81,   115,   307,   190,   176,   210,   211,     5,
      20,    21,    22,    23,   217,   213,   222,   218,   219,   272,
     273,   220,   221,   294,   225,   122,   123,     7,     8,    17,
      47,     9,    10,    11,    12,    13,   227,   229,   230,    47,
      24,    47,    47,   348,    47,    47,    47,   231,    47,   232,
      74,    47,    47,   233,   235,   237,   353,   354,   355,   356,
     357,   358,   359,   238,   239,   241,   243,   244,   245,   246,
      35,   247,    80,   249,   251,   279,   252,    17,   103,   103,
     105,   253,    81,   254,    41,   255,    41,    41,    24,    41,
      41,    41,   265,    41,   266,    35,   310,    41,   257,   259,
      35,   274,   268,   275,   276,   277,    90,   278,   280,   315,
     300,     5,    82,    83,    84,    85,    86,    87,   306,   308,
     311,    61,   361,    35,    35,    35,   362,   322,     6,     7,
       8,   113,    47,     9,    10,    11,    12,    13,   363,   323,
     364,    47,   139,    47,   367,   369,   370,   140,   141,   371,
      35,   377,   113,   113,   113,   113,   390,   386,   387,   400,
     402,   405,   406,   424,   409,   365,   410,   366,   411,   423,
     360,   428,   432,   434,   435,   122,   123,    41,   438,    17,
     442,   195,   174,   445,   376,   113,    41,   447,    41,   450,
      24,    59,   223,   224,   407,   331,   325,   341,   335,   347,
     352,    47,    47,    47,    47,   368,   378,   198,     0,   391,
       0,     0,    47,     0,     0,    47,    47,    47,     0,     0,
     431,     0,     0,     0,   290,     0,   103,   103,     0,   302,
     304,   305,   129,   103,     0,   151,   159,     0,    47,     0,
     169,     0,     0,     0,     0,     0,    41,    41,    41,   389,
       0,     0,    47,    47,    47,     0,     0,    41,    47,    47,
      41,    41,   395,     0,    47,   398,     0,     0,     0,    35,
      47,    35,    35,     0,    35,    35,    35,     0,    35,     0,
      47,     0,   113,    41,   414,     0,    47,     0,     0,   392,
       0,     0,   393,     0,     0,     0,     0,    41,    41,    41,
       0,     0,     0,    41,    41,     0,     0,   203,     0,    41,
     207,     0,   209,     0,     0,    41,     0,   290,     0,     0,
       0,     0,     0,     0,     0,    41,   373,     0,   374,   420,
     421,    41,     0,   226,     0,   425,   426,     0,     0,   212,
       0,     0,   234,     0,     0,     0,     0,   436,   240,    81,
      90,     0,   138,   144,     0,     0,   248,   444,     0,    90,
       0,     0,    35,   448,   256,     0,     0,     0,   261,   262,
     263,    35,     0,    35,   267,     0,     0,   270,   271,    82,
      83,    84,    85,    86,    87,     0,   103,   103,   388,     0,
       0,     0,     0,     0,     0,     0,   129,     0,     0,     0,
       0,   394,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   340,     0,   151,     0,
       0,   343,     0,   103,     0,     0,   159,     0,     0,     0,
       0,    35,    35,    35,   350,   351,     0,   169,     0,   422,
       0,     0,    35,     0,     0,    35,    35,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    35,    35,     0,     0,     0,    35,    35,
       0,     0,     0,     0,    35,     0,     0,     0,     0,     0,
      35,     0,     0,     0,     0,   317,   318,   319,   320,   321,
      35,     0,     0,   324,     0,     0,    35,   326,   327,   328,
     329,   330,     0,   138,     0,   332,   333,   334,     0,   144,
       0,   336,   337,   338,   339,     0,     0,     0,     0,   342,
       0,   344,   345,   346,     0,     0,     0,     0,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,   379,
     380,   381,   382,   383,   384,   385,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -215,     0,     0,
       1,     0,     2,     3,     4,     0,     0,     5,     0,     0,
    -215,     0,   396,   397,     0,   399,     0,     0,     0,     0,
     403,   404,     0,   216,     6,     7,     8,     0,     0,     9,
      10,    11,    12,    13,  -215,     0,     0,     1,     0,     2,
       3,     4,     0,     0,     5,     0,     0,     0,   429,     0,
       0,     0,     0,     0,     0,     0,     0,   437,     0,     0,
       0,     6,     7,     8,    14,    15,     9,    10,    11,    12,
      13,     0,     0,     5,    16,    17,     0,   116,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       6,     7,     8,     0,     0,     9,    10,    11,    12,    13,
       0,    14,    15,   281,     0,   282,   283,   284,     0,     0,
       5,    16,    17,  -215,     0,    18,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     6,     7,     8,
       0,     0,     9,    10,    11,    12,    13,   122,   123,     0,
       1,    17,     2,     3,     4,     0,     0,     5,     0,     0,
    -215,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     8,    14,    15,     9,
      10,    11,    12,    13,     0,     0,     0,    16,    17,     0,
       0,    18,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     5,    16,    17,     0,   116,    18,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       6,     7,     8,     0,     0,     9,    10,    11,    12,    13,
     117,   118,   119,   120,   121,     5,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     7,     8,     0,     0,     9,    10,    11,
      12,    13,     5,     0,     0,     0,   116,   122,   123,   124,
       0,    17,     0,   145,   146,   147,   148,     0,     0,     6,
       7,     8,    24,     0,     9,    10,    11,    12,    13,     0,
       0,     0,     0,   153,     0,     0,     0,   149,     5,   122,
     123,     0,     0,    17,   154,   155,   156,   157,   301,     0,
       0,     0,     0,     0,    24,     6,     7,     8,     0,     0,
       9,    10,    11,    12,    13,     5,   122,   123,     0,     0,
      17,     0,     0,     0,     0,   303,     0,     0,     0,     0,
       0,    24,     6,     7,     8,     0,     0,     9,    10,    11,
      12,    13,     0,     0,     0,    14,    15,     0,     0,     0,
       0,     0,     5,     0,     0,    16,    17,     0,     0,    18,
       0,     0,    19,     0,     0,     0,     0,    24,     0,     6,
       7,     8,    14,    15,     9,    10,    11,    12,    13,     0,
       5,     0,    16,    17,   116,     0,    18,     0,     0,    19,
       0,     0,     0,     0,    24,     0,     0,     6,     7,     8,
       0,     0,     9,    10,    11,    12,   165,     0,     0,    14,
      15,     5,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,     0,    18,     0,     0,    19,     0,     6,     7,
       8,    24,     0,     9,    10,    11,    12,    13,     0,     0,
       0,     0,     0,     0,   122,   123,     0,     0,    17,   166,
     167,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,   123,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24
};

static const yytype_int16 yycheck[] =
{
       0,     4,   399,     1,    10,     5,     6,     0,   434,   199,
      54,   199,   200,    69,    70,    61,    72,    73,    16,   199,
     199,   199,    10,   199,   450,    25,    18,    19,    10,     1,
      30,    10,     1,     1,    80,    14,    82,    83,    84,    85,
      10,   438,    11,    10,    16,     0,    10,    15,    21,    22,
       5,    10,    25,    53,    54,    55,    56,    27,    28,    29,
      60,    61,    32,    33,    34,    35,    36,    10,    71,   115,
      25,    10,    10,    10,    37,    30,    14,    20,    23,    24,
      80,    73,    82,    83,    84,    85,    58,    59,    10,    58,
      59,    10,    92,    93,    94,    95,    96,    97,    53,    54,
      55,    56,   292,    10,   292,    60,    61,    30,    78,    10,
       1,    74,   292,   292,   292,   115,   292,   201,   202,    89,
      11,    10,    56,    57,    10,    80,    10,    82,    83,    84,
      85,    10,    66,    93,    94,    69,    70,    92,    27,    28,
      29,    28,   105,    32,    33,    34,    35,    36,    82,    83,
      96,    97,    41,    42,    43,    44,    45,    26,    30,    12,
     115,    10,    30,    14,   208,    20,   212,    11,    31,    10,
      85,    86,    87,    88,    20,    15,    28,    20,    20,    10,
      10,    20,    20,   371,    20,    74,    75,    28,    29,    78,
     190,    32,    33,    34,    35,    36,    31,    20,    20,   199,
      89,   201,   202,   259,   204,   205,   206,    20,   208,    20,
      25,   211,   212,    20,    31,    20,   272,   273,   274,   275,
     276,   277,   278,    20,    20,    31,    20,    20,    20,    20,
       0,    20,    20,    31,    20,   190,    20,    78,    53,    54,
      55,    20,    30,    20,   199,    20,   201,   202,    89,   204,
     205,   206,    20,   208,    20,    25,   211,   212,    31,    31,
      30,    10,    31,    10,    10,    10,    36,    10,    31,    31,
      12,    10,    60,    61,    62,    63,    64,    65,    12,     8,
      15,    14,    10,    53,    54,    55,    10,    74,    27,    28,
      29,    61,   292,    32,    33,    34,    35,    36,    10,    75,
      10,   301,    41,   303,    13,    28,    11,    46,    47,    31,
      80,    10,    82,    83,    84,    85,    14,   361,   362,    15,
      13,    12,    12,    10,    13,   288,    12,   290,    12,    12,
     280,    13,    13,    13,    12,    74,    75,   292,    13,    78,
      12,    95,    80,    13,   307,   115,   301,    13,   303,    13,
      89,     6,   122,   123,   398,   235,   227,   249,   241,   257,
     268,   361,   362,   363,   364,   292,   315,    98,    -1,   371,
      -1,    -1,   372,    -1,    -1,   375,   376,   377,    -1,    -1,
     424,    -1,    -1,    -1,   199,    -1,   201,   202,    -1,   204,
     205,   206,    63,   208,    -1,    66,    67,    -1,   398,    -1,
      71,    -1,    -1,    -1,    -1,    -1,   361,   362,   363,   364,
      -1,    -1,   412,   413,   414,    -1,    -1,   372,   418,   419,
     375,   376,   377,    -1,   424,   388,    -1,    -1,    -1,   199,
     430,   201,   202,    -1,   204,   205,   206,    -1,   208,    -1,
     440,    -1,   212,   398,   407,    -1,   446,    -1,    -1,   372,
      -1,    -1,   375,    -1,    -1,    -1,    -1,   412,   413,   414,
      -1,    -1,    -1,   418,   419,    -1,    -1,   101,    -1,   424,
     104,    -1,   106,    -1,    -1,   430,    -1,   292,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   440,   301,    -1,   303,   412,
     413,   446,    -1,   127,    -1,   418,   419,    -1,    -1,    20,
      -1,    -1,   136,    -1,    -1,    -1,    -1,   430,   142,    30,
     280,    -1,    64,    65,    -1,    -1,   150,   440,    -1,   289,
      -1,    -1,   292,   446,   158,    -1,    -1,    -1,   162,   163,
     164,   301,    -1,   303,   168,    -1,    -1,   171,   172,    60,
      61,    62,    63,    64,    65,    -1,   361,   362,   363,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,   376,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,    -1,   249,    -1,
      -1,   252,    -1,   398,    -1,    -1,   257,    -1,    -1,    -1,
      -1,   361,   362,   363,   265,   266,    -1,   268,    -1,   414,
      -1,    -1,   372,    -1,    -1,   375,   376,    -1,    -1,   424,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   412,   413,   414,    -1,    -1,    -1,   418,   419,
      -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,
     430,    -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,
     440,    -1,    -1,   225,    -1,    -1,   446,   229,   230,   231,
     232,   233,    -1,   235,    -1,   237,   238,   239,    -1,   241,
      -1,   243,   244,   245,   246,    -1,    -1,    -1,    -1,   251,
      -1,   253,   254,   255,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,   353,
     354,   355,   356,   357,   358,   359,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,
       3,    -1,     5,     6,     7,    -1,    -1,    10,    -1,    -1,
      13,    -1,   386,   387,    -1,   389,    -1,    -1,    -1,    -1,
     394,   395,    -1,   315,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    36,     0,    -1,    -1,     3,    -1,     5,
       6,     7,    -1,    -1,    10,    -1,    -1,    -1,   422,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   431,    -1,    -1,
      -1,    27,    28,    29,    67,    68,    32,    33,    34,    35,
      36,    -1,    -1,    10,    77,    78,    -1,    14,    81,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    67,    68,     3,    -1,     5,     6,     7,    -1,    -1,
      10,    77,    78,    13,    -1,    81,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    36,    74,    75,    -1,
       3,    78,     5,     6,     7,    -1,    -1,    10,    -1,    -1,
      13,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    67,    68,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    77,    78,    -1,
      -1,    81,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    77,    78,    -1,    14,    81,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    10,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    36,    10,    -1,    -1,    -1,    14,    74,    75,    76,
      -1,    78,    -1,    48,    49,    50,    51,    -1,    -1,    27,
      28,    29,    89,    -1,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    72,    10,    74,
      75,    -1,    -1,    78,    52,    53,    54,    55,    20,    -1,
      -1,    -1,    -1,    -1,    89,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    10,    74,    75,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    89,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    77,    78,    -1,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    27,
      28,    29,    67,    68,    32,    33,    34,    35,    36,    -1,
      10,    -1,    77,    78,    14,    -1,    81,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,    67,
      68,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    -1,    -1,    81,    -1,    -1,    84,    -1,    27,    28,
      29,    89,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,    10,    27,    28,    29,    32,
      33,    34,    35,    36,    67,    68,    77,    78,    81,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    95,    96,
      97,   102,   103,   104,   110,   113,   115,   121,   122,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   161,   163,
     165,   175,   178,    10,    10,    10,    10,   113,   126,   131,
      10,    14,   114,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,   121,     0,    96,     1,    16,   158,
      20,    30,    60,    61,    62,    63,    64,    65,    28,   111,
     113,   158,    26,    21,    22,    25,    23,    24,    30,    12,
      10,   116,   117,   121,   116,   121,   126,     1,    11,   159,
     126,   176,   177,   113,   124,    14,    14,    37,    38,    39,
      40,    41,    74,    75,    76,   126,   132,   133,   145,   146,
     157,    41,    42,    43,    44,    45,   135,   149,   157,    41,
      46,    47,   137,   150,   157,    48,    49,    50,    51,    72,
     139,   146,   151,    41,    52,    53,    54,    55,   141,   146,
     152,   146,   155,   155,   155,    36,    79,    80,   143,   146,
     153,   155,   155,   158,   122,   123,   124,   132,    56,    57,
      66,    69,    70,    82,    83,   154,   124,   124,   124,   124,
      20,   112,   126,   129,   129,   127,   130,   130,   154,   162,
     164,    58,    59,   159,    18,    19,    73,   159,   158,   159,
      11,    31,    20,    15,   124,   147,   157,    20,    20,    20,
      20,    20,    28,   113,   113,    20,   159,    31,   134,    20,
      20,    20,    20,    20,   159,    31,   136,    20,    20,    20,
     159,    31,   138,    20,    20,    20,    20,    20,   159,    31,
     140,    20,    20,    20,    20,    20,   159,    31,   142,    31,
     156,   159,   159,   159,    20,    20,    20,   159,    31,   144,
     159,   159,    10,    10,    10,    10,    10,    10,    10,   126,
      31,     3,     5,     6,     7,   102,   103,   104,   110,   115,
     121,   169,   170,   178,   115,   166,   167,   168,   117,   117,
      12,    20,   121,    20,   121,   121,    12,   116,     8,   118,
     126,    15,     1,    15,   160,    31,   148,   157,   157,   157,
     157,   157,    74,    75,   157,   133,   157,   157,   157,   157,
     157,   135,   157,   157,   157,   137,   157,   157,   157,   157,
     146,   139,   157,   146,   157,   157,   157,   141,   155,   157,
     146,   146,   143,   155,   155,   155,   155,   155,   155,   155,
     111,    10,    10,    10,    10,   158,   158,    13,   169,    28,
      11,    31,    98,   121,   121,   100,   158,    10,   147,   159,
     159,   159,   159,   159,   159,   159,   116,   116,   121,   126,
      14,   168,    96,    96,   121,   126,   159,   159,   158,   159,
      15,    99,    13,   159,   159,    12,    12,   116,   118,    13,
      12,    12,   171,   173,   158,     4,    71,   105,   101,   119,
      96,    96,   121,    12,    10,    96,    96,   172,    13,   159,
     108,   116,    13,   120,    13,    12,    96,   159,    13,   105,
     174,   109,    12,   118,    96,    13,   106,    13,    96,   107,
      13,   105
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    96,    96,    98,    99,    97,   100,    97,
     101,    97,    97,    97,    97,    97,    97,    97,    97,   102,
     103,   104,   106,   107,   105,   108,   109,   105,   105,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     115,   115,   116,   116,   116,   117,   117,   117,   117,   117,
     117,   119,   120,   118,   118,   121,   121,   121,   121,   121,
     121,   121,   121,   122,   123,   123,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   126,   126,   127,   127,   128,
     128,   128,   129,   129,   129,   130,   130,   131,   131,   131,
     131,   131,   131,   131,   132,   132,   132,   132,   132,   132,
     133,   134,   134,   135,   136,   136,   137,   138,   138,   139,
     140,   140,   141,   142,   142,   143,   144,   144,   145,   145,
     145,   145,   145,   145,   145,   145,   146,   146,   147,   147,
     148,   148,   149,   149,   149,   149,   149,   149,   149,   150,
     150,   150,   150,   150,   151,   151,   151,   151,   151,   151,
     151,   152,   152,   152,   152,   152,   152,   152,   153,   153,
     153,   153,   153,   154,   154,   154,   154,   154,   154,   154,
     155,   155,   156,   156,   157,   157,   157,   157,   158,   158,
     159,   159,   160,   160,   162,   161,   164,   163,   165,   166,
     166,   167,   167,   168,   168,   169,   169,   171,   172,   170,
     173,   170,   174,   170,   170,   170,   170,   170,   170,   170,
     175,   176,   176,   177,   177,   178
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     0,    10,     0,     8,
       0,    12,     5,     2,     2,     1,     1,     1,     1,     1,
       1,     3,     0,     0,    10,     0,     0,     6,     0,     2,
       2,     4,     2,     0,     1,     2,     3,     4,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     4,     4,
       1,     0,     0,    10,     0,     4,     4,     4,     4,     4,
       1,     1,     0,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     2,     2,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     1,     2,     1,     1,     1,     3,
       3,     1,     3,     1,     4,     4,     4,     4,     4,     4,
       2,     2,     0,     2,     2,     0,     2,     2,     0,     2,
       2,     0,     2,     2,     0,     2,     2,     0,     3,     3,
       3,     3,     3,     3,     1,     0,     1,     3,     2,     0,
       2,     0,     3,     3,     3,     3,     3,     1,     0,     3,
       3,     3,     1,     0,     3,     3,     3,     3,     3,     1,
       0,     3,     3,     3,     3,     3,     1,     0,     3,     3,
       3,     1,     0,     4,     4,     4,     4,     4,     4,     4,
       2,     0,     2,     0,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     0,     5,     2,     1,
       0,     3,     1,     2,     4,     2,     1,     0,     0,    10,
       0,     8,     0,    12,     5,     2,     2,     1,     1,     1,
       4,     1,     0,     3,     1,     0
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
#line 313 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("grammar_start",(yyvsp[0].Node));
	if(flag==0){
		printf("Compilation successful.\n");
		ofstream output;
		output.open("parsetree.txt");
		print_nodes_in_file((yyval.Node),output);
		(yyval.Node)->code = "main:\n" + (yyvsp[0].Node)->code + "li $v0,10\nsyscall\n";
		for(int i = 0; i < func_tab.size(); i++)
		{
			(yyval.Node)->code = (yyval.Node)->code + func_tab[i].code;
		}
		cout<<"***** FINAL CODE *****\n";
		cout<<(yyval.Node)->code;
		cout<<"***** FINAL CODE END *****\n";
		cout<<"\n";

		//print_nodes($$,output);
		//print_nodes_node_num($$,output);
		output.close();
	}
	else{
		printf("Error encountered\n");
	}
}
#line 2117 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 342 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmtlist",(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->code = (yyvsp[-1].Node)->code + (yyvsp[0].Node)->code;
}
#line 2126 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 347 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmtlist",(yyvsp[0].Node));
}
#line 2134 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 352 "bisonfinal.y" /* yacc.c:1646  */
    { level++;}
#line 2140 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 352 "bisonfinal.y" /* yacc.c:1646  */
    { clear_sym_tab(level); level--; }
#line 2146 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 353 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt",(yyvsp[-9].Node),(yyvsp[-8].Node),(yyvsp[-7].Node),(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-3].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	
	(yyval.Node)->code = (yyvsp[-7].Node)->code + "li $t0,1" + "\n" + "blt	$a0,$t0," + "L_"+to_string(label)+"\n" + (yyvsp[-3].Node)->code;
	if(!noelseflag)
		(yyval.Node)->code =(yyval.Node)->code + "j L_" +to_string(label-1);
	(yyval.Node)->code =(yyval.Node)->code+"\nL_"+to_string(label)+":\n" + (yyvsp[0].Node)->code;
    label++;
}
#line 2160 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 362 "bisonfinal.y" /* yacc.c:1646  */
    { level++; }
#line 2166 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 363 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt",(yyvsp[-7].Node),(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	clear_sym_tab(level);
	level--;

	(yyval.Node)->code = "\nL_" + to_string(label)+":\n" + (yyvsp[-5].Node)->code +"li $t0,1\n";
    label++;

	int break_index = (yyvsp[-1].Node)->code.find("break");
	string break_replace = "j L_" + to_string(label)+"\n";

	if (break_index!=std::string::npos)
	     (yyvsp[-1].Node)->code.replace(break_index, break_replace.size()-1, break_replace);

	int continue_index = (yyvsp[-1].Node)->code.find("conti");
	string continue_replace = "j L_" + to_string(label-1)+"\n";

	if (continue_index!=std::string::npos)
	     (yyvsp[-1].Node)->code.replace(continue_index, continue_replace.size()-1, continue_replace);

    (yyval.Node)->code = (yyval.Node)->code + "blt $a0,$t0, " + "L_"+to_string(label)+"\n" + (yyvsp[-1].Node)->code+"j "+"L_"+to_string(label-1)+"\nL_"+to_string(label)+":\n";

    label++;
}
#line 2195 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 387 "bisonfinal.y" /* yacc.c:1646  */
    { level++; }
#line 2201 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 388 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt",(yyvsp[-11].Node),(yyvsp[-10].Node),(yyvsp[-9].Node),(yyvsp[-8].Node),(yyvsp[-7].Node),(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	clear_sym_tab(level);
	level--;

	(yyval.Node)->code = (yyvsp[-9].Node)->code+"\nL_"+to_string(label)+":"+(yyvsp[-7].Node)->code+ "li $t0,1" + "\n" + "blt $a0,$t0," + "L_"+to_string(label+1)+"\n";

	int index = (yyvsp[-1].Node)->code.find("break");

	string break_replace = "j L_" + to_string(label+1)+"\n";
	if (index!=std::string::npos)
	     (yyvsp[-1].Node)->code.replace(index, break_replace.size()-1, break_replace);

	int continue_index = (yyvsp[-1].Node)->code.find("conti");
	string continue_replace = "j L_" + to_string(label)+"\n";
	cout<<"!@#$!@#$12#$!@33"<<continue_replace.size()<<" " <<continue_replace<<endl;
	if (continue_index!=std::string::npos)
	     (yyvsp[-1].Node)->code.replace(continue_index, continue_replace.size()-1, continue_replace);


	(yyval.Node)->code = (yyval.Node)->code + (yyvsp[-5].Node)->code + (yyvsp[-1].Node)->code+"\nj L_" + to_string(label) + "\nL_" + to_string(label+1) + ":\n";

	label++;
	label++;
}
#line 2231 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 414 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt",(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->code = (yyvsp[-2].Node)->code+"\n"+ "sw $a0,268501992\n" + (yyvsp[0].Node)->code;
}
#line 2240 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 419 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt",(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->code = (yyvsp[-1].Node)->code;
}
#line 2249 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 424 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt",(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->code = (yyvsp[-1].Node)->code;
}
#line 2258 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 429 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt",(yyvsp[0].Node));
	(yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 2267 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 434 "bisonfinal.y" /* yacc.c:1646  */
    {
		(yyval.Node) = add_new_node("stmt",(yyvsp[0].Node));
	    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 2276 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 439 "bisonfinal.y" /* yacc.c:1646  */
    {
		(yyval.Node) = add_new_node("stmt",(yyvsp[0].Node));
	    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 2285 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 444 "bisonfinal.y" /* yacc.c:1646  */
    {
		(yyval.Node) = add_new_node("stmt",(yyvsp[0].Node));
	    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 2294 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 451 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node)->code = "break";
}
#line 2302 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 456 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node)->code = "conti";
}
#line 2310 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 461 "bisonfinal.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_new_node("return_stmt",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    if(active_function_ptr!=NULL)
    {
	    long long int param_offset = (active_function_ptr->paramlist).size();
	    param_offset*=4;
	    if ((yyvsp[-1].Node)->code == "")
	    {
	 		(yyval.Node)->code = "jr $ra\n";
	    }
	    else
	    {
	    	if(active_function_ptr->rettype != (yyvsp[-1].Node)->eletype)
	    	{
	    		cout<<"function and return types mismatch"<<endl;
	    	}
	    	(yyval.Node)->code= (yyvsp[-1].Node)->code + "move $v0,$a0\n" + "\njr $ra\n";
	    }
    }
    else
    {
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"return statement outside function"<<endl;
    }
}
#line 2339 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 488 "bisonfinal.y" /* yacc.c:1646  */
    {level++; }
#line 2345 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 488 "bisonfinal.y" /* yacc.c:1646  */
    { clear_sym_tab(level); level--; }
#line 2351 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 489 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("elsestmt",(yyvsp[-9].Node),(yyvsp[-8].Node),(yyvsp[-7].Node),(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-3].Node),(yyvsp[-1].Node),(yyvsp[0].Node));

	(yyval.Node)->code = (yyvsp[-7].Node)->code + "li $t0,1" + "\n" + "blt	$a0,$t0," + "L_" + to_string(label+1)+"\n" + "L_" + to_string(label) + ":\n" + (yyvsp[-3].Node)->code + "L_" + to_string(label+1) + ":\n" + (yyvsp[0].Node)->code;
	label++;
	label++;
	
	noelseflag = 0;
}
#line 2365 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 498 "bisonfinal.y" /* yacc.c:1646  */
    {level++; }
#line 2371 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 498 "bisonfinal.y" /* yacc.c:1646  */
    {clear_sym_tab(level); level--; }
#line 2377 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 499 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("elsestmt",(yyvsp[-5].Node),(yyvsp[-4].Node),(yyvsp[-2].Node),(yyvsp[0].Node));
	(yyval.Node)->code = (yyvsp[-2].Node)->code+ "L_" + to_string(label) + ":\n" ;
	label++;

	noelseflag = 0;

}
#line 2390 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 508 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("elsestmt");
}
#line 2398 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 515 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("d",(yyvsp[-1].Node),(yyvsp[0].Node));
    string temp_code = "";
    (yyval.Node)->eletype = (yyvsp[-1].Node)->eletype;
    string temp_code2 = (yyvsp[0].Node)->code;
	for(int i=0; i<namelist.size(); i++)
	{	
		if(search_sym_tab_decl(namelist[i].name,level) == NULL)
		{	
			if(compatible_assign((yyvsp[-1].Node)->eletype,namelist[i].eletype) || namelist[i].eletype=="any")
			{
				sym_tab_entry temp;
				temp.type = namelist[i].type;
				
				temp.eletype = (yyvsp[-1].Node)->eletype;
				
				temp.name = namelist[i].name;


				temp.level=level;
				int count=1;
				if(temp.type == "arraytype")
				{
					temp.dimlist = namelist[i].dimlist;
					for(int j=0;j<namelist[i].dimlist.size();j++)
					{
						count*=namelist[i].dimlist[j];
					}
				}
				// hardcoded offset
				temp.offset=268500992+(count*4);
				temp.size=count;

				

	            int index = temp_code2.find("***" + temp.name);
	            string t = "sw $a0,"+to_string(offset)+"\n";
				if (index!=std::string::npos)
				{
					if(namelist[i].type=="arraytype")
					{
						cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"whole array cant be initialised"<<endl;
						(yyval.Node)->eletype = "errortype";						
					}
					else
					{
		     			temp_code2.replace(index, temp.name.size()+3, t);	
					}
				}
				offset += (temp.offset-268500992);
	            temp.offset = (offset - (temp.offset-268500992));
				sym_tab.push_back(temp);
			}
			else
			{
				cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"variable is declared of "<<(yyvsp[-1].Node)->eletype<<" but the expression is assigned "<<namelist[i].eletype<<endl;
				(yyval.Node)->eletype = "errortype";
			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Variable already declared"<<endl;
			(yyval.Node)->eletype = "errortype";
		}
	}
	temp_code += temp_code2;			
	(yyval.Node)->code = temp_code;
	print_sym_table();
	namelist.clear();
}
#line 2473 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 589 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("list_var",(yyvsp[-1].Node));
	(yyval.Node)->eletype = (yyvsp[-1].Node)->eletype;
	struct id_name temp;
	temp.name = (yyvsp[-1].Node)->node_val;
	temp.type = (yyvsp[-1].Node)->eletype;
	temp.eletype = (yyvsp[0].Node)->eletype;
	temp.dimlist = (yyvsp[-1].Node)->dimlist;
	namelist.push_back(temp);

	if((yyvsp[0].Node)->code != "")
	{
		(yyval.Node)->code = (yyvsp[0].Node)->code + "***" + (yyvsp[-1].Node)->node_val;
	}

}
#line 2494 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 606 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("list_var",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[-3].Node)->eletype;
	struct id_name temp;
	temp.name = (yyvsp[-3].Node)->node_val;
	temp.type = (yyvsp[-3].Node)->eletype;
	temp.eletype = (yyvsp[-2].Node)->eletype;
	temp.dimlist = (yyvsp[-3].Node)->dimlist;
	namelist.push_back(temp);

	if((yyvsp[-2].Node)->code != "")
	{
		(yyval.Node)->code = (yyvsp[-2].Node)->code + "***" + (yyvsp[-3].Node)->node_val + (yyvsp[0].Node)->code;
	}
	else
	{
		(yyval.Node)->code=(yyvsp[0].Node)->code;
	}

}
#line 2519 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 629 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node)=add_new_node("X",(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->eletype=(yyvsp[0].Node)->eletype;

	(yyval.Node)->code= (yyvsp[0].Node)->code;
}
#line 2530 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 636 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node)=add_new_node("X");
	(yyval.Node)->eletype="any";
}
#line 2539 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 643 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("id_arr",(yyvsp[0].Node));
	(yyval.Node)->node_val = (yyvsp[0].Node)->node_val;
	(yyval.Node)->eletype = "simple";
	(yyval.Node)->dimlist = dim_list;
	dim_list.clear();
}
#line 2551 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 651 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("id_arr",(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->node_val = (yyvsp[-1].Node)->node_val;
	(yyval.Node)->eletype = "arraytype";
	(yyval.Node)->dimlist = dim_list;
	dim_list.clear();
}
#line 2563 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 661 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("br_dimlist",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	dim_list.insert(dim_list.begin(), (yyvsp[-1].Node)->node_val_num);
}
#line 2572 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 666 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) =add_new_node("br_dimlist",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	dim_list.push_back((yyvsp[-1].Node)->node_val_num);
}
#line 2581 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 673 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("type",(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[0].Node)->node_val;
}
#line 2590 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 678 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("type",(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[0].Node)->node_val;
}
#line 2599 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 683 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("type",(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[0].Node)->node_val;
}
#line 2608 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 688 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("type",(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[0].Node)->node_val;
}
#line 2617 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 696 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("exprc",(yyvsp[0].Node));

	(yyval.Node)->node_val_num = (yyvsp[0].Node)->node_val_num;
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
	(yyval.Node)->code = (yyvsp[0].Node)->code;

}
#line 2630 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 705 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("exprc",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->node_val_num = (yyvsp[-2].Node)->node_val_num || (yyvsp[0].Node)->node_val_num;
	(yyval.Node)->eletype = "int";
	//code generation
	int label1 = label++;
	int label2 = label++;
	(yyval.Node)->code = (yyvsp[-2].Node)->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + (yyvsp[0].Node)->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nadd $t1,$t1,$t2\nli $t2,0\nbeq $t1,$t2,L_" + to_string(label1) + "\nli $a0,1\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,0\nL_" + to_string(label2) + ":\n";
}
#line 2644 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 715 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("exprc",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->node_val_num = (yyvsp[-2].Node)->node_val_num && (yyvsp[0].Node)->node_val_num;
	(yyval.Node)->eletype = "int";

	//code generation
	int label1 = label++;
	int label2 = label++;
	(yyval.Node)->code = (yyvsp[-2].Node)->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + (yyvsp[0].Node)->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nmult $t1,$t2\nmflo $t1\nli $t2,0\nbeq $t1,$t2,L_" + to_string(label1) + "\nli $a0,1\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,0\nL_" + to_string(label2) + ":\n";
}
#line 2659 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 728 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("A",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	if(compatible_arithop((yyvsp[-2].Node)->eletype,(yyvsp[0].Node)->eletype))
	{
		(yyval.Node)->node_val_num = (yyvsp[-2].Node)->node_val_num < (yyvsp[0].Node)->node_val_num;
		(yyval.Node)->eletype = "int";

		//code generation
		int label1 = label++;
	    int label2 = label++;
	    (yyval.Node)->code = (yyvsp[-2].Node)->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + (yyvsp[0].Node)->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nbge $t1,$t2,L_" + to_string(label1) + "\nli $a0,1\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,0\nL_" + to_string(label2) + ":\n";

	}
	else
	{
		(yyval.Node)->eletype = "errortype";
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands not compatible"<<endl;
	}
}
#line 2683 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 748 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("A",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	if(compatible_arithop((yyvsp[-2].Node)->eletype,(yyvsp[0].Node)->eletype))
	{
		(yyval.Node)->node_val_num = (yyvsp[-2].Node)->node_val_num > (yyvsp[0].Node)->node_val_num;
		(yyval.Node)->eletype = "int";

		//code generation
		int label1 = label++;
	    int label2 = label++;
	    (yyval.Node)->code = (yyvsp[-2].Node)->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + (yyvsp[0].Node)->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nble $t1,$t2,L_" + to_string(label1) + "\nli $a0,1\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,0\nL_" + to_string(label2) + ":\n";
	}
	else
	{
		(yyval.Node)->eletype = "errortype";
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands not compatible"<<endl;		
	}
}
#line 2706 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 767 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("A",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	if(compatible_arithop((yyvsp[-2].Node)->eletype,(yyvsp[0].Node)->eletype))
	{
		(yyval.Node)->node_val_num = ((yyvsp[-2].Node)->node_val_num == (yyvsp[0].Node)->node_val_num);
		(yyval.Node)->eletype = "int";

		//code generation
		int label1 = label++;
    	int label2 = label++;
    	(yyval.Node)->code = (yyvsp[-2].Node)->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + (yyvsp[0].Node)->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nbeq $t1,$t2,L_" + to_string(label1) + "\nli $a0,0\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,1\nL_" + to_string(label2) + ":\n";
	}
	else
	{
		(yyval.Node)->eletype = "errortype";
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands not compatible"<<endl;				
	}
}
#line 2729 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 786 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("A",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	if(compatible_arithop((yyvsp[-3].Node)->eletype,(yyvsp[-1].Node)->eletype))
	{
		(yyval.Node)->node_val_num = (yyvsp[-3].Node)->node_val_num <= (yyvsp[-1].Node)->node_val_num;
		(yyval.Node)->eletype = "int";

		//code generation
		int label1 = label++;
	    int label2 = label++;
	    (yyval.Node)->code = (yyvsp[-3].Node)->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + (yyvsp[0].Node)->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nbgt $t1,$t2,L_" + to_string(label1) + "\nli $a0,1\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,0\nL_" + to_string(label2) + ":\n";
	}
	else
	{
		(yyval.Node)->eletype = "errortype";
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands not compatible"<<endl;				
	}
}
#line 2752 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 805 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("A",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	if(compatible_arithop((yyvsp[-3].Node)->eletype,(yyvsp[-1].Node)->eletype))
	{
		(yyval.Node)->node_val_num = (yyvsp[-3].Node)->node_val_num >= (yyvsp[-1].Node)->node_val_num;
		(yyval.Node)->eletype = "int";

		//code generation
		int label1 = label++;
    	int label2 = label++;
    	(yyval.Node)->code = (yyvsp[-3].Node)->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + (yyvsp[0].Node)->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nblt $t1,$t2,L_" + to_string(label1) + "\nli $a0,1\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,0\nL_" + to_string(label2) + ":\n";
	}
	else
	{
		(yyval.Node)->eletype = "errortype";
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands not compatible"<<endl;				
	}
}
#line 2775 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 824 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("A",(yyvsp[0].Node));
	(yyval.Node)->node_val_num = (yyvsp[0].Node)->node_val_num;
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;

	//code generation
	(yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 2788 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 834 "bisonfinal.y" /* yacc.c:1646  */
    { level++; }
#line 2794 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 834 "bisonfinal.y" /* yacc.c:1646  */
    { clear_sym_tab(level); level--; }
#line 2800 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 835 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("switchstmt",(yyvsp[-9].Node),(yyvsp[-8].Node),(yyvsp[-7].Node),(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-3].Node),(yyvsp[-1].Node),(yyvsp[0].Node));

	(yyval.Node)->code = "lw $t0,268501992\n" + (yyvsp[-7].Node)->code + "bne $t0,$a0,L_" + to_string(label+1) +"\n" + (yyvsp[-3].Node)->code + "L_" + to_string(label+1) + ":" + (yyvsp[0].Node)->code;
	label++;
}
#line 2811 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 842 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("switchstmt");
}
#line 2819 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 850 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2827 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 854 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2835 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 858 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2843 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 862 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2851 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 866 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2859 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 870 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[0].Node));
}
#line 2867 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 874 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression",(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
	(yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 2877 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 880 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expression");
}
#line 2885 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 886 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("initial",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 2893 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 892 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("init",(yyvsp[0].Node));
}
#line 2901 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 897 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("init",(yyvsp[0].Node));
}
#line 2909 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 903 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("mathexpr",(yyvsp[0].Node));
	(yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 2918 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 908 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("mathexpr",(yyvsp[0].Node));
	(yyval.Node)->node_val_num = (yyvsp[0].Node)->node_val_num ;
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype ;
	(yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 2929 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 918 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	int var=0;
	int func_flag=0,index=0;
	sym_tab_entry * temp= check_id_arr((yyvsp[-2].Node)->node_val,level,&var,&func_flag,&index,(yyvsp[-2].Node)->dimlist);
	if(temp!=NULL)
	{
		if(compatible_assign(temp->eletype,(yyvsp[0].Node)->eletype) || (temp->eletype == "char" && (yyvsp[0].Node)->eletype == "char"))
		{
			if(temp->type=="simple")
			{
				if(func_flag==1)
				{
					(yyval.Node)->code = (yyvsp[0].Node)->code + "move $a" + to_string(index)+ ",$a0\n";
				}
				else
				{
					(yyval.Node)->code= (yyvsp[0].Node)->code + "sw $a0,"+to_string(temp->offset)+"\n";
				}
			}
			else
			{
				//var is offset of array
				// array's name is temp->name
				long long int tmpoffset = temp->offset + var*4;
				if(func_flag==1)
				{
					(yyval.Node)->code = (yyvsp[0].Node)->code + "move $a" + to_string(index)+ ",$a0\n";						
				}
				else
				{
					(yyval.Node)->code= (yyvsp[0].Node)->code + "sw $a0,"+ to_string(tmpoffset);
				}
			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Expected type "<<temp->eletype<<" , Found "<<(yyvsp[0].Node)->eletype<<endl;
		}
	}
}
#line 2975 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 960 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
	int func_flag=0,index=0;
	int var=0;
	sym_tab_entry * temp= check_id_arr((yyvsp[-2].Node)->node_val,level,&var,&func_flag,&index,(yyvsp[-2].Node)->dimlist);
	if(temp!=NULL)
	{
		if(compatible_assign(temp->eletype,(yyvsp[0].Node)->eletype))
		{
			temp->eletype = compare_types(temp->eletype,(yyvsp[0].Node)->eletype);
			if(temp->eletype=="simple")
			{
				if(func_flag==1)
				{
					(yyval.Node)->code= (yyvsp[0].Node)->code + "move $t1,$a" + to_string(index) + "\n add $a0,$a0,$t1\n"+  "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					(yyval.Node)->code= (yyvsp[0].Node)->code + "lw $t1," + to_string(temp->offset) + "\n add $a0,$a0,$t1\n"+  "sw $a0,"+to_string(temp->offset)+"\n"+ "li $a0,1\n";
				}

			}
			else
			{
				//var is offset of array
				// array's name is temp->name

				if(func_flag==1)
				{
					(yyval.Node)->code= (yyvsp[0].Node)->code + "move $t1,$a" + to_string(index) + "\n add $a0,$a0,$t1\n"+  "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					long long int tmpoffset = temp->offset + var*4;
					(yyval.Node)->code= (yyvsp[0].Node)->code + "lw $t1," + to_string(tmpoffset)+ "\n add $a0,$a0,$t1\n"+  "sw $a0,"+to_string(tmpoffset)+"\n"+ "li $a0,1\n";
				}

			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<(yyvsp[0].Node)->eletype<<" can't be assigned to a "<<temp->eletype<<endl;
		}
	}
}
#line 3026 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1007 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
	int func_flag=0,index=0;
	int var=0;
	sym_tab_entry * temp= check_id_arr((yyvsp[-2].Node)->node_val,level,&var,&func_flag,&index,(yyvsp[-2].Node)->dimlist);
	if(temp!=NULL)
	{
		if(compatible_assign(temp->eletype,(yyvsp[0].Node)->eletype))
		{
			temp->eletype = compare_types(temp->eletype,(yyvsp[0].Node)->eletype);
			if(temp->eletype=="simple")
			{
				if(func_flag==1)
				{
					(yyval.Node)->code= (yyvsp[0].Node)->code + "move $t1,$a" + to_string(index) + "\n sub $a0,$a0,$t1\n"+  "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					(yyval.Node)->code= (yyvsp[0].Node)->code + "lw $t1,(" + to_string(temp->offset)+ "\n sub $a0,$a0,$t1\n"+  "sw $a0,"+to_string(temp->offset)+"\n"+ "li $a0,1\n";
				}
			}
			else
			{
				//var is offset of array
				// array's name is temp->name
				long long int tmpoffset = temp->offset + var*4;	
				if(func_flag==1)
				{
					(yyval.Node)->code= (yyvsp[0].Node)->code + "move $t1,$a" + to_string(index) + "\n sub $a0,$a0,$t1\n"+  "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					(yyval.Node)->code= (yyvsp[0].Node)->code + "lw $t1," + to_string(tmpoffset)+ "\n sub $a0,$a0,$t1\n"+  "sw $a0,"+to_string(tmpoffset)+"\n"+ "li $a0,1\n";
				}

			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<(yyvsp[0].Node)->eletype<<" can't be assigned to a "<<temp->eletype<<endl;
		}
	}
}
#line 3075 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1052 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
	int func_flag=0,index=0;
	int var=0;
	sym_tab_entry * temp= check_id_arr((yyvsp[-2].Node)->node_val,level,&var,&func_flag,&index,(yyvsp[-2].Node)->dimlist);
	if(temp!=NULL)
	{
		if(compatible_assign(temp->eletype,(yyvsp[0].Node)->eletype))
		{
			temp->eletype = compare_types(temp->eletype,(yyvsp[0].Node)->eletype);
			if(temp->eletype=="simple")
			{
				if(func_flag==1)
				{	
					(yyval.Node)->code= (yyvsp[0].Node)->code + "move $t1,$a" + to_string(index)+ "\n mul $a0,$t1\n" + "mflo $a0" +  "move $a0,$a"+to_string(index) + "\n"+ "li $a0,1\n";
				}
				else
				{
					(yyval.Node)->code= (yyvsp[0].Node)->code + "lw $t1," + to_string(temp->offset)+ "\n mul $a0,$t1\n" + "mflo $a0" +  "sw $a0,"+to_string(temp->offset)+"\n"+ "li $a0,1\n";
				}
			}
			else
			{
				//var is offset of array
				// array's name is temp->name
				if(func_flag==1)
				{
					(yyval.Node)->code= (yyvsp[0].Node)->code + "move $t1,$a" + to_string(index)+ "\n mul $a0,$t1\n" + "mflo $a0" +  "move $a0,$a"+to_string(index) + "\n"+ "li $a0,1\n";
				}
				else
				{
					long long int tmpoffset = temp->offset + var*4;
					(yyval.Node)->code= (yyvsp[0].Node)->code + "lw $t1," + to_string(tmpoffset)+ "\n mul $a0,$t1\n" + "mflo $a0" +  "sw $a0,"+to_string(tmpoffset)+"\n"+ "li $a0,1\n";
				}

			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<(yyvsp[0].Node)->eletype<<" can't be assigned to a "<<temp->eletype<<endl;
		}
	}
}
#line 3124 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1097 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	int func_flag=0,index=0;
	int var=0;
	sym_tab_entry * temp= check_id_arr((yyvsp[-2].Node)->node_val,level,&var,&func_flag,&index,(yyvsp[-2].Node)->dimlist);
	if((yyvsp[0].Node)->node_val_num != 0)
	{
		if(compatible_assign(temp->eletype,(yyvsp[0].Node)->eletype))
		{
			temp->eletype = compare_types(temp->eletype,(yyvsp[0].Node)->eletype);
			if(temp!=NULL)
			{
				(yyval.Node)->eletype = temp->eletype;
				if(temp->eletype=="simple")
				{
					if(func_flag==1)
					{
						(yyval.Node)->code= (yyvsp[0].Node)->code + "move $t1,$a" + to_string(index) + "\n div $a0,$t1\n" + "mflo $a0" +  "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
					}
					else
					{
						(yyval.Node)->code= (yyvsp[0].Node)->code + "lw $t1," + to_string(temp->offset)+ "\n div $a0,$t1\n" + "mflo $a0" +  "sw $a0,"+to_string(temp->offset)+"\n"+ "li $a0,1\n";
					}
				}
				else
				{
					//var is offset of array
					// array's name is temp->name
					if(func_flag==1)
					{
						(yyval.Node)->code= (yyvsp[0].Node)->code + "move $t1,$a" + to_string(index) + "\n div $a0,$t1\n" + "mflo $a0" +  "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
					}
					else
					{
						long long int tmpoffset = temp->offset + var*4;
						(yyval.Node)->code= (yyvsp[0].Node)->code + "lw $t1," + to_string(tmpoffset)+ "\n div $a0,$t1\n" + "mflo $a0" +  "sw $a0,"+to_string(tmpoffset)+"\n"+ "li $a0,1\n";
					}
				}
			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<(yyvsp[0].Node)->eletype<<" can't be assigned to a "<<temp->eletype<<endl;
		}
	}
	else
	{
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Division by 0 not allowed"<<temp->eletype<<endl;	
	}
}
#line 3179 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1148 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[-1].Node)->eletype;
	int func_flag=0,index=0;
	int var=0;
	sym_tab_entry * temp= check_id_arr((yyvsp[-1].Node)->node_val,level,&var,&func_flag,&index,(yyvsp[-1].Node)->dimlist);
	if(temp!=NULL)
	{
		if(temp->eletype == "int" || temp->eletype == "float")
		{
			if(temp->eletype=="simple")
			{
				if(func_flag==1)
				{
					(yyval.Node)->code= "move $t1,$a" + to_string(index) + "\nsubi $a0,$t1,1 \n" + "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					(yyval.Node)->code= "lw $t1," + to_string(temp->offset)+ "\nsubi $a0,$t1,1 \n" + "sw $a0,"+to_string(temp->offset)+"\n"+ "li $a0,1\n";
				}
			}
			else
			{
				//var is offset of array
				// array's name is temp->name
				long long int tmpoffset = temp->offset + var*4;	
				if( func_flag==1)
				{
					(yyval.Node)->code= "move $t1,$a" + to_string(index) + "\n subi $a0,$t1,1 \n" + "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					(yyval.Node)->code= "lw $t1," + to_string(tmpoffset)+ "\n subi $a0, $t1,1 \n" + "sw $a0,"+to_string(tmpoffset)+"\n"+ "li $a0,1\n";
				}
			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"-- operation not supported for "<<temp->eletype<<endl;
		}
	}
}
#line 3226 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1191 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("assignexpr",(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[-1].Node)->eletype;
	int func_flag=0,index=0;
	int var=0;
	sym_tab_entry * temp= check_id_arr((yyvsp[-1].Node)->node_val,level,&var,&func_flag,&index,(yyvsp[-1].Node)->dimlist);
	if(temp!=NULL)
	{
		if(temp->eletype == "int" || temp->eletype == "float")
		{
			if(temp->eletype=="simple")
			{
				if(func_flag==1)
				{
					(yyval.Node)->code= "move $t1,$a" + to_string(index)+ "\n addi $a0, $t1,1 \n" + "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					(yyval.Node)->code= "lw $t1," + to_string(temp->offset)+ "\n addi $a0,$t1,1 \n" + "sw $a0,"+to_string(temp->offset)+"\n"+ "li $a0,1\n";
				}
			}
			else
			{
				//var is offset of array
				// array's name is temp->name
				long long int tmpoffset = temp->offset + var*4;	
				if(func_flag==1)
				{
					(yyval.Node)->code= "move $t1,$a" + to_string(index)+ "\n addi $a0, $t1,1 \n" + "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					(yyval.Node)->code= "lw $t1," + to_string(tmpoffset)+ "\n addi $a0, $t1,1 \n" + "sw $a0,"+to_string(tmpoffset)+"\n"+ "li $a0,1\n";
				}
			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"++ operation not supported for "<<temp->eletype<<endl;
		}
	}
}
#line 3273 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1237 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("arithexpr",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	if((yyvsp[-2].Node)->eletype == "int" && (yyvsp[0].Node)->eletype == "int")
	{
		(yyval.Node)->eletype=(yyvsp[-2].Node)->eletype;
		(yyval.Node)->node_val_num = (int)(yyvsp[-2].Node)->node_val_num & (int)(yyvsp[0].Node)->node_val_num;
		(yyval.Node)->code = (yyvsp[-2].Node)->code + "move $t1,$a0\n" + (yyvsp[0].Node)->code+ "move $t2,$a0\n" + "and $a0,$t1,$t2\n";
	}
	else
	{
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"bitwise and operation is allowed only for integers"<<endl;	
	}
}
#line 3291 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1251 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("arithexpr",(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
	(yyval.Node)->node_val_num = (yyvsp[0].Node)->node_val_num;
	(yyval.Node)->code = (yyvsp[0].Node)->code;

}
#line 3303 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1261 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr1",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	if((yyvsp[-2].Node)->eletype == "int" && (yyvsp[0].Node)->eletype == "int")
	{
		(yyval.Node)->eletype=(yyvsp[-2].Node)->eletype;
		(yyval.Node)->node_val_num = (int)(yyvsp[-2].Node)->node_val_num | (int)(yyvsp[0].Node)->node_val_num;
		(yyval.Node)->code = (yyvsp[-2].Node)->code + "move $t1,$a0\n" + (yyvsp[0].Node)->code+ "move $t2,$a0\n" + "or $a0,$t1,$t2\n";
	}
	else
	{
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"bitwise or operation is allowed only for integers"<<endl;	
	}
}
#line 3321 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1275 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr1",(yyvsp[0].Node));
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
	(yyval.Node)->node_val_num = (yyvsp[0].Node)->node_val_num;
	(yyval.Node)->code = (yyvsp[0].Node)->code;

}
#line 3333 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1285 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr2",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	cout<<(yyvsp[-2].Node)->eletype<<" "<<(yyvsp[0].Node)->eletype<<endl;
	if(compatible_arithop((yyvsp[-2].Node)->eletype,(yyvsp[0].Node)->eletype))
	{
		(yyval.Node)->node_val_num = (yyvsp[-2].Node)->node_val_num+(yyvsp[0].Node)->node_val_num;
		(yyval.Node)->eletype = compare_types((yyvsp[-2].Node)->eletype,(yyvsp[0].Node)->eletype);
		(yyval.Node)->code = (yyvsp[-2].Node)->code + "move $t1,$a0\n" + (yyvsp[0].Node)->code+ "move $t2,$a0\n" + "add $a0,$t1,$t2\n";
	}
	else
	{
		(yyval.Node)->eletype = "errortype";
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands are not compatible for addition"<<endl;	
	}
}
#line 3353 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1301 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr2",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	if(compatible_arithop((yyvsp[-2].Node)->eletype,(yyvsp[0].Node)->eletype))
	{
		(yyval.Node)->node_val_num = (yyvsp[-2].Node)->node_val_num-(yyvsp[0].Node)->node_val_num;
		(yyval.Node)->eletype = compare_types((yyvsp[-2].Node)->eletype,(yyvsp[0].Node)->eletype);
		(yyval.Node)->code = (yyvsp[-2].Node)->code + "move $t1,$a0\n" + (yyvsp[0].Node)->code+ "move $t2,$a0\n" + "sub $a0,$t1,$t2\n";
	}
	else
	{
		(yyval.Node)->eletype = "errortype";
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands are not compatible for subtraction"<<endl;	
	}
}
#line 3372 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1316 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr2",(yyvsp[0].Node));
	(yyval.Node)->node_val_num = (yyvsp[0].Node)->node_val_num;
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
	(yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 3383 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1324 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr3",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	if(compatible_arithop((yyvsp[-2].Node)->eletype,(yyvsp[0].Node)->eletype))
	{
		(yyval.Node)->node_val_num = (yyvsp[-2].Node)->node_val_num * (yyvsp[0].Node)->node_val_num;
		(yyval.Node)->eletype = compare_types((yyvsp[-2].Node)->eletype,(yyvsp[0].Node)->eletype);
		(yyval.Node)->code = (yyvsp[-2].Node)->code + "move $t1,$a0\n" + (yyvsp[0].Node)->code+ "move $t2,$a0\n" + "mult $t1,$t2\n" + "mflo $a0 \n";
	}
	else
	{
		(yyval.Node)->eletype = "errortype";
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands are not compatible for multiplication"<<endl;	
	}
}
#line 3402 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1339 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr3",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	if(compatible_arithop((yyvsp[-2].Node)->eletype,(yyvsp[0].Node)->eletype))
	{
		if((yyvsp[0].Node)->node_val_num != 0)
		{
			(yyval.Node)->node_val_num = (yyvsp[-2].Node)->node_val_num / (yyvsp[0].Node)->node_val_num;
			(yyval.Node)->eletype = compare_types((yyvsp[-2].Node)->eletype,(yyvsp[0].Node)->eletype);
			(yyval.Node)->code = (yyvsp[-2].Node)->code + "move $t1,$a0\n" + (yyvsp[0].Node)->code+ "move $t2,$a0\n" + "div $t1,$t2\n" + "mflo $a0 \n";
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Division by zero not allowed"<<endl;	
		}
	}
	else
	{
		(yyval.Node)->eletype = "errortype";
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands are not compatible for division"<<endl;	
	}
}
#line 3428 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1361 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr3",(yyvsp[0].Node));
	(yyval.Node)->node_val_num = (yyvsp[0].Node)->node_val_num;
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;

	(yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 3440 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1371 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr4",(yyvsp[-1].Node),(yyvsp[0].Node));
	if((yyvsp[0].Node)->eletype =="int")
	{
		(yyval.Node)->node_val_num = !(int)(yyvsp[0].Node)->node_val_num;
		(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
		(yyval.Node)->code = (yyvsp[-1].Node)->code + "not $t1,$a0\n" + "mov $a0,$t1\n";

	}
	else
	{
		(yyval.Node)->eletype = "errortype";
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"NOT operation is allowed only for integers"<<endl;	
	}
}
#line 3460 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1387 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("expr4",(yyvsp[0].Node));
	(yyval.Node)->node_val_num = (yyvsp[0].Node)->node_val_num;
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
	(yyval.Node)->code = (yyvsp[0].Node)->code;

}
#line 3472 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1397 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("factor",(yyvsp[0].Node));
	(yyval.Node)->node_val_num = (yyvsp[0].Node)->node_val_num;
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
	if((yyval.Node)->eletype == "int")
	{
	    (yyval.Node)->code = "li $a0,"+to_string((int)(yyvsp[0].Node)->node_val_num)+"\n";
	}
	else if((yyval.Node)->eletype == "float")
	{
	    (yyval.Node)->code = "li $a0,"+to_string((float)(yyvsp[0].Node)->node_val_num)+"\n";
	}

}
#line 3491 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1412 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("factor",(yyvsp[0].Node));
	(yyval.Node)->node_val_num = (yyvsp[0].Node)->node_val_num;
	(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
    (yyval.Node)->code = "li $a0,"+to_string((int)(yyvsp[0].Node)->node_val_num)+"\n";
}
#line 3502 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1419 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("factor",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3510 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1423 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("factor",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3518 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1427 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("factor",(yyvsp[0].Node));
	int var=0;
	int func_flag=0,index=0;
	sym_tab_entry * temp= check_id_arr((yyvsp[0].Node)->node_val,level,&var,&func_flag,&index,(yyvsp[0].Node)->dimlist);
	if(temp!=NULL)
	{
		(yyval.Node)->eletype = temp->eletype;
		if(temp->eletype=="simple")
		{
			if(func_flag=1)
			{
	            (yyval.Node)->code= "move $a0,$a" + to_string(index) +"\n";
			}
			else
			{
	            (yyval.Node)->code= "lw $a0,"+to_string(temp->offset)+"\n";
			}
		}
		else
		{
			if(var != -1)
			{
				int offset_of_array = temp->offset + 4*var;
				if(func_flag==1)
				{
	            	(yyval.Node)->code= "move $a0,$a" + to_string(index) + "\n";

				}
				else
				{
	            	(yyval.Node)->code= "lw $a0,"+to_string(offset_of_array)+"\n";
				}
			}
			else
			{
				//cout<<"Index required for calling arrays"<<endl;
			}
		}
	}
	
	else
	{
		(yyval.Node)->eletype = "errortype";
	}
}
#line 3569 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1474 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("factor",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->node_val_num = (yyvsp[-1].Node)->node_val_num;
	(yyval.Node)->eletype = (yyvsp[-1].Node)->eletype;
	(yyval.Node)->code = (yyvsp[-2].Node)->code;

}
#line 3581 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1482 "bisonfinal.y" /* yacc.c:1646  */
    {
		(yyval.Node) = add_new_node("factor",(yyvsp[0].Node));
		
		(yyval.Node)->eletype = (yyvsp[0].Node)->eletype;
		(yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 3592 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1491 "bisonfinal.y" /* yacc.c:1646  */
    {
 	(yyval.Node) = add_new_node("constructor",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3600 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1495 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("constructor",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3608 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1499 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("constructor",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3616 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1503 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("constructor",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3624 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1507 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("constructor",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3632 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1511 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("constructor",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3640 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1517 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3648 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1522 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("C",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3656 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1526 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("C");
}
#line 3664 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1532 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3672 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1537 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("D",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3680 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1541 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("D");
}
#line 3688 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1547 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("memory_parameter_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3696 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1553 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("E",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3704 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1557 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("E");
}
#line 3712 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1563 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3720 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1569 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("F",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3728 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1573 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("F");
}
#line 3736 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1579 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3744 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1584 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("G",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3752 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1588 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("G");
}
#line 3760 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1594 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("scheduler_parameter_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3768 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1599 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("Z",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3776 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1603 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("Z");
}
#line 3784 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1609 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3792 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1613 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3800 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1617 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3808 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1621 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3816 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1625 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3824 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1629 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3832 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1633 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter",(yyvsp[0].Node));
}
#line 3840 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1637 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("proc_parameter");
}
#line 3848 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1643 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("argument",(yyvsp[0].Node));
}
#line 3856 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1647 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("argument",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3864 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1652 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("valuearray",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3872 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1656 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("valuearray");
}
#line 3880 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1661 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("H",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3888 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1665 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("H");
}
#line 3896 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1672 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3904 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1676 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3912 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1680 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3920 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1684 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3928 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1688 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3936 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1692 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter",(yyvsp[0].Node));
}
#line 3944 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1696 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("link_parameter");
}
#line 3952 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1702 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("memory_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3960 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1706 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("memory_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 3968 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1710 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("memory_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));

}
#line 3977 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1715 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("memory_parameter",(yyvsp[0].Node));
}
#line 3985 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1719 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("memory_parameter");
}
#line 3993 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1725 "bisonfinal.y" /* yacc.c:1646  */
    {
	printf("JOB ID FOUND\n");
	(yyval.Node) = add_new_node("job_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4002 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1730 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4010 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1734 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4018 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1738 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4026 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1742 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4034 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1746 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter",(yyvsp[0].Node));
}
#line 4042 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1750 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("job_parameter");
}
#line 4050 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1756 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4058 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1760 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4066 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1764 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4074 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1768 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4082 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1772 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4090 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1776 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter",(yyvsp[0].Node));
}
#line 4098 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1780 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("cluster_parameter");
}
#line 4106 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1786 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("scheduler_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4114 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1790 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("scheduler_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4122 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1794 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("scheduler_parameter",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4130 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1798 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("scheduler_parameter",(yyvsp[0].Node));
}
#line 4138 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1802 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("scheduler_parameter");
}
#line 4146 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1808 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4154 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1812 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4162 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1816 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4170 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1820 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4178 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1824 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4186 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1828 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4194 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1832 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("function",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4202 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1837 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("func_arg_list",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4210 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1841 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("func_arg_list");
}
#line 4218 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1846 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("I",(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4226 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1850 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("func_arg_list");
}
#line 4234 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1856 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("value",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4242 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1860 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("value",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4250 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1864 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("value",(yyvsp[0].Node));
}
#line 4258 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1868 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("value",(yyvsp[0].Node));
}
#line 4266 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1875 "bisonfinal.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_new_node("semi",(yyvsp[0].Node));
}
#line 4274 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1879 "bisonfinal.y" /* yacc.c:1646  */
    {
	printf("Error: Missing ';' in line no %d\n", lineno);
	flag = 1;
	(yyval.Node) = NULL;
}
#line 4284 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1887 "bisonfinal.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_new_node("rp",(yyvsp[0].Node));
}
#line 4292 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1891 "bisonfinal.y" /* yacc.c:1646  */
    {
	printf("Error: Missing ')' in line no %d\n", lineno);
	flag = 1;
	(yyval.Node) = NULL;
}
#line 4302 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1899 "bisonfinal.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_new_node("rsp",(yyvsp[0].Node));
}
#line 4310 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1903 "bisonfinal.y" /* yacc.c:1646  */
    {
	printf("Error: Missing ']' in line no %d\n", lineno);
	flag = 1;
	(yyval.Node) = NULL;
}
#line 4320 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1910 "bisonfinal.y" /* yacc.c:1646  */
    { level=2; }
#line 4326 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1911 "bisonfinal.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_new_node("func_decl",(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    clear_sym_tab(2);
    level=0;

	if(active_function_ptr->rettype != "void")
	{
		int index = (yyvsp[-1].Node)->code.find("jr $ra");
		if (index==std::string::npos)
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"function is of returntype : "<< active_function_ptr->rettype << " but no return mentioned"<<endl;
		}
	}

    string temp_code;
    temp_code = "func_"+active_function_ptr->name+":\n";
    temp_code += (yyvsp[-1].Node)->code;
    temp_code += "jr $ra\n";
    active_function_ptr->code = temp_code;
    active_function_ptr = NULL;



}
#line 4355 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1937 "bisonfinal.y" /* yacc.c:1646  */
    { level=1; }
#line 4361 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1938 "bisonfinal.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_new_node("func_head",(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    active_function_ptr=search_func_tab((yyvsp[-4].Node)->node_val);
    if(active_function_ptr == NULL)
    {
		int m = 1;
		for(int i = 0; i < param_list.size(); i++)
		{
			string x = param_list[i].name;
			for(int j = i+1; j < param_list.size(); j++)
			{
				string y = param_list[j].name;
				if(x == y)
				{
					printf("Parameter redeclared\n");
					m = 0;
				}
			}
		}
		if(m == 1)
		{
		    func_tab_entry temp;
		    temp.name = (yyvsp[-4].Node)->node_val;
		    temp.rettype = (yyvsp[-4].Node)->eletype;
		    temp.paramlist = param_list;
		    param_list.clear();
		    func_tab.push_back(temp);
		    active_function_ptr=search_func_tab((yyvsp[-4].Node)->node_val);
		}
		print_func_table();
    }
    else
    {
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Function "<<(yyvsp[-4].Node)->node_val<<" already exists."<<endl;
    }
}
#line 4402 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1977 "bisonfinal.y" /* yacc.c:1646  */
    {
    (yyval.Node) = add_new_node("res_id",(yyvsp[-1].Node),(yyvsp[0].Node));
    (yyval.Node)->eletype = (yyvsp[-1].Node)->eletype;
    (yyval.Node)->node_val = (yyvsp[0].Node)->node_val;
}
#line 4412 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1986 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("decl_plist",(yyvsp[0].Node));
}
#line 4420 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1990 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("decl_plist");
}
#line 4428 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1996 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("decl_pl",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
}
#line 4436 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 2000 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("decl_pl",(yyvsp[0].Node));
}
#line 4444 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 2006 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("decl_param",(yyvsp[-1].Node),(yyvsp[0].Node));
	sym_tab_entry temp;
	temp.eletype = (yyvsp[-1].Node)->eletype;
	temp.type = "simple";
	temp.name = (yyvsp[0].Node)->node_val;
	param_list.push_back(temp);
}
#line 4457 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 2015 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("decl_param",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	sym_tab_entry temp;
	temp.eletype = (yyvsp[-3].Node)->eletype;
	temp.type = "arraytype";
	temp.name = (yyvsp[-2].Node)->node_val;
	temp.dimlist.push_back(999999);
	dim_list.clear();
	param_list.push_back(temp);
}
#line 4472 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 2028 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmtlist_body",(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->code = (yyvsp[-1].Node)->code + (yyvsp[0].Node)->code;
}
#line 4481 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 2033 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmtlist_body",(yyvsp[0].Node));
}
#line 4489 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 2038 "bisonfinal.y" /* yacc.c:1646  */
    { level++;}
#line 4495 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 2038 "bisonfinal.y" /* yacc.c:1646  */
    {clear_sym_tab(level); level--; }
#line 4501 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 2039 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt_body",(yyvsp[-9].Node),(yyvsp[-8].Node),(yyvsp[-7].Node),(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-3].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	
	(yyval.Node)->code = (yyvsp[-7].Node)->code + "li $t0,1" + "\n" + "blt	$a0,$t0," + "L_"+to_string(label)+"\n" + (yyvsp[-3].Node)->code;
	if(!noelseflag)
		(yyval.Node)->code =(yyval.Node)->code + "j L_" +to_string(label-1);
	(yyval.Node)->code =(yyval.Node)->code+"\nL_"+to_string(label)+":\n" + (yyvsp[0].Node)->code;
    label++;
}
#line 4515 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 2048 "bisonfinal.y" /* yacc.c:1646  */
    { level++; }
#line 4521 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 2049 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt_body",(yyvsp[-7].Node),(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	clear_sym_tab(level);
	level--;

	(yyval.Node)->code = "\nL_" + to_string(label)+":\n" + (yyvsp[-5].Node)->code +"li $t0,1\n";
    label++;

	int break_index = (yyvsp[-1].Node)->code.find("break");
	string break_replace = "j L_" + to_string(label)+"\n";

	if (break_index!=std::string::npos)
	     (yyvsp[-1].Node)->code.replace(break_index, break_replace.size()-1, break_replace);

	int continue_index = (yyvsp[-1].Node)->code.find("conti");
	string continue_replace = "j L_" + to_string(label-1)+"\n";

	if (continue_index!=std::string::npos)
	     (yyvsp[-1].Node)->code.replace(continue_index, continue_replace.size()-1, continue_replace);

    (yyval.Node)->code = (yyval.Node)->code + "blt $a0,$t0, " + "L_"+to_string(label)+"\n" + (yyvsp[-1].Node)->code+"j "+"L_"+to_string(label-1)+"\nL_"+to_string(label)+":\n";

    label++;
}
#line 4550 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 2073 "bisonfinal.y" /* yacc.c:1646  */
    { level++; }
#line 4556 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 2074 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt_body",(yyvsp[-11].Node),(yyvsp[-10].Node),(yyvsp[-9].Node),(yyvsp[-8].Node),(yyvsp[-7].Node),(yyvsp[-6].Node),(yyvsp[-5].Node),(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	clear_sym_tab(level);
	level--;

	(yyval.Node)->code = (yyvsp[-9].Node)->code+"\nL_"+to_string(label)+":"+(yyvsp[-7].Node)->code+ "li $t0,1" + "\n" + "blt $a0,$t0," + "L_"+to_string(label+1)+"\n";

	int index = (yyvsp[-1].Node)->code.find("break");

	string break_replace = "j L_" + to_string(label+1)+"\n";
	if (index!=std::string::npos)
	     (yyvsp[-1].Node)->code.replace(index, break_replace.size()-1, break_replace);

	int continue_index = (yyvsp[-1].Node)->code.find("conti");
	string continue_replace = "j L_" + to_string(label)+"\n";

	if (continue_index!=std::string::npos)
	     (yyvsp[-1].Node)->code.replace(continue_index, continue_replace.size()-1, continue_replace);


	(yyval.Node)->code = (yyval.Node)->code + (yyvsp[-5].Node)->code+ (yyvsp[-1].Node)->code+"\nj L_" + to_string(label) + "\nL_" + to_string(label+1) + ":\n";

	label++;
	label++;
}
#line 4586 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 2100 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt_body",(yyvsp[-4].Node),(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->code = (yyvsp[-2].Node)->code+"\n"+ "sw $a0,268501992\n" + (yyvsp[0].Node)->code;
}
#line 4595 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 2105 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt_body",(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->code = (yyvsp[-1].Node)->code;
}
#line 4604 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 2110 "bisonfinal.y" /* yacc.c:1646  */
    {
	(yyval.Node) = add_new_node("stmt_body",(yyvsp[-1].Node),(yyvsp[0].Node));
	(yyval.Node)->code = (yyvsp[-1].Node)->code;
}
#line 4613 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 2115 "bisonfinal.y" /* yacc.c:1646  */
    {
		(yyval.Node) = add_new_node("stmt_body",(yyvsp[0].Node));
	    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 4622 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 2120 "bisonfinal.y" /* yacc.c:1646  */
    {
		(yyval.Node) = add_new_node("stmt_body",(yyvsp[0].Node));
	    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 4631 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 2125 "bisonfinal.y" /* yacc.c:1646  */
    {
		(yyval.Node) = add_new_node("stmt_body",(yyvsp[0].Node));
	    (yyval.Node)->code = (yyvsp[0].Node)->code;
}
#line 4640 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 2134 "bisonfinal.y" /* yacc.c:1646  */
    {
		(yyval.Node) = add_new_node("func_call",(yyvsp[-3].Node),(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
		
		func_tab_entry* call_name_ptr = search_func_tab((yyvsp[-3].Node)->node_val);

		if(call_name_ptr != NULL)
		{	
			if(call_name_ptr->paramlist.size() == (yyvsp[-1].Node)->paramlist.size())
			{
				int m = 1;

				for(int i = 0; i < (yyvsp[-1].Node)->paramlist.size(); i++)
				{
					if((yyvsp[-1].Node)->paramlist[i] != call_name_ptr->paramlist[i].eletype)
					{
						m = 0;
					}
				}
				if(m == 1)
				{
            		(yyval.Node)->code = (yyvsp[-1].Node)->code + "jal func_" + call_name_ptr->name+"\n";
            		
            		(yyval.Node)->eletype = call_name_ptr->rettype;
				}
				else
				{
					cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Parameter Type Mismatch"<<endl;
					
					(yyval.Node)->eletype = "errortype";
				}
			}
			else
			{
				
				(yyval.Node)->eletype = "errortype";
				cout<<"ERROR IN LINENO : "<<lineno<<"Number of Parameters mismatch\n"<<endl;
			}
		}
		else
		{
			
			(yyval.Node)->eletype = "errortype";
			cout<<"ERROR IN LINENO : "<<lineno<<"Function "<<(yyvsp[-3].Node)->node_val<<" not found"<<endl;
		}
}
#line 4690 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 2182 "bisonfinal.y" /* yacc.c:1646  */
    {
		(yyval.Node) = add_new_node("paramlist",(yyvsp[0].Node));
    	(yyval.Node)->code = (yyvsp[0].Node)->code;
    	(yyval.Node)->paramlist = ((yyvsp[0].Node)->paramlist);
}
#line 4700 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 2188 "bisonfinal.y" /* yacc.c:1646  */
    {
		(yyval.Node) = add_new_node("paramlist");
}
#line 4708 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 2194 "bisonfinal.y" /* yacc.c:1646  */
    {
		(yyval.Node) = add_new_node("plist",(yyvsp[-2].Node),(yyvsp[-1].Node),(yyvsp[0].Node));
    	(yyval.Node)->index =(yyvsp[-2].Node)->index + 1;
		((yyval.Node)->paramlist).insert(((yyval.Node)->paramlist).end(), ((yyvsp[-2].Node)->paramlist).begin(), ((yyvsp[-2].Node)->paramlist).end());
		((yyval.Node)->paramlist).push_back((yyvsp[0].Node)->eletype);
		string temp_code = (yyvsp[0].Node)->code + "move $a" + to_string((yyval.Node)->index) + ", $a0\n";
    	(yyval.Node)->code = temp_code + (yyvsp[-2].Node)->code;
}
#line 4721 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 2203 "bisonfinal.y" /* yacc.c:1646  */
    {
		(yyval.Node) = add_new_node("plist",(yyvsp[0].Node));
    	(yyval.Node)->index =0;
		((yyval.Node)->paramlist).push_back((yyvsp[0].Node)->eletype);
    	(yyval.Node)->code = (yyvsp[0].Node)->code + "move $a" + to_string((yyval.Node)->index) + ", $a0\n";
}
#line 4732 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 2212 "bisonfinal.y" /* yacc.c:1646  */
    {
    (yyval.Node) = NULL;
}
#line 4740 "bisonfinal.tab.c" /* yacc.c:1646  */
    break;


#line 4744 "bisonfinal.tab.c" /* yacc.c:1646  */
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
#line 2219 "bisonfinal.y" /* yacc.c:1906  */

int main()
{
    yyparse();
}








