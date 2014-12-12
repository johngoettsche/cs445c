/*
 * John Goettsche
 * CS445
 *
 * 120parse.h 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/* prototypes */
char *humanreadable(int ncode);
void printTree(TreeNode *t, int depth, int b);
void printSymbolTables(SymbolTable *symbolTable);
SymbolTable *getSymbolTable(SymbolTable *currentSymbolTable, char *tableName);
char *findLocation(SymbolTable *symbolTable, int offset);
void printLocation(Location * loc);
void printCode(TreeNode *node);
NType *getType(int tcode);
void passSymbolTableDownTree(SymbolTable *symbolTable, TreeNode *node);
SymbolTable *createSymbolTable(SymbolTable *parent, int size);
int hashSymbol(NType *symb, int size);
int inSymbolTable(SymbolTable *symbolTable, NType *symb);
NType * checkClassesForSymbol(SymbolTable *symbolTable, NType *symb);
NType *getSymbolFromTable(SymbolTable *symbolTable, NType *symb);
NType *getClass(SymbolTable* symbolTable, char *clas);
 int getBits(NType *symb, int bits);
void calculateOffsets(SymbolTable *symbolTable);
void addToSymbolTable(SymbolTable *symbolTable, NType *symb, int mode);
void addToSymbolTableList(SymbolTable *currentSymbolTable, NType *current, int mode);
void addLibrariesData();
NType *getOperatorType(NType *op1, NType *op2, int tp);
NType *checkType(NType *op1, NType *op2);
void copyType(NType *source, NType *dest);
void passTypeBelowPointer(NType *source, NType *dest);
void passTypeToDeclarationList(NType *source, TreeNode *dest);
void passAccessBelow(NType *source, NType *dest);
void addParamsToFunction(TreeNode *node, NType *param);
void addMembersToClass(TreeNode *node, NType *member);
CodeElem *getLabel();
void buildTypes(TreeNode *node){void addSimpleDeclarations(SymbolTable *currentSymbolTable, NType *current, int mode);
NType *createTempSymbol(NType *source, int lab, int mode);
NType *addToStringList(NType *source, int mode);
char *cvnIntString(char *str);
Location *makeLocation(NType *source);
void addFunctionBodySymbols(SymbolTable *currentSymbolTable, TreeNode *node, int mode);
void makeSymbolTables(TreeNode *node);
IntrCode *makeLabel();
CodeElem *createCodeElement();
IntrCode *createIntrCode();
IntrCode *makePairedExpression(int code, NType *child1, NType *child2, int mode);
IntrCode *concatCode(IntrCode *front, IntrCode *back);
void setBreaksAndContinues(IntrCode *intCode, IntrCode *brk, IntrCode *cont);
void intermediateCodeGeneration(TreeNode *node);
