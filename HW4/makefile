YACC=yacc
LEX=flex
CC=gcc

all: 120

.c.o:
	$(CC) -c $<

120: 120gram.o 120lex.o 120parse.o errors.o
	$(CC) -o 120 120gram.o 120lex.o 120parse.o errors.o

120gram.c 120gram.h: 120gram.y 
	$(YACC) -dt --verbose 120gram.y 
	mv -f y.tab.c 120gram.c
	mv -f y.tab.h 120gram.h

120lex.c: 120lex.l sdef.h token.h token.c errors.h errors.c
	$(LEX) -t 120lex.l >120lex.c

120lex.o: 120gram.h

120parse.o: 120parse.c 120parse.h
	$(CC) -c -g 120parse.c

errors.o: errors.h errors.c
	$(CC) -c errors.c

clean:
	rm -f 120 *.o
	rm -f 120lex.c 120gram.c 120gram.h
