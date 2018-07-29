%{
	#include "heading.h"
	#include "lexfinal.h"
%}

%%
"if" { printf("Found %s\n", yytext); return IF;}
"else"  { printf("Found %s\n", yytext); return ELSE; }
"elseif" { printf("Found %s\n", yytext); return ELSEIF; }
"while" { printf("Found %s\n", yytext); return WHILE; }
"for" { printf("Found %s\n", yytext); return FOR; }
"switch" { printf("Found %s\n", yytext); return SWITCH;}
"case" { printf("Found %s\n", yytext); return CASE;}
"default" { printf("Found %s\n", yytext); return DEFAULT;}

"(" { printf("Found %s\n", yytext); return LP ;}
"{" { printf("Found %s\n", yytext); return LCP; }
"[" { printf("Found %s\n", yytext); return LSP;}
")" { printf("Found %s\n", yytext); return RP ;}
"}" { printf("Found %s\n", yytext); return RCP;}
"]" { printf("Found %s\n", yytext); return RSP; }
";" { printf("Found %s\n", yytext); return SEMI;}
"," { printf("Found %s\n", yytext); return COMMA ;}
"." { printf("Found %s\n", yytext); return DOT ;}
"<" { printf("Found %s\n", yytext); return LT ;}
">" { printf("Found %s\n", yytext); return GT ;}
"=" { printf("Found %s\n", yytext); return EQ;}
":" { printf("Found %s\n", yytext); return COLON ;}
"==" { printf("Found %s\n", yytext); return EQEQ; }
"+=" { printf("Found %s\n", yytext); return PLUSEQ; }
"-=" { printf("Found %s\n", yytext); return MINUSEQ;}
"*=" { printf("Found %s\n", yytext); return MULTIPLYEQ;}
"/=" { printf("Found %s\n", yytext); return DIVIDEEQ;}
"++" { printf("Found %s\n", yytext); return PLUSPLUS;}
"--" { printf("Found %s\n", yytext); return MINUSMINUS;}
"||" { printf("Found %s\n", yytext); return OR;}
"&&" { printf("Found %s\n", yytext); return AND;}

"|" { printf("Found %s\n", yytext); return BITOR; }
"&" { printf("Found %s\n", yytext); return BITAND; }
"!"|"not" { printf("Found %s\n", yytext); return NOT ;}
"+" { printf("Found %s\n", yytext); return PLUS ;}
"-" { printf("Found %s\n", yytext); return MINUS ;}
"*" { printf("Found %s\n", yytext); return MULTIPLY; }
"/" { printf("Found %s\n", yytext); return DIVIDE ;}
"\"" { printf("Found %s\n", yytext); return DQUOTE; }
"\'" { printf("Found %s\n", yytext); return SQUOTE; }


"Processor" { printf("Found %s\n", yytext); return PROCESSOR; }
"isa" { printf("Found %s\n", yytext); return ISA;}
"clock_speed" { printf("Found %s\n", yytext); return CLOCK_SPEED; }
"l1_memory" { printf("Found %s\n", yytext); return L1_MEMORY ;}
"l2_memory" { printf("Found %s\n", yytext); return L2_MEMORY ;}
"name" { printf("Found %s\n", yytext); return NAME ;}

"is_running" { printf("Found %s\n", yytext); return IS_RUNNING ;}
"submit_jobs" { printf("Found %s\n", yytext); return SUBMIT_JOBS; }
"get_clock_speed" { printf("Found %s\n", yytext); return GET_CLOCK_SPEED ; }
"run" { printf("Found %s\n", yytext); return RUN ;}
"discard_job" { printf("Found %s\n", yytext); return DISCARD_JOB ;}


"Link" { printf("Found %s\n", yytext); return LINK ;}
"start_point" { printf("Found %s\n", yytext); return START_POINT ; }
"end_point" { printf("Found %s\n", yytext); return END_POINT ;}
"bandwidth" { printf("Found %s\n", yytext); return BANDWIDTH ;}
"channel_capacity" { printf("Found %s\n", yytext); return CHANNEL_CAPACITY ;}


"Memory" { printf("Found %s\n", yytext); return MEMORY ;}
"memory_type" { printf("Found %s\n", yytext); return MEMORY_TYPE ;}
"mem_size" { printf("Found %s\n", yytext); return MEM_SIZE ; }
"get_available_memory" { printf("Found %s\n", yytext); return GET_AVAILABLE_MEMORY ;}

"Job" { printf("Found %s\n", yytext); return JOB ;}
"job_id" { printf("Found %s\n", yytext); return JOB_ID ; }
"flops_required" { printf("Found %s\n", yytext); return FLOPS_REQUIRED ; }
"deadline" { printf("Found %s\n", yytext); return DEADLINE ;}
"mem_required" { printf("Found %s\n", yytext); return MEM_REQUIRED ;}
"affinity" { printf("Found %s\n", yytext); return AFFINITY ;}
"get_memory" { printf("Found %s\n", yytext); return GET_MEMORY ; }

"Cluster" { printf("Found %s\n", yytext); return CLUSTER ;}
"processors" { printf("Found %s\n", yytext); return PROCESSORS ; }
"topology" { printf("Found %s\n", yytext); return TOPOLOGY ;}
"link_bandwidth" { printf("Found %s\n", yytext); return LINK_BANDWIDTH ;}
"link_capacity" { printf("Found %s\n", yytext); return LINK_CAPACITY ;}

([0-9]*[.])?[0-9]+ { printf("Found %s\n", yytext); return NUM; }

[a-zA-Z_][a-zA-Z0-9_]*("["(([1-9][0-9]*)|([a-zA-Z_][a-zA-Z0-9_]*))"]")* { printf("Found ID %s\n", yytext); return ID ; }

[ \t]*  {}
[\n]		{ yylineno++;	}

.  {printf("unexpected error\n");}

%%

int main(void)
{
    while(1)
    {	
 	   yylex();
	}
}
int yyerror(void)
{
    printf("Error\n");
    exit(1);
}

