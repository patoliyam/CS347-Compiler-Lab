#include <stdlib.h>
#include <stdio.h>
#define NO_OF_REG 8

char  *Names[] = { "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7" };   
char  **Namep  = Names;   

char  *newname()   
{   
    if( Namep >= &Names[ sizeof(Names)/sizeof(*Names) ] )   
    {   
        printf( "%d: Expression too complex\n", yylineno );   
        exit( 1 );   
    }   
   
    return( *Namep++ );   
}   
   
void freename(char *s)
{   
    if( Namep > Names )   
    *--Namep = s;   
    else   
    printf( "%d: (Internal error) Name stack underflow\n",   
                                yylineno );   
}   

void freeall()
{
    Namep  = Names;   
}
