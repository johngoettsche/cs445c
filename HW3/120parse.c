/*
 * John Goettsche
 * CS445
 *
 * 120parse.c 
 */
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "sdef.h"
#include "errortab.h"
#include "parsedef.h"
#include "types.h"
#include "120gram.h"

#define SHOW_TREES 0

//#define SYMBOL_TABLE_SIZE 31

extern int exitStatus;
extern TreeNode *root;
extern SymbolTable *currentSymbolTable;
extern SymbolTable *globalSymbolTable;

extern int using_namespace_std;
extern int included_iostream;
extern int included_cstdlib;
extern int included_ctime; 
extern int included_string;
extern int included_fstream;
extern int included_stdio; 
extern int included_stdlib;

char *humanreadable(int ncode){
	if(ncode >= 1000 && ncode < 20000)ncode = (int)(ncode / 100) * 100;
	char *name;
	switch (ncode) {
		case IDENTIFIER: name =  "IDENTIFIER"; break;
		case INTEGER: name =  "INTEGER"; break;
		case FLOATING: name =  "FLOATING"; break;
		case CHARACTER: name =  "CHARACTER"; break;
		case STRING: name =  "STRING"; break;
		case TYPEDEF_NAME: name =  "TYPEDEF_NAME"; break;
		case NAMESPACE_NAME: name =  "NAMESPACE_NAME"; break;
		case CLASS_NAME: name =  "CLASS_NAME"; break;
		case ENUM_NAME: name =  "ENUM_NAME"; break;
		case TEMPLATE_NAME: name =  "TEMPLATE_NAME"; break;
		case ELLIPSIS: name =  "ELLIPSIS"; break;
		case COLONCOLON: name =  "COLONCOLON"; break; 
		case DOTSTAR: name =  "DOTSTAR"; break; 
		case ADDEQ: name =  "ADDEQ"; break; 
		case SUBEQ: name =  "SUBEQ"; break; 
		case MULEQ: name =  "MULEQ"; break; 
		case DIVEQ: name =  "DIVEQ"; break; 
		case MODEQ: name =  "MODEQ"; break;
		case XOREQ: name =  "XOREQ"; break; 
		case ANDEQ: name =  "ANDEQ"; break;  
		case OREQ: name =  "OREQ"; break; 
		case SL: name =  "SL"; break; 
		case SR: name =  "SR"; break; 
		case SREQ: name =  "SLEQ"; break; 
		case SLEQ: name =  "SLEQ"; break;
		case EQ: name =  "EQ"; break;
		case NOTEQ  : name =  "NOTEQ"; break;
		case LTEQ  : name =  "LTEQ"; break;
		case GTEQ  : name =  "GTEQ"; break;
		case ANDAND  : name =  "ANDAND"; break;
		case OROR : name =  "OROR" ; break;
		case PLUSPLUS  : name =  "PLUSPLUS"; break;
		case MINUSMINUS  : name =  "MINUSMINUS"  ; break;
		case ARROWSTAR  : name =  "ARROWSTAR"  ; break;
		case ARROW : name =  "ARROW" ; break;
		case ASM  : name =  "ASM"  ; break;
		case AUTO  : name =  "AUTO"  ; break;
		case BOOL  : name =  "BOOL"  ; break;
		case BREAK  : name =  "BREAK"  ; break;
		case CASE  : name =  "CASE"  ; break;
		case CATCH  : name =  "CATCH"  ; break;
		case CHAR  : name =  "CHAR"  ; break;
		case CLASS  : name =  "CLASS"  ; break;
		case CONST  : name =  "CONST"  ; break;
		case CONST_CAST  : name =  "CONST_CAST"  ; break;
		case CONTINUE : name =  "CONTINUE" ; break;
		case DEFAULT  : name =  "DEFAULT"  ; break;
		case DELETE  : name =  "DELETE"  ; break;
		case DO  : name =  "DO"  ; break;
		case DOUBLE  : name =  "DOUBLE"  ; break;
		case DYNAMIC_CAST  : name =  "DYNAMIC_CAST"  ; break;
		case ELSE  : name =  "ELSE"  ; break;
		case ENUM  : name =  "ENUM"  ; break;
		case EXPLICIT  : name =  "EXPLICIT"  ; break;
		case EXPORT  : name =  "EXPORT"  ; break;
		case EXTERN : name =  "EXTERN" ; break;
		case FALSE : name =  "FALSE" ; break;
		case FLOAT  : name =  "FLOAT"  ; break;
		case FOR  : name =  "FOR"  ; break;
		case FRIEND  : name =  "FRIEND"  ; break;
		case GOTO  : name =  "GOTO"  ; break;
		case IF  : name =  "IF"  ; break;
		case INLINE  : name =  "INLINE"  ; break;
		case INT  : name =  "INT"  ; break;
		case LONG  : name =  "LONG"  ; break;
		case MUTABLE  : name =  "MUTABLE"  ; break;
		case NAMESPACE  : name =  "NAMESPACE"  ; break;
		case NEW : name =  "NEW" ; break;
		case OPERATOR  : name =  "OPERATOR"  ; break;
		case PRIVATE  : name =  "PRIVATE"  ; break;
		case PROTECTED  : name =  "PROTECTED"  ; break;
		case PUBLIC  : name =  "PUBLIC"  ; break;
		case REGISTER  : name =  "REGISTER"  ; break;
		case REINTERPRET_CAST  : name =  "REINTERPRET_CAST"  ; break;
		case RETURN : name =  "RETURN" ; break;
		case SHORT  : name =  "SHORT"  ; break;
		case SIGNED  : name =  "SIGNED"  ; break;
		case SIZEOF  : name =  "SIZEOF"  ; break;
		case STATIC  : name =  "STATIC"  ; break;
		case STATIC_CAST  : name =  "STATIC_CAST"  ; break;
		case STRUCT  : name =  "STRUCT"  ; break;
		case SWITCH  : name =  "SWITCH"  ; break;
		case TEMPLATE  : name =  "TEMPLATE"  ; break;
		case THIS : name =  "THIS" ; break;
		case THROW  : name =  "THROW"  ; break;
		case TRUE : name =  "TRUE" ; break;
		case TRY  : name =  "TRY"  ; break;
		case TYPEDEF  : name =  "TYPEDEF"  ; break;
		case TYPEID  : name =  "TYPEID"  ; break;
		case TYPENAME  : name =  "TYPENAME"  ; break;
		case UNION  : name =  "UNION"  ; break;
		case UNSIGNED  : name =  "UNSIGNED"  ; break;
		case USING  : name =  "USING"  ; break;
		case VIRTUAL : name =  "VIRTUAL" ; break;
		case VOID  : name =  "VOID"  ; break;
		case VOLATILE  : name =  "VOLATILE"  ; break;
		case WCHAR_T  : name =  "WCHAR_T"  ; break;
		case WHILE  : name =  "WHILE"  ; break;
		case STR_TYPE : name =  "STR_TYPE" ; break;
		case typedef_name  : name =  "typedef_name"  ; break;
		case namespace_name  : name =  "namespace_name"  ; break;
		case original_namespace_name  : name =  "original_namespace_name"  ; break;
		case class_name  : name =  "class_name"  ; break;
		case enum_name  : name =  "enum_name"  ; break;
		case template_name : name =  "template_name" ; break;
		case identifier  : name =  "identifier"  ; break;
		case literal  : name =  "literal"  ; break;
		case integer_literal  : name =  "integer_literal"  ; break;
		case character_literal  : name =  "character_literal"  ; break;
		case floating_literal  : name =  "floating_literal"  ; break;
		case string_literal : name =  "string_literal" ; break;
		case boolean_literal  : name =  "boolean_literal"  ; break;
		case translation_unit : name =  "program" ; break;
		case primary_expression  : name =  "primary_expression"  ; break;
		case id_expression  : name =  "id_expression"  ; break;
		case unqualified_id  : name =  "unqualified_id"  ; break;
		case qualified_id : name =  "qualified_id" ; break;
		case nested_name_specifier  : name =  "nested_name_specifier"  ; break;
		case postfix_expression  : name =  "postfix_expression"  ; break;
		case expression_list  : name =  "expression_list"  ; break;
		case unary_expression  : name =  "unary_expression"  ; break;
		case unary_operator : name =  "unary_operator" ; break;
		case new_expression  : name =  "new_expression"  ; break;
		case new_placement  : name =  "new_placement"  ; break;
		case new_type_id  : name =  "new_type_id"  ; break;
		case new_declarator  : name =  "new_declarator"  ; break;
		case direct_new_declarator  : name =  "direct_new_declarator"  ; break;
		case new_initializer : name =  "new_initializer" ; break;
		case delete_expression  : name =  "delete_expression"  ; break;
		case cast_expression  : name =  "cast_expression"  ; break;
		case pm_expression  : name =  "pm_expression"  ; break;
		case multiplicative_expression  : name =  "multiplicative_expression"  ; break;
		case additive_expression : name =  "additive_expression" ; break;
		case shift_expression  : name =  "shift_expression"  ; break;
		case relational_expression  : name =  "relational_expression"  ; break;
		case equality_expression  : name =  "equality_expression"  ; break;
		case and_expression  : name =  "and_expression"  ; break;
		case exclusive_or_expression : name =  "exclusive_or_expression" ; break;
		case inclusive_or_expression  : name =  "inclusive_or_expression"  ; break;
		case logical_and_expression  : name =  "logical_and_expression"  ; break;
		case logical_or_expression  : name =  "logical_or_expression"  ; break;
		case conditional_expression : name =  "conditional_expression" ; break;
		case assignment_expression  : name =  "assignment_expression"  ; break;
		case assignment_operator  : name =  "assignment_operator"  ; break;
		case expression  : name =  "expression"  ; break;
		case constant_expression  : name =  "constant_expression"  ; break;
		case statement : name =  "statement" ; break;
		case labeled_statement  : name =  "labeled_statement"  ; break;
		case expression_statement  : name =  "expression_statement"  ; break;
		case compound_statement  : name =  "compound_statement"  ; break;
		case statement_seq  : name =  "statement_seq"  ; break;
		case selection_statement : name =  "selection_statement" ; break;
		case condition  : name =  "condition"  ; break;
		case iteration_statement  : name =  "iteration_statement"  ; break;
		case for_init_statement  : name =  "for_init_statement"  ; break;
		case jump_statement  : name =  "jump_statement"  ; break;
		case declaration_statement : name =  "declaration_statement" ; break;
		case declaration_seq  : name =  "declaration_seq"  ; break;
		case declaration  : name =  "declaration"  ; break;
		case block_declaration  : name =  "block_declaration"  ; break;
		case simple_declaration  : name =  "simple_declaration"  ; break;
		case decl_specifier : name =  "decl_specifier" ; break;
		case decl_specifier_seq  : name =  "decl_specifier_seq"  ; break;
		case storage_class_specifier  : name =  "storage_class_specifier"  ; break;
		case function_specifier  : name =  "function_specifier"  ; break;
		case type_specifier  : name =  "type_specifier"  ; break;
		case simple_type_specifier : name =  "simple_type_specifier" ; break;
		case type_name  : name =  "type_name"  ; break;
		case elaborated_type_specifier  : name =  "elaborated_type_specifier"  ; break;
		case enum_specifier  : name =  "enum_specifier"  ; break;
		case enumerator_list  : name =  "enumerator_list"  ; break;
		case enumerator_definition : name =  "enumerator_definition" ; break;
		case enumerator  : name =  "enumerator"  ; break;
		case namespace_definition  : name =  "namespace_definition"  ; break;
		case named_namespace_definition  : name =  "named_namespace_definition"  ; break;
		case original_namespace_definition : name =  "original_namespace_definition" ; break;
		case extension_namespace_definition  : name =  "extension_namespace_definition"  ; break;
		case unnamed_namespace_definition  : name =  "unnamed_namespace_definition"  ; break;
		case namespace_body  : name =  "namespace_body"  ; break;
		case namespace_alias_definition : name =  "namespace_alias_definition" ; break;
		case qualified_namespace_specifier  : name =  "qualified_namespace_specifier"  ; break;
		case using_declaration  : name =  "using_declaration"  ; break;
		case using_directive  : name =  "using_directive"  ; break;
		case asm_definition  : name =  "asm_definition"  ; break;
		case linkage_specification  : name =  "linkage_specification"  ; break;
		case init_declarator_list  : name =  "init_declarator_list"  ; break;
		case init_declarator  : name =  "init_declarator"  ; break;
		case declarator  : name =  "declarator"  ; break;
		case direct_declarator  : name =  "direct_declarator"  ; break;
		case ptr_operator  : name =  "ptr_operator"  ; break;
		case cv_qualifier_seq : name =  "cv_qualifier_seq" ; break;
		case cv_qualifier  : name =  "cv_qualifier"  ; break;
		case declarator_id  : name =  "declarator_id"  ; break;
		case type_id  : name =  "type_id"  ; break;
		case type_specifier_seq  : name =  "type_specifier_seq"  ; break;
		case abstract_declarator  : name =  "abstract_declarator"  ; break;
		case direct_abstract_declarator : name =  "direct_abstract_declarator" ; break;
		case parameter_declaration_clause  : name =  "parameter_declaration_clause"  ; break;
		case parameter_declaration_list  : name =  "parameter_declaration_list"  ; break;
		case parameter_declaration  : name =  "parameter_declaration"  ; break;
		case function_definition : name =  "function_definition" ; break;
		case function_body  : name =  "function_body"  ; break;
		case initializer  : name =  "initializer"  ; break;
		case initializer_clause  : name =  "initializer_clause"  ; break;
		case initializer_list  : name =  "initializer_list"  ; break;
		case class_specifier  : name =  "class_specifier"  ; break;
		case class_head : name =  "class_head" ; break;
		case class_key  : name =  "class_key"  ; break;
		case member_specification  : name =  "member_specification"  ; break;
		case member_declaration  : name =  "member_declaration"  ; break;
		case member_declarator_list  : name =  "member_declarator_list"  ; break;
		case member_declarator : name =  "member_declarator" ; break;
		case pure_specifier  : name =  "pure_specifier"  ; break;
		case constant_initializer  : name =  "constant_initializer"  ; break;
		case base_clause  : name =  "base_clause"  ; break;
		case base_specifier_list  : name =  "base_specifier_list"  ; break;
		case base_specifier : name =  "base_specifier" ; break;
		case access_specifier  : name =  "access_specifier"  ; break;
		case conversion_function_id  : name =  "conversion_function_id"  ; break;
		case conversion_type_id  : name =  "conversion_type_id"  ; break;
		case conversion_declarator  : name =  "conversion_declarator"  ; break;
		case ctor_initializer  : name =  "ctor_initializer"  ; break;
		case mem_initializer_list  : name =  "mem_initializer_list"  ; break;
		case mem_initializer  : name =  "mem_initializer"  ; break;
		case mem_initializer_id  : name =  "mem_initializer_id"  ; break;
		case operator_function_id : name =  "operator_function_id" ; break;
		case operator  : name =  "operator"  ; break;
		case template_declaration  : name =  "template_declaration"  ; break;
		case template_parameter_list  : name =  "template_parameter_list"  ; break;
		case template_parameter  : name =  "template_parameter"  ; break;
		case type_parameter : name =  "type_parameter" ; break;
		case template_id  : name =  "template_id"  ; break;
		case template_argument_list  : name =  "template_argument_list"  ; break;
		case template_argument  : name =  "template_argument"  ; break;
		case explicit_instantiation  : name =  "explicit_instantiation"  ; break;
		case explicit_specialization : name =  "explicit_specialization" ; break;
		case try_block  : name =  "try_block"  ; break;
		case function_try_block  : name =  "function_try_block"  ; break;
		case handler_seq : name =  "handler_seq"  ; break;
		case handler : name =  "handler"  ; break;
		case exception_declaration  : name =  "exception_declaration"  ; break;
		case throw_expression : name =  "throw_expression" ; break;
		case exception_specification  : name =  "exception_specification"  ; break;
		case type_id_list  : name =  "type_id_list"  ; break;
		case declaration_seq_opt  : name =  "declaration_seq_opt"  ; break;
		case nested_name_specifier_opt  : name =  "nested_name_specifier_opt"  ; break;
		case expression_list_opt  : name =  "expression_list_opt"  ; break;
		case COLONCOLON_opt  : name =  "COLONCOLON_opt"  ; break;
		case new_placement_opt  : name =  "new_placement_opt"  ; break;
		case new_initializer_opt  : name =  "new_initializer_opt"  ; break;
		case new_declarator_opt : name =  "new_declarator_opt" ; break;
		case expression_opt  : name =  "expression_opt"  ; break;
		case statement_seq_opt  : name =  "statement_seq_opt"  ; break;
		case condition_opt  : name =  "condition_opt"  ; break;
		case enumerator_list_opt  : name =  "enumerator_list_opt"  ; break;
		case initializer_opt : name =  "initializer_opt" ; break;
		case constant_expression_opt  : name =  "constant_expression_opt"  ; break;
		case abstract_declarator_opt  : name =  "abstract_declarator_opt"  ; break;
		case type_specifier_seq_opt  : name =  "type_specifier_seq_opt"  ; break;
		case direct_abstract_declarator_opt : name =  "direct_abstract_declarator_opt" ; break;
		case ctor_initializer_opt  : name =  "ctor_initializer_opt"  ; break;
		case COMMA_opt  : name =  "COMMA_opt"  ; break;
		case member_specification_opt  : name =  "member_specification_opt"  ; break;
		case SEMICOLON_opt  : name =  "SEMICOLON_opt"  ; break;
		case conversion_declarator_opt : name =  "conversion_declarator_opt" ; break;
		case EXPORT_opt  : name =  "EXPORT_opt"  ; break;
		case handler_seq_opt  : name =  "handler_seq_opt"  ; break;
		case assignment_expression_opt  : name =  "assignment_expression_opt"  ; break;
		case type_id_list_opt : name =  "type_id_list_opt" ; break;
		case NULL_TYPE : name =  "NULL" ; break;
		case CHAR_TYPE : name =  "char" ; break;
		case WCHAR_T_TYPE : name =  "wchar_t" ; break;
		case BOOL_TYPE : name =  "bool" ; break;
		case SHORT_TYPE : name =  "short" ; break;
		case INT_TYPE : name =  "int" ; break;
		case LONG_TYPE : name =  "long" ; break;
		case SIGNED_TYPE : name =  "signed" ; break;
		case UNSIGNED_TYPE : name =  "unsigned" ; break;
		case FLOAT_TYPE : name =  "float" ; break;
		case DOUBLE_TYPE : name =  "double" ; break;
		case VOID_TYPE : name =  "void" ; break;
		case STR_TYPE_TYPE : name =  "string" ; break;
		case ARRAY_TYPE : name =  "array" ; break;
		case POINTER_TYPE : name =  "pointer" ; break;
		case CLASS_TYPE : name =  "class" ; break;
		case STRUCT_TYPE : name =  "struct" ; break;
		case UNION_TYPE : name =  "union" ; break;
		case CONSTRUCTOR_TYPE : name =  "constructor" ; break;
		case DECONSTRUCTOR_TYPE : name =  "deconstructor" ; break;
		case METHOD_TYPE : name =  "method" ; break;
		case FUNC_TYPE : name =  "function" ; break;
		case TOUPLE_TYPE : name =  "touple" ; break;
		case UNKNOWN_TYPE : name =  "UNKNOWN TYPE" ; break;
		case PROGRAM_TYPE : name =  "program" ; break;
		case PRIVATE_TYPE : name =  "private" ; break;
		case PROTECTED_TYPE : name = "protected" ; break;
		case PUBLIC_TYPE : name = "public" ; break;
		case MEMBER_TYPE : name = "member" ; break;
		case OPERATOR_TYPE : name = "operator" ; break;
		case STATEMENT_TYPE : name = "statement" ; break;
		case ADDRESS_TYPE : name = "address" ; break;
		case STREAM_TYPE : name = "stream" ; break;

		default : name =  "Not Found"; break;
	}
	return name;
}

