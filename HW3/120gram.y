/*
 *
 * Parcer for 120++ 
 *
 * Adaptation by John Goettsche based upon the grammar provided by 
 * Clinton Jeffery for CS 445 at University of Idaho
 *
 */

/*
 * Grammar for 120++, a subset of C++ used in CS 120 at University of Idaho
 *
 * Adaptation by Clinton Jeffery, with help from Matthew Brown, Ranger
 * Adams, and Shea Newton.
 *
 * Based on Sandro Sigala's transcription of the ISO C++ 1996 draft standard.
 * 
 */

/*	$Id: parser.y,v 1.3 1997/11/19 15:13:16 sandro Exp $	*/

/*
 * Copyright (c) 1997 Sandro Sigala <ssigala@globalnet.it>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * ISO C++ parser.
 *
 * Based on the ISO C++ draft standard of December '96.
 */

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "sdef.h"
#include "parsedef.h"
//#include "symbol.h"
#include "errors.h"

//#define SYMBOL_TABLE_SIZE 31

extern int lineno;
int yydebug=1;
FILE *yyin;
char *fname;
int errors;
ErrorMessage *e_message;
TreeNode *root;
extern int exitStatus;

extern int using_namespace_std;
extern int included_iostream;
extern int included_cstdlib;
extern int included_ctime; 
extern int included_string;
extern int included_fstream;
extern int included_stdio; 
extern int included_stdlib;

%}

%union{
	struct TreeNode *n;
}

%token <n> IDENTIFIER INTEGER FLOATING CHARACTER STRING
%token <n> TYPEDEF_NAME NAMESPACE_NAME CLASS_NAME ENUM_NAME TEMPLATE_NAME

%token <n> ELLIPSIS COLONCOLON DOTSTAR ADDEQ SUBEQ MULEQ DIVEQ MODEQ
%token <n> XOREQ ANDEQ OREQ SL SR SREQ SLEQ EQ NOTEQ LTEQ GTEQ ANDAND OROR
%token <n> PLUSPLUS MINUSMINUS ARROWSTAR ARROW

%token <n> ASM AUTO BOOL BREAK CASE CATCH CHAR CLASS CONST CONST_CAST CONTINUE
%token <n> DEFAULT DELETE DO DOUBLE DYNAMIC_CAST ELSE ENUM EXPLICIT EXPORT EXTERN
%token <n> FALSE FLOAT FOR FRIEND GOTO IF INLINE INT LONG MUTABLE NAMESPACE NEW
%token <n> OPERATOR PRIVATE PROTECTED PUBLIC REGISTER REINTERPRET_CAST RETURN
%token <n> SHORT SIGNED SIZEOF STATIC STATIC_CAST STRUCT SWITCH TEMPLATE THIS
%token <n> THROW TRUE TRY TYPEDEF TYPEID TYPENAME UNION UNSIGNED USING VIRTUAL
%token <n> VOID VOLATILE WCHAR_T WHILE STR_TYPE

%type <n> typedef_name namespace_name original_namespace_name class_name enum_name template_name
%type <n> identifier literal integer_literal character_literal floating_literal string_literal
%type <n> boolean_literal translation_unit primary_expression id_expression unqualified_id qualified_id
%type <n> nested_name_specifier postfix_expression expression_list unary_expression unary_operator
%type <n> new_expression new_placement new_type_id new_declarator direct_new_declarator new_initializer
%type <n> delete_expression cast_expression pm_expression multiplicative_expression additive_expression
%type <n> shift_expression relational_expression equality_expression and_expression exclusive_or_expression
%type <n> inclusive_or_expression logical_and_expression logical_or_expression conditional_expression
%type <n> assignment_expression assignment_operator expression constant_expression statement
%type <n> labeled_statement expression_statement compound_statement statement_seq selection_statement
%type <n> condition iteration_statement for_init_statement jump_statement declaration_statement
%type <n> declaration_seq declaration block_declaration simple_declaration decl_specifier
%type <n> decl_specifier_seq storage_class_specifier function_specifier type_specifier simple_type_specifier
%type <n> type_name elaborated_type_specifier enum_specifier enumerator_list enumerator_definition
%type <n> enumerator namespace_definition named_namespace_definition original_namespace_definition
%type <n> extension_namespace_definition unnamed_namespace_definition namespace_body namespace_alias_definition
%type <n> qualified_namespace_specifier using_declaration using_directive asm_definition linkage_specification 
%type <n> init_declarator_list init_declarator declarator direct_declarator ptr_operator cv_qualifier_seq
%type <n> cv_qualifier declarator_id type_id type_specifier_seq abstract_declarator direct_abstract_declarator
%type <n> parameter_declaration_clause parameter_declaration_list parameter_declaration function_definition
%type <n> function_body initializer initializer_clause initializer_list class_specifier class_head
%type <n> class_key member_specification member_declaration member_declarator_list member_declarator
%type <n> pure_specifier constant_initializer base_clause base_specifier_list base_specifier
%type <n> access_specifier conversion_function_id conversion_type_id conversion_declarator 
%type <n> ctor_initializer mem_initializer_list mem_initializer mem_initializer_id operator_function_id
%type <n> operator template_declaration template_parameter_list template_parameter type_parameter
%type <n> template_id template_argument_list template_argument explicit_instantiation explicit_specialization
%type <n> try_block function_try_block handler_seq handler exception_declaration throw_expression
%type <n> exception_specification type_id_list declaration_seq_opt nested_name_specifier_opt 
%type <n> expression_list_opt COLONCOLON_opt new_placement_opt new_initializer_opt new_declarator_opt
%type <n> expression_opt statement_seq_opt condition_opt enumerator_list_opt initializer_opt
%type <n> constant_expression_opt abstract_declarator_opt type_specifier_seq_opt direct_abstract_declarator_opt
%type <n> ctor_initializer_opt COMMA_opt member_specification_opt SEMICOLON_opt conversion_declarator_opt
%type <n> EXPORT_opt handler_seq_opt assignment_expression_opt type_id_list_opt

