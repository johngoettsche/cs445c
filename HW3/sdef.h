

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
         int size;
			struct NType *elemtype; 
      } arry;
      struct struc {		
         char *label;
			int nfields;
         Field **f;
		} struc;
		struct clas { 
			char *label;
			int nfields;
			Field **f;
		} clas;
		struct func {
			char *label;
			struct NType *retType;
			struct NType *args;
		} func;
		struct touple {
			int nelems;
			struct NType **elems;
		} touple;
      struct NType *p;		/* pointer type, points at another type */
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

typedef struct Symbol{
	int type;
	char *label;
	union{
		struct IntegerType {
			int value;
		}intgr;
		struct CharType {
			char value;
		}chr;
		struct FloatType {
			float value;
		}flt;
		struct StringType {
			char *value;
		}str;
	}u;
}Symbol;

typedef struct SymbolTableEntry{
	Symbol *symbol;
	NType *type;
	struct SymbolTableEntry *next;
}SymbolTableEntry;

typedef struct SymbolTable{
	int size;
	int entries;
	NType *scope;
	struct SymbolTable *parent;
	SymbolTableEntry **bucket;
}SymbolTable;

typedef struct ErrorMessage{
   int number;
	char *errorType;
	char *message;
}ErrorMessage;


