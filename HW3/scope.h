/*
 * John Goettsche
 * CS445
 * Homework #3
 */

/*
 * from Dr. Jeffery's example in the class notes
 */
struct c_type {
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
	 struct c_type *elemtype; /* pointer to c_type for elements in array,
	 				follow it to find its base type, etc.*/
      } a;
      struct struc {		/* structs */
         char *label;
	 int nfields;
         struct field **f;
	 } s;
      struct ctype *p;		/* pointer type, points at another type */
   } u;
}

struct field {			/* members (fields) of structs */
   char *name;
   struct ctype *elemtype;
}