void printTree(TreeNode *t, int depth, int b){
	char *text;
	int i;
	if(t->symbol >= 1000){
		printf("%*s%s: %d", depth, " ", humanreadable(t->u.n.rule), t->u.n.children);
		if(b){
			if(t->type->label != NULL) printf(" %s ", t->type->label);
			printf(" - %s", humanreadable(t->type->base_type));
		}
		printf("\n");
		if(t->u.n.children > 0)
			for(i=0; i<t->u.n.children; i++)
				printTree(t->u.n.child[i], depth+1, b);
	} else {
		printf("%*s%s: %s", depth, " ", humanreadable(t->symbol), t->u.t.token->text);
		if(b)printf(" - %s", humanreadable(t->type->base_type));
		printf("\n");
	}
}

TreeNode *alacnary(int prodRule, int children,...){
	TreeNode *nd = (TreeNode *)calloc(1, sizeof(TreeNode));
	if(!nd)memoryError();
	
	nd->u.n.rule = prodRule;
	nd->u.n.children = children;
	nd->symbol = (int)(prodRule / 100) * 100;
	int c = 0;
	va_list mylist;
	va_start(mylist, children);
	while(c < children){
		nd->u.n.child[c] = va_arg(mylist, TreeNode *);
		c++;
	}
	va_end(mylist);
	return nd;
}

NType *getType(int tcode){
	struct NType *ntype;
	if((ntype = (NType *)calloc(1, sizeof(NType))) == NULL) memoryError();
	ntype->base_type = tcode;
	
	return ntype;
}

SymbolTable *createSymbolTable(SymbolTable *parent, int size){
	if(SHOW_TREES) printf("\t*createSymbolTable*\n");
	int i;
	parent->children++;
	SymbolTable *symbolTable;
	if((symbolTable = (SymbolTable *)calloc(1, sizeof(SymbolTable))) == NULL) memoryError();
	symbolTable->parent = parent;
	parent->child = realloc(parent->child, parent->children * sizeof(struct typeinfo *));
	parent->child[parent->children -1] = symbolTable;
	symbolTable->size = size;
	symbolTable->entries = 0;
	if((symbolTable->bucket = calloc(size, sizeof(SymbolTableEntry))) == NULL) memoryError();
	for(i = 0; i < size; i++){
		symbolTable->bucket[i] = NULL;
	}
	return symbolTable;
}

SymbolTable *createGlobalSymbolTable(int size){
	if(SHOW_TREES) printf("\t*createGlobalSymbolTable*\n");
	int i;
	SymbolTable *symbolTable;
	if((symbolTable = (SymbolTable *)calloc(1, sizeof(SymbolTable))) == NULL) memoryError();
	symbolTable->size = size;
	symbolTable->entries = 0;
	symbolTable->scope = root->type;
	if((symbolTable->bucket = calloc(size, sizeof(SymbolTableEntry))) == NULL) memoryError();
	for(i = 0; i < size; i++){
		symbolTable->bucket[i] = NULL;
	}
	if(SHOW_TREES) printf("global ST: %d\n", symbolTable->size);
	return symbolTable;
}

SymbolTable *getSymbolTable(SymbolTable *currentSymbolTable, char *tableName){
	int c;
	SymbolTable *symbolTable;
	if(strcmp(currentSymbolTable->scope->label, tableName) == 0) return currentSymbolTable;
	else for(c = 0; c < currentSymbolTable->children; c++){
		symbolTable = getSymbolTable(currentSymbolTable->child[c], tableName);
		if(symbolTable != NULL) return symbolTable;
	}
	return NULL;
}

int hashSymbol(NType *symb, int size){
	int i;
	int sum = 0;
	for(i = 0; i < strlen(symb->label); i++){
		sum += symb->label[i];
	}
	return sum % size;
}

int inSymbolTable(SymbolTable *symbolTable, NType *symb){
	int hashvalue = hashSymbol(symb, symbolTable->size);
	SymbolTableEntry *current = symbolTable->bucket[hashvalue];
	while(current != NULL){
		if(strcmp(current->symb->label, symb->label) == 0) return 1;
		current = current->next;
	}
	if(symbolTable->parent != NULL) 
		if(inSymbolTable(symbolTable->parent, symb) == 1) return 1;
	return 0;
}

NType *getSymbolFromTable(SymbolTable *symbolTable, NType *symb){
	int hashvalue = hashSymbol(symb, symbolTable->size);
	SymbolTableEntry *current = symbolTable->bucket[hashvalue];
	while(current != NULL){
		if(strcmp(current->symb->label, symb->label) == 0){
			return current->symb;
		}
		current = current->next;
	}
	if(symbolTable->parent != NULL) {
		return (NType *)inSymbolTable(symbolTable->parent, symb);
	}
	return NULL;
}

NType *getClass(SymbolTable* symbolTable, char *clas){
	NType *thisType = getType(UNKNOWN_TYPE);
	if((thisType->label = calloc(strlen(clas), sizeof(char))) == NULL) memoryError();
	strcpy(thisType->label, clas);
	int hashvalue = hashSymbol(thisType, symbolTable->size);
	free(thisType);
	SymbolTableEntry *current = symbolTable->bucket[hashvalue];
	while(current != NULL){
		if(strcmp(current->symb->label, clas) == 0){
			return current->symb;
		}
		current = current->next;
	}
	return NULL;
}

void addToSymbolTable(SymbolTable *symbolTable, NType *symb){
	if(SHOW_TREES) printf("adding to symbol table %s:\n", symbolTable->scope->label);
	SymbolTableEntry *newEntry;
	if((newEntry = (SymbolTableEntry *)calloc(1, sizeof(SymbolTableEntry))) == NULL) memoryError();
	newEntry->symb = symb;
	//if(symb->base_type == ARRAY_TYPE) printf("%s %s[%d]\n", humanreadable(symb->u.arry.elemtype->base_type), symb->label, symb->u.arry.size);
	//else if(symb->ref == NULL)printf("%s %s\n", humanreadable(symb->base_type), symb->label);
	//else printf("%s %s\n", symb->cType->label, symb->label);
	int hashvalue = hashSymbol(symb, symbolTable->size);
	if(symbolTable->bucket[hashvalue] == NULL){
		symbolTable->bucket[hashvalue] = newEntry;
		symbolTable->entries++;
	} else {
		if(inSymbolTable(symbolTable, symb) == 0){
			newEntry->next = symbolTable->bucket[hashvalue];
			symbolTable->bucket[hashvalue] = newEntry;
			symbolTable->entries++;
		}else{
			/* symbol used */
			exitStatus = 3;
			getErrorMessage(ER_USED_SYMBOL_LABEL);
			yyerror(symb->label);
		}
	}
	if(SHOW_TREES) printf("\naddToSymbolTable: [%d]\n", symbolTable->entries);
}

void addLibrariesData(){
	NType *tempType;
	if(included_iostream){
		if(using_namespace_std){
			tempType = (NType *)getType(STREAM_TYPE);
			tempType->label = "cin";
			addToSymbolTable(globalSymbolTable, tempType);
			tempType = (NType *)getType(STREAM_TYPE);
			tempType->label = "cout";
			addToSymbolTable(globalSymbolTable, tempType);
			tempType = (NType *)getType(STREAM_TYPE);
			tempType->label = "endl";
			addToSymbolTable(globalSymbolTable, tempType);
		}
		tempType = (NType *)getType(STREAM_TYPE);
		tempType->label = "std::cin";
		addToSymbolTable(globalSymbolTable, tempType);
		tempType = (NType *)getType(STREAM_TYPE);
		tempType->label = "std::cout";
		addToSymbolTable(globalSymbolTable, tempType);
		tempType = (NType *)getType(STREAM_TYPE);
		tempType->label = "std::endl";
		addToSymbolTable(globalSymbolTable, tempType);
	}
	if(included_cstdlib){
		if(using_namespace_std){
		
		}
	}
	if(included_ctime){
		if(using_namespace_std){
		
		}
	}
	if(included_string){
		if(using_namespace_std){

		}
	}
	if(included_fstream){
		if(using_namespace_std){
		
		}
	}
	if(included_stdio){
		if(using_namespace_std){
		
		}
	}
	if(included_stdlib){
		if(using_namespace_std){
		
		}
	}
}

/*checks to see if operators are the same*/
NType *getOperatorType(NType *op1, NType *op2){
	if(SHOW_TREES) printf("\t%s : %s\n", humanreadable(op1->base_type), humanreadable(op2->base_type));
	if(op1->base_type == op2->base_type)return getType(op1->base_type);
	else {
		exitStatus = 3;
		getErrorMessage(ER_TYPE_MISMATCH);
		yyerror(NULL);
	}
}

/*checks to see if node types are the same*/
NType *checkType(NType *op1, NType *op2){
	if(SHOW_TREES) printf("\t%s : %s\n", humanreadable(op1->base_type), humanreadable(op2->base_type));
	if(op1->base_type == op2->base_type)return getType(op1->base_type);
	else return NULL;
}

void copyType(NType *source, NType *dest){
	int i;
	dest->base_type = source->base_type;
	dest->label = source->label;
	dest->pub = source->pub;
	switch(source->base_type){
		case ARRAY_TYPE :
			dest->u.arry.size = source->u.arry.size;
			if((dest->u.arry.elemtype = calloc(dest->u.arry.size, sizeof(struct typeinfo *))) == NULL) memoryError();
			for(i = 0; i < dest->u.arry.size; i++){
				dest->u.arry.elemtype[i] = source->u.arry.elemtype[i];
			}
			break;
		case STRUCT_TYPE :
			dest->u.struc.nfields = source->u.struc.nfields;
			if((dest->u.struc.f = calloc(dest->u.struc.nfields, sizeof(struct typeinfo *))) == NULL) memoryError();
			for(i = 0; i < dest->u.struc.nfields; i++){
				dest->u.struc.f[i] = source->u.struc.f[i];
			}
			break;
		case CLASS_TYPE :
			dest->u.clas.nfields = source->u.clas.nfields;
			if((dest->u.clas.f = calloc(dest->u.clas.nfields, sizeof(struct typeinfo *))) == NULL) memoryError();
			for(i = 0; i < dest->u.clas.nfields; i++){
				dest->u.clas.f[i] = source->u.clas.f[i];
			}
			break;
		case FUNC_TYPE :
			dest->u.func.parent = source->u.func.parent;
			dest->u.func.retType = source->u.func.retType;
			dest->u.func.nargs = source->u.func.nargs;
			if((dest->u.func.args = calloc(dest->u.func.nargs, sizeof(struct typeinfo *))) == NULL) memoryError();
			for(i = 0; i < dest->u.func.nargs; i++){
				dest->u.func.args[i] = source->u.func.args[i];
			}
			break;
	}
}

void passTypeBelowPointer(NType *source, NType *dest){
	if(SHOW_TREES) printf("*passTypeBelowPointer*\n");
	if(dest->base_type == POINTER_TYPE){
	if(SHOW_TREES) printf("%s\n", humanreadable(dest->u.ptr->base_type));
		passTypeBelowPointer(source, dest->u.ptr);
	} else {
		dest->base_type = source->base_type;
		dest->pub = source->pub;
	}
}

void passTypeToDeclarationList(NType *source, TreeNode *dest){
	if(SHOW_TREES) printf("*passTypeToDeclarationList*\n");
	if(dest != NULL){
		if(dest->type->base_type == TOUPLE_TYPE){
			passTypeToDeclarationList(source, dest->u.n.child[0]);
			passTypeToDeclarationList(source, dest->u.n.child[1]);
		} else {
			dest->type->base_type = source->base_type;
			dest->type->pub = source->pub;
		}
	}
}

