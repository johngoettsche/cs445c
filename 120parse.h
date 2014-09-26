#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

typedef struct TreeNode TreeNode;
struct TreeNode {
	int symbol;
	union{
		Token token;
		struct node{
			int rule;
			struct TreeNode *child[9]
		}nt;
	} u;
};

typedef struct TokenStackNode TokenStackNode;
struct TokenStackNode {
	Token *t;
	TokenStackNode *next;
};

