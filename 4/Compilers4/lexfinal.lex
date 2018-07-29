%{
	#include "utility2.cpp"
	#include "bisonfinal.tab.h"
	using namespace std;
	void yyerror(char *s);
	extern "C" int yywrap() { }
	int lineno = 1;
%}

%option yylineno


%%
"char" { yylval.Node = add_leaf("CHAR","char"); printf("Found %s\n", yytext); return CHAR;}
"int" { yylval.Node = add_leaf("INT","int"); printf("Found %s\n", yytext); return INT;}
"float" { yylval.Node = add_leaf("FLOAT","float"); printf("Found %s\n", yytext); return FLOAT;}
"void" { yylval.Node = add_leaf("VOID","void"); printf("Found %s\n", yytext); return VOID;}
"break" { yylval.Node = add_leaf("BREAK","break"); printf("Found %s\n", yytext); return BREAK;}
"continue" { yylval.Node = add_leaf("CONTINUE","continue"); printf("Found %s\n",yytext); return CONTINUE;}
"return" { yylval.Node = add_leaf("RETURN","return"); printf("Found %s\n", yytext); return RETURN;}
"if" { yylval.Node = add_leaf("IF","if"); printf("Found %s\n", yytext); return IF;}
"else"  { yylval.Node = add_leaf("ELSE","else"); printf("Found %s\n", yytext); return ELSE; }
"elseif" { yylval.Node = add_leaf("ELSEIF","elseif"); printf("Found %s\n", yytext); return ELSEIF; }
"while" { yylval.Node = add_leaf("WHILE","while"); printf("Found %s\n", yytext); return WHILE; }
"for" { yylval.Node = add_leaf("FOR","for"); printf("Found %s\n", yytext); return FOR; }
"switch" { yylval.Node = add_leaf("SWITCH","switch"); printf("Found %s\n", yytext); return SWITCH;}
"case" { yylval.Node = add_leaf("CASE","case"); printf("Found %s\n", yytext); return CASE;}
"default" { yylval.Node = add_leaf("DEFAULT","default"); printf("Found %s\n", yytext); return DEFAULT;}
"(" { yylval.Node = add_leaf("LP","("); printf("Found %s\n", yytext); return LP ;}
"{" { yylval.Node = add_leaf("LCP", "{"); printf("Found %s\n", yytext); return LCP; }
"[" { yylval.Node = add_leaf("LSP", "["); printf("Found %s\n", yytext); return LSP;}
")" { yylval.Node = add_leaf("RP",")"); printf("Found %s\n", yytext); return RP ;}
"}" { yylval.Node = add_leaf("RCP","}"); printf("Found %s\n", yytext); return RCP;}
"]" { yylval.Node = add_leaf("RSP","]"); printf("Found %s\n", yytext); return RSP; }
";" { yylval.Node = add_leaf("SEMI",";"); printf("Found %s\n", yytext); return SEMI;}
"," { yylval.Node = add_leaf("COMMA",","); printf("Found %s\n", yytext); return COMMA ;}
"." { yylval.Node = add_leaf("DOT","."); printf("Found %s\n", yytext); return DOT ;}
"<" { yylval.Node = add_leaf("LT","<"); printf("Found %s\n", yytext); return LT ;}
">" { yylval.Node = add_leaf("GT",">"); printf("Found %s\n", yytext); return GT ;}
"=" { yylval.Node = add_leaf("EQ","="); printf("Found %s\n", yytext); return EQ;}
":" { yylval.Node = add_leaf("COLON",":"); printf("Found %s\n", yytext); return COLON ;}
"==" { yylval.Node = add_leaf("EQEQ","=="); printf("Found %s\n", yytext); return EQEQ; }
"+=" { yylval.Node = add_leaf("PLUSEQ","+="); printf("Found %s\n", yytext); return PLUSEQ; }
"-=" { yylval.Node = add_leaf("MINUSEQ","-="); printf("Found %s\n", yytext); return MINUSEQ;}
"*=" { yylval.Node = add_leaf("MULTIPLYEQ","*="); printf("Found %s\n", yytext); return MULTIPLYEQ;}
"/=" { yylval.Node = add_leaf("DIVIDEEQ","/="); printf("Found %s\n", yytext); return DIVIDEEQ;}
"++" { yylval.Node = add_leaf("PLUSPLUS","++"); printf("Found %s\n", yytext); return PLUSPLUS;}
"--" { yylval.Node = add_leaf("MINUSMINUS","--"); printf("Found %s\n", yytext); return MINUSMINUS;}
"||" { yylval.Node = add_leaf("OR","||"); printf("Found %s\n", yytext); return OR;}
"&&" { yylval.Node = add_leaf("AND","&&"); printf("Found %s\n", yytext); return AND;}
"|" { yylval.Node = add_leaf("BITOR","|"); printf("Found %s\n", yytext); return BITOR; }
"&" { yylval.Node = add_leaf("BITAND","&"); printf("Found %s\n", yytext); return BITAND; }
"!"|"not" { yylval.Node = add_leaf("NOT","not"); printf("Found %s\n", yytext); return NOT ;}
"+" { yylval.Node = add_leaf("PLUS","+"); printf("Found %s\n", yytext); return PLUS ;}
"-" { yylval.Node = add_leaf("MINUS","-"); printf("Found %s\n", yytext); return MINUS ;}
"*" { yylval.Node = add_leaf("MULTIPLY","*"); printf("Found %s\n", yytext); return MULTIPLY; }
"/" { yylval.Node = add_leaf("DIVIDE","/"); printf("Found %s\n", yytext); return DIVIDE ;}
"\"" { yylval.Node = add_leaf("DQUOTE","\""); printf("Found %s\n", yytext); return DQUOTE; }
"\'" { yylval.Node = add_leaf("SQUOTE","'"); printf("Found %s\n", yytext); return SQUOTE; }
"Processor" { yylval.Node = add_leaf("PROCESSOR","Processor"); printf("Found %s\n", yytext); return PROCESSOR; }
"architecture_type" { yylval.Node = add_leaf("ARCHITECTURE_TYPE","architecture_type"); printf("Found %s\n", yytext); return ARCHITECTURE_TYPE;}
"isa" { yylval.Node = add_leaf("ISA","isa"); printf("Found %s\n", yytext); return ISA;}
"clock_speed" { yylval.Node = add_leaf("CLOCK_SPEED","clock_speed"); printf("Found %s\n", yytext); return CLOCK_SPEED; }
"l1_memory" { yylval.Node = add_leaf("L1_MEMORY","l1_memory"); printf("Found %s\n", yytext); return L1_MEMORY ;}
"l2_memory" { yylval.Node = add_leaf("L2_MEMORY","l2_memory"); printf("Found %s\n", yytext); return L2_MEMORY ;}
"name" { yylval.Node = add_leaf("NAME","name"); printf("Found %s\n", yytext); return NAME ;}
"is_running" { yylval.Node = add_leaf("IS_RUNNING","is_running"); printf("Found %s\n", yytext); return IS_RUNNING ;}
"submit_jobs" { yylval.Node = add_leaf("SUBMIT_JOBS","submit_jobs"); printf("Found %s\n", yytext); return SUBMIT_JOBS; }
"get_clock_speed" { yylval.Node = add_leaf("GET_CLOCK_SPEED","get_clock_speed"); printf("Found %s\n", yytext); return GET_CLOCK_SPEED ; }
"run" { yylval.Node = add_leaf("RUN","run"); printf("Found %s\n", yytext); return RUN ;}
"discard_job" { yylval.Node = add_leaf("DISCARD_JOB","discard_job"); printf("Found %s\n", yytext); return DISCARD_JOB ;}
"Link" { yylval.Node = add_leaf("LINK","Link"); printf("Found %s\n", yytext); return LINK ;}
"start_point" { yylval.Node = add_leaf("START_POINT","start_point"); printf("Found %s\n", yytext); return START_POINT ; }
"end_point" { yylval.Node = add_leaf("END_POINT","end_point"); printf("Found %s\n", yytext); return END_POINT ;}
"bandwidth" { yylval.Node = add_leaf("BANDWIDTH","bandwidth"); printf("Found %s\n", yytext); return BANDWIDTH ;}
"channel_capacity" { yylval.Node = add_leaf("CHANNEL_CAPACITY","channel_capacity"); printf("Found %s\n", yytext); return CHANNEL_CAPACITY ;}
"Memory" { yylval.Node = add_leaf("MEMORY","memory"); printf("Found %s\n", yytext); return MEMORY ;}
"memory_type" { yylval.Node = add_leaf("MEMORY_TYPE","memory_type"); printf("Found %s\n", yytext); return MEMORY_TYPE ;}
"mem_size" { yylval.Node = add_leaf("MEM_SIZE","mem_size"); printf("Found %s\n", yytext); return MEM_SIZE ; }
"get_available_memory" { yylval.Node = add_leaf("GET_AVAILABLE_MEMORY","get_available_memory"); printf("Found %s\n", yytext); return GET_AVAILABLE_MEMORY ;}
"Job" { yylval.Node = add_leaf("JOB","job"); printf("Found %s\n", yytext); return JOB ;}
"job_id" { yylval.Node = add_leaf("JOB_ID","job_id"); printf("Found %s\n", yytext); return JOB_ID ; }
"flops_required" { yylval.Node = add_leaf("FLOPS_REQUIRED","flops_required"); printf("Found %s\n", yytext); return FLOPS_REQUIRED ; }
"deadline" { yylval.Node = add_leaf("DEADLINE","deadline"); printf("Found %s\n", yytext); return DEADLINE ;}
"mem_required" { yylval.Node = add_leaf("MEM_REQUIRED","mem_required"); printf("Found %s\n", yytext); return MEM_REQUIRED ;}
"affinity" { yylval.Node = add_leaf("AFFINITY","affinity"); printf("Found %s\n", yytext); return AFFINITY ;}
"get_memory" { yylval.Node = add_leaf("GET_MEMORY","get_memory"); printf("Found %s\n", yytext); return GET_MEMORY ; }
"Cluster" { yylval.Node = add_leaf("CLUSTER","cluster"); printf("Found %s\n", yytext); return CLUSTER ;}
"processors" { yylval.Node = add_leaf("PROCESSORS","processors"); printf("Found %s\n", yytext); return PROCESSORS ; }
"topology" { yylval.Node = add_leaf("TOPOLOGY","topology"); printf("Found %s\n", yytext); return TOPOLOGY ;}
"link_bandwidth" { yylval.Node = add_leaf("LINK_BANDWIDTH","link_bandwidth"); printf("Found %s\n", yytext); return LINK_BANDWIDTH ;}
"link_capacity" { yylval.Node = add_leaf("LINK_CAPACITY","link_capacity"); printf("Found %s\n", yytext); return LINK_CAPACITY ;}
"wait" { yylval.Node = add_leaf("WAIT","wait"); printf("Found %s\n", yytext); return WAIT; }

