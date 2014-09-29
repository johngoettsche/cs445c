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
#line 44 "120gram.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "errors.h"
#include "token.h"
#include "120parse.h"

extern int lineno;
extern Token *yytoken;
int yydebug=1;
FILE *yyin;
char *fname;
int errors;
ErrorMessage *e_message;

//static void yyerror(char *s);


/* Line 189 of yacc.c  */
#line 94 "y.tab.c"

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
#line 65 "120gram.y"

	Token *t;
	struct TreeNode *n;



/* Line 214 of yacc.c  */
#line 339 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 351 "y.tab.c"

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
#define YYFINAL  176
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4103

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  128
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  171
/* YYNRULES -- Number of rules.  */
#define YYNRULES  501
/* YYNRULES -- Number of states.  */
#define YYNSTATES  844

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
      61,    63,    66,    69,    73,    80,    83,    86,    88,    93,
      98,   104,   109,   114,   118,   124,   129,   134,   138,   141,
     144,   152,   160,   168,   176,   181,   186,   188,   192,   194,
     197,   200,   203,   206,   209,   212,   217,   219,   221,   223,
     225,   227,   229,   234,   240,   247,   255,   259,   262,   265,
     267,   271,   276,   280,   283,   287,   292,   298,   300,   305,
     307,   311,   315,   317,   321,   325,   329,   331,   335,   339,
     341,   345,   349,   351,   355,   359,   363,   367,   369,   373,
     377,   379,   383,   385,   389,   391,   395,   397,   401,   403,
     407,   409,   415,   417,   421,   423,   425,   427,   429,   431,
     433,   435,   437,   439,   441,   443,   445,   447,   451,   453,
     455,   457,   459,   461,   463,   465,   467,   469,   473,   478,
     482,   485,   489,   491,   494,   500,   508,   514,   516,   521,
     527,   535,   544,   546,   548,   551,   554,   558,   562,   564,
     566,   569,   571,   573,   575,   577,   579,   581,   583,   585,
     587,   589,   591,   593,   597,   600,   602,   604,   606,   608,
     610,   612,   615,   617,   619,   621,   623,   625,   627,   629,
     631,   633,   635,   637,   639,   641,   643,   646,   650,   652,
     654,   656,   658,   660,   662,   664,   666,   668,   670,   672,
     674,   676,   678,   680,   685,   689,   694,   698,   702,   707,
     715,   721,   723,   727,   729,   733,   735,   737,   739,   741,
     743,   749,   755,   760,   762,   768,   772,   775,   778,   780,
     787,   793,   799,   804,   809,   816,   822,   828,   833,   839,
     845,   849,   851,   855,   858,   860,   863,   865,   872,   878,
     884,   889,   894,   898,   900,   903,   905,   908,   912,   916,
     921,   923,   926,   928,   930,   932,   935,   939,   942,   945,
     948,   951,   953,   960,   966,   972,   977,   982,   986,   989,
     991,   993,   994,   998,  1000,  1004,  1007,  1012,  1015,  1020,
    1024,  1029,  1032,  1036,  1038,  1041,  1045,  1047,  1052,  1055,
    1057,  1061,  1066,  1069,  1073,  1077,  1082,  1084,  1086,  1088,
    1091,  1095,  1099,  1102,  1105,  1107,  1110,  1113,  1115,  1117,
    1119,  1123,  1124,  1126,  1129,  1132,  1136,  1139,  1142,  1145,
    1147,  1151,  1155,  1158,  1161,  1163,  1169,  1174,  1179,  1183,
    1189,  1194,  1199,  1203,  1205,  1207,  1209,  1212,  1215,  1218,
    1221,  1223,  1227,  1232,  1236,  1239,  1242,  1244,  1246,  1249,
    1251,  1253,  1257,  1261,  1263,  1265,  1267,  1269,  1271,  1273,
    1275,  1277,  1279,  1281,  1283,  1285,  1287,  1289,  1291,  1293,
    1295,  1297,  1299,  1301,  1303,  1305,  1307,  1309,  1311,  1313,
    1315,  1317,  1319,  1321,  1323,  1325,  1327,  1329,  1331,  1333,
    1336,  1339,  1346,  1348,  1352,  1354,  1356,  1359,  1364,  1367,
    1372,  1379,  1388,  1393,  1395,  1399,  1401,  1403,  1405,  1408,
    1413,  1417,  1422,  1425,  1431,  1434,  1437,  1439,  1441,  1444,
    1449,  1451,  1455,  1456,  1458,  1459,  1461,  1462,  1464,  1465,
    1467,  1468,  1470,  1471,  1473,  1474,  1476,  1477,  1479,  1480,
    1482,  1483,  1485,  1486,  1488,  1489,  1491,  1492,  1494,  1495,
    1497,  1498,  1500,  1501,  1503,  1504,  1506,  1507,  1509,  1510,
    1512,  1513,  1515,  1516,  1518,  1519,  1521,  1522,  1524,  1525,
    1527,  1528
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
      85,   145,    -1,   132,    14,   147,   130,    14,   147,    -1,
     132,    14,    -1,   130,    14,    -1,   143,    -1,   148,   105,
     174,   106,    -1,   148,   102,   276,   103,    -1,   148,   107,
      85,    14,   144,    -1,   148,   107,    85,   144,    -1,   148,
     107,    14,   144,    -1,   148,   107,   144,    -1,   148,    37,
      85,    14,   144,    -1,   148,    37,    85,   144,    -1,   148,
      37,    14,   144,    -1,   148,    37,   144,    -1,   148,    34,
      -1,   148,    35,    -1,    53,   108,   223,   109,   102,   174,
     103,    -1,    82,   108,   223,   109,   102,   174,   103,    -1,
      76,   108,   223,   109,   102,   174,   103,    -1,    47,   108,
     223,   109,   102,   174,   103,    -1,    91,   102,   174,   103,
      -1,    91,   102,   223,   103,    -1,   172,    -1,   149,   110,
     172,    -1,   148,    -1,    34,   159,    -1,    35,   159,    -1,
     111,   159,    -1,   112,   159,    -1,   151,   159,    -1,    80,
     150,    -1,    80,   102,   223,   103,    -1,   152,    -1,   158,
      -1,   113,    -1,   114,    -1,   115,    -1,   104,    -1,    70,
     278,   154,   279,    -1,    14,    70,   278,   154,   279,    -1,
      70,   278,   102,   223,   103,   279,    -1,    14,    70,   278,
     102,   223,   103,   279,    -1,   102,   149,   103,    -1,   224,
     280,    -1,   219,   280,    -1,   156,    -1,   105,   174,   106,
      -1,   156,   105,   175,   106,    -1,   102,   276,   103,    -1,
      50,   159,    -1,    14,    50,   159,    -1,    50,   105,   106,
     159,    -1,    14,    50,   105,   106,   159,    -1,   150,    -1,
     102,   223,   103,   159,    -1,   159,    -1,   160,    15,   159,
      -1,   160,    36,   159,    -1,   160,    -1,   161,   111,   160,
      -1,   161,   116,   160,    -1,   161,   117,   160,    -1,   161,
      -1,   162,   113,   161,    -1,   162,   114,   161,    -1,   162,
      -1,   163,    24,   162,    -1,   163,    25,   162,    -1,   163,
      -1,   164,   108,   163,    -1,   164,   109,   163,    -1,   164,
      30,   163,    -1,   164,    31,   163,    -1,   164,    -1,   165,
      28,   164,    -1,   165,    29,   164,    -1,   165,    -1,   166,
     112,   165,    -1,   166,    -1,   167,   118,   166,    -1,   167,
      -1,   168,   119,   167,    -1,   168,    -1,   169,    32,   168,
      -1,   169,    -1,   170,    33,   169,    -1,   170,    -1,   170,
     120,   174,   121,   172,    -1,   171,    -1,   170,   173,   172,
      -1,   271,    -1,   122,    -1,    18,    -1,    19,    -1,    20,
      -1,    16,    -1,    17,    -1,    26,    -1,    27,    -1,    22,
      -1,    21,    -1,    23,    -1,   172,    -1,   174,   110,   172,
      -1,   171,    -1,   177,    -1,   178,    -1,   179,    -1,   181,
      -1,   183,    -1,   185,    -1,   186,    -1,   266,    -1,   135,
     121,   176,    -1,    42,   175,   121,   176,    -1,    49,   121,
     176,    -1,   281,   123,    -1,   124,   282,   125,    -1,   176,
      -1,   180,   176,    -1,    64,   102,   182,   103,   176,    -1,
      64,   102,   182,   103,   176,    54,   176,    -1,    84,   102,
     182,   103,   176,    -1,   174,    -1,   224,   217,   122,   172,
      -1,   100,   102,   182,   103,   176,    -1,    51,   176,   100,
     102,   174,   103,   123,    -1,    61,   102,   184,   283,   123,
     281,   103,   176,    -1,   178,    -1,   190,    -1,    41,   123,
      -1,    48,   123,    -1,    77,   281,   123,    -1,    63,   135,
     123,    -1,   189,    -1,   188,    -1,   187,   188,    -1,   189,
      -1,   230,    -1,   257,    -1,   264,    -1,   265,    -1,   214,
      -1,   203,    -1,   190,    -1,   213,    -1,   209,    -1,   211,
      -1,   212,    -1,   192,   215,   123,    -1,   192,   123,    -1,
     193,    -1,   195,    -1,   194,    -1,    62,    -1,    90,    -1,
     191,    -1,   192,   191,    -1,    39,    -1,    75,    -1,    81,
      -1,    58,    -1,    68,    -1,    65,    -1,    96,    -1,    56,
      -1,   196,    -1,   235,    -1,   199,    -1,   198,    -1,   221,
      -1,   197,    -1,   147,   197,    -1,    14,   275,   197,    -1,
      44,    -1,    99,    -1,    40,    -1,    78,    -1,    66,    -1,
      67,    -1,    79,    -1,    94,    -1,    60,    -1,    52,    -1,
      97,    -1,   101,    -1,   132,    -1,   133,    -1,   129,    -1,
     237,    14,   147,   135,    -1,   237,    14,   135,    -1,    55,
      14,   147,   135,    -1,    55,    14,   135,    -1,    55,   147,
     135,    -1,    92,   277,   147,   135,    -1,    92,   277,   147,
     135,   108,   262,   109,    -1,    55,   135,   124,   284,   125,
      -1,   201,    -1,   200,   110,   201,    -1,   202,    -1,   202,
     122,   175,    -1,   135,    -1,   204,    -1,   207,    -1,   205,
      -1,   206,    -1,    69,   135,   124,   208,   125,    -1,    69,
     131,   124,   208,   125,    -1,    69,   124,   208,   125,    -1,
     274,    -1,    69,   135,   122,   210,   123,    -1,    14,   147,
     130,    -1,    14,   130,    -1,   147,   130,    -1,   130,    -1,
      95,    92,    14,   147,   145,   123,    -1,    95,    92,   147,
     145,   123,    -1,    95,    14,   147,   145,   123,    -1,    95,
     147,   145,   123,    -1,    95,    14,   145,   123,    -1,    95,
      69,    14,   147,   130,   123,    -1,    95,    69,    14,   130,
     123,    -1,    95,    69,   147,   130,   123,    -1,    95,    69,
     130,   123,    -1,    38,   102,   140,   103,   123,    -1,    58,
     140,   124,   274,   125,    -1,    58,   140,   188,    -1,   216,
      -1,   215,   110,   216,    -1,   217,   285,    -1,   218,    -1,
     219,   217,    -1,   222,    -1,   218,   102,   227,   103,   220,
     272,    -1,   218,   102,   227,   103,   220,    -1,   218,   102,
     227,   103,   272,    -1,   218,   102,   227,   103,    -1,   218,
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
      -1,   236,   124,   292,   125,    -1,   237,   135,    -1,   237,
     135,   244,    -1,   237,   147,   135,    -1,   237,   147,   135,
     244,    -1,    45,    -1,    83,    -1,    93,    -1,   239,   292,
      -1,   247,   121,   292,    -1,   192,   240,   123,    -1,   192,
     123,    -1,   240,   123,    -1,   123,    -1,   230,   293,    -1,
     146,   123,    -1,   211,    -1,   257,    -1,   241,    -1,   240,
     110,   241,    -1,    -1,   217,    -1,   217,   242,    -1,   217,
     243,    -1,   135,   121,   175,    -1,   122,   126,    -1,   122,
     175,    -1,   121,   245,    -1,   246,    -1,   245,   110,   246,
      -1,    14,   147,   132,    -1,    14,   132,    -1,   147,   132,
      -1,   132,    -1,    96,   247,    14,   275,   132,    -1,    96,
     247,   275,   132,    -1,    96,    14,   275,   132,    -1,    96,
     275,   132,    -1,   247,    96,    14,   275,   132,    -1,   247,
      96,   275,   132,    -1,   247,    14,   275,   132,    -1,   247,
     275,   132,    -1,    72,    -1,    73,    -1,    74,    -1,    71,
     249,    -1,   224,   294,    -1,   219,   294,    -1,   121,   252,
      -1,   253,    -1,   253,   110,   252,    -1,   254,   102,   276,
     103,    -1,    14,   147,   132,    -1,    14,   132,    -1,   147,
     132,    -1,   132,    -1,   135,    -1,    71,   256,    -1,    70,
      -1,    50,    -1,    70,   105,   106,    -1,    50,   105,   106,
      -1,   113,    -1,   127,    -1,   111,    -1,   116,    -1,   117,
      -1,   118,    -1,   112,    -1,   119,    -1,   104,    -1,   115,
      -1,   122,    -1,   108,    -1,   109,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,
      -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
      -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,    32,
      -1,    33,    -1,    34,    -1,    35,    -1,   110,    -1,    36,
      -1,    37,    -1,   102,   103,    -1,   105,   106,    -1,   295,
      85,   108,   258,   109,   188,    -1,   259,    -1,   258,   110,
     259,    -1,   260,    -1,   229,    -1,    45,   135,    -1,    45,
     135,   122,   223,    -1,    92,   135,    -1,    92,   135,   122,
     223,    -1,    85,   108,   258,   109,    45,   135,    -1,    85,
     108,   258,   109,    45,   135,   122,   134,    -1,   134,   108,
     262,   109,    -1,   263,    -1,   262,   110,   263,    -1,   172,
      -1,   223,    -1,   134,    -1,    85,   188,    -1,    85,   108,
     109,   188,    -1,    89,   179,   268,    -1,    89,   290,   231,
     268,    -1,   269,   296,    -1,    43,   102,   270,   103,   179,
      -1,   224,   217,    -1,   224,   225,    -1,   224,    -1,    13,
      -1,    87,   297,    -1,    87,   102,   298,   103,    -1,   223,
      -1,   273,   110,   223,    -1,    -1,   187,    -1,    -1,   147,
      -1,    -1,   149,    -1,    -1,    14,    -1,    -1,   153,    -1,
      -1,   157,    -1,    -1,   155,    -1,    -1,   174,    -1,    -1,
     180,    -1,    -1,   182,    -1,    -1,   200,    -1,    -1,   232,
      -1,    -1,   175,    -1,    -1,   225,    -1,    -1,   224,    -1,
      -1,   226,    -1,    -1,   251,    -1,    -1,   110,    -1,    -1,
     238,    -1,    -1,   123,    -1,    -1,   250,    -1,    -1,    57,
      -1,    -1,   268,    -1,    -1,   172,    -1,    -1,   273,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   131,   131,   135,   140,   145,   146,   151,   156,   164,
     168,   169,   170,   171,   172,   176,   180,   184,   188,   192,
     193,   201,   209,   210,   211,   212,   216,   217,   221,   222,
     223,   224,   228,   229,   233,   235,   236,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   262,   263,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   280,   281,
     282,   283,   287,   288,   289,   290,   294,   298,   302,   303,
     307,   308,   312,   316,   317,   318,   319,   323,   324,   328,
     329,   330,   334,   335,   336,   337,   341,   342,   343,   347,
     348,   349,   353,   354,   355,   356,   357,   361,   362,   363,
     367,   368,   372,   373,   377,   378,   382,   383,   387,   388,
     392,   393,   397,   398,   399,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   417,   418,   422,   430,
     431,   432,   433,   434,   435,   436,   437,   441,   442,   443,
     447,   451,   455,   456,   460,   461,   462,   466,   467,   471,
     472,   473,   477,   478,   482,   483,   484,   485,   489,   497,
     498,   502,   503,   504,   505,   506,   507,   508,   512,   513,
     514,   515,   516,   520,   521,   525,   526,   527,   528,   529,
     533,   534,   538,   539,   540,   541,   542,   546,   547,   548,
     552,   553,   554,   555,   556,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     578,   579,   580,   584,   585,   586,   587,   588,   589,   590,
     600,   604,   605,   609,   610,   614,   629,   630,   634,   635,
     639,   643,   647,   651,   661,   665,   666,   667,   668,   672,
     673,   674,   675,   676,   680,   681,   682,   683,   687,   691,
     692,   700,   701,   705,   709,   710,   714,   715,   716,   717,
     718,   719,   720,   724,   725,   726,   727,   728,   729,   730,
     734,   735,   739,   740,   744,   745,   746,   747,   751,   755,
     759,   760,   764,   765,   766,   767,   768,   769,   773,   774,
     775,   776,   777,   781,   782,   786,   787,   788,   789,   793,
     794,   795,   796,   800,   804,   805,   809,   810,   811,   815,
     816,   824,   828,   829,   830,   831,   835,   836,   837,   841,
     842,   846,   847,   848,   849,   850,   851,   852,   853,   857,
     858,   861,   862,   863,   864,   865,   874,   878,   886,   890,
     891,   895,   896,   897,   898,   899,   900,   901,   902,   903,
     904,   905,   906,   910,   911,   912,   920,   924,   928,   932,
     936,   937,   941,   945,   946,   947,   948,   949,   957,   961,
     962,   963,   964,   965,   966,   967,   968,   969,   970,   971,
     972,   973,   974,   975,   976,   977,   978,   979,   980,   981,
     982,   983,   984,   985,   986,   987,   988,   989,   990,   991,
     992,   993,   994,   995,   996,   997,   998,   999,  1000,  1001,
    1002,  1010,  1014,  1015,  1019,  1020,  1024,  1025,  1026,  1027,
    1028,  1029,  1033,  1037,  1038,  1042,  1043,  1044,  1048,  1052,
    1060,  1064,  1068,  1072,  1076,  1077,  1078,  1079,  1083,  1087,
    1091,  1092,  1099,  1101,  1104,  1106,  1109,  1111,  1114,  1116,
    1119,  1121,  1124,  1126,  1129,  1131,  1134,  1136,  1139,  1141,
    1144,  1146,  1149,  1151,  1154,  1156,  1159,  1161,  1164,  1166,
    1169,  1171,  1174,  1176,  1179,  1181,  1184,  1186,  1189,  1191,
    1194,  1196,  1199,  1201,  1204,  1206,  1209,  1211,  1214,  1216,
    1219,  1221
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
     145,   145,   146,   146,   147,   147,   147,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   149,   149,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   151,   151,
     151,   151,   152,   152,   152,   152,   153,   154,   155,   155,
     156,   156,   157,   158,   158,   158,   158,   159,   159,   160,
     160,   160,   161,   161,   161,   161,   162,   162,   162,   163,
     163,   163,   164,   164,   164,   164,   164,   165,   165,   165,
     166,   166,   167,   167,   168,   168,   169,   169,   170,   170,
     171,   171,   172,   172,   172,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   174,   174,   175,   176,
     176,   176,   176,   176,   176,   176,   176,   177,   177,   177,
     178,   179,   180,   180,   181,   181,   181,   182,   182,   183,
     183,   183,   184,   184,   185,   185,   185,   185,   186,   187,
     187,   188,   188,   188,   188,   188,   188,   188,   189,   189,
     189,   189,   189,   190,   190,   191,   191,   191,   191,   191,
     192,   192,   193,   193,   193,   193,   193,   194,   194,   194,
     195,   195,   195,   195,   195,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     197,   197,   197,   198,   198,   198,   198,   198,   198,   198,
     199,   200,   200,   201,   201,   202,   203,   203,   204,   204,
     205,   206,   207,   208,   209,   210,   210,   210,   210,   211,
     211,   211,   211,   211,   212,   212,   212,   212,   213,   214,
     214,   215,   215,   216,   217,   217,   218,   218,   218,   218,
     218,   218,   218,   219,   219,   219,   219,   219,   219,   219,
     220,   220,   221,   221,   222,   222,   222,   222,   223,   224,
     225,   225,   226,   226,   226,   226,   226,   226,   227,   227,
     227,   227,   227,   228,   228,   229,   229,   229,   229,   230,
     230,   230,   230,   231,   232,   232,   233,   233,   233,   234,
     234,   235,   236,   236,   236,   236,   237,   237,   237,   238,
     238,   239,   239,   239,   239,   239,   239,   239,   239,   240,
     240,   241,   241,   241,   241,   241,   242,   243,   244,   245,
     245,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   247,   247,   247,   248,   249,   250,   251,
     252,   252,   253,   254,   254,   254,   254,   254,   255,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   257,   258,   258,   259,   259,   260,   260,   260,   260,
     260,   260,   261,   262,   262,   263,   263,   263,   264,   265,
     266,   267,   268,   269,   270,   270,   270,   270,   271,   272,
     273,   273,   274,   274,   275,   275,   276,   276,   277,   277,
     278,   278,   279,   279,   280,   280,   281,   281,   282,   282,
     283,   283,   284,   284,   285,   285,   286,   286,   287,   287,
     288,   288,   289,   289,   290,   290,   291,   291,   292,   292,
     293,   293,   294,   294,   295,   295,   296,   296,   297,   297,
     298,   298
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     6,     2,     2,     1,     4,     4,
       5,     4,     4,     3,     5,     4,     4,     3,     2,     2,
       7,     7,     7,     7,     4,     4,     1,     3,     1,     2,
       2,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     4,     5,     6,     7,     3,     2,     2,     1,
       3,     4,     3,     2,     3,     4,     5,     1,     4,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     1,     2,     5,     7,     5,     1,     4,     5,
       7,     8,     1,     1,     2,     2,     3,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     4,     3,     3,     4,     7,
       5,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       5,     5,     4,     1,     5,     3,     2,     2,     1,     6,
       5,     5,     4,     4,     6,     5,     5,     4,     5,     5,
       3,     1,     3,     2,     1,     2,     1,     6,     5,     5,
       4,     4,     3,     1,     2,     1,     2,     3,     3,     4,
       1,     2,     1,     1,     1,     2,     3,     2,     2,     2,
       2,     1,     6,     5,     5,     4,     4,     3,     2,     1,
       1,     0,     3,     1,     3,     2,     4,     2,     4,     3,
       4,     2,     3,     1,     2,     3,     1,     4,     2,     1,
       3,     4,     2,     3,     3,     4,     1,     1,     1,     2,
       3,     3,     2,     2,     1,     2,     2,     1,     1,     1,
       3,     0,     1,     2,     2,     3,     2,     2,     2,     1,
       3,     3,     2,     2,     1,     5,     4,     4,     3,     5,
       4,     4,     3,     1,     1,     1,     2,     2,     2,     2,
       1,     3,     4,     3,     2,     2,     1,     1,     2,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     6,     1,     3,     1,     1,     2,     4,     2,     4,
       6,     8,     4,     1,     3,     1,     1,     1,     2,     4,
       3,     4,     2,     5,     2,     2,     1,     1,     2,     4,
       1,     3,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     452,     9,     2,     4,     5,     7,     8,     0,     0,   192,
     210,   208,   326,   282,   217,     0,   199,   495,   195,   216,
     188,   197,   212,   213,   196,     0,     0,   193,   211,   214,
     194,   327,     0,   189,   458,   328,   215,     0,   198,   218,
     283,   209,   219,     0,     0,   273,   275,   222,     0,     3,
     220,   221,     0,    28,     0,   284,    26,    27,     0,   453,
     169,   171,   178,   190,     0,   185,   187,   186,   200,   205,
     203,   202,   177,   236,   238,   239,   237,   180,   181,   182,
     179,   176,   484,   264,     0,   204,   266,   172,   201,     0,
       0,    30,    29,   173,     6,   174,   175,    21,     0,   285,
       0,   287,     0,     0,     0,     0,     0,     0,    18,     0,
     452,     0,     0,   454,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   417,   418,   380,   379,     0,   391,
       0,   394,   395,   416,   385,   389,   383,   392,   386,   387,
     388,   390,   393,   384,     0,   480,   492,   366,   378,     0,
     438,   459,     0,     0,     0,     0,     0,     0,     0,     0,
      31,   274,   280,    36,    35,     0,     1,     0,   276,   220,
      32,   206,   170,   195,   184,   191,     0,   261,   474,   484,
       0,   485,   311,     0,   301,   476,   265,   341,     0,   322,
       0,     0,   278,   286,   207,     0,   226,     0,   472,   227,
     452,   260,     0,   243,   452,     0,   452,   455,     0,     0,
     419,   420,   481,   289,     0,     0,   492,   493,   367,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     272,   281,     0,    15,    17,    16,   454,     0,     0,     0,
       0,     0,    20,   460,     0,     0,     0,    23,   498,    19,
       0,     0,    71,     0,     0,    68,    69,    70,   437,    22,
      10,    11,    12,    13,    14,    37,    25,     0,    58,    87,
       0,    66,    67,    89,    92,    96,    99,   102,   107,   110,
     112,   114,   116,   118,   120,   122,   435,   436,   478,     0,
     433,   124,    33,   277,     0,   183,     0,     0,   475,   312,
     263,     0,     0,     0,   376,   377,     0,   369,   370,     0,
     466,   313,   309,   300,   478,     0,   299,   303,     0,     0,
     120,   138,   477,     0,   363,   364,   365,     0,   334,    28,
      27,   341,   337,   342,   490,   489,   341,     0,   339,     0,
     338,     0,   224,     0,     0,   323,   324,     0,   279,     0,
     225,   235,   473,   231,   233,     0,     0,   242,     0,     0,
     248,     0,     0,     0,   382,   381,     0,   368,   439,   228,
     253,     0,     0,     0,   257,     0,     0,     0,   252,     0,
       0,   460,    59,    60,     0,     0,    83,     0,     0,   461,
       0,     0,     0,    64,     0,   499,   448,     0,   136,     0,
       0,    61,    62,    48,    49,     0,   456,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   126,   127,   128,   134,   133,   135,   131,   132,     0,
       0,   125,     0,   482,   478,   479,   291,   288,     0,   432,
       0,   262,   474,     0,    56,     0,   316,   314,   310,     0,
     374,     0,   375,     0,   456,     0,     0,     0,     0,   466,
       0,     0,     0,     0,   466,     0,     0,     0,    28,   467,
     152,   139,   140,   141,   466,   142,   143,   144,   145,   168,
       0,   146,     0,     0,   482,   305,   478,   307,   270,   298,
       0,   271,     0,   336,   332,   342,     0,     0,   343,   344,
     491,   335,   329,   341,   333,   341,   321,   223,     0,     0,
     354,     0,   348,   349,     0,   325,   326,     0,   458,   425,
       0,   422,   424,   258,     0,     0,   230,   259,   241,   246,
       0,   247,   244,   240,     0,   251,   255,     0,   256,     0,
     250,     0,     0,    84,     0,     0,     0,     0,     0,     0,
     462,   464,     0,     0,     0,     0,     0,    24,     0,     0,
       0,     0,    47,   457,     0,     0,     0,     0,    43,    90,
      91,    93,    94,    95,    97,    98,   100,   101,   105,   106,
     103,   104,   108,   109,   111,   113,   115,   117,   119,     0,
     123,     0,   290,   301,   476,   434,   315,     0,   318,   319,
     486,     0,   441,   496,   373,   371,     0,   164,     0,   165,
     466,     0,   466,     0,     0,     0,     0,     0,     0,     0,
     466,   153,   150,   151,     0,     0,     0,   268,   269,   302,
     304,   345,   331,   346,   347,   342,   340,   330,   352,     0,
       0,     0,     0,   353,     0,     0,     0,     0,   426,     0,
     428,     0,     0,   232,   234,   245,     0,   254,   249,    34,
       0,     0,   462,     0,    85,     0,    76,     0,   456,   463,
      72,     0,   465,    79,   464,    77,     0,    65,     0,    54,
      55,   137,    88,    46,     0,    45,    39,    38,    42,     0,
      41,     0,   297,     0,     0,    57,   487,     0,     0,   497,
     442,   372,   466,   149,     0,   162,   470,   163,   167,   157,
       0,     0,   166,     0,   440,     0,   147,   306,   308,   500,
     267,   351,     0,     0,     0,   358,   350,     0,     0,     0,
     362,     0,     0,     0,   421,   423,   229,    86,     0,    73,
       0,     0,   462,     0,     0,     0,    78,     0,     0,    44,
      40,   121,   295,   296,   320,   317,   447,   446,     0,   148,
       0,   471,     0,   466,     0,   466,   466,   450,   501,     0,
     357,     0,   356,   361,     0,   360,   427,     0,   429,   462,
       0,     0,    74,    82,    80,     0,     0,     0,   293,   294,
     444,   445,     0,     0,   466,   154,     0,   156,   159,     0,
     449,   355,   359,     0,    75,    53,    50,    81,    52,    51,
     292,   443,     0,     0,   466,   158,   451,   430,   160,   466,
     155,     0,   161,   431
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    47,    48,    49,   105,    51,    52,    53,   269,   270,
     271,   272,   273,   274,    54,   275,   276,    56,    57,   329,
     278,   583,   279,   280,   281,   399,   570,   692,   693,   689,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   408,   452,   489,   332,   490,   491,
     492,   493,   494,   495,   730,   496,   726,   497,   498,    59,
      60,   499,    62,    63,   500,    65,    66,    67,    68,    69,
      70,    71,   362,   363,   364,    72,    73,    74,    75,    76,
     212,    77,   372,    78,    79,    80,    81,   186,   187,    82,
      83,    84,   171,    85,    86,   297,   298,   455,   456,   325,
     326,   539,    87,   322,   308,   467,   620,    88,    89,    90,
     345,   346,   347,   348,   518,   519,   355,   532,   533,   349,
      91,   157,   227,   191,   317,   318,   319,    92,   158,    93,
     540,   541,   542,    94,   299,   300,    95,    96,   501,   192,
     622,   623,   778,   301,   648,   788,   213,   102,   584,   162,
     400,   690,   695,   502,   503,   782,   365,   310,   333,   612,
     223,   458,   193,   717,   351,   521,   228,    98,   720,   406,
     789
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -615
static const yytype_int16 yypact[] =
{
    3359,  -615,  -615,  -615,  -615,  -615,  -615,  1032,   -17,  -615,
    -615,  -615,  -615,  -615,  -615,   796,  -615,  -615,   114,  -615,
    -615,  -615,  -615,  -615,  -615,    37,  2462,  -615,  -615,  -615,
    -615,  -615,  3253,  -615,   133,  -615,  -615,   512,  -615,  -615,
    -615,  -615,  -615,   617,   127,     2,  -615,  -615,   143,  -615,
     146,  -615,   112,  -615,   131,  -615,  -615,  -615,   934,  3359,
    -615,  -615,  -615,  -615,  2249,  -615,  -615,  -615,  -615,  -615,
    -615,  -615,  -615,  -615,  -615,  -615,  -615,  -615,  -615,  -615,
    -615,  -615,   -27,   161,   617,  -615,  -615,  -615,  -615,   106,
     875,  -615,  -615,  -615,  -615,  -615,  -615,  -615,   107,  -615,
     945,  -615,   306,   114,   250,   146,   111,   237,  -615,  2052,
    3359,   134,   157,   296,  -615,  -615,  -615,  -615,  -615,  -615,
    -615,  -615,  -615,  -615,  -615,  -615,  -615,  -615,  -615,  -615,
    -615,  -615,  -615,  -615,  -615,  -615,   166,   188,   200,  -615,
     205,  -615,  -615,  -615,  -615,  -615,  -615,  -615,  -615,  -615,
    -615,  -615,  -615,  -615,   306,  4002,   585,  -615,  -615,   206,
    -615,  -615,   296,   432,   579,   762,    55,  1032,   184,   246,
    -615,  -615,     2,  -615,   296,  2700,  -615,    55,     2,  -615,
    -615,  -615,  -615,  -615,  -615,  -615,   -47,  -615,   418,   235,
     901,  -615,  -615,   234,  3677,  3080,  -615,  1702,   250,   240,
     237,   263,     2,  -615,  -615,   271,  -615,   237,   237,  -615,
    3359,  -615,   254,  -615,  3359,   823,  3359,  -615,   279,   282,
    -615,  -615,  -615,  -615,   296,   288,   585,  -615,  -615,  3359,
     237,   280,    55,   296,    17,   396,   296,    55,   285,   945,
    -615,  -615,   396,  -615,  -615,  -615,   363,  3080,  3080,   303,
    2813,   312,  -615,   320,   317,  3169,   340,  -615,  2902,  -615,
     355,  2700,   127,  3080,  3080,  -615,  -615,  -615,   112,  -615,
    -615,  -615,  -615,  -615,  -615,  -615,  -615,   996,   361,  -615,
    3080,  -615,  -615,  -615,    51,   180,   135,    50,    25,   294,
     350,   346,   352,   445,   967,  -615,  -615,  -615,   400,   257,
    -615,  -615,  -615,  -615,   617,  -615,  2902,  2163,  -615,  -615,
    -615,   234,   234,   296,   146,  -615,   127,  -615,   368,   379,
    1436,  -615,  -615,  -615,  3464,   380,    34,  -615,    31,   117,
      49,  -615,  -615,   384,  -615,  -615,  -615,   779,  -615,   364,
     369,  2354,  -615,   334,   370,  -615,  1702,   -11,  -615,   374,
    -615,   371,  -615,   237,  1103,  -615,   240,  3754,  -615,   375,
    -615,  -615,   389,  -615,   387,   392,   405,  -615,   406,   296,
     143,   396,   424,   426,  -615,  -615,   442,  -615,  -615,   447,
    -615,   433,    30,   396,  -615,   434,    55,   435,  -615,   549,
    2991,   320,  -615,  -615,  4002,   462,  -615,  4002,  2902,  -615,
    3541,  4002,  2700,  -615,  4002,  -615,  -615,  2700,  -615,     4,
     469,  -615,  -615,  -615,  -615,  1074,  2902,  2902,  1082,  -615,
    3080,  3080,  3080,  3080,  3080,  3080,  3080,  3080,  3080,  3080,
    3080,  3080,  3080,  3080,  3080,  3080,  3080,  3080,  3080,  -615,
    -615,  -615,  -615,  -615,  -615,  -615,  -615,  -615,  -615,  3080,
    2902,  -615,  2902,   140,   400,  -615,   187,  -615,   227,  -615,
    2700,  -615,   -14,    12,  -615,  1812,  -615,  -615,  -615,   533,
     146,   127,  -615,   901,  2902,   454,  3080,   455,   459,  1935,
     482,   237,   485,   237,  2902,   490,   234,   494,   479,   492,
    -615,  -615,  -615,  -615,  1584,  -615,  -615,  -615,  -615,  -615,
    2249,  -615,   483,   489,   867,   499,   817,   506,    19,  -615,
    3848,  -615,  3080,  -615,  -615,   334,     6,  1294,  -615,  -615,
    -615,  -615,  -615,   617,  -615,  1702,  -615,  -615,   296,   673,
     146,   127,   497,  -615,    83,  -615,   237,   515,    66,  -615,
     283,  -615,  -615,  -615,   237,  3080,  -615,  -615,  -615,   143,
     396,  -615,  -615,  -615,  2700,  -615,  -615,   510,  -615,   521,
    -615,   296,   529,  -615,  3601,   539,  3080,   541,    20,  4002,
     551,   377,   542,   554,   550,    74,   555,  -615,  2902,  3080,
     432,   534,  -615,   552,   560,    85,   432,   633,  -615,  -615,
    -615,    51,    51,    51,   180,   180,   135,   135,    50,    50,
      50,    50,    25,    25,   294,   350,   346,   352,   445,    68,
    -615,   567,  -615,  3677,  3080,  -615,  -615,  2902,  -615,  -615,
     563,   572,  -615,   533,  -615,  -615,   574,  -615,   558,  -615,
    1935,   580,  2587,   561,  2700,   564,   576,  2700,   533,  2700,
    1935,  -615,  -615,  -615,  2902,  2902,   598,   614,  -615,  -615,
    -615,  -615,  -615,  -615,  -615,   581,  -615,  -615,   146,   127,
     296,   854,   127,  -615,  1103,   296,   953,   127,   584,  3754,
     587,  3359,  3754,  -615,  -615,  -615,   307,  -615,  -615,  -615,
    3080,  4002,   551,   605,  -615,   611,  -615,   613,  2902,  -615,
    -615,  2902,  -615,   609,   377,  -615,   618,  -615,   622,  -615,
    -615,  -615,  -615,  -615,   432,  -615,  -615,  -615,  -615,   432,
    -615,  2902,  -615,   624,   619,  -615,  2163,   607,  3942,  -615,
    -615,  -615,  1935,  -615,   632,  -615,  2700,  -615,  -615,   492,
     639,   617,  -615,   641,  -615,   647,  -615,  -615,  -615,  4002,
    -615,  -615,   127,   296,   127,  -615,  -615,   127,   296,   127,
    -615,  4002,   321,  4002,  -615,  -615,  -615,  -615,   654,  -615,
    2902,  2902,   551,   655,   174,  3080,  -615,  2902,  2902,  -615,
    -615,  -615,    19,  -615,  -615,  -615,  -615,   817,   656,  -615,
    2902,  -615,   626,  1935,   638,  1935,  1935,  -615,   651,   661,
    -615,   127,  -615,  -615,   127,  -615,  -615,   721,  -615,   551,
     101,   109,  -615,  -615,  -615,   662,   128,   147,   614,  -615,
    -615,  -615,   234,   164,  2902,   716,  2902,  -615,  -615,  4002,
    -615,  -615,  -615,   237,  -615,  -615,  -615,  -615,  -615,  -615,
    -615,  -615,   652,   677,  1935,  -615,  -615,   659,  -615,  1935,
    -615,   770,  -615,  -615
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -615,  -615,  -144,   765,   501,  -615,  -174,   229,  -615,  -615,
    -615,  -615,    35,  -615,  -615,  -615,   850,   635,  -178,     0,
    -615,  -255,   532,  -615,  -615,  -615,   228,  -615,  -615,  -615,
    -615,  -145,   -40,    13,    23,    84,    36,   359,   360,   358,
     362,   348,  -182,  -167,  -126,  -615,  -194,  -434,  -458,  -615,
     170,  -187,  -615,  -615,  -585,  -615,  -615,  -615,  -615,  -615,
     -30,    18,   172,   -54,   646,  -615,  -615,   215,  -615,   210,
    -615,  -615,  -615,   265,  -615,  -615,  -615,  -615,  -615,  -615,
      -7,  -615,  -615,  -173,  -615,  -615,  -615,  -615,   503,   -39,
    -615,  -153,  -164,   -36,  -615,  -201,    15,  -418,  -615,   198,
    -615,  -189,  -170,   163,  -615,  -443,  -615,  -615,  -615,  -615,
    -615,  -615,   472,   292,  -615,  -615,   460,  -615,   154,  -324,
    -615,  -615,  -615,  -615,   349,  -615,  -615,  -615,  -615,  -163,
     155,   151,  -615,  -615,   274,   376,  -615,  -615,  -615,  -177,
    -566,  -615,  -615,  -615,  -586,  -615,    33,  -383,  -451,  -615,
     439,  -614,   144,  -472,  -615,  -615,  -615,  -615,   230,  -228,
    -615,  -615,  -172,  -615,  -307,  -615,   615,  -615,  -615,  -615,
    -615
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -495
static const yytype_int16 yytable[] =
{
      58,   268,   160,   226,   169,   327,   321,   100,   241,   172,
     185,   309,   636,   330,   303,   107,   311,   312,    61,   340,
     234,   631,   619,   626,   342,   188,   154,   344,   331,   182,
     534,   173,    58,    97,   350,   611,   641,   166,   358,   522,
       1,   156,   628,   168,   173,   196,     3,   509,    13,   296,
      61,   463,   733,   109,   735,   429,   430,   719,     1,    58,
     410,   740,   189,   304,    58,    13,   420,   409,   759,     1,
     457,   370,   734,   226,   427,   428,   305,    61,   651,   211,
     161,   390,   449,   654,   168,   103,   611,   421,   306,   382,
     200,   385,     3,     4,   190,     6,   507,   665,   389,   523,
      40,   391,   392,   393,   207,   396,   646,   577,   307,    58,
      58,   674,   524,   217,   578,   616,   523,    40,   411,   412,
       1,   108,   617,   686,   321,   321,    26,    61,    61,   652,
     617,   176,   405,   431,   432,   419,   172,     4,   205,     6,
     384,   781,   172,   568,   510,   454,   662,   161,   802,     3,
       4,   667,     6,   556,   224,   154,   225,   173,   343,    44,
     174,   110,   230,   232,   235,   237,   172,   239,   340,   450,
     222,   506,   723,   342,   242,   277,   344,   699,   578,   666,
     464,   466,   736,   350,   578,   824,   809,     1,    26,   711,
     316,   707,   201,   565,   154,   578,   567,    58,   353,   378,
     572,   573,   177,   574,   825,   661,   576,   368,   409,   373,
      58,   578,   826,   575,    58,   371,    58,   101,   657,   578,
     175,    44,   830,   585,   376,   549,   225,   551,    61,    58,
     197,   828,    61,   383,    61,   208,   386,   763,   578,   557,
       1,   155,   453,   366,   106,   563,   217,    61,   425,   426,
     829,    45,    46,     1,   112,    26,   609,   578,   214,     3,
       4,   277,     6,   194,   779,   462,   195,   832,   181,   177,
     185,   218,   464,   774,   578,   589,   590,   742,   744,   215,
     804,   216,   747,   749,   578,   505,   268,   185,    44,  -483,
     464,   422,  -483,   219,   330,   178,   423,   424,   225,   638,
     454,   454,   515,   220,   168,     3,     4,   343,     6,   331,
     203,   221,   204,   471,     2,   229,     4,     5,     6,   199,
     277,   650,   433,   434,    58,   815,   610,   817,   818,   613,
     330,   805,   614,   206,   296,   330,   209,   166,   309,   466,
     534,    58,   833,   311,   647,   331,    58,   340,   464,   240,
     331,   506,   342,   506,   531,   344,   190,   154,   320,   811,
     791,   354,   350,   330,   181,   794,   459,   460,   687,   550,
     155,   357,     3,     4,   359,     6,   840,   101,   331,   367,
     268,   842,   591,   592,   593,   374,     3,     4,   375,     6,
     155,   224,   671,   672,   154,   413,   414,   154,   415,   178,
     154,   154,   277,   380,   154,     3,   675,   277,   388,     3,
       4,   394,     6,   390,   224,   571,   756,   460,   694,   315,
     397,   684,   398,   189,   327,   401,   339,   352,   296,   356,
     797,   672,   330,   391,   702,     1,   360,   361,   594,   595,
     729,     3,     4,   729,     6,   729,   185,   331,   404,   203,
     596,   597,   701,   225,   225,   190,   517,   407,  -484,   379,
     277,   462,   435,   416,   436,   169,   417,   196,   418,   602,
     603,   437,   172,   316,   468,   469,   155,   438,   473,   277,
     758,   474,   691,   508,   655,   512,   343,   181,    45,    46,
     511,   715,   513,   520,   277,   525,   526,   764,   543,   544,
      58,    50,   453,    26,   168,  -482,   168,   189,    50,   545,
     154,    45,    46,   598,   599,   600,   601,   546,   737,   738,
     306,     3,     4,   168,     6,    58,   163,    50,   659,   217,
     547,   548,   729,    50,   217,   757,    44,     1,   787,   190,
     307,   694,  -484,     3,     4,   170,     6,   552,   704,   488,
     796,   553,   798,   202,   277,   554,   555,   558,   560,   179,
      50,   679,   464,   561,   154,    50,   800,   801,   566,   154,
     339,   225,   579,   806,   807,   339,   621,   627,   629,   571,
     630,   164,   527,   330,   632,   771,   813,   634,     3,     4,
     466,     6,   637,   233,     3,     4,   639,     6,   331,   224,
     640,   179,   578,   179,   165,    26,   642,   664,   808,   155,
      50,    50,   155,   154,   643,   155,   155,   155,   836,   155,
       1,   644,   155,   669,   506,   831,     3,     4,   645,     6,
     277,   167,   277,   677,   277,   680,     1,   277,    44,   277,
     277,   754,     3,     4,   678,     6,    64,   709,   683,   731,
     685,   696,   731,   688,   731,   179,    50,   697,   700,   698,
     217,   217,   617,   706,   531,   217,   217,   843,    50,   154,
     712,    58,   154,   716,   718,   155,    50,   721,    64,   722,
     724,   154,     3,     4,   728,     6,   215,   660,    26,    61,
     835,   314,   784,   180,   225,    50,    45,    46,    50,   732,
     739,   646,   315,   517,    26,    64,   751,   760,   488,   753,
     633,    50,   635,   761,   765,    50,   762,    50,   154,    43,
     767,    44,   277,   488,   768,   773,   277,   772,    45,    46,
      50,   168,   775,   777,   780,   180,   172,    44,   810,   154,
     179,   731,   783,   217,   785,   334,   335,   336,   217,   814,
     786,   154,   339,   154,   339,    64,    64,   799,   803,   812,
     816,   819,    50,   170,   820,   668,   823,   670,   827,   155,
     834,     3,     4,   361,     6,   838,   236,   168,   179,   155,
     839,   841,     6,   277,   155,   277,   277,   403,     3,     4,
     111,     6,   682,   163,   604,   606,   605,   608,   231,     1,
     607,   238,   725,   180,   727,     3,     4,   461,     6,   673,
     104,   713,   302,   516,   470,   656,   535,   472,   746,   154,
       1,    50,   625,   755,   752,    50,     3,     4,   676,     6,
     564,   167,     3,     4,   277,     6,   615,   369,   766,   277,
     324,   377,    50,   341,   714,     0,     0,    50,     0,   155,
      55,     0,   155,     0,   155,   530,    64,    99,    50,   488,
      64,     0,    64,     3,     4,     0,     6,   381,   743,   488,
       1,   165,   387,     0,   180,    64,     3,     4,     1,     6,
       0,   167,    55,     0,     3,     4,     0,     6,    26,   198,
       0,     0,     0,    55,     0,    50,   155,     0,    50,     0,
       0,    50,    50,    50,     1,    50,     0,     0,    50,    55,
       3,     4,   180,     6,    55,   313,     0,     0,     0,   504,
       0,    44,  -482,     0,     0,     0,     0,     0,    45,    46,
       0,     0,     0,   155,    55,     0,     0,     1,    26,     0,
       0,   155,     2,     0,     4,     5,     6,     0,     1,     0,
       0,   488,     0,     2,   155,     4,     5,     6,     0,    55,
      55,    50,     3,     4,   180,     6,   155,   748,   155,   504,
       0,    44,   624,     0,   314,     0,     0,     0,    45,    46,
      50,     0,     0,   439,   440,   441,   442,   443,   444,   445,
     446,     0,   341,   447,   448,    50,     0,     0,     0,     1,
     449,    50,     0,   324,     2,    26,     4,     5,     6,     0,
       0,    50,   488,     0,   488,   488,    26,    99,     0,   177,
       0,   559,     0,     0,     0,     0,    50,     0,     0,   658,
     177,     0,   663,     0,   155,     1,     0,     0,    44,     0,
       2,     3,     4,     5,     6,   178,     0,    55,     0,    44,
       0,     0,   837,     0,     0,    50,   202,     0,     0,     0,
      55,     0,     0,   488,    55,    50,    55,    26,   488,     0,
      50,     0,     0,     0,     0,     0,     0,     1,     0,    55,
       0,   177,     0,     3,     4,     1,     6,   450,   580,   451,
       0,     3,     4,     0,     6,     0,   586,     0,     0,     0,
      44,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     4,    50,     6,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,    50,     0,    50,    44,     0,    50,     0,
      50,    50,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,    26,    55,     0,   324,     0,     0,   581,
     741,     0,     0,   745,     0,   530,     0,   587,   750,     0,
      50,   341,    50,    50,    55,   334,   335,   336,    44,     0,
       0,     0,    50,     0,     0,     0,    44,     0,     0,     0,
       0,    55,     0,     0,     0,     0,    55,     0,     0,   529,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,    50,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,   790,     0,   792,     0,     0,   793,     0,
     795,     0,    50,     0,    50,     0,     0,     0,     0,   324,
       0,     0,     0,     0,     0,   582,     0,     0,   588,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,    50,    50,     0,     0,
       0,     0,   821,     0,     0,   822,     0,     1,   243,   244,
     245,   108,     0,     3,     4,     0,     6,     0,   328,     0,
       0,     0,     0,     0,     0,   324,     0,    64,   324,     0,
      50,     0,     0,     0,     0,     0,     0,     0,   247,   248,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
      50,   249,     0,     0,   250,     0,     0,   251,     0,     0,
      55,     0,     0,   252,    55,     0,    55,     0,     0,     0,
       0,     0,     0,     0,   253,    26,     0,     0,     0,     0,
     254,     0,     0,    55,   255,    55,   256,     0,     0,     0,
     257,     0,   259,     0,     0,   260,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,     0,   262,     0,
       0,     0,     0,     0,     0,   263,   264,   265,   266,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     653,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     703,   705,     0,     0,     0,     0,   708,   710,     0,     1,
     243,   244,   245,   108,     2,     3,     4,     5,     6,     0,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   248,     0,     0,     8,     9,    10,   475,   476,     0,
      11,    12,    13,   249,   477,   478,   250,   479,    14,   251,
       0,    15,    16,     0,   183,   252,    19,   480,    20,   481,
     482,    21,    22,    23,    24,   483,   253,    26,     0,     0,
       0,    27,   254,   484,    28,    29,   255,    30,   256,    31,
     485,    55,   257,   258,   259,   486,    33,   260,    34,    35,
      36,    37,    38,    39,    40,    41,   487,    42,   261,     0,
     262,     0,     0,     0,     0,     0,     0,   263,   264,   265,
     266,   267,     0,     0,   769,     0,     0,     0,     0,   770,
     320,  -468,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     1,   243,   244,
     245,   108,     2,     3,     4,     5,     6,     0,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,   248,
       0,     0,     8,     9,    10,   475,   476,    55,    11,    12,
      13,   249,   477,   478,   250,   479,    14,   251,     0,    15,
      16,     0,   183,   252,    19,   480,    20,   481,   482,    21,
      22,    23,    24,   483,   253,    26,     0,     0,     0,    27,
     254,   484,    28,    29,   255,    30,   256,    31,   485,     0,
     257,   258,   259,   486,    33,   260,    34,    35,    36,    37,
      38,    39,    40,    41,   487,    42,   261,     0,   262,     0,
       0,     0,     0,     0,     0,   263,   264,   265,   266,   267,
       0,     0,     0,     0,     0,     1,     0,     0,   320,  -469,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    10,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,    15,    16,    17,
     183,     0,    19,     0,    20,     0,     0,    21,    22,    23,
      24,     0,     0,    26,   334,   335,   336,    27,     0,     0,
      28,    29,     0,    30,     0,    31,     0,  -494,     0,     0,
       0,     0,    33,     0,    34,    35,    36,   337,    38,    39,
      40,    41,     0,    42,    43,     0,    44,     0,     0,     0,
       0,     0,     0,    45,    46,     1,   243,   244,   245,   108,
       0,     3,     4,     0,     6,   338,   328,  -488,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   247,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   249,
       0,     0,   250,     0,     0,   251,     0,     0,     0,     0,
       0,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,    26,     0,     0,     0,     0,   254,     0,
       0,     0,   255,     0,   256,     0,     0,     0,   257,   258,
     259,     0,     0,   260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,     0,   262,     0,     0,     0,
       0,     0,     0,   263,   264,   265,   266,   267,     0,     0,
       0,     0,     0,     0,     0,     0,   465,   618,     1,   243,
     244,   245,   108,     2,     3,     4,     5,     6,     0,   246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   247,
     248,     0,     0,     8,     9,    10,   475,   476,     0,    11,
      12,    13,   249,   477,   478,   250,   479,    14,   251,     0,
      15,    16,     0,   183,   252,    19,   480,    20,   481,   482,
      21,    22,    23,    24,   483,   253,    26,     0,     0,     0,
      27,   254,   484,    28,    29,   255,    30,   256,    31,   485,
       0,   257,   258,   259,   486,    33,   260,    34,    35,    36,
      37,    38,    39,    40,    41,   487,    42,   261,     0,   262,
       0,     0,     0,     0,     0,     0,   263,   264,   265,   266,
     267,     0,     0,     0,     0,     1,     0,     0,     0,   320,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,    10,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,    15,    16,    17,
      18,     0,    19,     0,    20,     0,     0,    21,    22,    23,
      24,    25,     0,    26,     0,     0,     0,    27,     0,     0,
      28,    29,     0,    30,     0,    31,     0,    32,     0,     0,
       0,     0,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,     0,    42,    43,     0,    44,     0,     0,     0,
       0,     0,     0,    45,    46,     0,     1,   243,   244,   245,
     108,     0,     3,     4,     0,     6,   210,   328,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,   248,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,   250,     0,     0,   251,     0,     0,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   253,    26,     0,     0,     0,     0,   254,
       0,     0,     0,   255,     0,   256,     0,     0,     0,   257,
     258,   259,     1,     0,   260,     0,     0,     2,     3,     4,
       5,     6,     0,     7,     0,   261,     0,   262,     0,     0,
       0,     0,     0,     0,   263,   264,   265,   266,   267,     0,
       0,     0,     0,     0,     0,     0,     0,   465,     9,    10,
       0,     0,     0,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,    15,    16,     0,   183,     0,    19,
       0,    20,     0,     0,    21,    22,    23,    24,     0,     0,
      26,     0,     0,     0,    27,     0,     0,    28,    29,     0,
      30,     0,    31,     0,     0,     0,     0,     0,     0,    33,
       0,    34,    35,    36,     0,    38,    39,    40,    41,     0,
      42,    43,     0,    44,     0,     0,     0,     1,     0,     0,
      45,    46,     2,     3,     4,     5,     6,     0,     7,     0,
       0,     0,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    10,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,     0,   183,     0,    19,     0,    20,     0,     0,    21,
      22,    23,    24,     0,     0,    26,     0,     0,     0,    27,
       0,     0,    28,    29,     0,    30,     0,    31,     0,     0,
       0,     0,     0,     0,    33,     0,    34,    35,    36,     0,
      38,    39,    40,    41,     0,    42,    43,     0,    44,     0,
       0,     0,     0,     0,     0,    45,    46,     0,     0,     0,
       2,     3,     4,     5,     6,     0,   113,   514,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,    10,     0,     0,     0,    11,    12,    13,     0,
       0,     0,   136,     0,    14,     0,     0,    15,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,    22,    23,
       0,     0,   137,     0,     0,     0,     0,     0,     0,     0,
      28,    29,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    35,    36,     0,     0,    39,
      40,    41,     0,    42,   138,     0,   139,   140,     0,     0,
     141,   142,   143,   144,   145,   146,     0,   147,   148,   149,
     150,   151,     0,     0,   152,     0,     0,     0,     0,   153,
       1,   243,   244,   245,   108,     2,     3,     4,     5,     6,
       0,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   247,   248,     0,     0,     0,     9,    10,     0,     0,
       0,    11,    12,    13,   249,     0,     0,   250,     0,    14,
     251,     0,    15,    16,     0,   183,   252,    19,     0,    20,
       0,     0,    21,    22,    23,    24,     0,   253,    26,     0,
       0,     0,    27,   254,     0,    28,    29,   255,    30,   256,
      31,     0,     0,   257,   258,   259,     0,    33,   260,    34,
      35,    36,     0,    38,    39,    40,    41,     0,    42,   261,
       0,   262,     0,     0,     0,     0,     0,     0,   263,   264,
     265,   266,   267,     1,   243,   244,   245,   108,     2,     3,
       4,     5,     6,     0,   246,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,   248,     0,     0,     0,     0,
      10,     0,     0,     0,    11,    12,    13,   249,     0,     0,
     250,     0,    14,   251,     0,    15,     0,     0,     0,   252,
      19,     0,     0,     0,     0,     0,    22,    23,     0,     0,
     253,    26,     0,     0,     0,     0,   254,     0,    28,    29,
     255,     0,   256,    31,     0,     0,   257,   258,   259,     0,
       0,   260,    34,    35,    36,     0,     0,    39,    40,    41,
       0,    42,   261,     0,   262,     0,     0,     0,     0,     0,
       0,   263,   264,   265,   266,   267,     1,   243,   244,   245,
     108,     0,     3,     4,     0,     6,     0,   328,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,   248,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,   250,     0,     0,   251,     0,     0,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   253,    26,     0,     0,     0,     0,   254,
       0,     0,     0,   255,     0,   256,     0,     0,     0,   257,
       0,   259,     0,     0,   260,     1,   243,   244,   245,   108,
       0,     3,     4,     0,     6,   261,   328,   262,   395,     0,
       0,     0,     0,     0,   263,   264,   265,   266,   267,     0,
       0,     0,     0,     0,     0,     0,   247,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   249,
       0,     0,   250,     0,     0,   251,     0,     0,     0,     0,
       0,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,    26,     0,     0,     0,     0,   254,     0,
       0,     0,   255,     0,   256,     0,     0,     0,   257,   258,
     259,     0,     0,   260,     1,   243,   244,   245,   108,     0,
       3,     4,     0,     6,   261,   328,   262,     0,     0,     0,
       0,     0,     0,   263,   264,   265,   266,   267,     0,     0,
       0,     0,     0,     0,     0,   247,   248,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   249,     0,
       0,   250,     0,     0,   251,     0,     0,     0,     0,     0,
     252,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   253,    26,     0,     0,     0,     0,   254,     0,     0,
       0,   255,     0,   256,     0,     0,     0,   257,     0,   259,
       0,     0,   260,     1,   243,   244,   245,   108,     0,     3,
       4,     0,     6,   261,   328,   262,   562,     0,     0,     0,
       0,     0,   263,   264,   265,   266,   267,     0,     0,     0,
       0,     0,     0,     0,   247,   248,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,     0,     0,
     250,     0,     0,   251,     0,     0,     0,     0,     0,   252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,    26,     0,     0,     0,     0,   254,     0,     0,     0,
     255,     0,   256,     0,     0,     0,   257,     0,   259,     0,
       0,   260,     1,   243,   244,   245,   108,     0,     3,     4,
       0,     6,   261,   328,   262,     0,     0,     0,     0,     0,
       0,   263,   264,   265,   266,   267,     0,     0,     0,     0,
       0,     0,     0,   247,   248,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   249,     0,     0,   250,
       0,     0,   251,     0,     0,     0,     0,     0,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   253,
      26,     0,     0,     0,     0,   254,     0,     0,     0,   255,
       0,   256,     0,     0,     0,   257,     1,   259,     0,     0,
     260,     2,     3,     4,     5,     6,     0,     7,     0,     0,
       0,   402,     0,   262,     0,     0,     0,     0,     0,     0,
     263,   264,   265,   266,   267,     0,     0,     0,     0,     0,
       0,     8,     9,    10,     0,     0,     0,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,    15,    16,
      17,    18,     0,    19,     0,    20,     0,     0,    21,    22,
      23,    24,    25,     0,    26,     0,     0,     0,    27,     0,
       0,    28,    29,     0,    30,     0,    31,     0,    32,     0,
       0,     0,     0,    33,     0,    34,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,     0,    44,     0,     0,
       0,   159,     1,     0,    45,    46,     0,     2,     3,     4,
       5,     6,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     9,    10,
       0,     0,     0,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,    15,    16,    17,    18,     0,    19,
       0,    20,     0,     0,    21,    22,    23,    24,    25,     0,
      26,     0,     0,     0,    27,     0,     0,    28,    29,     0,
      30,     0,    31,     0,    32,     0,     0,     0,     0,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,     0,    44,     0,     0,     0,     1,     0,     0,
      45,    46,     2,     3,     4,     5,     6,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    10,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,     0,   183,     0,    19,     0,    20,     0,     0,    21,
      22,    23,    24,     0,     0,    26,     0,     0,     0,    27,
       0,     0,    28,    29,     0,    30,     0,    31,     0,     2,
       3,     4,     5,     6,    33,   113,    34,    35,    36,     0,
      38,    39,    40,    41,     0,    42,   504,     0,    44,  -482,
       0,     0,     0,     0,     0,    45,    46,     0,     0,     0,
       0,    10,     0,     0,     0,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,    15,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,    22,    23,     2,
       3,     4,     5,     6,     0,   113,     0,     0,     0,    28,
      29,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    36,     0,     0,    39,    40,
      41,    10,    42,   569,     0,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,    15,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,     0,     0,     0,    31,     2,     3,     4,     5,     6,
     323,   113,     0,    34,    35,    36,     0,     0,    39,    40,
      41,     0,    42,   681,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    10,     0,     0,
       0,    11,    12,    13,     0,     0,     0,     0,     0,    14,
       0,     0,    15,    16,     0,   183,     0,    19,     0,    20,
       0,     0,    21,    22,    23,    24,     0,     0,     0,     0,
       0,     0,    27,     0,     0,    28,    29,     0,    30,     0,
      31,     0,     2,     3,     4,     5,     6,    33,   113,    34,
      35,    36,     0,    38,    39,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    10,     0,     0,     0,    11,   536,
      13,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,     0,   183,     0,    19,     0,    20,     0,     0,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,    29,     0,    30,     0,    31,     0,   537,
       0,     0,     0,     0,    33,     0,   538,    35,    36,     0,
      38,    39,    40,    41,     0,    42,     2,     3,     4,     5,
       6,   649,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,    10,     0,
       0,     0,    11,    12,    13,     0,     0,     0,     0,     0,
      14,     0,     0,    15,    16,     0,   183,     0,    19,     0,
      20,     0,     0,    21,    22,    23,    24,     0,     0,     0,
       0,     0,     0,    27,     0,     0,    28,    29,     0,    30,
       0,    31,     0,     0,     0,     0,     0,     0,    33,     0,
      34,    35,    36,     0,    38,    39,    40,    41,     0,    42,
       2,     3,     4,     5,     6,   776,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,    15,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,    22,    23,
       2,     3,     4,     5,     6,     0,   113,     0,     0,     0,
      28,    29,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    35,    36,     0,     0,    39,
      40,    41,    10,    42,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,    15,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    29,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    35,    36,     0,     0,    39,
      40,    41,     0,    42
};

static const yytype_int16 yycheck[] =
{
       0,   175,    32,   156,    43,   194,   193,     7,   172,    45,
      64,   188,   484,   195,   178,    15,   188,   189,     0,   197,
     164,   479,   465,   474,   197,    64,    26,   197,   195,    59,
     354,    14,    32,     0,   197,   453,   494,    37,   202,   346,
       3,    26,   476,    43,    14,    84,     9,    13,    46,   175,
      32,   306,   637,    18,   639,    30,    31,   623,     3,    59,
     261,   647,    89,   110,    64,    46,    15,   261,   682,     3,
     298,   215,   638,   226,    24,    25,   123,    59,   512,   109,
      14,    50,    33,   517,    84,   102,   504,    36,   102,   233,
      90,   235,     9,    10,   121,    12,   324,    14,   242,   110,
      98,    70,   247,   248,   104,   250,    87,   103,   122,   109,
     110,   545,   123,   113,   110,   103,   110,    98,   263,   264,
       3,     7,   110,   103,   311,   312,    71,   109,   110,   123,
     110,     0,   258,   108,   109,   280,   172,    10,   103,    12,
     123,   726,   178,   398,   110,   298,   529,    14,   762,     9,
      10,   534,    12,   123,    14,   155,   156,    14,   197,   104,
      14,   124,   162,   163,   164,   165,   202,   167,   346,   120,
     155,   324,   630,   346,   174,   175,   346,   103,   110,    96,
     306,   307,   640,   346,   110,   799,   772,     3,    71,   121,
     190,   106,    85,   394,   194,   110,   397,   197,   198,   229,
     401,   402,    85,   404,   103,   529,   407,   214,   402,   216,
     210,   110,   103,   407,   214,   215,   216,     7,   525,   110,
     108,   104,   808,   417,   224,   369,   226,   371,   210,   229,
     124,   103,   214,   233,   216,   124,   236,   688,   110,   383,
       3,    26,   102,   210,    15,   390,   246,   229,   113,   114,
     103,   111,   112,     3,    25,    71,   450,   110,   124,     9,
      10,   261,    12,   102,   722,   304,   105,   103,    58,    85,
     324,   105,   398,   716,   110,   420,   421,   660,   661,   122,
     106,   124,   665,   666,   110,   324,   460,   341,   104,   102,
     416,   111,   105,   105,   476,   111,   116,   117,   298,   486,
     453,   454,   341,   103,   304,     9,    10,   346,    12,   476,
     100,   106,   102,   313,     8,   109,    10,    11,    12,    90,
     320,   510,    28,    29,   324,   783,   452,   785,   786,   102,
     512,   765,   105,   104,   460,   517,   107,   337,   515,   465,
     664,   341,   814,   515,   508,   512,   346,   525,   474,   103,
     517,   504,   525,   506,   354,   525,   121,   357,   124,   777,
     743,   121,   525,   545,   154,   748,   109,   110,   569,   369,
     155,   108,     9,    10,   103,    12,   834,   167,   545,   125,
     554,   839,   422,   423,   424,   106,     9,    10,   106,    12,
     175,    14,   109,   110,   394,    34,    35,   397,    37,   111,
     400,   401,   402,   123,   404,     9,   550,   407,   123,     9,
      10,   108,    12,    50,    14,   400,   109,   110,   571,   190,
     108,   566,   102,    89,   613,   108,   197,   198,   554,   200,
     109,   110,   614,    70,   579,     3,   207,   208,   425,   426,
     634,     9,    10,   637,    12,   639,   500,   614,   108,   239,
     427,   428,   578,   453,   454,   121,   122,   102,   124,   230,
     460,   500,   112,   102,   118,   504,   105,   506,   107,   433,
     434,   119,   508,   473,   311,   312,   261,    32,   110,   479,
     681,   102,   105,   103,   523,   121,   525,   277,   111,   112,
     106,   617,   123,   123,   494,   121,   125,   691,   123,   110,
     500,     0,   102,    71,   504,   105,   506,    89,     7,   122,
     510,   111,   112,   429,   430,   431,   432,   125,   644,   645,
     102,     9,    10,   523,    12,   525,    14,    26,   528,   529,
     125,   125,   726,    32,   534,   680,   104,     3,   739,   121,
     122,   694,   124,     9,    10,    44,    12,   123,    14,   320,
     751,   125,   753,   111,   554,   108,   123,   123,   123,    58,
      59,   561,   688,    14,   564,    64,   760,   761,   106,   569,
     341,   571,   103,   767,   768,   346,    43,   123,   123,   564,
     121,    69,   353,   765,   102,   711,   780,   102,     9,    10,
     716,    12,   102,    14,     9,    10,   102,    12,   765,    14,
     121,   100,   110,   102,    92,    71,   123,   110,   772,   394,
     109,   110,   397,   613,   125,   400,   401,   402,   819,   404,
       3,   122,   407,   108,   777,   812,     9,    10,   122,    12,
     630,    14,   632,   123,   634,   106,     3,   637,   104,   639,
     640,   671,     9,    10,   123,    12,     0,    14,   109,   634,
     109,   109,   637,   102,   639,   154,   155,   103,   103,   109,
     660,   661,   110,   103,   664,   665,   666,   841,   167,   669,
     103,   671,   672,   110,   102,   460,   175,   103,    32,   121,
     100,   681,     9,    10,   123,    12,   122,    14,    71,   671,
     816,   190,   731,    58,   694,   194,   111,   112,   197,   123,
     102,    87,   473,   122,    71,    59,   122,   102,   479,   122,
     481,   210,   483,   102,   105,   214,   103,   216,   718,   102,
     102,   104,   722,   494,   102,   106,   726,   103,   111,   112,
     229,   731,   125,   718,   102,   100,   772,   104,   777,   739,
     239,   726,   103,   743,   103,    72,    73,    74,   748,   123,
     103,   751,   523,   753,   525,   109,   110,   103,   103,   103,
     122,   110,   261,   262,   103,   536,    45,   538,   106,   554,
      54,     9,    10,   544,    12,   123,    14,   777,   277,   564,
     103,   122,    12,   783,   569,   785,   786,   255,     9,    10,
      25,    12,   564,    14,   435,   437,   436,   449,   163,     3,
     438,   166,   632,   168,   632,     9,    10,   304,    12,   544,
      14,   613,   177,   341,   313,   523,   356,   316,   664,   819,
       3,   320,   473,   672,   669,   324,     9,    10,   554,    12,
     391,    14,     9,    10,   834,    12,   460,    14,   694,   839,
     194,   226,   341,   197,   614,    -1,    -1,   346,    -1,   634,
       0,    -1,   637,    -1,   639,   354,   210,     7,   357,   630,
     214,    -1,   216,     9,    10,    -1,    12,   232,    14,   640,
       3,    92,   237,    -1,   239,   229,     9,    10,     3,    12,
      -1,    14,    32,    -1,     9,    10,    -1,    12,    71,    14,
      -1,    -1,    -1,    43,    -1,   394,   681,    -1,   397,    -1,
      -1,   400,   401,   402,     3,   404,    -1,    -1,   407,    59,
       9,    10,   277,    12,    64,    14,    -1,    -1,    -1,   102,
      -1,   104,   105,    -1,    -1,    -1,    -1,    -1,   111,   112,
      -1,    -1,    -1,   718,    84,    -1,    -1,     3,    71,    -1,
      -1,   726,     8,    -1,    10,    11,    12,    -1,     3,    -1,
      -1,   722,    -1,     8,   739,    10,    11,    12,    -1,   109,
     110,   460,     9,    10,   329,    12,   751,    14,   753,   102,
      -1,   104,   471,    -1,   473,    -1,    -1,    -1,   111,   112,
     479,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,   346,    26,    27,   494,    -1,    -1,    -1,     3,
      33,   500,    -1,   357,     8,    71,    10,    11,    12,    -1,
      -1,   510,   783,    -1,   785,   786,    71,   167,    -1,    85,
      -1,   386,    -1,    -1,    -1,    -1,   525,    -1,    -1,   528,
      85,    -1,   531,    -1,   819,     3,    -1,    -1,   104,    -1,
       8,     9,    10,    11,    12,   111,    -1,   197,    -1,   104,
      -1,    -1,   823,    -1,    -1,   554,   111,    -1,    -1,    -1,
     210,    -1,    -1,   834,   214,   564,   216,    71,   839,    -1,
     569,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,   229,
      -1,    85,    -1,     9,    10,     3,    12,   120,    14,   122,
      -1,     9,    10,    -1,    12,    -1,    14,    -1,    -1,    -1,
     104,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,   613,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   630,    -1,   632,    -1,   634,   104,    -1,   637,    -1,
     639,   640,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,   304,    -1,   510,    -1,    -1,    85,
     659,    -1,    -1,   662,    -1,   664,    -1,    85,   667,    -1,
     669,   525,   671,   672,   324,    72,    73,    74,   104,    -1,
      -1,    -1,   681,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,   341,    -1,    -1,    -1,    -1,   346,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   718,
      -1,    -1,    -1,   722,    -1,    -1,    -1,   726,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     739,    -1,    -1,   742,    -1,   744,    -1,    -1,   747,    -1,
     749,    -1,   751,    -1,   753,    -1,    -1,    -1,    -1,   613,
      -1,    -1,    -1,    -1,    -1,   415,    -1,    -1,   418,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   783,    -1,   785,   786,    -1,    -1,
      -1,    -1,   791,    -1,    -1,   794,    -1,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,   669,    -1,   671,   672,    -1,
     819,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,   834,    -1,    -1,    -1,    -1,
     839,    47,    -1,    -1,    50,    -1,    -1,    53,    -1,    -1,
     500,    -1,    -1,    59,   504,    -1,   506,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    -1,
      76,    -1,    -1,   523,    80,   525,    82,    -1,    -1,    -1,
      86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,   581,    -1,    -1,    -1,    -1,   586,   587,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    38,    39,    40,    41,    42,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,   671,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,    -1,    -1,   704,    -1,    -1,    -1,    -1,   709,
     124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   731,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    40,    41,    42,   777,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,   124,   125,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,    57,
      58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      78,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    -1,
      -1,    -1,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,   101,   102,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    12,   123,    14,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    86,    87,
      88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    38,    39,    40,    41,    42,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,   124,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,    57,
      58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,
      68,    69,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    -1,
      -1,    -1,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,   101,   102,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,    -1,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    12,   124,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    50,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    86,
      87,    88,     3,    -1,    91,    -1,    -1,     8,     9,    10,
      11,    12,    -1,    14,    -1,   102,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    39,    40,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    56,    -1,    58,    -1,    60,
      -1,    62,    -1,    -1,    65,    66,    67,    68,    -1,    -1,
      71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,    -1,
      81,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
     101,   102,    -1,   104,    -1,    -1,    -1,     3,    -1,    -1,
     111,   112,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    -1,    58,    -1,    60,    -1,    62,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    -1,    81,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,   101,   102,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,
       8,     9,    10,    11,    12,    -1,    14,   123,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    50,    -1,    52,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    -1,    -1,    97,
      98,    99,    -1,   101,   102,    -1,   104,   105,    -1,    -1,
     108,   109,   110,   111,   112,   113,    -1,   115,   116,   117,
     118,   119,    -1,    -1,   122,    -1,    -1,    -1,    -1,   127,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    39,    40,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    58,    59,    60,    -1,    62,
      -1,    -1,    65,    66,    67,    68,    -1,    70,    71,    -1,
      -1,    -1,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    -1,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,   101,   102,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    -1,    52,    53,    -1,    55,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      70,    71,    -1,    -1,    -1,    -1,    76,    -1,    78,    79,
      80,    -1,    82,    83,    -1,    -1,    86,    87,    88,    -1,
      -1,    91,    92,    93,    94,    -1,    -1,    97,    98,    99,
      -1,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    50,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    86,
      -1,    88,    -1,    -1,    91,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    12,   102,    14,   104,   105,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    86,    87,
      88,    -1,    -1,    91,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    12,   102,    14,   104,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    86,    -1,    88,
      -1,    -1,    91,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,   102,    14,   104,   105,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    86,    -1,    88,    -1,
      -1,    91,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    12,   102,    14,   104,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,
      -1,    82,    -1,    -1,    -1,    86,     3,    88,    -1,    -1,
      91,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,
      57,    58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,
      67,    68,    69,    -1,    71,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    -1,    81,    -1,    83,    -1,    85,    -1,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,   101,   102,    -1,   104,    -1,    -1,
      -1,   108,     3,    -1,   111,   112,    -1,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,    60,
      -1,    62,    -1,    -1,    65,    66,    67,    68,    69,    -1,
      71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,    -1,
      81,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
     101,   102,    -1,   104,    -1,    -1,    -1,     3,    -1,    -1,
     111,   112,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    -1,    58,    -1,    60,    -1,    62,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    -1,    81,    -1,    83,    -1,     8,
       9,    10,    11,    12,    90,    14,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,   101,   102,    -1,   104,   105,
      -1,    -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,    78,
      79,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    -1,    -1,    97,    98,
      99,    40,   101,   102,    -1,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    -1,    -1,    -1,    83,     8,     9,    10,    11,    12,
      13,    14,    -1,    92,    93,    94,    -1,    -1,    97,    98,
      99,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,
      -1,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    56,    -1,    58,    -1,    60,    -1,    62,
      -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    79,    -1,    81,    -1,
      83,    -1,     8,     9,    10,    11,    12,    90,    14,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    -1,    58,    -1,    60,    -1,    62,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,   101,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,
      -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    55,    56,    -1,    58,    -1,    60,    -1,
      62,    -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    78,    79,    -1,    81,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,   101,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      78,    79,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    -1,    -1,    97,
      98,    99,    40,   101,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    -1,    -1,    97,
      98,    99,    -1,   101
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
     237,   248,   255,   257,   261,   264,   265,   274,   295,   144,
     147,   197,   275,   102,    14,   132,   135,   147,     7,   140,
     124,   131,   135,    14,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    50,    70,   102,   104,
     105,   108,   109,   110,   111,   112,   113,   115,   116,   117,
     118,   119,   122,   127,   147,   195,   224,   249,   256,   108,
     188,    14,   277,    14,    69,    92,   147,    14,   147,   217,
     132,   220,   221,    14,    14,   108,     0,    85,   111,   132,
     145,   197,   188,    58,   123,   191,   215,   216,   217,    89,
     121,   251,   267,   290,   102,   105,   217,   124,    14,   135,
     147,    85,   111,   197,   197,   140,   135,   147,   124,   135,
     124,   188,   208,   274,   124,   122,   124,   147,   105,   105,
     103,   106,   224,   288,    14,   147,   219,   250,   294,   109,
     147,   145,   147,    14,   130,   147,    14,   147,   145,   147,
     103,   220,   147,     4,     5,     6,    14,    34,    35,    47,
      50,    53,    59,    70,    76,    80,    82,    86,    87,    88,
      91,   102,   104,   111,   112,   113,   114,   115,   134,   136,
     137,   138,   139,   140,   141,   143,   144,   147,   148,   150,
     151,   152,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   223,   224,   262,
     263,   271,   145,   220,   110,   123,   102,   122,   232,   267,
     285,   290,   290,    14,   132,   135,   147,   252,   253,   254,
     124,   179,   231,    13,   192,   227,   228,   229,    14,   147,
     170,   171,   175,   286,    72,    73,    74,    95,   123,   135,
     146,   192,   211,   217,   230,   238,   239,   240,   241,   247,
     257,   292,   135,   147,   121,   244,   135,   108,   220,   103,
     135,   135,   200,   201,   202,   284,   274,   125,   208,    14,
     130,   147,   210,   208,   106,   106,   147,   294,   188,   135,
     123,   145,   130,   147,   123,   130,   147,   145,   123,   130,
      50,    70,   159,   159,   108,   105,   159,   108,   102,   153,
     278,   108,   102,   150,   108,   172,   297,   102,   172,   174,
     223,   159,   159,    34,    35,    37,   102,   105,   107,   159,
      15,    36,   111,   116,   117,   113,   114,    24,    25,    30,
      31,   108,   109,    28,    29,   112,   118,   119,    32,    16,
      17,    18,    19,    20,    21,    22,    23,    26,    27,    33,
     120,   122,   173,   102,   219,   225,   226,   287,   289,   109,
     110,   216,   217,   149,   172,   124,   172,   233,   231,   231,
     132,   147,   132,   110,   102,    41,    42,    48,    49,    51,
      61,    63,    64,    69,    77,    84,    89,   100,   135,   174,
     176,   177,   178,   179,   180,   181,   183,   185,   186,   189,
     192,   266,   281,   282,   102,   217,   219,   287,   103,    13,
     110,   106,   121,   123,   123,   217,   240,   122,   242,   243,
     123,   293,   292,   110,   123,   121,   125,   135,    14,    96,
     132,   147,   245,   246,   247,   244,    45,    85,    92,   229,
     258,   259,   260,   123,   110,   122,   125,   125,   125,   130,
     147,   130,   123,   125,   108,   123,   123,   130,   123,   145,
     123,    14,   105,   159,   278,   223,   106,   223,   149,   102,
     154,   224,   223,   223,   223,   174,   223,   103,   110,   103,
      14,    85,   144,   149,   276,   174,    14,    85,   144,   159,
     159,   160,   160,   160,   161,   161,   162,   162,   163,   163,
     163,   163,   164,   164,   165,   166,   167,   168,   169,   174,
     172,   225,   287,   102,   105,   263,   103,   110,   125,   233,
     234,    43,   268,   269,   132,   252,   276,   123,   175,   123,
     121,   176,   102,   135,   102,   135,   281,   102,   179,   102,
     121,   176,   123,   125,   122,   122,    87,   220,   272,    13,
     229,   175,   123,   126,   175,   217,   241,   292,   132,   147,
      14,   247,   275,   132,   110,    14,    96,   275,   135,   108,
     135,   109,   110,   201,   175,   130,   262,   123,   123,   147,
     106,   102,   154,   109,   159,   109,   103,   223,   102,   157,
     279,   105,   155,   156,   219,   280,   109,   103,   109,   103,
     103,   172,   159,   144,    14,   144,   103,   106,   144,    14,
     144,   121,   103,   227,   286,   172,   110,   291,   102,   268,
     296,   103,   121,   176,   100,   178,   184,   190,   123,   174,
     182,   224,   123,   182,   268,   182,   176,   172,   172,   102,
     272,   132,   275,    14,   275,   132,   246,   275,    14,   275,
     132,   122,   258,   122,   188,   259,   109,   159,   223,   279,
     102,   102,   103,   276,   174,   105,   280,   102,   102,   144,
     144,   172,   103,   106,   233,   125,    13,   224,   270,   176,
     102,   182,   283,   103,   217,   103,   103,   223,   273,   298,
     132,   275,   132,   132,   275,   132,   223,   109,   223,   103,
     174,   174,   279,   103,   106,   175,   174,   174,   220,   272,
     217,   225,   103,   174,   123,   176,   122,   176,   176,   110,
     103,   132,   132,    45,   279,   103,   103,   106,   103,   103,
     272,   179,   103,   281,    54,   172,   223,   135,   123,   103,
     176,   122,   176,   134
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
      

/* Line 1464 of yacc.c  */
#line 3089 "y.tab.c"
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
#line 1224 "120gram.y"


void memoryError(){
	getErrorMessage(ER_MALLOC_E);
	yyerror(NULL);
	exit(1);
}

void getErrorMessage(int ecode){
   int size = 1024;
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
	if(e_message){
		if(s != NULL) fprintf(stderr, "%s\t\'%s\' %s\n",e_message->errorType, s, e_message->message);
		else fprintf(stderr, "%s\t%s\n",e_message->errorType, e_message->message);
	} else {fprintf(stderr, "\n");}
	fflush(stderr);
}

/*
 * creates a token with its attributes
 */
 
Token *createToken(int tcode){
	Token *token = (Token *)calloc(1, sizeof(Token));
	if(token == NULL)memoryError();
	
	int length = strlen(yytext) + 1;
	char *text = (char *)calloc(length, sizeof(char));
	if(text == NULL) memoryError();
   strcpy(text, yytext); 
	token->category = tcode;
   token->text = text;
   token->lineno = lineno;
	
	char *filename = (char *)calloc(strlen(fname) + 1, sizeof(char));
	if(filename == NULL) memoryError();
	strcpy(filename, fname);
   token->filename =filename;
	
	if(tcode == INTEGER) token->ival = atoi(token->text);
	else token->ival = NULL;
   if(tcode == STRING){
      token->ival = length;
      int *st = (int *)calloc(length, sizeof(int));
		if(st == NULL) memoryError();
      int i;
      for(i = 0; i < length; i++) st[i] = (int)text[i];
      token->sval = st;
   }
	else token->sval = NULL;
	
	return token;
}

struct TreeNode * alacnary(int symbol, int prodRule, int children,...){
	struct TreeNode * nd = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
	if(!nd)memoryError();
	nd->symbol = symbol;
	nd->u.n.rule = prodRule;
	int c = 0;
	va_list mylist;
	va_start(mylist, children);
	while(c < children){
		nd->u.n.child[c] = va_arg(mylist, struct node *);
		c++;
	}
	va_end(mylist);
	return nd;
}

int main(int argc, char **argv){
	int rv;
   if(argc > 1) { 
		int f;
		//read each file in arguments
		for(f = 1; f < argc; f++) {
			fname = argv[f];
			FILE *infile = fopen(fname, "r");
			yyin = infile;
			lineno = 0;
			if(!yyin){
				printf("Error reading file %s\n", argv[f]);
				exit(1);
			}
			rv = yyparse();
			//treeprint(yyroot);
		}
	} else { //no files in arguments
		printf("Missing file name.\n");
		exit(1);
	}
   return 0;
}

