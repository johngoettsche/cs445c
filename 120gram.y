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

#include "errors.h"
#include "token.h"
#include "120parse.h"
#include "parsedef.h"

extern int lineno;
//extern Token *yytoken;
int yydebug=1;
FILE *yyin;
char *fname;
int errors;
ErrorMessage *e_message;
TreeNode *root;

TreeNode *alacnary(int, int,...);
char *humanreadable(int);

%}

%union{
	TreeNode *n;
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
	| template_id														{ $$ = (TreeNode *)alacnary(CLASS_NAMEr2, 1, $1); }
	;

enum_name:
	/* identifier */
	ENUM_NAME															{ $$ = (TreeNode *)alacnary(ENUM_NAMEr1, 1, $1); }
	;

template_name:
	/* identifier */
	TEMPLATE_NAME														{ $$ = (TreeNode *)alacnary(TEMPLATE_NAMEr1, 1, $1); }
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
	unqualified_id														{ $$ = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr1, 1, $1); }
	| qualified_id														{ $$ = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr2, 1, $1); }
	;

unqualified_id:
	identifier															{ $$ = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr1, 1, $1); }
	| operator_function_id											{ $$ = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr2, 1, $1); }
	| conversion_function_id										{ $$ = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr3, 1, $1); }
	| '~' class_name													{ $$ = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr4, 1, $2); }
	;

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
	  DELETE cast_expression										{ $$ = (TreeNode *)alacnary(DELETE_EXPRESSIONr1, 2, $1, $2); }
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
	equality_expression												{ $$ = alacnary(AND_EXPRESSIONr1, 1, $1); }
	| and_expression '&' equality_expression					{ $$ = alacnary(AND_EXPRESSIONr2, 2, $1, $3); }
	;

exclusive_or_expression:
	and_expression														{ $$ = alacnary(EXCLUSIVE_OR_EXPRESSIONr1, 1, $1); }
	| exclusive_or_expression '^' and_expression				{ $$ = alacnary(EXCLUSIVE_OR_EXPRESSIONr2, 2, $1, $3); }
	;

inclusive_or_expression:
	exclusive_or_expression											{ $$ = alacnary(INCLUSIVE_OR_EXPRESSIONr1, 1, $1); }
	| inclusive_or_expression '|' exclusive_or_expression	{ $$ = alacnary(INCLUSIVE_OR_EXPRESSIONr2, 2, $1, $3); }
	;

logical_and_expression:
	inclusive_or_expression											{ $$ = alacnary(LOGICAL_AND_EXPRESSIONr1, 1, $1); }
	| logical_and_expression ANDAND inclusive_or_expression
																			{ $$ = alacnary(LOGICAL_AND_EXPRESSIONr1, 3, $1, $2, $3); }
	;

logical_or_expression:
	logical_and_expression											{ $$ = alacnary(LOGICAL_OR_EXPRESSIONr1, 1, $1); }
	| logical_or_expression OROR logical_and_expression	{ $$ = alacnary(LOGICAL_OR_EXPRESSIONr2, 3, $1, $2, $3); }
	;

conditional_expression:
	logical_or_expression											{ $$ = alacnary(CONDITIONAL_EXPRESSIONr1, 1, $1); }
	| logical_or_expression  '?' expression ':' assignment_expression
																			{ $$ = alacnary(CONDITIONAL_EXPRESSIONr2, 3, $1, $3, $5); }
	;

assignment_expression:
	conditional_expression											{ $$ = alacnary(ASSIGNMENT_EXPRESSIONr1, 1, $1); }
	| logical_or_expression assignment_operator assignment_expression
																			{ $$ = alacnary(ASSIGNMENT_EXPRESSIONr2, 3, $1, $2, $3); }
	| throw_expression												{ $$ = alacnary(ASSIGNMENT_EXPRESSIONr3, 1, $1); }
	;

assignment_operator:
	'='																	{ $$ = alacnary(ASSIGNMENT_OPERATORr1, 0); }
	| MULEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr2, 1, $1); }
	| DIVEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr3, 1, $1); }
	| MODEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr4, 1, $1); }
	| ADDEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr5, 1, $1); }
	| SUBEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr6, 1, $1); }
	| SREQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr7, 1, $1); }
	| SLEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr8, 1, $1); }
	| ANDEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr9, 1, $1); }
	| XOREQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr10, 1, $1); }
	| OREQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr11, 1, $1); }
	;

expression:
	assignment_expression											{ $$ = alacnary(EXPRESSIONr1, 1, $1); }
	| expression ',' assignment_expression						{ $$ = alacnary(EXPRESSIONr2, 2, $1, $3); }
	;

