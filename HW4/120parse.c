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
#include "codedef.h"
#include "types.h"
#include "120gram.h"
#include "codegen.h"

#define SHOW_TREES 1
#define SHOW_MEMMORY 1
#define SHOW_CODE 1

//#define SYMBOL_TABLE_SIZE 31

extern int exitStatus;
extern TreeNode *root;
extern SymbolTable *currentSymbolTable;
extern SymbolTable *globalSymbolTable;
extern SymbolTable *stringTable;

extern int using_namespace_std;
extern int included_iostream;
extern int included_cstdlib;
extern int included_ctime; 
extern int included_string;
extern int included_fstream;
extern int included_stdio; 
extern int included_stdlib;

extern int codeMemory;
extern int labelNumber;
extern int tempSymbNumber;
extern int stringListOffset;

extern NType *codeRegion;

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
		case C_LABEL : name = "LABEL"; break;
		case C_ASN : name = "ASN"; break;
		case C_MULT : name = "MULT"; break;
		case C_DIV : name = "DIV"; break;
		case C_MOD : name = "MOD"; break;
		case C_ADD : name = "ADD"; break;
		case C_SUB : name = "SUB"; break;
		case C_LT : name = "LT"; break;
		case C_GT : name = "GT"; break;
		case C_LTEQ : name = "LTEQ"; break;
		case C_GTEQ : name = "GTEQ"; break;
		case C_PARAM : name = "PARAM"; break;
		case C_EQ : name = "EQ"; break;
		case C_NOTEQ : name = "NOTEQ"; break;
		case C_AND : name = "AND"; break;
		case C_EXOR : name = "EXOR"; break;
		case C_BR : name = "BR"; break;
		case C_GOTO : name = "GOTO"; break;
		case C_RET : name = "RETURN"; break;
		case C_NOT : name = "NOT"; break;
		case C_ADD1 : name = "ADD1"; break;
		case C_SUB1 : name = "SUB1"; break;
		case C_ASN_INT : name = "ASN_INT"; break;
		case C_FUNC : name = "FUNC"; break;
		case C_BRK : name = "BREAK"; break;
		case C_CONT : name = "CONTINUE"; break;
		case C_DSTRING : name = ".string"; break;
		case C_DCODE : name = ".code"; break;

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
			if(t->type->base_type == FUNC_TYPE) 
				if(t->type->u.func.retType != NULL) printf(" %s", humanreadable(t->type->u.func.retType->base_type));
			if(t->type->base_type == ARRAY_TYPE) 
				if(t->type->u.arry.elemtype != NULL) printf(" %s", humanreadable(t->type->u.arry.elemtype->base_type));
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

void printSymbolTables(SymbolTable *symbolTable){
	int i, t;
	SymbolListItem *item;
	switch(symbolTable->scope->base_type){
		case PROGRAM_TYPE :
			printf("%s: [%d]\n", symbolTable->scope->label, symbolTable->offset);
			item = symbolTable->list->head; 
			while(item != NULL){
				if(item->item->base_type == FUNC_TYPE)	printf("%d\t%s %s()\n", item->offset, humanreadable(item->item->u.func.retType->base_type), item->item->label);
				else printf("%d\t%s %s\n", item->offset, humanreadable(item->item->base_type), item->item->label);
				item = item->next;
			}
			printf("----------------------\n");
			break;
		case CONSTRUCTOR_TYPE :
		case FUNC_TYPE :
			printf("%s %s: [%d]\n", humanreadable(symbolTable->scope->base_type), symbolTable->scope->label, symbolTable->offset);	
			for(i = 0; i < symbolTable->scope->u.func.nargs; i++){
				if(symbolTable->scope->u.func.args[i]->elemtype->base_type == FUNC_TYPE)	{
					printf("%d\t%s %s %s()\n", symbolTable->scope->u.func.args[i]->elemtype->offset, humanreadable(symbolTable->scope->u.func.args[i]->elemtype->base_type), humanreadable(symbolTable->scope->u.func.retType->base_type), symbolTable->scope->u.func.args[i]->elemtype->label);
				} else {
					printf("%d\t%s %s\n", symbolTable->scope->u.func.args[i]->elemtype->offset, humanreadable(symbolTable->scope->u.func.args[i]->elemtype->base_type), symbolTable->scope->u.func.args[i]->elemtype->label);
				}
			}
			item = symbolTable->list->head; 
			while(item != NULL){
				if(item->item->base_type == FUNC_TYPE)	printf("%d\t%s %s()\n", item->offset, humanreadable(item->item->u.func.retType->base_type), item->item->label);
				else printf("%d\t%s %s\n", item->offset, humanreadable(item->item->base_type), item->item->label);
				item = item->next;
			}
			printf("----------------------\n");
			break;
		case CLASS_TYPE :
			printf("%s %s: [%d]\n", humanreadable(symbolTable->scope->base_type), symbolTable->scope->label, symbolTable->offset);
			for(i = 0; i < symbolTable->scope->u.clas.nfields; i++){
				if(symbolTable->scope->u.clas.f[i]->elemtype->base_type == FUNC_TYPE)	{
					printf("%d\t%s %s %s()\n", symbolTable->scope->u.clas.f[i]->elemtype->offset, humanreadable(symbolTable->scope->u.clas.f[i]->elemtype->base_type), humanreadable(symbolTable->scope->u.clas.f[i]->elemtype->u.func.retType->base_type),symbolTable->scope->u.clas.f[i]->elemtype->label);
				} else {
					printf("%d\t%s %s\n", symbolTable->scope->u.clas.f[i]->elemtype->offset, humanreadable(symbolTable->scope->u.clas.f[i]->elemtype->base_type), symbolTable->scope->u.clas.f[i]->elemtype->label);
				}
			}
			item = symbolTable->list->head; 
			while(item != NULL){
				if(item->item->base_type == FUNC_TYPE)	printf("%d\t%s %s()\n", item->offset, humanreadable(item->item->u.func.retType->base_type), item->item->label);
				else printf("%d\t%s %s\n", item->offset, humanreadable(item->item->base_type), item->item->label);
				item = item->next;
			}
			printf("----------------------\n");
			break;
	}
	for(t = 0; t < symbolTable->children; t++){
		printSymbolTables(symbolTable->child[t]);
	}
}

char *findLocation(SymbolTable *symbolTable, int offset){
	SymbolListItem *current = symbolTable->list->head;
	int count = 0;
	while(count < symbolTable->list->size) {
		if(current->offset == offset) return current->item->label;
		current = current->next;
		count++;
	}
	return NULL;
}

void printLocation(Location * loc){
	char *temp = findLocation(loc->region->symbTable, loc->offset);
		if(strstr(temp, "_Const_") != NULL){
			printf("Const:%s", loc->val);
		} else {
			printf("%s:%d", loc->region->label, loc->offset);
		}
}

void printCode(TreeNode *node){
	//int count = 0;
	IntrCode *current = node->intCode;
	while(current != NULL){
		//printf("(%d) ", count);
		//printf("%s\n", humanreadable(current->elem->desc)); 
		//count++;
		switch(current->elem->desc){
			case C_FUNC :
			case C_DCODE :
				printf("%s:\n", current->elem->label);
				break;
			case C_DSTRING :
				printf("%s %d\n", current->elem->label, stringListOffset);
				break;
			case C_STR_LIT :
				printf("%32s\n", current->elem->label);
				break;
			case C_LABEL :
				printf("%16s:\n", current->elem->label);
				break;
			case C_PARAM :
			case C_RET :
				printf("%32s    ", humanreadable(current->elem->desc));
				printLocation(current->elem->loc[0]);
				printf("\n");
				break;
			case C_ASN :
			case C_NOT :
			case C_ADD1 :
			case C_SUB1 :
				printf("%32s    ", humanreadable(current->elem->desc));
				printLocation(current->elem->loc[0]);
				printf(", ");
				printLocation(current->elem->loc[1]);
				printf("\n");
				break;
			case C_MULT :
			case C_DIV :
			case C_MOD :
			case C_ADD :
			case C_SUB :
			case C_LT :
			case C_GT :
			case C_LTEQ :
			case C_GTEQ :
			case C_EQ :
			case C_NOTEQ :
			case C_AND :
			case C_EXOR :
				printf("%32s    ", humanreadable(current->elem->desc)); 
				printLocation(current->elem->loc[0]);
				printf(", ");
				printLocation(current->elem->loc[1]);
				printf(", ");
				printLocation(current->elem->loc[2]);
				printf("\n");
				break;
			case C_BR :
				printf("%32s%11s, ", humanreadable(current->elem->desc), 
											current->elem->loc[0]->elem->label);
				printLocation(current->elem->loc[1]);
				printf("\n");
				break;
			case C_GOTO :
			case C_BRK :
			case C_CONT :
				//printf("%s\n", current->elem->loc[0]->val);
				if(strcmp(current->elem->loc[0]->val, "__NULL_") != 0) {
					//printf("%s\n", humanreadable(current->elem->desc));
					printf("%32s%11s\n", humanreadable(current->elem->desc), 
												current->elem->loc[0]->elem->label);
				} else {
					if(SHOW_CODE)printf("Undefined Jump\n");
				}
				break;
		}
		current = current->next;
	}
}

NType *getType(int tcode){
	struct NType *ntype;
	if((ntype = (NType *)calloc(1, sizeof(NType))) == NULL) memoryError();
	ntype->base_type = tcode;
	
	return ntype;
}

