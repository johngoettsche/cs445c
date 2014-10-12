

typedef struct Token{
  int category;
  char *text;
  int lineno;
  char *filename;
  int ival;
  int *sval;
}Token;

typedef struct TokenList {
  struct Token *t;
  struct TokenList *next;
}TokenList;

typedef struct TokenStackNode {
	Token *t;
	struct TokenStackNode *next;
}TokenStackNode;

typedef struct FileStack FileStack;
struct FileStack {
   char *filename;
	int lineno;
	FileStack *next;
};

typedef struct TypeStack TypeStack;
struct TypeStack{
	int tcode;
	TypeStack *next;
};

typedef struct Field {			/* members (fields) of structs */
   char *name;
   struct ctype *elemtype;
}Field;

typedef struct NType {
   /*
    * Integer code that says what kind of type this is.
    * Includes all primitive types: 1 = int, 2=float,
    * Also includes codes for compound types that then also
    * hold type information in a supporting union...
    * 7 = array, 8 = struct, 9 = pointer etc. */
   int base_type;
   union {
      struct array {
         int size; /* allow for missing size, e.g. -1 */
			struct NType *elemtype; /* pointer to c_type for elements in array,	follow it to find its base type, etc.*/
      } arry;
      struct struc {		/* structs */
         char *label;
			int nfields;
         Field **f;
		} struc;
		struct func {
			char *label;
			struct NType *retType;
			struct NType *args;
		} func;
		struct touple {
			int nelems;
			struct NType **elems;
		} touple;
      struct ctype *p;		/* pointer type, points at another type */
   } u;
}NType;

typedef struct TreeNode {
	int symbol;		/* <1000 is terminal, >=1000 is non-terminal */
	NType *type;
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
} TreeNode;

typedef struct ErrorMessage{
   int number;
	char *errorType;
	char *message;
}ErrorMessage;
