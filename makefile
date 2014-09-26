YACC=yacc
LEX=flex

all: 120

.c.o:
	cc -c $<

120: 120gram.o 120lex.o
	cc -o 120 120gram.o 120lex.o

120gram.c 120gram.h: 120gram.y
	$(YACC) -dt --verbose 120gram.y
	mv -f y.tab.c 120gram.c
	mv -f y.tab.h 120gram.h

120lex.c: 120lex.l
	$(LEX) -t 120lex.l >120lex.c

120lex.o: 120gram.h

clean:
	rm -f 120 *.o
	rm -f 120lex.c 120gram.c 120gram.h
	