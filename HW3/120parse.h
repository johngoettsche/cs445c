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

void addParamsToFunction(TreeNode, NType);
void addMembersToClass(TreeNode *, NType *);

void passTypeBelowPointer(NType *, NType *);
void passAccessBelow(NType *, NType *);
NType *getType(int);
getOperatorType(NType *, NType *);

SymbolTable *createSymbolTable(SymbolTable, int);
SymbolTable *createGlobalSymbolTable(int);
SymbolTable *getSymbolTable(SymbolTable *, char *);
int hashSymbol(NType *, int);
int inSymbolTable(SymbolTable *, NType *);

void addSimpleDeclarations(SymbolTable *, NType *);
void addFunctionBodySymbols(SymbolTable *, TreeNode *);
void addToSymbolTable(SymbolTable *, NType *);