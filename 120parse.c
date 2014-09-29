//#include "120parse.h"

TreeNode *treenode(int symbol)
{
	struct node *p = (struct node *)calloc(1, sizeof(struct node));
	if (p == NULL) memoryError();
	p->symbol = symbol;
	return p;
}

TokenStackNode *createTokenStack(){
	TokenStackNode *top = (TokenStackNode *)calloc(1, sizeof(TokenStackNode));
	if(top == NULL) memoryError();
	return top;
}

TokenStackNode *pushTokenStack(TokenStackNode *top, Token *token){
	TokenStackNode *newNode = (TokenStackNode *)calloc(1, sizeof(TokenStackNode));
	if(newNode == NULL) memoryError();
	newNode->t = token;
	newNode->next = top;
	top = newNode;
	return top;
}

TokenStackNode *popTokenStack(TokenStackNode *top){
	top = top->next;
	return top;
}

TokenStackNode *topTokenStack(TokenStackNode *top){
	return top;
}

