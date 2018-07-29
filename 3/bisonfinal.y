%{
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
%}

%union{
	node *Node;
}


%token <Node> IF ELSE WHILE FOR SWITCH CASE DEFAULT LP RP LCP RCP LSP RSP SEMI COLON LT GT EQ PLUS MINUS MULTIPLY DIVIDE BITOR BITAND NOT ID NUM DOT COMMA PROCESSOR LINK  MEMORY JOB CLUSTER ISA CLOCK_SPEED L1_MEMORY L2_MEMORY NAME START_POINT END_POINT BANDWIDTH CHANNEL_CAPACITY MEMORY_TYPE MEM_SIZE JOB_ID FLOPS_REQUIRED DEADLINE MEM_REQUIRED PROCESSORS TOPOLOGY LINK_BANDWIDTH LINK_CAPACITY IS_RUNNING SUBMIT_JOBS OR AND PLUSEQ MINUSEQ MULTIPLYEQ DIVIDEEQ MINUSMINUS PLUSPLUS GET_CLOCK_SPEED RUN DISCARD_JOB GET_AVAILABLE_MEMORY GET_MEMORY ELSEIF AFFINITY EQEQ DQUOTE SQUOTE ARCHITECTURE_TYPE WAIT SCHEDULER JOB_ARRAY PROCESSOR_ARRAY SET_JOB_AFFINITY MAX_JOBS GET_LOAD SET_ALGO 


%type <Node> stmtlist stmt elsestmt exprc A switchstmt exprfor expression init mathexpr assignexpr arithexpr expr1 expr2 expr3 expr4 factor constructor proc_parameter_list C link_parameter_list D memory_parameter_list E job_parameter_list F cluster_parameter_list G proc_parameter argument valuearray H link_parameter memory_parameter job_parameter cluster_parameter function func_arg_list I value grammar_start scheduler_parameter_list scheduler_parameter Z semi rp rsp


%token <Node>	INTEGER_LITERAL

%start	grammar_start


%%
grammar_start : stmtlist
{
	$$ = add_new_node("grammar_start",$1);
	if(flag==0){
		printf("Compilation successful.\n");
		ofstream output;
		output.open("parsetree.txt");
		print_nodes($$,output);	
		//print_nodes_node_num($$,output);
		output.close();	
	}
	else{
		printf("Error encountered\n");
	}
}
	;

stmtlist : stmt stmtlist
{
	$$ = add_new_node("stmtlist",$1,$2);
}
		|
{
	$$ = add_new_node("stmtlist");	
}
		; 
stmt  : IF  LP exprc rp  LCP  stmtlist  RCP elsestmt
{
	$$ = add_new_node("stmt",$1,$2,$3,$4,$5,$6,$7,$8);			
}
		| WHILE  LP exprc rp  LCP stmtlist RCP 
{
	$$ = add_new_node("stmt",$1,$2,$3,$4,$5,$6,$7);	
}
		| FOR  LP exprfor rp  LCP stmtlist RCP 
{
	$$ = add_new_node("stmt",$1,$2,$3,$4,$5,$6,$7);	
}
		| SWITCH LP arithexpr rp switchstmt
{
	$$ = add_new_node("stmt",$1,$2,$3,$4,$5);	
}
		| expression semi
{
	$$ = add_new_node("stmt",$1,$2);	
}
		;
elsestmt  : ELSEIF  LP exprc rp  LCP stmtlist  RCP  elsestmt
{
	$$ = add_new_node("elsestmt",$1,$2,$3,$4,$5,$6,$7);	
}
			| ELSE  LCP stmtlist RCP  
{
	$$ = add_new_node("elsestmt",$1,$2,$3,$4);	
}
			| 
{
	$$ = add_new_node("elsestmt");	
}
			;
exprc : exprc OR expression A
{
	$$ = add_new_node("exprc",$1,$2,$3,$4);	
}
	| exprc AND expression A
{
	$$ = add_new_node("exprc",$1,$2,$3,$4);	
}
	| expression A
{
	$$ = add_new_node("exprc",$1,$2);	
}
	;
A :   LT expression
{
	$$ = add_new_node("A",$1,$2);	
}
	| GT expression
{
	$$ = add_new_node("A",$1,$2);	
}
	| EQEQ expression
{
	$$ = add_new_node("A",$1,$2);	
}
	| GT EQ expression
{
	$$ = add_new_node("A",$1,$2,$3);	
}
	| LT EQ expression
{
	$$ = add_new_node("A",$1,$2,$3);	
}
	|
{
	$$ = add_new_node("A");	
}
	; 

