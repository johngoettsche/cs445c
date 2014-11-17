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
NType * checkClassesForSymbol(SymbolTable *symbolTable, NType *symb);
NType *getSymbolFromTable(SymbolTable *symbolTable, NType *symb);
NType *getClass(SymbolTable* symbolTable, char *clas);
int getBits(NType *symb, int bits);
void calculateOffsets(SymbolTable *symbolTable);
void addToSymbolTable(SymbolTable *symbolTable, NType *symb);
void addLibrariesData();
NType *getOperatorType(NType *op1, NType *op2);
NType *checkType(NType *op1, NType *op2);
void copyType(NType *source, NType *dest);
void passTypeBelowPointer(NType *source, NType *dest);
void passTypeToDeclarationList(NType *source, TreeNode *dest);
void passAccessBelow(NType *source, NType *dest);
void addParamsToFunction(TreeNode *node, NType *param);
void addMembersToClass(TreeNode *node, NType *member);
CodeElem *getLabel();
void addToSymbolTableList(SymbolTable *currentSymbolTable, NType *current);
void addSimpleDeclarations(SymbolTable *currentSymbolTable, NType *current);
void addFunctionBodySymbols(SymbolTable *currentSymbolTable, TreeNode *node);
void makeSymbolTables(TreeNode *node);
IntrCode *createIntrCode();
NType *createTempSymbol(NType *source, char *pre);
Location *makeLocation(NType *source);
IntrCode *makePairedExpression(int code, NType *child1, NType *child2);
IntrCode *concatCode(IntrCode *front, IntrCode *back);
void intermediateCodeGeneration(TreeNode *node);