constant_expression:
	conditional_expression											{ $$ = alacnary(CONSTANT_EXPRESSIONr1, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Statements.
 *----------------------------------------------------------------------*/

statement:
	labeled_statement													{ $$ = alacnary(STATEMENTr1, 1, $1); }
	| expression_statement											{ $$ = alacnary(STATEMENTr2, 1, $1); }
	| compound_statement												{ $$ = alacnary(STATEMENTr3, 1, $1); }
	| selection_statement											{ $$ = alacnary(STATEMENTr4, 1, $1); }
	| iteration_statement											{ $$ = alacnary(STATEMENTr5, 1, $1); }
	| jump_statement													{ $$ = alacnary(STATEMENTr6, 1, $1); }
	| declaration_statement											{ $$ = alacnary(STATEMENTr7, 1, $1); }
	| try_block															{ $$ = alacnary(STATEMENTr8, 1, $1); }
	;

labeled_statement:
	identifier ':' statement										{ $$ = alacnary(LABELED_STATEMENTr1, 2, $1, $3); }
	| CASE constant_expression ':' statement					{ $$ = alacnary(LABELED_STATEMENTr2, 3, $1, $2, $4); }
	| DEFAULT ':' statement											{ $$ = alacnary(LABELED_STATEMENTr3, 2, $1, $3); }
	;

expression_statement:
	expression_opt ';'												{ $$ = alacnary(EXPRESSION_STATEMENTr1, 1, $1); }
	;

compound_statement:
	'{' statement_seq_opt '}'										{ $$ = alacnary(COMPOUND_STATEMENTr1, 1, $2); }
	;

statement_seq:
	statement															{ $$ = alacnary(STATEMENT_SEQr1, 1, $1); }
	| statement_seq statement										{ $$ = alacnary(STATEMENT_SEQr2, 2, $1, $2); }
	;

selection_statement:
	IF '(' condition ')' statement								{ $$ = alacnary(SELECTION_STATEMENTr1, 3, $1, $3, $5); }
	| IF '(' condition ')' statement ELSE statement			{ $$ = alacnary(SELECTION_STATEMENTr2, 5, $1, $3, $5, $6, $7); }
	| SWITCH '(' condition ')' statement						{ $$ = alacnary(SELECTION_STATEMENTr3, 3, $1, $3, $5); }
	;

condition:
	expression															{ $$ = alacnary(CONDITIONr1, 1, $1); }
	| type_specifier_seq declarator '=' assignment_expression
																			{ $$ = alacnary(CONDITIONr2, 3, $1, $2, $4); }
	;

iteration_statement:
	WHILE '(' condition ')' statement							{ $$ = alacnary(ITERATION_STATEMENTr1, 3, $1, $3, $5); }
	| DO statement WHILE '(' expression ')' ';'				{ $$ = alacnary(ITERATION_STATEMENTr2, 4, $1, $2, $3, $5); }
	| FOR '(' for_init_statement condition_opt ';' expression_opt ')' statement
																			{ $$ = alacnary(ITERATION_STATEMENTr3, 5, $1, $3, $4, $6, $8); }
	;

for_init_statement:
	expression_statement												{ $$ = alacnary(FOR_INIT_STATEMENTr1, 1, $1); }
	| simple_declaration												{ $$ = alacnary(FOR_INIT_STATEMENTr2, 1, $1); }
	;

jump_statement:
	BREAK ';'															{ $$ = alacnary(JUMP_STATEMENTr1, 1, $1); }
	| CONTINUE ';'														{ $$ = alacnary(JUMP_STATEMENTr2, 1, $1); }
	| RETURN expression_opt ';'									{ $$ = alacnary(JUMP_STATEMENTr3, 2, $1, $2); }
	| GOTO identifier ';'											{ $$ = alacnary(JUMP_STATEMENTr4, 2, $1, $2); }
	;

declaration_statement:
	block_declaration													{ $$ = alacnary(DECLARATION_STATEMENTr1, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Declarations.
 *----------------------------------------------------------------------*/

declaration_seq:
	declaration															{ $$ = alacnary(DECLARATION_SEQr1, 1, $1); }
	| declaration_seq declaration									{ $$ = alacnary(DECLARATION_SEQr2, 2, $1, $2); }
	;

declaration:
	block_declaration													{ $$ = alacnary(DECLARATIONr1, 1, $1); }
	| function_definition											{ $$ = alacnary(DECLARATIONr2, 1, $1); }
	| template_declaration											{ $$ = alacnary(DECLARATIONr3, 1, $1); }
	| explicit_instantiation										{ $$ = alacnary(DECLARATIONr4, 1, $1); }
	| explicit_specialization										{ $$ = alacnary(DECLARATIONr5, 1, $1); }
	| linkage_specification											{ $$ = alacnary(DECLARATIONr6, 1, $1); }
	| namespace_definition											{ $$ = alacnary(DECLARATIONr7, 1, $1); }
	;

block_declaration:
	simple_declaration												{ $$ = alacnary(BLOCK_DECLARATIONr1, 1, $1); }
	| asm_definition													{ $$ = alacnary(BLOCK_DECLARATIONr2, 1, $1); }
	| namespace_alias_definition									{ $$ = alacnary(BLOCK_DECLARATIONr3, 1, $1); }
	| using_declaration												{ $$ = alacnary(BLOCK_DECLARATIONr4, 1, $1); }
	| using_directive													{ $$ = alacnary(BLOCK_DECLARATIONr5, 1, $1); }
	;

simple_declaration:
	decl_specifier_seq init_declarator_list ';'				{ $$ = alacnary(SIMPLE_DECLARATIONr1, 2, $1, $2); }
	|  decl_specifier_seq ';'										{ $$ = alacnary(SIMPLE_DECLARATIONr2, 1, $1); }
	;

decl_specifier:
	storage_class_specifier											{ $$ = alacnary(DECL_SPECIFIERr1, 1, $1); }
	| type_specifier													{ $$ = alacnary(DECL_SPECIFIERr2, 1, $1); }
	| function_specifier												{ $$ = alacnary(DECL_SPECIFIERr3, 1, $1); }
	| FRIEND																{ $$ = alacnary(DECL_SPECIFIERr4, 1, $1); }
	| TYPEDEF															{ $$ = alacnary(DECL_SPECIFIERr5, 1, $1); }
	;

decl_specifier_seq:
	decl_specifier														{ $$ = alacnary(DECL_SPECIFIER_SEQr1, 1, $1); }
	| decl_specifier_seq decl_specifier							{ $$ = alacnary(DECL_SPECIFIER_SEQr2, 2, $1, $2); }
	;

storage_class_specifier:
	AUTO																	{ $$ = alacnary(STORAGE_CLASS_SPECIFIERr1, 1, $1); }
	| REGISTER															{ $$ = alacnary(STORAGE_CLASS_SPECIFIERr2, 1, $1); }
	| STATIC																{ $$ = alacnary(STORAGE_CLASS_SPECIFIERr3, 1, $1); }
	| EXTERN																{ $$ = alacnary(STORAGE_CLASS_SPECIFIERr4, 1, $1); }
	| MUTABLE															{ $$ = alacnary(STORAGE_CLASS_SPECIFIERr5, 1, $1); }
	;

function_specifier:
	INLINE																{ $$ = alacnary(FUNCTION_SPECIFIERr1, 1, $1); }
	| VIRTUAL															{ $$ = alacnary(FUNCTION_SPECIFIERr2, 1, $1); }
	| EXPLICIT															{ $$ = alacnary(FUNCTION_SPECIFIERr3, 1, $1); }
	;

type_specifier:
	simple_type_specifier											{ $$ = alacnary(TYPE_SPECIFIERr1, 1, $1); }
	| class_specifier													{ $$ = alacnary(TYPE_SPECIFIERr2, 1, $1); }
	| enum_specifier													{ $$ = alacnary(TYPE_SPECIFIERr3, 1, $1); }
	| elaborated_type_specifier									{ $$ = alacnary(TYPE_SPECIFIERr4, 1, $1); }
	| cv_qualifier														{ $$ = alacnary(TYPE_SPECIFIERr5, 1, $1); }
	;

simple_type_specifier:
	type_name															{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr1, 1, $1); }
	| nested_name_specifier type_name							{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr2, 2, $1, $2); }
	| COLONCOLON nested_name_specifier_opt type_name		{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr3, 3, $1, $2, $3); }
	| CHAR																{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr4, 1, $1); }
	| WCHAR_T															{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr5, 1, $1); }
	| BOOL																{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr6, 1, $1); }
	| SHORT																{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr7, 1, $1); }
	| INT																	{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr8, 1, $1); }
	| LONG																{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr9, 1, $1); }
	| SIGNED																{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr10, 1, $1); }
	| UNSIGNED															{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr11, 1, $1); }
	| FLOAT																{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr12, 1, $1); }
	| DOUBLE																{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr13, 1, $1); }
	| VOID																{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr14, 1, $1); }
	| STR_TYPE															{ $$ = alacnary(SIMPLE_TYPE_SPECIFIERr15, 1, $1); }
	;

type_name:
	class_name															{ $$ = alacnary(TYPE_NAMEr1, 1, $1); }
	| enum_name															{ $$ = alacnary(TYPE_NAMEr2, 1, $1); }
	| typedef_name														{ $$ = alacnary(TYPE_NAMEr3, 1, $1); }
	;

