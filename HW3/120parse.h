/*
 * John Goettsche
 * CS445
 *
 * 120parse.h 
 */


/* prototypes */
char *humanreadable(int);
void printTree(TreeNode *, int);
char *humanreadable(int);
TreeNode *alacnary(int, int,...);
NType *getType(int);
SymbolTable *createSymbolTable(SymbolTable, int);
SymbolTable *createGlobalSymbolTable(int);
int hashSymbol(NType *, int);
int inSymbolTable(SymbolTable *, NType *);
void addToSymbolTable(SymbolTable *, NType *);