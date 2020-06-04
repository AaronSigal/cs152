parser : mini_l.lex mini_l.y       # module for twiddling the frobs
	bison -v -d --file-prefix=y mini_l.y
	flex mini_l.lex
	g++ -std=c++11 -Wno-write-strings -g -o compiler y.tab.c lex.yy.c -lfl

clean :
	rm lex.yy.c
	rm y.tab.*
	rm parser
	rm compiler
	rm y.output
	