%start translation_unit

%%

/*----------------------------------------------------------------------
 * Context-dependent identifiers.
 *----------------------------------------------------------------------*/

typedef_name:
	/* identifier */
	TYPEDEF_NAME														{ $$ = (TreeNode *)alacnary(TYPEDEF_NAMEr1, 1, $1); }
	;

namespace_name:
	original_namespace_name											{ $$ = (TreeNode *)alacnary(NAMESPACE_NAMEr1, 1, $1); }
	;

original_namespace_name:
	/* identifier */
	NAMESPACE_NAME														{ $$ = (TreeNode *)alacnary(ORIGINAL_NAMESPACE_NAMEr1, 1, $1); }
	;

class_name:
	/* identifier */
	CLASS_NAME															{ $$ = (TreeNode *)alacnary(CLASS_NAMEr1, 1, $1); }
	| template_id														{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL;
																				/*$$ = (TreeNode *)alacnary(CLASS_NAMEr2, 1, $1); */}
	;

enum_name:
	/* identifier */
	ENUM_NAME															{ $$ = (TreeNode *)alacnary(ENUM_NAMEr1, 1, $1); }
	;

template_name:
	/* identifier */
	TEMPLATE_NAME														{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL; 
																				/*(TreeNode *)alacnary(TEMPLATE_NAMEr1, 1, $1);*/ }
	;

/*----------------------------------------------------------------------
 * Lexical elements.
 *----------------------------------------------------------------------*/

identifier:
	IDENTIFIER															{ $$ = (TreeNode *)alacnary(IDENTIFIERr1, 1, $1); }
	;

literal:
	integer_literal													{ $$ = (TreeNode *)alacnary(LITERALr1, 1, $1); }
	| character_literal												{ $$ = (TreeNode *)alacnary(LITERALr2, 1, $1); }
	| floating_literal												{ $$ = (TreeNode *)alacnary(LITERALr3, 1, $1); }
	| string_literal													{ $$ = (TreeNode *)alacnary(LITERALr4, 1, $1); }
	| boolean_literal													{ $$ = (TreeNode *)alacnary(LITERALr5, 1, $1); }
	;

integer_literal:
	INTEGER																{ $$ = (TreeNode *)alacnary(INTEGER_LITERALr1, 1, $1); }
	;

character_literal:
	CHARACTER															{ $$ = (TreeNode *)alacnary(CHARACTER_LITERALr1, 1, $1); }
	;

floating_literal:
	FLOATING																{ $$ = (TreeNode *)alacnary(FLOATING_LITERALr1, 1, $1); }
	;

string_literal:
	STRING																{ $$ = (TreeNode *)alacnary(STRING_LITERALr1, 1, $1); }
	;

boolean_literal:
	TRUE																	{ $$ = (TreeNode *)alacnary(BOOLEAN_LITERALr1, 1, $1); }
	| FALSE																{ $$ = (TreeNode *)alacnary(BOOLEAN_LITERALr2, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Translation unit.
 *----------------------------------------------------------------------*/

translation_unit:
	declaration_seq_opt												{ root = (TreeNode *)alacnary(TRANSLATION_UNITr1, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Expressions.
 *----------------------------------------------------------------------*/

primary_expression:
	literal																{ $$ = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr1, 1, $1); }
	| THIS																{ $$ = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr2, 1, $1); }
	| '(' expression ')'												{ $$ = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr3, 1, $2); }
	| id_expression													{ $$ = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr4, 1, $1); }
	;