switchstmt  : CASE  LP arithexpr rp  LCP stmtlist  RCP  switchstmt
{
	$$ = add_new_node("switchstmt",$1,$2,$3,$4,$5,$6,$7,$8);	
}
			| DEFAULT  LCP stmtlist RCP  
{
	$$ = add_new_node("switchstmt",$1,$2,$3,$4);	
}
			| 
{
	$$ = add_new_node("switchstmt");	
}
			;
exprfor: expression semi exprc semi expression 
{
	$$ = add_new_node("exprfor",$1,$2,$3,$4,$5);	
}
		;
expression:  RUN LP func_arg_list rp
{
	$$ = add_new_node("expression",$1,$2,$3,$4);	
}
	| SET_JOB_AFFINITY LP func_arg_list rp
{
	$$ = add_new_node("expression",$1,$2,$3,$4);	
}
	|	SET_ALGO LP func_arg_list rp
{
	$$ = add_new_node("expression",$1,$2,$3,$4);	
}
	| DISCARD_JOB LP func_arg_list rp
{
	$$ = add_new_node("expression",$1,$2,$3,$4);	
}
	|	WAIT LP func_arg_list rp
{
	$$ = add_new_node("expression",$1,$2,$3,$4);	
}
	| init 
{
	$$ = add_new_node("expression",$1);	
}
	| mathexpr
{
	$$ = add_new_node("expression",$1);	
}
	;
init : ID EQ constructor init
{
	$$ = add_new_node("init",$1,$2,$3,$4);	
}
	   |
{
	$$ = add_new_node("init");	
}
	   ;
mathexpr : assignexpr
{
	$$ = add_new_node("mathexpr",$1);	
}
		   | arithexpr
{
	$$ = add_new_node("mathexpr",$1);	
}
		   ;
assignexpr : ID EQ mathexpr 	
{
	$$ = add_new_node("assignexpr",$1,$2,$3);	
}
			| ID PLUSEQ mathexpr 
{
	$$ = add_new_node("assignexpr",$1,$2,$3);	
}
			| ID MINUSEQ mathexpr 	
{
	$$ = add_new_node("assignexpr",$1,$2,$3);	
}
			| ID MULTIPLYEQ mathexpr 
{
	$$ = add_new_node("assignexpr",$1,$2,$3);	
}
			| ID DIVIDEEQ mathexpr 	
{
	$$ = add_new_node("assignexpr",$1,$2,$3);	
}
			| ID MINUSMINUS 
{
	$$ = add_new_node("assignexpr",$1,$2);	
}
			| ID PLUSPLUS
{
	$$ = add_new_node("assignexpr",$1,$2);	
}
			;


arithexpr :expr1 BITAND arithexpr 
{
	$$ = add_new_node("arithexpr",$1,$2,$3);	
}
			| expr1
{
	$$ = add_new_node("arithexpr",$1);	
}
			;

expr1 : expr2 BITOR expr1
{
	$$ = add_new_node("expr1",$1,$2,$3);
}
		| expr2
{
	$$ = add_new_node("expr1",$1);
}
		;

expr2: expr2 PLUS expr3
{	
	$$ = add_new_node("expr2",$1,$2,$3);
}
	| expr2 MINUS expr3 
{
	$$ = add_new_node("expr2",$1,$2,$3);
}
	| expr3 
{
	$$ = add_new_node("expr2",$1);
}	
	;
expr3: 	expr3 MULTIPLY expr4
{
	$$ = add_new_node("expr3",$1,$2,$3);
}
		| expr3 DIVIDE expr4
{
	$$ = add_new_node("expr3",$1,$2,$3);
}
		| expr4
{
	$$ = add_new_node("expr3",$1);
}
	   ;

expr4 : NOT factor 
{
	$$ = add_new_node("expr4",$1,$2);
}
		| factor
{
	$$ = add_new_node("expr4",$1);
}
		;
factor : NUM
{
	$$ = add_new_node("factor",$1);
} 
		| ID DOT function
{
	$$ = add_new_node("factor",$1,$2,$3);	
}
	| constructor DOT function
{
	$$ = add_new_node("factor",$1,$2,$3);	
}	
		| ID
{
	$$ = add_new_node("factor",$1);
}
		| LP arithexpr rp
{
	$$ = add_new_node("factor",$1,$2,$3);
}
		;

constructor : PROCESSOR LP proc_parameter_list rp
{
 	$$ = add_new_node("constructor",$1,$2,$3,$4);
}
			| LINK LP link_parameter_list rp
{
	$$ = add_new_node("constructor",$1,$2,$3,$4);
}
			| MEMORY LP memory_parameter_list rp
{
	$$ = add_new_node("constructor",$1,$2,$3,$4);
}
			| JOB LP job_parameter_list rp
{
	$$ = add_new_node("constructor",$1,$2,$3,$4);
}
			| CLUSTER LP cluster_parameter_list rp
{
	$$ = add_new_node("constructor",$1,$2,$3,$4);
}						
			| SCHEDULER LP scheduler_parameter_list rp
{
	$$ = add_new_node("constructor",$1,$2,$3,$4);
}
			;