"Scheduler" { yylval.Node = add_leaf("scheduler","SCHEDULER"); printf("Found %s\n", yytext); return SCHEDULER; }
"job_array" { yylval.Node = add_leaf("JOB_ARRAY","job_array"); printf("Found %s\n", yytext); return JOB_ARRAY; }
"processor_array" { yylval.Node = add_leaf("PROCESSOR_ARRAY","processor_array"); printf("Found %s\n", yytext); return PROCESSOR_ARRAY; }
"set_job_affinity" { yylval.Node = add_leaf("SET_JOB_AFFINITY","set_job_affinity"); printf("Found %s\n", yytext); return SET_JOB_AFFINITY; }
"max_jobs" { yylval.Node = add_leaf("MAX_JOBS","max_jobs"); printf("Found %s\n", yytext); return MAX_JOBS; }
"get_load" { yylval.Node = add_leaf("GET_LOAD","get_load"); printf("Found %s\n", yytext); return GET_LOAD; }
"set_algo" { yylval.Node = add_leaf("SET_ALGO","set_algo"); printf("Found %s\n", yytext); return SET_ALGO; }

['][a-zA-Z0-9_]['] { yylval.Node = add_leaf("CHARACTER",string(yytext)); printf("Found %s\n", yytext); return CHARACTER; }
([0-9]*[.])?[0-9]+ { yylval.Node = add_leaf("NUM",string(yytext)); printf("Found %s\n", yytext); return NUM; }

[a-zA-Z_][a-zA-Z0-9_]* { yylval.Node = add_leaf("ID",string(yytext)); printf("Found ID %s\n", yytext); return ID ; }

[ \t]*  {}
[\n]		{ yylineno++;	lineno++;}

.  {printf("unexpected error\n");}

%%