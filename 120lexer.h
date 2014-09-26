/*
 * John Goettsche
 * CS445
 *
 * header file for the main procedure for 120++ lexical scanner.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "cparser.tab.h"
#include "token.h"

/*
%option yywrap;
*/

extern int line_num;
extern FILE *yyin;
extern char *yytext;
