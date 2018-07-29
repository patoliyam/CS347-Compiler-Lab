  #include "lex.h"
  #include <stdio.h>
  #include <ctype.h>
  #include <string.h>

  char* yytext = ""; /* Lexeme (not '\0'
                        terminated)              */
  int yyleng   = 0;  /* Lexeme length.           */
  int yylineno = 0;  /* Input line number        */

extern FILE* fp;

  int lex(void){

    const char *keywords[10] = {"IFZ","GOTO"}; 
    int KEYWORD_SIZE = 2;
    static char input_buffer[1024];
    char *current;

    current = yytext + yyleng;

     while(1)
     {   
        while(!*current )
        {
           current = input_buffer;
           if(!fgets(input_buffer,1000,fp))
           {
              *current = '\0';
              return EOI;
           }
           ++yylineno;
           while(isspace(*current))
              ++current;
        }
        for(; *current; ++current){
           /* Get the next token */
           yytext = current;
           yyleng = 1;
           switch( *current ){
             case '+':
              return PLUS;
             case '-':
              return MINUS;
             case '*':
              return TIMES;
             case '/':
              return DIVIDE;
             case '<':
              return LT;
             case '>':
              return GT;
             case '=':
              return EQCOMP;
             case '\n':
             case '\t':
             case ' ' :
              break;
             default:
              {
                 while(isalnum(*current) || *current=='.' || *current==':' || *current=='_')
                 {
                    ++current;
                 }
                 yyleng = current - yytext;

                 char curword[10];
                 int i;
                 for( i=0; i<yyleng; ++i)
                 {
                    curword[i] = yytext[i];
                 }
                 curword[i] = '\0';
                 // printf("curword is : %s\n",curword);
                 for (i = 0; i<KEYWORD_SIZE;++i)
                 {
                  if (strcmp(keywords[i],curword)==0)
                    return (22+i);
                 }
                 int flag = 1;
                 int dotcnt = 0;
                 for(i =0; i<yyleng; i++)
                 {
                  if(curword[i] == '.')
                    dotcnt++;
                  else if(curword[i]-'0' < 0 || curword[i]-'0' > 9)
                    flag = 0;
                 }
                 if(flag == 1 && dotcnt <=1)
                 {
                    return NUM;
                 }
                 else
                 {
                    if(curword[0]=='t')
                    {
                      // printf("recog tempids\n");
                      return TEMPID;
                    }
                    else if (curword[0]=='L')
                    {
                      // printf("recoggnised LABELIDs\n");
                      return LABELID;
                    }
                    else
                    {
                      // printf("var recog\n");
                      return ID;
                    }
                 }
              }
           }
        }
     }
  }


  static int Lookahead = -1; /* Lookahead token  */

  int match(int token){
     /* Return true if "token" matches the
        current lookahead symbol.                */
     if(Lookahead == -1)
        Lookahead = lex();
    // printf("token:%d  lookahead: %d\n",token,Lookahead );
  
     return token == Lookahead;
  }

  void advance(void){
  /* Advance the lookahead to the next
     input symbol.                               */

      Lookahead = lex();
      // printf("Advanced text : %d\n", Lookahead);
  }