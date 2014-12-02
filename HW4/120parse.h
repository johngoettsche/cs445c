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
char *humanreadable(int);
void printTree(TreeNode *t, int depth, int b);
NType *getType(int tcode);
SymbolTable *createSymbolTable(SymbolTable *parent, int size);
SymbolTable *getSymbolTable(SymbolTable *currentSymbolTable, char *tableName);
int hashSymbol(NType *symb, int size);
int inSymbolTable(SymbolTable *symbolTable, NType *symb);
NType * checkClassesForSymbol(SymbolTable *symbolTable, NType *symb);
NType *getSymbolFromTable(SymbolTable *symbolTable, NType *symb);
NType *getClass(SymbolTable* symbolTable, char *clas);
int getBits(NType *symb, int bits);
void calculateOffsets(SymbolTable *symbolTable);
void addToSymbolTable(SymbolTable *symbolTable, NType *symb, int mode);
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

void addToSymbolTableList(SymbolTable *currentSymbolTable, NType *current, int mode);
void addSimpleDeclarations(SymbolTable *currentSymbolTable, NType *current, int mode);
void addFunctionBodySymbols(SymbolTable *currentSymbolTable, TreeNode *node, int mode);
void makeSymbolTables(TreeNode *node);
CodeElem *createCodeElement();
IntrCode *createIntrCode();
NType *createTempSymbol(NType *source, int lab, int mode);
Location *makeLocation(NType *source);
IntrCode *makePairedExpression(int code, NType *child1, NType *child2, int mode);
IntrCode *concatCode(IntrCode *front, IntrCode *back);
void setBreaksAndContinues(IntrCode *intCode, IntrCode *brk, IntrCode *cont);
void intermediateCodeGeneration(TreeNode *node);
