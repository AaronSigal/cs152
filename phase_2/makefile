parser : mini_l.lex mini_l.y       # module for twiddling the frobs
	flex mini_l.lex
	bison -v -d -Wconflicts-sr --file-prefix=y mini_l.y
	gcc -o parser lex.yy.c y.tab.c -lfl

clean :
	rm lex.yy.c
	rm y.tab.*
	rm parser
	