id_expression:
	unqualified_id														{ $$ = (TreeNode *)alacnary(ID_EXPRESSIONr1, 1, $1); }
	| qualified_id														{ $$ = (TreeNode *)alacnary(ID_EXPRESSIONr2, 1, $1); }
	;

unqualified_id:
	identifier															{ $$ = (TreeNode *)alacnary(UNQUALIFIED_IDr1, 1, $1); }
	| operator_function_id											{ $$ = (TreeNode *)alacnary(UNQUALIFIED_IDr2, 1, $1); }
	| conversion_function_id										{ $$ = (TreeNode *)alacnary(UNQUALIFIED_IDr3, 1, $1); }
	| '~' class_name													{ $$ = (TreeNode *)alacnary(UNQUALIFIED_IDr4, 1, $2); }
	;

qualified_id:
	nested_name_specifier unqualified_id						{ $$ = (TreeNode *)alacnary(QUALIFIED_IDr1, 2, $1, $2); }
	| nested_name_specifier TEMPLATE unqualified_id			{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL;
																			/* $$ = (TreeNode *)alacnary(QUALIFIED_IDr1, 3, $1, $2, $3);*/ }
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
																			{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL;
																			/*$$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr4, 3, $1, $3, $4);*/ }
	| postfix_expression '.' TEMPLATE id_expression			{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL;
																			/*$$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr5, 3, $1, $3, $4); */}
	| postfix_expression '.' COLONCOLON id_expression		{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr6, 3, $1, $3, $4); }
	| postfix_expression '.' id_expression						{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr7, 2, $1, $3); }
	| postfix_expression ARROW TEMPLATE COLONCOLON id_expression
																			{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr8, 5, $1, $2, $3, $4, $5); }
	| postfix_expression ARROW TEMPLATE id_expression		{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL;
																			/*$$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr9, 4, $1, $2, $3, $4); */}
	| postfix_expression ARROW COLONCOLON id_expression	{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr10, 4, $1, $2, $3, $4); }
	| postfix_expression ARROW id_expression					{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr11, 3, $1, $2, $3); }
	| postfix_expression PLUSPLUS									{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr12, 2, $1, $2); }
	| postfix_expression MINUSMINUS								{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr13, 2, $1, $2); }
	| DYNAMIC_CAST '<' type_id '>' '(' expression ')'		{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr14, 3, $1, $3, $6); }
	| STATIC_CAST '<' type_id '>' '(' expression ')'		{ exitStatus = 2;
																				getErrorMessage(ER_STATIC);
																				yyerror(NULL);
																				$$ = NULL;
																			/* $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr15, 3, $1, $3, $6); */}
	| REINTERPRET_CAST '<' type_id '>' '(' expression ')'	{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr16, 3, $1, $3, $6); }
	| CONST_CAST '<' type_id '>' '(' expression ')'			{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr17, 3, $1, $3, $6); }
	| TYPEID '(' expression ')'									{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr18, 2, $1, $3); }
	| TYPEID '(' type_id ')'										{ $$ = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr19, 2, $1, $3); }
	;

expression_list:
	assignment_expression											{ $$ = (TreeNode *)alacnary(EXPRESSION_LISTr1, 1, $1); }
	| expression_list ',' assignment_expression				{ $$ = (TreeNode *)alacnary(EXPRESSION_LISTr2, 2, $1, $3); }
	;

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
	;

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

statement:
	labeled_statement													{ $$ = (TreeNode *)alacnary(STATEMENTr1, 1, $1); }
	| expression_statement											{ $$ = (TreeNode *)alacnary(STATEMENTr2, 1, $1); }
	| compound_statement												{ $$ = (TreeNode *)alacnary(STATEMENTr3, 1, $1); }
	| selection_statement											{ $$ = (TreeNode *)alacnary(STATEMENTr4, 1, $1); }
	| iteration_statement											{ $$ = (TreeNode *)alacnary(STATEMENTr5, 1, $1); }
	| jump_statement													{ $$ = (TreeNode *)alacnary(STATEMENTr6, 1, $1); }
	| declaration_statement											{ $$ = (TreeNode *)alacnary(STATEMENTr7, 1, $1); }
	| try_block															{ $$ = (TreeNode *)alacnary(STATEMENTr8, 1, $1); }
	;

