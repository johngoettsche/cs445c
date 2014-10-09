/*
 * John Goettsche
 * CS445
 * Homework #3
 * types.h
 */
 
#define TYPE_NULL 100000
#define TYPE_INT 100001
#define TYPE_CHAR 100002

#define TYPE_ARRAY 100021

#define TYPE_CLASS 100031
#define TYPE_STRUCT 100032
#define TYPE_UNION 100033

#define TYPE_METHOD 100041

typedef struct Field Field;
struct Field {			/* members (fields) of structs */
   char *name;
   struct ctype *elemtype;
}

typedef struct SymbolType SymbolType;
struct SymbolType {
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
	 Type *elemtype; /* pointer to c_type for elements in array,
	 				follow it to find its base type, etc.*/
      } a;
      struct c
      struct struc {		/* structs */
         char *label;
	 int nfields;
         Field **f;
	 } s;
      struct ctype *p;		/* pointer type, points at another type */
   } u;
}
