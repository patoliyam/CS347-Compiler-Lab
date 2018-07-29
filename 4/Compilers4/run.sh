bison --defines -v bisonfinal.y
flex lexfinal.lex
g++ -std=c++11 lex.yy.c bisonfinal.tab.c -g
./a.out < test.txt