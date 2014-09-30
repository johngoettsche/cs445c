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
extern Token *yytoken;
int yydebug=1;
FILE *yyin;
char *fname;
int errors;
ErrorMessage *e_message;

//static void yyerror(char *s);
%}

%union{
	Token *t;
	struct TreeNode *n;
}

%token <t> IDENTIFIER INTEGER FLOATING CHARACTER STRING
%token <t> TYPEDEF_NAME NAMESPACE_NAME CLASS_NAME ENUM_NAME TEMPLATE_NAME

%token <t> ELLIPSIS COLONCOLON DOTSTAR ADDEQ SUBEQ MULEQ DIVEQ MODEQ
%token <t> XOREQ ANDEQ OREQ SL SR SREQ SLEQ EQ NOTEQ LTEQ GTEQ ANDAND OROR
%token <t> PLUSPLUS MINUSMINUS ARROWSTAR ARROW

%token <t> ASM AUTO BOOL BREAK CASE CATCH CHAR CLASS CONST CONST_CAST CONTINUE
%token <t> DEFAULT DELETE DO DOUBLE DYNAMIC_CAST ELSE ENUM EXPLICIT EXPORT EXTERN
%token <t> FALSE FLOAT FOR FRIEND GOTO IF INLINE INT LONG MUTABLE NAMESPACE NEW
%token <t> OPERATOR PRIVATE PROTECTED PUBLIC REGISTER REINTERPRET_CAST RETURN
%token <t> SHORT SIGNED SIZEOF STATIC STATIC_CAST STRUCT SWITCH TEMPLATE THIS
%token <t> THROW TRUE TRY TYPEDEF TYPEID TYPENAME UNION UNSIGNED USING VIRTUAL
%token <t> VOID VOLATILE WCHAR_T WHILE STR_TYPE

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
%start translation_unit

%%

/*----------------------------------------------------------------------
 * Context-dependent identifiers.
 *----------------------------------------------------------------------*/

typedef_name:
	/* identifier */
	TYPEDEF_NAME														{ $$ = alacnary(TYPEDEF_NAMEr1, 1, $1); }
	;

namespace_name:
	original_namespace_name											{ $$ = alacnary(NAMESPACE_NAMEr1, 1, $1); }
	;

original_namespace_name:
	/* identifier */
	NAMESPACE_NAME														{ $$ = alacnary(ORIGINAL_NAMESPACE_NAMEr1, 1, $1); }
	;

class_name:
	/* identifier */
	CLASS_NAME															{ $$ = alacnary(CLASS_NAMEr1, 1, $1); }
	| template_id														{ $$ = alacnary(CLASS_NAMEr2, 1, $1); }
	;

enum_name:
	/* identifier */
	ENUM_NAME															{ $$ = alacnary(ENUM_NAMEr1, 1, $1); }
	;

