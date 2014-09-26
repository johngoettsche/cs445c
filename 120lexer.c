/*
 * John Goettsche
 * CS445
 *
 * main procedure for 120++ lexical scanner.
 */

#include "120lex.h"
#include "errors.h"

/*
void memoryError(){
	getErrorMessage(ER_MALLOC_E);
	yyerror(NULL);
	exit(1);
}*/
/*
int main(int argc, char **argv){
	yytoken = (Token *)calloc(1, sizeof(Token));
	//create token list
	TokenList *head = (TokenList *)calloc(1, sizeof(TokenList));
	if(head == NULL) memoryError();
	TokenList *current = head;
	current->t = NULL;
	current->next = NULL;
		
   if(argc > 1) { 
		int f;
		//read each file in arguments
		for(f = 1; f < argc; f++) {
			fname = argv[f];
			FILE *infile = fopen(fname, "r");
			yyin = infile;
			line_num = 1;
			if(!yyin){
				printf("Error reading file %s\n", argv[f]);
				exit(1);
			}
			//create all tokens in file
			while(yytoken = (Token *)yylex()){
				if(current->t == NULL)current->t = yytoken;
				else{
					TokenList *item = (TokenList *)calloc(1, sizeof(TokenList));
					if(item == NULL) memoryError();
					item->t = yytoken;
					item->next = NULL;
   
					current->next = item;
					current = current->next;
				}
			}
			close(infile);
			yyrestart();
		}
	} else { //no files in arguments
		printf("Missing file name.\n");
		exit(1);
	}
	
   printAllTokens(head);
   return 0;
}*/