elaborated_type_specifier:
	class_key COLONCOLON nested_name_specifier identifier	{ $$ = alacnary(ELABORATED_TYPE_SPECIFIERr1, 4, $1, $2, $3, $4); }
	| class_key COLONCOLON identifier							{ $$ = alacnary(ELABORATED_TYPE_SPECIFIERr2, 3, $1, $2, $3); }
	| ENUM COLONCOLON nested_name_specifier identifier		{ $$ = alacnary(ELABORATED_TYPE_SPECIFIERr3, 4, $1, $2, $3, $4); }
	| ENUM COLONCOLON identifier									{ $$ = alacnary(ELABORATED_TYPE_SPECIFIERr4, 3, $1, $2, $3); }
	| ENUM nested_name_specifier identifier					{ $$ = alacnary(ELABORATED_TYPE_SPECIFIERr5, 3, $1, $2, $3); }
	| TYPENAME COLONCOLON_opt nested_name_specifier identifier
																			{ $$ = alacnary(ELABORATED_TYPE_SPECIFIERr6, 4, $1, $2, $3, $4); }
	| TYPENAME COLONCOLON_opt nested_name_specifier identifier '<' template_argument_list '>'
																			{ $$ = alacnary(ELABORATED_TYPE_SPECIFIERr7, 5, $1, $2, $3, $4, $6); }
	;

/*
enum_name:
	identifier
	;
*/

enum_specifier:
	ENUM identifier '{' enumerator_list_opt '}'				{ $$ = alacnary(ENUM_SPECIFIERr1, 3, $1, $2, $4); }
	;

enumerator_list:
	enumerator_definition											{ $$ = alacnary(ENUMERATOR_LISTr1, 1, $1); }
	| enumerator_list ',' enumerator_definition				{ $$ = alacnary(ENUMERATOR_LISTr2, 2, $1, $3); }
	;

enumerator_definition:
	enumerator															{ $$ = alacnary(ENUMERATOR_DEFINITIONr1, 1, $1); }
	| enumerator '=' constant_expression						{ $$ = alacnary(ENUMERATOR_DEFINITIONr2, 2, $1, $3); }
	;

enumerator:
	identifier															{ $$ = alacnary(ENUMERATORr1, 1, $1); }
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
	named_namespace_definition										{ $$ = alacnary(NAMESPACE_DEFINITIONr1, 1, $1); }
	| unnamed_namespace_definition								{ $$ = alacnary(NAMESPACE_DEFINITIONr2, 1, $1); }
	;

named_namespace_definition:
	original_namespace_definition									{ $$ = alacnary(NAMED_NAMESPACE_DEFINITIONr1, 1, $1); }
	| extension_namespace_definition								{ $$ = alacnary(NAMED_NAMESPACE_DEFINITIONr2, 1, $1); }
	;

original_namespace_definition:
	NAMESPACE identifier '{' namespace_body '}'				{ $$ = alacnary(ORIGINAL_NAMESPACE_DEFINITIONr1, 3, $1, $2, $4); }
	;

extension_namespace_definition:
	NAMESPACE original_namespace_name '{' namespace_body '}'
																			{ $$ = alacnary(EXTENSION_NAMESPACE_DEFINITIONr1, 3, $1, $2, $4); }
	;

unnamed_namespace_definition:
	NAMESPACE '{' namespace_body '}'								{ $$ = alacnary(UNNAMED_NAMESPACE_DEFINITIONr1, 2, $1, $3); }
	;

namespace_body:
	declaration_seq_opt												{ $$ = alacnary(NAMESPACE_BODYr1, 1, $1); }
	;

/*
namespace_alias:
	identifier
	;
*/

namespace_alias_definition:
	NAMESPACE identifier '=' qualified_namespace_specifier ';'
																			{ $$ = alacnary(NAMESPACE_ALIAS_DEFINITIONr1, 3, $1, $2, $4); }
	;

qualified_namespace_specifier:
	COLONCOLON nested_name_specifier namespace_name			{ $$ = alacnary(QUALIFIED_NAMESPACE_SPECIFIERr1, 3, $1, $2, $3); }
	| COLONCOLON namespace_name									{ $$ = alacnary(QUALIFIED_NAMESPACE_SPECIFIERr2, 2, $1, $2); }
	| nested_name_specifier namespace_name						{ $$ = alacnary(QUALIFIED_NAMESPACE_SPECIFIERr3, 2, $1, $2); }
	| namespace_name													{ $$ = alacnary(QUALIFIED_NAMESPACE_SPECIFIERr4, 1, $1); }
	;

using_declaration:
	USING TYPENAME COLONCOLON nested_name_specifier unqualified_id ';'
																			{ $$ = alacnary(USING_DECLARATIONr1, 5, $1, $2, $3, $4, $5); }
	| USING TYPENAME nested_name_specifier unqualified_id ';'
																			{ $$ = alacnary(USING_DECLARATIONr2, 4, $1, $2, $3, $4); }
	| USING COLONCOLON nested_name_specifier unqualified_id ';'
																			{ $$ = alacnary(USING_DECLARATIONr3, 4, $1, $2, $3, $4); }
	| USING nested_name_specifier unqualified_id ';'		{ $$ = alacnary(USING_DECLARATIONr4, 3, $1, $2, $3); }
	| USING COLONCOLON unqualified_id ';'						{ $$ = alacnary(USING_DECLARATIONr5, 3, $1, $2, $3); }
	;

using_directive:
	USING NAMESPACE COLONCOLON nested_name_specifier namespace_name ';'
																			{ $$ = alacnary(USING_DIRECTIVEr1, 5, $1, $2, $3, $4, $5); }
	| USING NAMESPACE COLONCOLON namespace_name ';'			{ $$ = alacnary(USING_DIRECTIVEr2, 4, $1, $2, $3, $4); }
	| USING NAMESPACE nested_name_specifier namespace_name ';'
																			{ $$ = alacnary(USING_DIRECTIVEr3, 4, $1, $2, $3, $4); }
	| USING NAMESPACE namespace_name ';'						{ $$ = alacnary(USING_DIRECTIVEr4, 3, $1, $2, $3); }
	;

asm_definition:
	ASM '(' string_literal ')' ';'								{ $$ = alacnary(ASM_DEFINITIONr1, 2, $1, $3); }
	;

linkage_specification:
	EXTERN string_literal '{' declaration_seq_opt '}'		{ $$ = alacnary(LINKAGE_SPECIFICATIONr1, 3, $1, $2, $4); }
	| EXTERN string_literal declaration							{ $$ = alacnary(LINKAGE_SPECIFICATIONr2, 3, $1, $2, $3); }
	;

/*----------------------------------------------------------------------
 * Declarators.
 *----------------------------------------------------------------------*/

init_declarator_list:
	init_declarator													{ $$ = alacnary(INIT_DECLARATOR_LISTr1, 1, $1); }
	| init_declarator_list ',' init_declarator				{ $$ = alacnary(INIT_DECLARATOR_LISTr2, 2, $1, $3); }
	;

init_declarator:
	declarator initializer_opt										{ $$ = alacnary(INIT_DECLARATORr1, 1, $1); }
	;

declarator:
	direct_declarator													{ $$ = alacnary(DECLARATORr1, 1, $1); }
	| ptr_operator declarator										{ $$ = alacnary(DECLARATORr2, 2, $1, $2); }
	;

