#define EOI   0 
#define SEMI  1 
#define PLUS  2 
#define MINUS   3 
#define TIMES 4 
#define DIVIDE   5 
#define LP    6 
#define RP    7 
#define NUM 8 
#define GT  9 
#define LT  10  
#define IF  11  
#define THEN 12
#define WHILE 13
#define DO  14
#define BEGIN 15
#define END 16
#define EQ  17
#define EQCOMP  18
#define ID 19 
#define ENTER 20 

#define COL 21
#define IFZ 22
#define GOTO 23
#define TEMPID 24
#define LABELID 25

extern char * yytext;
extern int yyleng;
extern int yylineno;


int lex();
int match(int);
void advance(void);