template_name:
	/* identifier */
	TEMPLATE_NAME														{ $$ = alacnary(TEMPLATE_NAMEr1, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Lexical elements.
 *----------------------------------------------------------------------*/

identifier:
	IDENTIFIER															{ $$ = alacnary(IDENTIFIERr1, 1, $1); }
	;

literal:
	integer_literal													{ $$ = alacnary(LITERALr1, 1, $1); }
	| character_literal												{ $$ = alacnary(LITERALr2, 1, $1); }
	| floating_literal												{ $$ = alacnary(LITERALr3, 1, $1); }
	| string_literal													{ $$ = alacnary(LITERALr4, 1, $1); }
	| boolean_literal													{ $$ = alacnary(LITERALr5, 1, $1); }
	;

integer_literal:
	INTEGER																{ $$ = alacnary(INTEGER_LITERALr1, 1, $1); }
	;

character_literal:
	CHARACTER															{ $$ = alacnary(CHARACTER_LITERALr1, 1, $1); }
	;

floating_literal:
	FLOATING																{ $$ = alacnary(FLOATING_LITERALr1, 1, $1); }
	;

string_literal:
	STRING																{ $$ = alacnary(STRING_LITERALr1, 1, $1); }
	;

boolean_literal:
	TRUE																	{ $$ = alacnary(BOOLEAN_LITERALr1, 1, $1); }
	| FALSE																{ $$ = alacnary(BOOLEAN_LITERALr2, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Translation unit.
 *----------------------------------------------------------------------*/

translation_unit:
	declaration_seq_opt												{ $$ = alacnary(TRANSLATION_UNITr1, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Expressions.
 *----------------------------------------------------------------------*/

primary_expression:
	literal																{ $$ = alacnary(PRIMARY_EXPRESSIONr1, 1, $1); }
	| THIS																{ $$ = alacnary(PRIMARY_EXPRESSIONr2, 1, $1); }
	| '(' expression ')'												{ $$ = alacnary(PRIMARY_EXPRESSIONr3, 1, $2,); }
	| id_expression													{ $$ = alacnary(PRIMARY_EXPRESSIONr4, 1, $1); }
	;

id_expression:
	unqualified_id														{ $$ = alacnary(PRIMARY_EXPRESSIONr1, 1, $1); }
	| qualified_id														{ $$ = alacnary(PRIMARY_EXPRESSIONr2, 1, $1); }
	;

unqualified_id:
	identifier															{ $$ = alacnary(PRIMARY_EXPRESSIONr1, 1, $1); }
	| operator_function_id											{ $$ = alacnary(PRIMARY_EXPRESSIONr2, 1, $1); }
	| conversion_function_id										{ $$ = alacnary(PRIMARY_EXPRESSIONr3, 1, $1); }
	| '~' class_name													{ $$ = alacnary(PRIMARY_EXPRESSIONr4, 2, $1, $2); }
	;

qualified_id:
	nested_name_specifier unqualified_id						{ $$ = alacnary(QUALIFIED_IDr1, 2, $1, $2); }
	| nested_name_specifier TEMPLATE unqualified_id			{ $$ = alacnary(QUALIFIED_IDr1, 3, $1, $2, $3); }
	;

nested_name_specifier:
	class_name COLONCOLON nested_name_specifier				{ $$ = alacnary(NESTED_NAME_SPECIFIERr1, 3, $1, $2, $3); }
	namespace_name COLONCOLON nested_name_specifier			{ $$ = alacnary(NESTED_NAME_SPECIFIERr2, 3, $1, $2, $3); }
	| class_name COLONCOLON											{ $$ = alacnary(NESTED_NAME_SPECIFIERr3, 2, $1, $2); }
	| namespace_name COLONCOLON									{ $$ = alacnary(NESTED_NAME_SPECIFIERr4, 2, $1, $2); }
	;

postfix_expression:
	primary_expression												{ $$ = alacnary(POSTFIX_EXRESSIONr1, 1, $1); }
	| postfix_expression '[' expression ']'					{ $$ = alacnary(POSTFIX_EXRESSIONr2, 2, $1, $3); }
	| postfix_expression '(' expression_list_opt ')'		{ $$ = alacnary(POSTFIX_EXRESSIONr3, 2, $1, $3); }
	| postfix_expression '.' TEMPLATE COLONCOLON id_expression
																			{ $$ = alacnary(POSTFIX_EXRESSIONr4, 3, $1, $3, $4); }
	| postfix_expression '.' TEMPLATE id_expression			{ $$ = alacnary(POSTFIX_EXRESSIONr5, 3, $1, $3, $4); }
	| postfix_expression '.' COLONCOLON id_expression		{ $$ = alacnary(POSTFIX_EXRESSIONr6, 3, $1, $3, $4); }
	| postfix_expression '.' id_expression						{ $$ = alacnary(POSTFIX_EXRESSIONr7, 2, $1, $3); }
	| postfix_expression ARROW TEMPLATE COLONCOLON id_expression
																			{ $$ = alacnary(POSTFIX_EXRESSIONr8, 5, $1, $2, $3, $4, $5); }
	| postfix_expression ARROW TEMPLATE id_expression		{ $$ = alacnary(POSTFIX_EXRESSIONr9, 4, $1, $2, $3, $4); }
	| postfix_expression ARROW COLONCOLON id_expression	{ $$ = alacnary(POSTFIX_EXRESSIONr10, 4, $1, $2, $3, $4); }
	| postfix_expression ARROW id_expression					{ $$ = alacnary(POSTFIX_EXRESSIONr11, 3, $1, $2, $3); }
	| postfix_expression PLUSPLUS									{ $$ = alacnary(POSTFIX_EXRESSIONr12, 2, $1, $2); }
	| postfix_expression MINUSMINUS								{ $$ = alacnary(POSTFIX_EXRESSIONr13, 2, $1, $2); }
	| DYNAMIC_CAST '<' type_id '>' '(' expression ')'		{ $$ = alacnary(POSTFIX_EXRESSIONr14, 3, $1, $3, $6); }
	| STATIC_CAST '<' type_id '>' '(' expression ')'		{ $$ = alacnary(POSTFIX_EXRESSIONr15, 3, $1, $3, $6); }
	| REINTERPRET_CAST '<' type_id '>' '(' expression ')'	{ $$ = alacnary(POSTFIX_EXRESSIONr16, 3, $1, $3, $6); }
	| CONST_CAST '<' type_id '>' '(' expression ')'			{ $$ = alacnary(POSTFIX_EXRESSIONr17, 3, $1, $3, $6); }
	| TYPEID '(' expression ')'									{ $$ = alacnary(POSTFIX_EXRESSIONr18, 2, $1, $3); }
	| TYPEID '(' type_id ')'										{ $$ = alacnary(POSTFIX_EXRESSIONr19, 2, $1, $3); }
	;

expression_list:
	assignment_expression											{ $$ = alacnary(EXPRESSION_LISTr1, 1, $1); }
	| expression_list ',' assignment_expression				{ $$ = alacnary(EXPRESSION_LISTr2, 2, $1, $3); }
	;

unary_expression:
	postfix_expression												{ $$ = alacnary(UNARY_EXPRESSIONr1, 1, $1); }
	| PLUSPLUS cast_expression										{ $$ = alacnary(UNARY_EXPRESSIONr2, 2, $1, $2); }
	| MINUSMINUS cast_expression									{ $$ = alacnary(UNARY_EXPRESSIONr3, 2, $1, $2); }
	| '*' cast_expression											{ $$ = alacnary(UNARY_EXPRESSIONr4, 1, $2); }
	| '&' cast_expression											{ $$ = alacnary(UNARY_EXPRESSIONr5, 1, $2); }
	| unary_operator cast_expression								{ $$ = alacnary(UNARY_EXPRESSIONr6, 2, $1, $2); }
	| SIZEOF unary_expression										{ $$ = alacnary(UNARY_EXPRESSIONr7, 2, $1, $2); }
	| SIZEOF '(' type_id ')'										{ $$ = alacnary(UNARY_EXPRESSIONr8, 2, $1, $3); }
	| new_expression													{ $$ = alacnary(UNARY_EXPRESSIONr9, 1, $1); }
	| delete_expression												{ $$ = alacnary(UNARY_EXPRESSIONr10, 1, $1); }
	;

unary_operator:
	  '+'																	{ $$ = $1 }
	| '-'																	{ $$ = $1 }
	| '!'																	{ $$ = $1 }
	| '~'																	{ $$ = $1 }
	;

new_expression:
	  NEW new_placement_opt new_type_id new_initializer_opt
																			{ $$ = alacnary(NEW_EXPRESSIONr1, 4, $1, $2, $3, $4); }
	| COLONCOLON NEW new_placement_opt new_type_id new_initializer_opt
																			{ $$ = alacnary(NEW_EXPRESSIONr2, 5, $1, $2, $3, $4, $5); }
	| NEW new_placement_opt '(' type_id ')' new_initializer_opt
																			{ $$ = alacnary(NEW_EXPRESSIONr3, 4, $1, $2, $4, $6); }
	| COLONCOLON NEW new_placement_opt '(' type_id ')' new_initializer_opt
																			{ $$ = alacnary(NEW_EXPRESSIONr4, 5, $1, $2, $3, $5, $7); }
	;

new_placement:
	'(' expression_list ')'											{ $$ = alacnary(NEW_PLACEMENTr1, 1, $2); }
	;

new_type_id:
	type_specifier_seq new_declarator_opt						{ $$ = alacnary(NEW_TYPE_IDr1, 2, $1, $2); }
	;

new_declarator:
	ptr_operator new_declarator_opt								{ $$ = alacnary(NEW_DECLARATORr1, 2, $1, $2); }
	| direct_new_declarator											{ $$ = alacnary(NEW_DECLARATORr2, 1, $1); }
	;

direct_new_declarator:
	'[' expression ']'												{ $$ = alacnary(DIRECT_NEW_DECLARATORr1, 1, $2); }
	| direct_new_declarator '[' constant_expression ']'	{ $$ = alacnary(DIRECT_NEW_DECLARATORr2, 2, $1, $3); }
	;

new_initializer:
	'(' expression_list_opt ')'									{ $$ = alacnary(NEW_INITIALIZERr1, 1, $2); }
	;

delete_expression:
	  DELETE cast_expression										{ $$ = alacnary(DELETE_EXPRESSIONr1, 2, $1, $2); }
	| COLONCOLON DELETE cast_expression							{ $$ = alacnary(DELETE_EXPRESSIONr2, 3, $1, $2, $3); }
	| DELETE '[' ']' cast_expression								{ $$ = alacnary(DELETE_EXPRESSIONr3, 2, $1, $4); }
	| COLONCOLON DELETE '[' ']' cast_expression				{ $$ = alacnary(DELETE_EXPRESSIONr4, 3, $1, $2, $5); }
	;

cast_expression:
	unary_expression													{ $$ = alacnary(CAST_EXPRESSIONr1, 1, $1); }
	| '(' type_id ')' cast_expression							{ $$ = alacnary(CAST_EXPRESSIONr2, 2, $2, $4); }
	;

pm_expression:
	cast_expression													{ $$ = alacnary(PM_EXPRESSIONr1, 1, $1); }
	| pm_expression DOTSTAR cast_expression					{ $$ = alacnary(PM_EXPRESSIONr2, 3, $1, $2, $3); }
	| pm_expression ARROWSTAR cast_expression					{ $$ = alacnary(PM_EXPRESSIONr3, 3, $1, $2, $3); }
	;

multiplicative_expression:
	pm_expression														{ $$ = alacnary(MULTIPLICATIVE_EXPRESSIONr1, 1, $1); }
	| multiplicative_expression '*' pm_expression			{ $$ = alacnary(MULTIPLICATIVE_EXPRESSIONr2, 2, $1, $3); }
	| multiplicative_expression '/' pm_expression			{ $$ = alacnary(MULTIPLICATIVE_EXPRESSIONr3, 2, $1, $3); }
	| multiplicative_expression '%' pm_expression			{ $$ = alacnary(MULTIPLICATIVE_EXPRESSIONr4, 2, $1, $3); }
	;

additive_expression:
	multiplicative_expression										{ $$ = alacnary(ADDITIVE_EXPRESSIONr1, 1, $1); }
	| additive_expression '+' multiplicative_expression	{ $$ = alacnary(ADDITIVE_EXPRESSIONr2, 2, $1, $3); }
	| additive_expression '-' multiplicative_expression	{ $$ = alacnary(ADDITIVE_EXPRESSIONr3, 2, $1, $3); }
	;

shift_expression:
	additive_expression												{ $$ = alacnary(SHIFT_EXPRESSIONr1, 1, $1); }
	| shift_expression SL additive_expression					{ $$ = alacnary(SHIFT_EXPRESSIONr2, 3, $1, $2, $3); }
	| shift_expression SR additive_expression					{ $$ = alacnary(SHIFT_EXPRESSIONr3, 3, $1, $2, $3); }
	;

relational_expression:
	shift_expression													{ $$ = alacnary(RELATIONAL_EXPRESSIONr1, 1, $1); }
	| relational_expression '<' shift_expression				{ $$ = alacnary(RELATIONAL_EXPRESSIONr2, 2, $1, $3); }
	| relational_expression '>' shift_expression				{ $$ = alacnary(RELATIONAL_EXPRESSIONr3, 2, $1, $3); }
	| relational_expression LTEQ shift_expression			{ $$ = alacnary(RELATIONAL_EXPRESSIONr4, 3, $1, $2, $3); }
	| relational_expression GTEQ shift_expression			{ $$ = alacnary(RELATIONAL_EXPRESSIONr5, 3, $1, $2, $3); }
	;

equality_expression:
	relational_expression											{ $$ = alacnary(EQUALITY_EXPRESSIONr1, 1, $1); }
	| equality_expression EQ relational_expression			{ $$ = alacnary(EQUALITY_EXPRESSIONr2, 3, $1, $2, $3); }
	| equality_expression NOTEQ relational_expression		{ $$ = alacnary(EQUALITY_EXPRESSIONr3, 1, $1, $2, $3); }
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
	'='																	{ $$ = $1 }
	| MULEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr1, 1, $1); }
	| DIVEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr2, 1, $1); }
	| MODEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr3, 1, $1); }
	| ADDEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr4, 1, $1); }
	| SUBEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr5, 1, $1); }
	| SREQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr6, 1, $1); }
	| SLEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr7, 1, $1); }
	| ANDEQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr8, 1, $1); }
	| XOREQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr9, 1, $1); }
	| OREQ																{ $$ = alacnary(ASSIGNMENT_OPERATORr10, 1, $1); }
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
	'{' statement_seq_opt '}'										{ $$ = alacnary(COMPOUND_STATEMENTr1, 1, $1); }
	;

