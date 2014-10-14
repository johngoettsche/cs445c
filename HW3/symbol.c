
SymbolTable *createSymbolTable(SymbolTable parent, int size){
	SymbolTable *symbolTable;
	if((symbolTable = (SymbolTable *)calloc(1, sizeof(SymbolTable))) == NULL) memoryError();
	symbolTable->parent = parent;
	symbolTable->size = size;
	if((symbolTable->bucket = (SymbolTableEntry *)calloc(size, sizeof(SymbolTableEntry))) == NULL) memoryError();
	
	return symbolTable;
}

SymbolTable *createGlobalSymbolTable(int size){
	SymbolTable *symbolTable;
	if((symbolTable = (SymbolTable *)calloc(1, sizeof(SymbolTable))) == NULL) memoryError();
	symbolTable->size = size;
	if((symbolTable->bucket = (SymbolTableEntry *)calloc(size, sizeof(SymbolTableEntry))) == NULL) memoryError();
	
	return symbolTable;
}