direct_declarator:
	declarator_id														{ $$ = alacnary(DIRECT_DECLARATORr1, 1, $1); }
	| direct_declarator '('parameter_declaration_clause ')' cv_qualifier_seq exception_specification
																			{ $$ = alacnary(DIRECT_DECLARATORr2, 4, $1, $3, $5, $6); }
	| direct_declarator '('parameter_declaration_clause ')' cv_qualifier_seq
																			{ $$ = alacnary(DIRECT_DECLARATORr3, 3, $1, $3, $5); }
	| direct_declarator '('parameter_declaration_clause ')' exception_specification
																			{ $$ = alacnary(DIRECT_DECLARATORr4, 3, $1, $3, $5); }
	| direct_declarator '('parameter_declaration_clause ')'
																			{ $$ = alacnary(DIRECT_DECLARATORr5, 2, $1, $3); }
	| direct_declarator '[' constant_expression_opt ']'	{ $$ = alacnary(DIRECT_DECLARATORr6, 2, $1, $3); }
	| '(' declarator ')'												{ $$ = alacnary(DIRECT_DECLARATORr7, 1, $2); }
	;

ptr_operator:
	'*'																	{ $$ = alacnary(PTR_OPERATORr1, 0); }
	| '*' cv_qualifier_seq											{ $$ = alacnary(PTR_OPERATORr2, 1, $2); }
	| '&'																	{ $$ = alacnary(PTR_OPERATORr3, 0); }
	| nested_name_specifier '*'									{ $$ = alacnary(PTR_OPERATORr4, 1, $1); }
	| nested_name_specifier '*' cv_qualifier_seq				{ $$ = alacnary(PTR_OPERATORr5, 2, $1, $3); }
	| COLONCOLON nested_name_specifier '*'						{ $$ = alacnary(PTR_OPERATORr6, 2, $1, $2); }
	| COLONCOLON nested_name_specifier '*' cv_qualifier_seq
																			{ $$ = alacnary(PTR_OPERATORr7, 3, $1, $2, $4); }
	;

cv_qualifier_seq:
	cv_qualifier														{ $$ = alacnary(CV_QUALIFIER_SEQr1, 1, $1); }
	| cv_qualifier cv_qualifier_seq								{ $$ = alacnary(CV_QUALIFIER_SEQr2, 2, $1, $2); }
	;

cv_qualifier:
	CONST																	{ $$ = alacnary(CV_QUALIFIERr1, 1, $1); }
	| VOLATILE															{ $$ = alacnary(CV_QUALIFIERr2, 1, $1); }
	;

declarator_id:
	id_expression														{ $$ = alacnary(DECLARATOR_IDr1, 1, $1); }
	| COLONCOLON id_expression										{ $$ = alacnary(DECLARATOR_IDr2, 2, $1, $2); }
	| COLONCOLON nested_name_specifier type_name				{ $$ = alacnary(DECLARATOR_IDr3, 3, $1, $2, $3); }
	| COLONCOLON type_name											{ $$ = alacnary(DECLARATOR_IDr4, 2, $1, $2); }
	;

type_id:
	type_specifier_seq abstract_declarator_opt				{ $$ = alacnary(TYPE_IDr1, 2, $1, $2); }
	;

type_specifier_seq:
	type_specifier type_specifier_seq_opt						{ $$ = alacnary(TYPE_SPECIFIER_SEQr1, 2, $1, $2); }
	;

abstract_declarator:
	ptr_operator abstract_declarator_opt						{ $$ = alacnary(ABSTRACT_DECLARATORr1, 2, $1, $2); }
	| direct_abstract_declarator									{ $$ = alacnary(ABSTRACT_DECLARATORr2, 1, $1); }
	;

direct_abstract_declarator:
	direct_abstract_declarator_opt '(' parameter_declaration_clause ')' cv_qualifier_seq exception_specification
																			{ $$ = alacnary(DIRECT_ABSTRACT_DECLARATORr1, 4, $1, $3, $5, $6); }
	| direct_abstract_declarator_opt '(' parameter_declaration_clause ')' cv_qualifier_seq
																			{ $$ = alacnary(DIRECT_ABSTRACT_DECLARATORr2, 3, $1, $3, $5); }
	| direct_abstract_declarator_opt '(' parameter_declaration_clause ')' exception_specification
																			{ $$ = alacnary(DIRECT_ABSTRACT_DECLARATORr3, 3, $1, $3, $5); }
	| direct_abstract_declarator_opt '(' parameter_declaration_clause ')'
																			{ $$ = alacnary(DIRECT_ABSTRACT_DECLARATORr4, 2, $1, $3); }
	| direct_abstract_declarator_opt '[' constant_expression_opt ']'
																			{ $$ = alacnary(DIRECT_ABSTRACT_DECLARATORr5, 2, $1, $3); }
	| '(' abstract_declarator ')'									{ $$ = alacnary(DIRECT_ABSTRACT_DECLARATORr6, 1, $2); }																		
	;

parameter_declaration_clause:
	parameter_declaration_list ELLIPSIS							{ $$ = alacnary(PARAMETER_DECLARATION_CLAUSEr1, 2, $1, $2); }
	| parameter_declaration_list									{ $$ = alacnary(PARAMETER_DECLARATION_CLAUSEr2, 1, $1); }
	| ELLIPSIS															{ $$ = alacnary(PARAMETER_DECLARATION_CLAUSEr3, 1, $1); }
	| /* epsilon */													{ $$ = alacnary(PARAMETER_DECLARATION_CLAUSEr4, 0); }
	| parameter_declaration_list ',' ELLIPSIS					{ $$ = alacnary(PARAMETER_DECLARATION_CLAUSEr5, 2, $1, $3); }
	;

parameter_declaration_list:
	parameter_declaration											{ $$ = alacnary(PARAMETER_DECLARATION_LISTr1, 1, $1); }
	| parameter_declaration_list ',' parameter_declaration
																			{ $$ = alacnary(PARAMETER_DECLARATION_LISTr2, 2, $1, $3); }
	;

parameter_declaration:
	decl_specifier_seq declarator									{ $$ = alacnary(PARAMETER_DECLARATIONr1, 2, $1, $2); }
	| decl_specifier_seq declarator '=' assignment_expression
																			{ $$ = alacnary(PARAMETER_DECLARATIONr2, 3, $1, $2, $4); }
	| decl_specifier_seq abstract_declarator_opt				{ $$ = alacnary(PARAMETER_DECLARATIONr3, 2, $1, $2); }
	| decl_specifier_seq abstract_declarator_opt '=' assignment_expression
																			{ $$ = alacnary(PARAMETER_DECLARATIONr4, 3, $1, $2, $4); }
	;

function_definition:
	declarator ctor_initializer_opt function_body			{ $$ = alacnary(FUNCTION_DEFINITIONr1, 3, $1, $2, $3); }
	| decl_specifier_seq declarator ctor_initializer_opt function_body
																			{ $$ = alacnary(FUNCTION_DEFINITIONr2, 4, $1, $2, $3, $4); }
	| declarator function_try_block								{ $$ = alacnary(FUNCTION_DEFINITIONr3, 2, $1, $2); }
	| decl_specifier_seq declarator function_try_block		{ $$ = alacnary(FUNCTION_DEFINITIONr4, 3, $1, $2, $3); }
	;

function_body:
	compound_statement												{ $$ = alacnary(FUNCTION_BODYr1, 1, $1); }
	;