statement_seq:
	statement															{ $$ = alacnary(STATEMENT_SEQr1, 1, $1); }
	| statement_seq statement										{ $$ = alacnary(STATEMENT_SEQr2, 2, $1, $2); }
	;

selection_statement:
	IF '(' condition ')' statement								{ $$ = alacnary(SELECTION_STATEMENT_SEQr1, 3, $1, $3, $5); }
	| IF '(' condition ')' statement ELSE statement			{ $$ = alacnary(SELECTION_STATEMENT_SEQr2, 5, $1, $3, $5, $6, $7); }
	| SWITCH '(' condition ')' statement						{ $$ = alacnary(SELECTION_STATEMENT_SEQr3, 3, $1, $3, $5); }
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
	ENUM identifier '{' enumerator_list_opt '}'
	;

enumerator_list:
	enumerator_definition
	| enumerator_list ',' enumerator_definition
	;

enumerator_definition:
	enumerator
	| enumerator '=' constant_expression
	;

enumerator:
	identifier
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
	named_namespace_definition
	| unnamed_namespace_definition
	;

named_namespace_definition:
	original_namespace_definition
	| extension_namespace_definition
	;

original_namespace_definition:
	NAMESPACE identifier '{' namespace_body '}'
	;

extension_namespace_definition:
	NAMESPACE original_namespace_name '{' namespace_body '}'
	;

