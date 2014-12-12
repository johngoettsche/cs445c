
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

/* intermediate code data */
typedef struct Location {
	struct NType *region;
	int offset;
	char *val;
	struct CodeElem *elem;
}Location;
  
typedef struct CodeElem {
	int desc;
	char *label;
	Location **loc;
}CodeElem;

typedef struct IntrCode {
	CodeElem *elem;
	struct IntrCode *next;
}IntrCode;

typedef struct Field {			/* members (fields) of structs */
   char *name;
   struct NType *elemtype;
}Field;

typedef struct NType {
	int lineno;
   int base_type;
	char *label;
	char *val;
	int pub;
	char *ref;
	struct NType *cType;
	struct SymbolTable *symbTable;
	int offset;
	struct NType *first;
	struct NType *follow;
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
	Location *place;
	IntrCode *intCode;
	int lineno;
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
	int offset;
	struct SymbolTableEntry *next;
}SymbolTableEntry;

typedef struct SymbolListItem{
	NType *item;
	int offset;
	struct SymbolListItem *next;
}SymbolListItem;

typedef struct SymbolList{
	int size;
	SymbolListItem *head;
	SymbolListItem *tail;
}SymbolList;

typedef struct SymbolTable{
	int size;
	int entries;
	int offset;
	NType *scope; /* what block is it associated */
	struct SymbolTable *parent;
	SymbolTableEntry **bucket;
	int children;
	struct SymbolTable **child;
	SymbolList *list; /* holds local variables in a linked list */
}SymbolTable;

typedef struct ErrorMessage{
   int number;
	int lineno;
	char *errorType;
	char *message;
}ErrorMessage;


