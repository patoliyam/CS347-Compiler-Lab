%{
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



%}

%union{
	node *Node;
}


%token <Node> IF ELSE WHILE FOR SWITCH CASE DEFAULT LP RP LCP RCP LSP RSP SEMI COLON LT GT EQ PLUS MINUS MULTIPLY DIVIDE BITOR BITAND NOT ID NUM DOT COMMA PROCESSOR LINK  MEMORY JOB CLUSTER ISA CLOCK_SPEED L1_MEMORY L2_MEMORY NAME START_POINT END_POINT BANDWIDTH CHANNEL_CAPACITY MEMORY_TYPE MEM_SIZE JOB_ID FLOPS_REQUIRED DEADLINE MEM_REQUIRED PROCESSORS TOPOLOGY LINK_BANDWIDTH LINK_CAPACITY IS_RUNNING SUBMIT_JOBS OR AND PLUSEQ MINUSEQ MULTIPLYEQ DIVIDEEQ MINUSMINUS PLUSPLUS GET_CLOCK_SPEED RUN DISCARD_JOB GET_AVAILABLE_MEMORY GET_MEMORY ELSEIF AFFINITY EQEQ DQUOTE SQUOTE ARCHITECTURE_TYPE WAIT SCHEDULER JOB_ARRAY PROCESSOR_ARRAY SET_JOB_AFFINITY MAX_JOBS GET_LOAD SET_ALGO INT FLOAT VOID CHAR CHARACTER RETURN BREAK CONTINUE 

%type <Node> stmtlist stmt elsestmt exprc A switchstmt expression init mathexpr assignexpr arithexpr expr1 expr2 expr3 expr4 factor constructor proc_parameter_list C link_parameter_list D memory_parameter_list E job_parameter_list F cluster_parameter_list G proc_parameter argument valuearray H link_parameter memory_parameter job_parameter cluster_parameter function func_arg_list I value grammar_start scheduler_parameter_list scheduler_parameter Z semi rp rsp d list_var id_arr br_dimlist func_decl initial func_head stmtlist_body res_id decl_plist decl_pl empty decl_param stmt_body func_call paramlist plist return_stmt break_stmt continue_stmt type X

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
		print_nodes_in_file($$,output);
		$$->code = "main:\n" + $1->code + "li $v0,10\nsyscall\n";
		for(int i = 0; i < func_tab.size(); i++)
		{
			$$->code = $$->code + func_tab[i].code;
		}
		cout<<"***** FINAL CODE *****\n";
		cout<<$$->code;
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
	;

	
stmtlist : stmt stmtlist
{
	$$ = add_new_node("stmtlist",$1,$2);
	$$->code = $1->code + $2->code;
}
		| empty
{
	$$ = add_new_node("stmtlist",$1);
}
		;

stmt  : IF  LP exprc rp  LCP  { level++;} stmtlist { clear_sym_tab(level); level--; }  RCP elsestmt
{
	$$ = add_new_node("stmt",$1,$2,$3,$4,$5,$7,$9,$10);
	
	$$->code = $3->code + "li $t0,1" + "\n" + "blt	$a0,$t0," + "L_"+to_string(label)+"\n" + $7->code;
	if(!noelseflag)
		$$->code =$$->code + "j L_" +to_string(label-1);
	$$->code =$$->code+"\nL_"+to_string(label)+":\n" + $10->code;
    label++;
}
	| WHILE  LP exprc rp  LCP { level++; } stmtlist RCP
{
	$$ = add_new_node("stmt",$1,$2,$3,$4,$5,$7,$8);
	clear_sym_tab(level);
	level--;

	$$->code = "\nL_" + to_string(label)+":\n" + $3->code +"li $t0,1\n";
    label++;

	int break_index = $7->code.find("break");
	string break_replace = "j L_" + to_string(label)+"\n";

	if (break_index!=std::string::npos)
	     $7->code.replace(break_index, break_replace.size()-1, break_replace);

	int continue_index = $7->code.find("conti");
	string continue_replace = "j L_" + to_string(label-1)+"\n";

	if (continue_index!=std::string::npos)
	     $7->code.replace(continue_index, continue_replace.size()-1, continue_replace);

    $$->code = $$->code + "blt $a0,$t0, " + "L_"+to_string(label)+"\n" + $7->code+"j "+"L_"+to_string(label-1)+"\nL_"+to_string(label)+":\n";

    label++;
}
		| FOR  LP expression semi exprc semi expression rp  LCP { level++; } stmtlist RCP
{
	$$ = add_new_node("stmt",$1,$2,$3,$4,$5,$6,$7,$8,$9,$11,$12);
	clear_sym_tab(level);
	level--;

	$$->code = $3->code+"\nL_"+to_string(label)+":"+$5->code+ "li $t0,1" + "\n" + "blt $a0,$t0," + "L_"+to_string(label+1)+"\n";

	int index = $11->code.find("break");

	string break_replace = "j L_" + to_string(label+1)+"\n";
	if (index!=std::string::npos)
	     $11->code.replace(index, break_replace.size()-1, break_replace);

	int continue_index = $11->code.find("conti");
	string continue_replace = "j L_" + to_string(label)+"\n";
	cout<<"!@#$!@#$12#$!@33"<<continue_replace.size()<<" " <<continue_replace<<endl;
	if (continue_index!=std::string::npos)
	     $11->code.replace(continue_index, continue_replace.size()-1, continue_replace);


	$$->code = $$->code + $7->code + $11->code+"\nj L_" + to_string(label) + "\nL_" + to_string(label+1) + ":\n";

	label++;
	label++;
}
		| SWITCH LP arithexpr rp switchstmt
{
	$$ = add_new_node("stmt",$1,$2,$3,$4,$5);
	$$->code = $3->code+"\n"+ "sw $a0,268501992\n" + $5->code;
}
		| expression semi
{
	$$ = add_new_node("stmt",$1,$2);
	$$->code = $1->code;
}
		| d semi
{
	$$ = add_new_node("stmt",$1,$2);
	$$->code = $1->code;
}
		| func_decl
{
	$$ = add_new_node("stmt",$1);
	$$->code = $1->code;
}
		| return_stmt
{
		$$ = add_new_node("stmt",$1);
	    $$->code = $1->code;
}
		| break_stmt
{
		$$ = add_new_node("stmt",$1);
	    $$->code = $1->code;
}
		| continue_stmt
{
		$$ = add_new_node("stmt",$1);
	    $$->code = $1->code;
}
		;