unnamed_namespace_definition:
	NAMESPACE '{' namespace_body '}'
	;

namespace_body:
	declaration_seq_opt
	;

/*
namespace_alias:
	identifier
	;
*/

namespace_alias_definition:
	NAMESPACE identifier '=' qualified_namespace_specifier ';'
	;

qualified_namespace_specifier:
	  COLONCOLON nested_name_specifier namespace_name
	| COLONCOLON namespace_name
	| nested_name_specifier namespace_name
	| namespace_name
	;

using_declaration:
	  USING TYPENAME COLONCOLON nested_name_specifier unqualified_id ';'
	| USING TYPENAME nested_name_specifier unqualified_id ';'
	| USING COLONCOLON nested_name_specifier unqualified_id ';'
	| USING nested_name_specifier unqualified_id ';'
	| USING COLONCOLON unqualified_id ';'
	;

using_directive:
	USING NAMESPACE COLONCOLON nested_name_specifier namespace_name ';'
	| USING NAMESPACE COLONCOLON namespace_name ';'
	| USING NAMESPACE nested_name_specifier namespace_name ';'
	| USING NAMESPACE namespace_name ';'
	;

asm_definition:
	ASM '(' string_literal ')' ';'
	;

linkage_specification:
	EXTERN string_literal '{' declaration_seq_opt '}'
	| EXTERN string_literal declaration
	;

