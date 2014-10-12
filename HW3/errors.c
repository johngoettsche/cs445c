/*
 * John Goettsche
 * CS445
 *
 * contains 
 */
 
#include "sdef.h"
#include "errors.h"
 
void memoryError(){
	exitStatus = 4;
	getErrorMessage(ER_MALLOC_E);
	yyerror(NULL);
	exit(exitStatus);
}

void getErrorMessage(int ecode){
   int size = 128;
   int code;
	char *line = (char *)calloc(size, sizeof(char));
	char *ertype = (char *)calloc(size, sizeof(char));
	char *mes = (char *)calloc(size, sizeof(char));
	e_message = (ErrorMessage *)calloc(1, sizeof(ErrorMessage));
	if(e_message == NULL || line == NULL || ertype == NULL || mes == NULL) memoryError();
	ef = fopen("errors.def", "r");
	while(fgets(line, size, ef)){
		code = atoi(line);
		fgets(ertype, size, ef);
		fgets(mes, size, ef);
		if(code == ecode){
			char *t = (char *)calloc(size, sizeof(char));
			char *m = (char *)calloc(size, sizeof(char));
			if(t == NULL || m == NULL) memoryError();
			strcpy(t, ertype);
			strcpy(m, mes);
			e_message->number = code;
			e_message->errorType = t;
			e_message->message = m;
		}
	}
	close(ef);
}

void yyerror(char *s)
{
   errors++;
   fprintf(stderr, "\nError #%d: %s, line: %d ", errors, fname, lineno);
	if(!e_message) {
		s = NULL;
		getErrorMessage(ER_SYNTAX);
	}
	if(s != NULL) fprintf(stderr, "%s\t\'%s\' %s\n",e_message->errorType, s, e_message->message);
	else fprintf(stderr, "%s\t%s\n",e_message->errorType, e_message->message);
	e_message = NULL;
	free(e_message);
	fflush(stderr);
}

void lexerr(char *s)
{
   errors++;
   fprintf(stderr, "\nLexical Error #%d: %s, line: %d ", errors, fname, lineno);
	if(s != NULL) fprintf(stderr, "%s\t\'%s\' %s\n",e_message->errorType, s, e_message->message);
	else fprintf(stderr, "%s\t%s\n",e_message->errorType, e_message->message);
	e_message = NULL;
	free(e_message);
	fflush(stderr);
}