initializer:
	'=' initializer_clause											{ $$ = alacnary(INITIALIZERr1, 1, $2); }
	| '(' expression_list ')'										{ $$ = alacnary(INITIALIZERr2, 1, $2); }
	;

initializer_clause:
	assignment_expression											{ $$ = alacnary(INITIALIZER_CLAUSEr1, 1, $1); }
	| '{' initializer_list COMMA_opt '}'						{ $$ = alacnary(INITIALIZER_CLAUSEr2, 2, $2, $3); }
	| '{' '}'															{ $$ = alacnary(INITIALIZER_CLAUSEr3, 0); }
	;

initializer_list:
	initializer_clause												{ $$ = alacnary(INITIALIZER_LISTr1, 1, $1); }
	| initializer_list ',' initializer_clause					{ $$ = alacnary(INITIALIZER_LISTr1, 2, $1, $3); }
	;

/*----------------------------------------------------------------------
 * Classes.
 *----------------------------------------------------------------------*/

class_specifier:
	class_head '{' member_specification_opt '}'				{ $$ = alacnary(CLASS_SPECIFIERr1, 2, $1, $3); }
	;

class_head:
	class_key identifier												{ $$ = alacnary(CLASS_HEADr1, 2, $1, $2); }
	| class_key identifier base_clause							{ $$ = alacnary(CLASS_HEADr2, 3, $1, $2, $3); }
	| class_key nested_name_specifier identifier				{ $$ = alacnary(CLASS_HEADr3, 3, $1, $2, $3); }
	| class_key nested_name_specifier identifier base_clause
																			{ $$ = alacnary(CLASS_HEADr4, 4, $1, $2, $3, $4); }
	;

class_key:
	CLASS																	{ $$ = alacnary(CLASS_KEYr1, 1, $1); }
	| STRUCT																{ $$ = alacnary(CLASS_KEYr2, 1, $1); }
	| UNION																{ $$ = alacnary(CLASS_KEYr3, 1, $1); }
	;

member_specification:
	member_declaration member_specification_opt				{ $$ = alacnary(MEMBER_SPECIFICATIONr1, 2, $1, $2); }
	| access_specifier ':' member_specification_opt			{ $$ = alacnary(MEMBER_SPECIFICATIONr2, 2, $1, $3); }
	;

member_declaration:
	decl_specifier_seq member_declarator_list ';'			{ $$ = alacnary(MEMBER_DECLARATIONr1, 2, $1, $2); }
	| decl_specifier_seq ';'										{ $$ = alacnary(MEMBER_DECLARATIONr2, 1, $1); }
	| member_declarator_list ';'									{ $$ = alacnary(MEMBER_DECLARATIONr3, 1, $1); }
	| ';'																	{ $$ = alacnary(MEMBER_DECLARATIONr4, 0); }
	| function_definition SEMICOLON_opt							{ $$ = alacnary(MEMBER_DECLARATIONr5, 2, $1, $2); }
	| qualified_id ';'												{ $$ = alacnary(MEMBER_DECLARATIONr6, 1, $1); }
	| using_declaration												{ $$ = alacnary(MEMBER_DECLARATIONr7, 1, $1); }
	| template_declaration											{ $$ = alacnary(MEMBER_DECLARATIONr8, 1, $1); }
	;

member_declarator_list:
	member_declarator													{ $$ = alacnary(MEMBER_DECLARATOR_LISTr1, 1, $1); }
	| member_declarator_list ',' member_declarator			{ $$ = alacnary(MEMBER_DECLARATOR_LISTr1, 2, $1, $3); }
	;

member_declarator:
	declarator															{ $$ = alacnary(MEMBER_DECLARATORr1, 1, $1); }
	| declarator pure_specifier									{ $$ = alacnary(MEMBER_DECLARATORr2, 2, $1, $2); }
	| declarator constant_initializer							{ $$ = alacnary(MEMBER_DECLARATORr3, 2, $1, $2); }
	| identifier ':' constant_expression						{ $$ = alacnary(MEMBER_DECLARATORr4, 2, $1, $3); }
	;

/*
 * This rule need a hack for working around the ``= 0'' pure specifier.
 * 0 is returned as an ``INTEGER'' by the lexical analyzer but in this
 * context is different.
 */
pure_specifier:
	'=' '0'															{ $$ = alacnary(PURE_SPECIFIERr1, 0); }
	;

constant_initializer:
	'=' constant_expression										{ $$ = alacnary(CONSTANT_INITIALIZERr1, 1, $2); }
	;

/*----------------------------------------------------------------------
 * Derived classes.
 *----------------------------------------------------------------------*/

base_clause:
	':' base_specifier_list										{ $$ = alacnary(BASE_CLAUSEr1, 1, $2); }
	;

base_specifier_list:
	base_specifier													{ $$ = alacnary(BASE_SPECIFIER_LISTr1, 1, $1); }
	| base_specifier_list ',' base_specifier				{ $$ = alacnary(BASE_SPECIFIER_LISTr2, 2, $1, $3); }
	;

base_specifier:
	COLONCOLON nested_name_specifier class_name			{ $$ = alacnary(BASE_SPECIFIERr1, 3, $1, $2, $3); }
	| COLONCOLON class_name										{ $$ = alacnary(BASE_SPECIFIERr2, 2, $1, $2); }
	| nested_name_specifier class_name						{ $$ = alacnary(BASE_SPECIFIERr3, 2, $1, $2); }
	| class_name													{ $$ = alacnary(BASE_SPECIFIERr4, 1, $1); }
	| VIRTUAL access_specifier COLONCOLON nested_name_specifier_opt class_name
																		{ $$ = alacnary(BASE_SPECIFIERr5, 5, $1, $2, $3, $4, $5); }
	| VIRTUAL access_specifier nested_name_specifier_opt class_name
																		{ $$ = alacnary(BASE_SPECIFIERr6, 4, $1, $2, $3, $4); }
	| VIRTUAL COLONCOLON nested_name_specifier_opt class_name
																		{ $$ = alacnary(BASE_SPECIFIERr7, 4, $1, $2, $3, $4); }
	| VIRTUAL nested_name_specifier_opt class_name		{ $$ = alacnary(BASE_SPECIFIERr8, 3, $1, $2, $3); }
	| access_specifier VIRTUAL COLONCOLON nested_name_specifier_opt class_name
																		{ $$ = alacnary(BASE_SPECIFIERr9, 5, $1, $2, $3, $4, $5); }
	| access_specifier VIRTUAL nested_name_specifier_opt class_name
																		{ $$ = alacnary(BASE_SPECIFIERr10, 4, $1, $2, $3, $4); }
	| access_specifier COLONCOLON nested_name_specifier_opt class_name
																		{ $$ = alacnary(BASE_SPECIFIERr11, 4, $1, $2, $3, $4); }
	| access_specifier nested_name_specifier_opt class_name
																		{ $$ = alacnary(BASE_SPECIFIERr12, 3, $1, $2, $3); }
	;

