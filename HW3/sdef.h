

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
   struct NType *elemtype;
}Field;

typedef struct NType {
   int base_type;
	char *label;
	int pub;
	//struct NType *pub;
   union {
      struct array {
         int size;
			struct NType *elemtype; 
      } arry;
      struct struc {		
			int nfields;
         Field **f;
		} struc;
		struct clas { 
			int nfields;
			Field **f;
		} clas;
		struct func {
			char *parent;
			struct NType *retType;
			int nargs;
			struct Field **args;
		} func;
		struct touple {
			int nelems;
			struct NType **elems;
		} touple;
      struct NType *ptr;		/* pointer type, points at another type */
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

typedef struct SymbolTableEntry{
	//Symbol *symbol;
	NType *symb;
	struct SymbolTableEntry *next;
}SymbolTableEntry;

typedef struct SymbolTable{
	int size;
	int entries;
	NType *scope;
	struct SymbolTable *parent;
	SymbolTableEntry **bucket;
	int children;
	struct SymbolTable **child;
}SymbolTable;

typedef struct ErrorMessage{
   int number;
	char *errorType;
	char *message;
}ErrorMessage;


