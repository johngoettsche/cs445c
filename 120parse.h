#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TokenStackNode TokenStackNode;
struct TokenStackNode {
	Token *t;
	TokenStackNode *next;
};

typedef struct TreeNode TreeNode;
struct TreeNode {
	int symbol;		/* <1000 is terminal, >=1000 is non-terminal */
   union {
      struct leaf {
			Token *token;
      } t;
      struct nonleaf {
         int rule;
			int children;
         struct TreeNode *child[9]; /* 9 not big enough for some grammars */
      } n;
   } u;
};