/*----------------------------------------------------------------------
 * Declarators.
 *----------------------------------------------------------------------*/

init_declarator_list:
	init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator:
	declarator initializer_opt
	;

declarator:
	direct_declarator
	| ptr_operator declarator
	;

direct_declarator:
	  declarator_id
	| direct_declarator '('parameter_declaration_clause ')' cv_qualifier_seq exception_specification
	| direct_declarator '('parameter_declaration_clause ')' cv_qualifier_seq
	| direct_declarator '('parameter_declaration_clause ')' exception_specification
	| direct_declarator '('parameter_declaration_clause ')'
	| direct_declarator '[' constant_expression_opt ']'
	| '(' declarator ')'
	;

ptr_operator:
	'*'
	| '*' cv_qualifier_seq
	| '&'
	| nested_name_specifier '*'
	| nested_name_specifier '*' cv_qualifier_seq
	| COLONCOLON nested_name_specifier '*'
	| COLONCOLON nested_name_specifier '*' cv_qualifier_seq
	;

cv_qualifier_seq:
	cv_qualifier
	| cv_qualifier cv_qualifier_seq
	;

cv_qualifier:
	CONST
	| VOLATILE
	;

declarator_id:
	  id_expression
	| COLONCOLON id_expression
	| COLONCOLON nested_name_specifier type_name
	| COLONCOLON type_name
	;