void passSymbolTableDownTree(SymbolTable *symbolTable, TreeNode *node){
	int c;
	if(node != NULL){
		node->type->symbTable = symbolTable;
		for(c = 0; c < node->u.n.children; c++){
			passSymbolTableDownTree(symbolTable, node->u.n.child[c]);
		}
	}
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
	symbolTable->offset = 0;
	if((symbolTable->list = (SymbolList *)calloc(1, sizeof(SymbolList))) == NULL) memoryError();
	symbolTable->list->size = 0;
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

NType * checkClassesForSymbol(SymbolTable *symbolTable, NType *symb){
	int t;
	int hashvalue = hashSymbol(symb, symbolTable->size);
	SymbolTableEntry *current = symbolTable->bucket[hashvalue];
	while(current != NULL){
		if(strcmp(current->symb->label, symb->label) == 0){
			return current->symb;
		}
		current = current->next;
	}
	for(t = 0; t < symbolTable->children; t++){
		if(symbolTable->child[t]->scope->base_type == CLASS_TYPE)
			return checkClassesForSymbol(symbolTable->child[t], symb);
	}
	return NULL;
}

NType *getSymbolFromTable(SymbolTable *symbolTable, NType *symb){
if(SHOW_TREES)printf("\t\tSymbolTable: %s\n", symbolTable->scope->label);
	int t;
	int hashvalue = hashSymbol(symb, symbolTable->size);
	SymbolTableEntry *current = symbolTable->bucket[hashvalue];
	while(current != NULL){
		if(strcmp(current->symb->label, symb->label) == 0){
			return current->symb;
		}
		current = current->next;
	}
	if(symbolTable->parent != NULL) {
		if(inSymbolTable(symbolTable->parent, symb))
		return (NType *)getSymbolFromTable(symbolTable->parent, symb);
	} else {
		for(t = 0; t < symbolTable->children; t++){
			if(symbolTable->child[t]->scope->base_type == CLASS_TYPE)
				return checkClassesForSymbol(symbolTable->child[t], symb);
		}
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

 int getBits(NType *symb, int bits){
	NType *tempType;
	SymbolListItem *item;
	int i;
	switch(symb->base_type){
		case VOID_TYPE  :
			break;
		case CHAR_TYPE : 
			bits += 1;
			break;
		case WCHAR_T_TYPE :
		case BOOL_TYPE  :
		case SHORT_TYPE  :
		case INT_TYPE :
		case LONG_TYPE  :
		case FLOAT_TYPE :
		case DOUBLE_TYPE	:
			bits += 8;
			break;
		case CLASS_TYPE :
			for(i = 0; i < symb->u.clas.nfields; i++){ // elements
				bits = getBits(symb->u.clas.f[i]->elemtype, bits);
			}
			item = symb->symbTable->list->head;
			break;
		case CONSTRUCTOR_TYPE :
		case FUNC_TYPE :
			if(symb->base_type == FUNC_TYPE){
				bits = getBits(symb->u.func.retType, bits); //return type
			} else {
				bits += 8;
			}
			for(i = 0; i < symb->u.func.nargs; i++){ //arguments
				bits = getBits(symb->u.func.args[i]->elemtype, bits);
			}
			item = symb->symbTable->list->head;
			while(item != NULL){ // in body
				bits = getBits(item->item, bits);
				item = item->next;
			}
			break;
		default :
			bits += 8;
	}
	return bits;
}

void calculateOffsets(SymbolTable *symbolTable){
if(SHOW_TREES)printf("*** Calculating Offsets ***\n");
	int i, t;
	SymbolListItem *item;
	int mode = M_OFFSETS;
	switch(symbolTable->scope->base_type){
		case CONSTRUCTOR_TYPE :
		case FUNC_TYPE :		
			if(symbolTable->scope->base_type == FUNC_TYPE){
				symbolTable->offset = getBits(symbolTable->scope->u.func.retType, symbolTable->offset); //return type
			}
			for(i = 0; i < symbolTable->scope->u.func.nargs; i++){
				symbolTable->scope->u.func.args[i]->elemtype->offset = symbolTable->offset;
				symbolTable->offset = getBits(symbolTable->scope->u.func.args[i]->elemtype, symbolTable->offset);
			}
			item = symbolTable->list->head; 
			while(item != NULL){
				item->offset = symbolTable->offset;
				item->item->offset = symbolTable->offset;
				symbolTable->offset = getBits(item->item, symbolTable->offset);
				item = item->next;
			}
			break;
		case CLASS_TYPE :	
			for(i = 0; i < symbolTable->scope->u.clas.nfields; i++){
				symbolTable->scope->u.clas.f[i]->elemtype->offset = symbolTable->offset;
				symbolTable->offset = getBits(symbolTable->scope->u.clas.f[i]->elemtype, symbolTable->offset);
			}
			item = symbolTable->list->head; 
			break;
	}
	for(t = 0; t < symbolTable->children; t++){
		calculateOffsets(symbolTable->child[t]);
	}
 }
 
void addToSymbolTable(SymbolTable *symbolTable, NType *symb, int mode){
	char *symbName;
	if(mode == M_CODEGEN){
		symb->offset = symbolTable->offset;
		symbolTable->offset = getBits(symb, symbolTable->offset);
	}
	if(SHOW_TREES) printf("adding to symbol table %s:\n", symbolTable->scope->label);
	SymbolTableEntry *newEntry;
	if((newEntry = (SymbolTableEntry *)calloc(1, sizeof(SymbolTableEntry))) == NULL) memoryError();
	newEntry->symb = symb;
	if(SHOW_MEMMORY){
		if(symb->base_type == ARRAY_TYPE) {
			printf("%s %s[%d]\n", humanreadable(symb->u.arry.elemtype->base_type), symb->label, symb->u.arry.size);
		} else {
			if(symb->ref == NULL) {
				printf("%s %s\n", humanreadable(symb->base_type), symb->label);
				if(symb->base_type == FUNC_TYPE) printf("ret: %s\n", humanreadable(symb->u.func.retType->base_type));
			} else {
				printf("%s %s\n", symb->cType->label, symb->label);
			}
		}
	}
	
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
			yerror(symb->label, symb->lineno);
		}
	}	
	if(SHOW_TREES) printf("\naddToSymbolTable: [%d]\n", symbolTable->entries);
}

void addToSymbolTableList(SymbolTable *currentSymbolTable, NType *current, int mode){
	SymbolListItem *item;
	if((item = (SymbolListItem *)calloc(1, sizeof(SymbolListItem))) == NULL)memoryError();
	item->item = current;
	item->next = NULL;
	if(mode == M_CODEGEN) item->offset = current->offset;
	if(currentSymbolTable->list->size == 0){
		currentSymbolTable->list->head = item;
	} else {
		currentSymbolTable->list->tail->next = item;
	}
	currentSymbolTable->list->tail = item;
	currentSymbolTable->list->size++;
}

void addLibrariesData(){
	NType *tempType;
	int mode = M_LIB;
	if(included_iostream){
		if(using_namespace_std){
			tempType = (NType *)getType(STREAM_TYPE);
			tempType->label = "cin";
			addToSymbolTable(globalSymbolTable, tempType, mode);
			addToSymbolTableList(globalSymbolTable, tempType, mode);
			tempType = (NType *)getType(STREAM_TYPE);
			tempType->label = "cout";
			addToSymbolTable(globalSymbolTable, tempType, mode);
			addToSymbolTableList(globalSymbolTable, tempType, mode);
			tempType = (NType *)getType(STREAM_TYPE);
			tempType->label = "endl";
			addToSymbolTable(globalSymbolTable, tempType, mode);
			addToSymbolTableList(globalSymbolTable, tempType, mode);
		}
		tempType = (NType *)getType(STREAM_TYPE);
		tempType->label = "std::cin";
		addToSymbolTable(globalSymbolTable, tempType, mode);
		addToSymbolTableList(globalSymbolTable, tempType, mode);
		tempType = (NType *)getType(STREAM_TYPE);
		tempType->label = "std::cout";
		addToSymbolTable(globalSymbolTable, tempType, mode);
		addToSymbolTableList(globalSymbolTable, tempType, mode);
		tempType = (NType *)getType(STREAM_TYPE);
		tempType->label = "std::endl";
		addToSymbolTable(globalSymbolTable, tempType, mode);
		addToSymbolTableList(globalSymbolTable, tempType, mode);
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
NType *getOperatorType(NType *op1, NType *op2, int tp){
	int fail;
	int base1, base2;
	fail = 0;
	if(SHOW_TREES) printf("\tOperator: %s : %s\n", humanreadable(op1->base_type), humanreadable(op2->base_type));
	
	if(op1->base_type == ARRAY_TYPE) {
		base1 = op1->u.arry.elemtype->base_type;
	} else base1 = op1->base_type;
	
	if(op2->base_type == ARRAY_TYPE) base2 = op2->u.arry.elemtype->base_type;
	else base2 = op2->base_type;
	
	if(SHOW_TREES) printf("\tBase:  %s : %s\n", humanreadable(base1), humanreadable(base2));
	if(op1->base_type == FUNC_TYPE || 
		op1->base_type == CLASS_TYPE || 
		op2->base_type == FUNC_TYPE || 
		op2->base_type == CLASS_TYPE){
				exitStatus = 3;
				getErrorMessage(ER_CLASS_FUNC_UNACC);
				yerror(NULL, op1->lineno);
				fail = 1;
	}
	if(base1 == base2) {
		return getType(op1->base_type);
	} else if(fail == 0) {
		exitStatus = 3;
		getErrorMessage(ER_TYPE_MISMATCH);
		yerror(NULL, op1->lineno);
		return NULL;
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
	dest->ref = source->ref;
	dest->cType = source->cType;
	dest->symbTable = source->symbTable;
	dest->offset = source->offset;
	dest->first = source->first;
	dest->follow = source->follow;

	switch(source->base_type){
		case ARRAY_TYPE :
			dest->u.arry.size = source->u.arry.size;
			if((dest->u.arry.elemtype = calloc(1, sizeof(struct typeinfo *))) == NULL) memoryError();
			dest->u.arry.elemtype = source->u.arry.elemtype;
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
			//dest->u.func.retType = source->u.func.retType;
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
					NType *constructor = getType(CONSTRUCTOR_TYPE);
					constructor->label = node->type->label;
					constructor->u.func.nargs = 0;
					constructor->pub = PUBLIC_TYPE;
					constructorField->elemtype = constructor;
					node->type->u.clas.f[0] = constructorField;
					node->type->u.clas.nfields++;
				}
				newField = (Field *)calloc(1, sizeof(Field));
				newField->name = member->label;
				//if(member->base_type == FUNC_TYPE){
				//	member = getSymbolFromTable(currentSymbolTable, member);
				//} else {
					newField->elemtype = member;
				//}
				node->type->u.clas.nfields++;
				if(node->type->u.clas.nfields % 10 > 8)
					node->type->u.clas.f = realloc(node->type->u.clas.f, ((int)(node->type->u.clas.nfields / 10) + 20) * sizeof(struct typeinfo *));
				node->type->u.clas.f[node->type->u.clas.nfields - 1] = newField;
			}
		}
	}
}

CodeElem *getLabel(){
	CodeElem *label;
	if((label = (CodeElem *)calloc(1, sizeof(CodeElem))) == NULL) memoryError();
	label->desc = labelNumber;
	label->loc = NULL;
	return label;
}

/* performs the first pass of semantic analysis by establishing the type of each node of the tree*/
void buildTypes(TreeNode *node){
	int c;
	NType *tempType;
	int mode = M_TYPES;
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
				node->type->first = node->u.n.child[0]->type;
				break;
				
			case NAMESPACE_NAMEr1 :
				if(SHOW_TREES) printf("namespace name1\n");
				node->type = getType(UNKNOWN_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[0]->type;
				break;
				
			case ORIGINAL_NAMESPACE_NAMEr1 :
				if(SHOW_TREES) printf("original namespace name1\n");
				node->type = getType(UNKNOWN_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[0]->type;
				break;
				
			case CLASS_NAMEr1 :
				if(SHOW_TREES) printf("class name1\n");
				node->type = getType(UNKNOWN_TYPE);
				node->u.n.child[0]->type = node->type;
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->type->first = node->u.n.child[0]->type;
				break;
				
			case ENUM_NAMEr1 :
				if(SHOW_TREES) printf("enum name1\n");
				node->type = getType(UNKNOWN_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[0]->type;
				break;
				
			case IDENTIFIERr1 :
				if(SHOW_TREES) printf("identifier1\n");
				node->type = getType(UNKNOWN_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[0]->type;
				break;
				
			case LITERALr1 :
				if(SHOW_TREES) printf("literal1\n");
				node->type = node->u.n.child[0]->type;
				node->type->first = node->u.n.child[0]->type;
				break;
			case LITERALr2 :
				if(SHOW_TREES) printf("literal2\n");
				node->type = node->u.n.child[0]->type;
				node->type->first = node->u.n.child[0]->type;
				break;
			case LITERALr3 :
				if(SHOW_TREES) printf("literal3\n");
				node->type = node->u.n.child[0]->type;
				node->type->first = node->u.n.child[0]->type;
				break;
			case LITERALr4 :
				if(SHOW_TREES) printf("literal4\n");
				node->type = node->u.n.child[0]->type;
				node->type->first = node->u.n.child[0]->type;
				break;
			case LITERALr5 :
				if(SHOW_TREES) printf("literal5\n");
				node->type = node->u.n.child[0]->type;
				node->type->first = node->u.n.child[0]->type;
				break;
				
			case INTEGER_LITERALr1 :
				if(SHOW_TREES) printf("integer literal1\n");
				node->type = getType(INT_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[0]->type;
				break;
			case CHARACTER_LITERALr1 :
				if(SHOW_TREES) printf("character literal1\n");
				node->type = getType(CHAR_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[0]->type;
				break;
			case FLOATING_LITERALr1 :
				if(SHOW_TREES) printf("floating literal1\n");
				node->type = getType(FLOAT_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[0]->type;
				break;
			case STRING_LITERALr1 :
				if(SHOW_TREES) printf("string literal1\n");
				node->type = getType(STR_TYPE_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[0]->type;
				break;
			case BOOLEAN_LITERALr1 :
				if(SHOW_TREES) printf("boolean literal1\n");
				node->type = getType(BOOL_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[0]->type;
				break;
			case BOOLEAN_LITERALr2 :
				if(SHOW_TREES) printf("boolean literal2\n");
				node->type = getType(BOOL_TYPE);
				node->type->label = node->u.n.child[0]->u.t.token->text;
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[0]->type;
				break;

			case TRANSLATION_UNITr1 :
				if(SHOW_TREES) printf("translation unit1\n");
				node->type = getType(PROGRAM_TYPE);
				node->type->label = "program";
				node->type->first = node->u.n.child[0]->type;
				break;
				
			case PRIMARY_EXPRESSIONr1 :
				if(SHOW_TREES) printf("primary expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case PRIMARY_EXPRESSIONr2 :
				if(SHOW_TREES) printf("primary expression2\n");
				exitStatus = 3;
				getErrorMessage(ER_NOT_SUPPORTED);
				yerror(node->type->label, node->lineno);
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
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;

			case NESTED_NAME_SPECIFIERr1 :
				if(SHOW_TREES) printf("nested name specifier1\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[2]->type;
				break;
			case NESTED_NAME_SPECIFIERr2 :
				if(SHOW_TREES) printf("nested name specifier2\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[2]->type;
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
				node->type = getType(ARRAY_TYPE);
				node->type->label = node->u.n.child[0]->type->label;
				node->type->u.arry.elemtype = node->u.n.child[0]->type; 
				node->type->first = node->u.n.child[0]->type;
				break;
			case POSTFIX_EXPRESSIONr3 :
				if(SHOW_TREES) printf("postfix expression3\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
			case POSTFIX_EXPRESSIONr5 :
				if(SHOW_TREES) printf("postfix expression5\n");
				node->type = node->u.n.child[0]->type;
				break;
			case POSTFIX_EXPRESSIONr6 :
				if(SHOW_TREES) printf("postfix expression6\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[2]->type;
				break;
			case POSTFIX_EXPRESSIONr7 :
				if(SHOW_TREES) printf("postfix expression7\n");
				node->type = node->u.n.child[1]->type;
				node->type->ref = node->u.n.child[0]->type->label;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
			case POSTFIX_EXPRESSIONr9 :
				if(SHOW_TREES) printf("postfix expression9\n");
				node->type = node->u.n.child[0]->type;
				break;
			case POSTFIX_EXPRESSIONr10 :
				if(SHOW_TREES) printf("postfix expression10\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[3]->type;
				break;
			case POSTFIX_EXPRESSIONr11 :
				if(SHOW_TREES) printf("postfix expression11\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[2]->type;
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
				if(SHOW_TREES) printf("postfix expression17\n");
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
							
			case EXPRESSION_LISTr1 :
				if(SHOW_TREES) printf("expression list1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case EXPRESSION_LISTr2 :
				if(SHOW_TREES) printf("expression list2\n");
				node->type = getType(TOUPLE_TYPE);
				node->type->u.touple.nelems = 2;
				if((node->type->u.touple.elems = calloc(2, sizeof(struct typeinfo *))) == NULL) memoryError();
				node->type->u.touple.elems[0] = node->u.n.child[0]->type;
				node->type->u.touple.elems[1] = node->u.n.child[1]->type;
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
				
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
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
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

			case MULTIPLICATIVE_EXPRESSIONr1 :
				if(SHOW_TREES) printf("multiplicative_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case MULTIPLICATIVE_EXPRESSIONr2 :
				if(SHOW_TREES) printf("multiplicative_expression2\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
			case MULTIPLICATIVE_EXPRESSIONr3 :
				if(SHOW_TREES) printf("multiplicative_expression3\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
			case MULTIPLICATIVE_EXPRESSIONr4 :
				if(SHOW_TREES) printf("multiplicative_expression4\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;

			case ADDITIVE_EXPRESSIONr1 :
				if(SHOW_TREES) printf("additive_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case ADDITIVE_EXPRESSIONr2 :
				if(SHOW_TREES) printf("additive_expression2\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
			case ADDITIVE_EXPRESSIONr3 :
				if(SHOW_TREES) printf("additive_expression3\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;

			case SHIFT_EXPRESSIONr1 :
				if(SHOW_TREES) printf("shift_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case SHIFT_EXPRESSIONr2 :
			/*??????????????????*/
				if(SHOW_TREES) printf("shift_expression2\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[2]->type;
				break;
			case SHIFT_EXPRESSIONr3 :
			/*??????????????????*/
				if(SHOW_TREES) printf("shift_expression3\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[2]->type;
				break;
			
			case RELATIONAL_EXPRESSIONr1 :
				if(SHOW_TREES) printf("relational_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case RELATIONAL_EXPRESSIONr2 :
				if(SHOW_TREES) printf("relational_expression2\n");
				node->type = getType(BOOL_TYPE);
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
			case RELATIONAL_EXPRESSIONr3 :
				if(SHOW_TREES) printf("relational_expression3\n");
				node->type = getType(BOOL_TYPE);
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
			case RELATIONAL_EXPRESSIONr4 :
				if(SHOW_TREES) printf("relational_expression4\n");
				node->type = getType(BOOL_TYPE);
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[2]->type;
				break;
			case RELATIONAL_EXPRESSIONr5 :
				if(SHOW_TREES) printf("relational_expression5\n");
				node->type = getType(BOOL_TYPE);
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[2]->type;
				break;
				
			case EQUALITY_EXPRESSIONr1 :
				if(SHOW_TREES) printf("equality_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case EQUALITY_EXPRESSIONr2 :
				if(SHOW_TREES) printf("equality_expression2\n");
				node->type = getType(BOOL_TYPE);
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[2]->type;
				break;
			case EQUALITY_EXPRESSIONr3 :
				if(SHOW_TREES) printf("equality_expression3\n");
				node->type = getType(BOOL_TYPE);
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[2]->type;
				break;
				
			case AND_EXPRESSIONr1 :
				if(SHOW_TREES) printf("and_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case AND_EXPRESSIONr2 :
				if(SHOW_TREES) printf("and_expression2\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
				
			case EXCLUSIVE_OR_EXPRESSIONr1 :
				if(SHOW_TREES) printf("exclusive_or_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case EXCLUSIVE_OR_EXPRESSIONr2 :
				if(SHOW_TREES) printf("exclusive_or_expression2\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
				
			case INCLUSIVE_OR_EXPRESSIONr1 :
				if(SHOW_TREES) printf("inclusive_or_expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case INCLUSIVE_OR_EXPRESSIONr2 :
				if(SHOW_TREES) printf("inclusive_or_expression2\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;

			case LOGICAL_AND_EXPRESSIONr1 :
				if(SHOW_TREES) printf("logical and expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case LOGICAL_AND_EXPRESSIONr2 :
				if(SHOW_TREES) printf("logical and expression2\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;

			case LOGICAL_OR_EXPRESSIONr1 :
				if(SHOW_TREES) printf("logical or expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case LOGICAL_OR_EXPRESSIONr2 :
				if(SHOW_TREES) printf("logical or expression2\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;

			case CONDITIONAL_EXPRESSIONr1 :
				if(SHOW_TREES) printf("conditional expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case CONDITIONAL_EXPRESSIONr2 :
				if(SHOW_TREES) printf("conditional expression2\n");
				exitStatus = 3;
				getErrorMessage(ER_NOT_SUPPORTED);
				yerror("Conditional Expression", node->lineno);
				break;

			case ASSIGNMENT_EXPRESSIONr1 :
				if(SHOW_TREES) printf("assignment expression1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case ASSIGNMENT_EXPRESSIONr2 :
				if(SHOW_TREES) printf("assignment expression2\n");
				node->type = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[2]->type;
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
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
				
			case CONSTANT_EXPRESSIONr1 :
				if(SHOW_TREES) printf("constant_expression1\n");
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
				node->type = getType(STATEMENT_TYPE);
				break;
			case LABELED_STATEMENTr2 :
				if(SHOW_TREES) printf("labeled_statement2\n");
				if(node->u.n.child[1]->type->base_type != INT_TYPE || node->u.n.child[1]->type->base_type != ENUM_TYPE){
					exitStatus = 3;
					getErrorMessage(ER_INT_EXPECTED);
					yerror(NULL, node->lineno);
				}
				node->type = getType(STATEMENT_TYPE);
				node->type->first = node->u.n.child[1]->type;
				node->u.n.child[1]->type->follow = node->u.n.child[2]->type;
				break;
			case LABELED_STATEMENTr3 :
				if(SHOW_TREES) printf("labeled_statement3\n");
				node->type = getType(STATEMENT_TYPE);
				node->type->first = node->u.n.child[1]->type;
				break;
	
			case EXPRESSION_STATEMENTr1 :
				if(SHOW_TREES) printf("expression statement1\n");
				node->type = getType(STATEMENT_TYPE);
				node->type->first = node->u.n.child[0]->type;
				break;

			case COMPOUND_STATEMENTr1 :
				if(SHOW_TREES) printf("compound statement1\n");
				node->type = getType(STATEMENT_TYPE);
				node->type->first = node->u.n.child[0]->type;
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
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;

			case CONDITIONr1 :
				if(SHOW_TREES) printf("condition1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case CONDITIONr2 :
				if(SHOW_TREES) printf("condition2\n");
				node->type = getOperatorType(node->u.n.child[0]->type,node->u.n.child[2]->type, TP_EQUA);
				node->u.n.child[1]->type->follow = node->u.n.child[2]->type;
				break;
				
			case SELECTION_STATEMENTr1 :
				if(SHOW_TREES) printf("selection_statement1\n");
				node->type = getType(STATEMENT_TYPE);
				if(node->u.n.child[1]->type->base_type != BOOL_TYPE && node->u.n.child[1]->type->base_type != INT_TYPE){
					exitStatus = 3;
					getErrorMessage(ER_BOOL_EXPECTED);
					yerror(NULL, node->lineno);
				}
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[1]->type;
				node->u.n.child[1]->type->follow = node->u.n.child[2]->type;
				break;
			case SELECTION_STATEMENTr2 :
				if(SHOW_TREES) printf("selection_statement2\n");
				node->type = getType(STATEMENT_TYPE);
				if(node->u.n.child[1]->type->base_type != BOOL_TYPE && node->u.n.child[1]->type->base_type != INT_TYPE){
					exitStatus = 3;
					getErrorMessage(ER_BOOL_EXPECTED);
					yerror(NULL, node->lineno);
				}
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[1]->type;
				node->u.n.child[1]->type->follow = node->u.n.child[2]->type;
				node->u.n.child[2]->type->follow = node->u.n.child[4]->type;
				break;
			case SELECTION_STATEMENTr3 :
				if(SHOW_TREES) printf("selection_statement3\n");
				node->type = getType(STATEMENT_TYPE);
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[1]->type;
				node->u.n.child[1]->type->follow = node->u.n.child[2]->type;
				break;
	
			case ITERATION_STATEMENTr1 :
				if(SHOW_TREES) printf("iteration statement1\n");
				node->type = getType(STATEMENT_TYPE);
				if(node->u.n.child[1]->type->base_type != BOOL_TYPE){
					exitStatus = 2;
					getErrorMessage(ER_BOOL_EXPECTED);
					yerror(NULL, node->lineno);
				}
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[1]->type;
				node->u.n.child[1]->type->follow = node->u.n.child[2]->type;
				break;
			case ITERATION_STATEMENTr2 :
				if(SHOW_TREES) printf("iteration statement2\n");
				node->type = getType(STATEMENT_TYPE);
				if(node->u.n.child[3]->type->base_type != BOOL_TYPE){
					exitStatus = 3;
					getErrorMessage(ER_BOOL_EXPECTED);
					yerror(NULL, node->lineno);
				}
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[1]->type;
				node->u.n.child[1]->type->follow = node->u.n.child[3]->type;
				break;
			case ITERATION_STATEMENTr3 :
				if(SHOW_TREES) printf("iteration statement3\n");
				node->type = getType(STATEMENT_TYPE);
				node->u.n.child[0]->type = node->type;
				node->type->first = node->u.n.child[1]->type;
				node->u.n.child[1]->type->follow = node->u.n.child[2]->type;
				node->u.n.child[2]->type->follow = node->u.n.child[3]->type;
				node->u.n.child[3]->type->follow = node->u.n.child[4]->type;
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
				yerror(NULL, node->lineno);
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
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
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
				yerror("friend", node->lineno);
				exit(exitStatus);
				break;
			case DECL_SPECIFIERr5:
				if(SHOW_TREES) printf("decl specifier5\n");
				exitStatus = 3;
				getErrorMessage(ER_NOT_SUPPORTED);
				yerror("typedef", node->lineno);
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

			case ENUM_SPECIFIERr1 :
				if(SHOW_TREES) printf("enum specifier1\n");
				node->type = getType(ENUM_TYPE);
				node->type->first = node->u.n.child[1]->type;
				node->u.n.child[1]->type->follow = node->u.n.child[2]->type;
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
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;

			case ENUMERATOR_DEFINITIONr1 :
				if(SHOW_TREES) printf("enumerator_definition1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case ENUMERATOR_DEFINITIONr2 :
				if(SHOW_TREES) printf("enumerator_definition2\n");
				node->type = node->u.n.child[0]->type;
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
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
				yerror("namespace", node->lineno);
				break;
				
			case ASM_DEFINITIONr1 :
				if(SHOW_TREES) printf("asm_definition1\n");
				node->type = node->u.n.child[1]->type;
				break;
			
			case LINKAGE_SPECIFICATIONr1 :
			case LINKAGE_SPECIFICATIONr2 :
				exitStatus = 3;
				getErrorMessage(ER_NOT_SUPPORTED);
				yerror("extern", node->lineno);
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
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;

			case INIT_DECLARATORr1 :
				if(SHOW_TREES) printf("init declarator1 \n");
				node->type = node->u.n.child[0]->type;
				//passTypeBelowPointer(node->u.n.child[0]->type, node->u.n.child[1]->type);
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
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
				
			case DIRECT_DECLARATORr1:
				if(SHOW_TREES) printf("direct declarator1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case DIRECT_DECLARATORr2:
				if(SHOW_TREES) printf("direct declarator2\n");
				node->type = getType(FUNC_TYPE);
				node->type->u.func.parent = NULL;
				node->type->u.func.retType = node->u.n.child[0]->type;
				node->type->label = node->u.n.child[0]->type->label;
				node->type->u.func.nargs = 0;
				addParamsToFunction(node, node->u.n.child[1]->type);
				passTypeBelowPointer(node->type, node->u.n.child[0]->type);
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				node->u.n.child[1]->type->follow = node->u.n.child[2]->type;
				node->u.n.child[2]->type->follow = node->u.n.child[3]->type;
				break;
			case DIRECT_DECLARATORr3:
				if(SHOW_TREES) printf("direct declarator3\n");
				node->type = getType(FUNC_TYPE);
				node->type->u.func.parent = NULL;
				node->type->u.func.retType = node->u.n.child[0]->type;
				node->type->label = node->u.n.child[0]->type->label;
				node->type->u.func.nargs = 0;
				addParamsToFunction(node, node->u.n.child[1]->type);
				passTypeBelowPointer(node->type, node->u.n.child[0]->type);
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				node->u.n.child[1]->type->follow = node->u.n.child[2]->type;
				break;
			case DIRECT_DECLARATORr4:
				if(SHOW_TREES) printf("direct declarator4\n");
				node->type = getType(FUNC_TYPE);
				node->type->u.func.parent = NULL;
				node->type->u.func.retType = node->u.n.child[0]->type;
				node->type->label = node->u.n.child[0]->type->label;
				node->type->u.func.nargs = 0;
				addParamsToFunction(node, node->u.n.child[1]->type);
				passTypeBelowPointer(node->type, node->u.n.child[0]->type);
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				node->u.n.child[1]->type->follow = node->u.n.child[2]->type;
				break;
			case DIRECT_DECLARATORr5:
				if(SHOW_TREES) printf("direct declarator5\n");
				node->type = getType(FUNC_TYPE);
				//node->type = node->u.n.child[0]->type;
				node->type->u.func.parent = NULL;
				node->type->u.func.retType = node->u.n.child[0]->type;
				node->type->label = node->u.n.child[0]->type->label;
				node->type->u.func.nargs = 0;
				addParamsToFunction(node, node->u.n.child[1]->type);
				passTypeBelowPointer(node->type, node->u.n.child[0]->type);
				node->type->first = node->u.n.child[0]->type;
				node->u.n.child[0]->type->follow = node->u.n.child[1]->type;
				break;
			case DIRECT_DECLARATORr6:
			/*????????*/
				if(SHOW_TREES) printf("direct declarator6\n");
				node->type = node->u.n.child[0]->type;
				//node->type->temp = node->u.n.child[1]->type;
				break;
			case DIRECT_DECLARATORr7:
			/*????????*/
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
				node->type = getType(ARRAY_TYPE);
				node->type->label = node->u.n.child[0]->type->label;
				node->type->pub = node->u.n.child[0]->type->pub;
				node->type->u.arry.elemtype = node->u.n.child[1]->type;
				node->type->u.arry.size = atoi(node->u.n.child[1]->type->label);
				break;
			case DIRECT_DECLARATORr10:
			/*????????*/
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
	
			case TYPE_SPECIFIER_SEQr1 :
				if(SHOW_TREES) printf("type_specifier_id1\n");
				node->type = node->u.n.child[0]->type;
				break;
	
			case ABSTRACT_DECLARATORr1 :
				if(SHOW_TREES) printf("abstract_declarator1\n");
				node->type = node->u.n.child[0]->type;
				break;
			case ABSTRACT_DECLARATORr2 :
				if(SHOW_TREES) printf("abstract_declarator2\n");
				node->type = node->u.n.child[0]->type;
				break;

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
				break;
			case FUNCTION_DEFINITIONr3:
				if(SHOW_TREES) printf("function definition3\n");
				node->type = node->u.n.child[0]->type;
				break;
			case FUNCTION_DEFINITIONr4:
				if(SHOW_TREES) printf("function definition4\n");
				node->type = node->u.n.child[1]->type;
				node->type->u.func.retType = node->u.n.child[0]->type;
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
				copyType(node->type, node->u.n.child[1]->type);
				break;
			case CLASS_HEADr2 :
				if(SHOW_TREES) printf("type head2\n");
				node->type = node->u.n.child[0]->type;
				node->type->label = node->u.n.child[1]->type->label;
				copyType(node->type, node->u.n.child[1]->type);
				break;
			case CLASS_HEADr3 :
				if(SHOW_TREES) printf("type head3\n");
				node->type = node->u.n.child[0]->type;
				node->type->label = node->u.n.child[2]->type->label;
				copyType(node->type, node->u.n.child[2]->type);
				break;
			case CLASS_HEADr4 :
				if(SHOW_TREES) printf("type head4\n");
				node->type = node->u.n.child[0]->type;
				node->type->label = node->u.n.child[2]->type->label;
				copyType(node->type, node->u.n.child[2]->type);
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
				if(node->type->base_type == FUNC_TYPE) {
					if(SHOW_TREES)printf("**** function: %s\n", node->type->label);
					node->type->u.func.retType = node->u.n.child[0]->type;
					if(SHOW_TREES)printf("**** return type: %s\n", humanreadable(node->type->u.func.retType->base_type));
					node->u.n.child[0]->type = node->type;
					if(SHOW_TREES)printf("**** return type: %s\n", humanreadable(node->u.n.child[0]->type->u.func.retType->base_type));
				} else {
					passTypeBelowPointer(node->u.n.child[0]->type, node->u.n.child[1]->type);
				}
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
	
			case CONSTANT_INITIALIZERr1 :
				if(SHOW_TREES) printf("constant_initializer1\n");
				node->type = node->u.n.child[1]->type;
				break;
	
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

			case DECLARATION_SEQ_OPTr1 :
				if(SHOW_TREES) printf("declaration seq opt1\n");
				node->type = getType(NULL_TYPE);
				break;
			case DECLARATION_SEQ_OPTr2 :
				if(SHOW_TREES) printf("declaration seq opt2\n");
				node->type = node->u.n.child[0]->type;
				break;

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

void addSimpleDeclarations(SymbolTable *currentSymbolTable, NType *current, int mode){
	if(SHOW_TREES) printf("**addSimpleDeclarations**\n");
	NType *tempType = NULL;
	if(current != NULL){
		if(current->base_type == TOUPLE_TYPE){
			addSimpleDeclarations(currentSymbolTable, current->u.touple.elems[0], mode);
			addSimpleDeclarations(currentSymbolTable, current->u.touple.elems[1], mode);
		} else {
			addToSymbolTable(currentSymbolTable, current, mode);
			addToSymbolTableList(currentSymbolTable, current, mode);
		}
	}
}

NType *createTempSymbol(NType *source, int lab, int mode){
	char *pre;
	NType *tempSymb;
	if((tempSymb = (NType *)calloc(1, sizeof(NType))) == NULL) memoryError();
	char *name;
	char *number;
	if((pre = (char *)calloc(8, sizeof(char))) == NULL) memoryError();
	if((name = (char *)calloc(16, sizeof(char))) == NULL) memoryError();
	if((number = (char *)calloc(8, sizeof(char))) == NULL) memoryError();
	switch(lab){
		case T_TEMP :
			pre = "_Temp_";
			break;
		case T_CONST :
			pre = "_Const_";
			break;
	}
if(SHOW_TREES)printf("temp count: %d\n", tempSymbNumber);
	sprintf(number, "%d", tempSymbNumber++);
	strcat(name, pre);
	strcat(name, number);
	tempSymb->label = name;
	tempSymb->base_type = source->base_type;
	tempSymb->symbTable = source->symbTable;
	tempSymb->offset = tempSymb->symbTable->offset;
if(SHOW_TREES)printf("%s %d\n", tempSymb->label, tempSymb->symbTable->offset);
	if(!inSymbolTable(tempSymb->symbTable, tempSymb)){
		addToSymbolTable(source->symbTable, tempSymb, mode);
		addToSymbolTableList(source->symbTable, tempSymb, mode);
	} else {
		tempSymb = getSymbolFromTable(tempSymb->symbTable, tempSymb);
	}
	tempSymb->val = source->label;
	return tempSymb;
}

NType *addToStringList(NType *source){
	SymbolListItem *listItem;
	if((listItem = (SymbolListItem *)calloc(1, sizeof(SymbolListItem))) == NULL) memoryError();
	listItem->item = source;
	listItem->offset = stringListOffset;
	source->offset = stringListOffset;
	stringListOffset += strlen(source->label);
	if(stringTable->list->head == NULL){
		stringTable->list->head = listItem;
		stringTable->list->tail = listItem;
	} else {
		stringTable->list->tail->next = listItem;
		stringTable->list->tail = listItem;
	}
	source->symbTable = stringTable;
	return source;
}

char *cvnIntString(int length, int *stVal){
   char *st = (char *)calloc(length, sizeof(char));
	if(st == NULL) memoryError();
   int s = 0;  /* 182 */
   int i;
   int escape = 0;
   for(i = 0; i < length; i++){
      if(escape == 0){
         if(stVal[i] != (int)'\"')
            if(stVal[i] == (int)'\\') escape = 1;
            else {
               st[s] = (char)stVal[i];
               s++;
            }
      }else{
		   int ch = -1;
	      switch(stVal[i]) {
		      case (int)'n' :
		         ch = 10;
				   break;
			   case (int)'t' :
			      ch = 9;
				   break;
			   case (int)'\'' :
			   case (int)'\"' :
			   case (int)'\\' :
			      ch = stVal[i];
				   break;
			   case (int)'0' :
			      ch = 0;
				   break;
			}
			if (ch >= 0) {
			   st[s] = (char)ch;
				s++;
			}			
      escape = 0;
    }
  }
  return st;
}

/* adds symbols in a function body and type checks for appropriate type.*/
void addFunctionBodySymbols(SymbolTable *currentSymbolTable, TreeNode *node, int mode){
	if(SHOW_TREES) printf("**addFunctionBodySymbols**\n");
	SymbolTable *oldSymbolTable;
	NType *tempType;
	int i;
	char *str;
	int fail = 0;
	if(node != NULL){
		if(SHOW_TREES)if(node->type->base_type == FUNC_TYPE) printf("**** %d ****\n", node->type->u.func.nargs);
		switch(node->u.n.rule) {
			case MULTIPLICATIVE_EXPRESSIONr2 :
				if(SHOW_TREES) printf("multiplicative_expression 2\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL)copyType(tempType, node->u.n.child[0]->type);
				}
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL)copyType(tempType, node->u.n.child[1]->type);
				}
				getOperatorType(node->u.n.child[0]->type, node->u.n.child[1]->type, TP_CALC);
				break;
			case MULTIPLICATIVE_EXPRESSIONr3 :
				if(SHOW_TREES) printf("multiplicative_expression 3\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL)copyType(tempType, node->u.n.child[0]->type);
				}
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL)copyType(tempType, node->u.n.child[1]->type);
				}
				getOperatorType(node->u.n.child[0]->type, node->u.n.child[1]->type, TP_CALC);
				break;
			case MULTIPLICATIVE_EXPRESSIONr4 :
				if(SHOW_TREES) printf("multiplicative_expression 4\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL)copyType(tempType, node->u.n.child[0]->type);
				}
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL)copyType(tempType, node->u.n.child[1]->type);
				}
				getOperatorType(node->u.n.child[0]->type, node->u.n.child[1]->type, TP_CALC);
				break;

			case ADDITIVE_EXPRESSIONr2 :
				if(SHOW_TREES) printf("additive_expression 2\n");
				if(SHOW_TREES)printf("%s\n", humanreadable(node->u.n.child[0]->type->base_type));
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL)copyType(tempType, node->u.n.child[0]->type);
				}
				if(SHOW_TREES)printf("%s\n", humanreadable(node->u.n.child[1]->type->base_type));
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[1]->type);
					if(tempType != NULL)copyType(tempType, node->u.n.child[1]->type);
				}
				getOperatorType(node->u.n.child[0]->type, node->u.n.child[1]->type, TP_CALC);
				break;
			case ADDITIVE_EXPRESSIONr3 :
				if(SHOW_TREES) printf("additive_expression 3\n");
				if(SHOW_TREES)printf("%s %s\n", humanreadable(node->u.n.child[0]->type->base_type), node->u.n.child[0]->type->label);
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
				if(SHOW_TREES)printf("%s\n", humanreadable(tempType->base_type));
					if(tempType != NULL)copyType(tempType, node->u.n.child[0]->type);
				}
				if(SHOW_TREES)printf("%s\n", humanreadable(node->u.n.child[1]->type->base_type));
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[1]->type);
				if(SHOW_TREES)printf("%s\n", humanreadable(tempType->base_type));
					if(tempType != NULL)copyType(tempType, node->u.n.child[1]->type);
				}
				getOperatorType(node->u.n.child[0]->type, node->u.n.child[1]->type, TP_CALC);
				break;
		
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
				addSimpleDeclarations(currentSymbolTable, node->u.n.child[1]->type, mode);
				if(SHOW_TREES) printf("simple declaration 1 complete\n");
				break;
			case SIMPLE_DECLARATIONr2 :
				if(SHOW_TREES) printf("simple declaration 2\n");
				if(SHOW_TREES)addSimpleDeclarations(currentSymbolTable, node->u.n.child[1]->type, mode);
				if(SHOW_TREES) printf("simple declaration 2 complete\n");
				break;
			
			case POSTFIX_EXPRESSIONr2 :
				if(SHOW_TREES) printf("postfix expression 2\n");
				tempType = getSymbolFromTable(currentSymbolTable, node->type);
				if(tempType == NULL){
					exitStatus = 3;
					getErrorMessage(ER_FUNC_NOT_DEFINED);
					yerror(node->type->ref, node->lineno);
				} else {
					copyType(tempType, node->type);
				}
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
								yerror(node->type->ref, node->lineno);
							}
						} else {
							tempType = getSymbolFromTable(tempType->cType->symbTable, node->type);
						}
						if(tempType != NULL){
							copyType(tempType, node->type);
						} else {
							exitStatus = 3;
							getErrorMessage(ER_FUNC_NOT_DEFINED);
							yerror(node->type->ref, node->lineno);
						}
					} else {
						exitStatus = 3;
						getErrorMessage(ER_CLASS_NOT_DEFINED);
						yerror(node->type->ref, node->lineno);
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
						yerror(node->type->label, node->lineno);
					}
				}
				if(SHOW_TREES) printf("*** %s : %s ***\n", 
							humanreadable(currentSymbolTable->scope->u.func.retType->base_type),
							humanreadable(node->type->base_type));
				tempType = checkType(currentSymbolTable->scope->u.func.retType, node->type);
				if(tempType == NULL){
					exitStatus = 3;
					getErrorMessage(ER_RETURN_TYPE);
					yerror(NULL, node->lineno);
				}
				break;
				
			case SELECTION_STATEMENTr3 :
				if(SHOW_TREES) printf("selection_statement 3\n");
				node->type = getType(STATEMENT_TYPE);
				tempType = NULL;
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[1]->type);
					if(tempType != NULL){
						copyType(tempType, node->u.n.child[1]->type);
					} else {
						exitStatus = 3;
						getErrorMessage(ER_FUNC_NOT_DEFINED);
						yerror(node->type->label, node->lineno);
					}
				}
				if(node->u.n.child[1]->type->base_type != INT_TYPE && node->u.n.child[1]->type->base_type != ENUM_TYPE){
					exitStatus = 3;
					getErrorMessage(ER_INT_EXPECTED);
					yerror(NULL, node->lineno);
				}
				break;
			
			case RELATIONAL_EXPRESSIONr2 :
			case RELATIONAL_EXPRESSIONr3 :
				if(SHOW_TREES) printf("relational_expression\n");
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE){
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL){
						copyType(tempType, node->u.n.child[0]->type);
					} else {
						fail = 1;
					}
				}
				if(node->u.n.child[1]->type->base_type == UNKNOWN_TYPE){
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[1]->type);
					if(tempType != NULL){
						copyType(tempType, node->u.n.child[2]->type);
					} else {
						fail = 1;
					}
				}
				if(fail == 0) tempType = getOperatorType(node->u.n.child[0]->type, node->u.n.child[1]->type, TP_EQUA);
				break;
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
						fail = 1;
					}
				}
				if(node->u.n.child[2]->type->base_type == UNKNOWN_TYPE){
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[2]->type);
					if(tempType != NULL){
						copyType(tempType, node->u.n.child[2]->type);
					} else {
						fail = 1;
					}
				}
				if(fail == 0) tempType = getOperatorType(node->u.n.child[0]->type, node->u.n.child[2]->type, TP_EQUA);
				break;
				
			case IDENTIFIERr1 :
				if(SHOW_TREES) printf("identifier 1\n");
				if(SHOW_TREES) printf("%s %s\n", humanreadable(node->type->base_type), node->type->label);
				if(node->type->base_type == UNKNOWN_TYPE) {
					tempType = getSymbolFromTable(currentSymbolTable, node->type);
					if(tempType != NULL)copyType(tempType, node->type);
				}
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE){
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL){
						if(SHOW_TREES) printf("Temp: %s %s\n", humanreadable(tempType->base_type), tempType->label);
						copyType(tempType, node->u.n.child[0]->type);
					} else {
						if(SHOW_TREES) printf("Temp: NULL\n");
						exitStatus = 3;
						getErrorMessage(ER_FUNC_NOT_DEFINED);
						yerror(node->type->label, node->lineno);
					}
				}
				if(SHOW_TREES) printf("%s %s\n", humanreadable(node->type->base_type), node->type->label);
				break;
			
			case LITERALr4 :
				if(SHOW_TREES)printf("literal 4\n");
				node->type->label = cvnIntString(node->u.t.token->ival, node->u.t.token->sval);
				//node->type->label = node->u.t.token->text;
				tempType = addToStringList(node->type);
				copyType(tempType, node->type);
				break;
			case LITERALr1 :
			case LITERALr2 :
			case LITERALr3 :
			case LITERALr5 :
			if(SHOW_TREES)printf("literal\n");
				tempType = (NType *)createTempSymbol(node->type, T_CONST, mode);
				copyType(tempType, node->type);
				break;
	
			case ASSIGNMENT_EXPRESSIONr2 :
				if(SHOW_TREES) printf("assignment_expression 2\n");
				//test left side
				tempType = NULL;
				if(node->u.n.child[0]->type->base_type == UNKNOWN_TYPE){
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
					if(tempType != NULL){
						copyType(tempType, node->u.n.child[0]->type);
					} else {
						fail = 1;
					}
				}
				tempType = NULL;
				if(node->u.n.child[0]->type->base_type == ARRAY_TYPE){
					if(node->u.n.child[0]->type->u.arry.elemtype->base_type == UNKNOWN_TYPE){
						tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[0]->type);
						if(tempType != NULL){
							copyType(tempType, node->u.n.child[0]->type);
						} else {
							exitStatus = 3;
							getErrorMessage(ER_FUNC_NOT_DEFINED);
							yerror(node->type->label, node->lineno);
							fail = 1;
						}
					}
				}
				if(SHOW_TREES) printf("%s %s\n", humanreadable(node->u.n.child[0]->type->base_type), node->u.n.child[0]->type->label);
				//test right side
				tempType = NULL;
				if(node->u.n.child[2]->type->base_type == UNKNOWN_TYPE){
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[2]->type);
					if(tempType != NULL){
						copyType(tempType, node->u.n.child[2]->type);
					} else {
						fail = 1;
					}
				}
				tempType = NULL;
				if(node->u.n.child[1]->type->base_type == ARRAY_TYPE){
					if(node->u.n.child[1]->type->u.arry.elemtype->base_type == UNKNOWN_TYPE){
						tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[1]->type);
						if(tempType != NULL){
							copyType(tempType, node->u.n.child[1]->type);
						} else {
							exitStatus = 3;
							getErrorMessage(ER_FUNC_NOT_DEFINED);
							yerror(node->type->label, node->lineno);
							fail = 1;
						}
					}
				}
				if(SHOW_TREES) printf("%s %s\n", humanreadable(node->u.n.child[2]->type->base_type), node->u.n.child[2]->type->label);
				if(fail == 0) tempType = getOperatorType(node->u.n.child[0]->type, node->u.n.child[2]->type, TP_EQUA);
				fail = 0;
				break;

			default :
				break;
		}
		int n;
		for(n = 0; n < node->u.n.children; n++){
			addFunctionBodySymbols(currentSymbolTable, node->u.n.child[n], mode);
		}
	}
}

/*performs the second pass of semantic analysis completing the node types and checking
for types for approriateness and creating symbol tables and adding symbols to those
tables.*/
void makeSymbolTables(TreeNode *node){
	if(node->lineno != NULL) node->type->lineno = node->lineno;
	SymbolTable *oldSymbolTable;
	SymbolTable *newSymbolTable;
	NType *tempType;
	int p;
	int mode = M_SYMBOLS;
	node->type->val = node->type->label;
	if(node != NULL){
		//recursion
		int n;
		for(n = 0; n < node->u.n.children; n++){
			makeSymbolTables(node->u.n.child[n]);
		}
		switch(node->u.n.rule) {
			case TRANSLATION_UNITr1 :
				if(SHOW_TREES) printf("translation unit 1\n");
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
			
			case DIRECT_DECLARATORr7 :
				if(SHOW_TREES) printf("direct_declarator 7\n");
					tempType = getSymbolFromTable(currentSymbolTable, node->u.n.child[2]->type);
					if(tempType != NULL) node->u.n.child[2]->type->u.func.retType = tempType->u.func.retType;
				break;

				
			case FUNCTION_DEFINITIONr1 :
				if(SHOW_TREES) printf("function definition 1\n");
				oldSymbolTable = currentSymbolTable;
				if(node->type->base_type == FUNC_TYPE)
					currentSymbolTable = getSymbolTable(globalSymbolTable, node->type->u.func.parent);
				if(currentSymbolTable == NULL) currentSymbolTable = oldSymbolTable;
				addToSymbolTable(currentSymbolTable, node->type, mode);
				addToSymbolTableList(currentSymbolTable, node->type, mode);
				currentSymbolTable = createSymbolTable(currentSymbolTable, currentSymbolTable->size);
				currentSymbolTable->scope = node->type;
				passSymbolTableDownTree(currentSymbolTable, node);
				//add parameters
			if(SHOW_TREES)printf("makeSymbolTables **** %d ****\n", node->type->u.func.nargs);
				for(p = 0; p < node->type->u.func.nargs; p++){
					addToSymbolTable(currentSymbolTable, node->type->u.func.args[p]->elemtype, mode);
					addToSymbolTableList(currentSymbolTable, node->type->u.func.args[p]->elemtype, mode);
				}
				//add body variables
				addFunctionBodySymbols(currentSymbolTable, node->u.n.child[2], mode);
				currentSymbolTable = oldSymbolTable;
				if(SHOW_TREES) printf("function definition 1 complete[%d]\n", currentSymbolTable->entries);
				break;	
			case FUNCTION_DEFINITIONr2 :
				if(SHOW_TREES) printf("function definition 2\n");	
				oldSymbolTable = currentSymbolTable;
				if(!inSymbolTable(currentSymbolTable, node->type)){
					addToSymbolTable(currentSymbolTable, node->type, mode);
					addToSymbolTableList(currentSymbolTable, node->type, mode);
					// create symbol table
					currentSymbolTable = createSymbolTable(currentSymbolTable, currentSymbolTable->size);
					currentSymbolTable->scope = node->type;
					passSymbolTableDownTree(currentSymbolTable, node);
					//add parameters
					for(p = 0; p < node->type->u.func.nargs; p++){
						addToSymbolTable(currentSymbolTable, node->type->u.func.args[p]->elemtype, mode);
						addToSymbolTableList(currentSymbolTable, node->type->u.func.args[p]->elemtype, mode);
					}
					//add body variables
					addFunctionBodySymbols(currentSymbolTable, node->u.n.child[3], mode);
					currentSymbolTable = oldSymbolTable;
					if(SHOW_TREES) printf("function definition 2 complete [%d]\n", currentSymbolTable->entries);
				}
				break;
				
			case FUNCTION_DEFINITIONr3 :
				if(SHOW_TREES) printf("function definition 3\n");
				oldSymbolTable = currentSymbolTable;
				addToSymbolTable(currentSymbolTable, node->type, mode);
				addToSymbolTableList(currentSymbolTable, node->type, mode);
				currentSymbolTable = createSymbolTable(currentSymbolTable, currentSymbolTable->size);
				currentSymbolTable->scope = node->type;
				passSymbolTableDownTree(currentSymbolTable, node);
				//add parameters
				for(p = 0; p < node->type->u.func.nargs; p++){
					addToSymbolTable(currentSymbolTable, node->type->u.func.args[p]->elemtype, mode);
					addToSymbolTableList(currentSymbolTable, node->type->u.func.args[p]->elemtype, mode);
				}
				//add body variables
				addFunctionBodySymbols(currentSymbolTable, node->u.n.child[2], mode);
				currentSymbolTable = oldSymbolTable;
				if(SHOW_TREES) printf("function definition 3 complete[%d]\n", currentSymbolTable->entries);
				break;
			case FUNCTION_DEFINITIONr4 :
				if(SHOW_TREES) printf("function definition 4\n");
				oldSymbolTable = currentSymbolTable;
				addToSymbolTable(currentSymbolTable, node->type, mode);
				addToSymbolTableList(currentSymbolTable, node->type, mode);
				currentSymbolTable = createSymbolTable(currentSymbolTable, currentSymbolTable->size);
				currentSymbolTable->scope = node->type;
				passSymbolTableDownTree(currentSymbolTable, node);
				//add parameters
				for(p = 0; p < node->type->u.func.nargs; p++){
					addToSymbolTable(currentSymbolTable, node->type->u.func.args[p]->elemtype, mode);
					addToSymbolTableList(currentSymbolTable, node->type->u.func.args[p]->elemtype, mode);
				}
				//add body variables
				addFunctionBodySymbols(currentSymbolTable, node->u.n.child[3], mode);
				currentSymbolTable = oldSymbolTable;
				if(SHOW_TREES) printf("function definition 4 complete[%d]\n", currentSymbolTable->entries);
				break;

			case CLASS_SPECIFIERr1 :
				if(SHOW_TREES) printf("class specifier 1\n");
				oldSymbolTable = currentSymbolTable;
				addToSymbolTable(currentSymbolTable, node->type, mode);
				addToSymbolTableList(currentSymbolTable, node->type, mode);
				//create symbol table
				currentSymbolTable = createSymbolTable(currentSymbolTable, currentSymbolTable->size);
				currentSymbolTable->scope = node->type;
				passSymbolTableDownTree(currentSymbolTable, node);
				//add members
				for(p = 0; p < node->type->u.clas.nfields; p++){
					addToSymbolTable(currentSymbolTable, node->type->u.clas.f[p]->elemtype, mode);
					addToSymbolTableList(currentSymbolTable, node->type->u.clas.f[p]->elemtype, mode);
					newSymbolTable = createSymbolTable(currentSymbolTable, currentSymbolTable->size);
					newSymbolTable->scope = node->type->u.clas.f[p]->elemtype;
					node->type->u.clas.f[p]->elemtype->symbTable = newSymbolTable;
				}
				if(SHOW_TREES) printf("class specifier 1 complete[%d]\n", currentSymbolTable->entries);
				currentSymbolTable = oldSymbolTable;
				break;
								
			default : 
				//if(SHOW_TREES) printf("oops!\n");
				break;
		}
	}
}

IntrCode *makeLabel(){
	char *pre;
	char *number;
	char *label;
	CodeElem *elem;
	IntrCode *intrCode;
	Location *loc;
	if((pre = (char *)calloc(8, sizeof(char))) == NULL) memoryError();
	if((number = (char *)calloc(8, sizeof(char))) == NULL) memoryError();
	if((label = (char *)calloc(16, sizeof(char))) == NULL) memoryError();
	pre = "LABEL_";
	sprintf(number, "%d", labelNumber++);
	strcat(label, pre);
	strcat(label, number);
	if((elem = (CodeElem *)calloc(1, sizeof(CodeElem))) == NULL) memoryError();
	elem->desc = C_LABEL;
	if((elem->label = (char *)calloc(16, sizeof(char))) == NULL) memoryError();
	elem->label = label;
	elem->loc = realloc(elem->loc, 3 * sizeof(Location));
	if((loc = (Location *)calloc(1, sizeof(Location))) == NULL) memoryError();
	loc->elem = elem;
	loc->region = codeRegion;
	loc->offset = 0;
	elem->loc[0] = loc;
	if((intrCode = (IntrCode *)calloc(1, sizeof(IntrCode))) == NULL) memoryError();
	intrCode->elem = elem;
	intrCode->next = NULL;
	return intrCode;
}

CodeElem *createCodeElement(){
	int i;
	CodeElem *elem;
	Location *NullLoc;
	if((NullLoc = (Location *)calloc(1, sizeof(Location))) == NULL) memoryError();
	NullLoc->val = "__NULL_";
	if((elem = (CodeElem *)calloc(1, sizeof(CodeElem))) == NULL) memoryError();
	if((elem->loc = realloc(elem->loc, 3 * sizeof(Location))) == NULL) memoryError();
	for(i = 0; i < 3; i++)
		elem->loc[i] = NullLoc;
	return elem;
}

IntrCode *createIntrCode(){
	IntrCode *intrCode;
	if((intrCode = (IntrCode *)calloc(1, sizeof(IntrCode))) == NULL) memoryError();
	CodeElem *elem = createCodeElement();
	intrCode->elem = elem;
	return intrCode;
}

Location *makeLocation(NType *source){
	Location *location;	
	NType *temp;
	temp = (NType *)getSymbolFromTable(source->symbTable, source);
	if(temp != NULL) source = temp;
	if((location = (Location *)calloc(1, sizeof(Location))) == NULL) memoryError();
	location->region = source->symbTable->scope;
	location->offset = source->offset;
	location->val = source->val;
	return location;
}

IntrCode *makePairedExpression(int code, NType *child1, NType *child2, int mode){
	NType *tempSymb;
	IntrCode *icode = createIntrCode();
	CodeElem *codeElem = createCodeElement();	
	tempSymb = (NType *)createTempSymbol(child2, T_TEMP, mode);
	icode->elem->desc = code;
	icode->elem->label = tempSymb->label;
	icode->elem->loc[0] = makeLocation(tempSymb);
	icode->elem->loc[0]->elem = codeElem;
	icode->elem->loc[1] = makeLocation(child1);
	icode->elem->loc[2] = makeLocation(child2);
	icode = createIntrCode();
	return icode;
}

IntrCode *concatCode(IntrCode *front, IntrCode *back){
	IntrCode *icode;
	IntrCode *current;
	IntrCode *tail;
	IntrCode *returnCode;
	
	current = front;
	if((returnCode = (IntrCode *)calloc(1, sizeof(IntrCode))) == NULL) memoryError();
	while(current != NULL){
		if((icode = (IntrCode *)calloc(1, sizeof(IntrCode))) == NULL) memoryError();
		icode->elem = current->elem;
		if(returnCode->elem == NULL) {
			returnCode = icode;
			tail = returnCode;
		} else {
			tail->next = icode;
			tail = icode;
		}
		current = current->next;
	}
	tail->next = back;
	return returnCode;
}

void setBreaksAndContinues(IntrCode *intCode, IntrCode *brk, IntrCode *cont){
	if(SHOW_CODE)printf("setBreaksAndContinues\n");
	intCode->elem->loc[0]->elem = createCodeElement();
	while(intCode != NULL){
		if(intCode->elem->loc[0]->val == "__NULL_"){
			if(strcmp(intCode->elem->label, "BREAK") == 0){
				intCode->elem->loc[0] = brk->elem->loc[0];
				intCode->elem->loc[0]->elem = brk->elem;
				intCode->elem->loc[0]->elem->label = brk->elem->label;
				intCode->elem->loc[0]->val = brk->elem->label;
			}
			if(strcmp(intCode->elem->label, "CONTINUE") == 0){
				intCode->elem->loc[0] = cont->elem->loc[0];
				intCode->elem->loc[0]->elem = cont->elem;
				intCode->elem->loc[0]->elem->label = cont->elem->label;
				intCode->elem->loc[0]->val = cont->elem->label;
			}
		}
		intCode = intCode->next;
	}
}

void intermediateCodeGeneration(TreeNode *node){
	IntrCode *icode;
	IntrCode *label1;
	IntrCode *label2;
	IntrCode *label3;
	IntrCode *current;
	NType *temp;
	Location *location;
	Location *NullLoc;
	CodeElem *codeElem;
	SymbolTable *thisSymbolTable;
	SymbolListItem *currentListItem;
	int mode = M_CODEGEN;
	if((NullLoc = (Location *)calloc(1, sizeof(Location))) == NULL) memoryError();
	NullLoc->val = "__NULL_";
	if(node != NULL){
		//recursion
		int n;
		for(n = 0; n < node->u.n.children; n++){
			intermediateCodeGeneration(node->u.n.child[n]);
		}
		switch(node->u.n.rule) {
			case TRANSLATION_UNITr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				icode = createIntrCode();
				icode->elem->desc = C_DSTRING;
				icode->elem->label = ".string";
				node->intCode = icode;
				//get strings
				currentListItem = stringTable->list->head;
				while(currentListItem != NULL){
					icode = createIntrCode();
					icode->elem->desc = C_STR_LIT;
					icode->elem->label = currentListItem->item->label;
					node->intCode = concatCode(node->intCode, icode);
					currentListItem = currentListItem->next;
				}
				icode = createIntrCode();
				icode->elem->desc = C_DCODE;
				icode->elem->label = ".code";
				node->intCode = concatCode(node->intCode, icode);
				node->intCode = concatCode(node->intCode, node->u.n.child[0]->intCode);
				break;
				
			case TYPEDEF_NAMEr1 :
			case NAMESPACE_NAMEr1 :
			case ORIGINAL_NAMESPACE_NAMEr1 :
			case CLASS_NAMEr1 :
			case ENUM_NAMEr1 :
			case IDENTIFIERr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				break;
				
			case LITERALr1 :	
			case LITERALr2 :	
			case LITERALr3 :	
			case LITERALr4 :	
			case LITERALr5 :
			case INTEGER_LITERALr1 :
			case CHARACTER_LITERALr1 :
			case FLOATING_LITERALr1 :
			case STRING_LITERALr1 :
			case BOOLEAN_LITERALr1 :
			case BOOLEAN_LITERALr2 :
			case PRIMARY_EXPRESSIONr1 :
			case PRIMARY_EXPRESSIONr2 :
			case PRIMARY_EXPRESSIONr3 :
			case PRIMARY_EXPRESSIONr4 :
			case ID_EXPRESSIONr1 :
			case ID_EXPRESSIONr2 :
			case UNQUALIFIED_IDr1 :
			case UNQUALIFIED_IDr2 :
			case UNQUALIFIED_IDr3 :
			case UNQUALIFIED_IDr4 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				break;
				
			case QUALIFIED_IDr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0]->intCode != NULL) {
					node->intCode = node->u.n.child[0]->intCode;
					if(node->u.n.child[1]->intCode != NULL)node->intCode = concatCode(node->intCode, node->u.n.child[1]->intCode);
				}
				else if(node->u.n.child[1]->intCode != NULL) node->intCode = node->u.n.child[1]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case QUALIFIED_IDr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				break;
				
			case NESTED_NAME_SPECIFIERr1 :
			case NESTED_NAME_SPECIFIERr2 :
			case NESTED_NAME_SPECIFIERr3 :
			case NESTED_NAME_SPECIFIERr4 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				break;
	
/*
nested_name_specifier:
	class_name COLONCOLON nested_name_specifier				{ $$ = (TreeNode *)alacnary(NESTED_NAME_SPECIFIERr1, 3, $1, $2, $3); }
	| namespace_name COLONCOLON nested_name_specifier		{ $$ = (TreeNode *)alacnary(NESTED_NAME_SPECIFIERr2, 3, $1, $2, $3); }
	| class_name COLONCOLON											{ $$ = (TreeNode *)alacnary(NESTED_NAME_SPECIFIERr3, 2, $1, $2); }
	| namespace_name COLONCOLON									{ $$ = (TreeNode *)alacnary(NESTED_NAME_SPECIFIERr4, 2, $1, $2); }
	;*/
			case POSTFIX_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
				
			case POSTFIX_EXPRESSIONr12 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0]->intCode != NULL)node->intCode = node->u.n.child[0]->intCode;
				icode = (IntrCode *)createIntrCode();
				icode->elem->label = "Add1";
				icode->elem->desc = C_ADD1;
				if(node->u.n.child[0]->intCode == NULL){
					temp = getSymbolFromTable(node->type->symbTable, node->type);
					icode->elem->loc[0] = makeLocation(temp);
					icode->elem->loc[1] = makeLocation(temp);
				} else {
					icode->elem->loc[0] = node->u.n.child[0]->intCode->elem->loc[0];
					icode->elem->loc[1] = node->u.n.child[0]->intCode->elem->loc[0];
				}
				if(node->intCode != NULL) node->intCode = concatCode(node->intCode, icode);
				else node->intCode = icode;
				if(SHOW_CODE)printCode(node);
				break;
/*
	
postfix_expression:
	primary_expression												{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr1, 1, $1); }
	| postfix_expression '[' expression ']'					{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr2, 2, $1, $3); }
	| postfix_expression '(' expression_list_opt ')'		{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr3, 2, $1, $3); }
	| postfix_expression '.' TEMPLATE COLONCOLON id_expression
																			{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL;
																			/*$$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr4, 3, $1, $3, $4); }
	| postfix_expression '.' TEMPLATE id_expression			{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL;
																			/*$$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr5, 3, $1, $3, $4); }
	| postfix_expression '.' COLONCOLON id_expression		{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr6, 3, $1, $3, $4); }
	| postfix_expression '.' id_expression						{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr7, 2, $1, $3); }
	| postfix_expression ARROW TEMPLATE COLONCOLON id_expression
																			{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL;
																			/*$$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr8, 5, $1, $2, $3, $4, $5);}
	| postfix_expression ARROW TEMPLATE id_expression		{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL;
																			/*$$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr9, 4, $1, $2, $3, $4); }
	| postfix_expression ARROW COLONCOLON id_expression	{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr10, 4, $1, $2, $3, $4); }
	| postfix_expression ARROW id_expression					{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr11, 3, $1, $2, $3); }
	| postfix_expression PLUSPLUS									{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr12, 2, $1, $2); }
	| postfix_expression MINUSMINUS								{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr13, 2, $1, $2); }
	| DYNAMIC_CAST '<' type_id '>' '(' expression ')'		{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr14, 3, $1, $3, $6); }
	| STATIC_CAST '<' type_id '>' '(' expression ')'		{ exitStatus = 2;
																				getErrorMessage(ER_STATIC);
																				yyerror(NULL);
																				$$ = NULL;
																			/* $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr15, 3, $1, $3, $6); }
	| REINTERPRET_CAST '<' type_id '>' '(' expression ')'	{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr16, 3, $1, $3, $6); }
	| CONST_CAST '<' type_id '>' '(' expression ')'			{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr17, 3, $1, $3, $6); }
	| TYPEID '(' expression ')'									{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr18, 2, $1, $3); }
	| TYPEID '(' type_id ')'										{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr19, 2, $1, $3); }
	;*/
	
			case EXPRESSION_LISTr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case EXPRESSION_LISTr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0]->intCode != NULL) {
					node->intCode = node->u.n.child[0]->intCode;
					if(node->u.n.child[1]->intCode != NULL)node->intCode = concatCode(node->intCode, node->u.n.child[1]->intCode);
				}
				else if(node->u.n.child[1]->intCode != NULL) node->intCode = node->u.n.child[1]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			
			case UNARY_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
	/*

unary_expression:
	postfix_expression												{ $$ = (TreeNode *)alacnary(UNARY_EXPRESSIONr1, 1, $1); }
	| PLUSPLUS cast_expression										{ $$ = (TreeNode *)alacnary(UNARY_EXPRESSIONr2, 2, $1, $2); }
	| MINUSMINUS cast_expression									{ $$ = (TreeNode *)alacnary(UNARY_EXPRESSIONr3, 2, $1, $2); }
	| '*' cast_expression											{ $$ = (TreeNode *)alacnary(UNARY_EXPRESSIONr4, 1, $2); }
	| '&' cast_expression											{ $$ = (TreeNode *)alacnary(UNARY_EXPRESSIONr5, 1, $2); }
	| unary_operator cast_expression								{ $$ = (TreeNode *)alacnary(UNARY_EXPRESSIONr6, 2, $1, $2); }
	| SIZEOF unary_expression										{ $$ = (TreeNode *)alacnary(UNARY_EXPRESSIONr7, 2, $1, $2); }
	| SIZEOF '(' type_id ')'										{ $$ = (TreeNode *)alacnary(UNARY_EXPRESSIONr8, 2, $1, $3); }
	| new_expression													{ $$ = (TreeNode *)alacnary(UNARY_EXPRESSIONr9, 1, $1); }
	| delete_expression												{ $$ = (TreeNode *)alacnary(UNARY_EXPRESSIONr10, 1, $1); }
	;

unary_operator:
	  '+'																	{ $$ = (TreeNode *)alacnary(UNARY_OPERATORr1, 0); }
	| '-'																	{ $$ = (TreeNode *)alacnary(UNARY_OPERATORr2, 0); }
	| '!'																	{ $$ = (TreeNode *)alacnary(UNARY_OPERATORr3, 0); }
	| '~'																	{ $$ = (TreeNode *)alacnary(UNARY_OPERATORr4, 0); }
	;

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
	;*/
			case CAST_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				break;
			case CAST_EXPRESSIONr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				break;
	
/*	
cast_expression:
	unary_expression													{ $$ = (TreeNode *)alacnary(CAST_EXPRESSIONr1, 1, $1); }
	| '(' type_id ')' cast_expression							{ $$ = (TreeNode *)alacnary(CAST_EXPRESSIONr2, 2, $2, $4); }
	;*/
	
			case PM_EXPRESSIONr1 :
			case PM_EXPRESSIONr2 :
			case PM_EXPRESSIONr3 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				break;
	
/*
pm_expression:
	cast_expression													{ $$ = (TreeNode *)alacnary(PM_EXPRESSIONr1, 1, $1); }
	| pm_expression DOTSTAR cast_expression					{ $$ = (TreeNode *)alacnary(PM_EXPRESSIONr2, 3, $1, $2, $3); }
	| pm_expression ARROWSTAR cast_expression					{ $$ =(TreeNode *)alacnary(PM_EXPRESSIONr3, 3, $1, $2, $3); }
	;*/
			case MULTIPLICATIVE_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				break;
			case MULTIPLICATIVE_EXPRESSIONr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				node->intCode = makePairedExpression(C_MULT, node->u.n.child[0]->type, node->u.n.child[1]->type, mode);
				if(SHOW_CODE)printCode(node);
				break;
			case MULTIPLICATIVE_EXPRESSIONr3 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				node->intCode = makePairedExpression(C_DIV, node->u.n.child[0]->type, node->u.n.child[1]->type, mode);
				if(SHOW_CODE)printCode(node);
				break;
			case MULTIPLICATIVE_EXPRESSIONr4 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				node->intCode = makePairedExpression(C_MOD, node->u.n.child[0]->type, node->u.n.child[1]->type, mode);
				if(SHOW_CODE)printCode(node);
				break;
				
			case ADDITIVE_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				break;
			case ADDITIVE_EXPRESSIONr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				node->intCode = makePairedExpression(C_ADD, node->u.n.child[0]->type, node->u.n.child[1]->type, mode);
				if(SHOW_CODE)printCode(node);
				break;
			case ADDITIVE_EXPRESSIONr3 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				node->intCode = makePairedExpression(C_SUB, node->u.n.child[0]->type, node->u.n.child[1]->type, mode);
				if(SHOW_CODE)printCode(node);
				break;
				
			case SHIFT_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				break;
			case SHIFT_EXPRESSIONr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				/* ?????????????????*/
				break;
			case SHIFT_EXPRESSIONr3 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				/* ?????????????????*/
				break;
/*
shift_expression:
	additive_expression												{ $$ = (TreeNode *)alacnary(SHIFT_EXPRESSIONr1, 1, $1); }
	| shift_expression SL additive_expression					{ $$ = (TreeNode *)alacnary(SHIFT_EXPRESSIONr2, 3, $1, $2, $3); }
	| shift_expression SR additive_expression					{ $$ = (TreeNode *)alacnary(SHIFT_EXPRESSIONr3, 3, $1, $2, $3); }
	;*/
	
			case RELATIONAL_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case RELATIONAL_EXPRESSIONr2 :
				node->intCode = (IntrCode *)createIntrCode();
				temp = (NType *)createTempSymbol(node->type, T_TEMP, mode);
				node->intCode->elem->desc = C_LT;
				node->intCode->elem->label = "<";
				node->intCode->elem->loc[0] = makeLocation(temp);
				node->intCode->elem->loc[0]->elem = node->intCode->elem;
				node->place = node->intCode->elem->loc[0];
				node->intCode->elem->loc[1] = makeLocation(node->u.n.child[0]->type);
				node->intCode->elem->loc[2] = makeLocation(node->u.n.child[1]->type);
				node->type->label = "<";
				if(SHOW_CODE)printCode(node);
				break;
			case RELATIONAL_EXPRESSIONr3 :
				node->intCode = (IntrCode *)createIntrCode();
				temp = (NType *)createTempSymbol(node->type, T_TEMP, mode);
				node->intCode->elem->desc = C_GT;
				node->intCode->elem->label = ">";
				node->intCode->elem->loc[0] = makeLocation(temp);
				node->intCode->elem->loc[0]->elem = node->intCode->elem;
				node->place = node->intCode->elem->loc[0];
				node->intCode->elem->loc[1] = makeLocation(node->u.n.child[0]->type);
				node->intCode->elem->loc[2] = makeLocation(node->u.n.child[1]->type);
				node->type->label = ">";
				if(SHOW_CODE)printCode(node);
				break;
			case RELATIONAL_EXPRESSIONr4 :	
				node->intCode = (IntrCode *)createIntrCode();
				temp = (NType *)createTempSymbol(node->type, T_TEMP, mode);
				node->intCode->elem->desc = C_LTEQ;
				node->intCode->elem->label = "<=";
				node->intCode->elem->loc[0] = makeLocation(temp);
				node->intCode->elem->loc[0]->elem = node->intCode->elem;
				node->place = node->intCode->elem->loc[0];
				node->intCode->elem->loc[1] = makeLocation(node->u.n.child[0]->type);
				node->intCode->elem->loc[2] = makeLocation(node->u.n.child[2]->type);
				node->type->label = "<=";
				if(SHOW_CODE)printCode(node);
				break;
			case RELATIONAL_EXPRESSIONr5 :
				node->intCode = (IntrCode *)createIntrCode();
				temp = (NType *)createTempSymbol(node->type, T_TEMP, mode);
				node->intCode->elem->desc = C_GTEQ;
				node->intCode->elem->label = ">=";
				node->intCode->elem->loc[0] = makeLocation(temp);
				node->intCode->elem->loc[0]->elem = node->intCode->elem;
				node->place = node->intCode->elem->loc[0];
				node->intCode->elem->loc[1] = makeLocation(node->u.n.child[0]->type);
				node->intCode->elem->loc[2] = makeLocation(node->u.n.child[2]->type);
				node->type->label = ">=";
				if(SHOW_CODE)printCode(node);
				break;
				
			case EQUALITY_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case EQUALITY_EXPRESSIONr2 :
				node->intCode = (IntrCode *)createIntrCode();
				temp = (NType *)createTempSymbol(node->type, T_TEMP, mode);
				node->intCode->elem->desc = C_EQ;
				node->intCode->elem->label = "==";
				node->intCode->elem->loc[0] = makeLocation(temp);
				node->intCode->elem->loc[0]->elem = node->intCode->elem;
				node->place = node->intCode->elem->loc[0];
				node->intCode->elem->loc[1] = makeLocation(node->u.n.child[0]->type);
				node->intCode->elem->loc[2] = makeLocation(node->u.n.child[2]->type);
				node->type->label = "==";
				if(SHOW_CODE)printCode(node);
				if(SHOW_MEMMORY)printf("%s:%d\n", node->place->region->label, node->place->offset);
				break;
			case EQUALITY_EXPRESSIONr3 :
				node->intCode = (IntrCode *)createIntrCode();
				temp = (NType *)createTempSymbol(node->type, T_TEMP, mode);
				node->intCode->elem->desc = C_NOTEQ;
				node->intCode->elem->label = "!=";
				node->intCode->elem->loc[0] = makeLocation(temp);
				node->intCode->elem->loc[0]->elem = node->intCode->elem;
				node->place = node->intCode->elem->loc[0];
				node->intCode->elem->loc[1] = makeLocation(node->u.n.child[0]->type);
				node->intCode->elem->loc[2] = makeLocation(node->u.n.child[2]->type);
				node->type->label = "!=";
				if(SHOW_CODE)printCode(node);
				break;
				
			case AND_EXPRESSIONr1 :
				printf("%s\n", humanreadable(node->u.n.rule));
				if(SHOW_MEMMORY)if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case AND_EXPRESSIONr2 :
				node->intCode = (IntrCode *)createIntrCode();
				temp = (NType *)createTempSymbol(node->type, T_TEMP, mode);
				node->intCode->elem->desc = C_AND;
				node->intCode->elem->label = "&";
				node->intCode->elem->loc[0] = makeLocation(temp);
				node->intCode->elem->loc[0]->elem = node->intCode->elem;
				node->place = node->intCode->elem->loc[0];
				node->intCode->elem->loc[1] = makeLocation(node->u.n.child[0]->type);
				node->intCode->elem->loc[2] = makeLocation(node->u.n.child[1]->type);
				node->type->label = "&";
				if(SHOW_CODE)printCode(node);
				break;
				
			case EXCLUSIVE_OR_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case EXCLUSIVE_OR_EXPRESSIONr2 :
				node->intCode = (IntrCode *)createIntrCode();
				temp = (NType *)createTempSymbol(node->type, T_TEMP, mode);
				node->intCode->elem->desc = C_EXOR;
				node->intCode->elem->label = "^";
				node->intCode->elem->loc[0] = makeLocation(temp);
				node->intCode->elem->loc[0]->elem = node->intCode->elem;
				node->place = node->intCode->elem->loc[0];
				node->intCode->elem->loc[1] = makeLocation(node->u.n.child[0]->type);
				node->intCode->elem->loc[2] = makeLocation(node->u.n.child[1]->type);
				node->type->label = "^";
				printCode(node);
				break;
				
			case INCLUSIVE_OR_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case INCLUSIVE_OR_EXPRESSIONr2 :
				node->intCode = (IntrCode *)createIntrCode();
				temp = (NType *)createTempSymbol(node->type, T_TEMP, mode);
				node->intCode->elem->desc = C_INOR;
				node->intCode->elem->label = "|";
				node->intCode->elem->loc[0] = makeLocation(temp);
				node->intCode->elem->loc[0]->elem = node->intCode->elem;
				node->place = node->intCode->elem->loc[0];
				node->intCode->elem->loc[1] = makeLocation(node->u.n.child[0]->type);
				node->intCode->elem->loc[2] = makeLocation(node->u.n.child[1]->type);
				node->type->label = "|";
				if(SHOW_CODE)printCode(node);
				break;
				
			case LOGICAL_AND_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case LOGICAL_AND_EXPRESSIONr2 :
				node->intCode = (IntrCode *)createIntrCode();
				temp = (NType *)createTempSymbol(node->type, T_TEMP, mode);
				node->intCode->elem->desc = C_ANDAND;
				node->intCode->elem->label = "&&";
				node->intCode->elem->loc[0] = makeLocation(temp);
				node->intCode->elem->loc[0]->elem = node->intCode->elem;
				node->place = node->intCode->elem->loc[0];
				node->intCode->elem->loc[1] = makeLocation(node->u.n.child[0]->type);
				node->intCode->elem->loc[2] = makeLocation(node->u.n.child[2]->type);
				node->type->label = "&&";
				if(SHOW_CODE)printCode(node);
				break;
			case LOGICAL_OR_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case LOGICAL_OR_EXPRESSIONr2 :
				node->intCode = (IntrCode *)createIntrCode();
				temp = (NType *)createTempSymbol(node->type, T_TEMP, mode);
				node->intCode->elem->desc = C_OROR;
				node->intCode->elem->label = "||";
				node->intCode->elem->loc[0] = makeLocation(temp);
				node->intCode->elem->loc[0]->elem = node->intCode->elem;
				node->place = node->intCode->elem->loc[0];
				node->intCode->elem->loc[1] = makeLocation(node->u.n.child[0]->type);
				node->intCode->elem->loc[2] = makeLocation(node->u.n.child[2]->type);
				node->type->label = "||";
				if(SHOW_CODE)printCode(node);
				break;
			
			case CONDITIONAL_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;

			case ASSIGNMENT_EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case ASSIGNMENT_EXPRESSIONr2 :
			case ASSIGNMENT_EXPRESSIONr3 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
	
	/*
assignment_expression:
	conditional_expression											{ $$ = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSIONr1, 1, $1); }
	| logical_or_expression assignment_operator assignment_expression
																			{ $$ = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSIONr2, 3, $1, $2, $3); }
	| throw_expression												{ $$ = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSIONr3, 1, $1); }
	;

assignment_operator:
	'='																	{ $$ = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr1, 0); }
	| MULEQ																{ $$ = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr2, 1, $1); }
	| DIVEQ																{ $$ = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr3, 1, $1); }
	| MODEQ																{ $$ = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr4, 1, $1); }
	| ADDEQ																{ $$ = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr5, 1, $1); }
	| SUBEQ																{ $$ = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr6, 1, $1); }
	| SREQ																{ $$ = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr7, 1, $1); }
	| SLEQ																{ $$ = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr8, 1, $1); }
	| ANDEQ																{ $$ = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr9, 1, $1); }
	| XOREQ																{ $$ = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr10, 1, $1); }
	| OREQ																{ $$ = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr11, 1, $1); }
	;*/
			case EXPRESSIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
/*

expression:
	assignment_expression											{ $$ = (TreeNode *)alacnary(EXPRESSIONr1, 1, $1); }
	| expression ',' assignment_expression						{ $$ = (TreeNode *)alacnary(EXPRESSIONr2, 2, $1, $3); }
	;

constant_expression:
	conditional_expression											{ $$ = (TreeNode *)alacnary(CONSTANT_EXPRESSIONr1, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Statements.
 *----------------------------------------------------------------------*/

			case STATEMENTr1 :
			case STATEMENTr2 :
			case STATEMENTr3 :
			case STATEMENTr4 :
			case STATEMENTr5 :
			case STATEMENTr6 :
			case STATEMENTr7 :
			case STATEMENTr8 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			
 /*
labeled_statement:
	identifier ':' statement										{ $$ = (TreeNode *)alacnary(LABELED_STATEMENTr1, 2, $1, $3); }
	| CASE constant_expression ':' statement					{ $$ = (TreeNode *)alacnary(LABELED_STATEMENTr2, 3, $1, $2, $4); }
	| DEFAULT ':' statement											{ $$ = (TreeNode *)alacnary(LABELED_STATEMENTr3, 2, $1, $3); }
	;
*/
			case EXPRESSION_STATEMENTr1 :
			case COMPOUND_STATEMENTr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;

			case STATEMENT_SEQr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL) node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case STATEMENT_SEQr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0]->intCode != NULL) {
					node->intCode = node->u.n.child[0]->intCode;
					if(node->u.n.child[1]->intCode != NULL)node->intCode = concatCode(node->intCode, node->u.n.child[1]->intCode);
				}
				else if(node->u.n.child[1]->intCode != NULL) node->intCode = node->u.n.child[1]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
				
			case SELECTION_STATEMENTr1 :

				/*
				 *				test
				 *				NOT test
				 *				BR Label1 !boolTestResult
				 *					code
				 *	Label1
				 */
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				node->intCode = node->u.n.child[1]->intCode;
				//make labels
				label1 = makeLabel();
				//make NOT
				icode = createIntrCode();		
				icode->elem->desc = C_NOT;
				icode->elem->loc[0] = node->u.n.child[1]->intCode->elem->loc[0];
				icode->elem->loc[1] = node->u.n.child[1]->intCode->elem->loc[0];
				node->intCode = concatCode(node->intCode, icode);
				//make BR 
				icode = createIntrCode();		
				icode->elem->desc = C_BR;
				icode->elem->label = "Branch";
			   icode->elem->loc[0] = label1->elem->loc[0];
				icode->elem->loc[0]->elem = label1->elem;
				icode->elem->loc[1] = node->u.n.child[1]->intCode->elem->loc[0];
				node->intCode = concatCode(node->intCode, icode);
					/* child[1]|BR|..*/
				node->intCode = concatCode(node->intCode, node->u.n.child[2]->intCode);
					/* child[1]|BR|child[2]|..*/
				
				current = node->intCode;
				while(current->next != NULL) current = current->next;
				current->next = label1;	
					/* child[1]|BR|child[2]|Label1*/
				if(SHOW_CODE)printCode(node);
				break;
			case SELECTION_STATEMENTr2 :
				/*
				 *				test
				 *				NOT test
				 *				BR Label1 test
				 *					code
				 *				GOTO Label2
				 *	Label1
				 *					elseCode
				 *	Label2
				 */
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				node->intCode = node->u.n.child[1]->intCode;
				//make labels
				label1 = makeLabel();
				label2 = makeLabel();
				//make NOT
				icode = createIntrCode();		
				icode->elem->desc = C_NOT;
				icode->elem->loc[0] = node->u.n.child[1]->intCode->elem->loc[0];
				icode->elem->loc[1] = node->u.n.child[1]->intCode->elem->loc[0];
				node->intCode = concatCode(node->intCode, icode);
				//make BR 
				icode = createIntrCode();		
				icode->elem->desc = C_BR;
				icode->elem->label = "Branch";
			   icode->elem->loc[0] = label1->elem->loc[0];
				icode->elem->loc[0]->elem = label1->elem;
				icode->elem->loc[1] = node->u.n.child[1]->intCode->elem->loc[0];
				node->intCode = concatCode(node->intCode, icode);
					/* child[1]|BR|..*/
				node->intCode = concatCode(node->intCode, node->u.n.child[2]->intCode);
					/* child[1]|BR|child[2]|..*/
				//make GOTO
				icode = createIntrCode();		
				icode->elem->desc = C_GOTO;
				icode->elem->label = "Goto";
				icode->elem->loc[0] = label2->elem->loc[0];
				icode->elem->loc[0]->elem = label2->elem;
				icode->elem->loc[0]->val = "GOTO";
				node->intCode = concatCode(node->intCode, icode);
					/* child[1]|BR|child[2]|GOTO|..*/
				current = node->intCode;
				while(current->next != NULL) current = current->next;
				current->next = label1;	
					/* child[1]|BR|child[2]|GOTO|Label1|..*/
				current = current->next;
				current->next = node->u.n.child[4]->intCode;
					/* child[1]|BR|child[2]|GOTO|Label1|child[4]..*/
				node->intCode = concatCode(node->intCode, label2);
					/* child[1]|BR|child[2]|GOTO|Label1|child[4]|Label2*/
				current->next = label2;
				if(SHOW_CODE)printCode(node);
				break;
				
			case SELECTION_STATEMENTr3 :
				/*
				 *	???????????
				 */
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				
				if(SHOW_CODE)printCode(node);
				break;
			
/*
selection_statement:

	| SWITCH '(' condition ')' statement						{ $$ = (TreeNode *)alacnary(SELECTION_STATEMENTr3, 3, $1, $3, $5); }
	;*/
			case CONDITIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
/*
condition:
	expression															{ $$ = (TreeNode *)alacnary(CONDITIONr1, 1, $1); }
	| type_specifier_seq declarator '=' assignment_expression
																			{ $$ = (TreeNode *)alacnary(CONDITIONr2, 3, $1, $2, $4); }
	;*/
			case ITERATION_STATEMENTr1 :
				/*
				 *				GOTO Label2
				 *	Label1
				 *				code(child[2])
				 * Label2
				 *				test(child[1])
				 *				BR Label 1
				 * Label3
				 */
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				//make labels
				label1 = makeLabel();
				label2 = makeLabel();
				label3 = makeLabel();
				//make GOTO
				icode = createIntrCode();		
				icode->elem->desc = C_GOTO;
				icode->elem->label = "Goto";
				icode->elem->loc[0] = label2->elem->loc[0];
				icode->elem->loc[0]->elem = label2->elem;
				icode->elem->loc[0]->val = "GOTO";
				node->intCode = icode;
					/* GOTO|..*/
				node->intCode = concatCode(node->intCode, label1);
					/* GOTO|Label1|..*/
				setBreaksAndContinues(node->u.n.child[2]->intCode, label3, label2);
				node->intCode = concatCode(node->intCode, node->u.n.child[2]->intCode);
					/* GOTO|Label1|child[2]..*/
				node->intCode = concatCode(node->intCode, label2);
					/* Label1|child[2]|Label2|..*/
				node->intCode = concatCode(node->intCode, node->u.n.child[1]->intCode);
					/* Label1|child[2]|Label2|child[1]..*/
				//temporary symbol	
				temp = node->u.n.child[1]->type;
				icode = createIntrCode();		
				icode->elem->desc = C_BR;
				icode->elem->label = "Branch";
			   icode->elem->loc[0] = makeLocation(temp);
				icode->elem->loc[0]->elem = label1->elem;
				icode->elem->loc[1] = node->u.n.child[1]->intCode->elem->loc[0];
				node->intCode = concatCode(node->intCode, icode);
					/* GOTO|Label1|child[2]|Label2|child[1]|BR| */
				node->intCode = concatCode(node->intCode, label3);
					/* GOTO|Label1|child[2]|Label2|child[1]|BR|Label3 */
				if(SHOW_CODE)printCode(node);
				break;
			case ITERATION_STATEMENTr2 :
				/*
				 *	Label1
				 *				code (child1)
				 * Label2
				 *				test (child3)
				 *				BR Label 1
				 * Label3
				 */
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				//make labels
				label1 = makeLabel();
				label2 = makeLabel();
				label3 = makeLabel();
	
				node->intCode = label1;
					/* Label1|..*/
				setBreaksAndContinues(node->u.n.child[1]->intCode, label3, label2);
				node->intCode = concatCode(node->intCode, node->u.n.child[1]->intCode);
					/* Label1|child[1]..*/
				node->intCode = concatCode(node->intCode, label2);
					/* Label1|child[1]|Label2|..*/
				node->intCode = concatCode(node->intCode, node->u.n.child[3]->intCode);
					/* Label1|child[1]|Label2|child[3]..*/
				//temporary symbol	
				temp = node->u.n.child[3]->type;
					/* Label1|child[1]|Label2|child[3]|..*/
				icode = createIntrCode();		
				icode->elem->desc = C_BR;
				icode->elem->label = "Branch";
			   icode->elem->loc[0] = makeLocation(temp);
				icode->elem->loc[0]->elem = label1->elem;
				icode->elem->loc[1] = node->u.n.child[3]->intCode->elem->loc[0];
				node->intCode = concatCode(node->intCode, icode);
					/* Label1|child[1]|Label2|child[3]|BR| */
				node->intCode = concatCode(node->intCode, label3);
					/* Label1|child[1]|Label2|child[3]|BR|Label3 */
				if(SHOW_CODE)printCode(node);
				break;
			case ITERATION_STATEMENTr3 :
				/*
				 *				child[1]
				 *				GOTO Label2
				 * Label1
				 *				child[3]
				 *				code (child[4])
				 * Label2
				 *				test (child[2])
				 *				BR Label 1
				 * Label3
				 */
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				//make labels
				label1 = makeLabel();
				label2 = makeLabel();
				label3 = makeLabel();
				
				node->intCode = node->u.n.child[1]->intCode;
					/* child[1] */
				//make GOTO
				icode = createIntrCode();		
				icode->elem->desc = C_GOTO;
				icode->elem->label = "Goto";
				icode->elem->loc[0] = label2->elem->loc[0];
				icode->elem->loc[0]->elem = label2->elem;
				icode->elem->loc[0]->val = "GOTO";
				node->intCode = concatCode(node->intCode, icode);
					/* child[1]|GOTO */
				node->intCode = concatCode(node->intCode, label1);
					/* child[1]|GOTO|Label1 */
				node->intCode = concatCode(node->intCode, node->u.n.child[3]->intCode);
					/* child[1]|GOTO|Label1|child[3] */
				setBreaksAndContinues(node->u.n.child[4]->intCode, label3, label2);	
				node->intCode = concatCode(node->intCode, node->u.n.child[4]->intCode);
					/* child[1]|GOTO|Label1|child[3]|child[4] */
				node->intCode = concatCode(node->intCode, label2);
					/* child[1]|GOTO|Label1|child[3]|child[4]|Label2 */
				node->intCode = concatCode(node->intCode, node->u.n.child[2]->intCode);
					/* child[1]|GOTO|Label1|child[3]|child[4]|label2|child[2] */
				temp = node->u.n.child[2]->type;
				//temp = (NType *)createTempSymbol(node->u.n.child[2]->type, T_TEMP, mode);
				icode = createIntrCode();		
				icode->elem->desc = C_BR;
				icode->elem->label = "Branch";
			   icode->elem->loc[0] = makeLocation(temp);
				icode->elem->loc[0]->elem = label1->elem;
				icode->elem->loc[1] = node->u.n.child[2]->intCode->elem->loc[0];
				node->intCode = concatCode(node->intCode, icode);
					/* child[1]|GOTO|Label1|child[3]|child[4]|label2|child[2]|BR */
				node->intCode = concatCode(node->intCode, label3);
					/* child[1]|GOTO|Label1|child[3]|child[4]|label2|child[2]|BR|Label3 */
				if(SHOW_CODE)printCode(node);
				break;
/*
			
iteration_statement:
	| FOR '(' for_init_statement condition_opt ';' expression_opt ')' statement
																			{ $$ = (TreeNode *)alacnary(ITERATION_STATEMENTr3, 5, $1, $3, $4, $6, $8); }
	;*/
	
			case FOR_INIT_STATEMENTr1 :
			case FOR_INIT_STATEMENTr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
	
			case JUMP_STATEMENTr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				node->intCode = (IntrCode *)createIntrCode();
				node->intCode->elem->desc = C_GOTO;
				node->intCode->elem->label = "BREAK";
				node->intCode->elem->loc[0] = NullLoc;
				node->type->label = "BREAK";
				if(SHOW_CODE)printCode(node);
				break;
			case JUMP_STATEMENTr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				node->intCode = (IntrCode *)createIntrCode();
				node->intCode->elem->desc = C_GOTO;
				node->intCode->elem->label = "CONTINUE";
				node->intCode->elem->loc[0] = NullLoc;
				node->type->label = "CONTINUE";
				if(SHOW_CODE)printCode(node);
				break;
			case JUMP_STATEMENTr3 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				node->intCode = (IntrCode *)createIntrCode();
				node->intCode->elem->desc = C_RET;
				node->intCode->elem->label = "RETURN";
				temp = (NType *)getSymbolFromTable(node->u.n.child[1]->type->symbTable, node->u.n.child[1]->type);
				if((location = (Location *)calloc(1, sizeof(Location))) == NULL) memoryError();
				location->region = temp->symbTable->scope;
				location->offset = temp->offset;
				location->elem = node->intCode->elem;
				node->intCode->elem->loc[0] = location;
				node->place = node->intCode->elem->loc[0];
				node->type->label = "RETURN";
				if(SHOW_CODE)printCode(node);
				break;

			case DECLARATION_STATEMENTr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;

/*----------------------------------------------------------------------
 * Declarations.
 *----------------------------------------------------------------------*/
			case DECLARATION_SEQr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(node->intCode == NULL) node->intCode = node->u.n.child[1]->intCode;
				else node->intCode = concatCode(node->intCode, node->u.n.child[1]->intCode);
				if(SHOW_CODE)printCode(node);
				break;

			case DECLARATION_SEQr1 :
			case DECLARATIONr1 :
			case DECLARATIONr2 :
			case DECLARATIONr4 :
			case DECLARATIONr5 :
			case DECLARATIONr6 :
			case DECLARATIONr7 :
			case BLOCK_DECLARATIONr1 :
			case BLOCK_DECLARATIONr2 :
			case BLOCK_DECLARATIONr3 :
			case BLOCK_DECLARATIONr4 :
			case BLOCK_DECLARATIONr5 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
				
			case SIMPLE_DECLARATIONr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(node->u.n.child[1] != NULL){
					if(node->u.n.child[0]->intCode != NULL) concatCode(node->intCode, node->u.n.child[1]->intCode);
					else node->intCode = node->u.n.child[1]->intCode;
				}
				if(SHOW_CODE)printCode(node);
				break;

			case SIMPLE_DECLARATIONr2 :
			case DECL_SPECIFIERr1 :
			case DECL_SPECIFIERr2 :
			case DECL_SPECIFIERr3 :
			case DECL_SPECIFIERr4 :
			case DECL_SPECIFIERr5 :
			case DECL_SPECIFIER_SEQr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
				
			case DECL_SPECIFIER_SEQr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(node->u.n.child[1] != NULL){
					if(node->u.n.child[0]->intCode != NULL) concatCode(node->intCode, node->u.n.child[1]->intCode);
					else node->intCode = node->u.n.child[1]->intCode;
				}
				if(SHOW_CODE)printCode(node);
				break;
			
			case TYPE_SPECIFIERr1 :
			case TYPE_SPECIFIERr2 :
			case TYPE_SPECIFIERr3 :
			case TYPE_SPECIFIERr4 :
			case TYPE_SPECIFIERr5 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
				
			case SIMPLE_TYPE_SPECIFIERr1 :
			case SIMPLE_TYPE_SPECIFIERr4 :
			case SIMPLE_TYPE_SPECIFIERr5 :
			case SIMPLE_TYPE_SPECIFIERr6 :
			case SIMPLE_TYPE_SPECIFIERr7 :
			case SIMPLE_TYPE_SPECIFIERr8 :
			case SIMPLE_TYPE_SPECIFIERr9 :
			case SIMPLE_TYPE_SPECIFIERr10 :
			case SIMPLE_TYPE_SPECIFIERr11 :
			case SIMPLE_TYPE_SPECIFIERr12 :
			case SIMPLE_TYPE_SPECIFIERr13 :
			case SIMPLE_TYPE_SPECIFIERr14 :
			case SIMPLE_TYPE_SPECIFIERr15 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
	/*
simple_type_specifier:
	| nested_name_specifier type_name							{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr2, 2, $1, $2); }
	| COLONCOLON nested_name_specifier_opt type_name		{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr3, 3, $1, $2, $3); }

	;*/
	
			case TYPE_NAMEr1:
			case TYPE_NAMEr2:
			case TYPE_NAMEr3:
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
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
	| TYPENAME COLONCOLON_opt nested_name_specifier identifier '<' template_argument_list '>'
																			{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL;
																				/*$$ = alacnary(ELABORATED_TYPE_SPECIFIERr7, 5, $1, $2, $3, $4, $6); }
	;

enum_specifier:
	ENUM identifier '{' enumerator_list_opt '}'				{ $$ = (TreeNode *)alacnary(ENUM_SPECIFIERr1, 3, $1, $2, $4); }
	;

enumerator_list:
	enumerator_definition											{ $$ = (TreeNode *)alacnary(ENUMERATOR_LISTr1, 1, $1); }
	| enumerator_list ',' enumerator_definition				{ $$ = (TreeNode *)alacnary(ENUMERATOR_LISTr2, 2, $1, $3); }
	;

enumerator_definition:
	enumerator															{ $$ = (TreeNode *)alacnary(ENUMERATOR_DEFINITIONr1, 1, $1); }
	| enumerator '=' constant_expression						{ $$ = (TreeNode *)alacnary(ENUMERATOR_DEFINITIONr2, 2, $1, $3); }
	;

enumerator:
	identifier															{ $$ = (TreeNode *)alacnary(ENUMERATORr1, 1, $1); }
	;

/*
namespace_name:
	original_namespace_name
	| namespace_alias
	;

original_namespace_name:
	identifier
	;


namespace_definition:
	named_namespace_definition										{ $$ = (TreeNode *)alacnary(NAMESPACE_DEFINITIONr1, 1, $1); }
	| unnamed_namespace_definition								{ $$ = (TreeNode *)alacnary(NAMESPACE_DEFINITIONr2, 1, $1); }
	;

named_namespace_definition:
	original_namespace_definition									{ $$ = (TreeNode *)alacnary(NAMED_NAMESPACE_DEFINITIONr1, 1, $1); }
	| extension_namespace_definition								{ $$ = (TreeNode *)alacnary(NAMED_NAMESPACE_DEFINITIONr2, 1, $1); }
	;

original_namespace_definition:
	NAMESPACE identifier '{' namespace_body '}'				{ $$ = (TreeNode *)alacnary(ORIGINAL_NAMESPACE_DEFINITIONr1, 3, $1, $2, $4); }
	;

extension_namespace_definition:
	NAMESPACE original_namespace_name '{' namespace_body '}'
																			{ $$ = (TreeNode *)alacnary(EXTENSION_NAMESPACE_DEFINITIONr1, 3, $1, $2, $4); }
	;

unnamed_namespace_definition:
	NAMESPACE '{' namespace_body '}'								{ $$ = (TreeNode *)alacnary(UNNAMED_NAMESPACE_DEFINITIONr1, 2, $1, $3); }
	;

namespace_body:
	declaration_seq_opt												{ $$ = (TreeNode *)alacnary(NAMESPACE_BODYr1, 1, $1); }
	;

/*
namespace_alias:
	identifier
	;


namespace_alias_definition:
	NAMESPACE identifier '=' qualified_namespace_specifier ';'
																			{ $$ = (TreeNode *)alacnary(NAMESPACE_ALIAS_DEFINITIONr1, 3, $1, $2, $4); }
	;

qualified_namespace_specifier:
	COLONCOLON nested_name_specifier namespace_name			{ $$ = (TreeNode *)alacnary(QUALIFIED_NAMESPACE_SPECIFIERr1, 3, $1, $2, $3); }
	| COLONCOLON namespace_name									{ $$ = (TreeNode *)alacnary(QUALIFIED_NAMESPACE_SPECIFIERr2, 2, $1, $2); }
	| nested_name_specifier namespace_name						{ $$ = (TreeNode *)alacnary(QUALIFIED_NAMESPACE_SPECIFIERr3, 2, $1, $2); }
	| namespace_name													{ $$ = (TreeNode *)alacnary(QUALIFIED_NAMESPACE_SPECIFIERr4, 1, $1); }
	;

using_declaration:
	USING TYPENAME COLONCOLON nested_name_specifier unqualified_id ';'
																			{ $$ = (TreeNode *)alacnary(USING_DECLARATIONr1, 5, $1, $2, $3, $4, $5); }
	| USING TYPENAME nested_name_specifier unqualified_id ';'
																			{ $$ = (TreeNode *)alacnary(USING_DECLARATIONr2, 4, $1, $2, $3, $4); }
	| USING COLONCOLON nested_name_specifier unqualified_id ';'
																			{ $$ = (TreeNode *)alacnary(USING_DECLARATIONr3, 4, $1, $2, $3, $4); }
	| USING nested_name_specifier unqualified_id ';'		{ $$ = (TreeNode *)alacnary(USING_DECLARATIONr4, 3, $1, $2, $3); }
	| USING COLONCOLON unqualified_id ';'						{ $$ = (TreeNode *)alacnary(USING_DECLARATIONr5, 3, $1, $2, $3); }
	;

using_directive:
	USING NAMESPACE COLONCOLON nested_name_specifier namespace_name ';'
																			{ $$ = (TreeNode *)alacnary(USING_DIRECTIVEr1, 5, $1, $2, $3, $4, $5); }
	| USING NAMESPACE COLONCOLON namespace_name ';'			{ $$ = (TreeNode *)alacnary(USING_DIRECTIVEr2, 4, $1, $2, $3, $4); }
	| USING NAMESPACE nested_name_specifier namespace_name ';'
																			{ $$ = (TreeNode *)alacnary(USING_DIRECTIVEr3, 4, $1, $2, $3, $4); }
	| USING NAMESPACE namespace_name ';'						{ $$ = (TreeNode *)alacnary(USING_DIRECTIVEr4, 3, $1, $2, $3); }
	;

asm_definition:
	ASM '(' string_literal ')' ';'								{ $$ = (TreeNode *)alacnary(ASM_DEFINITIONr1, 2, $1, $3); }
	;

linkage_specification:
	EXTERN string_literal '{' declaration_seq_opt '}'		{ $$ = (TreeNode *)alacnary(LINKAGE_SPECIFICATIONr1, 3, $1, $2, $4); }
	| EXTERN string_literal declaration							{ $$ = (TreeNode *)alacnary(LINKAGE_SPECIFICATIONr2, 3, $1, $2, $3); }
	;

/*----------------------------------------------------------------------
 * Declarators.
 *----------------------------------------------------------------------*/
			case INIT_DECLARATOR_LISTr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case INIT_DECLARATOR_LISTr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(node->u.n.child[1] != NULL){
					if(node->u.n.child[0]->intCode != NULL) concatCode(node->intCode, node->u.n.child[1]->intCode);
					else node->intCode = node->u.n.child[1]->intCode;
				}
				if(SHOW_CODE)printCode(node);
				break;
		
			case INIT_DECLARATORr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[1]->type->base_type != NULL_TYPE){
					icode = (IntrCode *)createIntrCode();
					icode->elem->desc = C_ASN;
					icode->elem->label = node->type->label;
					temp = (NType *)getSymbolFromTable(node->u.n.child[1]->type->symbTable, node->u.n.child[1]->type);
					if((location = (Location *)calloc(1, sizeof(Location))) == NULL) memoryError();
					location->region = temp->symbTable->scope;
					location->offset = temp->offset;
					location->val = temp->val;
					location->elem = icode->elem;
					temp = (NType *)getSymbolFromTable(node->u.n.child[0]->type->symbTable, node->u.n.child[0]->type);
					icode->elem->loc[0] = makeLocation(temp);
					icode->elem->loc[1] = location;
				} else {
					icode = (IntrCode *)createIntrCode();
					icode->elem->desc = C_PARAM;
					icode->elem->label = node->type->label;
					temp = (NType *)getSymbolFromTable(node->u.n.child[0]->type->symbTable, node->u.n.child[0]->type);
					if((location = (Location *)calloc(1, sizeof(Location))) == NULL) memoryError();
					location->region = temp->symbTable->scope;
					location->offset = temp->offset;
					location->elem = icode->elem;
					icode->elem->loc[0] = location;
				}
				node->intCode = icode;
				node->place = node->intCode->elem->loc[0];
				if(SHOW_CODE)printCode(node);
				break;
				
			case DECLARATORr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			case DECLARATORr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(node->u.n.child[1] != NULL){
					if(node->u.n.child[0]->intCode != NULL) concatCode(node->intCode, node->u.n.child[1]->intCode);
					else node->intCode = node->u.n.child[1]->intCode;
				}
				if(SHOW_CODE)printCode(node);
				break;
	/*
direct_declarator:
	declarator_id														{ $$ = (TreeNode *)alacnary(DIRECT_DECLARATORr1, 1, $1); }
	| direct_declarator '('parameter_declaration_clause ')' cv_qualifier_seq exception_specification
																			{ $$ = (TreeNode *)alacnary(DIRECT_DECLARATORr2, 4, $1, $3, $5, $6); }
	| direct_declarator '('parameter_declaration_clause ')' cv_qualifier_seq
																			{ $$ = (TreeNode *)alacnary(DIRECT_DECLARATORr3, 3, $1, $3, $5); }
	| direct_declarator '('parameter_declaration_clause ')' exception_specification
																			{ $$ = (TreeNode *)alacnary(DIRECT_DECLARATORr4, 3, $1, $3, $5); }
	| direct_declarator '('parameter_declaration_clause ')'
																			{ $$ = (TreeNode *)alacnary(DIRECT_DECLARATORr5, 2, $1, $3); }
	| CLASS_NAME '('parameter_declaration_clause ')'		{ $$ = (TreeNode *)alacnary(DIRECT_DECLARATORr6, 2, $1, $3); }
	| CLASS_NAME COLONCOLON declarator_id '('parameter_declaration_clause ')'
																			{ $$ = (TreeNode *)alacnary(DIRECT_DECLARATORr7, 4, $1, $2, $3, $5); }
	| CLASS_NAME COLONCOLON CLASS_NAME '('parameter_declaration_clause ')'
																			{ $$ = (TreeNode *)alacnary(DIRECT_DECLARATORr8, 4, $1, $2, $3, $5); }
	| direct_declarator '[' constant_expression_opt ']'	{ $$ = (TreeNode *)alacnary(DIRECT_DECLARATORr9, 2, $1, $3); }
	| '(' declarator ')'												{ $$ = (TreeNode *)alacnary(DIRECT_DECLARATORr10, 1, $2); }
	;

ptr_operator:
	'*'																	{ $$ = (TreeNode *)alacnary(PTR_OPERATORr1, 0); }
	| '*' cv_qualifier_seq											{ $$ = (TreeNode *)alacnary(PTR_OPERATORr2, 1, $2); }
	| '&'																	{ $$ = (TreeNode *)alacnary(PTR_OPERATORr3, 0); }
	| nested_name_specifier '*'									{ $$ = (TreeNode *)alacnary(PTR_OPERATORr4, 1, $1); }
	| nested_name_specifier '*' cv_qualifier_seq				{ $$ = (TreeNode *)alacnary(PTR_OPERATORr5, 2, $1, $3); }
	| COLONCOLON nested_name_specifier '*'						{ $$ = (TreeNode *)alacnary(PTR_OPERATORr6, 2, $1, $2); }
	| COLONCOLON nested_name_specifier '*' cv_qualifier_seq
																			{ $$ = (TreeNode *)alacnary(PTR_OPERATORr7, 3, $1, $2, $4); }
	;

cv_qualifier_seq:
	cv_qualifier														{ $$ = (TreeNode *)alacnary(CV_QUALIFIER_SEQr1, 1, $1); }
	| cv_qualifier cv_qualifier_seq								{ $$ = (TreeNode *)alacnary(CV_QUALIFIER_SEQr2, 2, $1, $2); }
	;

cv_qualifier:
	CONST																	{ $$ = (TreeNode *)alacnary(CV_QUALIFIERr1, 1, $1); }
	| VOLATILE															{ $$ = (TreeNode *)alacnary(CV_QUALIFIERr2, 1, $1); }
	;

declarator_id:
	id_expression														{ $$ = (TreeNode *)alacnary(DECLARATOR_IDr1, 1, $1); }
	| COLONCOLON id_expression										{ $$ = (TreeNode *)alacnary(DECLARATOR_IDr2, 2, $1, $2); }
	| COLONCOLON nested_name_specifier type_name				{ $$ = (TreeNode *)alacnary(DECLARATOR_IDr3, 3, $1, $2, $3); }
	| COLONCOLON type_name											{ $$ = (TreeNode *)alacnary(DECLARATOR_IDr4, 2, $1, $2); }
	;

type_id:
	type_specifier_seq abstract_declarator_opt				{ $$ = (TreeNode *)alacnary(TYPE_IDr1, 2, $1, $2); }
	;

type_specifier_seq:
	type_specifier type_specifier_seq_opt						{ $$ = (TreeNode *)alacnary(TYPE_SPECIFIER_SEQr1, 2, $1, $2); }
	;

abstract_declarator:
	ptr_operator abstract_declarator_opt						{ $$ = (TreeNode *)alacnary(ABSTRACT_DECLARATORr1, 2, $1, $2); }
	| direct_abstract_declarator									{ $$ = (TreeNode *)alacnary(ABSTRACT_DECLARATORr2, 1, $1); }
	;

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
	;

parameter_declaration_clause:
	parameter_declaration_list ELLIPSIS							{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr1, 2, $1, $2); }
	| parameter_declaration_list									{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr2, 1, $1); }
	| ELLIPSIS															{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr3, 1, $1); }
	| /* epsilon 													{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr4, 0); }
	| parameter_declaration_list ',' ELLIPSIS					{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr5, 2, $1, $3); }
	;

parameter_declaration_list:
	parameter_declaration											{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_LISTr1, 1, $1); }
	| parameter_declaration_list ',' parameter_declaration
																			{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_LISTr2, 2, $1, $3); }
	;

parameter_declaration:
	decl_specifier_seq declarator									{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATIONr1, 2, $1, $2); }
	| decl_specifier_seq declarator '=' assignment_expression
																			{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATIONr2, 3, $1, $2, $4); }
	| decl_specifier_seq abstract_declarator_opt				{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATIONr3, 2, $1, $2); }
	| decl_specifier_seq abstract_declarator_opt '=' assignment_expression
																			{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATIONr4, 3, $1, $2, $4); }
	;
*/
			case FUNCTION_DEFINITIONr1 :
				break;
			case FUNCTION_DEFINITIONr2 :
				/*
				 * 		returnVariable(child[1])
				 *			params(child[2])
				 *	functionLabel	
				 *			functionBody(child[3])
				 */
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				//temp = (NType *)createTempSymbol(node->u.n.child[1]->type->u.func.retType, T_TEMP, mode);
				//icode = (IntrCode *)createIntrCode();
				//icode->elem->desc = C_PARAM;
				//icode->elem->label = node->type->label;
				//if((location = (Location *)calloc(1, sizeof(Location))) == NULL) memoryError();
				//location->region = temp->symbTable->scope;
				//location->offset = temp->offset;
				//location->elem = icode->elem;
				//icode->elem->loc[0] = location;					
				//node->intCode = icode;
					/* returnVariable */
				//node->intCode = concatCode(node->intCode, node->u.n.child[2]->intCode);
				node->intCode = node->u.n.child[2]->intCode;
					/* returnVariable|chile[2] */
				icode = (IntrCode *)createIntrCode();
				icode->elem->desc = C_FUNC;
				icode->elem->label = node->type->label;
				if(node->intCode != NULL)node->intCode = concatCode(node->intCode, icode);
				else node->intCode = icode;
					/* returnVariable|chile[2]|functionLabel */
				node->intCode = concatCode(node->intCode, node->u.n.child[3]->intCode);
					/* returnVariable|chile[2]|functionLabel|child[3] */
				if(SHOW_CODE)printCode(node);
				break;
/*

function_definition:
	declarator ctor_initializer_opt function_body			{ $$ = (TreeNode *)alacnary(FUNCTION_DEFINITIONr1, 3, $1, $2, $3); }
	| decl_specifier_seq declarator ctor_initializer_opt function_body
																			{ $$ = (TreeNode *)alacnary(FUNCTION_DEFINITIONr2, 4, $1, $2, $3, $4); }
	| declarator function_try_block								{ $$ = (TreeNode *)alacnary(FUNCTION_DEFINITIONr3, 2, $1, $2); }
	| decl_specifier_seq declarator function_try_block		{ $$ = (TreeNode *)alacnary(FUNCTION_DEFINITIONr4, 3, $1, $2, $3); }
	;
*/
			case FUNCTION_BODYr1 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL)node->intCode = node->u.n.child[0]->intCode;
				if(SHOW_CODE)printCode(node);
				break;
			
/*
initializer:
	'=' initializer_clause											{ $$ = (TreeNode *)alacnary(INITIALIZERr1, 1, $2); }
	| '(' expression_list ')'										{ $$ = (TreeNode *)alacnary(INITIALIZERr2, 1, $2); }
	;

initializer_clause:
	assignment_expression											{ $$ = (TreeNode *)alacnary(INITIALIZER_CLAUSEr1, 1, $1); }
	| '{' initializer_list COMMA_opt '}'						{ $$ = (TreeNode *)alacnary(INITIALIZER_CLAUSEr2, 2, $2, $3); }
	| '{' '}'															{ $$ = (TreeNode *)alacnary(INITIALIZER_CLAUSEr3, 0); }
	;

initializer_list:
	initializer_clause												{ $$ = (TreeNode *)alacnary(INITIALIZER_LISTr1, 1, $1); }
	| initializer_list ',' initializer_clause					{ $$ = (TreeNode *)alacnary(INITIALIZER_LISTr2, 2, $1, $3); }
	;

/*----------------------------------------------------------------------
 * Classes.
 *----------------------------------------------------------------------

class_specifier:
	class_head '{' member_specification_opt '}'				{ $$ = (TreeNode *)alacnary(CLASS_SPECIFIERr1, 2, $1, $3); }
	;

class_head:
	class_key class_name												{ $$ = (TreeNode *)alacnary(CLASS_HEADr1, 2, $1, $2); }
	| class_key class_name base_clause							{ $$ = (TreeNode *)alacnary(CLASS_HEADr2, 3, $1, $2, $3); }
	| class_key nested_name_specifier class_name				{ $$ = (TreeNode *)alacnary(CLASS_HEADr3, 3, $1, $2, $3); }
	| class_key nested_name_specifier class_name base_clause
																			{ $$ = (TreeNode *)alacnary(CLASS_HEADr4, 4, $1, $2, $3, $4); }
	;

class_key:
	CLASS																	{ $$ = (TreeNode *)alacnary(CLASS_KEYr1, 1, $1); }
	| STRUCT																{ $$ = (TreeNode *)alacnary(CLASS_KEYr2, 1, $1); }
	| UNION																{ $$ = (TreeNode *)alacnary(CLASS_KEYr3, 1, $1); }
	;

member_specification:
	member_declaration member_specification_opt				{ $$ = (TreeNode *)alacnary(MEMBER_SPECIFICATIONr1, 2, $1, $2); }
	| access_specifier ':' member_specification_opt			{ $$ = (TreeNode *)alacnary(MEMBER_SPECIFICATIONr2, 2, $1, $3); }
	;

member_declaration:
	decl_specifier_seq member_declarator_list ';'			{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATIONr1, 2, $1, $2); }
	| decl_specifier_seq ';'										{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATIONr2, 1, $1); }
	| member_declarator_list ';'									{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATIONr3, 1, $1); }
	| ';'																	{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATIONr4, 0); }
	| function_definition SEMICOLON_opt							{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATIONr5, 2, $1, $2); }
	| qualified_id ';'												{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATIONr6, 1, $1); }
	| using_declaration												{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATIONr7, 1, $1); }
	| template_declaration											{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL;
																				/*$$ = alacnary(MEMBER_DECLARATIONr8, 1, $1); }
	;

member_declarator_list:
	member_declarator													{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATOR_LISTr1, 1, $1); }
	| member_declarator_list ',' member_declarator			{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATOR_LISTr1, 2, $1, $3); }
	;

member_declarator:
	declarator															{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATORr1, 1, $1); }
	| declarator pure_specifier									{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATORr2, 2, $1, $2); }
	| declarator constant_initializer							{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATORr3, 2, $1, $2); }
	| identifier ':' constant_expression						{ $$ = (TreeNode *)alacnary(MEMBER_DECLARATORr4, 2, $1, $3); }
	;

/*
 * This rule need a hack for working around the ``= 0'' pure specifier.
 * 0 is returned as an ``INTEGER'' by the lexical analyzer but in this
 * context is different.
 
pure_specifier:
	'=' '0'															{ $$ = (TreeNode *)alacnary(PURE_SPECIFIERr1, 0); }
	;

constant_initializer:
	'=' constant_expression										{ $$ = (TreeNode *)alacnary(CONSTANT_INITIALIZERr1, 1, $2); }
	;

/*----------------------------------------------------------------------
 * Derived classes.
 *----------------------------------------------------------------------

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
	;

access_specifier:
	PRIVATE															{ $$ = (TreeNode *)alacnary(ACCESS_SPECIFIERr1, 1, $1); }
	| PROTECTED														{ $$ = (TreeNode *)alacnary(ACCESS_SPECIFIERr2, 1, $1); }
	| PUBLIC															{ $$ = (TreeNode *)alacnary(ACCESS_SPECIFIERr3, 1, $1); }
	;

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
	;

operator:
	NEW																{ $$ = (TreeNode *)alacnary(OPERATORr1, 1, $1); }
	| DELETE															{ $$ = (TreeNode *)alacnary(OPERATORr2, 1, $1); }
	| NEW '[' ']'													{ $$ = (TreeNode *)alacnary(OPERATORr3, 1, $1); }
	| DELETE '[' ']'												{ $$ = (TreeNode *)alacnary(OPERATORr4, 1, $1); }
	| '+'																{ $$ = (TreeNode *)alacnary(OPERATORr5, 0); }
	| '_'																{ $$ = (TreeNode *)alacnary(OPERATORr6, 0); }
	| '*'																{ $$ = (TreeNode *)alacnary(OPERATORr7, 0); }
	| '/'																{ $$ = (TreeNode *)alacnary(OPERATORr8, 0); }
	| '%'																{ $$ = (TreeNode *)alacnary(OPERATORr9, 0); }
	| '^'																{ $$ = (TreeNode *)alacnary(OPERATORr10, 0); }
	| '&'																{ $$ = (TreeNode *)alacnary(OPERATORr11, 0); }
	| '|'																{ $$ = (TreeNode *)alacnary(OPERATORr12, 0); }
	| '~'																{ $$ = (TreeNode *)alacnary(OPERATORr13, 0); }
	| '!'																{ $$ = (TreeNode *)alacnary(OPERATORr14, 0); }
	| '='																{ $$ = (TreeNode *)alacnary(OPERATORr15, 0); }
	| '<'																{ $$ = (TreeNode *)alacnary(OPERATORr16, 0); }
	| '>'																{ $$ = (TreeNode *)alacnary(OPERATORr17, 0); }
	| ADDEQ															{ $$ = (TreeNode *)alacnary(OPERATORr18, 1, $1); }	
	| SUBEQ															{ $$ = (TreeNode *)alacnary(OPERATORr19, 1, $1); }
	| MULEQ															{ $$ = (TreeNode *)alacnary(OPERATORr20, 1, $1); }
	| DIVEQ															{ $$ = (TreeNode *)alacnary(OPERATORr21, 1, $1); }
	| MODEQ															{ $$ = (TreeNode *)alacnary(OPERATORr22, 1, $1); }
	| XOREQ															{ $$ = (TreeNode *)alacnary(OPERATORr23, 1, $1); }
	| ANDEQ															{ $$ = (TreeNode *)alacnary(OPERATORr24, 1, $1); }
	| OREQ															{ $$ = (TreeNode *)alacnary(OPERATORr25, 1, $1); }
	| SL																{ $$ = (TreeNode *)alacnary(OPERATORr26, 1, $1); }
	| SR																{ $$ = (TreeNode *)alacnary(OPERATORr27, 1, $1); }
	| SREQ															{ $$ = (TreeNode *)alacnary(OPERATORr28, 1, $1); }
	| SLEQ															{ $$ = (TreeNode *)alacnary(OPERATORr29, 1, $1); }
	| EQ																{ $$ = (TreeNode *)alacnary(OPERATORr30, 1, $1); }
	| NOTEQ															{ $$ = (TreeNode *)alacnary(OPERATORr31, 1, $1); }
	| LTEQ															{ $$ = (TreeNode *)alacnary(OPERATORr32, 1, $1); }
	| GTEQ															{ $$ = (TreeNode *)alacnary(OPERATORr33, 1, $1); }
	| ANDAND															{ $$ = (TreeNode *)alacnary(OPERATORr34, 1, $1); }
	| OROR															{ $$ = (TreeNode *)alacnary(OPERATORr35, 1, $1); }
	| PLUSPLUS														{ $$ = (TreeNode *)alacnary(OPERATORr36, 1, $1); }
	| MINUSMINUS													{ $$ = (TreeNode *)alacnary(OPERATORr37, 1, $1); }
	| ','																{ $$ = (TreeNode *)alacnary(OPERATORr38, 0); }
	| ARROWSTAR														{ $$ = (TreeNode *)alacnary(OPERATORr39, 1, $1); }
	| ARROW															{ $$ = (TreeNode *)alacnary(OPERATORr40, 1, $1); }
	| '(' ')'														{ $$ = (TreeNode *)alacnary(OPERATORr41, 0); }
	| '[' ']'														{ $$ = (TreeNode *)alacnary(OPERATORr42, 0); }
	;

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
			case DECLARATION_SEQ_OPTr2 :
			case NESTED_NAME_SPECIFIER_OPTr1 :
			case NESTED_NAME_SPECIFIER_OPTr2 :
			case EXPRESSION_LIST_OPTr1 :
			case EXPRESSION_LIST_OPTr2 :
			case COLONCOLON_OPTr1 :
			case COLONCOLON_OPTr2 :
			case NEW_PLACEMENT_OPTr1 :
			case NEW_PLACEMENT_OPTr2 :
			case NEW_INITIALIZER_OPTr1 :
			case NEW_INITIALIZER_OPTr2 :
			case NEW_DECLARATOR_OPTr1 :
			case NEW_DECLARATOR_OPTr2 :
			case EXPRESSION_OPTr1 :
			case EXPRESSION_OPTr2 :
			case STATEMENT_SEQ_OPTr1 :
			case STATEMENT_SEQ_OPTr2 :
			case CONDITION_OPTr1 :
			case CONDITION_OPTr2 :
			case ENUMERATOR_LIST_OPTr1 :
			case ENUMERATOR_LIST_OPTr2 :
			case INITIALIZER_OPTr1 :
			case INITIALIZER_OPTr2 :
			case CONSTANT_EXPRESSION_OPTr1 :
			case CONSTANT_EXPRESSION_OPTr2 :
			case ABSTRACT_DECLARATOR_OPTr1 :
			case ABSTRACT_DECLARATOR_OPTr2 :
			case TYPE_SPECIFIER_SEQ_OPTr1 :
			case TYPE_SPECIFIER_SEQ_OPTr2 :
			case DIRECT_ABSTRACT_DECLARATOR_OPTr1 :
			case DIRECT_ABSTRACT_DECLARATOR_OPTr2 :
			case CTOR_INITIALIZER_OPTr1 :
			case CTOR_INITIALIZER_OPTr2 :
			case COMMA_OPTr1 :
			case COMMA_OPTr2 :
			case MEMBER_SPECIFICATION_OPTr1 :
			case MEMBER_SPECIFICATION_OPTr2 :
			case SEMICOLON_OPTr1 :
			case SEMICOLON_OPTr2 :
			case CONVERSION_DECLARATOR_OPTr1 :
			case CONVERSION_DECLARATOR_OPTr2 :
			case EXPORT_OPTr1 :
			case EXPORT_OPTr2 :
			case HANDLER_SEQ_OPTr1 :
			case HANDLER_SEQ_OPTr2 :
			case ASSIGNMENT_EXPRESSION_OPTr1 :
			case ASSIGNMENT_EXPRESSION_OPTr2 :
			case TYPE_ID_LIST_OPTr1 :
			case TYPE_ID_LIST_OPTr2 :
				if(SHOW_MEMMORY)printf("%s\n", humanreadable(node->u.n.rule));
				if(node->u.n.child[0] != NULL) {
					printCode(node->u.n.child[0]);
					if(node->u.n.child[0]->intCode != NULL){
						node->intCode = node->u.n.child[0]->intCode;
					}
				}
				if(SHOW_CODE)printCode(node);
				break;

		}
	}
}