proc_parameter_list : proc_parameter C 
{
	$$ = add_new_node("proc_parameter_list",$1,$2);
}
	;
C : COMMA proc_parameter_list 
{
	$$ = add_new_node("C",$1,$2);
}
	| 
{
	$$ = add_new_node("C");
}
	;

link_parameter_list : link_parameter D 
{
	$$ = add_new_node("link_parameter_list",$1,$2);
}
	;
D : COMMA link_parameter_list 
{
	$$ = add_new_node("D",$1,$2);
}
	| 
{
	$$ = add_new_node("D");
}
	;

memory_parameter_list : memory_parameter E 
{
	$$ = add_new_node("memory_parameter_list",$1,$2);
}
	;

E : COMMA memory_parameter_list 
{
	$$ = add_new_node("E",$1,$2);
}
	| 
{
	$$ = add_new_node("E");
}
	;

job_parameter_list : job_parameter F 
{
	$$ = add_new_node("job_parameter_list",$1,$2);
}
	;

F : COMMA job_parameter_list 
{
	$$ = add_new_node("F",$1,$2);
}
	| 
{
	$$ = add_new_node("F");
}
	;

cluster_parameter_list : cluster_parameter G 
{
	$$ = add_new_node("cluster_parameter_list",$1,$2);
}
	;
G : COMMA cluster_parameter_list 
{
	$$ = add_new_node("G",$1,$2);
}
	| 
{
	$$ = add_new_node("G");
}
	;

scheduler_parameter_list : scheduler_parameter Z 
{
	$$ = add_new_node("scheduler_parameter_list",$1,$2);
}
	;
Z : COMMA scheduler_parameter_list 
{
	$$ = add_new_node("Z",$1,$2);
}
	| 
{
	$$ = add_new_node("Z");
}
	;

proc_parameter: ARCHITECTURE_TYPE EQ value
{
	$$ = add_new_node("proc_parameter",$1,$2,$3);
}
			| ISA EQ value
{
	$$ = add_new_node("proc_parameter",$1,$2,$3);
}
				| CLOCK_SPEED EQ value
{
	$$ = add_new_node("proc_parameter",$1,$2,$3);
}
				| L1_MEMORY EQ value
{
	$$ = add_new_node("proc_parameter",$1,$2,$3);
}
				| L2_MEMORY EQ value
{
	$$ = add_new_node("proc_parameter",$1,$2,$3);
}
				| NAME EQ value
{
	$$ = add_new_node("proc_parameter",$1,$2,$3);
}
				| argument
{
	$$ = add_new_node("proc_parameter",$1);
}
		| 
{
	$$ = add_new_node("proc_parameter");
}
	;

argument : value 
{
	$$ = add_new_node("argument",$1);
}
		| LSP valuearray rsp
{
	$$ = add_new_node("argument",$1,$2,$3);
}
	;
valuearray : value H 
{
	$$ = add_new_node("valuearray",$1,$2);
}
			| 
{
	$$ = add_new_node("valuearray");
}
			;
H : COMMA valuearray 
{
	$$ = add_new_node("H",$1,$2);
}
	|
{
	$$ = add_new_node("H");
}
	;


link_parameter: START_POINT EQ value
{
	$$ = add_new_node("link_parameter",$1,$2,$3);
}
		| END_POINT EQ value
{
	$$ = add_new_node("link_parameter",$1,$2,$3);
}
		| BANDWIDTH EQ value
{
	$$ = add_new_node("link_parameter",$1,$2,$3);
}
		| CHANNEL_CAPACITY EQ value
{
	$$ = add_new_node("link_parameter",$1,$2,$3);
}
		| NAME EQ value
{
	$$ = add_new_node("link_parameter",$1,$2,$3);
}
		| value
{
	$$ = add_new_node("link_parameter",$1);
}
		| 
{
	$$ = add_new_node("link_parameter");
}
	;

memory_parameter: MEMORY_TYPE EQ value
{
	$$ = add_new_node("memory_parameter",$1,$2,$3);
}
		| MEM_SIZE EQ value
{
	$$ = add_new_node("memory_parameter",$1,$2,$3);
}
		| NAME EQ value
{
	$$ = add_new_node("memory_parameter",$1,$2,$3);

}
		| value
{
	$$ = add_new_node("memory_parameter",$1);
}
		| 
{
	$$ = add_new_node("memory_parameter");
}
	;