type_id:
	type_specifier_seq abstract_declarator_opt
	;

type_specifier_seq:
	type_specifier type_specifier_seq_opt
	;

abstract_declarator:
	ptr_operator abstract_declarator_opt
	| direct_abstract_declarator
	;

direct_abstract_declarator:
	  direct_abstract_declarator_opt '(' parameter_declaration_clause ')' cv_qualifier_seq exception_specification
	| direct_abstract_declarator_opt '(' parameter_declaration_clause ')' cv_qualifier_seq
	| direct_abstract_declarator_opt '(' parameter_declaration_clause ')' exception_specification
	| direct_abstract_declarator_opt '(' parameter_declaration_clause ')'
	| direct_abstract_declarator_opt '[' constant_expression_opt ']'
	| '(' abstract_declarator ')'
	;

parameter_declaration_clause:
	  parameter_declaration_list ELLIPSIS
	| parameter_declaration_list
	| ELLIPSIS
	| 
	| parameter_declaration_list ',' ELLIPSIS
	;

parameter_declaration_list:
	parameter_declaration
	| parameter_declaration_list ',' parameter_declaration
	;

parameter_declaration:
	decl_specifier_seq declarator
	| decl_specifier_seq declarator '=' assignment_expression
	| decl_specifier_seq abstract_declarator_opt
	| decl_specifier_seq abstract_declarator_opt '=' assignment_expression
	;

function_definition:
	  declarator ctor_initializer_opt function_body
	| decl_specifier_seq declarator ctor_initializer_opt function_body
	| declarator function_try_block
	| decl_specifier_seq declarator function_try_block
	;

function_body:
	compound_statement
	;

initializer:
	'=' initializer_clause
	| '(' expression_list ')'
	;

initializer_clause:
	assignment_expression
	| '{' initializer_list COMMA_opt '}'
	| '{' '}'
	;

initializer_list:
	initializer_clause
	| initializer_list ',' initializer_clause
	;

/*----------------------------------------------------------------------
 * Classes.
 *----------------------------------------------------------------------*/

class_specifier:
	class_head '{' member_specification_opt '}'
	;

class_head:
	  class_key identifier
	| class_key identifier base_clause
	| class_key nested_name_specifier identifier
	| class_key nested_name_specifier identifier base_clause
	;

class_key:
	CLASS
	| STRUCT
	| UNION
	;

