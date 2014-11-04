/*
 * John Goettsche
 * CS445
 *
 * 120parse.h 
 */


/* prototypes */
char *humanreadable(int);
void printTree(TreeNode *t, int depth, int b);
TreeNode *alacnary(int prodRule, int children,...);
NType *getType(int tcode);
SymbolTable *createSymbolTable(SymbolTable *parent, int size);
SymbolTable *createGlobalSymbolTable(int size);
SymbolTable *getSymbolTable(SymbolTable *currentSymbolTable, char *tableName);
int hashSymbol(NType *symb, int size);
int inSymbolTable(SymbolTable *symbolTable, NType *symb);
NType *getSymbolFromTable(SymbolTable *symbolTable, NType *symb);
NType *getClass(SymbolTable* symbolTable, char *clas);
void addToSymbolTable(SymbolTable *symbolTable, NType *symb);
void addLibrariesData();
NType *getOperatorType(NType *op1, NType *op2);
NType *checkType(NType *op1, NType *op2);
void copyType(NType *source, NType *dest);
void addSimpleDeclarations(SymbolTable *currentSymbolTable, NType *current);
void addFunctionBodySymbols(SymbolTable *currentSymbolTable, TreeNode *node);
void makeSymbolTables(TreeNode *node);
