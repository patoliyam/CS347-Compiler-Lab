bison --defines -v bisonfinal.y
flex lexfinal.lex
g++ lex.yy.c bisonfinal.tab.c -g
./a.out < test.txt