member_specification:
	member_declaration member_specification_opt
	| access_specifier ':' member_specification_opt
	;

member_declaration:
	  decl_specifier_seq member_declarator_list ';'
	| decl_specifier_seq ';'
	| member_declarator_list ';'
	| ';'
	| function_definition SEMICOLON_opt
	| qualified_id ';'
	| using_declaration
	| template_declaration
	;

member_declarator_list:
	member_declarator
	| member_declarator_list ',' member_declarator
	;

member_declarator:
	| declarator
	| declarator pure_specifier
	| declarator constant_initializer
	| identifier ':' constant_expression
	;

/*
 * This rule need a hack for working around the ``= 0'' pure specifier.
 * 0 is returned as an ``INTEGER'' by the lexical analyzer but in this
 * context is different.
 */
pure_specifier:
	'=' '0'
	;

constant_initializer:
	'=' constant_expression
	;

/*----------------------------------------------------------------------
 * Derived classes.
 *----------------------------------------------------------------------*/

base_clause:
	':' base_specifier_list
	;

base_specifier_list:
	base_specifier
	| base_specifier_list ',' base_specifier
	;

base_specifier:
	  COLONCOLON nested_name_specifier class_name
	| COLONCOLON class_name
	| nested_name_specifier class_name
	| class_name
	| VIRTUAL access_specifier COLONCOLON nested_name_specifier_opt class_name
	| VIRTUAL access_specifier nested_name_specifier_opt class_name
	| VIRTUAL COLONCOLON nested_name_specifier_opt class_name
	| VIRTUAL nested_name_specifier_opt class_name
	| access_specifier VIRTUAL COLONCOLON nested_name_specifier_opt class_name
	| access_specifier VIRTUAL nested_name_specifier_opt class_name
	| access_specifier COLONCOLON nested_name_specifier_opt class_name
	| access_specifier nested_name_specifier_opt class_name
	;

access_specifier:
	PRIVATE
	| PROTECTED
	| PUBLIC
	;

/*----------------------------------------------------------------------
 * Special member functions.
 *----------------------------------------------------------------------*/

conversion_function_id:
	OPERATOR conversion_type_id
	;

conversion_type_id:
	type_specifier_seq conversion_declarator_opt
	;

conversion_declarator:
	ptr_operator conversion_declarator_opt
	;

ctor_initializer:
	':' mem_initializer_list
	;

mem_initializer_list:
	mem_initializer
	| mem_initializer ',' mem_initializer_list
	;

mem_initializer:
	mem_initializer_id '(' expression_list_opt ')'
	;

mem_initializer_id:
	  COLONCOLON nested_name_specifier class_name
	| COLONCOLON class_name
	| nested_name_specifier class_name
	| class_name
	| identifier
	;

/*----------------------------------------------------------------------
 * Overloading.
 *----------------------------------------------------------------------*/

operator_function_id:
	OPERATOR operator
	;

operator:
	NEW
	| DELETE
	| NEW '[' ']'
	| DELETE '[' ']'
	| '+'
	| '_'
	| '*'
	| '/'
	| '%'
	| '^'
	| '&'
	| '|'
	| '~'
	| '!'
	| '='
	| '<'
	| '>'
	| ADDEQ
	| SUBEQ
	| MULEQ
	| DIVEQ
	| MODEQ
	| XOREQ
	| ANDEQ
	| OREQ
	| SL
	| SR
	| SREQ
	| SLEQ
	| EQ
	| NOTEQ
	| LTEQ
	| GTEQ
	| ANDAND
	| OROR
	| PLUSPLUS
	| MINUSMINUS
	| ','
	| ARROWSTAR
	| ARROW
	| '(' ')'
	| '[' ']'
	;

/*----------------------------------------------------------------------
 * Templates.
 *----------------------------------------------------------------------*/

template_declaration:
	EXPORT_opt TEMPLATE '<' template_parameter_list '>' declaration
	;

template_parameter_list:
	template_parameter
	| template_parameter_list ',' template_parameter
	;

template_parameter:
	type_parameter
	| parameter_declaration
	;

