/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 22 "bisonfinal.y" /* yacc.c:1909  */

	node *Node;

#line 144 "bisonfinal.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISONFINAL_TAB_H_INCLUDED  */
