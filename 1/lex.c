  #include "lex.h"
  #include <stdio.h>
  #include <ctype.h>
  #include <string.h>


  char* yytext = ""; /* Lexeme (not '\0'
                        terminated)              */
  int yyleng   = 0;  /* Lexeme length.           */
  int yylineno = 0;  /* Input line number        */

  int lex(void){

    const char *keywords[10] = {"if","then","while","do","begin","end",":="}; 

    static char input_buffer[1024];
    char *current;

    current = yytext + yyleng;

     while(1)
     {   
        while(!*current )
        {
           current = input_buffer;
           if(!gets(input_buffer))
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
             case ';':
              return SEMI;
             case '+':
             {
              // printf("PLUS me aaya, text is %s\n", yytext);
              return PLUS;
             }
             case '-':
              return MINUS;
             case '*':
              return TIMES;
             case '/':
              return DIVIDE;
             case '(':
              return LP;
             case ')':
              return RP;
             case '<':
              return LT;
             case '>':
              return GT;
             case '=':
              return EQCOMP;
             case ':':
              {
                // printf("coming here\n");
                ++current;
                if(*current=='=')
                {
                  // printf("identified := \n");
                  // current++;
                  return EQ;
                }
                else
                {
                  printf("%s\n","error in :=" );
                  return -1;
                }
                break;
              }
             case '\n':
             case '\t':
             case ' ' :
              break;
             default:
              // if(!isalnum(*current) && *current!=':' && *current!='=')
              //    fprintf(stderr, "Not alphanumeric <%c>\n", *current);
              // else
              {
                 while(isalnum(*current) || *current=='.')
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
                 for (i = 0; i<7;++i)
                 {
                  if (strcmp(keywords[i],curword)==0)
                  {
                    // printf("%d\n",11+i);
                    return (11+i);
                  }
                 }
                 int flag = 1;
                 int dotcnt = 0;
                 for(i =0; i<yyleng; i++)
                 {
                  if(curword[i] == '.')
                  {
                    dotcnt++;
                  }
                  else if(curword[i]-'0' < 0 || curword[i]-'0' > 9)
                  {
                    // printf("Char : %c\n",curword[i] );
                    flag = 0;
                  }
                 }
                 // printf("flag %d\n", flag);
                 // printf("Dotcnt %d\n", dotcnt);
                 if(flag == 1)
                 {
                  if(dotcnt <= 1)
                  {
                    // printf("float aaya\n");
                    return NUM;
                  }
                  else
                  {
                    printf("paospaosas\n");
                    return -3;
                  }
                 }
                 else
                 {
                  if((curword[0]-'a' >= 0 && curword[0]-'a' <= 25) || (curword[0]-'A' >= 0 && curword[0]-'A' <= 25) || curword[0] == '_')
                  {
                    if(dotcnt == 0)
                      return ID;
                    else
                      return -2;
                  }
                  else
                  {
                    // printf("Meet ka error\n");
                    return -2;
                  } 
                  
                 }
              }
              break;
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