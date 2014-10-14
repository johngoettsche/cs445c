/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 53 "120gram.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "sdef.h"
#include "parsedef.h"
//#include "symbol.h"
#include "errors.h"

#define SYMBOL_TABLE_SIZE 31

extern int lineno;
int yydebug=1;
FILE *yyin;
char *fname;
int errors;
ErrorMessage *e_message;
TreeNode *root;
extern int exitStatus;
SymbolTable *globalSymbolTable;
SymbolTable *currentSymbolTable;



/* Line 189 of yacc.c  */
#line 100 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INTEGER = 259,
     FLOATING = 260,
     CHARACTER = 261,
     STRING = 262,
     TYPEDEF_NAME = 263,
     NAMESPACE_NAME = 264,
     CLASS_NAME = 265,
     ENUM_NAME = 266,
     TEMPLATE_NAME = 267,
     ELLIPSIS = 268,
     COLONCOLON = 269,
     DOTSTAR = 270,
     ADDEQ = 271,
     SUBEQ = 272,
     MULEQ = 273,
     DIVEQ = 274,
     MODEQ = 275,
     XOREQ = 276,
     ANDEQ = 277,
     OREQ = 278,
     SL = 279,
     SR = 280,
     SREQ = 281,
     SLEQ = 282,
     EQ = 283,
     NOTEQ = 284,
     LTEQ = 285,
     GTEQ = 286,
     ANDAND = 287,
     OROR = 288,
     PLUSPLUS = 289,
     MINUSMINUS = 290,
     ARROWSTAR = 291,
     ARROW = 292,
     ASM = 293,
     AUTO = 294,
     BOOL = 295,
     BREAK = 296,
     CASE = 297,
     CATCH = 298,
     CHAR = 299,
     CLASS = 300,
     CONST = 301,
     CONST_CAST = 302,
     CONTINUE = 303,
     DEFAULT = 304,
     DELETE = 305,
     DO = 306,
     DOUBLE = 307,
     DYNAMIC_CAST = 308,
     ELSE = 309,
     ENUM = 310,
     EXPLICIT = 311,
     EXPORT = 312,
     EXTERN = 313,
     FALSE = 314,
     FLOAT = 315,
     FOR = 316,
     FRIEND = 317,
     GOTO = 318,
     IF = 319,
     INLINE = 320,
     INT = 321,
     LONG = 322,
     MUTABLE = 323,
     NAMESPACE = 324,
     NEW = 325,
     OPERATOR = 326,
     PRIVATE = 327,
     PROTECTED = 328,
     PUBLIC = 329,
     REGISTER = 330,
     REINTERPRET_CAST = 331,
     RETURN = 332,
     SHORT = 333,
     SIGNED = 334,
     SIZEOF = 335,
     STATIC = 336,
     STATIC_CAST = 337,
     STRUCT = 338,
     SWITCH = 339,
     TEMPLATE = 340,
     THIS = 341,
     THROW = 342,
     TRUE = 343,
     TRY = 344,
     TYPEDEF = 345,
     TYPEID = 346,
     TYPENAME = 347,
     UNION = 348,
     UNSIGNED = 349,
     USING = 350,
     VIRTUAL = 351,
     VOID = 352,
     VOLATILE = 353,
     WCHAR_T = 354,
     WHILE = 355,
     STR_TYPE = 356
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INTEGER 259
#define FLOATING 260
#define CHARACTER 261
#define STRING 262
#define TYPEDEF_NAME 263
#define NAMESPACE_NAME 264
#define CLASS_NAME 265
#define ENUM_NAME 266
#define TEMPLATE_NAME 267
#define ELLIPSIS 268
#define COLONCOLON 269
#define DOTSTAR 270
#define ADDEQ 271
#define SUBEQ 272
#define MULEQ 273
#define DIVEQ 274
#define MODEQ 275
#define XOREQ 276
#define ANDEQ 277
#define OREQ 278
#define SL 279
#define SR 280
#define SREQ 281
#define SLEQ 282
#define EQ 283
#define NOTEQ 284
#define LTEQ 285
#define GTEQ 286
#define ANDAND 287
#define OROR 288
#define PLUSPLUS 289
#define MINUSMINUS 290
#define ARROWSTAR 291
#define ARROW 292
#define ASM 293
#define AUTO 294
#define BOOL 295
#define BREAK 296
#define CASE 297
#define CATCH 298
#define CHAR 299
#define CLASS 300
#define CONST 301
#define CONST_CAST 302
#define CONTINUE 303
#define DEFAULT 304
#define DELETE 305
#define DO 306
#define DOUBLE 307
#define DYNAMIC_CAST 308
#define ELSE 309
#define ENUM 310
#define EXPLICIT 311
#define EXPORT 312
#define EXTERN 313
#define FALSE 314
#define FLOAT 315
#define FOR 316
#define FRIEND 317
#define GOTO 318
#define IF 319
#define INLINE 320
#define INT 321
#define LONG 322
#define MUTABLE 323
#define NAMESPACE 324
#define NEW 325
#define OPERATOR 326
#define PRIVATE 327
#define PROTECTED 328
#define PUBLIC 329
#define REGISTER 330
#define REINTERPRET_CAST 331
#define RETURN 332
#define SHORT 333
#define SIGNED 334
#define SIZEOF 335
#define STATIC 336
#define STATIC_CAST 337
#define STRUCT 338
#define SWITCH 339
#define TEMPLATE 340
#define THIS 341
#define THROW 342
#define TRUE 343
#define TRY 344
#define TYPEDEF 345
#define TYPEID 346
#define TYPENAME 347
#define UNION 348
#define UNSIGNED 349
#define USING 350
#define VIRTUAL 351
#define VOID 352
#define VOLATILE 353
#define WCHAR_T 354
#define WHILE 355
#define STR_TYPE 356




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 80 "120gram.y"

	struct TreeNode *n;



