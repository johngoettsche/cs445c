/*
 *  John Goettsche
 *  CS445
 *  Homework #2
 *  revised lexer by Sandro Sigala.
 */

/*	$Id: lexer.l,v 1.2 1997/11/19 15:13:15 sandro Exp $	*/

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
 * ISO C++ lexical analyzer.
 *
 * Based on the ISO C++ draft standard of December '96.
 */

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "sdef.h"
#include "120gram.h"
#include "token.h"
#include "errors.h"

FileStack *topFile = NULL;
TypeStack *topType = NULL;
int lineno;
TreeNode *n;
FILE *yyin;
FILE *saved_yyin;
int exitStatus = 0;

static int yywrap(void);
void include();
void handle_include();
void pushTypeStack(int);
void popTypeStack();
void pushFileStack();
void popFileStack();
static void skip_until_eol(void);
static void skip_comment(void);
static int check_identifier(char *);
static int alac(Token *);
void lexerr(char *);

int using_namespace_std = 0;
int included_iostream = 0;
int included_cstdlib = 0;
int included_ctime = 0; 
int included_string = 0;
int included_fstream = 0;
int included_stdio = 0; 
int included_stdlib = 0;
int included_cmath = 0;
int typedefMode = 0;
int unionMode = 0;
%}

intsuffix				([uU][lL]?)|([lL][uU]?)
fracconst				([0-9]*\.[0-9]+)|([0-9]+\.)
exppart					[eE][-+]?[0-9]+
floatsuffix				[fFlL]
chartext					([^'])|(\\.)
stringtext				([^"])|(\\.)

%%

"\n"											{ ++lineno; }
[\t\f\v\r ]+								{ /* Ignore whitespace. */ }

"/*"											{ skip_comment(); }
"//"											{ skip_until_eol(); }

"{"											{ return '{'; }
"<%"											{ return '{'; }
"}"											{ return '}'; }
"%>"											{ return '}'; }
"["											{ return '['; }
"<:"											{ return '['; }
"]"											{ return ']'; }
":>"											{ return ']'; }
"("											{ return '('; }
")"											{ return ')'; }
";"											{ return ';'; }
":"											{ return ':'; }
"..."											{ return alac((Token *)createToken(ELLIPSIS)); }
"?"											{ return '?'; }
"::"											{ return alac((Token *)createToken(COLONCOLON)); }
"."											{ return '.'; }
".*"											{ return alac((Token *)createToken(DOTSTAR)); }
"+"											{ return '+'; }
"-"											{ return '-'; }
"*"											{ return '*'; }
"/"											{ return '/'; }
"%"											{ return '%'; }
"^"											{ return '^'; }
"xor"											{ return '^'; }
"&"											{ return '&'; }
"bitand"										{ return '&'; }
"|"											{ return '|'; }
"bitor"										{ return '|'; }
"~"											{ return '~'; }
"compl"										{ return '~'; }
"!"											{ return '!'; }
"not"											{ return '!'; }
"="											{ return '='; }
"<"											{ return '<'; }
">"											{ return '>'; }
"+="											{ return alac((Token *)createToken(ADDEQ)); }
"-="											{ return alac((Token *)createToken(SUBEQ)); }
"*="											{ return alac((Token *)createToken(MULEQ)); }
"/="											{ return alac((Token *)createToken(DIVEQ)); }
"%="											{ return alac((Token *)createToken(MODEQ)); }
"^="											{ return alac((Token *)createToken(XOREQ)); }
"xor_eq"										{ return alac((Token *)createToken(XOREQ)); }
"&="											{ return alac((Token *)createToken(ANDEQ)); }
"and_eq"										{ return alac((Token *)createToken(ANDEQ)); }
"|="											{ return alac((Token *)createToken(OREQ)); }
"or_eq"										{ return alac((Token *)createToken(OREQ)); }
"<<"											{ return alac((Token *)createToken(SL)); }
">>"											{ return alac((Token *)createToken(SR)); }
"<<="											{ return alac((Token *)createToken(SLEQ)); }
">>="											{ return alac((Token *)createToken(SREQ)); }
"=="											{ return alac((Token *)createToken(EQ)); }
"!="											{ return alac((Token *)createToken(NOTEQ)); }
"not_eq"										{ return alac((Token *)createToken(NOTEQ)); }
"<="											{ return alac((Token *)createToken(LTEQ)); }
">="											{ return alac((Token *)createToken(GTEQ)); }
"&&"											{ return alac((Token *)createToken(ANDAND)); }
"and"											{ return alac((Token *)createToken(ANDAND)); }
"||"											{ return alac((Token *)createToken(OROR)); }
"or"											{ return alac((Token *)createToken(OROR)); }
"++"											{ return alac((Token *)createToken(PLUSPLUS)); }
"--"											{ return alac((Token *)createToken(MINUSMINUS)); }
","											{ return ','; }
"->*"											{ return alac((Token *)createToken(ARROWSTAR)); }
"->"											{ return alac((Token *)createToken(ARROW)); }
"using namespace std;"					{ using_namespace_std = 1; }
"asm"											{ return alac((Token *)createToken(ASM)); }
"auto"										{ return alac((Token *)createToken(AUTO)); }
"bool"										{ return alac((Token *)createToken(BOOL)); }
"break"										{ return alac((Token *)createToken(BREAK)); }
"case"										{ return alac((Token *)createToken(CASE)); }
"catch"										{ return alac((Token *)createToken(CATCH)); }
"char"										{ return alac((Token *)createToken(CHAR)); }
"class"										{ pushTypeStack(CLASS);
													return alac((Token *)createToken(CLASS)); }
"const"										{ return alac((Token *)createToken(CONST)); }
"const_cast"								{ return alac((Token *)createToken(CONST_CAST)); }
"continue"									{ return alac((Token *)createToken(CONTINUE)); }
"default"									{ return alac((Token *)createToken(DEFAULT)); }
"delete"										{ return alac((Token *)createToken(DELETE)); }
"do"											{ return alac((Token *)createToken(DO)); }
"double"										{ return alac((Token *)createToken(DOUBLE)); }
"dynamic_cast"								{ return alac((Token *)createToken(DYNAMIC_CAST)); }
"else"										{ return alac((Token *)createToken(ELSE)); }
"enum"										{ pushTypeStack(ENUM);
													return alac((Token *)createToken(ENUM)); }
"explicit"									{ return alac((Token *)createToken(EXPLICIT)); }
"export"										{ return alac((Token *)createToken(EXPORT)); }
"extern"										{ return alac((Token *)createToken(EXTERN)); }
"false"										{ return alac((Token *)createToken(FALSE)); }
"float"										{ return alac((Token *)createToken(FLOAT)); }
"for"											{ return alac((Token *)createToken(FOR)); }
"friend"										{ return alac((Token *)createToken(FRIEND)); }
"goto"										{ return alac((Token *)createToken(GOTO)); }
"if"											{ return alac((Token *)createToken(IF)); }
"inline"										{ return alac((Token *)createToken(INLINE)); }
"int"											{ return alac((Token *)createToken(INT)); }
"long"										{ return alac((Token *)createToken(LONG)); }
"mutable"									{ return alac((Token *)createToken(MUTABLE)); }
"namespace"									{ pushTypeStack(NAMESPACE);
													return alac((Token *)createToken(NAMESPACE)); }
"new"											{ return alac((Token *)createToken(NEW)); }
"operator"									{ return alac((Token *)createToken(OPERATOR)); }
"private"									{ return alac((Token *)createToken(PRIVATE)); }
"protected"									{ return alac((Token *)createToken(PROTECTED)); }
"public"										{ return alac((Token *)createToken(PUBLIC)); }
"register"									{ return alac((Token *)createToken(REGISTER)); }
"reinterpret_cast"						{ return alac((Token *)createToken(REINTERPRET_CAST)); }
"return"										{ return alac((Token *)createToken(RETURN)); }
"short"										{ return alac((Token *)createToken(SHORT)); }
"signed"										{ return alac((Token *)createToken(SIGNED)); }
"sizeof"										{ return alac((Token *)createToken(SIZEOF)); }
"static"										{ return alac((Token *)createToken(STATIC)); }
"static_cast"								{ return alac((Token *)createToken(STATIC_CAST)); }
"struct"										{ pushTypeStack(STRUCT);
													return alac((Token *)createToken(STRUCT)); }
"switch"										{ return alac((Token *)createToken(SWITCH)); }
"template"									{ exitStatus = 3;
													getErrorMessage(ER_NOT_SUPPORTED);
													lexerr(yytext);
													/*pushTypeStack(TEMPLATE);
													return alac((Token *)createToken(TEMPLATE));*/ }
"this"										{ return alac((Token *)createToken(THIS)); }
"throw"										{ return alac((Token *)createToken(THROW)); }
"true"										{ return alac((Token *)createToken(TRUE)); }
"try"											{ return alac((Token *)createToken(TRY)); }
"typedef"									{ typedefMode = 1;
													return alac((Token *)createToken(TYPEDEF)); }
"typeid"										{ return alac((Token *)createToken(TYPEID)); }
"typename"									{ return alac((Token *)createToken(TYPENAME)); }
"union"										{ unionMode = 1;
													return alac((Token *)createToken(UNION)); }
"unsigned"									{ return alac((Token *)createToken(UNSIGNED)); }
"using"										{ return alac((Token *)createToken(USING)); }
"virtual"									{ return alac((Token *)createToken(VIRTUAL)); }
"void"										{ return alac((Token *)createToken(VOID)); }
"volatile"									{ return alac((Token *)createToken(VOLATILE)); }
"wchar_t"									{ return alac((Token *)createToken(WCHAR_T)); }
"while"										{ return alac((Token *)createToken(WHILE)); }
													
"#include"[ ]*\"[^\\"]+\"  			{ handle_include(); }

"#include"[ ]*"<iostream>"   			{ include();
													included_iostream = 1; }
"#include"[ ]*"<cstdlib>"    			{ include();
													included_cstdlib = 1; }
"#include"[ ]*"<ctime>"      			{ include();
													included_ctime = 1; }
"#include"[ ]*"<string>"     			{ include();
													included_string = 1; }
"#include"[ ]*"<string.h>"     		{ include();
													included_string = 1; }
"#include"[ ]*"<fstream>"    			{ include();
													included_fstream = 1; }
"#include"[ ]*"<stdio.h>"    			{ include();
													included_stdio = 1; }
"#include"[ ]*"<stdlib.h>"   			{ include();
													included_stdlib = 1; }
"#include"[ ]*"<cmath>"   				{ include();
													included_cmath = 1; }

[a-zA-Z_][a-zA-Z_0-9]*					{ return alac((Token *)createToken(check_identifier(yytext))); }

"0"[xX][0-9a-fA-F]+{intsuffix}?		{ return alac((Token *)createToken(INTEGER)); }
"0"[0-7]+{intsuffix}?					{ return alac((Token *)createToken(INTEGER)); }
[0-9]+{intsuffix}?						{ return alac((Token *)createToken(INTEGER)); }

{fracconst}{exppart}?{floatsuffix}?	{ return alac((Token *)createToken(FLOATING)); }
[0-9]+{exppart}{floatsuffix}?			{ return alac((Token *)createToken(FLOATING)); }

"'"{chartext}*"'"							{ return alac((Token *)createToken(CHARACTER)); }
"L'"{chartext}*"'"						{ return alac((Token *)createToken(CHARACTER)); }
"'"{chartext}*								{ exitStatus =1;
													getErrorMessage(ER_MALF_CHAR); 
													lexerr(NULL); }
"L'"{chartext}*							{ exitStatus =1;
													getErrorMessage(ER_MALF_CHAR); 
													lexerr(NULL); }
"\""{stringtext}*"\""					{ return alac((Token *)createToken(STRING)); }
"L\""{stringtext}*"\""					{ return alac((Token *)createToken(STRING)); }
"\""{stringtext}*							{ exitStatus =1;
													getErrorMessage(ER_STRING_CLOSE);
													lexerr(NULL); }
"L\""{stringtext}*						{ exitStatus =1;
													getErrorMessage(ER_STRING_CLOSE);
													lexerr(NULL); }
													
.												{ exitStatus =1;
													getErrorMessage(ER_UNREC_TOKEN);
													lexerr(NULL); }

<<EOF>>                 				{ popFileStack();
													yypop_buffer_state();
													if ( !YY_CURRENT_BUFFER ) {
														yyterminate();
													}
												}
%%

static int
yywrap(void)
{
	return 1;
}

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
	
	if(tcode == INTEGER){ 
		token->ival = atoi(token->text);
		//printf("*** %d ***\n", token->ival);
	}
   if(tcode == STRING){
      token->ival = length;
      int *st = (int *)calloc(length, sizeof(int));
		if(st == NULL) memoryError();
      int i;
      for(i = 0; i < length; i++) st[i] = (int)text[i];
      token->sval = st;
   }
	if(tcode == TRUE) token->ival = 1;
	if(tcode == FALSE) token->ival = 0;
	else token->sval = NULL;
	
	return token;
}

void pushTypeStack(int tcode){
	TypeStack *typeStack = (TypeStack *)calloc(1, sizeof(TypeStack));
	if(typeStack == NULL) memoryError();
	typeStack->tcode = tcode;
	if(topType == NULL){
		topType = typeStack;
		topType->next = NULL;
	} else {
		typeStack->next = topType;
		topType = typeStack;
	}
}

void popTypeStack(){
	if(topType != NULL){
		topType = topType->next;
	}
}

void pushFileStack(){
	FileStack *fileStack = (FileStack *)calloc(1, sizeof(FileStack));
	if(fileStack == NULL) memoryError();
	char *filename = (char *)calloc(strlen(fname) + 1, sizeof(char));
	if(filename == NULL) memoryError();
	strcpy(filename, fname);
	fileStack->filename = filename;
	fileStack->lineno = lineno;
	if (topFile == NULL){
		topFile = fileStack;
		topFile->next = NULL;
	} else {
		fileStack->next = topFile;
		topFile = fileStack;
	}
}

void popFileStack(){
	if(topFile!=NULL){
		fname = topFile->filename;
		lineno = topFile->lineno;
		topFile=topFile->next;
	}
}

void handle_include()
{
	pushFileStack();
   lineno = 1;
   saved_yyin = yyin;
	
   fname = strchr(yytext, '\"')+1;
   fname[strlen(fname)-1] = '\0';
   yyin = fopen(fname,"r");
   if (yyin == NULL) {
		getErrorMessage(ER_FILE_NOT_FOUND);
		yyerror(fname);
		exit(1);
   }
	yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));
}

