/*
 * John Goettsche
 * CS445
 *
 * token.h defines Token and TokenList
 */

typedef struct Token Token;
struct Token{
  int category;
  char *text;
  int lineno;
  char *filename;
  int ival;
  int *sval;
};

typedef struct TokenList TokenList;
struct TokenList {
  struct Token *t;
  struct TokenList *next;
};

extern char *fname;
extern int line_num;
extern int tcode;
extern char *yytext;
extern Token *yytoken;