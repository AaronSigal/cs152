sudo flex ./mini_1.lex
sudo bison -v -d --file-prefix=y mini_l.y
sudo gcc -o parser lex.yy.c y.tab.c -lfl