labeled_statement:
	identifier ':' statement										{ $$ = (TreeNode *)alacnary(LABELED_STATEMENTr1, 2, $1, $3); }
	| CASE constant_expression ':' statement					{ $$ = (TreeNode *)alacnary(LABELED_STATEMENTr2, 3, $1, $2, $4); }
	| DEFAULT ':' statement											{ $$ = (TreeNode *)alacnary(LABELED_STATEMENTr3, 2, $1, $3); }
	;

expression_statement:
	expression_opt ';'												{ $$ = (TreeNode *)alacnary(EXPRESSION_STATEMENTr1, 1, $1); }
	;

compound_statement:
	'{' statement_seq_opt '}'										{ $$ = (TreeNode *)alacnary(COMPOUND_STATEMENTr1, 1, $2); }
	;

statement_seq:
	statement															{ $$ = (TreeNode *)alacnary(STATEMENT_SEQr1, 1, $1); }
	| statement_seq statement										{ $$ = (TreeNode *)alacnary(STATEMENT_SEQr2, 2, $1, $2); }
	;

selection_statement:
	IF '(' condition ')' statement								{ $$ = (TreeNode *)alacnary(SELECTION_STATEMENTr1, 3, $1, $3, $5); }
	| IF '(' condition ')' statement ELSE statement			{ $$ = (TreeNode *)alacnary(SELECTION_STATEMENTr2, 5, $1, $3, $5, $6, $7); }
	| SWITCH '(' condition ')' statement						{ $$ = (TreeNode *)alacnary(SELECTION_STATEMENTr3, 3, $1, $3, $5); }
	;

condition:
	expression															{ $$ = (TreeNode *)alacnary(CONDITIONr1, 1, $1); }
	| type_specifier_seq declarator '=' assignment_expression
																			{ $$ = (TreeNode *)alacnary(CONDITIONr2, 3, $1, $2, $4); }
	;

iteration_statement:
	WHILE '(' condition ')' statement							{ $$ = (TreeNode *)alacnary(ITERATION_STATEMENTr1, 3, $1, $3, $5); }
	| DO statement WHILE '(' expression ')' ';'				{ $$ = (TreeNode *)alacnary(ITERATION_STATEMENTr2, 4, $1, $2, $3, $5); }
	| FOR '(' for_init_statement condition_opt ';' expression_opt ')' statement
																			{ $$ = (TreeNode *)alacnary(ITERATION_STATEMENTr3, 5, $1, $3, $4, $6, $8); }
	;

for_init_statement:
	expression_statement												{ $$ = (TreeNode *)alacnary(FOR_INIT_STATEMENTr1, 1, $1); }
	| simple_declaration												{ $$ = (TreeNode *)alacnary(FOR_INIT_STATEMENTr2, 1, $1); }
	;

jump_statement:
	BREAK ';'															{ $$ = (TreeNode *)alacnary(JUMP_STATEMENTr1, 1, $1); }
	| CONTINUE ';'														{ $$ = (TreeNode *)alacnary(JUMP_STATEMENTr2, 1, $1); }
	| RETURN expression_opt ';'									{ $$ = (TreeNode *)alacnary(JUMP_STATEMENTr3, 2, $1, $2); }
	| GOTO identifier ';'											{ $$ = (TreeNode *)alacnary(JUMP_STATEMENTr4, 2, $1, $2); }
	;

