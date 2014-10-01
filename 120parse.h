#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "token.h"

typedef struct TokenStackNode TokenStackNode;
struct TokenStackNode {
	Token *t;
	TokenStackNode *next;
};

typedef struct TreeNode TreeNode;
struct TreeNode {
//	int symbol;		/* <1000 is terminal, >=1000 is non-terminal */
   union {
      struct leaf {
			Token *token;
         //char *lexeme;  /* saved copy of yytext */
         //int val;       /* saved copy of val */
      } t;
      struct nonleaf {
         int rule;
         struct TreeNode *child[1]; /* 9 not big enough for some grammars */
      } n;
   } u;
};