break_stmt		: BREAK
{
	$$->code = "break";
}

continue_stmt	: CONTINUE
{
	$$->code = "conti";
}

return_stmt             : RETURN  expression semi
{
    $$ = add_new_node("return_stmt",$1,$2,$3);
    if(active_function_ptr!=NULL)
    {
	    long long int param_offset = (active_function_ptr->paramlist).size();
	    param_offset*=4;
	    if ($2->code == "")
	    {
	 		$$->code = "jr $ra\n";
	    }
	    else
	    {
	    	if(active_function_ptr->rettype != $2->eletype)
	    	{
	    		cout<<"function and return types mismatch"<<endl;
	    	}
	    	$$->code= $2->code + "move $v0,$a0\n" + "\njr $ra\n";
	    }
    }
    else
    {
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"return statement outside function"<<endl;
    }
}
		;


elsestmt  : ELSEIF  LP exprc rp  LCP {level++; } stmtlist  { clear_sym_tab(level); level--; } RCP  elsestmt
{
	$$ = add_new_node("elsestmt",$1,$2,$3,$4,$5,$7,$9,$10);

	$$->code = $3->code + "li $t0,1" + "\n" + "blt	$a0,$t0," + "L_" + to_string(label+1)+"\n" + "L_" + to_string(label) + ":\n" + $7->code + "L_" + to_string(label+1) + ":\n" + $10->code;
	label++;
	label++;
	
	noelseflag = 0;
}
			| ELSE  LCP {level++; }  stmtlist {clear_sym_tab(level); level--; }  RCP
{
	$$ = add_new_node("elsestmt",$1,$2,$4,$6);
	$$->code = $4->code+ "L_" + to_string(label) + ":\n" ;
	label++;

	noelseflag = 0;

}
			|
{
	$$ = add_new_node("elsestmt");
}
			;