declaration_statement:
	block_declaration													{ $$ = (TreeNode *)alacnary(DECLARATION_STATEMENTr1, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Declarations.
 *----------------------------------------------------------------------*/

declaration_seq:
	declaration															{ $$ = (TreeNode *)alacnary(DECLARATION_SEQr1, 1, $1); }
	| declaration_seq declaration									{ $$ = (TreeNode *)alacnary(DECLARATION_SEQr2, 2, $1, $2); }
	;

declaration:
	block_declaration													{ $$ = (TreeNode *)alacnary(DECLARATIONr1, 1, $1); }
	| function_definition											{ $$ = (TreeNode *)alacnary(DECLARATIONr2, 1, $1); }
	| template_declaration											{ exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				$$ = NULL;
																				/*$$ = alacnary(DECLARATIONr3, 1, $1); */}
	| explicit_instantiation										{ $$ = (TreeNode *)alacnary(DECLARATIONr4, 1, $1); }
	| explicit_specialization										{ $$ = (TreeNode *)alacnary(DECLARATIONr5, 1, $1); }
	| linkage_specification											{ $$ = (TreeNode *)alacnary(DECLARATIONr6, 1, $1); }
	| namespace_definition											{ $$ = (TreeNode *)alacnary(DECLARATIONr7, 1, $1); }
	;

block_declaration:
	simple_declaration												{ $$ = (TreeNode *)alacnary(BLOCK_DECLARATIONr1, 1, $1); }
	| asm_definition													{ $$ = (TreeNode *)alacnary(BLOCK_DECLARATIONr2, 1, $1); }
	| namespace_alias_definition									{ $$ = (TreeNode *)alacnary(BLOCK_DECLARATIONr3, 1, $1); }
	| using_declaration												{ $$ = (TreeNode *)alacnary(BLOCK_DECLARATIONr4, 1, $1); }
	| using_directive													{ $$ = (TreeNode *)alacnary(BLOCK_DECLARATIONr5, 1, $1); }
	;

simple_declaration:
	decl_specifier_seq init_declarator_list ';'				{ $$ = (TreeNode *)alacnary(SIMPLE_DECLARATIONr1, 2, $1, $2); }
	|  decl_specifier_seq ';'										{ $$ = (TreeNode *)alacnary(SIMPLE_DECLARATIONr2, 1, $1); }
	;

decl_specifier:
	storage_class_specifier											{ $$ = (TreeNode *)alacnary(DECL_SPECIFIERr1, 1, $1); }
	| type_specifier													{ $$ = (TreeNode *)alacnary(DECL_SPECIFIERr2, 1, $1); }
	| function_specifier												{ $$ = (TreeNode *)alacnary(DECL_SPECIFIERr3, 1, $1); }
	| FRIEND																{ $$ = (TreeNode *)alacnary(DECL_SPECIFIERr4, 1, $1); }
	| TYPEDEF															{ $$ = (TreeNode *)alacnary(DECL_SPECIFIERr5, 1, $1); }
	;

decl_specifier_seq:
	decl_specifier														{ $$ = (TreeNode *)alacnary(DECL_SPECIFIER_SEQr1, 1, $1); }
	| decl_specifier_seq decl_specifier							{ $$ = (TreeNode *)alacnary(DECL_SPECIFIER_SEQr2, 2, $1, $2); }
	;

storage_class_specifier:
	AUTO																	{ getErrorMessage(ER_AUTO);
																				yyerror(NULL);
																				$$ = NULL;
																				/*$$ = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr1, 1, $1); */}
	| REGISTER															{ getErrorMessage(ER_REGISTER);
																				yyerror(NULL);
																				$$ = NULL;
																				/*$$ = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr2, 1, $1); */}
	| STATIC																{ exitStatus = 3;
																				getErrorMessage(ER_STATIC);
																				yyerror(NULL);
																				$$ = NULL;
																				/*$$ = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr3, 1, $1); */}
	| EXTERN																{ exitStatus = 3;
																				getErrorMessage(ER_EXTERN);
																				yyerror(NULL);
																				$$ = NULL;
																				/*$$ = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr4, 1, $1); */}
	| MUTABLE															{ exitStatus = 3;
																				getErrorMessage(ER_MUTABLE);
																				yyerror(NULL);
																				$$ = NULL;
																				/*$$ = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr5, 1, $1); */}
	;

function_specifier:
	INLINE																{ getErrorMessage(ER_INLINE);
																				yyerror(NULL);
																				$$ = NULL;
																				/*$$ = (TreeNode *)alacnary(FUNCTION_SPECIFIERr1, 1, $1); */}
	| VIRTUAL															{ getErrorMessage(ER_VIRTUAL);
																				yyerror(NULL);
																				$$ = NULL;
																				/*$$ = (TreeNode *)alacnary(FUNCTION_SPECIFIERr2, 1, $1); */}
	| EXPLICIT															{ getErrorMessage(ER_EXPLICIT);
																				yyerror(NULL);
																				$$ = NULL;
																				/*$$ = (TreeNode *)alacnary(FUNCTION_SPECIFIERr3, 1, $1); */}
	;

type_specifier:
	simple_type_specifier											{ $$ = (TreeNode *)alacnary(TYPE_SPECIFIERr1, 1, $1); }
	| class_specifier													{ $$ = (TreeNode *)alacnary(TYPE_SPECIFIERr2, 1, $1); }
	| enum_specifier													{ $$ = (TreeNode *)alacnary(TYPE_SPECIFIERr3, 1, $1); }
	| elaborated_type_specifier									{ $$ = (TreeNode *)alacnary(TYPE_SPECIFIERr4, 1, $1); }
	| cv_qualifier														{ $$ = (TreeNode *)alacnary(TYPE_SPECIFIERr5, 1, $1); }
	;

simple_type_specifier:
	type_name															{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr1, 1, $1); }
	| nested_name_specifier type_name							{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr2, 2, $1, $2); }
	| COLONCOLON nested_name_specifier_opt type_name		{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr3, 3, $1, $2, $3); }
	| CHAR																{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr4, 1, $1); }
	| WCHAR_T															{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr5, 1, $1); }
	| BOOL																{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr6, 1, $1); }
	| SHORT																{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr7, 1, $1); }
	| INT																	{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr8, 1, $1); }
	| LONG																{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr9, 1, $1); }
	| SIGNED																{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr10, 1, $1); }
	| UNSIGNED															{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr11, 1, $1); }
	| FLOAT																{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr12, 1, $1); }
	| DOUBLE																{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr13, 1, $1); }
	| VOID																{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr14, 1, $1); }
	| STR_TYPE															{ $$ = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr15, 1, $1); }
	;

