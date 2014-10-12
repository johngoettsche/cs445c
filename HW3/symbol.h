
#include "errors.h"

#define TYPE_NULL 100000
#define TYPE_INTEGER 100001

typedef struct Symbol Symbol;
struct Symbol{
	int type;
	char *label;
	/*union{
		struct IntegerType {
			int value;
		}intgr;
	}u;*/
};

typedef struct SymbolTableEntry SymbolTableEntry;
struct SymbolTableEntry{
	Symbol *s;
	//Type *type;
	SymbolTableEntry *next;
}

typedef struct SymbolTable SymbolTable;
struct SymbolTable{
	int size;
	int entries;
	//Type *scope;
	SymbolTable *parent;
	SymbolTableEntry **bucket;
};

SymbolTable createSymbolTable(SymbolTable, int);