type_parameter:
	  CLASS identifier
	| CLASS identifier '=' type_id
	| TYPENAME identifier
	| TYPENAME identifier '=' type_id
	| TEMPLATE '<' template_parameter_list '>' CLASS identifier
	| TEMPLATE '<' template_parameter_list '>' CLASS identifier '=' template_name
	;

template_id:
	template_name '<' template_argument_list '>'
	;

template_argument_list:
	template_argument
	| template_argument_list ',' template_argument
	;

template_argument:
	assignment_expression
	| type_id
	| template_name
	;

explicit_instantiation:
	TEMPLATE declaration
	;

explicit_specialization:
	TEMPLATE '<' '>' declaration
	;

/*----------------------------------------------------------------------
 * Exception handling.
 *----------------------------------------------------------------------*/

try_block:
	TRY compound_statement handler_seq
	;

function_try_block:
	TRY ctor_initializer_opt function_body handler_seq
	;

handler_seq:
	handler handler_seq_opt
	;

handler:
	CATCH '(' exception_declaration ')' compound_statement
	;

exception_declaration:
	type_specifier_seq declarator
	| type_specifier_seq abstract_declarator
	| type_specifier_seq
	| ELLIPSIS
	;

throw_expression:
	THROW assignment_expression_opt
	;

exception_specification:
	THROW '(' type_id_list_opt ')'
	;

type_id_list:
	type_id
	| type_id_list ',' type_id
	;

/*----------------------------------------------------------------------
 * Epsilon (optional) definitions.
 *----------------------------------------------------------------------*/

declaration_seq_opt:
	/* epsilon */
	| declaration_seq
	;

nested_name_specifier_opt:
	/* epsilon */
	| nested_name_specifier
	;

expression_list_opt:
	/* epsilon */
	| expression_list
	;

COLONCOLON_opt:
	/* epsilon */
	| COLONCOLON
	;

new_placement_opt:
	/* epsilon */
	| new_placement
	;

new_initializer_opt:
	/* epsilon */
	| new_initializer
	;

new_declarator_opt:
	/* epsilon */
	| new_declarator
	;

expression_opt:
	/* epsilon */
	| expression
	;

statement_seq_opt:
	/* epsilon */
	| statement_seq
	;

condition_opt:
	/* epsilon */
	| condition
	;

enumerator_list_opt:
	/* epsilon */
	| enumerator_list
	;

initializer_opt:
	/* epsilon */
	| initializer
	;

constant_expression_opt:
	/* epsilon */
	| constant_expression
	;

abstract_declarator_opt:
	/* epsilon */
	| abstract_declarator
	;

type_specifier_seq_opt:
	/* epsilon */
	| type_specifier_seq
	;

direct_abstract_declarator_opt:
	/* epsilon */
	| direct_abstract_declarator
	;

ctor_initializer_opt:
	/* epsilon */
	| ctor_initializer
	;

COMMA_opt:
	/* epsilon */
	| ','
	;

member_specification_opt:
	/* epsilon */
	| member_specification
	;

SEMICOLON_opt:
	/* epsilon */
	| ';'
	;

conversion_declarator_opt:
	/* epsilon */
	| conversion_declarator
	;

EXPORT_opt:
	/* epsilon */
	| EXPORT
	;

handler_seq_opt:
	/* epsilon */
	| handler_seq
	;

assignment_expression_opt:
	/* epsilon */
	| assignment_expression
	;

type_id_list_opt:
	/* epsilon */
	| type_id_list
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
	else token->ival = NULL;
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

struct TreeNode * alacnary(int prodRule, int children,...){
	struct TreeNode * nd = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
	if(!nd)memoryError();
	nd->u.n.rule = prodRule;
	int c = 0;
	va_list mylist;
	va_start(mylist, children);
	while(c < children){
		nd->u.n.child[c] = va_arg(mylist, struct node *);
		c++;
	}
	va_end(mylist);
	return nd;
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
			//treeprint(yyroot);
		}
	} else { //no files in arguments
		printf("Missing file name.\n");
		exit(1);
	}
   return 0;
}
