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
#include <ctype.h>
#include <stdio.h>

//#include "errors.h"
#include "token.h"
#include "120parse.h"
#include "120gram.h"

int lineno;
Token *yytoken;
TreeNode *n;

static int yywrap(void);
static void skip_until_eol(void);
static void skip_comment(void);
static int check_identifier(char *);
static void alac(Token *);
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
"..."											{ alac((Token *)createToken(ELLIPSIS));
													return ELLIPSIS; }
"?"											{ return '?'; }
"::"											{ alac((Token *)createToken(COLONCOLON));
													return COLONCOLON; }
"."											{ return '.'; }
".*"											{ alac((Token *)createToken(DOTSTAR));
													return DOTSTAR; }
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
"+="											{ alac((Token *)createToken(ADDEQ));
													return ADDEQ; }
"-="											{ alac((Token *)createToken(SUBEQ));
													return SUBEQ; }
"*="											{ alac((Token *)createToken(MULEQ));
													return MULEQ; }
"/="											{ alac((Token *)createToken(DIVEQ));
													return DIVEQ; }
"%="											{ alac((Token *)createToken(MODEQ));
													return MODEQ; }
"^="											{ alac((Token *)createToken(XOREQ));
													return XOREQ; }
"xor_eq"										{ alac((Token *)createToken(XOREQ));
													return XOREQ; }
"&="											{ alac((Token *)createToken(ANDEQ));
													return ANDEQ; }
"and_eq"										{ alac((Token *)createToken(ANDEQ));
													return ANDEQ; }
"|="											{ alac((Token *)createToken(OREQ));
													return OREQ; }
"or_eq"										{ alac((Token *)createToken(OREQ));
													return OREQ; }
"<<"											{ alac((Token *)createToken(SL));
													return SL; }
">>"											{ alac((Token *)createToken(SR));
													return SR; }
"<<="											{ alac((Token *)createToken(SLEQ));
													return SLEQ; }
">>="											{ alac((Token *)createToken(SREQ));
													return SREQ; }
"=="											{ alac((Token *)createToken(EQ));
													return EQ; }
"!="											{ alac((Token *)createToken(NOTEQ));
													return NOTEQ; }
"not_eq"										{ alac((Token *)createToken(NOTEQ));
													return NOTEQ; }
"<="											{ alac((Token *)createToken(LTEQ));
													return LTEQ; }
">="											{ alac((Token *)createToken(GTEQ));
													return GTEQ; }
"&&"											{ alac((Token *)createToken(ANDAND));
													return ANDAND; }
"and"											{ alac((Token *)createToken(ANDAND));
													return ANDAND; }
"||"											{ alac((Token *)createToken(OROR));
													return OROR; }
"or"											{ alac((Token *)createToken(OROR));
													return OROR; }
"++"											{ alac((Token *)createToken(PLUSPLUS));
													return PLUSPLUS; }
"--"											{ alac((Token *)createToken(MINUSMINUS));
													return MINUSMINUS; }
","											{ return ','; }
"->*"											{ alac((Token *)createToken(ARROWSTAR));
													return ARROWSTAR; }
"->"											{ alac((Token *)createToken(ARROW));
													return ARROW; }

"asm"											{ alac((Token *)createToken(ASM));
													return ASM; }
"auto"										{ alac((Token *)createToken(AUTO));
													return AUTO; }
"bool"										{ alac((Token *)createToken(BOOL));
													return BOOL; }
"break"										{ alac((Token *)createToken(BREAK));
													return BREAK; }
"case"										{ alac((Token *)createToken(CASE));
													return CASE; }
"catch"										{ alac((Token *)createToken(CATCH));
													return CATCH; }
"char"										{ alac((Token *)createToken(CHAR));
													return CHAR; }
"class"										{ alac((Token *)createToken(CLASS));
													return CLASS; }
"const"										{ alac((Token *)createToken(CONST));
													return CONST; }
"const_cast"								{ alac((Token *)createToken(CONST_CAST));
													return CONST_CAST; }
"continue"									{ alac((Token *)createToken(CONTINUE));
													return CONTINUE; }
"default"									{ alac((Token *)createToken(DEFAULT));
													return DEFAULT; }
"delete"										{ alac((Token *)createToken(DELETE));
													return DELETE; }
"do"											{ alac((Token *)createToken(DO));
													return DO; }
"double"										{ alac((Token *)createToken(DOUBLE));
													return DOUBLE; }
"dynamic_cast"								{ alac((Token *)createToken(DYNAMIC_CAST));
													return DYNAMIC_CAST; }
"else"										{ alac((Token *)createToken(ELSE));
													return ELSE; }
"enum"										{ alac((Token *)createToken(ENUM));
													return ENUM; }
"explicit"									{ alac((Token *)createToken(EXPLICIT));
													return EXPLICIT; }
"export"										{ alac((Token *)createToken(EXPORT));
													return EXPORT; }
"extern"										{ alac((Token *)createToken(EXTERN));
													return EXTERN; }
"false"										{ alac((Token *)createToken(FALSE));
													return FALSE; }
"float"										{ alac((Token *)createToken(FLOAT));
													return FLOAT; }
"for"											{ alac((Token *)createToken(FOR));
													return FOR; }
