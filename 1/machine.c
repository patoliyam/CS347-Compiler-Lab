#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lex.h"
#include "machine_lex.c"

int search_in_sym_table(char* );
int alloc_mem_to_symbol();
int get_register_no();
int get_num();

char* symbol_table[1024];
int tail;
int label;
int rel_jmp;
FILE *fp, *fp2;

void get_machine_code()
{	
	// printf("into machine code\n");
	while( !match (EOI) )
	{
		if ( match(LABELID) )
		{
			//print label
			fprintf(fp2, "%s", yytext);
			advance();
			// advance();
			// advance();
		}
		else if( match(GOTO) )
		{
			advance();
			// get label string
			// print JP label
			fprintf(fp2, "JMP %s",yytext);
			advance();
		}
		else if( match(IFZ) )
		{
			advance();
			int operand1 = get_register_no();
			// mov operand one to accumulator
			// MOV A 00
			// CMP A operand1
			//
			fprintf(fp2, "MVI A, 1\n");
			fprintf(fp2, "CMP %d\n",operand1);
			advance();
			if( match(GOTO) )
			{
				advance();
				if( match(LABELID) )
				{
					// get_label_no
					//print jnz label1
					fprintf(fp2, "JNZ %s\n",yytext);
					// JZ Label1
					advance();
					// advance();
				}
				
			}
		}
		//t0 += t1/3
		//t0 -= t1/3
		//t0 *= t1/3
		//t0 /= t1/3
		//t0 = t1/3
		else if( match(TEMPID) )
		{
			// fprintf(fp2,"into TEMPID\n");
			int operand1 = get_register_no();
			advance();
			if(match(PLUS))
			{
				advance();
				advance();
				if(match(TEMPID))
				{
					//getregister number
					int operand2 = get_register_no();
					fprintf(fp2, "LDA %d\n", operand1);
					fprintf(fp2, "ADD %d\n",operand2);
					fprintf(fp2, "MOV %d,A\n", operand1);
					advance();
				}
				else if(match(NUM))
				{
					int curnumber = get_num();
					fprintf(fp2, "LDA %d\n", operand1);
					fprintf(fp2, "ADI %d\n",curnumber);
					fprintf(fp2, "MOV %d,A\n", operand1);
					advance();	
				}
			}
			else if(match(MINUS))
			{
				advance();
				advance();
				if(match(TEMPID))
				{
					//getregister number
					int operand2 = get_register_no();
					fprintf(fp2, "LDA %d\n", operand1);
					fprintf(fp2, "SUB %d\n",operand2);
					fprintf(fp2, "MOV %d,A\n", operand1);
					advance();
				}
				else if(match(NUM))
				{
					int curnumber = get_num();
					fprintf(fp2, "LDA %d\n", operand1);
					fprintf(fp2, "SUI %d\n",curnumber);
					fprintf(fp2, "MOV %d,A\n", operand1);
					advance();	
				}
			}
			else if(match(EQCOMP))
			{
				advance();
				if(match(TEMPID))
				{
					int operand2 = get_register_no();	
					advance();
					if (match(LT))
					{
						advance();
						if(match(TEMPID))
						{
							int operand3 = get_register_no();
							fprintf(fp2,"LDA %d\n", operand2 );
							fprintf(fp2,"CMP %d\n", operand3 );
							//jump on condn true
							fprintf(fp2,"JC K%d\n", label);
							//if false here we set operand to 0
							fprintf(fp2,"MOV %d, 0\n", operand1 );
							label++;
							fprintf(fp2,"JMP K%d\n", label);
							//label for true
							fprintf(fp2,"K%d : MOV %d, 1\n", label-1, operand1);
							//label for false
							fprintf(fp2,"K%d : 	\n", label );
							label++;
						}						
					}
					else if (match(GT))
					{
						advance();
						if(match(TEMPID))
						{
							int operand3 = get_register_no();
							fprintf(fp2,"LDA %d\n", operand2 );
							fprintf(fp2,"CMP %d\n", operand3 );
							fprintf(fp2,"JC K%d\n", label);
							fprintf(fp2,"MOV %d, 1\n", operand1 );
							label++;
							fprintf(fp2,"JMP K%d\n", label);
							fprintf(fp2,"K%d : MOV %d, 0\n", label-1, operand1);
							fprintf(fp2,"K%d : 	\n", label );
							label++;
						}
					}
					else if(match(EQCOMP))
					{
						advance();
						if(match(TEMPID))
						{
							int operand3 = get_register_no();
							fprintf(fp2,"LDA %d\n", operand2 );
							fprintf(fp2,"CMP %d\n", operand3 );
							fprintf(fp2,"JZ K%d\n", label);
							fprintf(fp2,"MOV %d, 1\n", operand1);
							label++;
							fprintf(fp2,"JMP K%d\n", label);
							fprintf(fp2,"K%d : MOV %d, 0\n", label-1, operand1);
							fprintf(fp2,"K%d : 	\n", label );
							label++;
						}
					}
					else
					{					
						fprintf(fp2, "LDA %d\n", operand2);
						fprintf(fp2, "MOV %d,A\n", operand1);

					}
				}
				else if(match(NUM))
				{
					int curnumber = get_num();
					fprintf(fp2, "MOV %d,%d\n", operand1,curnumber);
					advance();	
				}
			}
			else if (match(TIMES))
			{
				// fprintf(fp2,"in multiply\n");
				advance();
				advance();
				if(match(TEMPID))
				{
					//getregister number
					int operand2 = get_register_no();
					fprintf(fp2, "LDA %d\n", operand1);
					fprintf(fp2, "MUL %d\n",operand2);
					fprintf(fp2, "MOV %d,A\n", operand1);
					advance();
				}
				else if(match(NUM))
				{
					int curnumber = get_num();
					fprintf(fp2, "LDA %d\n", operand1);
					fprintf(fp2, "MLI %d\n",curnumber);
					fprintf(fp2, "MOV %d,A\n", operand1);
					advance();	
				}
			}
			else if (match(DIVIDE))
			{
				advance();
				advance();
				if(match(TEMPID))
				{
					//getregister number
					int operand2 = get_register_no();
					fprintf(fp2, "LDA %d\n", operand1);
					fprintf(fp2, "DIV %d\n",operand2);
					fprintf(fp2, "MOV %d,A\n", operand1);
					advance();
				}
				else if(match(NUM))
				{
					int curnumber = get_num();
					fprintf(fp2, "LDA %d\n", operand1);
					fprintf(fp2, "DVI %d\n",curnumber);
					fprintf(fp2, "MOV %d,A\n", operand1);
					advance();	
				}
			}
		}
		// _a = t0
		else if(match(ID))
		{
			int operand1 = alloc_mem_to_symbol();
			advance();
			if (match(EQCOMP))
			{
				advance();
				if (match(TEMPID))
				{
					int operand2 = get_register_no();
					fprintf(fp2, "LDA %d\n",operand2 );
					fprintf(fp2, "STA %d\n",operand1 );
					advance();
				}
			}
		}		
	}
}


