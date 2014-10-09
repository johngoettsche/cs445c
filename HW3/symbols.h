
#ifndef SYMTAB_H
#define SYMTAB_H

#include "types.h"

typedef struct SymbolTable SymbolTable;
struct SymbolTable {
	int buckets;
	int entities;
	SymbolTable *parent;
	typeptr scope;
	SymbolTableEntry **table
};

typedef struct SymbolTableEntry SymbolTableEntry;
struct SymbolTableEntry {
	SymbolTable table;
	char *s;
	SymbolType *type;
	SymbolTableEntry *next;
};

/*
 * Prototypes
 */
SymbolTable new_st(int size);			/* create symbol table */
void delete_st(SymbolTable);			/* destroy symbol table */
char *insert_stringpool(char *);		/* enter string into pool */
char *install_sym(SymbolTable, char *, typeptr);/* enter string into table */
int insert_sym(SymbolTable, char *, typeptr);	/* enter symbol into table */
SymbolTableEntry lookup_st(SymbolTable, char *); /* lookup symbol */

extern SymbolTable stringpool;	       /* all idents seen in entire program */
extern SymbolTable globals;	       /* global symbols */
extern SymbolTable current;	       /* current */

extern void printsymbols(SymbolTable st, int level);

#define pushscope(stp) do { stp->parent = current; current = stp; } while (0)
#define popscope() do { current = current->parent; } while(0)

#endif					/* SYMTAB_H */