d : type list_var
{
	$$ = add_new_node("d",$1,$2);
    string temp_code = "";
    $$->eletype = $1->eletype;
    string temp_code2 = $2->code;
	for(int i=0; i<namelist.size(); i++)
	{	
		if(search_sym_tab_decl(namelist[i].name,level) == NULL)
		{	
			if(compatible_assign($1->eletype,namelist[i].eletype) || namelist[i].eletype=="any")
			{
				sym_tab_entry temp;
				temp.type = namelist[i].type;
				
				temp.eletype = $1->eletype;
				
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
						$$->eletype = "errortype";						
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
				cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"variable is declared of "<<$1->eletype<<" but the expression is assigned "<<namelist[i].eletype<<endl;
				$$->eletype = "errortype";
			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Variable already declared"<<endl;
			$$->eletype = "errortype";
		}
	}
	temp_code += temp_code2;			
	$$->code = temp_code;
	print_sym_table();
	namelist.clear();
}
	;


list_var : id_arr X
{
	$$ = add_new_node("list_var",$1);
	$$->eletype = $1->eletype;
	struct id_name temp;
	temp.name = $1->node_val;
	temp.type = $1->eletype;
	temp.eletype = $2->eletype;
	temp.dimlist = $1->dimlist;
	namelist.push_back(temp);

	if($2->code != "")
	{
		$$->code = $2->code + "***" + $1->node_val;
	}

}
	| id_arr X COMMA list_var
{
	$$ = add_new_node("list_var",$1,$2,$3,$4);
	$$->eletype = $1->eletype;
	struct id_name temp;
	temp.name = $1->node_val;
	temp.type = $1->eletype;
	temp.eletype = $2->eletype;
	temp.dimlist = $1->dimlist;
	namelist.push_back(temp);

	if($2->code != "")
	{
		$$->code = $2->code + "***" + $1->node_val + $4->code;
	}
	else
	{
		$$->code=$4->code;
	}

}
	;

X : EQ arithexpr
{
	$$=add_new_node("X",$1,$2);
	$$->eletype=$2->eletype;

	$$->code= $2->code;
}
	|
{
	$$=add_new_node("X");
	$$->eletype="any";
}
	;
	
id_arr : ID
{
	$$ = add_new_node("id_arr",$1);
	$$->node_val = $1->node_val;
	$$->eletype = "simple";
	$$->dimlist = dim_list;
	dim_list.clear();
}
	|ID br_dimlist
{
	$$ = add_new_node("id_arr",$1,$2);
	$$->node_val = $1->node_val;
	$$->eletype = "arraytype";
	$$->dimlist = dim_list;
	dim_list.clear();
}
	;

br_dimlist : LSP mathexpr RSP
{
	$$ = add_new_node("br_dimlist",$1,$2,$3);
	dim_list.insert(dim_list.begin(), $2->node_val_num);
}
	|br_dimlist LSP mathexpr RSP
{
	$$ =add_new_node("br_dimlist",$1,$2,$3,$4);
	dim_list.push_back($3->node_val_num);
}
	;

type: INT
{
	$$ = add_new_node("type",$1);
	$$->eletype = $1->node_val;
}
		| FLOAT
{
	$$ = add_new_node("type",$1);
	$$->eletype = $1->node_val;
}
		| CHAR
{
	$$ = add_new_node("type",$1);
	$$->eletype = $1->node_val;
}
		| VOID
{
	$$ = add_new_node("type",$1);
	$$->eletype = $1->node_val;
}
		;


exprc : A
{
	$$ = add_new_node("exprc",$1);

	$$->node_val_num = $1->node_val_num;
	$$->eletype = $1->eletype;
	$$->code = $1->code;

}
	|	exprc OR A
{
	$$ = add_new_node("exprc",$1,$2,$3);
	$$->node_val_num = $1->node_val_num || $3->node_val_num;
	$$->eletype = "int";
	//code generation
	int label1 = label++;
	int label2 = label++;
	$$->code = $1->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + $3->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nadd $t1,$t1,$t2\nli $t2,0\nbeq $t1,$t2,L_" + to_string(label1) + "\nli $a0,1\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,0\nL_" + to_string(label2) + ":\n";
}
	| exprc AND A
{
	$$ = add_new_node("exprc",$1,$2,$3);
	$$->node_val_num = $1->node_val_num && $3->node_val_num;
	$$->eletype = "int";

	//code generation
	int label1 = label++;
	int label2 = label++;
	$$->code = $1->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + $3->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nmult $t1,$t2\nmflo $t1\nli $t2,0\nbeq $t1,$t2,L_" + to_string(label1) + "\nli $a0,1\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,0\nL_" + to_string(label2) + ":\n";
}
	;

A : expression LT expression
{
	$$ = add_new_node("A",$1,$2,$3);
	if(compatible_arithop($1->eletype,$3->eletype))
	{
		$$->node_val_num = $1->node_val_num < $3->node_val_num;
		$$->eletype = "int";

		//code generation
		int label1 = label++;
	    int label2 = label++;
	    $$->code = $1->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + $3->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nbge $t1,$t2,L_" + to_string(label1) + "\nli $a0,1\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,0\nL_" + to_string(label2) + ":\n";

	}
	else
	{
		$$->eletype = "errortype";
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands not compatible"<<endl;
	}
}
	| expression GT expression
{
	$$ = add_new_node("A",$1,$2,$3);
	if(compatible_arithop($1->eletype,$3->eletype))
	{
		$$->node_val_num = $1->node_val_num > $3->node_val_num;
		$$->eletype = "int";

		//code generation
		int label1 = label++;
	    int label2 = label++;
	    $$->code = $1->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + $3->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nble $t1,$t2,L_" + to_string(label1) + "\nli $a0,1\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,0\nL_" + to_string(label2) + ":\n";
	}
	else
	{
		$$->eletype = "errortype";
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands not compatible"<<endl;		
	}
}
	| expression EQEQ expression
{
	$$ = add_new_node("A",$1,$2,$3);
	if(compatible_arithop($1->eletype,$3->eletype))
	{
		$$->node_val_num = ($1->node_val_num == $3->node_val_num);
		$$->eletype = "int";

		//code generation
		int label1 = label++;
    	int label2 = label++;
    	$$->code = $1->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + $3->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nbeq $t1,$t2,L_" + to_string(label1) + "\nli $a0,0\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,1\nL_" + to_string(label2) + ":\n";
	}
	else
	{
		$$->eletype = "errortype";
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands not compatible"<<endl;				
	}
}
	| expression LT EQ expression
{
	$$ = add_new_node("A",$1,$2,$3,$4);
	if(compatible_arithop($1->eletype,$3->eletype))
	{
		$$->node_val_num = $1->node_val_num <= $3->node_val_num;
		$$->eletype = "int";

		//code generation
		int label1 = label++;
	    int label2 = label++;
	    $$->code = $1->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + $4->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nbgt $t1,$t2,L_" + to_string(label1) + "\nli $a0,1\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,0\nL_" + to_string(label2) + ":\n";
	}
	else
	{
		$$->eletype = "errortype";
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands not compatible"<<endl;				
	}
}
	| expression GT EQ expression
{
	$$ = add_new_node("A",$1,$2,$3,$4);
	if(compatible_arithop($1->eletype,$3->eletype))
	{
		$$->node_val_num = $1->node_val_num >= $3->node_val_num;
		$$->eletype = "int";

		//code generation
		int label1 = label++;
    	int label2 = label++;
    	$$->code = $1->code + "sw $a0,0($sp)\naddiu $sp,$sp,-4\n" + $4->code + "lw $t1,4($sp)\naddiu $sp,$sp,4\nmove $t2,$a0\nblt $t1,$t2,L_" + to_string(label1) + "\nli $a0,1\nj L_" + to_string(label2) +"\nL_" + to_string(label1) + ": li $a0,0\nL_" + to_string(label2) + ":\n";
	}
	else
	{
		$$->eletype = "errortype";
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands not compatible"<<endl;				
	}
}
	| expression
{
	$$ = add_new_node("A",$1);
	$$->node_val_num = $1->node_val_num;
	$$->eletype = $1->eletype;

	//code generation
	$$->code = $1->code;
}

	;
switchstmt  : CASE  LP arithexpr rp  LCP { level++; } stmtlist   { clear_sym_tab(level); level--; }RCP  switchstmt
{
	$$ = add_new_node("switchstmt",$1,$2,$3,$4,$5,$7,$9,$10);

	$$->code = "lw $t0,268501992\n" + $3->code + "bne $t0,$a0,L_" + to_string(label+1) +"\n" + $7->code + "L_" + to_string(label+1) + ":" + $10->code;
	label++;
}
			|
{
	$$ = add_new_node("switchstmt");
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
	| initial
{
	$$ = add_new_node("expression",$1);
}
	| mathexpr
{
	$$ = add_new_node("expression",$1);
	$$->eletype = $1->eletype;
	$$->code = $1->code;
}
	|
{
	$$ = add_new_node("expression");
}
	;

initial : id_arr EQ init
{
	$$ = add_new_node("initial",$1,$2,$3);
}
	   ;

init : constructor
{
	$$ = add_new_node("init",$1);
}
	|
		initial
{
	$$ = add_new_node("init",$1);
}
	;

mathexpr : assignexpr
{
	$$ = add_new_node("mathexpr",$1);
	$$->code = $1->code;
}
		   | arithexpr
{
	$$ = add_new_node("mathexpr",$1);
	$$->node_val_num = $1->node_val_num ;
	$$->eletype = $1->eletype ;
	$$->code = $1->code;
}
	;


assignexpr : id_arr EQ mathexpr
{
	$$ = add_new_node("assignexpr",$1,$2,$3);
	int var=0;
	int func_flag=0,index=0;
	sym_tab_entry * temp= check_id_arr($1->node_val,level,&var,&func_flag,&index,$1->dimlist);
	if(temp!=NULL)
	{
		if(compatible_assign(temp->eletype,$3->eletype) || (temp->eletype == "char" && $3->eletype == "char"))
		{
			if(temp->type=="simple")
			{
				if(func_flag==1)
				{
					$$->code = $3->code + "move $a" + to_string(index)+ ",$a0\n";
				}
				else
				{
					$$->code= $3->code + "sw $a0,"+to_string(temp->offset)+"\n";
				}
			}
			else
			{
				//var is offset of array
				// array's name is temp->name
				long long int tmpoffset = temp->offset + var*4;
				if(func_flag==1)
				{
					$$->code = $3->code + "move $a" + to_string(index)+ ",$a0\n";						
				}
				else
				{
					$$->code= $3->code + "sw $a0,"+ to_string(tmpoffset);
				}
			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Expected type "<<temp->eletype<<" , Found "<<$3->eletype<<endl;
		}
	}
}
			| id_arr PLUSEQ mathexpr
{
	$$ = add_new_node("assignexpr",$1,$2,$3);
	$$->eletype = $3->eletype;
	int func_flag=0,index=0;
	int var=0;
	sym_tab_entry * temp= check_id_arr($1->node_val,level,&var,&func_flag,&index,$1->dimlist);
	if(temp!=NULL)
	{
		if(compatible_assign(temp->eletype,$3->eletype))
		{
			temp->eletype = compare_types(temp->eletype,$3->eletype);
			if(temp->eletype=="simple")
			{
				if(func_flag==1)
				{
					$$->code= $3->code + "move $t1,$a" + to_string(index) + "\n add $a0,$a0,$t1\n"+  "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					$$->code= $3->code + "lw $t1," + to_string(temp->offset) + "\n add $a0,$a0,$t1\n"+  "sw $a0,"+to_string(temp->offset)+"\n"+ "li $a0,1\n";
				}

			}
			else
			{
				//var is offset of array
				// array's name is temp->name

				if(func_flag==1)
				{
					$$->code= $3->code + "move $t1,$a" + to_string(index) + "\n add $a0,$a0,$t1\n"+  "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					long long int tmpoffset = temp->offset + var*4;
					$$->code= $3->code + "lw $t1," + to_string(tmpoffset)+ "\n add $a0,$a0,$t1\n"+  "sw $a0,"+to_string(tmpoffset)+"\n"+ "li $a0,1\n";
				}

			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<$3->eletype<<" can't be assigned to a "<<temp->eletype<<endl;
		}
	}
}
			| id_arr MINUSEQ mathexpr
{
	$$ = add_new_node("assignexpr",$1,$2,$3);
	$$->eletype = $3->eletype;
	int func_flag=0,index=0;
	int var=0;
	sym_tab_entry * temp= check_id_arr($1->node_val,level,&var,&func_flag,&index,$1->dimlist);
	if(temp!=NULL)
	{
		if(compatible_assign(temp->eletype,$3->eletype))
		{
			temp->eletype = compare_types(temp->eletype,$3->eletype);
			if(temp->eletype=="simple")
			{
				if(func_flag==1)
				{
					$$->code= $3->code + "move $t1,$a" + to_string(index) + "\n sub $a0,$a0,$t1\n"+  "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					$$->code= $3->code + "lw $t1,(" + to_string(temp->offset)+ "\n sub $a0,$a0,$t1\n"+  "sw $a0,"+to_string(temp->offset)+"\n"+ "li $a0,1\n";
				}
			}
			else
			{
				//var is offset of array
				// array's name is temp->name
				long long int tmpoffset = temp->offset + var*4;	
				if(func_flag==1)
				{
					$$->code= $3->code + "move $t1,$a" + to_string(index) + "\n sub $a0,$a0,$t1\n"+  "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					$$->code= $3->code + "lw $t1," + to_string(tmpoffset)+ "\n sub $a0,$a0,$t1\n"+  "sw $a0,"+to_string(tmpoffset)+"\n"+ "li $a0,1\n";
				}

			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<$3->eletype<<" can't be assigned to a "<<temp->eletype<<endl;
		}
	}
}
			| id_arr MULTIPLYEQ mathexpr
{
	$$ = add_new_node("assignexpr",$1,$2,$3);
	$$->eletype = $3->eletype;
	int func_flag=0,index=0;
	int var=0;
	sym_tab_entry * temp= check_id_arr($1->node_val,level,&var,&func_flag,&index,$1->dimlist);
	if(temp!=NULL)
	{
		if(compatible_assign(temp->eletype,$3->eletype))
		{
			temp->eletype = compare_types(temp->eletype,$3->eletype);
			if(temp->eletype=="simple")
			{
				if(func_flag==1)
				{	
					$$->code= $3->code + "move $t1,$a" + to_string(index)+ "\n mul $a0,$t1\n" + "mflo $a0" +  "move $a0,$a"+to_string(index) + "\n"+ "li $a0,1\n";
				}
				else
				{
					$$->code= $3->code + "lw $t1," + to_string(temp->offset)+ "\n mul $a0,$t1\n" + "mflo $a0" +  "sw $a0,"+to_string(temp->offset)+"\n"+ "li $a0,1\n";
				}
			}
			else
			{
				//var is offset of array
				// array's name is temp->name
				if(func_flag==1)
				{
					$$->code= $3->code + "move $t1,$a" + to_string(index)+ "\n mul $a0,$t1\n" + "mflo $a0" +  "move $a0,$a"+to_string(index) + "\n"+ "li $a0,1\n";
				}
				else
				{
					long long int tmpoffset = temp->offset + var*4;
					$$->code= $3->code + "lw $t1," + to_string(tmpoffset)+ "\n mul $a0,$t1\n" + "mflo $a0" +  "sw $a0,"+to_string(tmpoffset)+"\n"+ "li $a0,1\n";
				}

			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<$3->eletype<<" can't be assigned to a "<<temp->eletype<<endl;
		}
	}
}
			| id_arr DIVIDEEQ mathexpr
{
	$$ = add_new_node("assignexpr",$1,$2,$3);
	int func_flag=0,index=0;
	int var=0;
	sym_tab_entry * temp= check_id_arr($1->node_val,level,&var,&func_flag,&index,$1->dimlist);
	if($3->node_val_num != 0)
	{
		if(compatible_assign(temp->eletype,$3->eletype))
		{
			temp->eletype = compare_types(temp->eletype,$3->eletype);
			if(temp!=NULL)
			{
				$$->eletype = temp->eletype;
				if(temp->eletype=="simple")
				{
					if(func_flag==1)
					{
						$$->code= $3->code + "move $t1,$a" + to_string(index) + "\n div $a0,$t1\n" + "mflo $a0" +  "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
					}
					else
					{
						$$->code= $3->code + "lw $t1," + to_string(temp->offset)+ "\n div $a0,$t1\n" + "mflo $a0" +  "sw $a0,"+to_string(temp->offset)+"\n"+ "li $a0,1\n";
					}
				}
				else
				{
					//var is offset of array
					// array's name is temp->name
					if(func_flag==1)
					{
						$$->code= $3->code + "move $t1,$a" + to_string(index) + "\n div $a0,$t1\n" + "mflo $a0" +  "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
					}
					else
					{
						long long int tmpoffset = temp->offset + var*4;
						$$->code= $3->code + "lw $t1," + to_string(tmpoffset)+ "\n div $a0,$t1\n" + "mflo $a0" +  "sw $a0,"+to_string(tmpoffset)+"\n"+ "li $a0,1\n";
					}
				}
			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<$3->eletype<<" can't be assigned to a "<<temp->eletype<<endl;
		}
	}
	else
	{
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Division by 0 not allowed"<<temp->eletype<<endl;	
	}
}
			| id_arr MINUSMINUS
{
	$$ = add_new_node("assignexpr",$1,$2);
	$$->eletype = $1->eletype;
	int func_flag=0,index=0;
	int var=0;
	sym_tab_entry * temp= check_id_arr($1->node_val,level,&var,&func_flag,&index,$1->dimlist);
	if(temp!=NULL)
	{
		if(temp->eletype == "int" || temp->eletype == "float")
		{
			if(temp->eletype=="simple")
			{
				if(func_flag==1)
				{
					$$->code= "move $t1,$a" + to_string(index) + "\nsubi $a0,$t1,1 \n" + "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					$$->code= "lw $t1," + to_string(temp->offset)+ "\nsubi $a0,$t1,1 \n" + "sw $a0,"+to_string(temp->offset)+"\n"+ "li $a0,1\n";
				}
			}
			else
			{
				//var is offset of array
				// array's name is temp->name
				long long int tmpoffset = temp->offset + var*4;	
				if( func_flag==1)
				{
					$$->code= "move $t1,$a" + to_string(index) + "\n subi $a0,$t1,1 \n" + "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					$$->code= "lw $t1," + to_string(tmpoffset)+ "\n subi $a0, $t1,1 \n" + "sw $a0,"+to_string(tmpoffset)+"\n"+ "li $a0,1\n";
				}
			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"-- operation not supported for "<<temp->eletype<<endl;
		}
	}
}
			| id_arr PLUSPLUS
{
	$$ = add_new_node("assignexpr",$1,$2);
	$$->eletype = $1->eletype;
	int func_flag=0,index=0;
	int var=0;
	sym_tab_entry * temp= check_id_arr($1->node_val,level,&var,&func_flag,&index,$1->dimlist);
	if(temp!=NULL)
	{
		if(temp->eletype == "int" || temp->eletype == "float")
		{
			if(temp->eletype=="simple")
			{
				if(func_flag==1)
				{
					$$->code= "move $t1,$a" + to_string(index)+ "\n addi $a0, $t1,1 \n" + "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					$$->code= "lw $t1," + to_string(temp->offset)+ "\n addi $a0,$t1,1 \n" + "sw $a0,"+to_string(temp->offset)+"\n"+ "li $a0,1\n";
				}
			}
			else
			{
				//var is offset of array
				// array's name is temp->name
				long long int tmpoffset = temp->offset + var*4;	
				if(func_flag==1)
				{
					$$->code= "move $t1,$a" + to_string(index)+ "\n addi $a0, $t1,1 \n" + "move $a0,$a"+to_string(index)+"\n"+ "li $a0,1\n";
				}
				else
				{
					$$->code= "lw $t1," + to_string(tmpoffset)+ "\n addi $a0, $t1,1 \n" + "sw $a0,"+to_string(tmpoffset)+"\n"+ "li $a0,1\n";
				}
			}
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"++ operation not supported for "<<temp->eletype<<endl;
		}
	}
}
	;


arithexpr :expr1 BITAND arithexpr
{
	$$ = add_new_node("arithexpr",$1,$2,$3);
	if($1->eletype == "int" && $3->eletype == "int")
	{
		$$->eletype=$1->eletype;
		$$->node_val_num = (int)$1->node_val_num & (int)$3->node_val_num;
		$$->code = $1->code + "move $t1,$a0\n" + $3->code+ "move $t2,$a0\n" + "and $a0,$t1,$t2\n";
	}
	else
	{
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"bitwise and operation is allowed only for integers"<<endl;	
	}
}
			| expr1
{
	$$ = add_new_node("arithexpr",$1);
	$$->eletype = $1->eletype;
	$$->node_val_num = $1->node_val_num;
	$$->code = $1->code;

}
			;

expr1 : expr2 BITOR expr1
{
	$$ = add_new_node("expr1",$1,$2,$3);
	if($1->eletype == "int" && $3->eletype == "int")
	{
		$$->eletype=$1->eletype;
		$$->node_val_num = (int)$1->node_val_num | (int)$3->node_val_num;
		$$->code = $1->code + "move $t1,$a0\n" + $3->code+ "move $t2,$a0\n" + "or $a0,$t1,$t2\n";
	}
	else
	{
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"bitwise or operation is allowed only for integers"<<endl;	
	}
}
		| expr2
{
	$$ = add_new_node("expr1",$1);
	$$->eletype = $1->eletype;
	$$->node_val_num = $1->node_val_num;
	$$->code = $1->code;

}
		;

expr2: expr2 PLUS expr3
{
	$$ = add_new_node("expr2",$1,$2,$3);
	cout<<$1->eletype<<" "<<$3->eletype<<endl;
	if(compatible_arithop($1->eletype,$3->eletype))
	{
		$$->node_val_num = $1->node_val_num+$3->node_val_num;
		$$->eletype = compare_types($1->eletype,$3->eletype);
		$$->code = $1->code + "move $t1,$a0\n" + $3->code+ "move $t2,$a0\n" + "add $a0,$t1,$t2\n";
	}
	else
	{
		$$->eletype = "errortype";
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands are not compatible for addition"<<endl;	
	}
}
	| expr2 MINUS expr3
{
	$$ = add_new_node("expr2",$1,$2,$3);
	if(compatible_arithop($1->eletype,$3->eletype))
	{
		$$->node_val_num = $1->node_val_num-$3->node_val_num;
		$$->eletype = compare_types($1->eletype,$3->eletype);
		$$->code = $1->code + "move $t1,$a0\n" + $3->code+ "move $t2,$a0\n" + "sub $a0,$t1,$t2\n";
	}
	else
	{
		$$->eletype = "errortype";
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands are not compatible for subtraction"<<endl;	
	}
}
	| expr3
{
	$$ = add_new_node("expr2",$1);
	$$->node_val_num = $1->node_val_num;
	$$->eletype = $1->eletype;
	$$->code = $1->code;
}
	;
expr3: 	expr3 MULTIPLY expr4
{
	$$ = add_new_node("expr3",$1,$2,$3);
	if(compatible_arithop($1->eletype,$3->eletype))
	{
		$$->node_val_num = $1->node_val_num * $3->node_val_num;
		$$->eletype = compare_types($1->eletype,$3->eletype);
		$$->code = $1->code + "move $t1,$a0\n" + $3->code+ "move $t2,$a0\n" + "mult $t1,$t2\n" + "mflo $a0 \n";
	}
	else
	{
		$$->eletype = "errortype";
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands are not compatible for multiplication"<<endl;	
	}
}
		| expr3 DIVIDE expr4
{
	$$ = add_new_node("expr3",$1,$2,$3);
	if(compatible_arithop($1->eletype,$3->eletype))
	{
		if($3->node_val_num != 0)
		{
			$$->node_val_num = $1->node_val_num / $3->node_val_num;
			$$->eletype = compare_types($1->eletype,$3->eletype);
			$$->code = $1->code + "move $t1,$a0\n" + $3->code+ "move $t2,$a0\n" + "div $t1,$t2\n" + "mflo $a0 \n";
		}
		else
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Division by zero not allowed"<<endl;	
		}
	}
	else
	{
		$$->eletype = "errortype";
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Operands are not compatible for division"<<endl;	
	}
}
		| expr4
{
	$$ = add_new_node("expr3",$1);
	$$->node_val_num = $1->node_val_num;
	$$->eletype = $1->eletype;

	$$->code = $1->code;
}
	   ;

expr4 : NOT factor
{
	$$ = add_new_node("expr4",$1,$2);
	if($2->eletype =="int")
	{
		$$->node_val_num = !(int)$2->node_val_num;
		$$->eletype = $2->eletype;
		$$->code = $1->code + "not $t1,$a0\n" + "mov $a0,$t1\n";

	}
	else
	{
		$$->eletype = "errortype";
		cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"NOT operation is allowed only for integers"<<endl;	
	}
}
		| factor
{
	$$ = add_new_node("expr4",$1);
	$$->node_val_num = $1->node_val_num;
	$$->eletype = $1->eletype;
	$$->code = $1->code;

}
		;

factor : NUM
{
	$$ = add_new_node("factor",$1);
	$$->node_val_num = $1->node_val_num;
	$$->eletype = $1->eletype;
	if($$->eletype == "int")
	{
	    $$->code = "li $a0,"+to_string((int)$1->node_val_num)+"\n";
	}
	else if($$->eletype == "float")
	{
	    $$->code = "li $a0,"+to_string((float)$1->node_val_num)+"\n";
	}

}
	| CHARACTER
{
	$$ = add_new_node("factor",$1);
	$$->node_val_num = $1->node_val_num;
	$$->eletype = $1->eletype;
    $$->code = "li $a0,"+to_string((int)$1->node_val_num)+"\n";
}
	| id_arr DOT function
{
	$$ = add_new_node("factor",$1,$2,$3);
}
	| constructor DOT function
{
	$$ = add_new_node("factor",$1,$2,$3);
}
		| id_arr
{
	$$ = add_new_node("factor",$1);
	int var=0;
	int func_flag=0,index=0;
	sym_tab_entry * temp= check_id_arr($1->node_val,level,&var,&func_flag,&index,$1->dimlist);
	if(temp!=NULL)
	{
		$$->eletype = temp->eletype;
		if(temp->eletype=="simple")
		{
			if(func_flag=1)
			{
	            $$->code= "move $a0,$a" + to_string(index) +"\n";
			}
			else
			{
	            $$->code= "lw $a0,"+to_string(temp->offset)+"\n";
			}
		}
		else
		{
			if(var != -1)
			{
				int offset_of_array = temp->offset + 4*var;
				if(func_flag==1)
				{
	            	$$->code= "move $a0,$a" + to_string(index) + "\n";

				}
				else
				{
	            	$$->code= "lw $a0,"+to_string(offset_of_array)+"\n";
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
		$$->eletype = "errortype";
	}
}
		| LP arithexpr rp
{
	$$ = add_new_node("factor",$1,$2,$3);
	$$->node_val_num = $2->node_val_num;
	$$->eletype = $2->eletype;
	$$->code = $1->code;

}
		| func_call
{
		$$ = add_new_node("factor",$1);
		
		$$->eletype = $1->eletype;
		$$->code = $1->code;
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

value : SQUOTE id_arr SQUOTE
{
	$$ = add_new_node("value",$1,$2,$3);
}
	| DQUOTE id_arr DQUOTE
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

func_decl:func_head LCP { level=2; } stmtlist_body RCP
{
    $$ = add_new_node("func_decl",$1,$2,$4,$5);
    clear_sym_tab(2);
    level=0;

	if(active_function_ptr->rettype != "void")
	{
		int index = $4->code.find("jr $ra");
		if (index==std::string::npos)
		{
			cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"function is of returntype : "<< active_function_ptr->rettype << " but no return mentioned"<<endl;
		}
	}

    string temp_code;
    temp_code = "func_"+active_function_ptr->name+":\n";
    temp_code += $4->code;
    temp_code += "jr $ra\n";
    active_function_ptr->code = temp_code;
    active_function_ptr = NULL;



}
		;

func_head:res_id LP { level=1; } decl_plist RP
{
    $$ = add_new_node("func_head",$1,$2,$4,$5);
    active_function_ptr=search_func_tab($1->node_val);
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
		    temp.name = $1->node_val;
		    temp.rettype = $1->eletype;
		    temp.paramlist = param_list;
		    param_list.clear();
		    func_tab.push_back(temp);
		    active_function_ptr=search_func_tab($1->node_val);
		}
		print_func_table();
    }
    else
    {
    	cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Function "<<$1->node_val<<" already exists."<<endl;
    }
}
		;

res_id:type ID
{
    $$ = add_new_node("res_id",$1,$2);
    $$->eletype = $1->eletype;
    $$->node_val = $2->node_val;
}
		;


decl_plist: decl_pl
{
	$$ = add_new_node("decl_plist",$1);
}
		|
{
	$$ = add_new_node("decl_plist");
}
		;

decl_pl: decl_pl COMMA decl_param
{
	$$ = add_new_node("decl_pl",$1,$2,$3);
}
		|decl_param
{
	$$ = add_new_node("decl_pl",$1);
}
		;

decl_param: type ID
{
	$$ = add_new_node("decl_param",$1,$2);
	sym_tab_entry temp;
	temp.eletype = $1->eletype;
	temp.type = "simple";
	temp.name = $2->node_val;
	param_list.push_back(temp);
}
			|type ID LSP RSP
{
	$$ = add_new_node("decl_param",$1,$2,$3,$4);
	sym_tab_entry temp;
	temp.eletype = $1->eletype;
	temp.type = "arraytype";
	temp.name = $2->node_val;
	temp.dimlist.push_back(999999);
	dim_list.clear();
	param_list.push_back(temp);
}
		;

stmtlist_body:  stmt_body stmtlist_body
{
	$$ = add_new_node("stmtlist_body",$1,$2);
	$$->code = $1->code + $2->code;
}
			| empty
{
	$$ = add_new_node("stmtlist_body",$1);
}
		;

stmt_body  : IF  LP exprc rp  LCP  { level++;} stmtlist {clear_sym_tab(level); level--; }  RCP elsestmt
{
	$$ = add_new_node("stmt_body",$1,$2,$3,$4,$5,$7,$9,$10);
	
	$$->code = $3->code + "li $t0,1" + "\n" + "blt	$a0,$t0," + "L_"+to_string(label)+"\n" + $7->code;
	if(!noelseflag)
		$$->code =$$->code + "j L_" +to_string(label-1);
	$$->code =$$->code+"\nL_"+to_string(label)+":\n" + $10->code;
    label++;
}
	| WHILE  LP exprc rp  LCP { level++; } stmtlist RCP
{
	$$ = add_new_node("stmt_body",$1,$2,$3,$4,$5,$7,$8);
	clear_sym_tab(level);
	level--;

	$$->code = "\nL_" + to_string(label)+":\n" + $3->code +"li $t0,1\n";
    label++;

	int break_index = $7->code.find("break");
	string break_replace = "j L_" + to_string(label)+"\n";

	if (break_index!=std::string::npos)
	     $7->code.replace(break_index, break_replace.size()-1, break_replace);

	int continue_index = $7->code.find("conti");
	string continue_replace = "j L_" + to_string(label-1)+"\n";

	if (continue_index!=std::string::npos)
	     $7->code.replace(continue_index, continue_replace.size()-1, continue_replace);

    $$->code = $$->code + "blt $a0,$t0, " + "L_"+to_string(label)+"\n" + $7->code+"j "+"L_"+to_string(label-1)+"\nL_"+to_string(label)+":\n";

    label++;
}
		| FOR  LP expression semi exprc semi expression rp  LCP { level++; } stmtlist RCP
{
	$$ = add_new_node("stmt_body",$1,$2,$3,$4,$5,$6,$7,$8,$9,$11,$12);
	clear_sym_tab(level);
	level--;

	$$->code = $3->code+"\nL_"+to_string(label)+":"+$5->code+ "li $t0,1" + "\n" + "blt $a0,$t0," + "L_"+to_string(label+1)+"\n";

	int index = $11->code.find("break");

	string break_replace = "j L_" + to_string(label+1)+"\n";
	if (index!=std::string::npos)
	     $11->code.replace(index, break_replace.size()-1, break_replace);

	int continue_index = $11->code.find("conti");
	string continue_replace = "j L_" + to_string(label)+"\n";

	if (continue_index!=std::string::npos)
	     $11->code.replace(continue_index, continue_replace.size()-1, continue_replace);


	$$->code = $$->code + $7->code+ $11->code+"\nj L_" + to_string(label) + "\nL_" + to_string(label+1) + ":\n";

	label++;
	label++;
}
		| SWITCH LP arithexpr rp switchstmt
{
	$$ = add_new_node("stmt_body",$1,$2,$3,$4,$5);
	$$->code = $3->code+"\n"+ "sw $a0,268501992\n" + $5->code;
}
		| expression semi
{
	$$ = add_new_node("stmt_body",$1,$2);
	$$->code = $1->code;
}
		| d semi
{
	$$ = add_new_node("stmt_body",$1,$2);
	$$->code = $1->code;
}
		| return_stmt
{
		$$ = add_new_node("stmt_body",$1);
	    $$->code = $1->code;
}
		| break_stmt
{
		$$ = add_new_node("stmt_body",$1);
	    $$->code = $1->code;
}
		| continue_stmt
{
		$$ = add_new_node("stmt_body",$1);
	    $$->code = $1->code;
}
		;



func_call: ID LP paramlist RP
{
		$$ = add_new_node("func_call",$1,$2,$3,$4);
		
		func_tab_entry* call_name_ptr = search_func_tab($1->node_val);

		if(call_name_ptr != NULL)
		{	
			if(call_name_ptr->paramlist.size() == $3->paramlist.size())
			{
				int m = 1;

				for(int i = 0; i < $3->paramlist.size(); i++)
				{
					if($3->paramlist[i] != call_name_ptr->paramlist[i].eletype)
					{
						m = 0;
					}
				}
				if(m == 1)
				{
            		$$->code = $3->code + "jal func_" + call_name_ptr->name+"\n";
            		
            		$$->eletype = call_name_ptr->rettype;
				}
				else
				{
					cout<<"ERROR IN LINENO : "<<lineno<<"-->"<<"Parameter Type Mismatch"<<endl;
					
					$$->eletype = "errortype";
				}
			}
			else
			{
				
				$$->eletype = "errortype";
				cout<<"ERROR IN LINENO : "<<lineno<<"Number of Parameters mismatch\n"<<endl;
			}
		}
		else
		{
			
			$$->eletype = "errortype";
			cout<<"ERROR IN LINENO : "<<lineno<<"Function "<<$1->node_val<<" not found"<<endl;
		}
}
		;

paramlist: plist
{
		$$ = add_new_node("paramlist",$1);
    	$$->code = $1->code;
    	$$->paramlist = ($1->paramlist);
}
		|
{
		$$ = add_new_node("paramlist");
}
		;

plist: plist COMMA arithexpr
{
		$$ = add_new_node("plist",$1,$2,$3);
    	$$->index =$1->index + 1;
		($$->paramlist).insert(($$->paramlist).end(), ($1->paramlist).begin(), ($1->paramlist).end());
		($$->paramlist).push_back($3->eletype);
		string temp_code = $3->code + "move $a" + to_string($$->index) + ", $a0\n";
    	$$->code = temp_code + $1->code;
}
		|arithexpr
{
		$$ = add_new_node("plist",$1);
    	$$->index =0;
		($$->paramlist).push_back($1->eletype);
    	$$->code = $1->code + "move $a" + to_string($$->index) + ", $a0\n";
}
		;

empty :
{
    $$ = NULL;
}

;


%%
int main()
{
    yyparse();
}








