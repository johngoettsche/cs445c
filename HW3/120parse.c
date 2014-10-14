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
#include "parsedef.h"
#include "types.h"
#include "120gram.h"

char *humanreadable(int ncode){
	if(ncode >= 1000)ncode = (int)(ncode / 100) * 100;
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

		default : name =  "Not Found"; break;
	}
	return name;
}

void printTree(TreeNode *t, int depth){
	char *text;
	int i;
	if(t->symbol >= 1000){
		printf("%*s%s: %d - %d\n", depth*2, " ", humanreadable(t->u.n.rule), t->u.n.children, t->type->base_type);
		if(t->u.n.children > 0)
			for(i=0; i<t->u.n.children; i++)
				printTree(t->u.n.child[i], depth+1);
	} else {
		printf("%*s%s: %s - %d\n", depth*2, " ", humanreadable(t->symbol), t->u.t.token->text, t->type->base_type);
	}
}

TreeNode *alacnary(int prodRule, int children,...){
	TreeNode *nd = (TreeNode *)calloc(1, sizeof(TreeNode));
	if(!nd)memoryError();
	
	nd->symbol = (int)(prodRule / 100) * 100;
	nd->u.n.rule = prodRule;
	nd->u.n.children = children;
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
	SymbolTable *symbolTable;
	if((symbolTable = (SymbolTable *)calloc(1, sizeof(SymbolTable))) == NULL) memoryError();
	symbolTable->parent = parent;
	symbolTable->size = size;
	if((symbolTable->bucket = calloc(size, sizeof(SymbolTableEntry))) == NULL) memoryError();
	
	return symbolTable;
}

SymbolTable *createGlobalSymbolTable(int size){
	SymbolTable *symbolTable;
	if((symbolTable = (SymbolTable *)calloc(1, sizeof(SymbolTable))) == NULL) memoryError();
	symbolTable->size = size;
	if((symbolTable->bucket = calloc(size, sizeof(SymbolTableEntry))) == NULL) memoryError();
	return symbolTable;
}

int hashSymbol(Symbol *symbol){
	int i;
	int sum = 0;
	for(i = 0; i < strlen(symbol->label); i++){
		sum += symbol[i];
	}
	return sum % SYMBOL_TABLE_SIZE;
}

int inSymbolTable(SymbolTable *symbolTable, Symbol *symbol){
	
}

void addToSymbolTable(SymbolTable *symbolTable, Symbol *symbol){
	SymbolTableEntry newEntry;
	int hashvalue = hash(symbol);
	if(symbolTable->bucket[hashvalue]->symbol == NULL)symbolTable->bucket[hashvalue]->symbol = symbol;
	else {
		
		if((newEntry = (SymbolTableEntry *)calloc(1, sizeof(SymbolTableEntry))) == NULL) memoryError();
		
	}
}