access_specifier:
	PRIVATE															{ $$ = alacnary(ACCESS_SPECIFIERr1, 1, $1); }
	| PROTECTED														{ $$ = alacnary(ACCESS_SPECIFIERr2, 1, $1); }
	| PUBLIC															{ $$ = alacnary(ACCESS_SPECIFIERr3, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Special member functions.
 *----------------------------------------------------------------------*/

conversion_function_id:
	OPERATOR conversion_type_id								{ $$ = alacnary(CONVERSION_FUNCTION_IDr1, 2, $1, $2); }
	;

conversion_type_id:
	type_specifier_seq conversion_declarator_opt			{ $$ = alacnary(CONVERSION_TYPE_IDr1, 2, $1, $2); }
	;

conversion_declarator:
	ptr_operator conversion_declarator_opt					{ $$ = alacnary(CONVERSION_DECLARATORr1, 2, $1, $2); }
	;

ctor_initializer:
	':' mem_initializer_list									{ $$ = alacnary(CTOR_INITIALIZERr1, 1, $2); }
	;

mem_initializer_list:
	mem_initializer												{ $$ = alacnary(MEM_INITIALIZER_LISTr1, 1, $1); }
	| mem_initializer ',' mem_initializer_list			{ $$ = alacnary(MEM_INITIALIZER_LISTr1, 2, $1, $3); }
	;

mem_initializer:
	mem_initializer_id '(' expression_list_opt ')'		{ $$ = alacnary(MEM_INITIALIZERr1, 2, $1, $3); }
	;

mem_initializer_id:
	COLONCOLON nested_name_specifier class_name			{ $$ = alacnary(MEM_INITIALIZER_IDr1, 3, $1, $2, $3); }
	| COLONCOLON class_name										{ $$ = alacnary(MEM_INITIALIZER_IDr2, 2, $1, $2); }
	| nested_name_specifier class_name						{ $$ = alacnary(MEM_INITIALIZER_IDr3, 2, $1, $2); }
	| class_name													{ $$ = alacnary(MEM_INITIALIZER_IDr4, 1, $1); }
	| identifier													{ $$ = alacnary(MEM_INITIALIZER_IDr5, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Overloading.
 *----------------------------------------------------------------------*/

operator_function_id:
	OPERATOR operator												{ $$ = alacnary(OPERATOR_FUNCTION_IDr1, 2, $1, $2); }
	;

operator:
	NEW																{ $$ = alacnary(OPERATORr1, 1, $1); }
	| DELETE															{ $$ = alacnary(OPERATORr2, 1, $1); }
	| NEW '[' ']'													{ $$ = alacnary(OPERATORr3, 1, $1); }
	| DELETE '[' ']'												{ $$ = alacnary(OPERATORr4, 1, $1); }
	| '+'																{ $$ = alacnary(OPERATORr5, 0); }
	| '_'																{ $$ = alacnary(OPERATORr6, 0); }
	| '*'																{ $$ = alacnary(OPERATORr7, 0); }
	| '/'																{ $$ = alacnary(OPERATORr8, 0); }
	| '%'																{ $$ = alacnary(OPERATORr9, 0); }
	| '^'																{ $$ = alacnary(OPERATORr10, 0); }
	| '&'																{ $$ = alacnary(OPERATORr11, 0); }
	| '|'																{ $$ = alacnary(OPERATORr12, 0); }
	| '~'																{ $$ = alacnary(OPERATORr13, 0); }
	| '!'																{ $$ = alacnary(OPERATORr14, 0); }
	| '='																{ $$ = alacnary(OPERATORr15, 0); }
	| '<'																{ $$ = alacnary(OPERATORr16, 0); }
	| '>'																{ $$ = alacnary(OPERATORr17, 0); }
	| ADDEQ															{ $$ = alacnary(OPERATORr18, 1, $1); }	
	| SUBEQ															{ $$ = alacnary(OPERATORr19, 1, $1); }
	| MULEQ															{ $$ = alacnary(OPERATORr20, 1, $1); }
	| DIVEQ															{ $$ = alacnary(OPERATORr21, 1, $1); }
	| MODEQ															{ $$ = alacnary(OPERATORr22, 1, $1); }
	| XOREQ															{ $$ = alacnary(OPERATORr23, 1, $1); }
	| ANDEQ															{ $$ = alacnary(OPERATORr24, 1, $1); }
	| OREQ															{ $$ = alacnary(OPERATORr25, 1, $1); }
	| SL																{ $$ = alacnary(OPERATORr26, 1, $1); }
	| SR																{ $$ = alacnary(OPERATORr27, 1, $1); }
	| SREQ															{ $$ = alacnary(OPERATORr28, 1, $1); }
	| SLEQ															{ $$ = alacnary(OPERATORr29, 1, $1); }
	| EQ																{ $$ = alacnary(OPERATORr30, 1, $1); }
	| NOTEQ															{ $$ = alacnary(OPERATORr31, 1, $1); }
	| LTEQ															{ $$ = alacnary(OPERATORr32, 1, $1); }
	| GTEQ															{ $$ = alacnary(OPERATORr33, 1, $1); }
	| ANDAND															{ $$ = alacnary(OPERATORr34, 1, $1); }
	| OROR															{ $$ = alacnary(OPERATORr35, 1, $1); }
	| PLUSPLUS														{ $$ = alacnary(OPERATORr36, 1, $1); }
	| MINUSMINUS													{ $$ = alacnary(OPERATORr37, 1, $1); }
	| ','																{ $$ = alacnary(OPERATORr38, 0); }
	| ARROWSTAR														{ $$ = alacnary(OPERATORr39, 1, $1); }
	| ARROW															{ $$ = alacnary(OPERATORr40, 1, $1); }
	| '(' ')'														{ $$ = alacnary(OPERATORr41, 0); }
	| '[' ']'														{ $$ = alacnary(OPERATORr42, 0); }
	;

/*----------------------------------------------------------------------
 * Templates.
 *----------------------------------------------------------------------*/

template_declaration:
	EXPORT_opt TEMPLATE '<' template_parameter_list '>' declaration
																		{ $$ = alacnary(TEMPLATE_DECLARATIONr1, 4, $1, $2, $4, $6); }
	;

template_parameter_list:
	template_parameter											{ $$ = alacnary(TEMPLATE_PARAMETER_LISTr1, 1, $1); }
	| template_parameter_list ',' template_parameter	{ $$ = alacnary(TEMPLATE_PARAMETER_LISTr2, 2, $1, $3); }
	;

template_parameter:
	type_parameter													{ $$ = alacnary(TEMPLATE_PARAMETERr1, 1, $1); }
	| parameter_declaration										{ $$ = alacnary(TEMPLATE_PARAMETERr2, 1, $1); }
	;

type_parameter:
	CLASS identifier												{ $$ = alacnary(TYPE_PARAMETERr1, 2, $1, $2); }
	| CLASS identifier '=' type_id							{ $$ = alacnary(TYPE_PARAMETERr2, 3, $1, $2, $4); }
	| TYPENAME identifier										{ $$ = alacnary(TYPE_PARAMETERr3, 2, $1, $2); }
	| TYPENAME identifier '=' type_id						{ $$ = alacnary(TYPE_PARAMETERr4, 3, $1, $2, $4); }
	| TEMPLATE '<' template_parameter_list '>' CLASS identifier
																		{ $$ = alacnary(TYPE_PARAMETERr5, 4, $1, $3, $5, $6); }
	| TEMPLATE '<' template_parameter_list '>' CLASS identifier '=' template_name
																		{ $$ = alacnary(TYPE_PARAMETERr6, 5, $1, $3, $5, $6, $8); }
	;

template_id:
	template_name '<' template_argument_list '>'			{ $$ = alacnary(TEMPLATE_IDr1, 2, $1, $3); }
	;

template_argument_list:
	template_argument												{ $$ = alacnary(TEMPLATE_ARGUMENT_LISTr1, 1, $1); }
	| template_argument_list ',' template_argument		{ $$ = alacnary(TEMPLATE_ARGUMENT_LISTr2, 2, $1, $3); }
	;

template_argument:
	assignment_expression										{ $$ = alacnary(TEMPLATE_ARGUMENTr1, 1, $1); }
	| type_id														{ $$ = alacnary(TEMPLATE_ARGUMENTr2, 1, $1); }
	| template_name												{ $$ = alacnary(TEMPLATE_ARGUMENTr3, 1, $1); }
	;

explicit_instantiation:
	TEMPLATE declaration											{ $$ = alacnary(EXPLICIT_INSTANTIATIONr1, 2, $1, $2); }
	;

explicit_specialization:
	TEMPLATE '<' '>' declaration								{ $$ = alacnary(EXPLICIT_SPECIALIZATIONr1, 2, $1, $4); }
	;

/*----------------------------------------------------------------------
 * Exception handling.
 *----------------------------------------------------------------------*/

try_block:
	TRY compound_statement handler_seq						{ $$ = alacnary(TRY_BLOCKr1, 3, $1, $2, $3); }
	;

function_try_block:
	TRY ctor_initializer_opt function_body handler_seq	{ $$ = alacnary(FUNCTION_TRY_BLOCKr1, 3, $1, $2, $3); }
	;

handler_seq:
	handler handler_seq_opt										{ $$ = alacnary(HANDLER_SEQr1, 2, $1, $2); }
	;

handler:
	CATCH '(' exception_declaration ')' compound_statement
																		{ $$ = alacnary(HANDLERr1, 3, $1, $3, $5); }
	;

exception_declaration:
	type_specifier_seq declarator								{ $$ = alacnary(EXCEPTION_DECLARATIONr1, 2, $1, $2); }
	| type_specifier_seq abstract_declarator				{ $$ = alacnary(EXCEPTION_DECLARATIONr2, 2, $1, $2); }
	| type_specifier_seq											{ $$ = alacnary(EXCEPTION_DECLARATIONr3, 1, $1); }
	| ELLIPSIS														{ $$ = alacnary(EXCEPTION_DECLARATIONr4, 1, $1); }
	;

throw_expression:
	THROW assignment_expression_opt							{ $$ = alacnary(THROW_EXPRESSIONr1, 2, $1, $2); }
	;

exception_specification:
	THROW '(' type_id_list_opt ')'							{ $$ = alacnary(EXCEPTION_SPECIFICATIONr1, 2, $1, $3); }
	;

type_id_list:
	type_id															{ $$ = alacnary(TYPE_ID_LISTr1, 1, $1); }
	| type_id_list ',' type_id									{ $$ = alacnary(TYPE_ID_LISTr2, 2, $1, $3); }
	;

/*----------------------------------------------------------------------
 * Epsilon (optional) definitions.
 *----------------------------------------------------------------------*/

declaration_seq_opt:
	/* epsilon */													{ $$ = alacnary(DECLARATION_SEQ_OPTr1, 0); }
	| declaration_seq												{ $$ = alacnary(DECLARATION_SEQ_OPTr2, 1, $1); }
	;

nested_name_specifier_opt:
	/* epsilon */													{ $$ = alacnary(NESTED_NAME_SPECIFIER_OPTr1, 0); }
	| nested_name_specifier										{ $$ = alacnary(NESTED_NAME_SPECIFIER_OPTr2, 1, $1); }
	;

expression_list_opt:
	/* epsilon */													{ $$ = alacnary(EXPRESSION_LIST_OPTr1, 0); }
	| expression_list												{ $$ = alacnary(EXPRESSION_LIST_OPTr2, 1, $1); }
	;

COLONCOLON_opt:
	/* epsilon */													{ $$ = alacnary(COLONCOLON_OPTr1, 0); }
	| COLONCOLON													{ $$ = alacnary(COLONCOLON_OPTr2, 1, $1); }
	;

new_placement_opt:
	/* epsilon */													{ $$ = alacnary(NEW_PLACEMENT_OPTr1, 0); }
	| new_placement												{ $$ = alacnary(NEW_PLACEMENT_OPTr2, 1, $1); }
	;

new_initializer_opt:
	/* epsilon */													{ $$ = alacnary(NEW_INITIALIZER_OPTr1, 0); }
	| new_initializer												{ $$ = alacnary(NEW_INITIALIZER_OPTr2, 1, $1); }
	;

new_declarator_opt:
	/* epsilon */													{ $$ = alacnary(NEW_DECLARATOR_OPTr1, 0); }
	| new_declarator												{ $$ = alacnary(NEW_DECLARATOR_OPTr2, 1, $1); }
	;

expression_opt:
	/* epsilon */													{ $$ = alacnary(EXPRESSION_OPTr1, 0); }
	| expression													{ $$ = alacnary(EXPRESSION_OPTr2, 1, $1); }
	;

statement_seq_opt:
	/* epsilon */													{ $$ = alacnary(STATEMENT_SEQ_OPTr1, 0); }
	| statement_seq												{ $$ = alacnary(STATEMENT_SEQ_OPTr2, 1, $1); }
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

void memoryError(){
	getErrorMessage(ER_MALLOC_E);
	yyerror(NULL);
	exit(1);
}

void getErrorMessage(int ecode){
   int size = 1024;
   int code;
	char *line = (char *)calloc(size, sizeof(char));
	char *ertype = (char *)calloc(size, sizeof(char));
	char *mes = (char *)calloc(size, sizeof(char));
	e_message = (ErrorMessage *)calloc(1, sizeof(ErrorMessage));
	if(e_message == NULL || line == NULL || ertype == NULL || mes == NULL) memoryError();
	ef = fopen("errors.def", "r");
	while(fgets(line, size, ef)){
		code = atoi(line);
		fgets(ertype, size, ef);
		fgets(mes, size, ef);
		if(code == ecode){
			char *t = (char *)calloc(size, sizeof(char));
			char *m = (char *)calloc(size, sizeof(char));
			if(t == NULL || m == NULL) memoryError();
			strcpy(t, ertype);
			strcpy(m, mes);
			e_message->number = code;
			e_message->errorType = t;
			e_message->message = m;
		}
	}
	close(ef);
}

void yyerror(char *s)
{
   errors++;
   fprintf(stderr, "\nError #%d: %s, line: %d ", errors, fname, lineno);
	if(e_message){
		if(s != NULL) fprintf(stderr, "%s\t\'%s\' %s\n",e_message->errorType, s, e_message->message);
		else fprintf(stderr, "%s\t%s\n",e_message->errorType, e_message->message);
	} else {fprintf(stderr, "\n");}
	fflush(stderr);
}

/*
 * creates a token with its attributes
 */
 
Token *createToken(int tcode){
	Token *token = (Token *)calloc(1, sizeof(Token));
	if(token == NULL)memoryError();
	
	int length = strlen(yytext) + 1;
	char *text = (char *)calloc(length, sizeof(char));
	if(text == NULL) memoryError();
   strcpy(text, yytext); 
	token->category = tcode;
   token->text = text;
   token->lineno = lineno;
	
	char *filename = (char *)calloc(strlen(fname) + 1, sizeof(char));
	if(filename == NULL) memoryError();
	strcpy(filename, fname);
   token->filename =filename;
	
	if(tcode == INTEGER) token->ival = atoi(token->text);
//	else token->ival = NULL;
   if(tcode == STRING){
      token->ival = length;
      int *st = (int *)calloc(length, sizeof(int));
		if(st == NULL) memoryError();
      int i;
      for(i = 0; i < length; i++) st[i] = (int)text[i];
      token->sval = st;
   }
	else token->sval = NULL;
	
	return token;
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

void printTree(struct TreeNode *t, int depth)
{
	char *text;
	int i;
	if(t->symbol >= 1000){
		printf("%*s %d: %d\n", depth*2, " ", t->u.n.rule, t->u.n.children);
		if(t->u.n.children > 0)
			for(i=0; i<t->u.n.children; i++)
				printTree(t->u.n.child[i], depth+1);
	} else {
		printf("%d\n", t->symbol);
		printf("%*s %d\n", depth*2, " ", humanreadable(t->symbol));
	}
}

char *humanreadable(int ncode){
	printf("%d\n", ncode);
	switch (ncode) {
		case IDENTIFIER: printf("IDENTIFIER\n"); return "IDENTIFIER";
		case INTEGER: return "INTEGER";
		case FLOATING: return "FLOATING";
		case CHARACTER: return "CHARACTER";
		case STRING: return "STRING";
		case TYPEDEF_NAME: return "TYPEDEF_NAME";
		case NAMESPACE_NAME: return "NAMESPACE_NAME";
		case CLASS_NAME: return "CLASS_NAME";
		case ENUM_NAME: return "ENUM_NAME";
		case TEMPLATE_NAME: return "TEMPLATE_NAME";
		case ELLIPSIS: return "ELLIPSIS";
		case COLONCOLON: return "COLONCOLON"; 
		case DOTSTAR: return "DOTSTAR"; 
		case ADDEQ: return "ADDEQ"; 
		case SUBEQ: return "SUBEQ"; 
		case MULEQ: return "MULEQ"; 
		case DIVEQ: return "DIVEQ"; 
		case MODEQ: return "MODEQ";
		case XOREQ: return "XOREQ"; 
		case ANDEQ: return "ANDEQ";  
		case OREQ: return "OREQ"; 
		case SL: return "SL"; 
		case SR: return "SR"; 
		case SREQ: return "SLEQ"; 
		case SLEQ: return "SLEQ";
		case EQ: return "EQ";
		case NOTEQ  : return "NOTEQ";
		case LTEQ  : return "LTEQ";
		case GTEQ  : return "GTEQ";
		case ANDAND  : return "ANDAND";
		case OROR : return "OROR" ;
		case PLUSPLUS  : return "PLUSPLUS";
		case MINUSMINUS  : return "MINUSMINUS"  ;
		case ARROWSTAR  : return "ARROWSTAR"  ;
		case ARROW : return "ARROW" ;
		case ASM  : return "ASM"  ;
		case AUTO  : return "AUTO"  ;
		case BOOL  : return "BOOL"  ;
		case BREAK  : return "BREAK"  ;
		case CASE  : return "CASE"  ;
		case CATCH  : return "CATCH"  ;
		case CHAR  : return "CHAR"  ;
		case CLASS  : return "CLASS"  ;
		case CONST  : return "CONST"  ;
		case CONST_CAST  : return "CONST_CAST"  ;
		case CONTINUE : return "CONTINUE" ;
		case DEFAULT  : return "DEFAULT"  ;
		case DELETE  : return "DELETE"  ;
		case DO  : return "DO"  ;
		case DOUBLE  : return "DOUBLE"  ;
		case DYNAMIC_CAST  : return "DYNAMIC_CAST"  ;
		case ELSE  : return "ELSE"  ;
		case ENUM  : return "ENUM"  ;
		case EXPLICIT  : return "EXPLICIT"  ;
		case EXPORT  : return "EXPORT"  ;
		case EXTERN : return "EXTERN" ;
		case FALSE : return "FALSE" ;
		case FLOAT  : return "FLOAT"  ;
		case FOR  : return "FOR"  ;
		case FRIEND  : return "FRIEND"  ;
		case GOTO  : return "GOTO"  ;
		case IF  : return "IF"  ;
		case INLINE  : return "INLINE"  ;
		case INT  : return "INT"  ;
		case LONG  : return "LONG"  ;
		case MUTABLE  : return "MUTABLE"  ;
		case NAMESPACE  : return "NAMESPACE"  ;
		case NEW : return "NEW" ;
		case OPERATOR  : return "OPERATOR"  ;
		case PRIVATE  : return "PRIVATE"  ;
		case PROTECTED  : return "PROTECTED"  ;
		case PUBLIC  : return "PUBLIC"  ;
		case REGISTER  : return "REGISTER"  ;
		case REINTERPRET_CAST  : return "REINTERPRET_CAST"  ;
		case RETURN : return "RETURN" ;
		case SHORT  : return "SHORT"  ;
		case SIGNED  : return "SIGNED"  ;
		case SIZEOF  : return "SIZEOF"  ;
		case STATIC  : return "STATIC"  ;
		case STATIC_CAST  : return "STATIC_CAST"  ;
		case STRUCT  : return "STRUCT"  ;
		case SWITCH  : return "SWITCH"  ;
		case TEMPLATE  : return "TEMPLATE"  ;
		case THIS : return "THIS" ;
		case THROW  : return "THROW"  ;
		case TRUE : return "TRUE" ;
		case TRY  : return "TRY"  ;
		case TYPEDEF  : return "TYPEDEF"  ;
		case TYPEID  : return "TYPEID"  ;
		case TYPENAME  : return "TYPENAME"  ;
		case UNION  : return "UNION"  ;
		case UNSIGNED  : return "UNSIGNED"  ;
		case USING  : return "USING"  ;
		case VIRTUAL : return "VIRTUAL" ;
		case VOID  : return "VOID"  ;
		case VOLATILE  : return "VOLATILE"  ;
		case WCHAR_T  : return "WCHAR_T"  ;
		case WHILE  : return "WHILE"  ;
		case STR_TYPE : return "STR_TYPE" ;

/*
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
*/
	}
}



int main(int argc, char **argv){
	int rv;
   if(argc > 1) { 
		int f;
		//read each file in arguments
		for(f = 1; f < argc; f++) {
			fname = argv[f];
			FILE *infile = fopen(fname, "r");
			yyin = infile;
			lineno = 0;
			if(!yyin){
				printf("Error reading file %s\n", argv[f]);
				exit(1);
			}
			rv = yyparse();
			printTree(root, 0);
		}
	} else { //no files in arguments
		printf("Missing file name.\n");
		exit(1);
	}
   return 0;
}
