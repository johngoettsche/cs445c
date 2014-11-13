/*
 * John Goettsche
 * CS445
 *
 * token.h defines Token and TokenList
 */

extern char *fname;
extern int lineno;
extern int tcode;
extern char *yytext;
extern Token *yytoken;

/* prototypes */
char *cvnIntString(int, int *);
Token *createToken(int);
void printToken(Token *);
void printAllTokens(TokenList *);