#include "lex.c"
#include "name.c"    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int label_index;

void stmt();
char* expr();
char* term();
char* factor();
char* expr2();
char* term2();
char* term1(char* prev);
char* factor2();
char* expr1(char* prev);
char* exprc();
void exprcwhile();
void opt_stmts();
void stmt_list();

extern FILE *fp;

void stmt()
{
   /*  statements -> exprression SEMI  | 
    exprression SEMI statements  */
    int temp_index;
    if(match(IF))
    {
        advance();
        char* tempvar=exprc();
        fprintf(fp , "\tIFZ %s goto L%d\n",tempvar,label_index);
        temp_index=label_index;
        label_index++;
        freename(tempvar);
        if(match(THEN))
        {
            advance();
            stmt();
            fprintf(fp,"L%d:\n",temp_index);

        }
        else
        {
            printf("%d:SYNTAX:missing then after if \n",yylineno );
        }
    } 
    else if(match(WHILE))
    {
        advance();
        fprintf(fp,"L%d:\n",label_index);
        temp_index=label_index;
        label_index++;
        char* tempvar=exprc();
        fprintf(fp,"\tIFZ %s goto L%d\n",tempvar,label_index);
        if(match(DO))
        {
            advance();
            stmt();
            fprintf(fp,"\tgoto L%d\n", temp_index);
            fprintf(fp,"L%d:\n", label_index);
        }
        else
        {
            printf("%d:SYNTAX:missing do in while loop\n", yylineno);
        }
    }
    else if(match(BEGIN))
    {
        advance();
        while(!match(END) && !match(EOF))
            stmt();
        if(match(EOF))
            printf("%d: no end statement after Begin\n", yylineno);
        else
            advance();
        return;
    }
    

    else
    {
        expr();
        freeall();
        if( match( SEMI ) )
        {
            advance();
        }
        else if(match(-3))
        {
            printf("%d : Number invalid\n", yylineno);
            while(!match(SEMI))
            {
                advance();
            }
        }
        else if(match(-2))
        {
            printf("%d : Variable name invalid\n", yylineno);
            while(!match(SEMI))
            {
                advance();
            }
        }
        else
        {    
            printf("%d: Some error in expr / semicolon not found\n", yylineno );
            while(!match(SEMI))
            {
                advance();
            }
        }
    }
}
char* expr()
{
    // term will never will e (will never return NULL)
    char * tempvar=term();
    if(tempvar!=NULL)
        return expr1(tempvar);
    return NULL;
}
char* term()
{
    // factor will never will e (will nevver return NULL)
    char* tempvar=factor();
    if(tempvar!=NULL)
        return term1(tempvar);
    else
        return NULL;
}

char* factor()
{
    char *tempvar;
    char *tempid;

    if( match(LP) )
    {
        advance();
        tempvar = expr2();
        if( match(RP) )
            advance();
        else
            printf("%d: Mismatched parenthesis\n", yylineno );
        return tempvar;
    }
    else if( match(NUM))
    {
        fprintf(fp,"\t%s = %0.*s\n", tempvar = newname(), yyleng, yytext );
        advance();
        return tempvar;
    }
    else if(match(ID))
    {   
        tempid = (char  *)malloc((yyleng+1)*sizeof(char));
        for (int i = yyleng-1;i>=0;i--)
        {
            tempid[i+1] = yytext[i];
            tempid[0] = '_';
        }
        tempid[yyleng+1] = '\0';
        advance();
        if(match(EQ))
        {
            advance();
            advance();
            char* rightside=expr();
            fprintf(fp,"\t%s = %s\n",tempid,rightside);   
            return rightside;
        }
        else
        {
            fprintf(fp,"\t%s = %s\n", tempvar = newname(),tempid);
            return tempvar;
        }
    }

    else
    {   
        return NULL;
    }
}

char* expr2()
{
    char * tempvar=term2();
    if(tempvar!=NULL)
        return expr1(tempvar);
    return NULL;
}
char* term2()
{
    char* tempvar=factor2();
    if(tempvar!=NULL)
        return term1(tempvar);
    return NULL;
}

char* term1(char* prev)
{
    char* tempvar;
    if(match(TIMES))
    {
        advance();
        tempvar=factor2();
        fprintf(fp,"\t%s *= %s\n", prev, tempvar );
        freename(tempvar);
        return term1(prev);
    }
    else if(match(DIVIDE))
    {
        advance();
        tempvar=factor2();
        fprintf(fp,"\t%s /= %s\n", prev, tempvar );
        freename(tempvar);
        return term1(prev);
    }
    return prev;
}

char* factor2()
{
    char* tempvar;
    char tempid[25];
    if(match(NUM))
    {
        fprintf(fp,"\t%s = %0.*s\n", tempvar = newname(), yyleng, yytext );
        advance();
        return tempvar;
    }
    else if(match(ID))
    {
        for (int i = yyleng-1;i>=0;i--)
        {
            tempid[i+1] = yytext[i];
            tempid[0] = '_';
        }
        tempid[yyleng+1] = '\0';

        if(match(EQ))
        {
            advance();
            advance();
            tempvar=expr();
        }
        else
        {   
            fprintf(fp,"\t%s = %s\n", tempvar = newname(),tempid);
            advance();
        }
        return tempvar;
    }

    else if( match(LP))
    {
        advance();
        tempvar=expr();
        if( match(RP) )
            advance();
        else
            printf("%d: Mismatched parenthesis\n",yylineno );
        return tempvar;
    }
    else
    {
       return NULL;
    }
}

char* expr1(char* prev)
{
    char* tempvar;
    if(match(PLUS))
    {   
        advance();
        tempvar=term2();
        fprintf(fp,"\t%s += %s\n", prev, tempvar );
        freename(tempvar);
        return expr1(prev);
    }
    else if(match(MINUS))
    {
        advance();
        tempvar=term2();
        fprintf(fp,"\t%s -= %s\n", prev, tempvar );
        freename(tempvar);
        return expr1(prev);
    }
    return prev;
}

char* exprc()
{
    char* tempvar1=expr2();
    if(match(GT) || match(LT) || match(EQCOMP))
    {
        char symbol =*yytext;
        advance();
        char* tempvar2=expr2(); 
        
        fprintf(fp,"\t%s=%s %c %s\n",tempvar1,tempvar1,symbol,tempvar2);
        freename(tempvar2);
        return tempvar1;
    }
    else
    {
        printf("%d:SYNTAX:missing operand\n", yylineno);
        return NULL;
    }
}
