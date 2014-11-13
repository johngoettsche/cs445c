/*
 * John Goettsche
 * CS445
 *
 * defines ErrorMessage structure
 */

#include <string.h>
#include <stdlib.h> 
#include <stdio.h>

#include "errortab.h"

FILE *ef;
ErrorMessage *e_message;
extern int errors;
extern char *fname;
extern int lineno;
extern char *yytext;
extern int exitStatus;

/* prototypes */
void memoryError();
void getErrorMessage(int ecode);
void lexerr(char *s);
void yyerror(char *s);