void passAccessBelow(NType *source, NType *dest){
	if(SHOW_TREES) printf("*passAccessBelow*\n");
	if(dest != NULL){
		dest->pub = source->pub;
	}
	if(dest->base_type == TOUPLE_TYPE){
		passAccessBelow(source, dest->u.touple.elems[0]);
		passAccessBelow(source, dest->u.touple.elems[1]);
	} 
}

void addParamsToFunction(TreeNode *node, NType *param){
	if(node != NULL){
		if(SHOW_TREES) printf("*addParamsToFunction*\n");
		int e;
		Field *newField;
		if(param->base_type == TOUPLE_TYPE){
			for(e = 0; e < param->u.touple.nelems; e++)
				addParamsToFunction(node, param->u.touple.elems[e]);
		} else {
			if(param->base_type != NULL_TYPE){
				newField = (Field *)calloc(1, sizeof(Field));
				newField->name = param->label;
				newField->elemtype = param;
				if(node->type->u.func.nargs == 0) node->type->u.func.args = calloc(10, sizeof(struct typeinfo *));
				node->type->u.func.nargs++;
				if(node->type->u.func.nargs % 10 > 8)
					node->type->u.func.args = realloc(node->type->u.func.args, ((int)(node->type->u.func.nargs / 10) + 20 ) * sizeof(struct typeinfo *));
				node->type->u.func.args[node->type->u.func.nargs - 1] = newField;
			}
		}
	}
}

void addMembersToClass(TreeNode *node, NType *member){
	if(node != NULL){
		if(SHOW_TREES) printf("*addMembersToClass*\n");
		int e;
		Field *newField;
		if(member->base_type == TOUPLE_TYPE){
			for(e = 0; e < member->u.touple.nelems; e++)
				addMembersToClass(node, member->u.touple.elems[e]);
		} else {
			if(member->base_type != NULL_TYPE){
				if(node->type->u.clas.nfields == 0) {
					node->type->u.clas.f = calloc(10, sizeof(struct typeinfo *));
					//make default constructor
					Field *constructorField = (Field *)calloc(1, sizeof(Field));
					constructorField->name = node->type->label;
					NType *constructor = getType(FUNC_TYPE);
					constructor->label = node->type->label;
					constructor->u.func.nargs = 0;
					constructor->pub = PUBLIC_TYPE;
					constructorField->elemtype = constructor;
					node->type->u.clas.f[0] = constructorField;
					node->type->u.clas.nfields++;
				}
				newField = (Field *)calloc(1, sizeof(Field));
				newField->name = member->label;
				newField->elemtype = member;
				node->type->u.clas.nfields++;
				if(node->type->u.clas.nfields % 10 > 8)
					node->type->u.clas.f = realloc(node->type->u.clas.f, ((int)(node->type->u.clas.nfields / 10) + 20) * sizeof(struct typeinfo *));
				node->type->u.clas.f[node->type->u.clas.nfields - 1] = newField;
			}
		}
	}
}