job_parameter : JOB_ID EQ value
{	
	printf("JOB ID FOUND\n");
	$$ = add_new_node("job_parameter",$1,$2,$3);
}
		| FLOPS_REQUIRED EQ value
{
	$$ = add_new_node("job_parameter",$1,$2,$3);
}
		| DEADLINE EQ value
{
	$$ = add_new_node("job_parameter",$1,$2,$3);
}
		| MEM_REQUIRED EQ value
{
	$$ = add_new_node("job_parameter",$1,$2,$3);
}
		| AFFINITY EQ argument
{
	$$ = add_new_node("job_parameter",$1,$2,$3);
}
		| argument
{
	$$ = add_new_node("job_parameter",$1);
}
		| 
{
	$$ = add_new_node("job_parameter");
}	
	;

cluster_parameter: PROCESSORS EQ argument
{
	$$ = add_new_node("cluster_parameter",$1,$2,$3);
}
		| TOPOLOGY EQ value
{
	$$ = add_new_node("cluster_parameter",$1,$2,$3);
}
		| LINK_BANDWIDTH EQ value
{
	$$ = add_new_node("cluster_parameter",$1,$2,$3);
}		
		| LINK_CAPACITY EQ value
{
	$$ = add_new_node("cluster_parameter",$1,$2,$3);
}		
		| NAME EQ value 
{
	$$ = add_new_node("cluster_parameter",$1,$2,$3);
}
		| argument 
{
	$$ = add_new_node("cluster_parameter",$1);
}
		| 
{
	$$ = add_new_node("cluster_parameter");
}
	;

scheduler_parameter: CLUSTER EQ value
{
	$$ = add_new_node("scheduler_parameter",$1,$2,$3);
}
		| JOB_ARRAY EQ argument
{
	$$ = add_new_node("scheduler_parameter",$1,$2,$3);
}
		| PROCESSOR_ARRAY EQ argument
{
	$$ = add_new_node("scheduler_parameter",$1,$2,$3);
}		
		| argument 
{
	$$ = add_new_node("scheduler_parameter",$1);
}
		| 
{
	$$ = add_new_node("scheduler_parameter");
}
	;

function : IS_RUNNING LP  func_arg_list  rp
{
	$$ = add_new_node("function",$1,$2,$3,$4);
}
		| SUBMIT_JOBS LP func_arg_list rp
{
	$$ = add_new_node("function",$1,$2,$3,$4);
}
		| GET_CLOCK_SPEED LP func_arg_list rp
{
	$$ = add_new_node("function",$1,$2,$3,$4);
}
		| GET_AVAILABLE_MEMORY LP func_arg_list rp
{
	$$ = add_new_node("function",$1,$2,$3,$4);
}
		| GET_MEMORY LP func_arg_list rp
{
	$$ = add_new_node("function",$1,$2,$3,$4);
}
	| GET_LOAD LP func_arg_list rp
{
	$$ = add_new_node("function",$1,$2,$3,$4);
}
		| MAX_JOBS LP func_arg_list rp
{
	$$ = add_new_node("function",$1,$2,$3,$4);
};

func_arg_list :argument I 
{
	$$ = add_new_node("func_arg_list",$1,$2);
}
				| 
{
	$$ = add_new_node("func_arg_list");
}
				;
I : COMMA func_arg_list 
{
	$$ = add_new_node("I",$1,$2);
}
	| 
{
	$$ = add_new_node("func_arg_list");
}
	;

value : SQUOTE ID SQUOTE
{
	$$ = add_new_node("value",$1,$2,$3);
}
	| DQUOTE ID DQUOTE
{
	$$ = add_new_node("value",$1,$2,$3);
}
	| arithexpr
{
	$$ = add_new_node("value",$1);
}
	    | constructor
{
	$$ = add_new_node("value",$1);
}
	    ;


semi               : SEMI
{
    $$ = add_new_node("semi",$1);
}
                | error 
{
	printf("Error: Missing ';' in line no %d\n", lineno); 
	flag = 1; 
	$$ = NULL;
}
		;

rp               : RP
{
    $$ = add_new_node("rp",$1);
}
                | error 
{
	printf("Error: Missing ')' in line no %d\n", lineno); 
	flag = 1; 
	$$ = NULL;
}
		;

rsp               : RSP
{
    $$ = add_new_node("rsp",$1);
}
                | error 
{
	printf("Error: Missing ']' in line no %d\n", lineno); 
	flag = 1; 
	$$ = NULL;
}
		;



%%
int main()
{
    yyparse();
}
 