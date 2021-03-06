/*
 * John Goettsche
 * cs 445
 * codedef.h
 */

#define TP_CALC 220001 
#define TP_EQUA 220002
 
/* memory definitions */
#define GLOBAL_MEM 200001
#define PARAM_MEM 200002
#define LOCAL_MEM 200003
#define CODE_MEM 200004

/* code definitions */
#define C_LABEL 210001
#define C_PARAM 210002
#define C_ASN 210003

#define C_LT 210009
#define C_GT 210010
#define C_LTEQ 210011
#define C_GTEQ 210012
#define C_EQ 210013
#define C_NOTEQ 210014
#define C_AND 210015
#define C_EXOR 210016
#define C_INOR 210017
#define C_ANDAND 210018
#define C_OROR 210019

#define C_BR 210100
#define C_GOTO 210101
#define C_RET 210102 
#define C_BRK 210103
#define C_CONT 210104

#define C_IDENT 210200

#define C_INT_LIT 210201
#define C_CHAR_LIT 210202
#define C_FLT_LIT 210203
#define C_STR_LIT 210204
#define C_BOOL_LIT 210205

#define C_NOT 210300
#define C_ADD1 210301
#define C_SUB1 210302
#define C_ASN_INT 210303
#define C_MULT 210304
#define C_DIV 210305
#define C_MOD 210306
#define C_ADD 210307
#define C_SUB 210308
#define C_MULEQ 210309
#define C_DIVEQ 210310
#define C_MODEQ 210311
#define C_ADDEQ 210312
#define C_SUBEQ 210313
#define C_SREQ 210314
#define C_SLEQ 210315
#define C_ANDEQ 210316
#define C_XOREQ 210317
#define C_OREQ 210318

#define C_FUNC 210400
#define C_CLASS 210401
#define C_DCODE 210402
#define C_DSTRING 210403
#define C_CALL 210404