void buildTypes(TreeNode *node){
	if(node != NULL){
		int n;
		for(n = 0; n < node->u.n.children; n++){
			buildTypes(node->u.n.child[n]);
		}
		switch(node->u.n.rule){
			case IDENTIFIERr1 :
				node->type = node->u.n.child[0]->type;
				/* ADD TO SYMBOL TABLE */
				break;
				
			case LITERALr1 :
				node->type = node->u.n.child[0]->type;
				break;
			case LITERALr2 :
				node->type = node->u.n.child[0]->type;
				break;
			case LITERALr3 :
				node->type = node->u.n.child[0]->type;
				break;
			case LITERALr4 :
				node->type = node->u.n.child[0]->type;
				break;
			case LITERALr5 :
				node->type = node->u.n.child[0]->type;
				break;
				
			case INTEGER_LITERALr1 :
				node->type = getType(INT_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case CHARACTER_LITERALr1 :
				node->type = getType(CHAR_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case FLOATING_LITERALr1 :
				node->type = getType(FLOAT_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case STRING_LITERALr1 :
				node->type = getType(STR_TYPE_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case BOOLEAN_LITERALr1 :
				node->type = getType(BOOL_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case BOOLEAN_LITERALr2 :
				node->type = getType(BOOL_TYPE);
				node->u.n.child[0]->type = node->type;
				break;

			case TRANSLATION_UNITr1 :
			/* NOT SHURE WHAT THIS ONE DOES YET */
				node->type = node->u.n.child[0]->type;
				break;
				
			case PRIMARY_EXPRESSIONr1 :
				node->type = node->u.n.child[0]->type;
				break;
			case PRIMARY_EXPRESSIONr2 :
				/* GET TYPE FROM CURRENT CLASS */
				break;
			case PRIMARY_EXPRESSIONr3 :
				node->type = node->u.n.child[1]->type;
				break;
			case PRIMARY_EXPRESSIONr4 :
				node->type = node->u.n.child[0]->type;
				break;

			case ID_EXPRESSIONr1 :
				node->type = node->u.n.child[0]->type;
				break;
			case ID_EXPRESSIONr2 :
				node->type = node->u.n.child[0]->type;
				break;
				
			case UNQUALIFIED_IDr1 :
				node->type = node->u.n.child[0]->type;
				break;
			case UNQUALIFIED_IDr2 :
				node->type = node->u.n.child[0]->type;
				break;
			case UNQUALIFIED_IDr3 :
				node->type = node->u.n.child[0]->type;
				break;
			case UNQUALIFIED_IDr4 :
				node->type = node->u.n.child[1]->type;
				break;
				
			
			/*
qualified_id:
	nested_name_specifier unqualified_id						{ $$ = (TreeNode *)alacnary(QUALIFIED_IDr1, 2, $1, $2); }
	| nested_name_specifier TEMPLATE unqualified_id			{ $$ = (TreeNode *)alacnary(QUALIFIED_IDr1, 3, $1, $2, $3); }
	;

nested_name_specifier:
	class_name COLONCOLON nested_name_specifier				{ $$ = (TreeNode *)alacnary(NESTED_NAME_SPECIFIERr1, 3, $1, $2, $3); }
	| namespace_name COLONCOLON nested_name_specifier		{ $$ = (TreeNode *)alacnary(NESTED_NAME_SPECIFIERr2, 3, $1, $2, $3); }
	| class_name COLONCOLON											{ $$ = (TreeNode *)alacnary(NESTED_NAME_SPECIFIERr3, 2, $1, $2); }
	| namespace_name COLONCOLON									{ $$ = (TreeNode *)alacnary(NESTED_NAME_SPECIFIERr4, 2, $1, $2); }
	;

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
	;
				*/
				
			case UNARY_EXPRESSIONr1 :
				node->type = node->u.n.child[0]->type;
				break;
			case UNARY_EXPRESSIONr2 :
				node->type = node->u.n.child[1]->type;
				break;
			case UNARY_EXPRESSIONr3 :
				node->type = node->u.n.child[1]->type;
				break;
			case UNARY_EXPRESSIONr4 :
				//pointer//
				/*node->type = node->u.n.child[1]->type;*/
				break;
			case UNARY_EXPRESSIONr5 :
				//&//
				/*node->type = node->u.n.child[1]->type;*/
				break;
			case UNARY_EXPRESSIONr6 :
				node->type = node->u.n.child[1]->type;
				break;
			case UNARY_EXPRESSIONr7 :
				node->type = getType(INT_TYPE);
				break;
			case UNARY_EXPRESSIONr8 :
				node->type = getType(INT_TYPE);
				break;
			case UNARY_EXPRESSIONr9 :
				node->type = node->u.n.child[1]->type;
				break;
			case UNARY_EXPRESSIONr10 :
				//NOT SHURE YET//
				/*node->type = node->u.n.child[1]->type;*/
				break;

/* SKIPPED UNARY_OPERATOR */
				
				
/*
new_expression:
	  NEW new_placement_opt new_type_id new_initializer_opt
																			{ $$ = (TreeNode *)alacnary(NEW_EXPRESSIONr1, 4, $1, $2, $3, $4); }
	| COLONCOLON NEW new_placement_opt new_type_id new_initializer_opt
																			{ $$ = (TreeNode *)alacnary(NEW_EXPRESSIONr2, 5, $1, $2, $3, $4, $5); }
	| NEW new_placement_opt '(' type_id ')' new_initializer_opt
																			{ $$ = (TreeNode *)alacnary(NEW_EXPRESSIONr3, 4, $1, $2, $4, $6); }
	| COLONCOLON NEW new_placement_opt '(' type_id ')' new_initializer_opt
																			{ $$ = (TreeNode *)alacnary(NEW_EXPRESSIONr4, 5, $1, $2, $3, $5, $7); }
	;

new_placement:
	'(' expression_list ')'											{ $$ = (TreeNode *)alacnary(NEW_PLACEMENTr1, 1, $2); }
	;

new_type_id:
	type_specifier_seq new_declarator_opt						{ $$ = (TreeNode *)alacnary(NEW_TYPE_IDr1, 2, $1, $2); }
	;

new_declarator:
	ptr_operator new_declarator_opt								{ $$ = (TreeNode *)alacnary(NEW_DECLARATORr1, 2, $1, $2); }
	| direct_new_declarator											{ $$ = (TreeNode *)alacnary(NEW_DECLARATORr2, 1, $1); }
	;

direct_new_declarator:
	'[' expression ']'												{ $$ = (TreeNode *)alacnary(DIRECT_NEW_DECLARATORr1, 1, $2); }
	| direct_new_declarator '[' constant_expression ']'	{ $$ = (TreeNode *)alacnary(DIRECT_NEW_DECLARATORr2, 2, $1, $3); }
	;

new_initializer:
	'(' expression_list_opt ')'									{ $$ = (TreeNode *)alacnary(NEW_INITIALIZERr1, 1, $2); }
	;

delete_expression:
	DELETE cast_expression											{ $$ = (TreeNode *)alacnary(DELETE_EXPRESSIONr1, 2, $1, $2); }
	| COLONCOLON DELETE cast_expression							{ $$ = (TreeNode *)alacnary(DELETE_EXPRESSIONr2, 3, $1, $2, $3); }
	| DELETE '[' ']' cast_expression								{ $$ = (TreeNode *)alacnary(DELETE_EXPRESSIONr3, 2, $1, $4); }
	| COLONCOLON DELETE '[' ']' cast_expression				{ $$ = (TreeNode *)alacnary(DELETE_EXPRESSIONr4, 3, $1, $2, $5); }
	;

cast_expression:
	unary_expression													{ $$ = (TreeNode *)alacnary(CAST_EXPRESSIONr1, 1, $1); }
	| '(' type_id ')' cast_expression							{ $$ = (TreeNode *)alacnary(CAST_EXPRESSIONr2, 2, $2, $4); }
	;

pm_expression:
	cast_expression													{ $$ = (TreeNode *)alacnary(PM_EXPRESSIONr1, 1, $1); }
	| pm_expression DOTSTAR cast_expression					{ $$ = (TreeNode *)alacnary(PM_EXPRESSIONr2, 3, $1, $2, $3); }
	| pm_expression ARROWSTAR cast_expression					{ $$ =(TreeNode *)alacnary(PM_EXPRESSIONr3, 3, $1, $2, $3); }
	;

multiplicative_expression:
	pm_expression														{ $$ = (TreeNode *)alacnary(MULTIPLICATIVE_EXPRESSIONr1, 1, $1); }
	| multiplicative_expression '*' pm_expression			{ $$ = (TreeNode *)alacnary(MULTIPLICATIVE_EXPRESSIONr2, 2, $1, $3); }
	| multiplicative_expression '/' pm_expression			{ $$ = (TreeNode *)alacnary(MULTIPLICATIVE_EXPRESSIONr3, 2, $1, $3); }
	| multiplicative_expression '%' pm_expression			{ $$ = (TreeNode *)alacnary(MULTIPLICATIVE_EXPRESSIONr4, 2, $1, $3); }
	;

additive_expression:
	multiplicative_expression										{ $$ = (TreeNode *)alacnary(ADDITIVE_EXPRESSIONr1, 1, $1); }
	| additive_expression '+' multiplicative_expression	{ $$ = (TreeNode *)alacnary(ADDITIVE_EXPRESSIONr2, 2, $1, $3); }
	| additive_expression '-' multiplicative_expression	{ $$ = (TreeNode *)alacnary(ADDITIVE_EXPRESSIONr3, 2, $1, $3); }
	;

shift_expression:
	additive_expression												{ $$ = (TreeNode *)alacnary(SHIFT_EXPRESSIONr1, 1, $1); }
	| shift_expression SL additive_expression					{ $$ = (TreeNode *)alacnary(SHIFT_EXPRESSIONr2, 3, $1, $2, $3); }
	| shift_expression SR additive_expression					{ $$ = (TreeNode *)alacnary(SHIFT_EXPRESSIONr3, 3, $1, $2, $3); }
	;

relational_expression:
	shift_expression													{ $$ = (TreeNode *)alacnary(RELATIONAL_EXPRESSIONr1, 1, $1); }
	| relational_expression '<' shift_expression				{ $$ = (TreeNode *)alacnary(RELATIONAL_EXPRESSIONr2, 2, $1, $3); }
	| relational_expression '>' shift_expression				{ $$ = (TreeNode *)alacnary(RELATIONAL_EXPRESSIONr3, 2, $1, $3); }
	| relational_expression LTEQ shift_expression			{ $$ = (TreeNode *)alacnary(RELATIONAL_EXPRESSIONr4, 3, $1, $2, $3); }
	| relational_expression GTEQ shift_expression			{ $$ = (TreeNode *)alacnary(RELATIONAL_EXPRESSIONr5, 3, $1, $2, $3); }
	;

equality_expression:
	relational_expression											{ $$ = (TreeNode *)alacnary(EQUALITY_EXPRESSIONr1, 1, $1); }
	| equality_expression EQ relational_expression			{ $$ = (TreeNode *)alacnary(EQUALITY_EXPRESSIONr2, 3, $1, $2, $3); }
	| equality_expression NOTEQ relational_expression		{ $$ = (TreeNode *)alacnary(EQUALITY_EXPRESSIONr3, 1, $1, $2, $3); }
	;

and_expression:
	equality_expression												{ $$ = (TreeNode *)alacnary(AND_EXPRESSIONr1, 1, $1); }
	| and_expression '&' equality_expression					{ $$ = (TreeNode *)alacnary(AND_EXPRESSIONr2, 2, $1, $3); }
	;

exclusive_or_expression:
	and_expression														{ $$ = (TreeNode *)alacnary(EXCLUSIVE_OR_EXPRESSIONr1, 1, $1); }
	| exclusive_or_expression '^' and_expression				{ $$ = (TreeNode *)alacnary(EXCLUSIVE_OR_EXPRESSIONr2, 2, $1, $3); }
	;

inclusive_or_expression:
	exclusive_or_expression											{ $$ = (TreeNode *)alacnary(INCLUSIVE_OR_EXPRESSIONr1, 1, $1); }
	| inclusive_or_expression '|' exclusive_or_expression	{ $$ = (TreeNode *)alacnary(INCLUSIVE_OR_EXPRESSIONr2, 2, $1, $3); }
	;

logical_and_expression:
	inclusive_or_expression											{ $$ = (TreeNode *)alacnary(LOGICAL_AND_EXPRESSIONr1, 1, $1); }
	| logical_and_expression ANDAND inclusive_or_expression
																			{ $$ = (TreeNode *)alacnary(LOGICAL_AND_EXPRESSIONr1, 3, $1, $2, $3); }
	;

logical_or_expression:
	logical_and_expression											{ $$ = (TreeNode *)alacnary(LOGICAL_OR_EXPRESSIONr1, 1, $1); }
	| logical_or_expression OROR logical_and_expression	{ $$ = (TreeNode *)alacnary(LOGICAL_OR_EXPRESSIONr2, 3, $1, $2, $3); }
	;

conditional_expression:
	logical_or_expression											{ $$ = (TreeNode *)alacnary(CONDITIONAL_EXPRESSIONr1, 1, $1); }
	| logical_or_expression  '?' expression ':' assignment_expression
																			{ $$ = (TreeNode *)alacnary(CONDITIONAL_EXPRESSIONr2, 3, $1, $3, $5); }
	;

assignment_expression:
	conditional_expression											{ $$ = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSIONr1, 1, $1); }
	| logical_or_expression assignment_operator assignment_expression
																			{ $$ = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSIONr2, 3, $1, $2, $3); }
	| throw_expression												{ $$ = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSIONr3, 1, $1); }
	;
*/
/***************************************************************/
			case DECL_SPECIFIER_SEQr1:
				node->type = node->u.n.child[0]->type;
				break;
			case DECL_SPECIFIER_SEQr2:
				node->type = getType(TOUPLE);
				node->type->u.touple.nelems = 2;
				node->type->u.touple.elems = calloc(2, sizeof(struct typeinfo *));
				node->type->u.touple.elems[0] = node->u.n.child[0]->type;
				node->type->u.touple.elems[1] = node->u.n.child[1]->type;
				break;

			case DECL_SPECIFIERr1:
				node->type = node->u.n.child[0]->type;
				break;
			case DECL_SPECIFIERr2:
				node->type = node->u.n.child[0]->type;
				break;
			case DECL_SPECIFIERr3:
				node->type = node->u.n.child[0]->type;
				break;
			case DECL_SPECIFIERr4:
				node->type = node->u.n.child[0]->type;
				break;
			case DECL_SPECIFIERr5:
				node->type = node->u.n.child[0]->type;
				break;	

			
			case TYPE_SPECIFIERr1:
				node->type = node->u.n.child[0]->type;
				break;
			case TYPE_SPECIFIERr2:
				node->type = node->u.n.child[0]->type;
				break;
			case TYPE_SPECIFIERr3:
				node->type = node->u.n.child[0]->type;
				break;
			case TYPE_SPECIFIERr4:
				node->type = node->u.n.child[0]->type;
				break;
			case TYPE_SPECIFIERr5:
				node->type = node->u.n.child[0]->type;
				break;
				
			case SIMPLE_TYPE_SPECIFIERr4:
				node->type = getType(CHAR_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr5:
				node->type = getType(WCHAR_T_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr6:
				node->type = getType(BOOL_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr7:
				node->type = getType(SHORT_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr8:
				node->type = getType(INT_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr9:
				node->type = getType(LONG_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr10:
				node->type = getType(SIGNED_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr11:
				node->type = getType(UNSIGNED_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr12:
				node->type = getType(FLOAT_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr13:
				node->type = getType(DOUBLE_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr14:
				node->type = getType(VOID_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			case SIMPLE_TYPE_SPECIFIERr15:
				node->type = getType(STR_TYPE_TYPE);
				node->u.n.child[0]->type = node->type;
				break;
			
			case TYPE_NAMEr1:
				node->type = node->u.n.child[0]->type;
				break;
			case TYPE_NAMEr2:
				node->type = node->u.n.child[0]->type;
				break;
			case TYPE_NAMEr3: 
				node->type = node->u.n.child[0]->type;
				break;
				
			case FUNCTION_DEFINITIONr1:
				node->type = getType(FUNC_TYPE);
				/* CREATE SCOPE */
				node->type->u.func.retType = node->u.n.child[0]->type;
				//node->type.u.g.label = node->u.n.child[0]->type->u.dec**.label;
				//node->type->u.f.args = node->u.n.child[1]->type->u.ini**.label;
				break;	
			case FUNCTION_DEFINITIONr2:
				node->type = getType(FUNC_TYPE);
				/* CREATE SCOPE */
				node->type->u.func.retType = node->u.n.child[0]->type;
				//node->type.u.g.label = node->u.n.child[1]->type->u.dec**.label;
				//node->type->u.f.args = node->u.n.child[2]->type->u.ini**.label;
				//child 3 is func body
				break;
			case FUNCTION_DEFINITIONr3:
				node->type = getType(FUNC_TYPE);
				/* CREATE SCOPE */
				node->type->u.func.retType = node->u.n.child[0]->type;
				//node->type.u.g.label = node->u.n.child[1]->type->u.dec**.label;
				//node->type->u.f.args = node->u.n.child[2]->type->u.ini**.label;
				break;
			case FUNCTION_DEFINITIONr4:
				node->type = getType(FUNC_TYPE);
				/* CREATE SCOPE */
				node->type->u.func.retType = node->u.n.child[0]->type;
				//node->type.u.g.label = node->u.n.child[1]->type->u.dec**.label;
				//node->type->u.f.args = node->u.n.child[2]->type->u.ini**.label;
				break;
	/*		
			
	| declarator function_try_block								{ $$ = (TreeNode *)alacnary(FUNCTION_DEFINITIONr3, 2, $1, $2); }
	| decl_specifier_seq declarator function_try_block		{ $$ = (TreeNode *)alacnary(FUNCTION_DEFINITIONr4, 3, $1, $2, $3); }
	;*/

			default:
				node->type = getType(UNKNOWN_TYPE);
		}
	}
}