type_name:
	class_name															{ $$ = (TreeNode *)alacnary(TYPE_NAMEr1, 1, $1); }
	| enum_name															{ $$ = (TreeNode *)alacnary(TYPE_NAMEr2, 1, $1); }
	| typedef_name														{ $$ = (TreeNode *)alacnary(TYPE_NAMEr3, 1, $1); }
	;

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
																				/*$$ = alacnary(ELABORATED_TYPE_SPECIFIERr7, 5, $1, $2, $3, $4, $6); */}
	;

/*
enum_name:
	identifier
	;
*/

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
*/

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
*/

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

init_declarator_list:
	init_declarator													{ $$ = (TreeNode *)alacnary(INIT_DECLARATOR_LISTr1, 1, $1); }
	| init_declarator_list ',' init_declarator				{ $$ = (TreeNode *)alacnary(INIT_DECLARATOR_LISTr2, 2, $1, $3); }
	;

init_declarator:
	declarator initializer_opt										{ $$ = (TreeNode *)alacnary(INIT_DECLARATORr1, 2, $1, $2); }
	;

declarator:
	direct_declarator													{ $$ = (TreeNode *)alacnary(DECLARATORr1, 1, $1); }
	| ptr_operator declarator										{ $$ = (TreeNode *)alacnary(DECLARATORr2, 2, $1, $2); }
	;

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
	| /* epsilon */													{ $$ = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr4, 0); }
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

function_definition:
	declarator ctor_initializer_opt function_body			{ $$ = (TreeNode *)alacnary(FUNCTION_DEFINITIONr1, 3, $1, $2, $3); }
	| decl_specifier_seq declarator ctor_initializer_opt function_body
																			{ $$ = (TreeNode *)alacnary(FUNCTION_DEFINITIONr2, 4, $1, $2, $3, $4); }
	| declarator function_try_block								{ $$ = (TreeNode *)alacnary(FUNCTION_DEFINITIONr3, 2, $1, $2); }
	| decl_specifier_seq declarator function_try_block		{ $$ = (TreeNode *)alacnary(FUNCTION_DEFINITIONr4, 3, $1, $2, $3); }
	;

function_body:
	compound_statement												{ $$ = (TreeNode *)alacnary(FUNCTION_BODYr1, 1, $1); }
	;

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
 *----------------------------------------------------------------------*/

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
																				/*$$ = alacnary(MEMBER_DECLARATIONr8, 1, $1); */}
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
 */
pure_specifier:
	'=' '0'															{ $$ = (TreeNode *)alacnary(PURE_SPECIFIERr1, 0); }
	;

constant_initializer:
	'=' constant_expression										{ $$ = (TreeNode *)alacnary(CONSTANT_INITIALIZERr1, 1, $2); }
	;

/*----------------------------------------------------------------------
 * Derived classes.
 *----------------------------------------------------------------------*/

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
 *----------------------------------------------------------------------*/

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
 *----------------------------------------------------------------------*/

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
 * Templates.
 *----------------------------------------------------------------------*/

template_declaration:
	EXPORT_opt TEMPLATE '<' template_parameter_list '>' declaration
																		{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL; 
																			/*alacnary(TEMPLATE_DECLARATIONr1, 4, $1, $2, $4, $6); */}
	;

template_parameter_list:
	template_parameter											{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL; 
																			/*$$ = alacnary(TEMPLATE_PARAMETER_LISTr1, 1, $1); */}
	| template_parameter_list ',' template_parameter	{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL; 
																			/*$$ = alacnary(TEMPLATE_PARAMETER_LISTr2, 2, $1, $3);*/ }
	;

template_parameter:
	type_parameter													{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL; 
																			/*$$ = alacnary(TEMPLATE_PARAMETERr1, 1, $1); */}
	| parameter_declaration										{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL; 
																			/* $$ = alacnary(TEMPLATE_PARAMETERr2, 1, $1); */}
	;