/* performs the first pass of semantic analysis by establishing the type of each node of the tree*/
void buildTypes(TreeNode *node){
	int c;
	NType *tempType;
	if(node != NULL){
		int n;
		for(n = 0; n < node->u.n.children; n++){
			buildTypes(node->u.n.child[n]);
		}
		switch(node->u.n.rule){
			case TYPEDEF_NAMEr1 :
				if(SHOW_TREES) printf("typedef name1\n");
				node->type = getType(UNKNOWN_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				break;
				
			case NAMESPACE_NAMEr1 :
				if(SHOW_TREES) printf("namespace name1\n");
				node->type = getType(UNKNOWN_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				break;
				
			case ORIGINAL_NAMESPACE_NAMEr1 :
				if(SHOW_TREES) printf("original namespace name1\n");
				node->type = getType(UNKNOWN_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				break;
				
			case CLASS_NAMEr1 :
				if(SHOW_TREES) printf("class name1\n");
				node->type = getType(UNKNOWN_TYPE);
				node->u.n.child[0]->type = node->type;
				node->type->label = node->u.n.child[0]->u.t.token->text;
				//node->u.n.child[0]->type = node->type;
				break;
				
			case ENUM_NAMEr1 :
				if(SHOW_TREES) printf("enum name1\n");
				node->type = getType(UNKNOWN_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				break;
				
			case IDENTIFIERr1 :
				if(SHOW_TREES) printf("identifier1\n");
				node->type = getType(UNKNOWN_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				break;
				
			case LITERALr1 :
				if(SHOW_TREES) printf("literal1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case LITERALr2 :
				if(SHOW_TREES) printf("literal2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case LITERALr3 :
				if(SHOW_TREES) printf("literal3\n");
				node->type = node->u.n.child[0]->type;
				break;
			case LITERALr4 :
				if(SHOW_TREES) printf("literal4\n");
				node->type = node->u.n.child[0]->type;
				break;
			case LITERALr5 :
				if(SHOW_TREES) printf("literal5\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case INTEGER_LITERALr1 :
				if(SHOW_TREES) printf("integer literal1\n");
				node->type = getType(INT_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				break;
			case CHARACTER_LITERALr1 :
				if(SHOW_TREES) printf("character literal1\n");
				node->type = getType(CHAR_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				break;
			case FLOATING_LITERALr1 :
				if(SHOW_TREES) printf("floating literal1\n");
				node->type = getType(FLOAT_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				break;
			case STRING_LITERALr1 :
				if(SHOW_TREES) printf("string literal1\n");
				node->type = getType(STR_TYPE_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				break;
			case BOOLEAN_LITERALr1 :
				if(SHOW_TREES) printf("boolean literal1\n");
				node->type = getType(BOOL_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				break;
			case BOOLEAN_LITERALr2 :
				if(SHOW_TREES) printf("boolean literal2\n");
				node->type = getType(BOOL_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				break;

			case TRANSLATION_UNITr1 :
				if(SHOW_TREES) printf("translation unit1\n");
				node->type = getType(PROGRAM_TYPE);
				node->type->label = "program";
				break;
				
			case PRIMARY_EXPRESSIONr1 :
				if(SHOW_TREES) printf("primary expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case PRIMARY_EXPRESSIONr2 :
				if(SHOW_TREES) printf("primary expression2\n");
				exitStatus = 3;
				getErrorMessage(ER_NOT_SUPPORTED);
				yyerror(node->type->label);
				break;
			case PRIMARY_EXPRESSIONr3 :
				if(SHOW_TREES) printf("primary expression3\n");
				node->type = node->u.n.child[1]->type;
				break;
			case PRIMARY_EXPRESSIONr4 :
				if(SHOW_TREES) printf("primary expression4\n");
				node->type = node->u.n.child[0]->type;
				break;

			case ID_EXPRESSIONr1 :
				if(SHOW_TREES) printf("id expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case ID_EXPRESSIONr2 :
				if(SHOW_TREES) printf("id expression2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case UNQUALIFIED_IDr1 :
				if(SHOW_TREES) printf("unqualified id1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case UNQUALIFIED_IDr2 :
				if(SHOW_TREES) printf("unqualified id2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case UNQUALIFIED_IDr3 :
				if(SHOW_TREES) printf("unqualified id3\n");
				node->type = node->u.n.child[0]->type;
				break;
			case UNQUALIFIED_IDr4 :
				if(SHOW_TREES) printf("unqualified id4\n");
				node->type = node->u.n.child[1]->type;
				break;
				
			case QUALIFIED_IDr1 :
				if(SHOW_TREES) printf("qualified id1\n");
				node->type = node->u.n.child[1]->type;
				break;

			case NESTED_NAME_SPECIFIERr1 :
				if(SHOW_TREES) printf("nested name specifier1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case NESTED_NAME_SPECIFIERr2 :
				if(SHOW_TREES) printf("nested name specifier2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case NESTED_NAME_SPECIFIERr3 :
				if(SHOW_TREES) printf("nested name specifier3\n");
				node->type = node->u.n.child[0]->type;
				break;
			case NESTED_NAME_SPECIFIERr4 :
				if(SHOW_TREES) printf("nested name specifier4\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case POSTFIX_EXPRESSIONr1 :
				if(SHOW_TREES) printf("postfix expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case POSTFIX_EXPRESSIONr2 :
				if(SHOW_TREES) printf("postfix expression2\n");
				if(node->u.n.child[1]->type->base_type != INT_TYPE){
					getErrorMessage();
					yyerror(NULL);
				}
				node->type = getType(ARRAY_TYPE);
				break;
			case POSTFIX_EXPRESSIONr3 :
				if(SHOW_TREES) printf("postfix expression3\n");
				node->type = node->u.n.child[0]->type;
				break;
			case POSTFIX_EXPRESSIONr5 :
				if(SHOW_TREES) printf("postfix expression5\n");
				node->type = node->u.n.child[0]->type;
				break;
			case POSTFIX_EXPRESSIONr6 :
				if(SHOW_TREES) printf("postfix expression6\n");
				node->type = node->u.n.child[0]->type;
				break;
			case POSTFIX_EXPRESSIONr7 :
				if(SHOW_TREES) printf("postfix expression7\n");
				node->type = node->u.n.child[1]->type;
				node->type->ref = node->u.n.child[0]->type->label;
				break;
			case POSTFIX_EXPRESSIONr9 :
				if(SHOW_TREES) printf("postfix expression9\n");
				node->type = node->u.n.child[0]->type;
				break;
			case POSTFIX_EXPRESSIONr10 :
				if(SHOW_TREES) printf("postfix expression10\n");
				node->type = node->u.n.child[0]->type;
				break;
			case POSTFIX_EXPRESSIONr11 :
				if(SHOW_TREES) printf("postfix expression11\n");
				node->type = node->u.n.child[0]->type;
				break;
			case POSTFIX_EXPRESSIONr12 :
				if(SHOW_TREES) printf("postfix expression12\n");
				node->type = node->u.n.child[0]->type;
				break;
			case POSTFIX_EXPRESSIONr13 :
				if(SHOW_TREES) printf("postfix expression13\n");
				break;
				node->type = node->u.n.child[0]->type;
			case POSTFIX_EXPRESSIONr14 :
				if(SHOW_TREES) printf("postfix expression14\n");
				node->type = node->u.n.child[2]->type;
				break;
			case POSTFIX_EXPRESSIONr15 :
				if(SHOW_TREES) printf("postfix expression15\n");
				node->type = node->u.n.child[2]->type;
				break;
			case POSTFIX_EXPRESSIONr16 :
				if(SHOW_TREES) printf("postfix expression16\n");
				node->type = node->u.n.child[2]->type;
				break;
			case POSTFIX_EXPRESSIONr17 :
				printf("postfix expression17\n");
				node->type = node->u.n.child[2]->type;
				break;
			case POSTFIX_EXPRESSIONr18 :
				if(SHOW_TREES) printf("postfix expression18\n");
				node->type = node->u.n.child[2]->type;
				break;
			case POSTFIX_EXPRESSIONr19 :
				if(SHOW_TREES) printf("postfix expression19\n");
				node->type = node->u.n.child[2]->type;
				break;
				/*
postfix_expression:
	primary_expression												{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr1, 1, $1); }
	| postfix_expression '[' expression ']'					{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr2, 2, $1, $3); }
	| postfix_expression '(' expression_list_opt ')'		{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr3, 2, $1, $3); }
	| postfix_expression '.' TEMPLATE COLONCOLON id_expression
																			{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr4, 3, $1, $3, $4); }
	| postfix_expression '.' TEMPLATE id_expression			{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr5, 3, $1, $3, $4); }
	| postfix_expression '.' COLONCOLON id_expression		{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr6, 3, $1, $3, $4); }
	| postfix_expression '.' id_expression						{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr7, 2, $1, $3); }
	| postfix_expression ARROW TEMPLATE COLONCOLON id_expression
																			{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr8, 5, $1, $2, $3, $4, $5); }
	| postfix_expression ARROW TEMPLATE id_expression		{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr9, 4, $1, $2, $3, $4); }
	| postfix_expression ARROW COLONCOLON id_expression	{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr10, 4, $1, $2, $3, $4); }
	| postfix_expression ARROW id_expression					{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr11, 3, $1, $2, $3); }
	| postfix_expression PLUSPLUS									{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr12, 2, $1, $2); }
	| postfix_expression MINUSMINUS								{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr13, 2, $1, $2); }
	| DYNAMIC_CAST '<' type_id '>' '(' expression ')'		{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr14, 3, $1, $3, $6); }
	| STATIC_CAST '<' type_id '>' '(' expression ')'		{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr15, 3, $1, $3, $6); }
	| REINTERPRET_CAST '<' type_id '>' '(' expression ')'	{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr16, 3, $1, $3, $6); }
	| CONST_CAST '<' type_id '>' '(' expression ')'			{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr17, 3, $1, $3, $6); }
	| TYPEID '(' expression ')'									{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr18, 2, $1, $3); }
	| TYPEID '(' type_id ')'										{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr19, 2, $1, $3); }
	; */
				
			case EXPRESSION_LISTr1 :
				if(SHOW_TREES) printf("expression list1\n");
				node->type = node->u.n.child[0]->type;
			case EXPRESSION_LISTr2 :
				if(SHOW_TREES) printf("expression list2\n");
				node->type = getType(TOUPLE_TYPE);
				node->type->u.touple.nelems = 2;
				if((node->type->u.touple.elems = calloc(2, sizeof(struct typeinfo *))) == NULL) memoryError();
				node->type->u.touple.elems[0] = node->u.n.child[0]->type;
				node->type->u.touple.elems[1] = node->u.n.child[1]->type;
				
			case UNARY_EXPRESSIONr1 :
				if(SHOW_TREES) printf("unary expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case UNARY_EXPRESSIONr2 :
				if(SHOW_TREES) printf("unary expression2\n");
				node->type = node->u.n.child[1]->type;
				break;
			case UNARY_EXPRESSIONr3 :
				if(SHOW_TREES) printf("unary expression3\n");
				node->type = node->u.n.child[1]->type;
				break;
			case UNARY_EXPRESSIONr4 :
				if(SHOW_TREES) printf("unary expression4\n");
				node->type = getType(POINTER_TYPE);
				node->type->u.ptr = node->u.n.child[0]->type;
				break;
			case UNARY_EXPRESSIONr5 :
				if(SHOW_TREES) printf("unary expression5\n");
				node->type = getType(ADDRESS_TYPE);
				node->type->u.ptr = node->u.n.child[0]->type;
				break;
			case UNARY_EXPRESSIONr6 :
				if(SHOW_TREES) printf("unary expression6\n");
				node->type = node->u.n.child[1]->type;
				break;
			case UNARY_EXPRESSIONr7 :
				if(SHOW_TREES) printf("unary expression7\n");
				node->type = getType(INT_TYPE);
				break;
			case UNARY_EXPRESSIONr8 :
				if(SHOW_TREES) printf("unary expression8\n");
				node->type = getType(INT_TYPE);
				break;
			case UNARY_EXPRESSIONr9 :
				if(SHOW_TREES) printf("unary expression9\n");
				node->type = node->u.n.child[1]->type;
				break;
			case UNARY_EXPRESSIONr10 :
				if(SHOW_TREES) printf("unary expression10\n");
				node->type = getType(DECONSTRUCTOR_TYPE);
				break;

/* SKIPPED UNARY_OPERATOR */
				
			case NEW_EXPRESSIONr1 :
				if(SHOW_TREES) printf("new_expression1\n");
				node->type = node->u.n.child[2]->type;
				break;
			case NEW_EXPRESSIONr2 :
				if(SHOW_TREES) printf("new_expression2\n");
				node->type = node->u.n.child[3]->type;
				break;
			case NEW_EXPRESSIONr3 :
				if(SHOW_TREES) printf("new_expression3\n");
				node->type = node->u.n.child[2]->type;
				break;
			case NEW_EXPRESSIONr4 :
				if(SHOW_TREES) printf("new_expression4\n");
				node->type = node->u.n.child[3]->type;
				break;
				
			case NEW_PLACEMENTr1 :
				if(SHOW_TREES) printf("new_placement1\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case NEW_TYPE_IDr1 :
				if(SHOW_TREES) printf("new_type_id1\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case NEW_DECLARATORr1 :
				if(SHOW_TREES) printf("new_declarator1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case NEW_DECLARATORr2 :
				if(SHOW_TREES) printf("new_declarator2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case DIRECT_NEW_DECLARATORr1 :
				if(SHOW_TREES) printf("direct_new_declarator1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DIRECT_NEW_DECLARATORr2 :
				if(SHOW_TREES) printf("direct_new_declarator2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case NEW_INITIALIZERr1 :
				if(SHOW_TREES) printf("new_initializer1\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case DELETE_EXPRESSIONr1 :
				if(SHOW_TREES) printf("delete_expression1\n");
				node->type = node->u.n.child[1]->type;
				break;
			case DELETE_EXPRESSIONr2 :
				if(SHOW_TREES) printf("delete_expression2\n");
				node->type = node->u.n.child[2]->type;
				break;
			case DELETE_EXPRESSIONr3 :
				if(SHOW_TREES) printf("delete_expression3\n");
				node->type = node->u.n.child[1]->type;
				break;
			case DELETE_EXPRESSIONr4 :
				if(SHOW_TREES) printf("delete_expression4\n");
				node->type = node->u.n.child[2]->type;
				break;
	
			case CAST_EXPRESSIONr1 :
				if(SHOW_TREES) printf("cast_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case CAST_EXPRESSIONr2 :
				if(SHOW_TREES) printf("cast_expression2\n");
				node->type = node->u.n.child[0]->type;
				break;
	
			case PM_EXPRESSIONr1 :
				if(SHOW_TREES) printf("pm_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case PM_EXPRESSIONr2 :
			/*????????????????*/
				if(SHOW_TREES) printf("pm_expression2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case PM_EXPRESSIONr3 :
			/*????????????????*/
				if(SHOW_TREES) printf("pm_expression3\n");
				node->type = node->u.n.child[0]->type;
				break;
/*
pm_expression:
	cast_expression													{ $$ = (TreeNode *)alacnary(PM_EXPRESSIONr1, 1, $1); }
	| pm_expression DOTSTAR cast_expression					{ $$ = (TreeNode *)alacnary(PM_EXPRESSIONr2, 3, $1, $2, $3); }
	| pm_expression ARROWSTAR cast_expression					{ $$ =(TreeNode *)alacnary(PM_EXPRESSIONr3, 3, $1, $2, $3); }
	;*/
	/******************************************************************************************************************/
			case MULTIPLICATIVE_EXPRESSIONr1 :
				if(SHOW_TREES) printf("multiplicative_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case MULTIPLICATIVE_EXPRESSIONr2 :
				if(SHOW_TREES) printf("multiplicative_expression2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case MULTIPLICATIVE_EXPRESSIONr3 :
				if(SHOW_TREES) printf("multiplicative_expression3\n");
				node->type = node->u.n.child[0]->type;
				break;
			case MULTIPLICATIVE_EXPRESSIONr4 :
				if(SHOW_TREES) printf("multiplicative_expression4\n");
				node->type = node->u.n.child[0]->type;
				break;

			case ADDITIVE_EXPRESSIONr1 :
				if(SHOW_TREES) printf("additive_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case ADDITIVE_EXPRESSIONr2 :
				if(SHOW_TREES) printf("additive_expression2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case ADDITIVE_EXPRESSIONr3 :
				if(SHOW_TREES) printf("additive_expression3\n");
				node->type = node->u.n.child[0]->type;
				break;
	/***********************************************************************************************************************/
			case SHIFT_EXPRESSIONr1 :
				if(SHOW_TREES) printf("shift_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case SHIFT_EXPRESSIONr2 :
			/*??????????????????*/
				if(SHOW_TREES) printf("shift_expression2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case SHIFT_EXPRESSIONr3 :
			/*??????????????????*/
				if(SHOW_TREES) printf("shift_expression3\n");
				node->type = node->u.n.child[0]->type;
				break;
			
			case RELATIONAL_EXPRESSIONr1 :
				if(SHOW_TREES) printf("relational_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case RELATIONAL_EXPRESSIONr2 :
			/*??????????????????*/
				if(SHOW_TREES) printf("relational_expression2\n");
				node->type = getType(BOOL_TYPE);
				break;
			case RELATIONAL_EXPRESSIONr3 :
			/*??????????????????*/
				if(SHOW_TREES) printf("relational_expression3\n");
				node->type = getType(BOOL_TYPE);
				break;
			case RELATIONAL_EXPRESSIONr4 :
			/*??????????????????*/
				if(SHOW_TREES) printf("relational_expression4\n");
				node->type = getType(BOOL_TYPE);
				break;
				
			case EQUALITY_EXPRESSIONr1 :
				if(SHOW_TREES) printf("equality_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case EQUALITY_EXPRESSIONr2 :
				if(SHOW_TREES) printf("equality_expression2\n");
				node->type = getType(BOOL_TYPE);
				break;
			case EQUALITY_EXPRESSIONr3 :
				if(SHOW_TREES) printf("equality_expression3\n");
				node->type = getType(BOOL_TYPE);
				break;
				
			case AND_EXPRESSIONr1 :
				if(SHOW_TREES) printf("and_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case AND_EXPRESSIONr2 :
				if(SHOW_TREES) printf("and_expression2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case EXCLUSIVE_OR_EXPRESSIONr1 :
				if(SHOW_TREES) printf("exclusive_or_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case EXCLUSIVE_OR_EXPRESSIONr2 :
				if(SHOW_TREES) printf("exclusive_or_expression2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case INCLUSIVE_OR_EXPRESSIONr1 :
				if(SHOW_TREES) printf("inclusive_or_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case INCLUSIVE_OR_EXPRESSIONr2 :
				if(SHOW_TREES) printf("inclusive_or_expression2\n");
				node->type = node->u.n.child[0]->type;
				break;

			case LOGICAL_AND_EXPRESSIONr1 :
				if(SHOW_TREES) printf("logical and expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case LOGICAL_AND_EXPRESSIONr2 :
				if(SHOW_TREES) printf("logical and expression2\n");
				node->type = node->u.n.child[0]->type;
				break;

			case LOGICAL_OR_EXPRESSIONr1 :
				if(SHOW_TREES) printf("logical or expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case LOGICAL_OR_EXPRESSIONr2 :
				if(SHOW_TREES) printf("logical or expression2\n");
				node->type = node->u.n.child[0]->type;
				break;

			case CONDITIONAL_EXPRESSIONr1 :
				if(SHOW_TREES) printf("conditional expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case CONDITIONAL_EXPRESSIONr2 :
				if(SHOW_TREES) printf("conditional expression2\n");
				node->type = node->u.n.child[0]->type;
				break;

			case ASSIGNMENT_EXPRESSIONr1 :
				if(SHOW_TREES) printf("assignment expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case ASSIGNMENT_EXPRESSIONr2 :
				if(SHOW_TREES) printf("assignment expression2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case ASSIGNMENT_EXPRESSIONr3 :
				if(SHOW_TREES) printf("assignment expression3\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case ASSIGNMENT_OPERATORr1 :
				node->type = getType(OPERATOR_TYPE);
				break;
			case ASSIGNMENT_OPERATORr2 :
				node->type = getType(OPERATOR_TYPE);
				break;
			case ASSIGNMENT_OPERATORr3 :
				node->type = getType(OPERATOR_TYPE);
				break;
			case ASSIGNMENT_OPERATORr4 :
				node->type = getType(OPERATOR_TYPE);
				break;
			case ASSIGNMENT_OPERATORr5 :
				node->type = getType(OPERATOR_TYPE);
				break;
			case ASSIGNMENT_OPERATORr6 :
				node->type = getType(OPERATOR_TYPE);
				break;
			case ASSIGNMENT_OPERATORr7 :
				node->type = getType(OPERATOR_TYPE);
				break;
			case ASSIGNMENT_OPERATORr8 :
				node->type = getType(OPERATOR_TYPE);
				break;
			case ASSIGNMENT_OPERATORr9 :
				node->type = getType(OPERATOR_TYPE);
				break;
			case ASSIGNMENT_OPERATORr10 :
				node->type = getType(OPERATOR_TYPE);
				break;
			case ASSIGNMENT_OPERATORr11 :
				node->type = getType(OPERATOR_TYPE);
				break;
	
			case EXPRESSIONr1 :
				if(SHOW_TREES) printf("expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case EXPRESSIONr2 :
				if(SHOW_TREES) printf("expression2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case CONSTANT_EXPRESSIONr1 :
				//if(SHOW_TREES) printf("constant_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;

/*----------------------------------------------------------------------
 * Statements.
 *----------------------------------------------------------------------*/

			case STATEMENTr1 :
				if(SHOW_TREES) printf("statement1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case STATEMENTr2 :
				if(SHOW_TREES) printf("statement2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case STATEMENTr3 :
				if(SHOW_TREES) printf("statement3\n");
				node->type = node->u.n.child[0]->type;
				break;
			case STATEMENTr4 :
				if(SHOW_TREES) printf("statement4\n");
				node->type = node->u.n.child[0]->type;
				break;
			case STATEMENTr5 :
				if(SHOW_TREES) printf("statement5\n");
				node->type = node->u.n.child[0]->type;
				break;
			case STATEMENTr6 :
				if(SHOW_TREES) printf("statement6\n");
				node->type = node->u.n.child[0]->type;
				break;
			case STATEMENTr7 :
				if(SHOW_TREES) printf("statement7\n");
				node->type = node->u.n.child[0]->type;
				break;
			case STATEMENTr8 :
				if(SHOW_TREES) printf("statement8\n");
				node->type = node->u.n.child[0]->type;
				break;
			
			case LABELED_STATEMENTr1 :
				if(SHOW_TREES) printf("labeled_statement1\n");
				/*if(node->u.n.child[0]->type->base_type != INT_TYPE || node->u.n.child[0]->type->base_type != ENUM_TYPE){
					exitStatus = 3;
					getErrorMessage(ER_INT_EXPECTED);
					yyerror(NULL);
				}*/
				node->type = getType(STATEMENT_TYPE);
				break;
			case LABELED_STATEMENTr2 :
				if(SHOW_TREES) printf("labeled_statement2\n");
				if(node->u.n.child[1]->type->base_type != INT_TYPE || node->u.n.child[1]->type->base_type != ENUM_TYPE){
					exitStatus = 3;
					getErrorMessage(ER_INT_EXPECTED);
					yyerror(NULL);
				}
				node->type = getType(STATEMENT_TYPE);
				break;
			case LABELED_STATEMENTr3 :
				if(SHOW_TREES) printf("labeled_statement3\n");
				node->type = getType(STATEMENT_TYPE);
				break;
	
			case EXPRESSION_STATEMENTr1 :
				if(SHOW_TREES) printf("expression statement1\n");
				node->type = getType(STATEMENT_TYPE);
				break;

			case COMPOUND_STATEMENTr1 :
				if(SHOW_TREES) printf("compound statement1\n");
				node->type = getType(STATEMENT_TYPE);
				break;

			case STATEMENT_SEQr1 :
				if(SHOW_TREES) printf("statement seq1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case STATEMENT_SEQr2 :
				if(SHOW_TREES) printf("statement seq2\n");
				node->type = getType(TOUPLE_TYPE);
				node->type->u.touple.nelems = 2;
				node->type->u.touple.elems = calloc(2, sizeof(struct typeinfo *));
				node->type->u.touple.elems[0] = node->u.n.child[0]->type;
				node->type->u.touple.elems[1] = node->u.n.child[1]->type;
				break;

			case CONDITIONr1 :
				if(SHOW_TREES) printf("condition1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case CONDITIONr2 :
				if(SHOW_TREES) printf("condition2\n");
				node->type = getOperatorType(node->u.n.child[0]->type,node->u.n.child[2]->type);
				break;
				
			case SELECTION_STATEMENTr1 :
				if(SHOW_TREES) printf("selection_statement1\n");
				node->type = getType(STATEMENT_TYPE);
				if(node->u.n.child[1]->type->base_type != BOOL_TYPE || node->u.n.child[1]->type->base_type != INT_TYPE){
					exitStatus = 3;
					getErrorMessage(ER_BOOL_EXPECTED);
					yyerror(NULL);
				}
				node->u.n.child[0]->type = node->type;
				break;
			case SELECTION_STATEMENTr2 :
				if(SHOW_TREES) printf("selection_statement2\n");
				node->type = getType(STATEMENT_TYPE);
				if(node->u.n.child[1]->type->base_type != BOOL_TYPE || node->u.n.child[1]->type->base_type != INT_TYPE){
					exitStatus = 3;
					getErrorMessage(ER_BOOL_EXPECTED);
					yyerror(NULL);
				}
				node->u.n.child[0]->type = node->type;
				break;
			case SELECTION_STATEMENTr3 :
				if(SHOW_TREES) printf("selection_statement3\n");
				node->type = getType(STATEMENT_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
	
			case ITERATION_STATEMENTr1 :
				if(SHOW_TREES) printf("iteration statement1\n");
				node->type = getType(STATEMENT_TYPE);
				if(node->u.n.child[1]->type->base_type != BOOL_TYPE){
					exitStatus = 2;
					getErrorMessage(ER_BOOL_EXPECTED);
					yyerror(NULL);
				}
				node->u.n.child[0]->type = node->type;
				break;
			case ITERATION_STATEMENTr2 :
				if(SHOW_TREES) printf("iteration statement2\n");
				node->type = getType(STATEMENT_TYPE);
				if(node->u.n.child[3]->type->base_type != BOOL_TYPE){
					exitStatus = 3;
					getErrorMessage(ER_BOOL_EXPECTED);
					yyerror(NULL);
				}
				node->u.n.child[0]->type = node->type;
				break;
			case ITERATION_STATEMENTr3 :
				if(SHOW_TREES) printf("iteration statement3\n");
				node->type = getType(STATEMENT_TYPE);
				
				node->u.n.child[0]->type = node->type;
				break;
	
			case FOR_INIT_STATEMENTr1 :
				if(SHOW_TREES) printf("for_init_statement1");
				node->type = node->u.n.child[0]->type;
				break;
			case FOR_INIT_STATEMENTr2 :
				if(SHOW_TREES) printf("for_init_statement2");
				node->type = node->u.n.child[0]->type;
				break;
				
			case JUMP_STATEMENTr1 :
				if(SHOW_TREES) printf("jump_statement1");
				node->type = getType(STATEMENT_TYPE);
				break;
			case JUMP_STATEMENTr2 :
				if(SHOW_TREES) printf("jump_statement2");
				node->type = getType(STATEMENT_TYPE);
				break;
			case JUMP_STATEMENTr3 :
				if(SHOW_TREES) printf("jump_statement3");
				node->type = node->u.n.child[1]->type;
				node->u.n.child[0]->type = node->type;
				break;
			case JUMP_STATEMENTr4 :
				if(SHOW_TREES) printf("jump_statement4");
				exitStatus = 3;
				getErrorMessage(ER_NOT_SUPPORTED);
				yyerror(NULL);
				exit(exitStatus);
				break;

			case DECLARATION_STATEMENTr1 :
				if(SHOW_TREES) printf("declaration statement1\n");
				node->type = node->u.n.child[0]->type;
				break;

/*----------------------------------------------------------------------
 * Declarations.
 *----------------------------------------------------------------------*/

			case DECLARATION_SEQr1 :
				if(SHOW_TREES) printf("declaration seq1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DECLARATION_SEQr2 :
				if(SHOW_TREES) printf("declaration seq2\n");
				node->type = getType(TOUPLE_TYPE);
				node->type->u.touple.nelems = 2;
				node->type->u.touple.elems = calloc(2, sizeof(struct typeinfo *));
				node->type->u.touple.elems[0] = node->u.n.child[0]->type;
				node->type->u.touple.elems[1] = node->u.n.child[1]->type;
				break;

			case DECLARATIONr1 :
				if(SHOW_TREES) printf("declaration1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DECLARATIONr2 :
				if(SHOW_TREES) printf("declaration2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DECLARATIONr4 :
				if(SHOW_TREES) printf("declaration4\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DECLARATIONr5 :
				if(SHOW_TREES) printf("declaration5\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DECLARATIONr6 :
				if(SHOW_TREES) printf("declaration6\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DECLARATIONr7 :
				if(SHOW_TREES) printf("declaration7\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case BLOCK_DECLARATIONr1 :
				if(SHOW_TREES) printf("block declaration1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case BLOCK_DECLARATIONr2 :
				if(SHOW_TREES) printf("block declaration2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case BLOCK_DECLARATIONr3 :
				if(SHOW_TREES) printf("block declaration3\n");
				node->type = node->u.n.child[0]->type;
				break;
			case BLOCK_DECLARATIONr4 :
				if(SHOW_TREES) printf("block declaration4\n");
				node->type = node->u.n.child[0]->type;
				break;
			case BLOCK_DECLARATIONr5 :
				if(SHOW_TREES) printf("block declaration5\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case SIMPLE_DECLARATIONr1 :
				if(SHOW_TREES) printf("simple declaration1\n");
				if(node->u.n.child[1]->type->base_type == ARRAY_TYPE){
					node->type = node->u.n.child[1]->type;
					node->type->u.arry.elemtype = node->u.n.child[0]->type;
				} else if(node->u.n.child[1]->type->base_type == TOUPLE_TYPE){
					node->type = node->u.n.child[0]->type;
					if(node->u.n.child[0]->type->label != NULL){
						if((node->type->ref = calloc(strlen(node->u.n.child[0]->type->label), sizeof(char))) == NULL) memoryError();
						strcpy(node->type->ref, node->u.n.child[0]->type->label);
					}
					node->type->label = node->u.n.child[1]->type->label;
					passTypeToDeclarationList(node->u.n.child[0]->type, node->u.n.child[1]);
				} else {
					node->type = node->u.n.child[0]->type;
					if(node->u.n.child[0]->type->label != NULL){
						if((node->type->ref = calloc(strlen(node->u.n.child[0]->type->label), sizeof(char))) == NULL) memoryError();
						strcpy(node->type->ref, node->u.n.child[0]->type->label);
					}
					node->type->label = node->u.n.child[1]->type->label;
					passTypeBelowPointer(node->u.n.child[0]->type, node->u.n.child[1]->type);
				}
				break;
			case SIMPLE_DECLARATIONr2 :
				if(SHOW_TREES) printf("simple declaration2\n");
				node->type = node->u.n.child[0]->type;
				break;

			case DECL_SPECIFIERr1:
				if(SHOW_TREES) printf("decl specifier1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DECL_SPECIFIERr2:
				if(SHOW_TREES) printf("decl specifier2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DECL_SPECIFIERr3:
				if(SHOW_TREES) printf("decl specifier3\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DECL_SPECIFIERr4:
				if(SHOW_TREES) printf("decl specifier4\n");
				exitStatus = 3;
				getErrorMessage(ER_NOT_SUPPORTED);
				yyerror("friend");
				exit(exitStatus);
				break;
			case DECL_SPECIFIERr5:
				if(SHOW_TREES) printf("decl specifier5\n");
				exitStatus = 3;
				getErrorMessage(ER_NOT_SUPPORTED);
				yyerror("typedef");
				exit(exitStatus);
				break;
				
			case DECL_SPECIFIER_SEQr1:
				if(SHOW_TREES) printf("decl specifier seq1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DECL_SPECIFIER_SEQr2:
				if(SHOW_TREES) printf("decl specifier seq2\n");
				node->type = getType(TOUPLE_TYPE);
				node->type->u.touple.nelems = 2;
				node->type->u.touple.elems = calloc(2, sizeof(struct typeinfo *));
				node->type->u.touple.elems[0] = node->u.n.child[0]->type;
				node->type->u.touple.elems[1] = node->u.n.child[1]->type;
				break;
/*
THESE ARE NOT SUPPORTED IN 120++
storage_class_specifier:
	AUTO																	{ $$ = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr1, 1, $1); }
	| REGISTER															{ $$ = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr2, 1, $1); }
	| STATIC																{ $$ = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr3, 1, $1); }
	| EXTERN																{ $$ = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr4, 1, $1); }
	| MUTABLE															{ $$ = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr5, 1, $1); }
	;

function_specifier:
	INLINE																{ $$ = (TreeNode *)alacnary(FUNCTION_SPECIFIERr1, 1, $1); }
	| VIRTUAL															{ $$ = (TreeNode *)alacnary(FUNCTION_SPECIFIERr2, 1, $1); }
	| EXPLICIT															{ $$ = (TreeNode *)alacnary(FUNCTION_SPECIFIERr3, 1, $1); }
	;*/

			
			case TYPE_SPECIFIERr1:
				if(SHOW_TREES) printf("type specifier1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case TYPE_SPECIFIERr2:
				if(SHOW_TREES) printf("type specifier2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case TYPE_SPECIFIERr3:
				if(SHOW_TREES) printf("type specifier3\n");
				node->type = node->u.n.child[0]->type;
				break;
			case TYPE_SPECIFIERr4:
				if(SHOW_TREES) printf("type specifier4\n");
				node->type = node->u.n.child[0]->type;
				break;
			case TYPE_SPECIFIERr5:
				if(SHOW_TREES) printf("type specifier5\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case SIMPLE_TYPE_SPECIFIERr1:
				if(SHOW_TREES) printf("simple type specifier1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr2:
				if(SHOW_TREES) printf("simple type specifier2\n");
				node->type = getType(TOUPLE_TYPE);
				break;
			case SIMPLE_TYPE_SPECIFIERr3:
				if(SHOW_TREES) printf("simple type specifier3\n");
				node->type = getType(TOUPLE_TYPE);
				break;
			case SIMPLE_TYPE_SPECIFIERr4:
				if(SHOW_TREES) printf("simple type specifier4\n");
				node->type = getType(CHAR_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr5:
				if(SHOW_TREES) printf("simple type specifier5\n");
				node->type = getType(WCHAR_T_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr6:
				if(SHOW_TREES) printf("simple type specifier6\n");
				node->type = getType(BOOL_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr7:
				if(SHOW_TREES) printf("simple type specifier7\n");
				node->type = getType(SHORT_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr8:
				if(SHOW_TREES) printf("simple type specifier8\n");
				node->type = getType(INT_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr9:
				if(SHOW_TREES) printf("simple type specifier9\n");
				node->type = getType(LONG_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr10:
				if(SHOW_TREES) printf("simple type specifier10\n");
				node->type = getType(SIGNED_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr11:
				if(SHOW_TREES) printf("simple type specifier11\n");
				node->type = getType(UNSIGNED_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr12:
				if(SHOW_TREES) printf("simple type specifier12\n");
				node->type = getType(FLOAT_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr13:
				if(SHOW_TREES) printf("simple type specifier13\n");
				node->type = getType(DOUBLE_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr14:
				if(SHOW_TREES) printf("simple type specifier14\n");
				node->type = getType(VOID_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr15:
				if(SHOW_TREES) printf("simple type specifier15\n");
				node->type = getType(STR_TYPE_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			
			case TYPE_NAMEr1:
				if(SHOW_TREES) printf("type name1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case TYPE_NAMEr2:
				if(SHOW_TREES) printf("type name2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case TYPE_NAMEr3: 
				if(SHOW_TREES) printf("type name3\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case ELABORATED_TYPE_SPECIFIERr1 :
				if(SHOW_TREES) printf("elaborated_type_specifier1\n");
				node->type = node->u.n.child[2]->type;
				break;
			case ELABORATED_TYPE_SPECIFIERr2 :
				if(SHOW_TREES) printf("elaborated_type_specifier2\n");
				node->type = node->u.n.child[2]->type;
				break;
			case ELABORATED_TYPE_SPECIFIERr3 :
				if(SHOW_TREES) printf("elaborated_type_specifier3\n");
				node->type = node->u.n.child[1]->type;
				break;
			case ELABORATED_TYPE_SPECIFIERr4 :
				if(SHOW_TREES) printf("elaborated_type_specifier4\n");
				node->type = node->u.n.child[1]->type;
				break;
			case ELABORATED_TYPE_SPECIFIERr5 :
				if(SHOW_TREES) printf("elaborated_type_specifier5\n");
				node->type = node->u.n.child[1]->type;
				break;
			case ELABORATED_TYPE_SPECIFIERr6 :
				if(SHOW_TREES) printf("elaborated_type_specifier6\n");
				node->type = node->u.n.child[2]->type;
				break;
/*
elaborated_type_specifier:
	class_key COLONCOLON nested_name_specifier identifier	{ $$ = (TreeNode *)alacnary(ELABORATED_TYPE_SPECIFIERr1, 4, $1, $2, $3, $4); }
	| class_key COLONCOLON identifier							{ $$ = (TreeNode *)alacnary(ELABORATED_TYPE_SPECIFIERr2, 3, $1, $2, $3); }
	| ENUM COLONCOLON nested_name_specifier identifier		{ $$ = (TreeNode *)alacnary(ELABORATED_TYPE_SPECIFIERr3, 4, $1, $2, $3, $4); }
	| ENUM COLONCOLON identifier									{ $$ = (TreeNode *)alacnary(ELABORATED_TYPE_SPECIFIERr4, 3, $1, $2, $3); }
	| ENUM nested_name_specifier identifier					{ $$ = (TreeNode *)alacnary(ELABORATED_TYPE_SPECIFIERr5, 3, $1, $2, $3); }
	| TYPENAME COLONCOLON_opt nested_name_specifier identifier
																			{ $$ = (TreeNode *)alacnary(ELABORATED_TYPE_SPECIFIERr6, 4, $1, $2, $3, $4); }
	;*/

			case ENUM_SPECIFIERr1 :
				if(SHOW_TREES) printf("enum specifier1\n");
				node->type = getType(ENUM_TYPE);
				break;
				
			case ENUMERATOR_LISTr1 :
				if(SHOW_TREES) printf("enumerator_list1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case ENUMERATOR_LISTr2 :
				if(SHOW_TREES) printf("enumerator_list2\n");
				node->type = getType(TOUPLE_TYPE);
				node->type->u.touple.nelems = 2;
				node->type->u.touple.elems = calloc(2, sizeof(struct typeinfo *));
				node->type->u.touple.elems[0] = node->u.n.child[0]->type;
				node->type->u.touple.elems[1] = node->u.n.child[1]->type;
				break;

			case ENUMERATOR_DEFINITIONr1 :
				if(SHOW_TREES) printf("enumerator_definition1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case ENUMERATOR_DEFINITIONr2 :
				if(SHOW_TREES) printf("enumerator_definition2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case ENUMERATORr1 :
				if(SHOW_TREES) printf("enumerator1\n");
				node->type = node->u.n.child[0]->type;
				break;

			case NAMESPACE_DEFINITIONr1 :
			case NAMESPACE_DEFINITIONr2 :
			case NAMED_NAMESPACE_DEFINITIONr1 :
			case NAMED_NAMESPACE_DEFINITIONr2 :
			case ORIGINAL_NAMESPACE_DEFINITIONr1 :
			case EXTENSION_NAMESPACE_DEFINITIONr1 :
			case UNNAMED_NAMESPACE_DEFINITIONr1 :
			case NAMESPACE_BODYr1 :
			case NAMESPACE_ALIAS_DEFINITIONr1 :
			case QUALIFIED_NAMESPACE_SPECIFIERr1 :
			case QUALIFIED_NAMESPACE_SPECIFIERr2 :
			case QUALIFIED_NAMESPACE_SPECIFIERr3 :
			case QUALIFIED_NAMESPACE_SPECIFIERr4 :
			case USING_DECLARATIONr1 :
			case USING_DECLARATIONr2 :
			case USING_DECLARATIONr3 :
			case USING_DECLARATIONr4 :
			case USING_DECLARATIONr5 :
			case USING_DIRECTIVEr1 :
			case USING_DIRECTIVEr2 :
			case USING_DIRECTIVEr3 :
			case USING_DIRECTIVEr4 :
				exitStatus = 3;
				getErrorMessage(ER_NOT_SUPPORTED);
				yyerror("namespace");
				break;
				
			case ASM_DEFINITIONr1 :
				if(SHOW_TREES) printf("asm_definition1\n");
				node->type = node->u.n.child[1]->type;
				break;
			
			case LINKAGE_SPECIFICATIONr1 :
			case LINKAGE_SPECIFICATIONr2 :
				exitStatus = 3;
				getErrorMessage(ER_NOT_SUPPORTED);
				yyerror("extern");
				break;

/*----------------------------------------------------------------------
 * Declarators.
 *----------------------------------------------------------------------*/

			case INIT_DECLARATOR_LISTr1 :
				if(SHOW_TREES) printf("init declarator list1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case INIT_DECLARATOR_LISTr2 :
				if(SHOW_TREES) printf("init declarator list2\n");
				node->type = getType(TOUPLE_TYPE);
				node->type->u.touple.nelems = 2;
				node->type->u.touple.elems = calloc(2, sizeof(struct typeinfo *));
				node->type->u.touple.elems[0] = node->u.n.child[0]->type;
				node->type->u.touple.elems[1] = node->u.n.child[1]->type;
				break;

			case INIT_DECLARATORr1 :
				if(SHOW_TREES) printf("init declarator1 \n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case DECLARATORr1:
				if(SHOW_TREES) printf("declarator1 %\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DECLARATORr2:
				if(SHOW_TREES) printf("declarator2\n");
				node->type = getType(POINTER_TYPE);
				node->type->u.ptr = node->u.n.child[1]->type;
				node->type->label = node->u.n.child[1]->type->label;
				break;
				
			case DIRECT_DECLARATORr1:
				if(SHOW_TREES) printf("direct declarator1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DIRECT_DECLARATORr2:
				if(SHOW_TREES) printf("direct declarator2\n");
				node->type = getType(FUNC_TYPE);
				node->type->u.func.parent = NULL;
				node->type->label = node->u.n.child[0]->type->label;
				node->type->u.func.nargs = 0;
				addParamsToFunction(node, node->u.n.child[1]->type);
				passTypeBelowPointer(node->type, node->u.n.child[0]->type);
				break;
			case DIRECT_DECLARATORr3:
				if(SHOW_TREES) printf("direct declarator3\n");
				node->type = getType(FUNC_TYPE);
				node->type->u.func.parent = NULL;
				node->type->label = node->u.n.child[0]->type->label;
				node->type->u.func.nargs = 0;
				addParamsToFunction(node, node->u.n.child[1]->type);
				passTypeBelowPointer(node->type, node->u.n.child[0]->type);
				break;
			case DIRECT_DECLARATORr4:
				if(SHOW_TREES) printf("direct declarator4\n");
				node->type = getType(FUNC_TYPE);
				node->type->u.func.parent = NULL;
				node->type->label = node->u.n.child[0]->type->label;
				node->type->u.func.nargs = 0;
				addParamsToFunction(node, node->u.n.child[1]->type);
				passTypeBelowPointer(node->type, node->u.n.child[0]->type);
				break;
			case DIRECT_DECLARATORr5:
				if(SHOW_TREES) printf("direct declarator5\n");
				node->type = getType(FUNC_TYPE);
				node->type->u.func.parent = NULL;
				node->type->label = node->u.n.child[0]->type->label;
				node->type->u.func.nargs = 0;
				addParamsToFunction(node, node->u.n.child[1]->type);
				passTypeBelowPointer(node->type, node->u.n.child[0]->type);
				break;
			case DIRECT_DECLARATORr6:
			/*????????*/
				if(SHOW_TREES) printf("direct declarator6\n");
				node->type = node->u.n.child[0]->type;
				//node->type->temp = node->u.n.child[1]->type;
				break;
			case DIRECT_DECLARATORr7:
				if(SHOW_TREES) printf("direct declarator7\n");
				node->type = getType(FUNC_TYPE);
				node->type->u.func.parent = node->u.n.child[0]->u.t.token->text;
				node->type->label = node->u.n.child[2]->type->label;
				node->type->u.func.nargs = 0;
				addParamsToFunction(node, node->u.n.child[3]->type);
				break;
			case DIRECT_DECLARATORr8:
			/*????????*/
				if(SHOW_TREES) printf("direct declarator8\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DIRECT_DECLARATORr9:
				if(SHOW_TREES) printf("direct declarator9\n");
				if(node->u.n.child[1]->type->base_type != INT_TYPE){
					exitStatus = 3;
					getErrorMessage(ER_INT_EXPECTED);
					yyerror(NULL);
				}
				node->type = getType(ARRAY_TYPE);
				node->type->label = node->u.n.child[0]->type->label;
				node->type->pub = node->u.n.child[0]->type->pub;
				node->type->u.arry.size = atoi(node->u.n.child[1]->type->label);
				
				break;
			case DIRECT_DECLARATORr10:
				if(SHOW_TREES) printf("direct declarator10\n");
				node->type = node->u.n.child[1]->type;
				break;
				
			case DECLARATOR_IDr1:
				if(SHOW_TREES) printf("declarator id1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DECLARATOR_IDr2:
				if(SHOW_TREES) printf("declarator id2\n");
				node->type = node->u.n.child[1]->type;
				break;
			case DECLARATOR_IDr3:
				if(SHOW_TREES) printf("declarator id3\n");
			/*????????*/
				node->type = node->u.n.child[2]->type;
				break;
			case DECLARATOR_IDr4:
				if(SHOW_TREES) printf("declarator id4\n");
			/*????????*/
				node->type = node->u.n.child[1]->type;
				break;
				
			case PTR_OPERATORr1 :
				if(SHOW_TREES) printf("ptr operator1\n");
				node->type = getType(POINTER_TYPE);
				break;
			case PTR_OPERATORr2 :
				if(SHOW_TREES) printf("ptr operator2\n");
				node->type = getType(POINTER_TYPE);
				break;
			case PTR_OPERATORr3 :
				if(SHOW_TREES) printf("ptr operator3\n");
				node->type = getType(ADDRESS_TYPE);
				break;
			case PTR_OPERATORr4 :
				if(SHOW_TREES) printf("ptr operator4\n");
				node->type = getType(POINTER_TYPE);
				break;
			case PTR_OPERATORr5 :
				if(SHOW_TREES) printf("ptr operator5\n");
				node->type = getType(POINTER_TYPE);
				break;
			case PTR_OPERATORr6 :
				if(SHOW_TREES) printf("ptr operator6\n");
				node->type = getType(POINTER_TYPE);
				break;
			case PTR_OPERATORr7 :
				if(SHOW_TREES) printf("ptr operator7\n");
				node->type = getType(POINTER_TYPE);
				break;

			case CV_QUALIFIER_SEQr1 :
				if(SHOW_TREES) printf("cv qualifier seq1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case CV_QUALIFIER_SEQr2 :
				if(SHOW_TREES) printf("cv qualifier seq2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case TYPE_IDr1 :
				if(SHOW_TREES) printf("type_id1\n");
				node->type = node->u.n.child[0]->type;
				break;
				/*
type_id:
	type_specifier_seq abstract_declarator_opt				{ $$ = (TreeNode *)alacnary(TYPE_IDr1, 2, $1, $2); }
	;*/
	
			case TYPE_SPECIFIER_SEQr1 :
				if(SHOW_TREES) printf("type_specifier_id1\n");
				node->type = node->u.n.child[0]->type;
				break;
/*
type_specifier_seq:
	type_specifier type_specifier_seq_opt						{ $$ = (TreeNode *)alacnary(TYPE_SPECIFIER_SEQr1, 2, $1, $2); }
	;*/
	
			case ABSTRACT_DECLARATORr1 :
				if(SHOW_TREES) printf("abstract_declarator1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case ABSTRACT_DECLARATORr2 :
				if(SHOW_TREES) printf("abstract_declarator2\n");
				node->type = node->u.n.child[0]->type;
				break;

/*
abstract_declarator:
	ptr_operator abstract_declarator_opt						{ $$ = (TreeNode *)alacnary(ABSTRACT_DECLARATORr1, 2, $1, $2); }
	| direct_abstract_declarator									{ $$ = (TreeNode *)alacnary(ABSTRACT_DECLARATORr2, 1, $1); }
	;*/
			case DIRECT_ABSTRACT_DECLARATORr1 :
				if(SHOW_TREES) printf("direct_abstract_declarator1\n");
				node->type = getType(FUNC_TYPE);
				break;
			case DIRECT_ABSTRACT_DECLARATORr2 :
				if(SHOW_TREES) printf("direct_abstract_declarator2\n");
				node->type = getType(FUNC_TYPE);
				break;
			case DIRECT_ABSTRACT_DECLARATORr3 :
				if(SHOW_TREES) printf("direct_abstract_declarator3\n");
				node->type = getType(FUNC_TYPE);
				break;
			case DIRECT_ABSTRACT_DECLARATORr4 :
				if(SHOW_TREES) printf("direct_abstract_declarator4\n");
				node->type = getType(FUNC_TYPE);
				break;
			case DIRECT_ABSTRACT_DECLARATORr5 :
				if(SHOW_TREES) printf("direct_abstract_declarator5\n");
				node->type = getType(ARRAY_TYPE);
				break;
			case DIRECT_ABSTRACT_DECLARATORr6 :
				if(SHOW_TREES) printf("direct_abstract_declarator6\n");
				node->type = node->u.n.child[0]->type;
				break;
	/*
direct_abstract_declarator:
	direct_abstract_declarator_opt '(' parameter_declaration_clause ')' cv_qualifier_seq exception_specification
																			{ $$ = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATORr1, 4, $1, $3, $5, $6); }
	| direct_abstract_declarator_opt '(' parameter_declaration_clause ')' cv_qualifier_seq
																			{ $$ = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATORr2, 3, $1, $3, $5); }
	| direct_abstract_declarator_opt '(' parameter_declaration_clause ')' exception_specification
																			{ $$ = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATORr3, 3, $1, $3, $5); }
	| direct_abstract_declarator_opt '(' parameter_declaration_clause ')'
																			{ $$ = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATORr4, 2, $1, $3); }
	| direct_abstract_declarator_opt '[' constant_expression_opt ']'
																			{ $$ = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATORr5, 2, $1, $3); }
	| '(' abstract_declarator ')'									{ $$ = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATORr6, 1, $2); }																		
	;*/
			case PARAMETER_DECLARATION_CLAUSEr1 :
				if(SHOW_TREES) printf("parameter declaration clause1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case PARAMETER_DECLARATION_CLAUSEr2 :
				if(SHOW_TREES) printf("parameter declaration clause2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case PARAMETER_DECLARATION_CLAUSEr3 :
				if(SHOW_TREES) printf("parameter declaration clause3\n");
				node->type = getType(ELLIPSIS_TYPE);
				break;
			case PARAMETER_DECLARATION_CLAUSEr4 :
				if(SHOW_TREES) printf("parameter declaration clause4\n");
				node->type = getType(NULL_TYPE);
				break;
			case PARAMETER_DECLARATION_CLAUSEr5 :
				if(SHOW_TREES) printf("parameter declaration clause5\n");
				node->type = node->u.n.child[0]->type;
				break;
	/*
parameter_declaration_clause:
	parameter_declaration_list ELLIPSIS							{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr1, 2, $1, $2); }
	| parameter_declaration_list									{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr2, 1, $1); }
	| ELLIPSIS															{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr3, 1, $1); }
	| /* epsilon *//*													{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr4, 0); }
	| parameter_declaration_list ',' ELLIPSIS					{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr5, 2, $1, $3); }
	;*/
	
			case PARAMETER_DECLARATION_LISTr1 :
				if(SHOW_TREES) printf("parameter declaration list1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case PARAMETER_DECLARATION_LISTr2 :
				if(SHOW_TREES) printf("parameter declaration list2\n");
				node->type = getType(TOUPLE_TYPE);
				node->type->u.touple.nelems = 2;
				node->type->u.touple.elems = calloc(2, sizeof(struct typeinfo *));
				node->type->u.touple.elems[0] = node->u.n.child[0]->type;
				node->type->u.touple.elems[1] = node->u.n.child[1]->type;
				break;
	
			case PARAMETER_DECLARATIONr1 :
				if(SHOW_TREES) printf("parameter declaration1\n");
				if(node->u.n.child[1]->type->base_type == POINTER_TYPE){
					node->type = node->u.n.child[1]->type;
					passTypeBelowPointer(node->u.n.child[0]->type, node->u.n.child[1]->type);
				}else{
					node->type = node->u.n.child[0]->type;
					node->u.n.child[1]->type->base_type = node->u.n.child[0]->type->base_type;
				}
				node->type->label = node->u.n.child[1]->type->label;
				break;
			case PARAMETER_DECLARATIONr2 :
				if(SHOW_TREES) printf("parameter declaration2\n");
				if(node->u.n.child[1]->type->base_type == POINTER_TYPE){
					node->type = node->u.n.child[1]->type;
					passTypeBelowPointer(node->u.n.child[0]->type, node->u.n.child[1]->type);
				}else{
					node->type = node->u.n.child[0]->type;
					node->u.n.child[1]->type->base_type = node->u.n.child[0]->type->base_type;
				}
				node->type->label = node->u.n.child[1]->type->label;
				break;
			case PARAMETER_DECLARATIONr3 :
				if(SHOW_TREES) printf("parameter declaration3\n");
				node->type = node->u.n.child[0]->type;
				//passTypeBelowPointer(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;
			case PARAMETER_DECLARATIONr4 :
				if(SHOW_TREES) printf("parameter declaration4\n");
				node->type = node->u.n.child[0]->type;
				passTypeBelowPointer(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;
				
			case FUNCTION_DEFINITIONr1:
				if(SHOW_TREES) printf("function definition1\n");
				node->type = node->u.n.child[0]->type;
				node->type->u.func.retType = getType(VOID_TYPE);
				passTypeBelowPointer(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;	
			case FUNCTION_DEFINITIONr2:
				if(SHOW_TREES) printf("function definition2\n");
				node->type = node->u.n.child[1]->type;
				node->type->u.func.retType = node->u.n.child[0]->type;
				passTypeBelowPointer(node->type, node->u.n.child[1]->type);
				break;
			case FUNCTION_DEFINITIONr3:
				if(SHOW_TREES) printf("function definition3\n");
				node->type = node->u.n.child[0]->type;
				passTypeBelowPointer(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;
			case FUNCTION_DEFINITIONr4:
				if(SHOW_TREES) printf("function definition4\n");
				node->type = node->u.n.child[1]->type;
				node->type->u.func.retType = node->u.n.child[0]->type;
				passTypeBelowPointer(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;
				
			case FUNCTION_BODYr1 :
				if(SHOW_TREES) printf("function body1\n");
				node->type = getType(FUNC_TYPE);
				break;
				
			case INITIALIZERr1 :
				if(SHOW_TREES) printf("initializer1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case INITIALIZERr2 :
				if(SHOW_TREES) printf("initializer2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case INITIALIZER_CLAUSEr1 :
				if(SHOW_TREES) printf("initializer clause1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case INITIALIZER_CLAUSEr2 :
				if(SHOW_TREES) printf("initializer clause2\n");
				node->type = node->u.n.child[1]->type;
				break;
			case INITIALIZER_CLAUSEr3 :
				if(SHOW_TREES) printf("initializer clause3\n");
				node->type = getType(NULL_TYPE);
				break;
				
			case INITIALIZER_LISTr1 :
				if(SHOW_TREES) printf("initializer list1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case INITIALIZER_LISTr2 :
				if(SHOW_TREES) printf("initializer list2\n");
				node->type = node->u.n.child[0]->type;
				break;

/*----------------------------------------------------------------------
 * Classes.
 *----------------------------------------------------------------------*/

			case CLASS_SPECIFIERr1 :
				if(SHOW_TREES) printf("type name1\n");
				node->type = node->u.n.child[0]->type;
				addMembersToClass(node, node->u.n.child[1]->type);
				break;

			case CLASS_HEADr1 :
				if(SHOW_TREES) printf("type head1\n");
				node->type = node->u.n.child[0]->type;
				node->type->label = node->u.n.child[1]->type->label;
				node->u.n.child[1]->type = node->u.n.child[0]->type;
				break;
			case CLASS_HEADr2 :
				if(SHOW_TREES) printf("type head2\n");
				node->type = node->u.n.child[0]->type;
				node->type->label = node->u.n.child[1]->type->label;
				node->u.n.child[1]->type = node->u.n.child[0]->type;
				break;
			case CLASS_HEADr3 :
				if(SHOW_TREES) printf("type head3\n");
				node->type = node->u.n.child[0]->type;
				node->type->label = node->u.n.child[2]->type->label;
				node->u.n.child[2]->type = node->u.n.child[0]->type;
				break;
			case CLASS_HEADr4 :
				if(SHOW_TREES) printf("type head4\n");
				node->type = node->u.n.child[0]->type;
				node->type->label = node->u.n.child[2]->type->label;
				node->u.n.child[2]->type = node->u.n.child[0]->type;
				break;

			case CLASS_KEYr1 :
				if(SHOW_TREES) printf("type key1\n");
				node->type = getType(CLASS_TYPE);
				node->type->u.clas.nfields = 0;
				node->u.n.child[0]->type = node->type;
				break;
			case CLASS_KEYr2 :
				if(SHOW_TREES) printf("type key2\n");
				node->type = getType(STRUCT_TYPE);
				node->type->u.struc.nfields = 0;
				node->u.n.child[0]->type = node->type;
				break;
			case CLASS_KEYr3 :
				if(SHOW_TREES) printf("type key3\n");
				node->type = getType(UNION_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
				
			case MEMBER_SPECIFICATIONr1 :
				if(SHOW_TREES) printf("member speccification1\n");
				if(node->u.n.child[1]->type->base_type != NULL_TYPE){
					node->type = getType(TOUPLE_TYPE);
					node->type->u.touple.nelems = 2;
					node->type->u.touple.elems = calloc(2, sizeof(struct typeinfo *));
					if(SHOW_TREES) printf("%s\n", node->u.n.child[0]->type->label);
					if(SHOW_TREES) printf("%s\n", node->u.n.child[1]->type->label);
					node->type->u.touple.elems[0] = node->u.n.child[0]->type;
					node->type->u.touple.elems[1] = node->u.n.child[1]->type;
					passAccessBelow(node->u.n.child[0]->type, node->u.n.child[1]->type);
				} else {
					node->type = node->u.n.child[0]->type;
				}
				break;
			case MEMBER_SPECIFICATIONr2 :
				if(SHOW_TREES) printf("member speccification2\n");
				node->type = node->u.n.child[1]->type;
				node->type->pub = node->u.n.child[0]->type->pub;
				passAccessBelow(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;
	
			case MEMBER_DECLARATIONr1 :
				if(SHOW_TREES) printf("member declaration1\n");
				node->type = node->u.n.child[1]->type;
				passTypeBelowPointer(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;
			case MEMBER_DECLARATIONr2 :
				if(SHOW_TREES) printf("member declaration2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case MEMBER_DECLARATIONr3 :
				if(SHOW_TREES) printf("member declaration3\n");
				node->type = node->u.n.child[0]->type;
				break;
			case MEMBER_DECLARATIONr4 :
				if(SHOW_TREES) printf("member declaration4\n");
				node->type = getType(NULL_TYPE);
				break;
			case MEMBER_DECLARATIONr5 :
				if(SHOW_TREES) printf("member declaration5\n");
				node->type = node->u.n.child[0]->type;
				break;
			case MEMBER_DECLARATIONr6 :
				if(SHOW_TREES) printf("member declaration6\n");
				node->type = node->u.n.child[0]->type;
				break;
			case MEMBER_DECLARATIONr7 :
				if(SHOW_TREES) printf("member declaration7\n");
				node->type = node->u.n.child[0]->type;
				break;

			case MEMBER_DECLARATOR_LISTr1 :
				if(SHOW_TREES) printf("member declarator list1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case MEMBER_DECLARATOR_LISTr2 :
				if(SHOW_TREES) printf("member declarator list2\n");
				node->type = getType(TOUPLE_TYPE);
				node->type->u.touple.nelems = 2;
				node->type->u.touple.elems = calloc(2, sizeof(struct typeinfo *));
				node->type->u.touple.elems[0] = node->u.n.child[0]->type;
				node->type->u.touple.elems[1] = node->u.n.child[1]->type;
				break;

			case MEMBER_DECLARATORr1 :
				if(SHOW_TREES) printf("member declaration1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case MEMBER_DECLARATORr2 :
				if(SHOW_TREES) printf("member declaration2\n");
				node->type = node->u.n.child[0]->type;
				break;
			case MEMBER_DECLARATORr3 :
				if(SHOW_TREES) printf("member declaration3\n");
				node->type = node->u.n.child[0]->type;
				break;
			case MEMBER_DECLARATORr4 :
				if(SHOW_TREES) printf("member declaration4\n");
				node->type = node->u.n.child[0]->type;
				break;

/*
 * This rule need a hack for working around the ``= 0'' pure specifier.
 * 0 is returned as an ``INTEGER'' by the lexical analyzer but in this
 * context is different.
 
pure_specifier:
	'=' '0'															{ $$ = (TreeNode *)alacnary(PURE_SPECIFIERr1, 0); }
	;*/
	
			case CONSTANT_INITIALIZERr1 :
				if(SHOW_TREES) printf("constant_initializer1\n");
				node->type = node->u.n.child[1]->type;
				break;

/*----------------------------------------------------------------------
 * Derived classes.
 *---------------------------------------------------------------------

base_clause:
	':' base_specifier_list										{ $$ = (TreeNode *)alacnary(BASE_CLAUSEr1, 1, $2); }
	;

base_specifier_list:
	base_specifier													{ $$ = (TreeNode *)alacnary(BASE_SPECIFIER_LISTr1, 1, $1); }
	| base_specifier_list ',' base_specifier				{ $$ = (TreeNode *)alacnary(BASE_SPECIFIER_LISTr2, 2, $1, $3); }
	;

base_specifier:
	COLONCOLON nested_name_specifier class_name			{ $$ = (TreeNode *)alacnary(BASE_SPECIFIERr1, 3, $1, $2, $3); }
	| COLONCOLON class_name										{ $$ = (TreeNode *)alacnary(BASE_SPECIFIERr2, 2, $1, $2); }
	| nested_name_specifier class_name						{ $$ = (TreeNode *)alacnary(BASE_SPECIFIERr3, 2, $1, $2); }
	| class_name													{ $$ = (TreeNode *)alacnary(BASE_SPECIFIERr4, 1, $1); }
	| VIRTUAL access_specifier COLONCOLON nested_name_specifier_opt class_name
																		{ $$ = (TreeNode *)alacnary(BASE_SPECIFIERr5, 5, $1, $2, $3, $4, $5); }
	| VIRTUAL access_specifier nested_name_specifier_opt class_name
																		{ $$ = (TreeNode *)alacnary(BASE_SPECIFIERr6, 4, $1, $2, $3, $4); }
	| VIRTUAL COLONCOLON nested_name_specifier_opt class_name
																		{ $$ = (TreeNode *)alacnary(BASE_SPECIFIERr7, 4, $1, $2, $3, $4); }
	| VIRTUAL nested_name_specifier_opt class_name		{ $$ = (TreeNode *)alacnary(BASE_SPECIFIERr8, 3, $1, $2, $3); }
	| access_specifier VIRTUAL COLONCOLON nested_name_specifier_opt class_name
																		{ $$ = (TreeNode *)alacnary(BASE_SPECIFIERr9, 5, $1, $2, $3, $4, $5); }
	| access_specifier VIRTUAL nested_name_specifier_opt class_name
																		{ $$ = (TreeNode *)alacnary(BASE_SPECIFIERr10, 4, $1, $2, $3, $4); }
	| access_specifier COLONCOLON nested_name_specifier_opt class_name
																		{ $$ = (TreeNode *)alacnary(BASE_SPECIFIERr11, 4, $1, $2, $3, $4); }
	| access_specifier nested_name_specifier_opt class_name
																		{ $$ = (TreeNode *)alacnary(BASE_SPECIFIERr12, 3, $1, $2, $3); }
	;*/
	
			case ACCESS_SPECIFIERr1 :
				if(SHOW_TREES) printf("access specifier1\n");
				node->type = getType(UNKNOWN_TYPE);
				node->type->pub = PRIVATE_TYPE;
				node->u.n.child[0]->type = node->type;
				break;
			case ACCESS_SPECIFIERr2 :
				if(SHOW_TREES) printf("access specifier2\n");
				node->type = getType(UNKNOWN_TYPE);
				node->type->pub = PROTECTED_TYPE;
				node->u.n.child[0]->type = node->type;
				break;
			case ACCESS_SPECIFIERr3 :
				if(SHOW_TREES) printf("access specifier3\n");
				node->type = getType(UNKNOWN_TYPE);
				node->type->pub = PUBLIC_TYPE;
				node->u.n.child[0]->type = node->type;
				break;

/*----------------------------------------------------------------------
 * Special member functions.
 *----------------------------------------------------------------------

conversion_function_id:
	OPERATOR conversion_type_id								{ $$ = (TreeNode *)alacnary(CONVERSION_FUNCTION_IDr1, 2, $1, $2); }
	;

conversion_type_id:
	type_specifier_seq conversion_declarator_opt			{ $$ = (TreeNode *)alacnary(CONVERSION_TYPE_IDr1, 2, $1, $2); }
	;

conversion_declarator:
	ptr_operator conversion_declarator_opt					{ $$ = (TreeNode *)alacnary(CONVERSION_DECLARATORr1, 2, $1, $2); }
	;

ctor_initializer:
	':' mem_initializer_list									{ $$ = (TreeNode *)alacnary(CTOR_INITIALIZERr1, 1, $2); }
	;

mem_initializer_list:
	mem_initializer												{ $$ = (TreeNode *)alacnary(MEM_INITIALIZER_LISTr1, 1, $1); }
	| mem_initializer ',' mem_initializer_list			{ $$ = (TreeNode *)alacnary(MEM_INITIALIZER_LISTr1, 2, $1, $3); }
	;

mem_initializer:
	mem_initializer_id '(' expression_list_opt ')'		{ $$ = (TreeNode *)alacnary(MEM_INITIALIZERr1, 2, $1, $3); }
	;

mem_initializer_id:
	COLONCOLON nested_name_specifier class_name			{ $$ = (TreeNode *)alacnary(MEM_INITIALIZER_IDr1, 3, $1, $2, $3); }
	| COLONCOLON class_name										{ $$ = (TreeNode *)alacnary(MEM_INITIALIZER_IDr2, 2, $1, $2); }
	| nested_name_specifier class_name						{ $$ = (TreeNode *)alacnary(MEM_INITIALIZER_IDr3, 2, $1, $2); }
	| class_name													{ $$ = (TreeNode *)alacnary(MEM_INITIALIZER_IDr4, 1, $1); }
	| identifier													{ $$ = (TreeNode *)alacnary(MEM_INITIALIZER_IDr5, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Overloading.
 *----------------------------------------------------------------------

operator_function_id:
	OPERATOR operator												{ $$ = (TreeNode *)alacnary(OPERATOR_FUNCTION_IDr1, 2, $1, $2); }
	;*/

			case OPERATORr1 :
			case OPERATORr2 :
			case OPERATORr3 :
			case OPERATORr4 :
			case OPERATORr5 :
			case OPERATORr6 :
			case OPERATORr7 :
			case OPERATORr8 :
			case OPERATORr9 :
			case OPERATORr10 :
			case OPERATORr11 :
			case OPERATORr12 :
			case OPERATORr13 :
			case OPERATORr14 :
			case OPERATORr15 :
			case OPERATORr16 :
			case OPERATORr17 :
			case OPERATORr18 :
			case OPERATORr19 :
			case OPERATORr20 :
			case OPERATORr21 :
			case OPERATORr22 :
			case OPERATORr23 :
			case OPERATORr24 :
			case OPERATORr25 :
			case OPERATORr26 :
			case OPERATORr27 :
			case OPERATORr28 :
			case OPERATORr29 :
			case OPERATORr30 :
			case OPERATORr31 :
			case OPERATORr32 :
			case OPERATORr33 :
			case OPERATORr34 :
			case OPERATORr35 :
			case OPERATORr36 :
			case OPERATORr37 :
			case OPERATORr38 :
			case OPERATORr39 :
			case OPERATORr40 :
			case OPERATORr41 :
			case OPERATORr42 :
				node->type = getType(OPERATOR_TYPE);
				break;

/*----------------------------------------------------------------------
 * Exception handling.
 *----------------------------------------------------------------------

try_block:
	TRY compound_statement handler_seq						{ $$ = (TreeNode *)alacnary(TRY_BLOCKr1, 3, $1, $2, $3); }
	;

function_try_block:
	TRY ctor_initializer_opt function_body handler_seq	{ $$ = (TreeNode *)alacnary(FUNCTION_TRY_BLOCKr1, 3, $1, $2, $3); }
	;

handler_seq:
	handler handler_seq_opt										{ $$ = (TreeNode *)alacnary(HANDLER_SEQr1, 2, $1, $2); }
	;

handler:
	CATCH '(' exception_declaration ')' compound_statement
																		{ $$ = (TreeNode *)alacnary(HANDLERr1, 3, $1, $3, $5); }
	;

exception_declaration:
	type_specifier_seq declarator								{ $$ = (TreeNode *)alacnary(EXCEPTION_DECLARATIONr1, 2, $1, $2); }
	| type_specifier_seq abstract_declarator				{ $$ = (TreeNode *)alacnary(EXCEPTION_DECLARATIONr2, 2, $1, $2); }
	| type_specifier_seq											{ $$ = (TreeNode *)alacnary(EXCEPTION_DECLARATIONr3, 1, $1); }
	| ELLIPSIS														{ $$ = (TreeNode *)alacnary(EXCEPTION_DECLARATIONr4, 1, $1); }
	;

throw_expression:
	THROW assignment_expression_opt							{ $$ = (TreeNode *)alacnary(THROW_EXPRESSIONr1, 2, $1, $2); }
	;

exception_specification:
	THROW '(' type_id_list_opt ')'							{ $$ = (TreeNode *)alacnary(EXCEPTION_SPECIFICATIONr1, 2, $1, $3); }
	;

type_id_list:
	type_id															{ $$ = (TreeNode *)alacnary(TYPE_ID_LISTr1, 1, $1); }
	| type_id_list ',' type_id									{ $$ = (TreeNode *)alacnary(TYPE_ID_LISTr2, 2, $1, $3); }
	;
				*/
			case DECLARATION_SEQ_OPTr1 :
				if(SHOW_TREES) printf("declaration seq opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case DECLARATION_SEQ_OPTr2 :
				if(SHOW_TREES) printf("declaration seq opt2\n");
				node->type = node->u.n.child[0]->type;
				break;
				/*

nested_name_specifier_opt:
	/* epsilon 													{ $$ = (TreeNode *)alacnary(NESTED_NAME_SPECIFIER_OPTr1, 0); }
	| nested_name_specifier										{ $$ = (TreeNode *)alacnary(NESTED_NAME_SPECIFIER_OPTr2, 1, $1); }
	;*/

			case EXPRESSION_LIST_OPTr1 :
				if(SHOW_TREES) printf("expression list opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case EXPRESSION_LIST_OPTr2 :
				if(SHOW_TREES) printf("expression list opt2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case NEW_PLACEMENT_OPTr1 :
				if(SHOW_TREES) printf("new_placement_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case NEW_PLACEMENT_OPTr2 :
				if(SHOW_TREES) printf("new_placement_opt2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case NEW_INITIALIZER_OPTr1 :
				if(SHOW_TREES) printf("new_initializer_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case NEW_INITIALIZER_OPTr2 :
				if(SHOW_TREES) printf("new_initializer_opt2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case NEW_DECLARATOR_OPTr1 :
				if(SHOW_TREES) printf("new_declarator_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case NEW_DECLARATOR_OPTr2 :
				if(SHOW_TREES) printf("new_declarator_opt2\n");
				node->type = node->u.n.child[0]->type;
				break;

			case EXPRESSION_OPTr1 :
				if(SHOW_TREES) printf("expression opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case EXPRESSION_OPTr2 :
				if(SHOW_TREES) printf("expression opt2\n");
				node->type = node->u.n.child[0]->type;
				break;
	
			case STATEMENT_SEQ_OPTr1 :
				if(SHOW_TREES) printf("statement seq opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case STATEMENT_SEQ_OPTr2 :
				if(SHOW_TREES) printf("statement seq opt2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case CONDITION_OPTr1 :
				if(SHOW_TREES) printf("condition_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case CONDITION_OPTr2 :
				if(SHOW_TREES) printf("condition_opt2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case ENUMERATOR_LIST_OPTr1 :
				if(SHOW_TREES) printf("enumorator_list_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case ENUMERATOR_LIST_OPTr2 :
				if(SHOW_TREES) printf("enumorator_list_opt2\n");
				node->type = node->u.n.child[0]->type;
				break;

			case INITIALIZER_OPTr1 :
				if(SHOW_TREES) printf("initializer opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case INITIALIZER_OPTr2 :
				if(SHOW_TREES) printf("initializer opt\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case CONSTANT_EXPRESSION_OPTr1 :
				if(SHOW_TREES) printf("constant_expression_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case CONSTANT_EXPRESSION_OPTr2 :
				if(SHOW_TREES) printf("constant_expression_opt1\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case ABSTRACT_DECLARATOR_OPTr1 :
				if(SHOW_TREES) printf("abstract_declarator_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case ABSTRACT_DECLARATOR_OPTr2 :
				if(SHOW_TREES) printf("abstract_declarator_opt1\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case TYPE_SPECIFIER_SEQ_OPTr1 :
				if(SHOW_TREES) printf("type_specifier_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case TYPE_SPECIFIER_SEQ_OPTr2 :
				if(SHOW_TREES) printf("type_specifier_opt1\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case DIRECT_ABSTRACT_DECLARATOR_OPTr1 :
				if(SHOW_TREES) printf("direct_abstract_declarator_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case DIRECT_ABSTRACT_DECLARATOR_OPTr2 :
				if(SHOW_TREES) printf("direct_abstract_declarator_opt1\n");
				node->type = node->u.n.child[0]->type;
				break;

			case CTOR_INITIALIZER_OPTr1 :
				if(SHOW_TREES) printf("ctor initializer opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case CTOR_INITIALIZER_OPTr2 :
				if(SHOW_TREES) printf("ctor initializer opt2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case MEMBER_SPECIFICATION_OPTr1 :
				if(SHOW_TREES) printf("member specification opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case MEMBER_SPECIFICATION_OPTr2 :
				if(SHOW_TREES) printf("member specification opt2\n");
				node->type = node->u.n.child[0]->type;
				//node->type->pub = node->u.n.child[0]->type->pub;  
				break;
				
			case CONVERSION_DECLARATOR_OPTr1 :
				if(SHOW_TREES) printf("conversion_declarator_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case CONVERSION_DECLARATOR_OPTr2 :
				if(SHOW_TREES) printf("conversion_declarator_opt2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case EXPORT_OPTr1 :
				if(SHOW_TREES) printf("export_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case EXPORT_OPTr2 :
				if(SHOW_TREES) printf("export_opt2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case HANDLER_SEQ_OPTr1 :
				if(SHOW_TREES) printf("handler_seq_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case HANDLER_SEQ_OPTr2 :
				if(SHOW_TREES) printf("handler_seq_opt2\n");
				node->type = node->u.n.child[0]->type;
				break;

			case ASSIGNMENT_EXPRESSION_OPTr1 :
				if(SHOW_TREES) printf("assignment expression opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case ASSIGNMENT_EXPRESSION_OPTr2 :
				if(SHOW_TREES) printf("assignment expression opt2\n");
				node->type = node->u.n.child[0]->type;
				break;
				
			case TYPE_ID_LIST_OPTr1 :
				if(SHOW_TREES) printf("type_id_opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case TYPE_ID_LIST_OPTr2 :
				if(SHOW_TREES) printf("type_id_opt2\n");
				node->type = node->u.n.child[0]->type;
				break;

			default:
				node->type = getType(UNKNOWN_TYPE);
		}
	}
}

void addSimpleDeclarations(SymbolTable *currentSymbolTable, NType *current){
	if(SHOW_TREES) printf("**addSimpleDeclarations**\n");
	NType *tempType = NULL;
	if(current != NULL){
		if(current->base_type == TOUPLE_TYPE){
			addSimpleDeclarations(currentSymbolTable, current->u.touple.elems[0]);
			addSimpleDeclarations(currentSymbolTable, current->u.touple.elems[1]);
		} else {
			addToSymbolTable(currentSymbolTable, current);
		}
	}
}

/* adds symbols in a function body and type checks for appropriate type.*/
void addFunctionBodySymbols(SymbolTable *currentSymbolTable, TreeNode *node){
	if(SHOW_TREES) printf("**addFunctionBodySymbols**\n");
	SymbolTable *oldSymbolTable;
	NType *tempType;
	int i;
	if(node != NULL){
		switch(node->u.n.rule) {
			case SIMPLE_DECLARATIONr1 :
				if(SHOW_TREES) printf("simple declaration 1\n");
				if(node->type->base_type == UNKNOWN_TYPE){
					if(node->type->ref != NULL){
						tempType = getClass(globalSymbolTable, node->type->ref);
						if(tempType != NULL) copyType(tempType, node->type);
						node->u.n.child[1]->type->base_type = node->type->base_type;
						node->u.n.child[1]->type->cType = node->type;
						node->u.n.child[1]->type->ref = node->type->label;
					}
				}
				addSimpleDeclarations(currentSymbolTable, node->u.n.child[1]->type);
				if(SHOW_TREES) printf("simple declaration 1 complete\n");
				break;
			case SIMPLE_DECLARATIONr2 :
				if(SHOW_TREES) printf("simple declaration 2\n");
				//addSimpleDeclarations(currentSymbolTable, node->u.n.child[1]->type);
				if(SHOW_TREES) printf("simple declaration 2 complete\n");
				break;
			
			case POSTFIX_EXPRESSIONr7 :
				if(SHOW_TREES) printf("postfix expression 7\n");
				oldSymbolTable = currentSymbolTable;
				if(node->type->base_type == UNKNOWN_TYPE){
					//get function's class
					tempType = getClass(currentSymbolTable, node->type->ref);
					if(tempType != NULL) {
						copyType(tempType, node->u.n.child[0]->type);
						//get function from class symbol table
						if(tempType->cType->symbTable == NULL){
							currentSymbolTable = getSymbolTable(globalSymbolTable, tempType->cType->label);
							if(currentSymbolTable != NULL){
								tempType->cType->symbTable = currentSymbolTable;
								tempType = getSymbolFromTable(currentSymbolTable, node->type);
								currentSymbolTable = oldSymbolTable;
							} else {
								exitStatus = 3;
								getErrorMessage(ER_FUNC_NOT_DEFINED);
								yyerror(node->type->ref);
							}
						} else {
							tempType = getSymbolFromTable(tempType->cType->symbTable, node->type);
						}
						if(tempType != NULL){
							copyType(tempType, node->type);
						} else {
							exitStatus = 3;
							getErrorMessage(ER_FUNC_NOT_DEFINED);
							yyerror(node->type->ref);
						}
					} else {
						exitStatus = 3;
						getErrorMessage(ER_CLASS_NOT_DEFINED);
						yyerror(node->type->ref);
					}
				}
				break;
				
			case UNARY_EXPRESSIONr4 :
				if(SHOW_TREES) printf("unary expression4\n");
				tempType = getSymbolFromTable(currentSymbolTable, node->type->u.ptr);
				if(tempType != NULL) {
					copyType(tempType, node->type->u.ptr);
				}
				break;
			case UNARY_EXPRESSIONr5 :
				if(SHOW_TREES) printf("unary expression5\n");
				tempType = getSymbolFromTable(currentSymbolTable, node->type->u.ptr);
				if(tempType != NULL) {
					copyType(tempType, node->type->u.ptr);
				}
				break;
				
			case JUMP_STATEMENTr3 :
				if(SHOW_TREES) printf("jump_statement 3");
				if(node->type->base_type == UNKNOWN_TYPE){
					tempType = getSymbolFromTable(currentSymbolTable, node->type);
					if(tempType != NULL){
						copyType(tempType, node->type);
					} else {
						exitStatus = 3;
						getErrorMessage(ER_FUNC_NOT_DEFINED);
						yyerror(node->type->label);
					}
				}
				tempType = checkType(currentSymbolTable->scope->u.func.retType, node->type);
				if(tempType == NULL){
					exitStatus = 3;
					getErrorMessage(ER_RETURN_TYPE);
					yyerror(NULL);
				}
				break;
				
			case SELECTION_STATEMENTr3 :
				if(SHOW_TREES) printf("selection_statement 3\n");
				node->type = getType(STATEMENT_TYPE);
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[1]->type);
					if(tempType != NULL){
						copyType(tempType, node->u.n.child[1]->type);
					} else {
						exitStatus = 3;
						getErrorMessage(ER_FUNC_NOT_DEFINED);
						yyerror(node->type->label);
					}
				}
				if(node->u.n.child[1]->type->base_type != INT_TYPE && node->u.n.child[1]->type->base_type != ENUM_TYPE){
					exitStatus = 3;
					getErrorMessage(ER_INT_EXPECTED);
					yyerror(NULL);
				}
				break;
			
			case EXPRESSION_STATEMENTr1 :
				if(SHOW_TREES) printf("expression_statement 1\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE){
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL){
						copyType(tempType, node->u.n.child[0]->type);
					} else {
						exitStatus = 3;
						getErrorMessage(ER_FUNC_NOT_DEFINED);
						yyerror(node->type->label);
					}
				}
				break;
			
				
			case RELATIONAL_EXPRESSIONr2 :
			case RELATIONAL_EXPRESSIONr3 :
			case RELATIONAL_EXPRESSIONr4 :
			case RELATIONAL_EXPRESSIONr5 :
			case EQUALITY_EXPRESSIONr2 :
			case EQUALITY_EXPRESSIONr3 :
				if(SHOW_TREES) printf("relational_expression\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE){
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL){
						copyType(tempType, node->u.n.child[0]->type);
					} else {
						exitStatus = 3;
						getErrorMessage(ER_FUNC_NOT_DEFINED);
						yyerror(node->type->label);
					}
				}
				tempType = getOperatorType(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;
				
			case EXPRESSIONr1 :
				if(SHOW_TREES) printf("expression 1\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE){
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL){
						copyType(tempType, node->u.n.child[0]->type);
					} else {
						exitStatus = 3;
						getErrorMessage(ER_FUNC_NOT_DEFINED);
						yyerror(node->type->label);
					}
				}
				break;
				
			case IDENTIFIERr1 :
				if(SHOW_TREES) printf("identifier 1\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE){
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL){
						copyType(tempType, node->u.n.child[0]->type);
					} else {
						exitStatus = 3;
						getErrorMessage(ER_FUNC_NOT_DEFINED);
						yyerror(node->type->label);
					}
				}
				break;
			
			case ASSIGNMENT_EXPRESSIONr2 :
				if(SHOW_TREES) printf("assignment_expression 2\n");
				for(i = 0; i < 3; i++){
					if(node->u.n.child[i]->type->base_type == UNKNOWN_TYPE){
						tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[i]->type);
						if(tempType != NULL){
							copyType(tempType, node->u.n.child[i]->type);
						} else {
							exitStatus = 3;
							getErrorMessage(ER_FUNC_NOT_DEFINED);
							yyerror(node->type->label);
						}
					}
				}
				tempType = getOperatorType(node->u.n.child[0]->type, node->u.n.child[2]->type);
				break;

			default :
				break;
		}
		int n;
		for(n = 0; n < node->u.n.children; n++){
			addFunctionBodySymbols(currentSymbolTable, node->u.n.child[n]);
		}
	}
}

/*performs the second pass of semantic analysis completing the node types and checking
for types for approriateness and creating symbol tables and adding symbols to those
tables.*/
void makeSymbolTables(TreeNode *node){
	SymbolTable *oldSymbolTable;
	//globalSymbolTable->scope = node->type;
	NType *tempType;
	int p;
	if(node != NULL){
		//recursion
		int n;
		for(n = 0; n < node->u.n.children; n++){
			makeSymbolTables(node->u.n.child[n]);
		}
		switch(node->u.n.rule) {
			case TRANSLATION_UNITr1 :
				if(SHOW_TREES) printf("translation unit 1\n");
				//globalSymbolTable->scope = node->type;
				if(SHOW_TREES) printf("translation unit 1 complete\n");
				break;
				
			case CLASS_NAMEr1 :
				if(node->type->base_type == UNKNOWN_TYPE){
					tempType = getSymbolFromTable(currentSymbolTable, node->type);
					if(tempType != NULL)copyType(tempType, node->type);
				}
				break;
				
			case IDENTIFIERr1 :
				if(SHOW_TREES) printf("identifier 1\n");
				if(node->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->type);
					if(tempType != NULL)copyType(tempType, node->type);
				}
				break;
				
			case MULTIPLICATIVE_EXPRESSIONr2 :
				if(SHOW_TREES) printf("multiplicative_expression 2\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE) 
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
				if(tempType != NULL)copyType(tempType, node->u.n.child[0]->type);
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE) 
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
				if(tempType != NULL)copyType(tempType, node->u.n.child[1]->type);
				getOperatorType(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;
			case MULTIPLICATIVE_EXPRESSIONr3 :
				if(SHOW_TREES) printf("multiplicative_expression 3\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE) 
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
				if(tempType != NULL)copyType(tempType, node->u.n.child[0]->type);
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE) 
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
				if(tempType != NULL)copyType(tempType, node->u.n.child[1]->type);
				getOperatorType(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;
			case MULTIPLICATIVE_EXPRESSIONr4 :
				if(SHOW_TREES) printf("multiplicative_expression 4\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE) 
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
				if(tempType != NULL)copyType(tempType, node->u.n.child[0]->type);
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE) 
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
				if(tempType != NULL)copyType(tempType, node->u.n.child[1]->type);
				getOperatorType(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;

			case ADDITIVE_EXPRESSIONr2 :
				if(SHOW_TREES) printf("additive_expression 2\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE) 
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
				if(tempType != NULL)copyType(tempType, node->u.n.child[0]->type);
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE) 
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
				if(tempType != NULL)copyType(tempType, node->u.n.child[1]->type);
				getOperatorType(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;
			case ADDITIVE_EXPRESSIONr3 :
				if(SHOW_TREES) printf("additive_expression 3\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE) 
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
				if(tempType != NULL)copyType(tempType, node->u.n.child[0]->type);
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE) 
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
				if(tempType != NULL)copyType(tempType, node->u.n.child[1]->type);
				getOperatorType(node->u.n.child[0]->type, node->u.n.child[1]->type);
				break;
				
			case FUNCTION_DEFINITIONr1 :
				if(SHOW_TREES) printf("function definition 1\n");
				oldSymbolTable = currentSymbolTable;
				if(node->type->base_type == FUNC_TYPE)
					currentSymbolTable = getSymbolTable(globalSymbolTable, node->type->u.func.parent);
				if(currentSymbolTable == NULL) currentSymbolTable = oldSymbolTable;
				addToSymbolTable(currentSymbolTable, node->type);
				currentSymbolTable = createSymbolTable(currentSymbolTable, currentSymbolTable->size);
				currentSymbolTable->scope = node->type;
				node->type->symbTable = currentSymbolTable;
				//add parameters
				for(p = 0; p < node->type->u.func.nargs; p++){
					addToSymbolTable(currentSymbolTable, node->type->u.func.args[p]->elemtype);
				}
				//add body variables
				addFunctionBodySymbols(currentSymbolTable, node->u.n.child[2]);
				currentSymbolTable = oldSymbolTable;
				if(SHOW_TREES) printf("function definition 1 complete[%d]\n", currentSymbolTable->entries);
				break;	
			case FUNCTION_DEFINITIONr2 :
				if(SHOW_TREES) printf("function definition 2\n");
				addToSymbolTable(currentSymbolTable, node->type);
				currentSymbolTable = createSymbolTable(currentSymbolTable, currentSymbolTable->size);
				currentSymbolTable->scope = node->type;
				node->type->symbTable = currentSymbolTable;
				//add parameters
				for(p = 0; p < node->type->u.func.nargs; p++){
					addToSymbolTable(currentSymbolTable, node->type->u.func.args[p]->elemtype);
				}
				//add body variables
				addFunctionBodySymbols(currentSymbolTable, node->u.n.child[3]);
				if(SHOW_TREES) printf("function definition 2 complete [%d]\n", currentSymbolTable->entries);
				break;
				
			case FUNCTION_DEFINITIONr3 :
				if(SHOW_TREES) printf("function definition 3\n");
				addToSymbolTable(currentSymbolTable, node->type);
				currentSymbolTable = createSymbolTable(currentSymbolTable, currentSymbolTable->size);
				currentSymbolTable->scope = node->type;
				node->type->symbTable = currentSymbolTable;
				//add parameters
				for(p = 0; p < node->type->u.func.nargs; p++){
					addToSymbolTable(currentSymbolTable, node->type->u.func.args[p]->elemtype);
				}
				//add body variables
				addFunctionBodySymbols(currentSymbolTable, node->u.n.child[2]);
				if(SHOW_TREES) printf("function definition 3 complete[%d]\n", currentSymbolTable->entries);
				break;
			case FUNCTION_DEFINITIONr4 :
				if(SHOW_TREES) printf("function definition 4\n");
				addToSymbolTable(currentSymbolTable, node->type);
				currentSymbolTable = createSymbolTable(currentSymbolTable, currentSymbolTable->size);
				currentSymbolTable->scope = node->type;
				node->type->symbTable = currentSymbolTable;
				//add parameters
				for(p = 0; p < node->type->u.func.nargs; p++){
					addToSymbolTable(currentSymbolTable, node->type->u.func.args[p]->elemtype);
				}
				//add body variables
				addFunctionBodySymbols(currentSymbolTable, node->u.n.child[3]);
				if(SHOW_TREES) printf("function definition 4 complete[%d]\n", currentSymbolTable->entries);
				break;

			case CLASS_SPECIFIERr1 :
				if(SHOW_TREES) printf("class specifier 1\n");
				addToSymbolTable(currentSymbolTable, node->type);
				currentSymbolTable = createSymbolTable(currentSymbolTable, currentSymbolTable->size);
				currentSymbolTable->entries = 0;
				currentSymbolTable->scope = node->type;
				node->type->symbTable = currentSymbolTable;
				//add members
				for(p = 0; p < node->type->u.clas.nfields; p++)
					addToSymbolTable(currentSymbolTable, node->type->u.clas.f[p]->elemtype);
				if(SHOW_TREES) printf("class specifier 1 complete[%d]\n", currentSymbolTable->entries);
				
				currentSymbolTable = currentSymbolTable->parent;
				break;
				
			default : 
				//if(SHOW_TREES) printf("oops!\n");
				break;
		}
	}
}