void include()
{
	pushFileStack();
	lineno = 1;
	saved_yyin = yyin;
	
	fname = strchr(yytext, '<')+1;
	fname[strlen(fname)-1] = '\0';
	fname = strcat(fname, ".a");
	yyin = fopen(fname,"r");
	if (yyin == NULL) {
		getErrorMessage(ER_FILE_NOT_FOUND);
		yyerror(fname);
		exit(1);
   }
	yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));
}

/*
 * We use this routine instead a lex pattern because we don't need
 * to save the matched comment in the `yytext' buffer.
 */
static void
skip_comment(void)
{
	int c1, c2;

	c1 = input();
	c2 = input();

	while (c2 != EOF && !(c1 == '*' && c2 == '/')) {
		if (c1 == '\n')
			++lineno;
		c1 = c2;
		c2 = input();
	}
}

/*
 * See the previous comment for an explanation.
 */
static void
skip_until_eol(void)
{
	int c;

	while ((c = input()) != EOF && c != '\n')
		;
	++lineno;
}

/*
 * Type name table.
 * Replace this with a hash table, when you get a chance.
 */
struct typenametable_entry {
   char *name;
   int category;
   struct typenametable_entry *next;
   } *head;

int typenametable_lookup(char *s)
{
   struct typenametable_entry *tmp = head;
   while (tmp) {
      if (!strcmp(s, tmp->name)) return tmp->category;
      tmp = tmp->next;
   }	
	
	if(strcmp(s, "string") == 0){
		typenametable_insert(s, STR_TYPE);
		return STR_TYPE;
	}
	
	if(topType!=NULL){
		switch(topType->tcode){
			case CLASS : 
				popTypeStack();
				typenametable_insert(s, CLASS_NAME);
				return CLASS_NAME;
		/*	case TYPEDEF : 
				popTypeStack();
				typenametable_insert(s, TYPEDEF_NAME);
				return TYPEDEF_NAME;*/
			case ENUM : 
				popTypeStack();
				typenametable_insert(s, ENUM_NAME);
				return ENUM_NAME;
			case NAMESPACE : 
				popTypeStack();
				typenametable_insert(s, NAMESPACE_NAME);
				return NAMESPACE_NAME;
		/*	case TEMPLATE : 
				popTypeStack();
				typenametable_insert(s, TEMPLATE_NAME);
				return TEMPLATE_NAME;*/
			case STRUCT : 
				popTypeStack();
				typenametable_insert(s, CLASS_NAME);
				return CLASS_NAME;
		/*	case UNION : 
				popTypeStack();
				typenametable_insert(s, CLASS_NAME);
				return CLASS_NAME;*/
		}
	}
   return IDENTIFIER;
}

int typenametable_insert(char *s, int cat)
{
   struct typenametable_entry *tmp = head;
   while (tmp) {
      if (!strcmp(s, tmp->name)) {
         fprintf(stderr,
	    "warning, %s is already in the typename table as a %d\n",
	    s, tmp->category );
         return tmp->category;
         }
      tmp = tmp->next;
   }
   tmp = calloc(1, sizeof (struct typenametable_entry));
   if(!tmp) { memoryError();/*fprintf(stderr, "tnti out of memory\n"); return -1;*/ }
   tmp->name = strdup(s);
   tmp->category = cat;
   tmp->next = head;
   head = tmp;
}

static int
check_identifier(char *s)
{
	return typenametable_lookup(s);
}

static int alac(Token *token)
{
	int i;
	if((yylval.n = (TreeNode *)calloc(1, sizeof(TreeNode))) == NULL) memoryError(); 
	yylval.n->symbol = token->category;
	yylval.n->u.t.token = token;
	return token->category;
}