type_parameter:
	CLASS identifier												{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL;
																			/*$$ = alacnary(TYPE_PARAMETERr1, 2, $1, $2);*/ }
	| CLASS identifier '=' type_id							{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL;
																			/*$$ = alacnary(TYPE_PARAMETERr2, 3, $1, $2, $4); */}
	| TYPENAME identifier										{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL;
																			/*$$ = alacnary(TYPE_PARAMETERr3, 2, $1, $2);*/ }
	| TYPENAME identifier '=' type_id						{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL;
																			/*$$ = alacnary(TYPE_PARAMETERr4, 3, $1, $2, $4); */}
	| TEMPLATE '<' template_parameter_list '>' CLASS identifier
																		{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL; /*alacnary(TYPE_PARAMETERr5, 4, $1, $3, $5, $6);*/ }
	| TEMPLATE '<' template_parameter_list '>' CLASS identifier '=' template_name
																		{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL; /*alacnary(TYPE_PARAMETERr6, 5, $1, $3, $5, $6, $8);*/ }
	;

template_id:
	template_name '<' template_argument_list '>'			{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL; /*alacnary(TEMPLATE_IDr1, 2, $1, $3);*/ }
	;

template_argument_list:
	template_argument												{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL;
																			/*$$ = alacnary(TEMPLATE_ARGUMENT_LISTr1, 1, $1); */}
	| template_argument_list ',' template_argument		{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL;
																			/*$$ = alacnary(TEMPLATE_ARGUMENT_LISTr2, 2, $1, $3);*/}
	;

template_argument:
	assignment_expression										{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL;
																			/*$$ = alacnary(TEMPLATE_ARGUMENTr1, 1, $1);*/ }
	| type_id														{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL;
																			/*$$ = alacnary(TEMPLATE_ARGUMENTr2, 1, $1);*/ }
	| template_name												{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL;
																			/*$$ = alacnary(TEMPLATE_ARGUMENTr3, 1, $1);*/ }
	;

explicit_instantiation:
	TEMPLATE declaration											{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL; 
																			/*alacnary(EXPLICIT_INSTANTIATIONr1, 2, $1, $2);*/ }
	;

explicit_specialization:
	TEMPLATE '<' '>' declaration								{ exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			$$ = NULL; 
																			/*alacnary(EXPLICIT_SPECIALIZATIONr1, 2, $1, $4);*/ }
	;

/*----------------------------------------------------------------------
 * Exception handling.
 *----------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------
 * Epsilon (optional) definitions.
 *----------------------------------------------------------------------*/

declaration_seq_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(DECLARATION_SEQ_OPTr1, 0); }
	| declaration_seq												{ $$ = (TreeNode *)alacnary(DECLARATION_SEQ_OPTr2, 1, $1); }
	;

nested_name_specifier_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(NESTED_NAME_SPECIFIER_OPTr1, 0); }
	| nested_name_specifier										{ $$ = (TreeNode *)alacnary(NESTED_NAME_SPECIFIER_OPTr2, 1, $1); }
	;

expression_list_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(EXPRESSION_LIST_OPTr1, 0); }
	| expression_list												{ $$ = (TreeNode *)alacnary(EXPRESSION_LIST_OPTr2, 1, $1); }
	;

COLONCOLON_opt:
	/* epsilon */													{ $$ = (TreeNode *)(TreeNode *)alacnary(COLONCOLON_OPTr1, 0); }
	| COLONCOLON													{ $$ = (TreeNode *)alacnary(COLONCOLON_OPTr2, 1, $1); }
	;

new_placement_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(NEW_PLACEMENT_OPTr1, 0); }
	| new_placement												{ $$ = (TreeNode *)alacnary(NEW_PLACEMENT_OPTr2, 1, $1); }
	;

new_initializer_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(NEW_INITIALIZER_OPTr1, 0); }
	| new_initializer												{ $$ = (TreeNode *)alacnary(NEW_INITIALIZER_OPTr2, 1, $1); }
	;

new_declarator_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(NEW_DECLARATOR_OPTr1, 0); }
	| new_declarator												{ $$ = (TreeNode *)alacnary(NEW_DECLARATOR_OPTr2, 1, $1); }
	;

expression_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(EXPRESSION_OPTr1, 0); }
	| expression													{ $$ = (TreeNode *)alacnary(EXPRESSION_OPTr2, 1, $1); }
	;

statement_seq_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(STATEMENT_SEQ_OPTr1, 0); }
	| statement_seq												{ $$ = (TreeNode *)alacnary(STATEMENT_SEQ_OPTr2, 1, $1); }
	;