int search_in_sym_table(char* a)
{
	int t=0;
	while(t < tail)
	{
		if(strcmp(symbol_table[t], a) == 0)
			return t;
		t++;
	}
	return -1;
}

int alloc_mem_to_symbol()
{
	char subbuff[yyleng+1];
	int memory_no;
    memcpy( subbuff, yytext, yyleng );
    subbuff[yyleng] = '\0';
	memory_no = search_in_sym_table(subbuff);
	if(memory_no == -1)
	{
		symbol_table[tail] = (char *)malloc(yyleng+1);
		memcpy( symbol_table[tail], subbuff, yyleng+1 );
    	fprintf(fp2, "MVI A, 0\n");
    	fprintf(fp2, "STA %d\n", tail*2+610);
    	memory_no = tail;
		tail++;
	}
	return memory_no*2+610;
}

int get_register_no()
{
	return ((*(yytext+1)-48)*2)+600;
}

int get_num()
{
	
    char subbuff[yyleng+1];
    memcpy( subbuff, yytext, yyleng );
    subbuff[yyleng] = '\0';
	return atoi(subbuff);
}
int main()
{
	fp = fopen("Int_Code.txt", "r");
	fp2 = fopen("machine_8085.txt", "w");
	get_machine_code();
	fprintf(fp2, "HLT\n");
	fclose(fp);
	fclose(fp2);
}