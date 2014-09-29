/*
 * John Goettsche
 * CS445
 *
 * token.c contains the functions cvnIntString, define_token, printToken, printAllTokens
 */
 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include "token.h"
//#include "120gram.c"

/*
 * handles the escape items in a string of text
 */
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

/*
 * creates a token with its attributes
 */
/* 
Token *createToken(int tcode){
	Token *token = (Token *)calloc(1, sizeof(Token));
	if(token == NULL)memoryError();
	
	int length = strlen(yytext) + 1;
	char *text = (char *)calloc(length, sizeof(char));
	if(text == NULL) memoryError();
   strcpy(text, yytext); 
	token->category = tcode;
   token->text = text;
   token->lineno = line_num;
	
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
}*/

/*
 * prints a single token
 */
void printToken(Token *token)
{ 
   if(token->category > 257) {
		fprintf(stdout, "%4d  %24s%8d%16s", token->category, token->text, token->lineno, token->filename);
		if(token->category == INTEGER){
			fprintf(stdout, "%24d\n", token->ival);
		}else if(token->category == STRING){
			int length = token->ival;
			char *st = cvnIntString(token->ival, token->sval);
			fprintf(stdout, "%24s\n", st);
			free(st);
		}else fprintf(stdout, "\n");
		fflush(stdout);
	}
}

/*
 * prints a list of all tokens in the token list
 */
void printAllTokens(TokenList *current)
{
  fprintf(stdout, "Category                  Text  Lineno        Filename              Ival/Sval\n");
  fprintf(stdout, "-----------------------------------------------------------------------------\n");
  while(current != NULL){
    printToken(current->t);
    current = current->next;
  }
}