condition_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(CONDITION_OPTr1, 0); }
	| condition														{ $$ = (TreeNode *)alacnary(CONDITION_OPTr2, 1, $1); }
	;

enumerator_list_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(ENUMERATOR_LIST_OPTr1, 0); }
	| enumerator_list												{ $$ = (TreeNode *)alacnary(ENUMERATOR_LIST_OPTr2, 1, $1); }
	;

initializer_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(INITIALIZER_OPTr1, 0); }
	| initializer													{ $$ = (TreeNode *)alacnary(INITIALIZER_OPTr2, 1, $1); }
	;

constant_expression_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(CONSTANT_EXPRESSION_OPTr1, 0); }
	| constant_expression										{ $$ = (TreeNode *)alacnary(CONSTANT_EXPRESSION_OPTr2, 1, $1); }
	;

abstract_declarator_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(ABSTRACT_DECLARATOR_OPTr1, 0); }
	| abstract_declarator										{ $$ = (TreeNode *)alacnary(ABSTRACT_DECLARATOR_OPTr2, 1, $1); }
	;

type_specifier_seq_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(TYPE_SPECIFIER_SEQ_OPTr1, 0); }
	| type_specifier_seq											{ $$ = (TreeNode *)alacnary(TYPE_SPECIFIER_SEQ_OPTr2, 1, $1); }
	;

direct_abstract_declarator_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATOR_OPTr1, 0); }
	| direct_abstract_declarator								{ $$ = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATOR_OPTr2, 1, $1); }
	;

ctor_initializer_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(CTOR_INITIALIZER_OPTr1, 0); }
	| ctor_initializer											{ $$ = (TreeNode *)alacnary(CTOR_INITIALIZER_OPTr2, 1, $1); }
	;

COMMA_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(COMMA_OPTr1, 0); }
	| ','																{ $$ = (TreeNode *)alacnary(COMMA_OPTr2, 0); }
	;

member_specification_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(MEMBER_SPECIFICATION_OPTr1, 0); }
	| member_specification										{ $$ = (TreeNode *)alacnary(MEMBER_SPECIFICATION_OPTr2, 1, $1); }
	;

SEMICOLON_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(SEMICOLON_OPTr1, 0); }
	| ';'																{ $$ = (TreeNode *)alacnary(SEMICOLON_OPTr2, 0); }
	;

conversion_declarator_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(CONVERSION_DECLARATOR_OPTr1, 0); }
	| conversion_declarator										{ $$ = (TreeNode *)alacnary(CONVERSION_DECLARATOR_OPTr2, 1, $1); }
	;

EXPORT_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(EXPORT_OPTr1, 0); }
	| EXPORT															{ $$ = (TreeNode *)alacnary(EXPORT_OPTr2, 1, $1); }
	;

handler_seq_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(HANDLER_SEQ_OPTr1, 0); }
	| handler_seq													{ $$ = (TreeNode *)alacnary(HANDLER_SEQ_OPTr2, 1, $1); }
	;

assignment_expression_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSION_OPTr1, 0); }
	| assignment_expression										{ $$ = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSION_OPTr2, 1, $1); }
	;

type_id_list_opt:
	/* epsilon */													{ $$ = (TreeNode *)alacnary(TYPE_ID_LIST_OPTr1, 0); }
	| type_id_list													{ $$ = (TreeNode *)alacnary(TYPE_ID_LIST_OPTr2, 1, $1); }
	;

%%

int main(int argc, char **argv){
	int rv;
   if(argc > 1) { 
		int f;
		//read each file in arguments
		for(f = 1; f < argc; f++) {
			fname = argv[f];
			FILE *infile = fopen(fname, "r");
			yyin = infile;
			lineno = 1;
			if(!yyin){
				printf("Error reading file %s\n", argv[f]);
				exit(1);
			}
			rv = yyparse();
			switch(rv){
				case 0 :
					printf("*** parse successful ***\n");
					//globalSymbolTable = (SymbolTable *)createGlobalSymbolTable(SYMBOL_TABLE_SIZE);
					//currentSymbolTable = globalSymbolTable;
					buildTypes(root);
					printf("*** build types successful ***\n");
					printTree(root, 0);
					printf("*** print tree successful ***\n");
					makeSymbolTables(root);
					break;
				case 1 :
					if(exitStatus < 2) exitStatus = 2;
					break;
			}
		}
	} else { //no files in arguments
		printf("Missing file name.\n");
		exit(4);
	}
	//printf("\n%d\n", exitStatus);
   return exitStatus;
}