"friend"										{ alac((Token *)createToken(FRIEND));
													return FRIEND; }
"goto"										{ alac((Token *)createToken(GOTO));
													return GOTO; }
"if"											{ alac((Token *)createToken(IF));
													return IF; }
"inline"										{ alac((Token *)createToken(INLINE));
													return INLINE; }
"int"											{ alac((Token *)createToken(INT));
													return INT; }
"long"										{ alac((Token *)createToken(LONG));
													return LONG; }
"mutable"									{ alac((Token *)createToken(MUTABLE));
													return MUTABLE; }
"namespace"									{ alac((Token *)createToken(NAMESPACE));
													return NAMESPACE; }
"new"											{ alac((Token *)createToken(NEW));
													return NEW; }
"operator"									{ alac((Token *)createToken(OPERATOR));
													return OPERATOR; }
"private"									{ alac((Token *)createToken(PRIVATE));
													return PRIVATE; }
"protected"									{ alac((Token *)createToken(PROTECTED));
													return PROTECTED; }
"public"										{ alac((Token *)createToken(PUBLIC));
													return PUBLIC; }
"register"									{ alac((Token *)createToken(REGISTER));
													return REGISTER; }
"reinterpret_cast"						{ alac((Token *)createToken(REINTERPRET_CAST));
													return REINTERPRET_CAST; }
"return"										{ alac((Token *)createToken(RETURN));
													return RETURN; }
"short"										{ alac((Token *)createToken(SHORT));
													return SHORT; }
"signed"										{ alac((Token *)createToken(SIGNED));
													return SIGNED; }
"sizeof"										{ alac((Token *)createToken(SIZEOF));
													return SIZEOF; }
"static"										{ alac((Token *)createToken(STATIC));
													return STATIC; }
"static_cast"								{ alac((Token *)createToken(STATIC_CAST));
													return STATIC_CAST; }
"struct"										{ alac((Token *)createToken(STRUCT));
													return STRUCT; }
"switch"										{ alac((Token *)createToken(SWITCH));
													return SWITCH; }
"template"									{ alac((Token *)createToken(TEMPLATE));
													return TEMPLATE; }
"this"										{ alac((Token *)createToken(THIS));
													return THIS; }
"throw"										{ alac((Token *)createToken(THROW));
													return THROW; }
"true"										{ alac((Token *)createToken(TRUE));
													return TRUE; }
"try"											{ alac((Token *)createToken(TRY));
													return TRY; }
"typedef"									{ alac((Token *)createToken(TYPEDEF));
													return TYPEDEF; }
"typeid"										{ alac((Token *)createToken(TYPEID));
													return TYPEID; }
"typename"									{ alac((Token *)createToken(TYPENAME));
													return TYPENAME; }
"union"										{ alac((Token *)createToken(UNION));
													return UNION; }
"unsigned"									{ alac((Token *)createToken(UNSIGNED));
													return UNSIGNED; }
"using"										{ alac((Token *)createToken(USING));
													return USING; }
"virtual"									{ alac((Token *)createToken(VIRTUAL));
													return VIRTUAL; }
"void"										{ alac((Token *)createToken(VOID));
													return VOID; }
"volatile"									{ alac((Token *)createToken(VOLATILE));
													return VOLATILE; }
"wchar_t"									{ alac((Token *)createToken(WCHAR_T));
													return WCHAR_T; }
"while"										{ alac((Token *)createToken(WHILE));
													return WHILE; }

[a-zA-Z_][a-zA-Z_0-9]*					{ return check_identifier(yytext); }

"0"[xX][0-9a-fA-F]+{intsuffix}?		{ alac((Token *)createToken(INTEGER));
													return INTEGER; }
"0"[0-7]+{intsuffix}?					{ alac((Token *)createToken(INTEGER));
													return INTEGER; }
[0-9]+{intsuffix}?						{ alac((Token *)createToken(INTEGER));
													return INTEGER; }

{fracconst}{exppart}?{floatsuffix}?	{ alac((Token *)createToken(FLOATING));
													return FLOATING; }
[0-9]+{exppart}{floatsuffix}?			{ alac((Token *)createToken(FLOATING));
													return FLOATING; }

"'"{chartext}*"'"							{ alac((Token *)createToken(CHARACTER));
													return CHARACTER; }
"L'"{chartext}*"'"						{ alac((Token *)createToken(CHARACTER));
													return CHARACTER; }
/* add error messages for missing ' */

"\""{stringtext}*"\""					{ alac((Token *)createToken(STRING));
													return STRING; }
"L\""{stringtext}*"\""					{ alac((Token *)createToken(STRING));
													return STRING; }
/* add error messages for missing " */

.												{ fprintf(stderr, "%d: unexpected character `%c'\n", lineno, yytext[0]); }
												/* change to use error system */
%%

static int
yywrap(void)
{
	return 1;
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
   if(!tmp) { fprintf(stderr, "tnti out of memory\n"); return -1; }
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

void alac(Token *token)
{
	yylval.n = (TreeNode *)calloc(1, sizeof(TreeNode)); 
	yylval.n->symbol = (int)token->category;
	yylval.n->u.t.token = token;
}