/* Line 214 of yacc.c  */
#line 344 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 356 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  179
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4070

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  128
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  171
/* YYNRULES -- Number of rules.  */
#define YYNRULES  504
/* YYNRULES -- Number of states.  */
#define YYNSTATES  857

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   356

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   115,     2,     2,     2,   117,   112,     2,
     102,   103,   111,   113,   110,   114,   107,   116,   126,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   121,   123,
     108,   122,   109,   120,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   105,     2,   106,   118,   127,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   124,   119,   125,   104,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    51,    53,    55,    57,    59,
      61,    63,    66,    69,    73,    77,    81,    84,    87,    89,
      94,    99,   105,   110,   115,   119,   125,   130,   135,   139,
     142,   145,   153,   161,   169,   177,   182,   187,   189,   193,
     195,   198,   201,   204,   207,   210,   213,   218,   220,   222,
     224,   226,   228,   230,   235,   241,   248,   256,   260,   263,
     266,   268,   272,   277,   281,   284,   288,   293,   299,   301,
     306,   308,   312,   316,   318,   322,   326,   330,   332,   336,
     340,   342,   346,   350,   352,   356,   360,   364,   368,   370,
     374,   378,   380,   384,   386,   390,   392,   396,   398,   402,
     404,   408,   410,   416,   418,   422,   424,   426,   428,   430,
     432,   434,   436,   438,   440,   442,   444,   446,   448,   452,
     454,   456,   458,   460,   462,   464,   466,   468,   470,   474,
     479,   483,   486,   490,   492,   495,   501,   509,   515,   517,
     522,   528,   536,   545,   547,   549,   552,   555,   559,   563,
     565,   567,   570,   572,   574,   576,   578,   580,   582,   584,
     586,   588,   590,   592,   594,   598,   601,   603,   605,   607,
     609,   611,   613,   616,   618,   620,   622,   624,   626,   628,
     630,   632,   634,   636,   638,   640,   642,   644,   647,   651,
     653,   655,   657,   659,   661,   663,   665,   667,   669,   671,
     673,   675,   677,   679,   681,   686,   690,   695,   699,   703,
     708,   716,   722,   724,   728,   730,   734,   736,   738,   740,
     742,   744,   750,   756,   761,   763,   769,   773,   776,   779,
     781,   788,   794,   800,   805,   810,   817,   823,   829,   834,
     840,   846,   850,   852,   856,   859,   861,   864,   866,   873,
     879,   885,   890,   895,   902,   909,   914,   918,   920,   923,
     925,   928,   932,   936,   941,   943,   946,   948,   950,   952,
     955,   959,   962,   965,   968,   971,   973,   980,   986,   992,
     997,  1002,  1006,  1009,  1011,  1013,  1014,  1018,  1020,  1024,
    1027,  1032,  1035,  1040,  1044,  1049,  1052,  1056,  1058,  1061,
    1065,  1067,  1072,  1075,  1077,  1081,  1086,  1089,  1093,  1097,
    1102,  1104,  1106,  1108,  1111,  1115,  1119,  1122,  1125,  1127,
    1130,  1133,  1135,  1137,  1139,  1143,  1145,  1148,  1151,  1155,
    1158,  1161,  1164,  1166,  1170,  1174,  1177,  1180,  1182,  1188,
    1193,  1198,  1202,  1208,  1213,  1218,  1222,  1224,  1226,  1228,
    1231,  1234,  1237,  1240,  1242,  1246,  1251,  1255,  1258,  1261,
    1263,  1265,  1268,  1270,  1272,  1276,  1280,  1282,  1284,  1286,
    1288,  1290,  1292,  1294,  1296,  1298,  1300,  1302,  1304,  1306,
    1308,  1310,  1312,  1314,  1316,  1318,  1320,  1322,  1324,  1326,
    1328,  1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,  1346,
    1348,  1350,  1352,  1355,  1358,  1365,  1367,  1371,  1373,  1375,
    1378,  1383,  1386,  1391,  1398,  1407,  1412,  1414,  1418,  1420,
    1422,  1424,  1427,  1432,  1436,  1441,  1444,  1450,  1453,  1456,
    1458,  1460,  1463,  1468,  1470,  1474,  1475,  1477,  1478,  1480,
    1481,  1483,  1484,  1486,  1487,  1489,  1490,  1492,  1493,  1495,
    1496,  1498,  1499,  1501,  1502,  1504,  1505,  1507,  1508,  1510,
    1511,  1513,  1514,  1516,  1517,  1519,  1520,  1522,  1523,  1525,
    1526,  1528,  1529,  1531,  1532,  1534,  1535,  1537,  1538,  1540,
    1541,  1543,  1544,  1546,  1547
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     142,     0,    -1,     8,    -1,   131,    -1,     9,    -1,    10,
      -1,   261,    -1,    11,    -1,    12,    -1,     3,    -1,   137,
      -1,   138,    -1,   139,    -1,   140,    -1,   141,    -1,     4,
      -1,     6,    -1,     5,    -1,     7,    -1,    88,    -1,    59,
      -1,   274,    -1,   136,    -1,    86,    -1,   102,   174,   103,
      -1,   144,    -1,   145,    -1,   146,    -1,   135,    -1,   255,
      -1,   248,    -1,   104,   132,    -1,   147,   145,    -1,   147,
      85,   145,    -1,   132,    14,   147,    -1,   130,    14,   147,
      -1,   132,    14,    -1,   130,    14,    -1,   143,    -1,   148,
     105,   174,   106,    -1,   148,   102,   276,   103,    -1,   148,
     107,    85,    14,   144,    -1,   148,   107,    85,   144,    -1,
     148,   107,    14,   144,    -1,   148,   107,   144,    -1,   148,
      37,    85,    14,   144,    -1,   148,    37,    85,   144,    -1,
     148,    37,    14,   144,    -1,   148,    37,   144,    -1,   148,
      34,    -1,   148,    35,    -1,    53,   108,   223,   109,   102,
     174,   103,    -1,    82,   108,   223,   109,   102,   174,   103,
      -1,    76,   108,   223,   109,   102,   174,   103,    -1,    47,
     108,   223,   109,   102,   174,   103,    -1,    91,   102,   174,
     103,    -1,    91,   102,   223,   103,    -1,   172,    -1,   149,
     110,   172,    -1,   148,    -1,    34,   159,    -1,    35,   159,
      -1,   111,   159,    -1,   112,   159,    -1,   151,   159,    -1,
      80,   150,    -1,    80,   102,   223,   103,    -1,   152,    -1,
     158,    -1,   113,    -1,   114,    -1,   115,    -1,   104,    -1,
      70,   278,   154,   279,    -1,    14,    70,   278,   154,   279,
      -1,    70,   278,   102,   223,   103,   279,    -1,    14,    70,
     278,   102,   223,   103,   279,    -1,   102,   149,   103,    -1,
     224,   280,    -1,   219,   280,    -1,   156,    -1,   105,   174,
     106,    -1,   156,   105,   175,   106,    -1,   102,   276,   103,
      -1,    50,   159,    -1,    14,    50,   159,    -1,    50,   105,
     106,   159,    -1,    14,    50,   105,   106,   159,    -1,   150,
      -1,   102,   223,   103,   159,    -1,   159,    -1,   160,    15,
     159,    -1,   160,    36,   159,    -1,   160,    -1,   161,   111,
     160,    -1,   161,   116,   160,    -1,   161,   117,   160,    -1,
     161,    -1,   162,   113,   161,    -1,   162,   114,   161,    -1,
     162,    -1,   163,    24,   162,    -1,   163,    25,   162,    -1,
     163,    -1,   164,   108,   163,    -1,   164,   109,   163,    -1,
     164,    30,   163,    -1,   164,    31,   163,    -1,   164,    -1,
     165,    28,   164,    -1,   165,    29,   164,    -1,   165,    -1,
     166,   112,   165,    -1,   166,    -1,   167,   118,   166,    -1,
     167,    -1,   168,   119,   167,    -1,   168,    -1,   169,    32,
     168,    -1,   169,    -1,   170,    33,   169,    -1,   170,    -1,
     170,   120,   174,   121,   172,    -1,   171,    -1,   170,   173,
     172,    -1,   271,    -1,   122,    -1,    18,    -1,    19,    -1,
      20,    -1,    16,    -1,    17,    -1,    26,    -1,    27,    -1,
      22,    -1,    21,    -1,    23,    -1,   172,    -1,   174,   110,
     172,    -1,   171,    -1,   177,    -1,   178,    -1,   179,    -1,
     181,    -1,   183,    -1,   185,    -1,   186,    -1,   266,    -1,
     135,   121,   176,    -1,    42,   175,   121,   176,    -1,    49,
     121,   176,    -1,   281,   123,    -1,   124,   282,   125,    -1,
     176,    -1,   180,   176,    -1,    64,   102,   182,   103,   176,
      -1,    64,   102,   182,   103,   176,    54,   176,    -1,    84,
     102,   182,   103,   176,    -1,   174,    -1,   224,   217,   122,
     172,    -1,   100,   102,   182,   103,   176,    -1,    51,   176,
     100,   102,   174,   103,   123,    -1,    61,   102,   184,   283,
     123,   281,   103,   176,    -1,   178,    -1,   190,    -1,    41,
     123,    -1,    48,   123,    -1,    77,   281,   123,    -1,    63,
     135,   123,    -1,   189,    -1,   188,    -1,   187,   188,    -1,
     189,    -1,   230,    -1,   257,    -1,   264,    -1,   265,    -1,
     214,    -1,   203,    -1,   190,    -1,   213,    -1,   209,    -1,
     211,    -1,   212,    -1,   192,   215,   123,    -1,   192,   123,
      -1,   193,    -1,   195,    -1,   194,    -1,    62,    -1,    90,
      -1,   191,    -1,   192,   191,    -1,    39,    -1,    75,    -1,
      81,    -1,    58,    -1,    68,    -1,    65,    -1,    96,    -1,
      56,    -1,   196,    -1,   235,    -1,   199,    -1,   198,    -1,
     221,    -1,   197,    -1,   147,   197,    -1,    14,   275,   197,
      -1,    44,    -1,    99,    -1,    40,    -1,    78,    -1,    66,
      -1,    67,    -1,    79,    -1,    94,    -1,    60,    -1,    52,
      -1,    97,    -1,   101,    -1,   132,    -1,   133,    -1,   129,
      -1,   237,    14,   147,   135,    -1,   237,    14,   135,    -1,
      55,    14,   147,   135,    -1,    55,    14,   135,    -1,    55,
     147,   135,    -1,    92,   277,   147,   135,    -1,    92,   277,
     147,   135,   108,   262,   109,    -1,    55,   135,   124,   284,
     125,    -1,   201,    -1,   200,   110,   201,    -1,   202,    -1,
     202,   122,   175,    -1,   135,    -1,   204,    -1,   207,    -1,
     205,    -1,   206,    -1,    69,   135,   124,   208,   125,    -1,
      69,   131,   124,   208,   125,    -1,    69,   124,   208,   125,
      -1,   274,    -1,    69,   135,   122,   210,   123,    -1,    14,
     147,   130,    -1,    14,   130,    -1,   147,   130,    -1,   130,
      -1,    95,    92,    14,   147,   145,   123,    -1,    95,    92,
     147,   145,   123,    -1,    95,    14,   147,   145,   123,    -1,
      95,   147,   145,   123,    -1,    95,    14,   145,   123,    -1,
      95,    69,    14,   147,   130,   123,    -1,    95,    69,    14,
     130,   123,    -1,    95,    69,   147,   130,   123,    -1,    95,
      69,   130,   123,    -1,    38,   102,   140,   103,   123,    -1,
      58,   140,   124,   274,   125,    -1,    58,   140,   188,    -1,
     216,    -1,   215,   110,   216,    -1,   217,   285,    -1,   218,
      -1,   219,   217,    -1,   222,    -1,   218,   102,   227,   103,
     220,   272,    -1,   218,   102,   227,   103,   220,    -1,   218,
     102,   227,   103,   272,    -1,   218,   102,   227,   103,    -1,
      10,   102,   227,   103,    -1,    10,    14,   222,   102,   227,
     103,    -1,    10,    14,    10,   102,   227,   103,    -1,   218,
     105,   286,   106,    -1,   102,   217,   103,    -1,   111,    -1,
     111,   220,    -1,   112,    -1,   147,   111,    -1,   147,   111,
     220,    -1,    14,   147,   111,    -1,    14,   147,   111,   220,
      -1,   221,    -1,   221,   220,    -1,    46,    -1,    98,    -1,
     144,    -1,    14,   144,    -1,    14,   147,   197,    -1,    14,
     197,    -1,   224,   287,    -1,   195,   288,    -1,   219,   287,
      -1,   226,    -1,   289,   102,   227,   103,   220,   272,    -1,
     289,   102,   227,   103,   220,    -1,   289,   102,   227,   103,
     272,    -1,   289,   102,   227,   103,    -1,   289,   105,   286,
     106,    -1,   102,   225,   103,    -1,   228,    13,    -1,   228,
      -1,    13,    -1,    -1,   228,   110,    13,    -1,   229,    -1,
     228,   110,   229,    -1,   192,   217,    -1,   192,   217,   122,
     172,    -1,   192,   287,    -1,   192,   287,   122,   172,    -1,
     217,   290,   231,    -1,   192,   217,   290,   231,    -1,   217,
     267,    -1,   192,   217,   267,    -1,   179,    -1,   122,   233,
      -1,   102,   149,   103,    -1,   172,    -1,   124,   234,   291,
     125,    -1,   124,   125,    -1,   233,    -1,   234,   110,   233,
      -1,   236,   124,   292,   125,    -1,   237,   132,    -1,   237,
     132,   244,    -1,   237,   147,   132,    -1,   237,   147,   132,
     244,    -1,    45,    -1,    83,    -1,    93,    -1,   239,   292,
      -1,   247,   121,   292,    -1,   192,   240,   123,    -1,   192,
     123,    -1,   240,   123,    -1,   123,    -1,   230,   293,    -1,
     146,   123,    -1,   211,    -1,   257,    -1,   241,    -1,   240,
     110,   241,    -1,   217,    -1,   217,   242,    -1,   217,   243,
      -1,   135,   121,   175,    -1,   122,   126,    -1,   122,   175,
      -1,   121,   245,    -1,   246,    -1,   245,   110,   246,    -1,
      14,   147,   132,    -1,    14,   132,    -1,   147,   132,    -1,
     132,    -1,    96,   247,    14,   275,   132,    -1,    96,   247,
     275,   132,    -1,    96,    14,   275,   132,    -1,    96,   275,
     132,    -1,   247,    96,    14,   275,   132,    -1,   247,    96,
     275,   132,    -1,   247,    14,   275,   132,    -1,   247,   275,
     132,    -1,    72,    -1,    73,    -1,    74,    -1,    71,   249,
      -1,   224,   294,    -1,   219,   294,    -1,   121,   252,    -1,
     253,    -1,   253,   110,   252,    -1,   254,   102,   276,   103,
      -1,    14,   147,   132,    -1,    14,   132,    -1,   147,   132,
      -1,   132,    -1,   135,    -1,    71,   256,    -1,    70,    -1,
      50,    -1,    70,   105,   106,    -1,    50,   105,   106,    -1,
     113,    -1,   127,    -1,   111,    -1,   116,    -1,   117,    -1,
     118,    -1,   112,    -1,   119,    -1,   104,    -1,   115,    -1,
     122,    -1,   108,    -1,   109,    -1,    16,    -1,    17,    -1,
      18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,
      28,    -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,
      33,    -1,    34,    -1,    35,    -1,   110,    -1,    36,    -1,
      37,    -1,   102,   103,    -1,   105,   106,    -1,   295,    85,
     108,   258,   109,   188,    -1,   259,    -1,   258,   110,   259,
      -1,   260,    -1,   229,    -1,    45,   135,    -1,    45,   135,
     122,   223,    -1,    92,   135,    -1,    92,   135,   122,   223,
      -1,    85,   108,   258,   109,    45,   135,    -1,    85,   108,
     258,   109,    45,   135,   122,   134,    -1,   134,   108,   262,
     109,    -1,   263,    -1,   262,   110,   263,    -1,   172,    -1,
     223,    -1,   134,    -1,    85,   188,    -1,    85,   108,   109,
     188,    -1,    89,   179,   268,    -1,    89,   290,   231,   268,
      -1,   269,   296,    -1,    43,   102,   270,   103,   179,    -1,
     224,   217,    -1,   224,   225,    -1,   224,    -1,    13,    -1,
      87,   297,    -1,    87,   102,   298,   103,    -1,   223,    -1,
     273,   110,   223,    -1,    -1,   187,    -1,    -1,   147,    -1,
      -1,   149,    -1,    -1,    14,    -1,    -1,   153,    -1,    -1,
     157,    -1,    -1,   155,    -1,    -1,   174,    -1,    -1,   180,
      -1,    -1,   182,    -1,    -1,   200,    -1,    -1,   232,    -1,
      -1,   175,    -1,    -1,   225,    -1,    -1,   224,    -1,    -1,
     226,    -1,    -1,   251,    -1,    -1,   110,    -1,    -1,   238,
      -1,    -1,   123,    -1,    -1,   250,    -1,    -1,    57,    -1,
      -1,   268,    -1,    -1,   172,    -1,    -1,   273,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   144,   144,   148,   153,   158,   159,   168,   173,   185,
     189,   190,   191,   192,   193,   197,   201,   205,   209,   213,
     214,   222,   230,   231,   232,   233,   237,   238,   242,   243,
     244,   245,   249,   250,   254,   255,   256,   257,   261,   262,
     263,   264,   266,   267,   268,   269,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   285,   286,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   303,
     304,   305,   306,   310,   312,   314,   316,   321,   325,   329,
     330,   334,   335,   339,   343,   344,   345,   346,   350,   351,
     355,   356,   357,   361,   362,   363,   364,   368,   369,   370,
     374,   375,   376,   380,   381,   382,   383,   384,   388,   389,
     390,   394,   395,   399,   400,   404,   405,   409,   410,   415,
     416,   420,   421,   426,   427,   429,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   447,   448,   452,
     460,   461,   462,   463,   464,   465,   466,   467,   471,   472,
     473,   477,   481,   485,   486,   490,   491,   492,   496,   497,
     502,   503,   504,   509,   510,   514,   515,   516,   517,   521,
     529,   530,   534,   535,   536,   541,   542,   543,   544,   548,
     549,   550,   551,   552,   556,   557,   561,   562,   563,   564,
     565,   569,   570,   574,   575,   576,   577,   578,   582,   583,
     584,   588,   589,   590,   591,   592,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   614,   615,   616,   620,   621,   622,   623,   624,   625,
     627,   642,   646,   647,   651,   652,   656,   671,   672,   676,
     677,   681,   685,   690,   694,   704,   709,   710,   711,   712,
     716,   718,   720,   722,   723,   727,   729,   730,   732,   736,
     740,   741,   749,   750,   754,   758,   759,   763,   764,   766,
     768,   770,   772,   773,   775,   777,   778,   782,   783,   784,
     785,   786,   787,   788,   793,   794,   798,   799,   803,   804,
     805,   806,   810,   814,   818,   819,   823,   825,   827,   829,
     831,   833,   837,   838,   839,   840,   841,   845,   846,   851,
     852,   854,   855,   860,   861,   863,   864,   868,   872,   873,
     877,   878,   879,   883,   884,   892,   896,   897,   898,   899,
     904,   905,   906,   910,   911,   915,   916,   917,   918,   919,
     920,   921,   922,   930,   931,   935,   936,   937,   938,   947,
     951,   959,   963,   964,   968,   969,   970,   971,   972,   974,
     976,   978,   979,   981,   983,   985,   990,   991,   992,  1000,
    1004,  1008,  1012,  1016,  1017,  1021,  1025,  1026,  1027,  1028,
    1029,  1037,  1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1090,  1099,  1104,  1112,  1117,  1125,
    1130,  1135,  1140,  1145,  1150,  1158,  1165,  1170,  1178,  1183,
    1188,  1196,  1204,  1216,  1220,  1224,  1228,  1233,  1234,  1235,
    1236,  1240,  1244,  1248,  1249,  1257,  1258,  1262,  1263,  1267,
    1268,  1272,  1273,  1277,  1278,  1282,  1283,  1287,  1288,  1292,
    1293,  1297,  1298,  1302,  1303,  1307,  1308,  1312,  1313,  1317,
    1318,  1322,  1323,  1327,  1328,  1332,  1333,  1337,  1338,  1342,
    1343,  1347,  1348,  1352,  1353,  1357,  1358,  1362,  1363,  1367,
    1368,  1372,  1373,  1377,  1378
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER", "FLOATING",
  "CHARACTER", "STRING", "TYPEDEF_NAME", "NAMESPACE_NAME", "CLASS_NAME",
  "ENUM_NAME", "TEMPLATE_NAME", "ELLIPSIS", "COLONCOLON", "DOTSTAR",
  "ADDEQ", "SUBEQ", "MULEQ", "DIVEQ", "MODEQ", "XOREQ", "ANDEQ", "OREQ",
  "SL", "SR", "SREQ", "SLEQ", "EQ", "NOTEQ", "LTEQ", "GTEQ", "ANDAND",
  "OROR", "PLUSPLUS", "MINUSMINUS", "ARROWSTAR", "ARROW", "ASM", "AUTO",
  "BOOL", "BREAK", "CASE", "CATCH", "CHAR", "CLASS", "CONST", "CONST_CAST",
  "CONTINUE", "DEFAULT", "DELETE", "DO", "DOUBLE", "DYNAMIC_CAST", "ELSE",
  "ENUM", "EXPLICIT", "EXPORT", "EXTERN", "FALSE", "FLOAT", "FOR",
  "FRIEND", "GOTO", "IF", "INLINE", "INT", "LONG", "MUTABLE", "NAMESPACE",
  "NEW", "OPERATOR", "PRIVATE", "PROTECTED", "PUBLIC", "REGISTER",
  "REINTERPRET_CAST", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC",
  "STATIC_CAST", "STRUCT", "SWITCH", "TEMPLATE", "THIS", "THROW", "TRUE",
  "TRY", "TYPEDEF", "TYPEID", "TYPENAME", "UNION", "UNSIGNED", "USING",
  "VIRTUAL", "VOID", "VOLATILE", "WCHAR_T", "WHILE", "STR_TYPE", "'('",
  "')'", "'~'", "'['", "']'", "'.'", "'<'", "'>'", "','", "'*'", "'&'",
  "'+'", "'-'", "'!'", "'/'", "'%'", "'^'", "'|'", "'?'", "':'", "'='",
  "';'", "'{'", "'}'", "'0'", "'_'", "$accept", "typedef_name",
  "namespace_name", "original_namespace_name", "class_name", "enum_name",
  "template_name", "identifier", "literal", "integer_literal",
  "character_literal", "floating_literal", "string_literal",
  "boolean_literal", "translation_unit", "primary_expression",
  "id_expression", "unqualified_id", "qualified_id",
  "nested_name_specifier", "postfix_expression", "expression_list",
  "unary_expression", "unary_operator", "new_expression", "new_placement",
  "new_type_id", "new_declarator", "direct_new_declarator",
  "new_initializer", "delete_expression", "cast_expression",
  "pm_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "statement", "labeled_statement",
  "expression_statement", "compound_statement", "statement_seq",
  "selection_statement", "condition", "iteration_statement",
  "for_init_statement", "jump_statement", "declaration_statement",
  "declaration_seq", "declaration", "block_declaration",
  "simple_declaration", "decl_specifier", "decl_specifier_seq",
  "storage_class_specifier", "function_specifier", "type_specifier",
  "simple_type_specifier", "type_name", "elaborated_type_specifier",
  "enum_specifier", "enumerator_list", "enumerator_definition",
  "enumerator", "namespace_definition", "named_namespace_definition",
  "original_namespace_definition", "extension_namespace_definition",
  "unnamed_namespace_definition", "namespace_body",
  "namespace_alias_definition", "qualified_namespace_specifier",
  "using_declaration", "using_directive", "asm_definition",
  "linkage_specification", "init_declarator_list", "init_declarator",
  "declarator", "direct_declarator", "ptr_operator", "cv_qualifier_seq",
  "cv_qualifier", "declarator_id", "type_id", "type_specifier_seq",
  "abstract_declarator", "direct_abstract_declarator",
  "parameter_declaration_clause", "parameter_declaration_list",
  "parameter_declaration", "function_definition", "function_body",
  "initializer", "initializer_clause", "initializer_list",
  "class_specifier", "class_head", "class_key", "member_specification",
  "member_declaration", "member_declarator_list", "member_declarator",
  "pure_specifier", "constant_initializer", "base_clause",
  "base_specifier_list", "base_specifier", "access_specifier",
  "conversion_function_id", "conversion_type_id", "conversion_declarator",
  "ctor_initializer", "mem_initializer_list", "mem_initializer",
  "mem_initializer_id", "operator_function_id", "operator",
  "template_declaration", "template_parameter_list", "template_parameter",
  "type_parameter", "template_id", "template_argument_list",
  "template_argument", "explicit_instantiation", "explicit_specialization",
  "try_block", "function_try_block", "handler_seq", "handler",
  "exception_declaration", "throw_expression", "exception_specification",
  "type_id_list", "declaration_seq_opt", "nested_name_specifier_opt",
  "expression_list_opt", "COLONCOLON_opt", "new_placement_opt",
  "new_initializer_opt", "new_declarator_opt", "expression_opt",
  "statement_seq_opt", "condition_opt", "enumerator_list_opt",
  "initializer_opt", "constant_expression_opt", "abstract_declarator_opt",
  "type_specifier_seq_opt", "direct_abstract_declarator_opt",
  "ctor_initializer_opt", "COMMA_opt", "member_specification_opt",
  "SEMICOLON_opt", "conversion_declarator_opt", "EXPORT_opt",
  "handler_seq_opt", "assignment_expression_opt", "type_id_list_opt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,    40,    41,   126,    91,    93,    46,    60,    62,
      44,    42,    38,    43,    45,    33,    47,    37,    94,   124,
      63,    58,    61,    59,   123,   125,    48,    95
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   128,   129,   130,   131,   132,   132,   133,   134,   135,
     136,   136,   136,   136,   136,   137,   138,   139,   140,   141,
     141,   142,   143,   143,   143,   143,   144,   144,   145,   145,
     145,   145,   146,   146,   147,   147,   147,   147,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   149,   149,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   151,
     151,   151,   151,   152,   152,   152,   152,   153,   154,   155,
     155,   156,   156,   157,   158,   158,   158,   158,   159,   159,
     160,   160,   160,   161,   161,   161,   161,   162,   162,   162,
     163,   163,   163,   164,   164,   164,   164,   164,   165,   165,
     165,   166,   166,   167,   167,   168,   168,   169,   169,   170,
     170,   171,   171,   172,   172,   172,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   174,   174,   175,
     176,   176,   176,   176,   176,   176,   176,   176,   177,   177,
     177,   178,   179,   180,   180,   181,   181,   181,   182,   182,
     183,   183,   183,   184,   184,   185,   185,   185,   185,   186,
     187,   187,   188,   188,   188,   188,   188,   188,   188,   189,
     189,   189,   189,   189,   190,   190,   191,   191,   191,   191,
     191,   192,   192,   193,   193,   193,   193,   193,   194,   194,
     194,   195,   195,   195,   195,   195,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   197,   197,   197,   198,   198,   198,   198,   198,   198,
     198,   199,   200,   200,   201,   201,   202,   203,   203,   204,
     204,   205,   206,   207,   208,   209,   210,   210,   210,   210,
     211,   211,   211,   211,   211,   212,   212,   212,   212,   213,
     214,   214,   215,   215,   216,   217,   217,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   219,   219,   219,
     219,   219,   219,   219,   220,   220,   221,   221,   222,   222,
     222,   222,   223,   224,   225,   225,   226,   226,   226,   226,
     226,   226,   227,   227,   227,   227,   227,   228,   228,   229,
     229,   229,   229,   230,   230,   230,   230,   231,   232,   232,
     233,   233,   233,   234,   234,   235,   236,   236,   236,   236,
     237,   237,   237,   238,   238,   239,   239,   239,   239,   239,
     239,   239,   239,   240,   240,   241,   241,   241,   241,   242,
     243,   244,   245,   245,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   247,   247,   247,   248,
     249,   250,   251,   252,   252,   253,   254,   254,   254,   254,
     254,   255,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   257,   258,   258,   259,   259,   260,
     260,   260,   260,   260,   260,   261,   262,   262,   263,   263,
     263,   264,   265,   266,   267,   268,   269,   270,   270,   270,
     270,   271,   272,   273,   273,   274,   274,   275,   275,   276,
     276,   277,   277,   278,   278,   279,   279,   280,   280,   281,
     281,   282,   282,   283,   283,   284,   284,   285,   285,   286,
     286,   287,   287,   288,   288,   289,   289,   290,   290,   291,
     291,   292,   292,   293,   293,   294,   294,   295,   295,   296,
     296,   297,   297,   298,   298
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     3,     3,     2,     2,     1,     4,
       4,     5,     4,     4,     3,     5,     4,     4,     3,     2,
       2,     7,     7,     7,     7,     4,     4,     1,     3,     1,
       2,     2,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     4,     5,     6,     7,     3,     2,     2,
       1,     3,     4,     3,     2,     3,     4,     5,     1,     4,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     2,     3,     1,     2,     5,     7,     5,     1,     4,
       5,     7,     8,     1,     1,     2,     2,     3,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     4,     3,     3,     4,
       7,     5,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     5,     5,     4,     1,     5,     3,     2,     2,     1,
       6,     5,     5,     4,     4,     6,     5,     5,     4,     5,
       5,     3,     1,     3,     2,     1,     2,     1,     6,     5,
       5,     4,     4,     6,     6,     4,     3,     1,     2,     1,
       2,     3,     3,     4,     1,     2,     1,     1,     1,     2,
       3,     2,     2,     2,     2,     1,     6,     5,     5,     4,
       4,     3,     2,     1,     1,     0,     3,     1,     3,     2,
       4,     2,     4,     3,     4,     2,     3,     1,     2,     3,
       1,     4,     2,     1,     3,     4,     2,     3,     3,     4,
       1,     1,     1,     2,     3,     3,     2,     2,     1,     2,
       2,     1,     1,     1,     3,     1,     2,     2,     3,     2,
       2,     2,     1,     3,     3,     2,     2,     1,     5,     4,
       4,     3,     5,     4,     4,     3,     1,     1,     1,     2,
       2,     2,     2,     1,     3,     4,     3,     2,     2,     1,
       1,     2,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     6,     1,     3,     1,     1,     2,
       4,     2,     4,     6,     8,     4,     1,     3,     1,     1,
       1,     2,     4,     3,     4,     2,     5,     2,     2,     1,
       1,     2,     4,     1,     3,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     455,     9,     2,     4,     5,     7,     8,     0,     0,   193,
     211,   209,   330,   286,   218,     0,   200,   498,   196,   217,
     189,   198,   213,   214,   197,     0,     0,   194,   212,   215,
     195,   331,     0,   190,   461,   332,   216,     0,   199,   219,
     287,   210,   220,     0,     0,   277,   279,   223,     0,     3,
     221,   222,     0,    28,     0,   288,    26,    27,     0,   456,
     170,   172,   179,   191,     0,   186,   188,   187,   201,   206,
     204,   203,   178,   237,   239,   240,   238,   181,   182,   183,
     180,   177,   487,   265,     0,   205,   267,   173,   202,     0,
       0,    30,    29,   174,     6,   175,   176,    21,     0,     0,
     305,     5,   289,     0,   291,     0,     0,     0,     0,     0,
       0,    18,     0,   455,     0,     0,   457,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   420,   421,   383,
     382,     0,   394,     0,   397,   398,   419,   388,   392,   386,
     395,   389,   390,   391,   393,   396,   387,     0,   483,   495,
     369,   381,     0,   441,   462,     0,     0,     0,     0,     0,
       0,     0,     0,    31,   278,   284,    37,    36,     0,     1,
       0,   280,   221,    32,   207,   171,   196,   185,   192,     0,
     262,   477,   487,     0,   488,   315,     0,   305,   479,   266,
     491,     0,   326,     0,     0,     5,     0,     0,     0,   304,
     481,     0,   303,   307,   282,   290,   208,     0,   227,     0,
     475,   228,   455,   261,     0,   244,   455,     0,   455,   458,
       0,     0,   422,   423,   484,   293,     0,     0,   495,   496,
     370,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,   285,    35,    34,    15,    17,    16,   457,
       0,     0,     0,     0,     0,    20,   463,     0,     0,     0,
      23,   501,    19,     0,     0,    72,     0,     0,    69,    70,
      71,   440,    22,    10,    11,    12,    13,    14,    38,    25,
       0,    59,    88,     0,    67,    68,    90,    93,    97,   100,
     103,   108,   111,   113,   115,   117,   119,   121,   123,   438,
     439,   481,     0,   436,   125,    33,   281,     0,   184,     0,
       0,   478,   316,   264,     0,     0,     0,   379,   380,     0,
     372,   373,     0,   469,   317,   313,     0,     0,   121,   139,
     480,     0,   366,   367,   368,     0,   338,    28,    27,     0,
     341,   345,   493,   492,   491,     0,   343,     0,   342,     0,
     225,     0,     0,   327,   328,     0,   305,     0,   305,   485,
     309,   481,   482,   295,   311,     0,   272,   302,     0,   283,
       0,   226,   236,   476,   232,   234,     0,     0,   243,     0,
       0,   249,     0,     0,     0,   385,   384,     0,   371,   442,
     229,   254,     0,     0,     0,   258,     0,     0,     0,   253,
       0,   463,    60,    61,     0,     0,    84,     0,     0,   464,
       0,     0,     0,    65,     0,   502,   451,     0,   137,     0,
       0,    62,    63,    49,    50,     0,   459,     0,     0,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   127,   128,   129,   135,   134,   136,   132,   133,     0,
       0,   126,     0,   485,   481,   292,   435,     0,   263,   477,
       0,    57,     0,   320,   318,   314,     0,   377,     0,   378,
       0,   459,     0,     0,     0,     0,   469,     0,     0,     0,
       0,   469,     0,     0,     0,    28,   470,   153,   140,   141,
     142,   469,   143,   144,   145,   146,   169,     0,   147,     0,
       0,   271,   275,     0,   340,   336,   345,     0,     0,   346,
     347,   494,   339,   333,     0,   337,   491,   325,   224,     0,
       0,   357,     0,   351,   352,     0,   329,   330,     0,   461,
     428,     0,   425,   427,     0,     0,     0,     0,   294,     0,
     305,   479,   306,   308,   259,     0,     0,   231,   260,   242,
     247,     0,   248,   245,   241,     0,   252,   256,     0,   257,
       0,   251,     0,    85,     0,     0,     0,     0,     0,     0,
     465,   467,     0,     0,     0,     0,     0,    24,     0,     0,
       0,     0,    48,   460,     0,     0,     0,     0,    44,    91,
      92,    94,    95,    96,    98,    99,   101,   102,   106,   107,
     104,   105,   109,   110,   112,   114,   116,   118,   120,     0,
     124,   437,   319,     0,   322,   323,   489,     0,   444,   499,
     376,   374,     0,   165,     0,   166,   469,     0,   469,     0,
       0,     0,     0,     0,     0,     0,   469,   154,   151,   152,
       0,   269,   270,   348,   335,   349,   350,   345,   344,   334,
     355,     0,     0,     0,     0,   356,     0,     0,     0,     0,
     429,     0,   431,     0,     0,   274,   273,   301,   310,   312,
       0,     0,   233,   235,   246,     0,   255,   250,     0,     0,
     465,     0,    86,     0,    77,     0,   459,   466,    73,     0,
     468,    80,   467,    78,     0,    66,     0,    55,    56,   138,
      89,    47,     0,    46,    40,    39,    43,     0,    42,     0,
      58,   490,     0,     0,   500,   445,   375,   469,   150,     0,
     163,   473,   164,   168,   158,     0,     0,   167,     0,   443,
       0,   148,   503,   268,   354,     0,     0,     0,   361,   353,
       0,     0,     0,   365,     0,     0,     0,   424,   426,   299,
     300,   230,    87,     0,    74,     0,     0,   465,     0,     0,
       0,    79,     0,     0,    45,    41,   122,   324,   321,   450,
     449,     0,   149,     0,   474,     0,   469,     0,   469,   469,
     453,   504,     0,   360,     0,   359,   364,     0,   363,   430,
       0,   432,   297,   298,   465,     0,     0,    75,    83,    81,
       0,     0,     0,   447,   448,     0,     0,   469,   155,     0,
     157,   160,     0,   452,   358,   362,     0,   296,    76,    54,
      51,    82,    53,    52,   446,     0,     0,   469,   159,   454,
     433,   161,   469,   156,     0,   162,   434
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    47,    48,    49,   108,    51,    52,    53,   282,   283,
     284,   285,   286,   287,    54,   288,   289,    56,    57,   207,
     291,   603,   292,   293,   294,   419,   590,   710,   711,   707,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   428,   472,   506,   340,   507,   508,
     509,   510,   511,   512,   745,   513,   741,   514,   515,    59,
      60,   516,    62,    63,   517,    65,    66,    67,    68,    69,
      70,    71,   383,   384,   385,    72,    73,    74,    75,    76,
     224,    77,   393,    78,    79,    80,    81,   189,   190,    82,
      83,    84,   174,    85,    86,   310,   311,   372,   373,   211,
     212,   213,    87,   335,   321,   484,   636,    88,    89,    90,
     353,   354,   355,   356,   529,   530,   363,   543,   544,   357,
      91,   160,   239,   194,   330,   331,   332,    92,   161,    93,
     551,   552,   553,    94,   312,   313,    95,    96,   518,   195,
     638,   639,   791,   314,   662,   801,   225,   105,   604,   165,
     420,   708,   713,   519,   520,   795,   386,   323,   341,   558,
     235,   375,   196,   732,   359,   532,   240,    98,   735,   426,
     802
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -673
static const yytype_int16 yypact[] =
{
    3386,  -673,  -673,  -673,    54,  -673,  -673,   972,   -51,  -673,
    -673,  -673,  -673,  -673,  -673,   318,  -673,  -673,    56,  -673,
    -673,  -673,  -673,  -673,  -673,    63,  2489,  -673,  -673,  -673,
    -673,  -673,  3280,  -673,    61,  -673,  -673,   517,  -673,  -673,
    -673,  -673,  -673,   510,   340,    47,  -673,  -673,    64,  -673,
      84,  -673,   -39,  -673,   140,  -673,  -673,  -673,   809,  3386,
    -673,  -673,  -673,  -673,  2276,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,   -22,   310,   510,  -673,  -673,  -673,  -673,    50,
     616,  -673,  -673,  -673,  -673,  -673,  -673,  -673,    75,    92,
    3644,  -673,  -673,   889,  -673,   504,    56,   221,    84,    65,
     206,  -673,  1974,  3386,    90,   319,   389,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,   135,
     156,   164,  -673,   171,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,   504,  3969,   261,
    -673,  -673,   163,  -673,  -673,   389,   864,   696,   709,    76,
     972,    39,   193,  -673,  -673,    47,   389,   389,  2727,  -673,
      76,    47,  -673,  -673,  -673,  -673,  -673,  -673,  -673,   -14,
    -673,   160,   201,   593,  -673,  -673,   212,  3644,  3107,  -673,
    2171,   221,    43,   340,   233,   280,   972,    86,   300,  -673,
    3491,   211,    17,  -673,    47,  -673,  -673,   308,  -673,   206,
     206,  -673,  3386,  -673,   294,  -673,  3386,   716,  3386,  -673,
     322,   332,  -673,  -673,  -673,  -673,   389,   336,   261,  -673,
    -673,  3386,   206,   329,    76,   389,    15,   445,   389,    76,
     335,   889,  -673,  -673,  -673,  -673,  -673,  -673,  -673,   483,
    3107,  3107,   353,  2840,   358,  -673,   370,   362,  3196,   381,
    -673,  2929,  -673,   395,  2727,   340,  3107,  3107,  -673,  -673,
    -673,   -39,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
     986,   560,  -673,  3107,  -673,  -673,  -673,    55,   242,   192,
     350,   190,   359,   388,   384,   402,   493,  1000,  -673,  -673,
    -673,   874,   285,  -673,  -673,  -673,  -673,   510,  -673,  2929,
    2085,  -673,  -673,  -673,   212,   212,   389,    84,  -673,   340,
    -673,   418,   433,  1611,  -673,  -673,   446,    11,    78,  -673,
    -673,   436,  -673,  -673,  -673,   254,  -673,   431,   443,  2381,
    -673,   134,   447,  -673,  2171,    85,  -673,   438,  -673,   451,
    -673,   206,   568,  -673,   458,  3721,  3644,   986,  3644,   794,
     461,   439,  -673,   311,   468,   321,  -673,  -673,  3815,  -673,
     470,  -673,  -673,   488,  -673,   479,   494,   499,  -673,   502,
     389,    64,   445,   485,   509,  -673,  -673,   507,  -673,  -673,
     505,  -673,   512,    32,   445,  -673,   514,    76,   522,  -673,
    3018,   370,  -673,  -673,  3969,   541,  -673,  3969,  2929,  -673,
    1265,  3969,  2727,  -673,  3969,  -673,  -673,  2727,  -673,   102,
     548,  -673,  -673,  -673,  -673,  1022,  2929,  2929,  1032,  -673,
    3107,  3107,  3107,  3107,  3107,  3107,  3107,  3107,  3107,  3107,
    3107,  3107,  3107,  3107,  3107,  3107,  3107,  3107,  3107,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  3107,
    2929,  -673,  2929,   453,   874,  -673,  -673,  2727,  -673,   -25,
     150,  -673,  1484,  -673,  -673,  -673,   609,    84,   340,  -673,
     593,  2929,   531,  3107,   534,   537,  1857,   558,   206,   559,
     206,  2929,   567,   212,   569,   549,   570,  -673,  -673,  -673,
    -673,  1734,  -673,  -673,  -673,  -673,  -673,  2276,  -673,   571,
     575,    30,  -673,  3107,  -673,  -673,   134,   119,  1395,  -673,
    -673,  -673,  -673,  -673,   510,  -673,  2171,  -673,  -673,   389,
     761,    84,   340,   582,  -673,   111,  -673,   206,   587,   112,
    -673,   378,  -673,  -673,   590,   600,   606,  2929,  -673,  2929,
    3644,  3107,  -673,  -673,  -673,   206,  3107,  -673,  -673,  -673,
      64,   445,  -673,  -673,  -673,  2727,  -673,  -673,   573,  -673,
     588,  -673,   607,  -673,  3568,   605,  3107,   611,   166,  3969,
     630,   325,   629,   636,   631,   175,   641,  -673,  2929,  3107,
     864,   836,  -673,   638,   647,     8,   864,  1042,  -673,  -673,
    -673,    55,    55,    55,   242,   242,   192,   192,   350,   350,
     350,   350,   190,   190,   359,   388,   384,   402,   493,   122,
    -673,  -673,  -673,  2929,  -673,  -673,   643,   649,  -673,   609,
    -673,  -673,   651,  -673,   644,  -673,  1857,   667,  2614,   645,
    2727,   652,   656,  2727,   609,  2727,  1857,  -673,  -673,  -673,
     678,   694,  -673,  -673,  -673,  -673,  -673,   661,  -673,  -673,
      84,   340,   389,   748,   340,  -673,   568,   389,   881,   340,
     670,  3721,   671,  3386,  3721,  -673,  -673,  -673,  -673,  -673,
     686,   688,  -673,  -673,  -673,   428,  -673,  -673,  3107,  3969,
     630,   698,  -673,   699,  -673,   702,  2929,  -673,  -673,  2929,
    -673,   705,   325,  -673,   721,  -673,   722,  -673,  -673,  -673,
    -673,  -673,   864,  -673,  -673,  -673,  -673,   864,  -673,  2929,
    -673,  2085,   693,  3909,  -673,  -673,  -673,  1857,  -673,   723,
    -673,  2727,  -673,  -673,   570,   725,   510,  -673,   727,  -673,
     728,  -673,  3969,  -673,  -673,   340,   389,   340,  -673,  -673,
     340,   389,   340,  -673,  3969,   437,  3969,  -673,  -673,    30,
    -673,  -673,  -673,   735,  -673,  2929,  2929,   630,   737,   214,
    3107,  -673,  2929,  2929,  -673,  -673,  -673,  -673,  -673,  -673,
     439,   739,  -673,  2929,  -673,   726,  1857,   729,  1857,  1857,
    -673,   734,   750,  -673,   340,  -673,  -673,   340,  -673,  -673,
     811,  -673,   694,  -673,   630,   180,   184,  -673,  -673,  -673,
     751,   185,   194,  -673,  -673,   212,   198,  2929,   800,  2929,
    -673,  -673,  3969,  -673,  -673,  -673,   206,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,   738,   759,  1857,  -673,  -673,
     741,  -673,  1857,  -673,   857,  -673,  -673
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -673,  -673,  -153,   846,   585,  -673,  -167,   368,  -673,  -673,
    -673,  -673,    67,  -673,  -673,  -673,   878,   565,  -179,     0,
    -673,  -296,   604,  -673,  -673,  -673,   293,  -673,  -673,  -673,
    -673,  -222,    40,   117,   109,    57,   120,   426,   452,   425,
     429,   420,  -181,  -180,   -27,  -673,   400,  -374,  -367,  -673,
     255,  -194,  -673,  -673,  -595,  -673,  -673,  -673,  -673,  -673,
     -24,    24,   264,   -58,   103,  -673,  -673,   -17,  -673,    29,
    -673,  -673,  -673,   351,  -673,  -673,  -673,  -673,  -673,  -673,
     218,  -673,  -673,  -173,  -673,  -673,  -673,  -673,   602,   -31,
    -673,  -158,  -165,   -42,   823,    77,    36,  -365,  -673,  -184,
    -673,  -292,  -169,   291,  -673,  -477,  -673,  -673,  -673,  -673,
    -673,  -673,   574,   390,  -673,  -673,   561,  -673,   250,  -315,
    -673,  -673,  -673,  -673,   440,  -673,  -673,  -673,  -673,  -152,
     246,   244,  -673,  -673,   354,   454,  -673,  -673,  -673,  -171,
    -589,  -673,  -673,  -673,  -621,  -673,    25,  -238,  -472,  -673,
     525,  -672,   226,  -467,  -673,  -673,  -673,  -673,   380,  -128,
    -673,  -673,  -147,  -673,  -332,  -673,   706,  -673,  -673,  -673,
    -673
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -498
static const yytype_int16 yytable[] =
{
      58,   238,   334,   175,   556,   635,   188,   103,   163,   158,
     253,   281,   172,   336,   246,   110,   316,   338,   339,   642,
     322,   348,   533,   480,    61,    97,   157,   350,   774,   176,
     377,   352,    58,   191,   652,   185,   104,   169,   412,   413,
     753,   416,     1,   171,   324,   325,   176,   545,   358,   379,
     734,   106,   371,   199,   431,   432,    61,   177,   748,    58,
     750,   410,   159,   111,    58,   749,     1,   192,    99,   178,
     440,   439,     3,   550,   391,   164,    13,   319,   176,     1,
     238,   411,   374,    61,   171,   112,   563,   184,   223,     1,
     203,   441,   403,    13,   406,     1,   317,   320,   177,   193,
     157,     3,   205,    64,     6,   817,   206,   219,   556,   318,
      26,   469,    58,    58,   725,     1,   229,   660,   598,   644,
       3,   101,   588,     6,   180,   677,   164,   378,    40,   647,
     334,   334,   215,   175,   216,    64,    61,    61,   405,   175,
     179,   158,   838,    44,   657,    40,   794,    26,   813,   663,
     181,   309,   188,   474,   666,   577,   100,    26,   157,   237,
     204,   158,    64,    26,   362,   242,   244,   247,   249,   351,
     251,   180,   175,   217,   200,   348,   254,   255,   290,   370,
      44,   350,   554,   475,   555,   352,   184,   113,   583,   220,
      44,   837,   693,   329,   234,   534,    44,   157,   470,   104,
      58,   361,   358,   210,   669,   597,   367,   678,   535,     1,
      58,   371,   598,   371,   226,    64,    64,   399,   609,   610,
     449,   450,    58,   192,     1,   673,    58,   392,    58,   534,
       3,   101,   598,     6,   778,   104,   397,   570,   237,   572,
     230,    58,   664,   729,   425,   404,    61,   387,   407,   192,
      61,   578,    61,   632,   787,   193,   528,   158,  -487,   229,
     633,   231,   319,     3,   101,    61,     6,   232,   166,   704,
       3,   101,   241,     6,   290,   236,   633,   233,   717,   738,
     215,   193,   320,   839,  -487,   598,   479,   840,   842,   751,
     598,   188,   481,   483,   598,   598,   252,   843,   451,   452,
     210,   845,   674,   349,   598,   445,   446,   679,   598,   654,
     281,   237,   338,   339,   376,   474,   474,   171,   526,   184,
     819,     1,   193,   351,   598,    64,   488,     3,   101,    64,
       6,    64,   107,   290,     3,   101,   333,     6,   172,   236,
     199,   365,   338,   339,    64,   169,   168,   338,   339,    58,
     101,   430,     6,   442,    58,   322,   661,   348,   443,   444,
     846,   545,   542,   350,   702,   157,   157,   352,   157,   171,
     792,   171,    45,    46,   447,   448,   690,   720,   157,   324,
     338,   339,   366,   109,   358,   338,   339,   453,   454,   550,
     571,   481,   550,   115,   476,   477,   215,   158,     3,   101,
     158,     6,   368,   158,   158,   158,   820,   158,   281,   481,
     158,   380,   197,  -486,   157,   198,  -486,   157,   694,   388,
     157,   157,   290,   560,   157,   824,   561,   290,   395,   828,
     709,   830,   831,   712,   755,   757,    45,    46,   396,   760,
     762,   227,     1,   228,   389,   630,   394,   181,     3,     4,
     309,     6,   401,   170,     3,   483,   591,   349,   409,   188,
     158,   414,     3,   101,   481,     6,   417,   236,   210,   210,
     421,   210,   418,   237,   237,   218,   772,   290,   221,   175,
     853,   210,   611,   612,   613,   855,   479,   683,   684,   424,
     329,   585,     3,   101,   587,     6,   290,   427,   592,   593,
     455,   594,   456,   667,   596,   351,   618,   619,   620,   621,
      26,   290,     2,     1,   101,     5,     6,    58,   804,     3,
       4,   457,     6,   807,   170,   458,     3,   101,   490,     6,
     688,   166,   689,   410,   171,   491,    58,   771,   477,   671,
     229,   369,   522,    44,  -485,   229,   810,   684,   309,   521,
      45,    46,   523,   411,   712,   473,   616,   617,   158,   536,
     157,   328,   614,   615,    45,    46,   524,   158,   347,   360,
     531,   719,   158,   622,   623,   290,   537,     3,   101,   362,
       6,    26,   539,   557,   157,    50,   167,   381,   382,   157,
     559,   237,    50,   564,   433,   434,     1,   435,   565,   338,
     339,   566,     3,   101,   812,     6,   730,   326,   573,   168,
     400,    50,    43,   575,    44,   485,   486,    50,   214,   567,
     591,    45,    46,   183,   568,     3,   101,   569,     6,   173,
     201,   844,   371,   158,   574,   576,   158,   579,   158,   349,
     342,   343,   344,   182,    50,   581,   290,   586,   290,    50,
     290,   599,   637,   290,   643,   290,   290,   645,   646,   767,
     648,   650,   436,   210,   540,   437,   705,   438,   183,   653,
     656,   655,   229,   229,   429,   202,   542,   229,   229,   481,
     598,   157,   158,    58,   157,    50,   746,   856,   182,   746,
     182,   746,   676,   685,   658,   681,   696,    50,    50,   157,
     659,   505,   786,   686,   483,     3,   101,    61,     6,   687,
     245,   697,   237,   698,   701,   797,   158,   347,     3,   101,
     703,     6,   347,   248,   158,     3,   101,   175,     6,   538,
     390,   243,   706,   157,   250,   158,   183,   290,   714,   715,
     716,   290,   182,    50,   718,   315,   171,   158,   633,   158,
     724,   733,   157,   731,   736,    50,   229,     3,   101,   823,
       6,   229,   756,    50,   157,   737,   157,   739,   743,   790,
       3,   101,   183,     6,   227,   672,   773,   746,   327,   747,
     752,   660,    50,   528,   210,    50,    64,   210,   364,   769,
     171,    50,   764,   766,   770,    50,   290,     1,   290,   290,
     775,   776,   848,     3,     4,   777,     6,    50,   170,   402,
     780,    50,     1,    50,   408,   158,   183,     2,   788,   101,
       5,     6,   429,   782,   783,   793,    50,   595,   796,   800,
     798,   799,   157,   342,   343,   344,   182,   605,   814,     1,
     818,   809,   825,   811,   832,     3,   101,   290,     6,   827,
     722,   829,   290,   833,   847,   183,   836,   841,   328,    50,
     173,   851,   852,   854,   505,    26,   649,     1,   651,     6,
     629,   114,   423,     3,   101,   182,     6,   700,    55,   505,
      26,   624,   626,     3,   101,   102,     6,   627,   236,   628,
       3,   101,     1,     6,   180,   761,   369,     2,    44,   101,
       5,     6,   347,   740,   347,    45,    46,    26,   625,   849,
      55,   487,   742,    44,   489,   680,   692,   682,    50,   478,
     181,    55,   208,   527,   668,   546,   759,   765,   768,   695,
     641,   631,   183,   382,    50,    26,   584,    55,   781,    50,
      44,   691,    55,     0,   398,     0,     0,   541,     0,     0,
      50,    50,   182,    50,     0,     0,     0,     0,     0,     0,
      26,     0,    55,    50,     0,     0,     0,     0,    44,     0,
       0,     0,   580,     0,   180,     1,   473,    55,     0,  -485,
       2,     3,   101,     5,     6,    45,    46,     0,     0,     1,
      55,    55,     0,    44,     2,     0,   101,     5,     6,    50,
     214,     0,    50,     0,     0,    50,    50,    50,     0,    50,
       0,     0,    50,     0,   505,     0,   459,   460,   461,   462,
     463,   464,   465,   466,   505,     1,   467,   468,     0,     0,
       0,     3,   101,   469,     6,     1,   600,     0,     0,     0,
       0,     3,   101,    26,     6,     1,   606,     0,   102,     0,
     744,     3,   101,   744,     6,   744,   727,    26,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
       0,   180,     0,   640,     0,   327,    44,     0,    55,     0,
       0,    50,     0,     0,   102,     0,     0,     0,    55,     0,
      44,     0,     0,    26,     0,     0,    50,     0,     0,     0,
      55,     0,    50,    26,    55,   505,    55,   601,     0,   779,
       0,     0,     0,    26,     0,     0,     0,   607,     0,    55,
     470,    50,   471,     0,   670,     0,    44,   675,     0,     0,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,   744,     0,     0,     0,    50,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,     0,   505,     0,   505,   505,     0,    50,
       0,     0,     0,     0,    50,   815,   816,     0,     0,     0,
       0,     0,   821,   822,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   826,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,   850,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,    50,    55,    50,     0,    50,     0,     0,    50,     0,
      50,    50,     0,     0,     0,     0,     0,    55,     0,    55,
       0,     0,     0,     0,     0,     0,   754,     0,     0,   758,
       0,   541,     0,     0,   763,     0,    50,     0,    50,    50,
       0,     0,     0,     2,     3,   101,     5,     6,     0,   116,
       0,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,    11,
      12,    13,     0,   602,     0,     0,   608,    14,    50,     0,
      15,     0,    50,     0,     0,    19,    50,     0,     0,     0,
       0,    22,    23,     0,     0,     0,     0,    50,     0,     0,
     803,     0,   805,    28,    29,   806,     0,   808,    31,    50,
       0,    50,     0,     0,     0,     0,     0,    34,    35,    36,
       0,     0,    39,    40,    41,     0,    42,   589,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,    50,    50,     0,     0,     0,     0,   834,
       0,     0,   835,     0,     0,    55,     0,     0,     1,   256,
     257,   258,   111,     0,     3,   101,     0,     6,     0,   337,
       0,     0,    55,     0,    55,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
     261,     0,    50,     0,     0,     0,     0,    50,     0,     0,
       0,     0,   262,     0,     0,   263,     0,     0,   264,     0,
       0,     0,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,    26,     0,     0,     0,
       0,   267,     0,     0,     0,   268,     0,   269,   721,   723,
       0,   270,     0,   272,   726,   728,   273,     1,   256,   257,
     258,   111,     0,     3,   101,     0,     6,   274,   337,   275,
       0,     0,     0,     0,     0,     0,   276,   277,   278,   279,
     280,     0,     0,     0,     0,     0,     0,     0,   260,   261,
       0,   665,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,     0,   263,     0,     0,   264,     0,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    26,     0,     0,     0,     0,
     267,    55,     0,     0,   268,     0,   269,     0,     0,     0,
     270,   271,   272,     0,     0,   273,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   274,     0,   275,     0,
       0,     0,     0,     0,     0,   276,   277,   278,   279,   280,
     784,     0,     0,     0,     0,   785,     0,     0,   482,   634,
       0,     0,     0,     0,     1,   256,   257,   258,   111,     2,
       3,   101,     5,     6,    55,   259,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,   261,     0,     0,     8,
       9,    10,   492,   493,     0,    11,    12,    13,   262,   494,
     495,   263,   496,    14,   264,     0,    15,    16,    55,   186,
     265,    19,   497,    20,   498,   499,    21,    22,    23,    24,
     500,   266,    26,     0,     0,     0,    27,   267,   501,    28,
      29,   268,    30,   269,    31,   502,     0,   270,   271,   272,
     503,    33,   273,    34,    35,    36,    37,    38,    39,    40,
      41,   504,    42,   274,     0,   275,     0,     0,     0,     0,
       0,     0,   276,   277,   278,   279,   280,     0,     0,     0,
       0,     0,     0,     0,     0,   333,  -471,     1,   256,   257,
     258,   111,     2,     3,   101,     5,     6,     0,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   260,   261,
       0,     0,     8,     9,    10,   492,   493,     0,    11,    12,
      13,   262,   494,   495,   263,   496,    14,   264,     0,    15,
      16,     0,   186,   265,    19,   497,    20,   498,   499,    21,
      22,    23,    24,   500,   266,    26,     0,     0,     0,    27,
     267,   501,    28,    29,   268,    30,   269,    31,   502,     0,
     270,   271,   272,   503,    33,   273,    34,    35,    36,    37,
      38,    39,    40,    41,   504,    42,   274,     0,   275,     0,
       0,     0,     0,     0,     0,   276,   277,   278,   279,   280,
       0,     0,     0,     0,     0,     0,     0,     0,   333,  -472,
       1,   256,   257,   258,   111,     2,     3,   101,     5,     6,
       0,   259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,   261,     0,     0,     8,     9,    10,   492,   493,
       0,    11,    12,    13,   262,   494,   495,   263,   496,    14,
     264,     0,    15,    16,     0,   186,   265,    19,   497,    20,
     498,   499,    21,    22,    23,    24,   500,   266,    26,     0,
       0,     0,    27,   267,   501,    28,    29,   268,    30,   269,
      31,   502,     0,   270,   271,   272,   503,    33,   273,    34,
      35,    36,    37,    38,    39,    40,    41,   504,    42,   274,
       0,   275,     0,     0,     0,     0,     0,     0,   276,   277,
     278,   279,   280,     0,     0,     0,     0,     1,     0,     0,
       0,   333,     2,     3,     4,     5,     6,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,    17,    18,     0,    19,     0,    20,     0,     0,    21,
      22,    23,    24,    25,     0,    26,     0,     0,     0,    27,
       0,     0,    28,    29,     0,    30,     0,    31,     0,    32,
       0,     0,     0,     0,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,     0,    44,     0,
       0,     0,     0,     0,     0,    45,    46,     0,     1,   256,
     257,   258,   111,     0,     3,   101,     0,     6,   222,   337,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
     261,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,   263,     0,     0,   264,     0,
       0,     0,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,    26,     0,     0,     0,
       0,   267,     0,     0,     0,   268,     0,   269,     0,     0,
       0,   270,   271,   272,     1,     0,   273,     0,     0,     2,
       3,     4,     5,     6,     0,     7,     0,   274,     0,   275,
       0,     0,     0,     0,     0,     0,   276,   277,   278,   279,
     280,     0,     0,     0,     0,     0,     0,     0,     0,   482,
       9,    10,     0,     0,     0,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,    15,    16,    17,   186,
       0,    19,     0,    20,     0,     0,    21,    22,    23,    24,
       0,     0,    26,   342,   343,   344,    27,     0,     0,    28,
      29,     0,    30,     0,    31,     0,  -497,     0,     0,     0,
       0,    33,     0,    34,    35,    36,   345,    38,    39,    40,
      41,     0,    42,    43,     0,    44,     0,     0,     0,     1,
       0,     0,    45,    46,     2,     3,     4,     5,     6,     0,
       7,     0,     0,     0,   346,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,    10,     0,     0,     0,
      11,    12,    13,     0,     0,     0,     0,     0,    14,     0,
       0,    15,    16,     0,   186,     0,    19,     0,    20,     0,
       0,    21,    22,    23,    24,     0,     0,    26,     0,     0,
       0,    27,     0,     0,    28,    29,     0,    30,     0,    31,
       0,     0,     0,     0,     0,     0,    33,     0,    34,    35,
      36,     0,    38,    39,    40,    41,     0,    42,    43,     0,
      44,     0,     0,     0,     1,     0,     0,    45,    46,     2,
       3,     4,     5,     6,     0,     7,     0,     0,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    10,     0,     0,     0,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,    15,    16,     0,   186,
       0,    19,     0,    20,     0,     0,    21,    22,    23,    24,
       0,     0,    26,     0,     0,     0,    27,     0,     0,    28,
      29,     0,    30,     0,    31,     0,     0,     0,     0,     0,
       0,    33,     0,    34,    35,    36,     0,    38,    39,    40,
      41,     0,    42,    43,     0,    44,     0,     0,     0,     0,
       0,     0,    45,    46,     0,     0,     0,     2,     3,   101,
       5,     6,     0,   116,   525,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,    10,
       0,     0,     0,    11,    12,    13,     0,     0,     0,   139,
       0,    14,     0,     0,    15,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    22,    23,     0,     0,   140,
       0,     0,     0,     0,     0,     0,     0,    28,    29,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    35,    36,     0,     0,    39,    40,    41,     0,
      42,   141,     0,   142,   143,     0,     0,   144,   145,   146,
     147,   148,   149,     0,   150,   151,   152,   153,   154,     0,
       0,   155,     0,     0,     0,     0,   156,     1,   256,   257,
     258,   111,     2,     3,   101,     5,     6,     0,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   260,   261,
       0,     0,     0,     9,    10,     0,     0,     0,    11,    12,
      13,   262,     0,     0,   263,     0,    14,   264,     0,    15,
      16,     0,   186,   265,    19,     0,    20,     0,     0,    21,
      22,    23,    24,     0,   266,    26,     0,     0,     0,    27,
     267,     0,    28,    29,   268,    30,   269,    31,     0,     0,
     270,   271,   272,     0,    33,   273,    34,    35,    36,     0,
      38,    39,    40,    41,     0,    42,   274,     0,   275,     0,
       0,     0,     0,     0,     0,   276,   277,   278,   279,   280,
       1,   256,   257,   258,   111,     2,     3,   101,     5,     6,
       0,   259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,   261,     0,     0,     0,     0,    10,     0,     0,
       0,    11,    12,    13,   262,     0,     0,   263,     0,    14,
     264,     0,    15,     0,     0,     0,   265,    19,     0,     0,
       0,     0,     0,    22,    23,     0,     0,   266,    26,     0,
       0,     0,     0,   267,     0,    28,    29,   268,     0,   269,
      31,     0,     0,   270,   271,   272,     0,     0,   273,    34,
      35,    36,     0,     0,    39,    40,    41,     0,    42,   274,
       0,   275,     0,     0,     0,     0,     0,     0,   276,   277,
     278,   279,   280,     1,   256,   257,   258,   111,     0,     3,
     101,     0,     6,     0,   337,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,   261,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
     263,     0,     0,   264,     0,     0,     0,     0,     0,   265,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     266,    26,     0,     0,     0,     0,   267,     0,     0,     0,
     268,     0,   269,     0,     0,     0,   270,     0,   272,     0,
       0,   273,     1,   256,   257,   258,   111,     0,     3,   101,
       0,     6,   274,   337,   275,   415,     0,     0,     0,     0,
       0,   276,   277,   278,   279,   280,     0,     0,     0,     0,
       0,     0,     0,   260,   261,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,     0,   263,
       0,     0,   264,     0,     0,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   266,
      26,     0,     0,     0,     0,   267,     0,     0,     0,   268,
       0,   269,     0,     0,     0,   270,   271,   272,     0,     0,
     273,     1,   256,   257,   258,   111,     0,     3,   101,     0,
       6,   274,   337,   275,     0,     0,     0,     0,     0,     0,
     276,   277,   278,   279,   280,     0,     0,     0,     0,     0,
       0,     0,   260,   261,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,   263,     0,
       0,   264,     0,     0,     0,     0,     0,   265,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   266,    26,
       0,     0,     0,     0,   267,     0,     0,     0,   268,     0,
     269,     0,     0,     0,   270,     0,   272,     0,     0,   273,
       1,   256,   257,   258,   111,     0,     3,   101,     0,     6,
     274,   337,   275,   582,     0,     0,     0,     0,     0,   276,
     277,   278,   279,   280,     0,     0,     0,     0,     0,     0,
       0,   260,   261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,   263,     0,     0,
     264,     0,     0,     0,     0,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,    26,     0,
       0,     0,     0,   267,     0,     0,     0,   268,     0,   269,
       0,     0,     0,   270,     0,   272,     0,     0,   273,     1,
     256,   257,   258,   111,     0,     3,   101,     0,     6,   274,
     337,   275,     0,     0,     0,     0,     0,     0,   276,   277,
     278,   279,   280,     0,     0,     0,     0,     0,     0,     0,
     260,   261,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,     0,   263,     0,     0,   264,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   266,    26,     0,     0,
       0,     0,   267,     0,     0,     0,   268,     0,   269,     0,
       0,     0,   270,     1,   272,     0,     0,   273,     2,     3,
       4,     5,     6,     0,     7,     0,     0,     0,   422,     0,
     275,     0,     0,     0,     0,     0,     0,   276,   277,   278,
     279,   280,     0,     0,     0,     0,     0,     0,     8,     9,
      10,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,    17,    18,     0,
      19,     0,    20,     0,     0,    21,    22,    23,    24,    25,
       0,    26,     0,     0,     0,    27,     0,     0,    28,    29,
       0,    30,     0,    31,     0,    32,     0,     0,     0,     0,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,     0,    44,     0,     0,     0,   162,     1,
       0,    45,    46,     0,     2,     3,     4,     5,     6,     0,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    10,     0,     0,     0,
      11,    12,    13,     0,     0,     0,     0,     0,    14,     0,
       0,    15,    16,    17,    18,     0,    19,     0,    20,     0,
       0,    21,    22,    23,    24,    25,     0,    26,     0,     0,
       0,    27,     0,     0,    28,    29,     0,    30,     0,    31,
       0,    32,     0,     0,     0,     0,    33,     0,    34,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,     0,
      44,     0,     0,     0,     1,     0,     0,    45,    46,     2,
       3,     4,     5,     6,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    10,     0,     0,     0,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,    15,    16,     0,   186,
       0,    19,     0,    20,     0,     0,    21,    22,    23,    24,
       0,     0,    26,     0,     0,     0,    27,     0,     0,    28,
      29,     0,    30,     0,    31,     0,     2,     3,   101,     5,
       6,    33,   116,    34,    35,    36,     0,    38,    39,    40,
      41,     0,    42,   369,     0,    44,  -485,     0,     0,     0,
       0,     0,    45,    46,     0,     0,     0,     0,    10,     0,
       0,     0,    11,    12,    13,     0,     0,     0,     0,     0,
      14,     0,     0,    15,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    29,     0,     0,
       0,    31,     2,     3,   101,     5,     6,   209,   116,     0,
      34,    35,    36,     0,     0,    39,    40,    41,     0,    42,
     699,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    10,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,     0,   186,     0,    19,     0,    20,     0,     0,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,    29,     0,    30,     0,    31,     0,     2,
       3,   101,     5,     6,    33,   116,    34,    35,    36,     0,
      38,    39,    40,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    10,     0,     0,     0,    11,   547,    13,     0,     0,
       0,     0,     0,    14,     0,     0,    15,    16,     0,   186,
       0,    19,     0,    20,     0,     0,    21,    22,    23,    24,
       0,     0,     0,     0,     0,     0,    27,     0,     0,    28,
      29,     0,    30,     0,    31,     0,   548,     0,     0,     0,
       0,    33,     0,   549,    35,    36,     0,    38,    39,    40,
      41,     0,    42,     2,     3,   101,     5,     6,   562,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,    10,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,     0,    14,     0,     0,
      15,    16,     0,   186,     0,    19,     0,    20,     0,     0,
      21,    22,    23,    24,     0,     0,     0,     0,     0,     0,
      27,     0,     0,    28,    29,     0,    30,     0,    31,     0,
       0,     0,     0,     0,     0,    33,     0,    34,    35,    36,
       0,    38,    39,    40,    41,     0,    42,     2,     3,   101,
       5,     6,   789,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,    15,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    22,    23,     2,     3,   101,
       5,     6,     0,   116,     0,     0,     0,    28,    29,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    35,    36,     0,     0,    39,    40,    41,    10,
      42,     0,     0,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,    15,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    35,    36,     0,     0,    39,    40,    41,     0,
      42
};

static const yytype_int16 yycheck[] =
{
       0,   159,   196,    45,   369,   482,    64,     7,    32,    26,
     175,   178,    43,   197,   167,    15,   181,   198,   198,   491,
     191,   200,   354,   319,     0,     0,    26,   200,   700,    14,
      13,   200,    32,    64,   501,    59,     7,    37,   260,   261,
     661,   263,     3,    43,   191,   192,    14,   362,   200,   214,
     639,   102,   210,    84,   276,   277,    32,    14,   653,    59,
     655,    50,    26,     7,    64,   654,     3,    89,    14,   108,
      15,   293,     9,   365,   227,    14,    46,   102,    14,     3,
     238,    70,   210,    59,    84,    18,   378,    58,   112,     3,
      90,    36,   245,    46,   247,     3,   110,   122,    14,   121,
     100,     9,    10,     0,    12,   777,    14,   107,   473,   123,
      71,    33,   112,   113,   106,     3,   116,    87,   110,   493,
       9,    10,   418,    12,    85,    14,    14,   110,    98,   496,
     324,   325,   103,   175,   105,    32,   112,   113,   123,   181,
       0,   158,   814,   104,   511,    98,   741,    71,   769,   523,
     111,   178,   210,   311,   528,   123,   102,    71,   158,   159,
      85,   178,    59,    71,   121,   165,   166,   167,   168,   200,
     170,    85,   214,   106,   124,   354,   176,   177,   178,   210,
     104,   354,   366,   311,   368,   354,   157,   124,   410,   124,
     104,   812,   566,   193,   158,   110,   104,   197,   120,   170,
     200,   201,   354,   100,   536,   103,   206,    96,   123,     3,
     210,   369,   110,   371,   124,   112,   113,   241,   440,   441,
      30,    31,   222,    89,     3,   540,   226,   227,   228,   110,
       9,    10,   110,    12,   706,   206,   236,   390,   238,   392,
     105,   241,   123,   121,   271,   245,   222,   222,   248,    89,
     226,   404,   228,   103,   731,   121,   122,   274,   124,   259,
     110,   105,   102,     9,    10,   241,    12,   103,    14,   103,
       9,    10,   109,    12,   274,    14,   110,   106,   103,   646,
     251,   121,   122,   103,   124,   110,   317,   103,   103,   656,
     110,   349,   319,   320,   110,   110,   103,   103,   108,   109,
     197,   103,   540,   200,   110,   113,   114,   545,   110,   503,
     477,   311,   493,   493,   103,   473,   474,   317,   349,   290,
     106,     3,   121,   354,   110,   222,   326,     9,    10,   226,
      12,   228,    14,   333,     9,    10,   124,    12,   369,    14,
     371,   108,   523,   523,   241,   345,    92,   528,   528,   349,
      10,   274,    12,   111,   354,   526,   521,   536,   116,   117,
     827,   676,   362,   536,   586,   365,   366,   536,   368,   369,
     737,   371,   111,   112,    24,    25,   560,   599,   378,   526,
     561,   561,   102,    15,   536,   566,   566,    28,    29,   681,
     390,   418,   684,    25,   109,   110,   367,   414,     9,    10,
     417,    12,   102,   420,   421,   422,   780,   424,   575,   436,
     427,   103,   102,   102,   414,   105,   105,   417,   571,   125,
     420,   421,   422,   102,   424,   790,   105,   427,   106,   796,
     105,   798,   799,   591,   672,   673,   111,   112,   106,   677,
     678,   122,     3,   124,   226,   472,   228,   111,     9,    10,
     477,    12,   123,    14,     9,   482,   420,   354,   123,   517,
     477,   108,     9,    10,   491,    12,   108,    14,   365,   366,
     108,   368,   102,   473,   474,   107,   698,   477,   110,   521,
     847,   378,   442,   443,   444,   852,   517,   109,   110,   108,
     490,   414,     9,    10,   417,    12,   496,   102,   421,   422,
     112,   424,   118,   534,   427,   536,   449,   450,   451,   452,
      71,   511,     8,     3,    10,    11,    12,   517,   756,     9,
      10,   119,    12,   761,    14,    32,     9,    10,   110,    12,
     557,    14,   559,    50,   534,   102,   536,   109,   110,   539,
     540,   102,   106,   104,   105,   545,   109,   110,   575,   103,
     111,   112,   121,    70,   712,   102,   447,   448,   575,   121,
     560,   193,   445,   446,   111,   112,   123,   584,   200,   201,
     123,   598,   589,   453,   454,   575,   125,     9,    10,   121,
      12,    71,    14,   122,   584,     0,    69,   219,   220,   589,
     122,   591,     7,   123,    34,    35,     3,    37,   110,   780,
     780,   122,     9,    10,   769,    12,   633,    14,   123,    92,
     242,    26,   102,   108,   104,   324,   325,    32,   111,   125,
     584,   111,   112,    58,   125,     9,    10,   125,    12,    44,
      14,   825,   790,   650,   125,   123,   653,   123,   655,   536,
      72,    73,    74,    58,    59,   123,   646,   106,   648,    64,
     650,   103,    43,   653,   123,   655,   656,   123,   121,   683,
     102,   102,   102,   560,    96,   105,   589,   107,   103,   102,
     121,   102,   672,   673,   274,    90,   676,   677,   678,   706,
     110,   681,   699,   683,   684,   100,   650,   854,   103,   653,
     105,   655,   110,   103,   123,   108,   123,   112,   113,   699,
     125,   333,   729,   103,   731,     9,    10,   683,    12,   103,
      14,   123,   712,   106,   109,   746,   733,   349,     9,    10,
     109,    12,   354,    14,   741,     9,    10,   769,    12,   361,
      14,   166,   102,   733,   169,   752,   171,   737,   109,   103,
     109,   741,   157,   158,   103,   180,   746,   764,   110,   766,
     103,   102,   752,   110,   103,   170,   756,     9,    10,   790,
      12,   761,    14,   178,   764,   121,   766,   100,   123,   733,
       9,    10,   207,    12,   122,    14,   699,   741,   193,   123,
     102,    87,   197,   122,   681,   200,   683,   684,   203,   103,
     790,   206,   122,   122,   106,   210,   796,     3,   798,   799,
     102,   102,   829,     9,    10,   103,    12,   222,    14,   244,
     105,   226,     3,   228,   249,   832,   251,     8,   125,    10,
      11,    12,   422,   102,   102,   102,   241,   427,   103,   752,
     103,   103,   832,    72,    73,    74,   251,   437,   103,     3,
     103,   764,   103,   766,   110,     9,    10,   847,    12,   123,
      14,   122,   852,   103,    54,   290,    45,   106,   490,   274,
     275,   123,   103,   122,   496,    71,   498,     3,   500,    12,
     470,    25,   268,     9,    10,   290,    12,   584,     0,   511,
      71,   455,   457,     9,    10,     7,    12,   458,    14,   469,
       9,    10,     3,    12,    85,    14,   102,     8,   104,    10,
      11,    12,   534,   648,   536,   111,   112,    71,   456,   832,
      32,   326,   648,   104,   329,   547,   565,   549,   333,   317,
     111,    43,    99,   349,   534,   364,   676,   681,   684,   575,
     490,   477,   367,   565,   349,    71,   411,    59,   712,   354,
     104,   561,    64,    -1,   238,    -1,    -1,   362,    -1,    -1,
     365,   366,   367,   368,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    84,   378,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,   407,    -1,    85,     3,   102,    99,    -1,   105,
       8,     9,    10,    11,    12,   111,   112,    -1,    -1,     3,
     112,   113,    -1,   104,     8,    -1,    10,    11,    12,   414,
     111,    -1,   417,    -1,    -1,   420,   421,   422,    -1,   424,
      -1,    -1,   427,    -1,   646,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,   656,     3,    26,    27,    -1,    -1,
      -1,     9,    10,    33,    12,     3,    14,    -1,    -1,    -1,
      -1,     9,    10,    71,    12,     3,    14,    -1,   170,    -1,
     650,     9,    10,   653,    12,   655,    14,    71,    -1,    -1,
      -1,    -1,   477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,   488,    -1,   490,   104,    -1,   200,    -1,
      -1,   496,    -1,    -1,   206,    -1,    -1,    -1,   210,    -1,
     104,    -1,    -1,    71,    -1,    -1,   511,    -1,    -1,    -1,
     222,    -1,   517,    71,   226,   737,   228,    85,    -1,   709,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    85,    -1,   241,
     120,   536,   122,    -1,   539,    -1,   104,   542,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,   741,    -1,    -1,    -1,   560,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     575,    -1,    -1,    -1,   796,    -1,   798,   799,    -1,   584,
      -1,    -1,    -1,    -1,   589,   775,   776,    -1,    -1,    -1,
      -1,    -1,   782,   783,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   793,    -1,   317,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   836,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   847,    -1,    -1,    -1,    -1,
     852,    -1,    -1,    -1,    -1,    -1,    -1,   349,    -1,    -1,
      -1,   646,   354,   648,    -1,   650,    -1,    -1,   653,    -1,
     655,   656,    -1,    -1,    -1,    -1,    -1,   369,    -1,   371,
      -1,    -1,    -1,    -1,    -1,    -1,   671,    -1,    -1,   674,
      -1,   676,    -1,    -1,   679,    -1,   681,    -1,   683,   684,
      -1,    -1,    -1,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,   699,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,
      45,    46,    -1,   435,    -1,    -1,   438,    52,   733,    -1,
      55,    -1,   737,    -1,    -1,    60,   741,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,   752,    -1,    -1,
     755,    -1,   757,    78,    79,   760,    -1,   762,    83,   764,
      -1,   766,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      -1,    -1,    97,    98,    99,    -1,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   796,    -1,   798,   799,    -1,    -1,    -1,    -1,   804,
      -1,    -1,   807,    -1,    -1,   517,    -1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    12,    -1,    14,
      -1,    -1,   534,    -1,   536,    -1,    -1,   832,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,   847,    -1,    -1,    -1,    -1,   852,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    82,   600,   601,
      -1,    86,    -1,    88,   606,   607,    91,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    12,   102,    14,   104,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    -1,
      76,   683,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,
      86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     722,    -1,    -1,    -1,    -1,   727,    -1,    -1,   124,   125,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,   746,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,
      39,    40,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,   790,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    38,    39,    40,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      -1,   124,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    57,    58,    -1,    60,    -1,    62,    -1,    -1,    65,
      66,    67,    68,    69,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,   101,   102,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    12,   124,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,
      -1,    86,    87,    88,     3,    -1,    91,    -1,    -1,     8,
       9,    10,    11,    12,    -1,    14,    -1,   102,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,
      -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,    78,
      79,    -1,    81,    -1,    83,    -1,    85,    -1,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,   101,   102,    -1,   104,    -1,    -1,    -1,     3,
      -1,    -1,   111,   112,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    55,    56,    -1,    58,    -1,    60,    -1,    62,    -1,
      -1,    65,    66,    67,    68,    -1,    -1,    71,    -1,    -1,
      -1,    75,    -1,    -1,    78,    79,    -1,    81,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,   101,   102,    -1,
     104,    -1,    -1,    -1,     3,    -1,    -1,   111,   112,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,    58,
      -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,
      79,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    -1,    -1,     8,     9,    10,
      11,    12,    -1,    14,   123,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    50,
      -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    -1,    -1,    97,    98,    99,    -1,
     101,   102,    -1,   104,   105,    -1,    -1,   108,   109,   110,
     111,   112,   113,    -1,   115,   116,   117,   118,   119,    -1,
      -1,   122,    -1,    -1,    -1,    -1,   127,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    58,    59,    60,    -1,    62,    -1,    -1,    65,
      66,    67,    68,    -1,    70,    71,    -1,    -1,    -1,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    88,    -1,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,   101,   102,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    -1,    52,
      53,    -1,    55,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    70,    71,    -1,
      -1,    -1,    -1,    76,    -1,    78,    79,    80,    -1,    82,
      83,    -1,    -1,    86,    87,    88,    -1,    -1,    91,    92,
      93,    94,    -1,    -1,    97,    98,    99,    -1,   101,   102,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    86,    -1,    88,    -1,
      -1,    91,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    12,   102,    14,   104,   105,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,
      -1,    82,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,
      91,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      12,   102,    14,   104,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    -1,    86,    -1,    88,    -1,    -1,    91,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    12,
     102,    14,   104,   105,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    82,
      -1,    -1,    -1,    86,    -1,    88,    -1,    -1,    91,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    12,   102,
      14,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    82,    -1,
      -1,    -1,    86,     3,    88,    -1,    -1,    91,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,   102,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    62,    -1,    -1,    65,    66,    67,    68,    69,
      -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,   101,   102,    -1,   104,    -1,    -1,    -1,   108,     3,
      -1,   111,   112,    -1,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    55,    56,    57,    58,    -1,    60,    -1,    62,    -1,
      -1,    65,    66,    67,    68,    69,    -1,    71,    -1,    -1,
      -1,    75,    -1,    -1,    78,    79,    -1,    81,    -1,    83,
      -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,   101,   102,    -1,
     104,    -1,    -1,    -1,     3,    -1,    -1,   111,   112,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,    58,
      -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,
      79,    -1,    81,    -1,    83,    -1,     8,     9,    10,    11,
      12,    90,    14,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,   101,   102,    -1,   104,   105,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,
      -1,    83,     8,     9,    10,    11,    12,    13,    14,    -1,
      92,    93,    94,    -1,    -1,    97,    98,    99,    -1,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    -1,    58,    -1,    60,    -1,    62,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    -1,    81,    -1,    83,    -1,     8,
       9,    10,    11,    12,    90,    14,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,    58,
      -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      79,    -1,    81,    -1,    83,    -1,    85,    -1,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,   101,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      55,    56,    -1,    58,    -1,    60,    -1,    62,    -1,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    -1,    81,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,   101,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    78,    79,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    -1,    -1,    97,    98,    99,    40,
     101,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    -1,    -1,    97,    98,    99,    -1,
     101
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,     8,     9,    10,    11,    12,    14,    38,    39,
      40,    44,    45,    46,    52,    55,    56,    57,    58,    60,
      62,    65,    66,    67,    68,    69,    71,    75,    78,    79,
      81,    83,    85,    90,    92,    93,    94,    95,    96,    97,
      98,    99,   101,   102,   104,   111,   112,   129,   130,   131,
     132,   133,   134,   135,   142,   144,   145,   146,   147,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   203,   204,   205,   206,   207,   209,   211,   212,
     213,   214,   217,   218,   219,   221,   222,   230,   235,   236,
     237,   248,   255,   257,   261,   264,   265,   274,   295,    14,
     102,    10,   144,   147,   197,   275,   102,    14,   132,   135,
     147,     7,   140,   124,   131,   135,    14,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    50,
      70,   102,   104,   105,   108,   109,   110,   111,   112,   113,
     115,   116,   117,   118,   119,   122,   127,   147,   195,   224,
     249,   256,   108,   188,    14,   277,    14,    69,    92,   147,
      14,   147,   217,   132,   220,   221,    14,    14,   108,     0,
      85,   111,   132,   145,   197,   188,    58,   123,   191,   215,
     216,   217,    89,   121,   251,   267,   290,   102,   105,   217,
     124,    14,   132,   147,    85,    10,    14,   147,   222,    13,
     192,   227,   228,   229,   111,   197,   197,   140,   135,   147,
     124,   135,   124,   188,   208,   274,   124,   122,   124,   147,
     105,   105,   103,   106,   224,   288,    14,   147,   219,   250,
     294,   109,   147,   145,   147,    14,   130,   147,    14,   147,
     145,   147,   103,   220,   147,   147,     4,     5,     6,    14,
      34,    35,    47,    50,    53,    59,    70,    76,    80,    82,
      86,    87,    88,    91,   102,   104,   111,   112,   113,   114,
     115,   134,   136,   137,   138,   139,   140,   141,   143,   144,
     147,   148,   150,   151,   152,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     223,   224,   262,   263,   271,   145,   220,   110,   123,   102,
     122,   232,   267,   285,   290,   290,    14,   132,   135,   147,
     252,   253,   254,   124,   179,   231,   227,    14,   170,   171,
     175,   286,    72,    73,    74,    95,   123,   135,   146,   192,
     211,   217,   230,   238,   239,   240,   241,   247,   257,   292,
     135,   147,   121,   244,   132,   108,   102,   147,   102,   102,
     217,   219,   225,   226,   287,   289,   103,    13,   110,   220,
     103,   135,   135,   200,   201,   202,   284,   274,   125,   208,
      14,   130,   147,   210,   208,   106,   106,   147,   294,   188,
     135,   123,   145,   130,   147,   123,   130,   147,   145,   123,
      50,    70,   159,   159,   108,   105,   159,   108,   102,   153,
     278,   108,   102,   150,   108,   172,   297,   102,   172,   174,
     223,   159,   159,    34,    35,    37,   102,   105,   107,   159,
      15,    36,   111,   116,   117,   113,   114,    24,    25,    30,
      31,   108,   109,    28,    29,   112,   118,   119,    32,    16,
      17,    18,    19,    20,    21,    22,    23,    26,    27,    33,
     120,   122,   173,   102,   219,   287,   109,   110,   216,   217,
     149,   172,   124,   172,   233,   231,   231,   132,   147,   132,
     110,   102,    41,    42,    48,    49,    51,    61,    63,    64,
      69,    77,    84,    89,   100,   135,   174,   176,   177,   178,
     179,   180,   181,   183,   185,   186,   189,   192,   266,   281,
     282,   103,   106,   121,   123,   123,   217,   240,   122,   242,
     243,   123,   293,   292,   110,   123,   121,   125,   135,    14,
      96,   132,   147,   245,   246,   247,   244,    45,    85,    92,
     229,   258,   259,   260,   227,   227,   225,   122,   287,   122,
     102,   105,    13,   229,   123,   110,   122,   125,   125,   125,
     130,   147,   130,   123,   125,   108,   123,   123,   130,   123,
     145,   123,   105,   159,   278,   223,   106,   223,   149,   102,
     154,   224,   223,   223,   223,   174,   223,   103,   110,   103,
      14,    85,   144,   149,   276,   174,    14,    85,   144,   159,
     159,   160,   160,   160,   161,   161,   162,   162,   163,   163,
     163,   163,   164,   164,   165,   166,   167,   168,   169,   174,
     172,   263,   103,   110,   125,   233,   234,    43,   268,   269,
     132,   252,   276,   123,   175,   123,   121,   176,   102,   135,
     102,   135,   281,   102,   179,   102,   121,   176,   123,   125,
      87,   220,   272,   175,   123,   126,   175,   217,   241,   292,
     132,   147,    14,   247,   275,   132,   110,    14,    96,   275,
     135,   108,   135,   109,   110,   103,   103,   103,   172,   172,
     227,   286,   201,   175,   130,   262,   123,   123,   106,   102,
     154,   109,   159,   109,   103,   223,   102,   157,   279,   105,
     155,   156,   219,   280,   109,   103,   109,   103,   103,   172,
     159,   144,    14,   144,   103,   106,   144,    14,   144,   121,
     172,   110,   291,   102,   268,   296,   103,   121,   176,   100,
     178,   184,   190,   123,   174,   182,   224,   123,   182,   268,
     182,   176,   102,   272,   132,   275,    14,   275,   132,   246,
     275,    14,   275,   132,   122,   258,   122,   188,   259,   103,
     106,   109,   159,   223,   279,   102,   102,   103,   276,   174,
     105,   280,   102,   102,   144,   144,   172,   233,   125,    13,
     224,   270,   176,   102,   182,   283,   103,   217,   103,   103,
     223,   273,   298,   132,   275,   132,   132,   275,   132,   223,
     109,   223,   220,   272,   103,   174,   174,   279,   103,   106,
     175,   174,   174,   217,   225,   103,   174,   123,   176,   122,
     176,   176,   110,   103,   132,   132,    45,   272,   279,   103,
     103,   106,   103,   103,   179,   103,   281,    54,   172,   223,
     135,   123,   103,   176,   122,   176,   134
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 144 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPEDEF_NAMEr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 148 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NAMESPACE_NAMEr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 153 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ORIGINAL_NAMESPACE_NAMEr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 158 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CLASS_NAMEr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 159 "120gram.y"
    { exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				(yyval.n) = NULL;
																				/*$$ = (TreeNode *)alacnary(CLASS_NAMEr2, 1, $1); */}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 168 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ENUM_NAMEr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 173 "120gram.y"
    { exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				(yyval.n) = NULL; 
																				/*(TreeNode *)alacnary(TEMPLATE_NAMEr1, 1, $1);*/ }
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 185 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(IDENTIFIERr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 189 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LITERALr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 190 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LITERALr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 191 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LITERALr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 192 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LITERALr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 193 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LITERALr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 197 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INTEGER_LITERALr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 201 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CHARACTER_LITERALr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 205 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(FLOATING_LITERALr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 209 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STRING_LITERALr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 213 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BOOLEAN_LITERALr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 214 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BOOLEAN_LITERALr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 222 "120gram.y"
    { root = (TreeNode *)alacnary(TRANSLATION_UNITr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 230 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 231 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 232 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr3, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 233 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PRIMARY_EXPRESSIONr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 237 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ID_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 238 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ID_EXPRESSIONr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 242 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNQUALIFIED_IDr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 243 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNQUALIFIED_IDr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 244 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNQUALIFIED_IDr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 245 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNQUALIFIED_IDr4, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 249 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(QUALIFIED_IDr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 250 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(QUALIFIED_IDr1, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 254 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NESTED_NAME_SPECIFIERr1, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 255 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NESTED_NAME_SPECIFIERr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 256 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NESTED_NAME_SPECIFIERr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 257 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NESTED_NAME_SPECIFIERr4, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 261 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 262 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr2, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 263 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr3, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 265 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr4, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 266 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr5, 3, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 267 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr6, 3, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 268 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr7, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 270 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr8, 5, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 271 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr9, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 272 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr10, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 273 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr11, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 274 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr12, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 275 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr13, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 276 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr14, 3, (yyvsp[(1) - (7)].n), (yyvsp[(3) - (7)].n), (yyvsp[(6) - (7)].n)); }
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 277 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr15, 3, (yyvsp[(1) - (7)].n), (yyvsp[(3) - (7)].n), (yyvsp[(6) - (7)].n)); }
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 278 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr16, 3, (yyvsp[(1) - (7)].n), (yyvsp[(3) - (7)].n), (yyvsp[(6) - (7)].n)); }
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 279 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr17, 3, (yyvsp[(1) - (7)].n), (yyvsp[(3) - (7)].n), (yyvsp[(6) - (7)].n)); }
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 280 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr18, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 281 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(POSTFIX_EXPRESSIONr19, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 285 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXPRESSION_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 286 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXPRESSION_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 290 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 291 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_EXPRESSIONr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 292 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_EXPRESSIONr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 293 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_EXPRESSIONr4, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 294 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_EXPRESSIONr5, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 295 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_EXPRESSIONr6, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 296 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_EXPRESSIONr7, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 297 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_EXPRESSIONr8, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 298 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_EXPRESSIONr9, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 299 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_EXPRESSIONr10, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 303 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_OPERATORr1, 0); }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 304 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_OPERATORr2, 0); }
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 305 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_OPERATORr3, 0); }
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 306 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNARY_OPERATORr4, 0); }
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 311 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_EXPRESSIONr1, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 313 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_EXPRESSIONr2, 5, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 315 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_EXPRESSIONr3, 4, (yyvsp[(1) - (6)].n), (yyvsp[(2) - (6)].n), (yyvsp[(4) - (6)].n), (yyvsp[(6) - (6)].n)); }
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 317 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_EXPRESSIONr4, 5, (yyvsp[(1) - (7)].n), (yyvsp[(2) - (7)].n), (yyvsp[(3) - (7)].n), (yyvsp[(5) - (7)].n), (yyvsp[(7) - (7)].n)); }
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 321 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_PLACEMENTr1, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 325 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_TYPE_IDr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 329 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_DECLARATORr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 330 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_DECLARATORr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 334 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_NEW_DECLARATORr1, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 335 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_NEW_DECLARATORr2, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 339 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_INITIALIZERr1, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 343 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DELETE_EXPRESSIONr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 344 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DELETE_EXPRESSIONr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 345 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DELETE_EXPRESSIONr3, 2, (yyvsp[(1) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 346 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DELETE_EXPRESSIONr4, 3, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 350 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CAST_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 351 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CAST_EXPRESSIONr2, 2, (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 355 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PM_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 356 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PM_EXPRESSIONr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 357 "120gram.y"
    { (yyval.n) =(TreeNode *)alacnary(PM_EXPRESSIONr3, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 361 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MULTIPLICATIVE_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 362 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MULTIPLICATIVE_EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 363 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MULTIPLICATIVE_EXPRESSIONr3, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 364 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MULTIPLICATIVE_EXPRESSIONr4, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 368 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ADDITIVE_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 369 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ADDITIVE_EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 370 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ADDITIVE_EXPRESSIONr3, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 374 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SHIFT_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 375 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SHIFT_EXPRESSIONr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 376 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SHIFT_EXPRESSIONr3, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 380 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(RELATIONAL_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 381 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(RELATIONAL_EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 382 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(RELATIONAL_EXPRESSIONr3, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 383 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(RELATIONAL_EXPRESSIONr4, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 384 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(RELATIONAL_EXPRESSIONr5, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 388 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EQUALITY_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 389 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EQUALITY_EXPRESSIONr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 390 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EQUALITY_EXPRESSIONr3, 1, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 394 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(AND_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 395 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(AND_EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 399 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXCLUSIVE_OR_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 400 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXCLUSIVE_OR_EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 404 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INCLUSIVE_OR_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 405 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INCLUSIVE_OR_EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 409 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LOGICAL_AND_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 411 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LOGICAL_AND_EXPRESSIONr1, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 415 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LOGICAL_OR_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 416 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LOGICAL_OR_EXPRESSIONr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 420 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONDITIONAL_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 422 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONDITIONAL_EXPRESSIONr2, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 426 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 428 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSIONr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 429 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSIONr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 433 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr1, 0); }
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 434 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 435 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 436 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 437 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 438 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr6, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 439 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr7, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 440 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr8, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 441 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr9, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 442 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr10, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 443 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_OPERATORr11, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 447 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 448 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 452 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONSTANT_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 460 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STATEMENTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 461 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STATEMENTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 462 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STATEMENTr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 463 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STATEMENTr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 464 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STATEMENTr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 465 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STATEMENTr6, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 466 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STATEMENTr7, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 467 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STATEMENTr8, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 471 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LABELED_STATEMENTr1, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 472 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LABELED_STATEMENTr2, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 473 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LABELED_STATEMENTr3, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 477 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXPRESSION_STATEMENTr1, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 481 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(COMPOUND_STATEMENTr1, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 485 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STATEMENT_SEQr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 486 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STATEMENT_SEQr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 490 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SELECTION_STATEMENTr1, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 491 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SELECTION_STATEMENTr2, 5, (yyvsp[(1) - (7)].n), (yyvsp[(3) - (7)].n), (yyvsp[(5) - (7)].n), (yyvsp[(6) - (7)].n), (yyvsp[(7) - (7)].n)); }
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 492 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SELECTION_STATEMENTr3, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 496 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONDITIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 498 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONDITIONr2, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 502 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ITERATION_STATEMENTr1, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 503 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ITERATION_STATEMENTr2, 4, (yyvsp[(1) - (7)].n), (yyvsp[(2) - (7)].n), (yyvsp[(3) - (7)].n), (yyvsp[(5) - (7)].n)); }
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 505 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ITERATION_STATEMENTr3, 5, (yyvsp[(1) - (8)].n), (yyvsp[(3) - (8)].n), (yyvsp[(4) - (8)].n), (yyvsp[(6) - (8)].n), (yyvsp[(8) - (8)].n)); }
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 509 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(FOR_INIT_STATEMENTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 510 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(FOR_INIT_STATEMENTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 514 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(JUMP_STATEMENTr1, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 515 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(JUMP_STATEMENTr2, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 516 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(JUMP_STATEMENTr3, 2, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n)); }
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 517 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(JUMP_STATEMENTr4, 2, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n)); }
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 521 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATION_STATEMENTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 529 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATION_SEQr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 530 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATION_SEQr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 534 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 535 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATIONr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 536 "120gram.y"
    { exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				(yyval.n) = NULL;
																				/*$$ = alacnary(DECLARATIONr3, 1, $1); */}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 541 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATIONr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 542 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATIONr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 177:

/* Line 1464 of yacc.c  */
#line 543 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATIONr6, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 544 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATIONr7, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 548 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BLOCK_DECLARATIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 549 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BLOCK_DECLARATIONr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 550 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BLOCK_DECLARATIONr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 551 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BLOCK_DECLARATIONr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 552 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BLOCK_DECLARATIONr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 556 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_DECLARATIONr1, 2, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n)); }
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 557 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_DECLARATIONr2, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 561 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECL_SPECIFIERr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 562 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECL_SPECIFIERr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 563 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECL_SPECIFIERr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 564 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECL_SPECIFIERr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 565 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECL_SPECIFIERr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 569 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECL_SPECIFIER_SEQr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 570 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECL_SPECIFIER_SEQr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 574 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 575 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 576 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 577 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 578 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STORAGE_CLASS_SPECIFIERr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 582 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(FUNCTION_SPECIFIERr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 583 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(FUNCTION_SPECIFIERr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 584 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(FUNCTION_SPECIFIERr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 588 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_SPECIFIERr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 589 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_SPECIFIERr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 590 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_SPECIFIERr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 591 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_SPECIFIERr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 592 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_SPECIFIERr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 596 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 597 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 598 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr3, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 599 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 600 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 601 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr6, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 602 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr7, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 603 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr8, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 604 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr9, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 605 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr10, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 606 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr11, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 607 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr12, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 608 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr13, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 609 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr14, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 610 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SIMPLE_TYPE_SPECIFIERr15, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 614 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_NAMEr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 615 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_NAMEr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 616 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_NAMEr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 620 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ELABORATED_TYPE_SPECIFIERr1, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 621 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ELABORATED_TYPE_SPECIFIERr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 622 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ELABORATED_TYPE_SPECIFIERr3, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 623 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ELABORATED_TYPE_SPECIFIERr4, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 624 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ELABORATED_TYPE_SPECIFIERr5, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 626 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ELABORATED_TYPE_SPECIFIERr6, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 628 "120gram.y"
    { exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				(yyval.n) = NULL;
																				/*$$ = alacnary(ELABORATED_TYPE_SPECIFIERr7, 5, $1, $2, $3, $4, $6); */}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 642 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ENUM_SPECIFIERr1, 3, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 646 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ENUMERATOR_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 647 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ENUMERATOR_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 651 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ENUMERATOR_DEFINITIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 652 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ENUMERATOR_DEFINITIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 656 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ENUMERATORr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 671 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NAMESPACE_DEFINITIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 672 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NAMESPACE_DEFINITIONr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 676 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NAMED_NAMESPACE_DEFINITIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 677 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NAMED_NAMESPACE_DEFINITIONr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 681 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ORIGINAL_NAMESPACE_DEFINITIONr1, 3, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 686 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXTENSION_NAMESPACE_DEFINITIONr1, 3, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 690 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(UNNAMED_NAMESPACE_DEFINITIONr1, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 694 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NAMESPACE_BODYr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 705 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NAMESPACE_ALIAS_DEFINITIONr1, 3, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 709 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(QUALIFIED_NAMESPACE_SPECIFIERr1, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 710 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(QUALIFIED_NAMESPACE_SPECIFIERr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 711 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(QUALIFIED_NAMESPACE_SPECIFIERr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 712 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(QUALIFIED_NAMESPACE_SPECIFIERr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 717 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(USING_DECLARATIONr1, 5, (yyvsp[(1) - (6)].n), (yyvsp[(2) - (6)].n), (yyvsp[(3) - (6)].n), (yyvsp[(4) - (6)].n), (yyvsp[(5) - (6)].n)); }
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 719 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(USING_DECLARATIONr2, 4, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 721 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(USING_DECLARATIONr3, 4, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 722 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(USING_DECLARATIONr4, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 723 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(USING_DECLARATIONr5, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 728 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(USING_DIRECTIVEr1, 5, (yyvsp[(1) - (6)].n), (yyvsp[(2) - (6)].n), (yyvsp[(3) - (6)].n), (yyvsp[(4) - (6)].n), (yyvsp[(5) - (6)].n)); }
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 729 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(USING_DIRECTIVEr2, 4, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 731 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(USING_DIRECTIVEr3, 4, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 732 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(USING_DIRECTIVEr4, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 736 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASM_DEFINITIONr1, 2, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n)); }
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 740 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LINKAGE_SPECIFICATIONr1, 3, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 741 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(LINKAGE_SPECIFICATIONr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 749 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INIT_DECLARATOR_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 750 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INIT_DECLARATOR_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 754 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INIT_DECLARATORr1, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 758 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATORr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 759 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATORr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 763 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_DECLARATORr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 765 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_DECLARATORr2, 4, (yyvsp[(1) - (6)].n), (yyvsp[(3) - (6)].n), (yyvsp[(5) - (6)].n), (yyvsp[(6) - (6)].n)); }
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 767 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_DECLARATORr3, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 769 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_DECLARATORr4, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 771 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_DECLARATORr5, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 772 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_DECLARATORr6, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 774 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_DECLARATORr7, 4, (yyvsp[(1) - (6)].n), (yyvsp[(2) - (6)].n), (yyvsp[(3) - (6)].n), (yyvsp[(5) - (6)].n)); }
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 776 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_DECLARATORr8, 4, (yyvsp[(1) - (6)].n), (yyvsp[(2) - (6)].n), (yyvsp[(3) - (6)].n), (yyvsp[(5) - (6)].n)); }
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 777 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_DECLARATORr9, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 778 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_DECLARATORr10, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 782 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PTR_OPERATORr1, 0); }
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 783 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PTR_OPERATORr2, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 784 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PTR_OPERATORr3, 0); }
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 785 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PTR_OPERATORr4, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 786 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PTR_OPERATORr5, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 787 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PTR_OPERATORr6, 2, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n)); }
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 789 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PTR_OPERATORr7, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 793 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CV_QUALIFIER_SEQr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 794 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CV_QUALIFIER_SEQr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 798 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CV_QUALIFIERr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 799 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CV_QUALIFIERr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 803 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATOR_IDr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 804 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATOR_IDr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 805 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATOR_IDr3, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 806 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATOR_IDr4, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 810 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_IDr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 814 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_SPECIFIER_SEQr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 818 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ABSTRACT_DECLARATORr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 819 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ABSTRACT_DECLARATORr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 824 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATORr1, 4, (yyvsp[(1) - (6)].n), (yyvsp[(3) - (6)].n), (yyvsp[(5) - (6)].n), (yyvsp[(6) - (6)].n)); }
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 826 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATORr2, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 828 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATORr3, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 830 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATORr4, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 832 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATORr5, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 833 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATORr6, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 837 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 838 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 839 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 840 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr4, 0); }
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 841 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PARAMETER_DECLARATION_CLAUSEr5, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 845 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PARAMETER_DECLARATION_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 847 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PARAMETER_DECLARATION_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 851 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PARAMETER_DECLARATIONr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 853 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PARAMETER_DECLARATIONr2, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 854 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PARAMETER_DECLARATIONr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 856 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PARAMETER_DECLARATIONr4, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 860 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(FUNCTION_DEFINITIONr1, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 862 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(FUNCTION_DEFINITIONr2, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 863 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(FUNCTION_DEFINITIONr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 864 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(FUNCTION_DEFINITIONr4, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 868 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(FUNCTION_BODYr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 872 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INITIALIZERr1, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 873 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INITIALIZERr2, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 877 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INITIALIZER_CLAUSEr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 878 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INITIALIZER_CLAUSEr2, 2, (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 879 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INITIALIZER_CLAUSEr3, 0); }
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 883 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INITIALIZER_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 884 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INITIALIZER_LISTr1, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 892 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CLASS_SPECIFIERr1, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 896 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CLASS_HEADr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 897 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CLASS_HEADr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 898 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CLASS_HEADr3, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 900 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CLASS_HEADr4, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 904 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CLASS_KEYr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 905 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CLASS_KEYr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 906 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CLASS_KEYr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 910 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_SPECIFICATIONr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 911 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_SPECIFICATIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 915 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATIONr1, 2, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n)); }
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 916 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATIONr2, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 917 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATIONr3, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 918 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATIONr4, 0); }
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 919 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATIONr5, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 920 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATIONr6, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 921 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATIONr7, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 922 "120gram.y"
    { exitStatus = 3;
																				getErrorMessage(ER_TEMPLATE);
																				yyerror(NULL);
																				(yyval.n) = NULL;
																				/*$$ = alacnary(MEMBER_DECLARATIONr8, 1, $1); */}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 930 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATOR_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 931 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATOR_LISTr1, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 935 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATORr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 936 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATORr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 937 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATORr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 938 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_DECLARATORr4, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 947 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(PURE_SPECIFIERr1, 0); }
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 951 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONSTANT_INITIALIZERr1, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 959 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_CLAUSEr1, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 963 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIER_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 964 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIER_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 968 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIERr1, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 969 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIERr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 970 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIERr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 971 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIERr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 973 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIERr5, 5, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 975 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIERr6, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 977 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIERr7, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 978 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIERr8, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 980 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIERr9, 5, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 982 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIERr10, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 984 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIERr11, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 986 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(BASE_SPECIFIERr12, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 990 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ACCESS_SPECIFIERr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 991 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ACCESS_SPECIFIERr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 992 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ACCESS_SPECIFIERr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 1000 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONVERSION_FUNCTION_IDr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 1004 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONVERSION_TYPE_IDr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 1008 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONVERSION_DECLARATORr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 1012 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CTOR_INITIALIZERr1, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 1016 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEM_INITIALIZER_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 1017 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEM_INITIALIZER_LISTr1, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 1021 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEM_INITIALIZERr1, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 1025 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEM_INITIALIZER_IDr1, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 1026 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEM_INITIALIZER_IDr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 1027 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEM_INITIALIZER_IDr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 1028 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEM_INITIALIZER_IDr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 1029 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEM_INITIALIZER_IDr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 1037 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATOR_FUNCTION_IDr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 1041 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 1042 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 1043 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr3, 1, (yyvsp[(1) - (3)].n)); }
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 1044 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr4, 1, (yyvsp[(1) - (3)].n)); }
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 1045 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr5, 0); }
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 1046 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr6, 0); }
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 1047 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr7, 0); }
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 1048 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr8, 0); }
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 1049 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr9, 0); }
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 1050 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr10, 0); }
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 1051 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr11, 0); }
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 1052 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr12, 0); }
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 1053 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr13, 0); }
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 1054 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr14, 0); }
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 1055 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr15, 0); }
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 1056 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr16, 0); }
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 1057 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr17, 0); }
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 1058 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr18, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 1059 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr19, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 1060 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr20, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 1061 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr21, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 1062 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr22, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 1063 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr23, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 1064 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr24, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 1065 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr25, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 1066 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr26, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 1067 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr27, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 1068 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr28, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 1069 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr29, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 1070 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr30, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 1071 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr31, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 1072 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr32, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 1073 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr33, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 1074 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr34, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 1075 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr35, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 1076 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr36, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 1077 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr37, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 1078 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr38, 0); }
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 1079 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr39, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 1080 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr40, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 1081 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr41, 0); }
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 1082 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(OPERATORr42, 0); }
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 1091 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL; 
																			/*alacnary(TEMPLATE_DECLARATIONr1, 4, $1, $2, $4, $6); */}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 1099 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL; 
																			/*$$ = alacnary(TEMPLATE_PARAMETER_LISTr1, 1, $1); */}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 1104 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL; 
																			/*$$ = alacnary(TEMPLATE_PARAMETER_LISTr2, 2, $1, $3);*/ }
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 1112 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL; 
																			/*$$ = alacnary(TEMPLATE_PARAMETERr1, 1, $1); */}
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 1117 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL; 
																			/* $$ = alacnary(TEMPLATE_PARAMETERr2, 1, $1); */}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 1125 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL;
																			/*$$ = alacnary(TYPE_PARAMETERr1, 2, $1, $2);*/ }
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 1130 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL;
																			/*$$ = alacnary(TYPE_PARAMETERr2, 3, $1, $2, $4); */}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 1135 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL;
																			/*$$ = alacnary(TYPE_PARAMETERr3, 2, $1, $2);*/ }
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 1140 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL;
																			/*$$ = alacnary(TYPE_PARAMETERr4, 3, $1, $2, $4); */}
    break;

  case 433:

/* Line 1464 of yacc.c  */
#line 1146 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL; /*alacnary(TYPE_PARAMETERr5, 4, $1, $3, $5, $6);*/ }
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 1151 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL; /*alacnary(TYPE_PARAMETERr6, 5, $1, $3, $5, $6, $8);*/ }
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 1158 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL; /*alacnary(TEMPLATE_IDr1, 2, $1, $3);*/ }
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 1165 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL;
																			/*$$ = alacnary(TEMPLATE_ARGUMENT_LISTr1, 1, $1); */}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 1170 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL;
																			/*$$ = alacnary(TEMPLATE_ARGUMENT_LISTr2, 2, $1, $3);*/}
    break;

  case 438:

/* Line 1464 of yacc.c  */
#line 1178 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL;
																			/*$$ = alacnary(TEMPLATE_ARGUMENTr1, 1, $1);*/ }
    break;

  case 439:

/* Line 1464 of yacc.c  */
#line 1183 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL;
																			/*$$ = alacnary(TEMPLATE_ARGUMENTr2, 1, $1);*/ }
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 1188 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL;
																			/*$$ = alacnary(TEMPLATE_ARGUMENTr3, 1, $1);*/ }
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 1196 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL; 
																			/*alacnary(EXPLICIT_INSTANTIATIONr1, 2, $1, $2);*/ }
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 1204 "120gram.y"
    { exitStatus = 3;
																			getErrorMessage(ER_TEMPLATE);
																			yyerror(NULL);
																			(yyval.n) = NULL; 
																			/*alacnary(EXPLICIT_SPECIALIZATIONr1, 2, $1, $4);*/ }
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 1216 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TRY_BLOCKr1, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 1220 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(FUNCTION_TRY_BLOCKr1, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 445:

/* Line 1464 of yacc.c  */
#line 1224 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(HANDLER_SEQr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 446:

/* Line 1464 of yacc.c  */
#line 1229 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(HANDLERr1, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 447:

/* Line 1464 of yacc.c  */
#line 1233 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXCEPTION_DECLARATIONr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 448:

/* Line 1464 of yacc.c  */
#line 1234 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXCEPTION_DECLARATIONr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 1235 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXCEPTION_DECLARATIONr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 1236 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXCEPTION_DECLARATIONr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 1240 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(THROW_EXPRESSIONr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 1244 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXCEPTION_SPECIFICATIONr1, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 1248 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_ID_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 1249 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_ID_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 1257 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATION_SEQ_OPTr1, 0); }
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 1258 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DECLARATION_SEQ_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 1262 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NESTED_NAME_SPECIFIER_OPTr1, 0); }
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 1263 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NESTED_NAME_SPECIFIER_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 1267 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXPRESSION_LIST_OPTr1, 0); }
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 1268 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXPRESSION_LIST_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 1272 "120gram.y"
    { (yyval.n) = (TreeNode *)(TreeNode *)alacnary(COLONCOLON_OPTr1, 0); }
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 1273 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(COLONCOLON_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 1277 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_PLACEMENT_OPTr1, 0); }
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 1278 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_PLACEMENT_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 1282 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_INITIALIZER_OPTr1, 0); }
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 1283 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_INITIALIZER_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 1287 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_DECLARATOR_OPTr1, 0); }
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 1288 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(NEW_DECLARATOR_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 1292 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXPRESSION_OPTr1, 0); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 1293 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXPRESSION_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 1297 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STATEMENT_SEQ_OPTr1, 0); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 1298 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(STATEMENT_SEQ_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 1302 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONDITION_OPTr1, 0); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 1303 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONDITION_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 1307 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ENUMERATOR_LIST_OPTr1, 0); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 1308 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ENUMERATOR_LIST_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 1312 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INITIALIZER_OPTr1, 0); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 1313 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(INITIALIZER_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 1317 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONSTANT_EXPRESSION_OPTr1, 0); }
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 1318 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONSTANT_EXPRESSION_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 1322 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ABSTRACT_DECLARATOR_OPTr1, 0); }
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 1323 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ABSTRACT_DECLARATOR_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 1327 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_SPECIFIER_SEQ_OPTr1, 0); }
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 1328 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_SPECIFIER_SEQ_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 1332 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATOR_OPTr1, 0); }
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 1333 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(DIRECT_ABSTRACT_DECLARATOR_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 1337 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CTOR_INITIALIZER_OPTr1, 0); }
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 1338 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CTOR_INITIALIZER_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 1342 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(COMMA_OPTr1, 0); }
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 1343 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(COMMA_OPTr2, 0); }
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 1347 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_SPECIFICATION_OPTr1, 0); }
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 1348 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(MEMBER_SPECIFICATION_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 1352 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SEMICOLON_OPTr1, 0); }
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 1353 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(SEMICOLON_OPTr2, 0); }
    break;

  case 495:

/* Line 1464 of yacc.c  */
#line 1357 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONVERSION_DECLARATOR_OPTr1, 0); }
    break;

  case 496:

/* Line 1464 of yacc.c  */
#line 1358 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(CONVERSION_DECLARATOR_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 497:

/* Line 1464 of yacc.c  */
#line 1362 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXPORT_OPTr1, 0); }
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 1363 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(EXPORT_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 499:

/* Line 1464 of yacc.c  */
#line 1367 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(HANDLER_SEQ_OPTr1, 0); }
    break;

  case 500:

/* Line 1464 of yacc.c  */
#line 1368 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(HANDLER_SEQ_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 501:

/* Line 1464 of yacc.c  */
#line 1372 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSION_OPTr1, 0); }
    break;

  case 502:

/* Line 1464 of yacc.c  */
#line 1373 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(ASSIGNMENT_EXPRESSION_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 503:

/* Line 1464 of yacc.c  */
#line 1377 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_ID_LIST_OPTr1, 0); }
    break;

  case 504:

/* Line 1464 of yacc.c  */
#line 1378 "120gram.y"
    { (yyval.n) = (TreeNode *)alacnary(TYPE_ID_LIST_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;



/* Line 1464 of yacc.c  */
#line 6707 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 1381 "120gram.y"


int main(int argc, char **argv){
	int rv;
   if(argc > 1) { 
		int f;
		//read each file in arguments
		for(f = 1; f < argc; f++) {
			fname = argv[f];
			FILE *infile = fopen(fname, "r");
			yyin = infile;
			lineno = 1;
			if(!yyin){
				printf("Error reading file %s\n", argv[f]);
				exit(1);
			}
			rv = yyparse();
			switch(rv){
				case 0 :
					globalSymbolTable = (SymbolTable *)createGlobalSymbolTable(SYMBOL_TABLE_SIZE);
					currentSymbolTable = globalSymbolTable;
					buildTypes(root);
					printTree(root, 0);
					break;
				case 1 :
					if(exitStatus < 2) exitStatus = 2;
					break;
			}
		}
	} else { //no files in arguments
		printf("Missing file name.\n");
		exit(4);
	}
	//printf("\n%d\n", exitStatus);
   return exitStatus;
}

