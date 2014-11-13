/*
 * John Goettsche
 * CS445
 *
 * codegen.h 
 */
 
 int getBits(NType *symb, int bits){
	SymbolListItem *item;
	int i;
	switch(symb->base_type){
		case CHAR_TYPE : 
			bits += 1;
			break;
		case CLASS_TYPE :
			for(i = 0; i < symb->u.clas.nfields; i++){
				printf("-");
				bits += getBits(symb->u.clas.f[i]->elemtype, bits);
			}
			item = symb->symbTable->list->head;
			while(item != NULL){
				printf("+");
				bits += getBits(item->item, bits);
				item = item->next;
			}
			break;
		case FUNC_TYPE :
			bits += 8;
			for(i = 0; i < symb->u.func.nargs; i++){
				bits += getBits(symb->u.func.args[i]->elemtype, bits);
			}
			item = symb->symbTable->list->head;
			while(item != NULL){
				bits += getBits(item->item, bits);
				item = item->next;
			}
		default :
			bits += 8;
	}
	return bits;
}

void calculateOffsets(SymbolTable *symbolTable){
	
	int i;
	switch(symbolTable->scope->base_type){
		case PROGRAM_TYPE :
			item = symbolTable->list->head; 
			while(item != NULL){
				item->offset = symbolTable->offset;
				item->item->offset = symbolTable->offset;
				symbolTable->offset += getBits();
			}
			break;
		case CONSTRUCTOR_TYPE :
		case FUNC_TYPE :		
			for(i = 0; i < symbolTable->scope->u.func.nargs; i++){
				symbolTable->scope->u.func.args[i]->type->offset = symbolTable->offset;
				symbolTable->offset += getBits();
			}
			item = symbolTable->list->head; 
			while(item != NULL){
				item->offset = symbolTable->offset;
				item->item->offset = symbolTable->offset;
				symbolTable->offset += getBits();
			}
			break;
		case CLASS_TYPE :			
			for(i = 0; i < symbolTable->scope->u.clas.nfields; i++){
				symbolTable->scope->u.func.args[i]->type->offset = symbolTable->offset;
				symbolTable->offset += getBits();
			}
			item = symbolTable->list->head; 
			while(item != NULL){
				item->offset = symbolTable->offset;
				item->item->offset = symbolTable->offset;
				symbolTable->offset += getBits();
			}
			break;
	}
	for(t = 0; t < symbolTable->children; t++){
		printSymbolTables(symbolTable->child[t]);
	}
 }