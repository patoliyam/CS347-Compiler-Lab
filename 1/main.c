#include "lex.h"
#include "code_gen.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
void main()
{
    fp = fopen("Int_Code.txt","w"); 
    while(!match(EOI))
    {
        stmt();
    }
    fclose(fp);
}
