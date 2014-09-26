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
#include "errors.h"
#include "120parse.h"

extern int lineno;
int yydebug=1;
FILE *yyin;
char *fname;
int errors;
ErrorMessage *e_message;

//static void yyerror(char *s);


/* Line 189 of yacc.c  */
#line 88 "y.tab.c"

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
     WHILE = 355
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 330 "y.tab.c"

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
#define YYFINAL  175
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3887

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  127
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  171
/* YYNRULES -- Number of rules.  */
#define YYNRULES  500
/* YYNRULES -- Number of states.  */
#define YYNSTATES  843

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   355

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   114,     2,     2,     2,   116,   111,     2,
     101,   102,   110,   112,   109,   113,   106,   115,   125,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   120,   122,
     107,   121,   108,   119,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   104,     2,   105,   117,   126,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   123,   118,   124,   103,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100
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
     674,   676,   678,   683,   687,   692,   696,   700,   705,   713,
     719,   721,   725,   727,   731,   733,   735,   737,   739,   741,
     747,   753,   758,   760,   766,   770,   773,   776,   778,   785,
     791,   797,   802,   807,   814,   820,   826,   831,   837,   843,
     847,   849,   853,   856,   858,   861,   863,   870,   876,   882,
     887,   892,   896,   898,   901,   903,   906,   910,   914,   919,
     921,   924,   926,   928,   930,   933,   937,   940,   943,   946,
     949,   951,   958,   964,   970,   975,   980,   984,   987,   989,
     991,   992,   996,   998,  1002,  1005,  1010,  1013,  1018,  1022,
    1027,  1030,  1034,  1036,  1039,  1043,  1045,  1050,  1053,  1055,
    1059,  1064,  1067,  1071,  1075,  1080,  1082,  1084,  1086,  1089,
    1093,  1097,  1100,  1103,  1105,  1108,  1111,  1113,  1115,  1117,
    1121,  1122,  1124,  1127,  1130,  1134,  1137,  1140,  1143,  1145,
    1149,  1153,  1156,  1159,  1161,  1167,  1172,  1177,  1181,  1187,
    1192,  1197,  1201,  1203,  1205,  1207,  1210,  1213,  1216,  1219,
    1221,  1225,  1230,  1234,  1237,  1240,  1242,  1244,  1247,  1249,
    1251,  1255,  1259,  1261,  1263,  1265,  1267,  1269,  1271,  1273,
    1275,  1277,  1279,  1281,  1283,  1285,  1287,  1289,  1291,  1293,
    1295,  1297,  1299,  1301,  1303,  1305,  1307,  1309,  1311,  1313,
    1315,  1317,  1319,  1321,  1323,  1325,  1327,  1329,  1331,  1334,
    1337,  1344,  1346,  1350,  1352,  1354,  1357,  1362,  1365,  1370,
    1377,  1386,  1391,  1393,  1397,  1399,  1401,  1403,  1406,  1411,
    1415,  1420,  1423,  1429,  1432,  1435,  1437,  1439,  1442,  1447,
    1449,  1453,  1454,  1456,  1457,  1459,  1460,  1462,  1463,  1465,
    1466,  1468,  1469,  1471,  1472,  1474,  1475,  1477,  1478,  1480,
    1481,  1483,  1484,  1486,  1487,  1489,  1490,  1492,  1493,  1495,
    1496,  1498,  1499,  1501,  1502,  1504,  1505,  1507,  1508,  1510,
    1511,  1513,  1514,  1516,  1517,  1519,  1520,  1522,  1523,  1525,
    1526
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     141,     0,    -1,     8,    -1,   130,    -1,     9,    -1,    10,
      -1,   260,    -1,    11,    -1,    12,    -1,     3,    -1,   136,
      -1,   137,    -1,   138,    -1,   139,    -1,   140,    -1,     4,
      -1,     6,    -1,     5,    -1,     7,    -1,    88,    -1,    59,
      -1,   273,    -1,   135,    -1,    86,    -1,   101,   173,   102,
      -1,   143,    -1,   144,    -1,   145,    -1,   134,    -1,   254,
      -1,   247,    -1,   103,   131,    -1,   146,   144,    -1,   146,
      85,   144,    -1,   131,    14,   146,   129,    14,   146,    -1,
     131,    14,    -1,   129,    14,    -1,   142,    -1,   147,   104,
     173,   105,    -1,   147,   101,   275,   102,    -1,   147,   106,
      85,    14,   143,    -1,   147,   106,    85,   143,    -1,   147,
     106,    14,   143,    -1,   147,   106,   143,    -1,   147,    37,
      85,    14,   143,    -1,   147,    37,    85,   143,    -1,   147,
      37,    14,   143,    -1,   147,    37,   143,    -1,   147,    34,
      -1,   147,    35,    -1,    53,   107,   222,   108,   101,   173,
     102,    -1,    82,   107,   222,   108,   101,   173,   102,    -1,
      76,   107,   222,   108,   101,   173,   102,    -1,    47,   107,
     222,   108,   101,   173,   102,    -1,    91,   101,   173,   102,
      -1,    91,   101,   222,   102,    -1,   171,    -1,   148,   109,
     171,    -1,   147,    -1,    34,   158,    -1,    35,   158,    -1,
     110,   158,    -1,   111,   158,    -1,   150,   158,    -1,    80,
     149,    -1,    80,   101,   222,   102,    -1,   151,    -1,   157,
      -1,   112,    -1,   113,    -1,   114,    -1,   103,    -1,    70,
     277,   153,   278,    -1,    14,    70,   277,   153,   278,    -1,
      70,   277,   101,   222,   102,   278,    -1,    14,    70,   277,
     101,   222,   102,   278,    -1,   101,   148,   102,    -1,   223,
     279,    -1,   218,   279,    -1,   155,    -1,   104,   173,   105,
      -1,   155,   104,   174,   105,    -1,   101,   275,   102,    -1,
      50,   158,    -1,    14,    50,   158,    -1,    50,   104,   105,
     158,    -1,    14,    50,   104,   105,   158,    -1,   149,    -1,
     101,   222,   102,   158,    -1,   158,    -1,   159,    15,   158,
      -1,   159,    36,   158,    -1,   159,    -1,   160,   110,   159,
      -1,   160,   115,   159,    -1,   160,   116,   159,    -1,   160,
      -1,   161,   112,   160,    -1,   161,   113,   160,    -1,   161,
      -1,   162,    24,   161,    -1,   162,    25,   161,    -1,   162,
      -1,   163,   107,   162,    -1,   163,   108,   162,    -1,   163,
      30,   162,    -1,   163,    31,   162,    -1,   163,    -1,   164,
      28,   163,    -1,   164,    29,   163,    -1,   164,    -1,   165,
     111,   164,    -1,   165,    -1,   166,   117,   165,    -1,   166,
      -1,   167,   118,   166,    -1,   167,    -1,   168,    32,   167,
      -1,   168,    -1,   169,    33,   168,    -1,   169,    -1,   169,
     119,   173,   120,   171,    -1,   170,    -1,   169,   172,   171,
      -1,   270,    -1,   121,    -1,    18,    -1,    19,    -1,    20,
      -1,    16,    -1,    17,    -1,    26,    -1,    27,    -1,    22,
      -1,    21,    -1,    23,    -1,   171,    -1,   173,   109,   171,
      -1,   170,    -1,   176,    -1,   177,    -1,   178,    -1,   180,
      -1,   182,    -1,   184,    -1,   185,    -1,   265,    -1,   134,
     120,   175,    -1,    42,   174,   120,   175,    -1,    49,   120,
     175,    -1,   280,   122,    -1,   123,   281,   124,    -1,   175,
      -1,   179,   175,    -1,    64,   101,   181,   102,   175,    -1,
      64,   101,   181,   102,   175,    54,   175,    -1,    84,   101,
     181,   102,   175,    -1,   173,    -1,   223,   216,   121,   171,
      -1,   100,   101,   181,   102,   175,    -1,    51,   175,   100,
     101,   173,   102,   122,    -1,    61,   101,   183,   282,   122,
     280,   102,   175,    -1,   177,    -1,   189,    -1,    41,   122,
      -1,    48,   122,    -1,    77,   280,   122,    -1,    63,   134,
     122,    -1,   188,    -1,   187,    -1,   186,   187,    -1,   188,
      -1,   229,    -1,   256,    -1,   263,    -1,   264,    -1,   213,
      -1,   202,    -1,   189,    -1,   212,    -1,   208,    -1,   210,
      -1,   211,    -1,   191,   214,   122,    -1,   191,   122,    -1,
     192,    -1,   194,    -1,   193,    -1,    62,    -1,    90,    -1,
     190,    -1,   191,   190,    -1,    39,    -1,    75,    -1,    81,
      -1,    58,    -1,    68,    -1,    65,    -1,    96,    -1,    56,
      -1,   195,    -1,   234,    -1,   198,    -1,   197,    -1,   220,
      -1,   196,    -1,   146,   196,    -1,    14,   274,   196,    -1,
      44,    -1,    99,    -1,    40,    -1,    78,    -1,    66,    -1,
      67,    -1,    79,    -1,    94,    -1,    60,    -1,    52,    -1,
      97,    -1,   131,    -1,   132,    -1,   128,    -1,   236,    14,
     146,   134,    -1,   236,    14,   134,    -1,    55,    14,   146,
     134,    -1,    55,    14,   134,    -1,    55,   146,   134,    -1,
      92,   276,   146,   134,    -1,    92,   276,   146,   134,   107,
     261,   108,    -1,    55,   134,   123,   283,   124,    -1,   200,
      -1,   199,   109,   200,    -1,   201,    -1,   201,   121,   174,
      -1,   134,    -1,   203,    -1,   206,    -1,   204,    -1,   205,
      -1,    69,   134,   123,   207,   124,    -1,    69,   130,   123,
     207,   124,    -1,    69,   123,   207,   124,    -1,   273,    -1,
      69,   134,   121,   209,   122,    -1,    14,   146,   129,    -1,
      14,   129,    -1,   146,   129,    -1,   129,    -1,    95,    92,
      14,   146,   144,   122,    -1,    95,    92,   146,   144,   122,
      -1,    95,    14,   146,   144,   122,    -1,    95,   146,   144,
     122,    -1,    95,    14,   144,   122,    -1,    95,    69,    14,
     146,   129,   122,    -1,    95,    69,    14,   129,   122,    -1,
      95,    69,   146,   129,   122,    -1,    95,    69,   129,   122,
      -1,    38,   101,   139,   102,   122,    -1,    58,   139,   123,
     273,   124,    -1,    58,   139,   187,    -1,   215,    -1,   214,
     109,   215,    -1,   216,   284,    -1,   217,    -1,   218,   216,
      -1,   221,    -1,   217,   101,   226,   102,   219,   271,    -1,
     217,   101,   226,   102,   219,    -1,   217,   101,   226,   102,
     271,    -1,   217,   101,   226,   102,    -1,   217,   104,   285,
     105,    -1,   101,   216,   102,    -1,   110,    -1,   110,   219,
      -1,   111,    -1,   146,   110,    -1,   146,   110,   219,    -1,
      14,   146,   110,    -1,    14,   146,   110,   219,    -1,   220,
      -1,   220,   219,    -1,    46,    -1,    98,    -1,   143,    -1,
      14,   143,    -1,    14,   146,   196,    -1,    14,   196,    -1,
     223,   286,    -1,   194,   287,    -1,   218,   286,    -1,   225,
      -1,   288,   101,   226,   102,   219,   271,    -1,   288,   101,
     226,   102,   219,    -1,   288,   101,   226,   102,   271,    -1,
     288,   101,   226,   102,    -1,   288,   104,   285,   105,    -1,
     101,   224,   102,    -1,   227,    13,    -1,   227,    -1,    13,
      -1,    -1,   227,   109,    13,    -1,   228,    -1,   227,   109,
     228,    -1,   191,   216,    -1,   191,   216,   121,   171,    -1,
     191,   286,    -1,   191,   286,   121,   171,    -1,   216,   289,
     230,    -1,   191,   216,   289,   230,    -1,   216,   266,    -1,
     191,   216,   266,    -1,   178,    -1,   121,   232,    -1,   101,
     148,   102,    -1,   171,    -1,   123,   233,   290,   124,    -1,
     123,   124,    -1,   232,    -1,   233,   109,   232,    -1,   235,
     123,   291,   124,    -1,   236,   134,    -1,   236,   134,   243,
      -1,   236,   146,   134,    -1,   236,   146,   134,   243,    -1,
      45,    -1,    83,    -1,    93,    -1,   238,   291,    -1,   246,
     120,   291,    -1,   191,   239,   122,    -1,   191,   122,    -1,
     239,   122,    -1,   122,    -1,   229,   292,    -1,   145,   122,
      -1,   210,    -1,   256,    -1,   240,    -1,   239,   109,   240,
      -1,    -1,   216,    -1,   216,   241,    -1,   216,   242,    -1,
     134,   120,   174,    -1,   121,   125,    -1,   121,   174,    -1,
     120,   244,    -1,   245,    -1,   244,   109,   245,    -1,    14,
     146,   131,    -1,    14,   131,    -1,   146,   131,    -1,   131,
      -1,    96,   246,    14,   274,   131,    -1,    96,   246,   274,
     131,    -1,    96,    14,   274,   131,    -1,    96,   274,   131,
      -1,   246,    96,    14,   274,   131,    -1,   246,    96,   274,
     131,    -1,   246,    14,   274,   131,    -1,   246,   274,   131,
      -1,    72,    -1,    73,    -1,    74,    -1,    71,   248,    -1,
     223,   293,    -1,   218,   293,    -1,   120,   251,    -1,   252,
      -1,   252,   109,   251,    -1,   253,   101,   275,   102,    -1,
      14,   146,   131,    -1,    14,   131,    -1,   146,   131,    -1,
     131,    -1,   134,    -1,    71,   255,    -1,    70,    -1,    50,
      -1,    70,   104,   105,    -1,    50,   104,   105,    -1,   112,
      -1,   126,    -1,   110,    -1,   115,    -1,   116,    -1,   117,
      -1,   111,    -1,   118,    -1,   103,    -1,   114,    -1,   121,
      -1,   107,    -1,   108,    -1,    16,    -1,    17,    -1,    18,
      -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,
      -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,
      -1,    34,    -1,    35,    -1,   109,    -1,    36,    -1,    37,
      -1,   101,   102,    -1,   104,   105,    -1,   294,    85,   107,
     257,   108,   187,    -1,   258,    -1,   257,   109,   258,    -1,
     259,    -1,   228,    -1,    45,   134,    -1,    45,   134,   121,
     222,    -1,    92,   134,    -1,    92,   134,   121,   222,    -1,
      85,   107,   257,   108,    45,   134,    -1,    85,   107,   257,
     108,    45,   134,   121,   133,    -1,   133,   107,   261,   108,
      -1,   262,    -1,   261,   109,   262,    -1,   171,    -1,   222,
      -1,   133,    -1,    85,   187,    -1,    85,   107,   108,   187,
      -1,    89,   178,   267,    -1,    89,   289,   230,   267,    -1,
     268,   295,    -1,    43,   101,   269,   102,   178,    -1,   223,
     216,    -1,   223,   224,    -1,   223,    -1,    13,    -1,    87,
     296,    -1,    87,   101,   297,   102,    -1,   222,    -1,   272,
     109,   222,    -1,    -1,   186,    -1,    -1,   146,    -1,    -1,
     148,    -1,    -1,    14,    -1,    -1,   152,    -1,    -1,   156,
      -1,    -1,   154,    -1,    -1,   173,    -1,    -1,   179,    -1,
      -1,   181,    -1,    -1,   199,    -1,    -1,   231,    -1,    -1,
     174,    -1,    -1,   224,    -1,    -1,   223,    -1,    -1,   225,
      -1,    -1,   250,    -1,    -1,   109,    -1,    -1,   237,    -1,
      -1,   122,    -1,    -1,   249,    -1,    -1,    57,    -1,    -1,
     267,    -1,    -1,   171,    -1,    -1,   272,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    88,    93,    98,    99,   104,   109,   117,
     121,   122,   123,   124,   125,   129,   133,   137,   141,   145,
     146,   154,   162,   163,   164,   165,   169,   170,   174,   175,
     176,   177,   181,   182,   186,   188,   189,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   215,   216,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   233,   234,
     235,   236,   240,   241,   242,   243,   247,   251,   255,   256,
     260,   261,   265,   269,   270,   271,   272,   276,   277,   281,
     282,   283,   287,   288,   289,   290,   294,   295,   296,   300,
     301,   302,   306,   307,   308,   309,   310,   314,   315,   316,
     320,   321,   325,   326,   330,   331,   335,   336,   340,   341,
     345,   346,   350,   351,   352,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   370,   371,   375,   383,
     384,   385,   386,   387,   388,   389,   390,   394,   395,   396,
     400,   404,   408,   409,   413,   414,   415,   419,   420,   424,
     425,   426,   430,   431,   435,   436,   437,   438,   442,   450,
     451,   455,   456,   457,   458,   459,   460,   461,   465,   466,
     467,   468,   469,   473,   474,   478,   479,   480,   481,   482,
     486,   487,   491,   492,   493,   494,   495,   499,   500,   501,
     505,   506,   507,   508,   509,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   530,
     531,   532,   536,   537,   538,   539,   540,   541,   542,   552,
     556,   557,   561,   562,   566,   581,   582,   586,   587,   591,
     595,   599,   603,   613,   617,   618,   619,   620,   624,   625,
     626,   627,   628,   632,   633,   634,   635,   639,   643,   644,
     652,   653,   657,   661,   662,   666,   667,   668,   669,   670,
     671,   672,   676,   677,   678,   679,   680,   681,   682,   686,
     687,   691,   692,   696,   697,   698,   699,   703,   707,   711,
     712,   716,   717,   718,   719,   720,   721,   725,   726,   727,
     728,   729,   733,   734,   738,   739,   740,   741,   745,   746,
     747,   748,   752,   756,   757,   761,   762,   763,   767,   768,
     776,   780,   781,   782,   783,   787,   788,   789,   793,   794,
     798,   799,   800,   801,   802,   803,   804,   805,   809,   810,
     813,   814,   815,   816,   817,   826,   830,   838,   842,   843,
     847,   848,   849,   850,   851,   852,   853,   854,   855,   856,
     857,   858,   862,   863,   864,   872,   876,   880,   884,   888,
     889,   893,   897,   898,   899,   900,   901,   909,   913,   914,
     915,   916,   917,   918,   919,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,   930,   931,   932,   933,   934,
     935,   936,   937,   938,   939,   940,   941,   942,   943,   944,
     945,   946,   947,   948,   949,   950,   951,   952,   953,   954,
     962,   966,   967,   971,   972,   976,   977,   978,   979,   980,
     981,   985,   989,   990,   994,   995,   996,  1000,  1004,  1012,
    1016,  1020,  1024,  1028,  1029,  1030,  1031,  1035,  1039,  1043,
    1044,  1051,  1053,  1056,  1058,  1061,  1063,  1066,  1068,  1071,
    1073,  1076,  1078,  1081,  1083,  1086,  1088,  1091,  1093,  1096,
    1098,  1101,  1103,  1106,  1108,  1111,  1113,  1116,  1118,  1121,
    1123,  1126,  1128,  1131,  1133,  1136,  1138,  1141,  1143,  1146,
    1148,  1151,  1153,  1156,  1158,  1161,  1163,  1166,  1168,  1171,
    1173
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
  "VIRTUAL", "VOID", "VOLATILE", "WCHAR_T", "WHILE", "'('", "')'", "'~'",
  "'['", "']'", "'.'", "'<'", "'>'", "','", "'*'", "'&'", "'+'", "'-'",
  "'!'", "'/'", "'%'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'",
  "'}'", "'0'", "'_'", "$accept", "typedef_name", "namespace_name",
  "original_namespace_name", "class_name", "enum_name", "template_name",
  "identifier", "literal", "integer_literal", "character_literal",
  "floating_literal", "string_literal", "boolean_literal",
  "translation_unit", "primary_expression", "id_expression",
  "unqualified_id", "qualified_id", "nested_name_specifier",
  "postfix_expression", "expression_list", "unary_expression",
  "unary_operator", "new_expression", "new_placement", "new_type_id",
  "new_declarator", "direct_new_declarator", "new_initializer",
  "delete_expression", "cast_expression", "pm_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
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
     355,    40,    41,   126,    91,    93,    46,    60,    62,    44,
      42,    38,    43,    45,    33,    47,    37,    94,   124,    63,
      58,    61,    59,   123,   125,    48,    95
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   127,   128,   129,   130,   131,   131,   132,   133,   134,
     135,   135,   135,   135,   135,   136,   137,   138,   139,   140,
     140,   141,   142,   142,   142,   142,   143,   143,   144,   144,
     144,   144,   145,   145,   146,   146,   146,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   148,   148,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   150,   150,
     150,   150,   151,   151,   151,   151,   152,   153,   154,   154,
     155,   155,   156,   157,   157,   157,   157,   158,   158,   159,
     159,   159,   160,   160,   160,   160,   161,   161,   161,   162,
     162,   162,   163,   163,   163,   163,   163,   164,   164,   164,
     165,   165,   166,   166,   167,   167,   168,   168,   169,   169,
     170,   170,   171,   171,   171,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   173,   173,   174,   175,
     175,   175,   175,   175,   175,   175,   175,   176,   176,   176,
     177,   178,   179,   179,   180,   180,   180,   181,   181,   182,
     182,   182,   183,   183,   184,   184,   184,   184,   185,   186,
     186,   187,   187,   187,   187,   187,   187,   187,   188,   188,
     188,   188,   188,   189,   189,   190,   190,   190,   190,   190,
     191,   191,   192,   192,   192,   192,   192,   193,   193,   193,
     194,   194,   194,   194,   194,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   196,
     196,   196,   197,   197,   197,   197,   197,   197,   197,   198,
     199,   199,   200,   200,   201,   202,   202,   203,   203,   204,
     205,   206,   207,   208,   209,   209,   209,   209,   210,   210,
     210,   210,   210,   211,   211,   211,   211,   212,   213,   213,
     214,   214,   215,   216,   216,   217,   217,   217,   217,   217,
     217,   217,   218,   218,   218,   218,   218,   218,   218,   219,
     219,   220,   220,   221,   221,   221,   221,   222,   223,   224,
     224,   225,   225,   225,   225,   225,   225,   226,   226,   226,
     226,   226,   227,   227,   228,   228,   228,   228,   229,   229,
     229,   229,   230,   231,   231,   232,   232,   232,   233,   233,
     234,   235,   235,   235,   235,   236,   236,   236,   237,   237,
     238,   238,   238,   238,   238,   238,   238,   238,   239,   239,
     240,   240,   240,   240,   240,   241,   242,   243,   244,   244,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   246,   246,   246,   247,   248,   249,   250,   251,
     251,   252,   253,   253,   253,   253,   253,   254,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     256,   257,   257,   258,   258,   259,   259,   259,   259,   259,
     259,   260,   261,   261,   262,   262,   262,   263,   264,   265,
     266,   267,   268,   269,   269,   269,   269,   270,   271,   272,
     272,   273,   273,   274,   274,   275,   275,   276,   276,   277,
     277,   278,   278,   279,   279,   280,   280,   281,   281,   282,
     282,   283,   283,   284,   284,   285,   285,   286,   286,   287,
     287,   288,   288,   289,   289,   290,   290,   291,   291,   292,
     292,   293,   293,   294,   294,   295,   295,   296,   296,   297,
     297
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
       1,     1,     4,     3,     4,     3,     3,     4,     7,     5,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     5,
       5,     4,     1,     5,     3,     2,     2,     1,     6,     5,
       5,     4,     4,     6,     5,     5,     4,     5,     5,     3,
       1,     3,     2,     1,     2,     1,     6,     5,     5,     4,
       4,     3,     1,     2,     1,     2,     3,     3,     4,     1,
       2,     1,     1,     1,     2,     3,     2,     2,     2,     2,
       1,     6,     5,     5,     4,     4,     3,     2,     1,     1,
       0,     3,     1,     3,     2,     4,     2,     4,     3,     4,
       2,     3,     1,     2,     3,     1,     4,     2,     1,     3,
       4,     2,     3,     3,     4,     1,     1,     1,     2,     3,
       3,     2,     2,     1,     2,     2,     1,     1,     1,     3,
       0,     1,     2,     2,     3,     2,     2,     2,     1,     3,
       3,     2,     2,     1,     5,     4,     4,     3,     5,     4,
       4,     3,     1,     1,     1,     2,     2,     2,     2,     1,
       3,     4,     3,     2,     2,     1,     1,     2,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       6,     1,     3,     1,     1,     2,     4,     2,     4,     6,
       8,     4,     1,     3,     1,     1,     1,     2,     4,     3,
       4,     2,     5,     2,     2,     1,     1,     2,     4,     1,
       3,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     451,     9,     2,     4,     5,     7,     8,     0,     0,   192,
     210,   208,   325,   281,   217,     0,   199,   494,   195,   216,
     188,   197,   212,   213,   196,     0,     0,   193,   211,   214,
     194,   326,     0,   189,   457,   327,   215,     0,   198,   218,
     282,   209,     0,     0,   272,   274,   221,     0,     3,   219,
     220,     0,    28,     0,   283,    26,    27,     0,   452,   169,
     171,   178,   190,     0,   185,   187,   186,   200,   205,   203,
     202,   177,   235,   237,   238,   236,   180,   181,   182,   179,
     176,   483,   263,     0,   204,   265,   172,   201,     0,     0,
      30,    29,   173,     6,   174,   175,    21,     0,   284,     0,
     286,     0,     0,     0,     0,     0,     0,    18,     0,   451,
       0,     0,   453,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   416,   417,   379,   378,     0,   390,     0,
     393,   394,   415,   384,   388,   382,   391,   385,   386,   387,
     389,   392,   383,     0,   479,   491,   365,   377,     0,   437,
     458,     0,     0,     0,     0,     0,     0,     0,     0,    31,
     273,   279,    36,    35,     0,     1,     0,   275,   219,    32,
     206,   170,   195,   184,   191,     0,   260,   473,   483,     0,
     484,   310,     0,   300,   475,   264,   340,     0,   321,     0,
       0,   277,   285,   207,     0,   225,     0,   471,   226,   451,
     259,     0,   242,   451,     0,   451,   454,     0,     0,   418,
     419,   480,   288,     0,     0,   491,   492,   366,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     280,     0,    15,    17,    16,   453,     0,     0,     0,     0,
       0,    20,   459,     0,     0,     0,    23,   497,    19,     0,
       0,    71,     0,     0,    68,    69,    70,   436,    22,    10,
      11,    12,    13,    14,    37,    25,     0,    58,    87,     0,
      66,    67,    89,    92,    96,    99,   102,   107,   110,   112,
     114,   116,   118,   120,   122,   434,   435,   477,     0,   432,
     124,    33,   276,     0,   183,     0,     0,   474,   311,   262,
       0,     0,     0,   375,   376,     0,   368,   369,     0,   465,
     312,   308,   299,   477,     0,   298,   302,     0,     0,   120,
     138,   476,     0,   362,   363,   364,     0,   333,    28,    27,
     340,   336,   341,   489,   488,   340,     0,   338,     0,   337,
       0,   223,     0,     0,   322,   323,     0,   278,     0,   224,
     234,   472,   230,   232,     0,     0,   241,     0,     0,   247,
       0,     0,     0,   381,   380,     0,   367,   438,   227,   252,
       0,     0,     0,   256,     0,     0,     0,   251,     0,     0,
     459,    59,    60,     0,     0,    83,     0,     0,   460,     0,
       0,     0,    64,     0,   498,   447,     0,   136,     0,     0,
      61,    62,    48,    49,     0,   455,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     126,   127,   128,   134,   133,   135,   131,   132,     0,     0,
     125,     0,   481,   477,   478,   290,   287,     0,   431,     0,
     261,   473,     0,    56,     0,   315,   313,   309,     0,   373,
       0,   374,     0,   455,     0,     0,     0,     0,   465,     0,
       0,     0,     0,   465,     0,     0,     0,    28,   466,   152,
     139,   140,   141,   465,   142,   143,   144,   145,   168,     0,
     146,     0,     0,   481,   304,   477,   306,   269,   297,     0,
     270,     0,   335,   331,   341,     0,     0,   342,   343,   490,
     334,   328,   340,   332,   340,   320,   222,     0,     0,   353,
       0,   347,   348,     0,   324,   325,     0,   457,   424,     0,
     421,   423,   257,     0,     0,   229,   258,   240,   245,     0,
     246,   243,   239,     0,   250,   254,     0,   255,     0,   249,
       0,     0,    84,     0,     0,     0,     0,     0,     0,   461,
     463,     0,     0,     0,     0,     0,    24,     0,     0,     0,
       0,    47,   456,     0,     0,     0,     0,    43,    90,    91,
      93,    94,    95,    97,    98,   100,   101,   105,   106,   103,
     104,   108,   109,   111,   113,   115,   117,   119,     0,   123,
       0,   289,   300,   475,   433,   314,     0,   317,   318,   485,
       0,   440,   495,   372,   370,     0,   164,     0,   165,   465,
       0,   465,     0,     0,     0,     0,     0,     0,     0,   465,
     153,   150,   151,     0,     0,     0,   267,   268,   301,   303,
     344,   330,   345,   346,   341,   339,   329,   351,     0,     0,
       0,     0,   352,     0,     0,     0,     0,   425,     0,   427,
       0,     0,   231,   233,   244,     0,   253,   248,    34,     0,
       0,   461,     0,    85,     0,    76,     0,   455,   462,    72,
       0,   464,    79,   463,    77,     0,    65,     0,    54,    55,
     137,    88,    46,     0,    45,    39,    38,    42,     0,    41,
       0,   296,     0,     0,    57,   486,     0,     0,   496,   441,
     371,   465,   149,     0,   162,   469,   163,   167,   157,     0,
       0,   166,     0,   439,     0,   147,   305,   307,   499,   266,
     350,     0,     0,     0,   357,   349,     0,     0,     0,   361,
       0,     0,     0,   420,   422,   228,    86,     0,    73,     0,
       0,   461,     0,     0,     0,    78,     0,     0,    44,    40,
     121,   294,   295,   319,   316,   446,   445,     0,   148,     0,
     470,     0,   465,     0,   465,   465,   449,   500,     0,   356,
       0,   355,   360,     0,   359,   426,     0,   428,   461,     0,
       0,    74,    82,    80,     0,     0,     0,   292,   293,   443,
     444,     0,     0,   465,   154,     0,   156,   159,     0,   448,
     354,   358,     0,    75,    53,    50,    81,    52,    51,   291,
     442,     0,     0,   465,   158,   450,   429,   160,   465,   155,
       0,   161,   430
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    46,    47,    48,   104,    50,    51,    52,   268,   269,
     270,   271,   272,   273,    53,   274,   275,    55,    56,   328,
     277,   582,   278,   279,   280,   398,   569,   691,   692,   688,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   407,   451,   488,   331,   489,   490,
     491,   492,   493,   494,   729,   495,   725,   496,   497,    58,
      59,   498,    61,    62,   499,    64,    65,    66,    67,    68,
      69,    70,   361,   362,   363,    71,    72,    73,    74,    75,
     211,    76,   371,    77,    78,    79,    80,   185,   186,    81,
      82,    83,   170,    84,    85,   296,   297,   454,   455,   324,
     325,   538,    86,   321,   307,   466,   619,    87,    88,    89,
     344,   345,   346,   347,   517,   518,   354,   531,   532,   348,
      90,   156,   226,   190,   316,   317,   318,    91,   157,    92,
     539,   540,   541,    93,   298,   299,    94,    95,   500,   191,
     621,   622,   777,   300,   647,   787,   212,   101,   583,   161,
     399,   689,   694,   501,   502,   781,   364,   309,   332,   611,
     222,   457,   192,   716,   350,   520,   227,    97,   719,   405,
     788
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -646
static const yytype_int16 yypact[] =
{
    3178,  -646,  -646,  -646,  -646,  -646,  -646,   811,   -11,  -646,
    -646,  -646,  -646,  -646,  -646,   673,  -646,  -646,   121,  -646,
    -646,  -646,  -646,  -646,  -646,    35,  2361,  -646,  -646,  -646,
    -646,  -646,  3073,  -646,   119,  -646,  -646,   781,  -646,  -646,
    -646,  -646,   634,   171,    21,  -646,  -646,   128,  -646,   142,
    -646,   137,  -646,   210,  -646,  -646,  -646,   846,  3178,  -646,
    -646,  -646,  -646,  2150,  -646,  -646,  -646,  -646,  -646,  -646,
    -646,  -646,  -646,  -646,  -646,  -646,  -646,  -646,  -646,  -646,
    -646,   -41,   -16,   634,  -646,  -646,  -646,  -646,   133,   697,
    -646,  -646,  -646,  -646,  -646,  -646,  -646,   180,  -646,  1025,
    -646,   507,   121,   379,   142,   152,   280,  -646,  1954,  3178,
     184,   103,    47,  -646,  -646,  -646,  -646,  -646,  -646,  -646,
    -646,  -646,  -646,  -646,  -646,  -646,  -646,  -646,  -646,  -646,
    -646,  -646,  -646,  -646,  -646,   216,   222,   245,  -646,   246,
    -646,  -646,  -646,  -646,  -646,  -646,  -646,  -646,  -646,  -646,
    -646,  -646,  -646,   507,  3788,   170,  -646,  -646,   253,  -646,
    -646,    47,   461,   350,   426,    96,   811,    40,   265,  -646,
    -646,    21,  -646,    47,  2597,  -646,    96,    21,  -646,  -646,
    -646,  -646,  -646,  -646,  -646,    63,  -646,   -29,   249,   750,
    -646,  -646,   252,  3482,  2947,  -646,  1729,   379,   259,   280,
     283,    21,  -646,  -646,   290,  -646,   280,   280,  -646,  3178,
    -646,   284,  -646,  3178,   492,  3178,  -646,   310,   316,  -646,
    -646,  -646,  -646,    47,   313,   170,  -646,  -646,  3178,   280,
     311,    96,    47,    14,   428,    47,    96,   317,  1025,  -646,
    -646,   428,  -646,  -646,  -646,    52,  2947,  2947,   359,  2709,
     361,  -646,   375,   377,  2961,   387,  -646,  2821,  -646,   381,
    2597,   171,  2947,  2947,  -646,  -646,  -646,   137,  -646,  -646,
    -646,  -646,  -646,  -646,  -646,  -646,   983,   548,  -646,  2947,
    -646,  -646,  -646,    30,   262,   274,   370,   208,   369,   385,
     383,   392,   480,  1099,  -646,  -646,  -646,   448,   303,  -646,
    -646,  -646,  -646,   634,  -646,  2821,  2064,  -646,  -646,  -646,
     252,   252,    47,   142,  -646,   171,  -646,   407,   422,  1432,
    -646,  -646,  -646,  3282,   427,    28,  -646,    45,    46,    13,
    -646,  -646,   436,  -646,  -646,  -646,   416,  -646,   411,   421,
    2254,  -646,   129,   423,  -646,  1729,    83,  -646,   430,  -646,
     441,  -646,   280,  1092,  -646,   259,  3544,  -646,   425,  -646,
    -646,   445,  -646,   446,   447,   450,  -646,   453,    47,   128,
     428,   459,   469,  -646,  -646,   486,  -646,  -646,   462,  -646,
     476,    26,   428,  -646,   478,    96,   482,  -646,   588,  2835,
     375,  -646,  -646,  3788,   503,  -646,  3788,  2821,  -646,  3359,
    3788,  2597,  -646,  3788,  -646,  -646,  2597,  -646,    99,   515,
    -646,  -646,  -646,  -646,   803,  2821,  2821,  1160,  -646,  2947,
    2947,  2947,  2947,  2947,  2947,  2947,  2947,  2947,  2947,  2947,
    2947,  2947,  2947,  2947,  2947,  2947,  2947,  2947,  -646,  -646,
    -646,  -646,  -646,  -646,  -646,  -646,  -646,  -646,  2947,  2821,
    -646,  2821,   465,   448,  -646,   230,  -646,   234,  -646,  2597,
    -646,   -17,   102,  -646,  1146,  -646,  -646,  -646,   566,   142,
     171,  -646,   750,  2821,   497,  2947,   498,   505,  1838,   533,
     280,   534,   280,  2821,   539,   252,   544,   531,   546,  -646,
    -646,  -646,  -646,  1612,  -646,  -646,  -646,  -646,  -646,  2150,
    -646,   535,   537,   793,   541,   410,   545,   226,  -646,  3636,
    -646,  2947,  -646,  -646,   129,    98,   970,  -646,  -646,  -646,
    -646,  -646,   634,  -646,  1729,  -646,  -646,    47,  1039,   142,
     171,   560,  -646,    61,  -646,   280,   567,   107,  -646,   309,
    -646,  -646,  -646,   280,  2947,  -646,  -646,  -646,   128,   428,
    -646,  -646,  -646,  2597,  -646,  -646,   553,  -646,   555,  -646,
      47,   584,  -646,  3419,   582,  2947,   591,   127,  3788,   595,
     207,   604,   590,   605,   132,   601,  -646,  2821,  2947,   461,
     936,  -646,   606,   602,   157,   461,  1194,  -646,  -646,  -646,
      30,    30,    30,   262,   262,   274,   274,   370,   370,   370,
     370,   208,   208,   369,   385,   383,   392,   480,    66,  -646,
     616,  -646,  3482,  2947,  -646,  -646,  2821,  -646,  -646,   610,
     625,  -646,   566,  -646,  -646,   637,  -646,   607,  -646,  1838,
     643,  2485,   626,  2597,   628,   629,  2597,   566,  2597,  1838,
    -646,  -646,  -646,  2821,  2821,   665,   680,  -646,  -646,  -646,
    -646,  -646,  -646,  -646,   649,  -646,  -646,   142,   171,    47,
     618,   171,  -646,  1092,    47,   722,   171,   650,  3544,   653,
    3178,  3544,  -646,  -646,  -646,   337,  -646,  -646,  -646,  2947,
    3788,   595,   674,  -646,   676,  -646,   677,  2821,  -646,  -646,
    2821,  -646,   683,   207,  -646,   679,  -646,   691,  -646,  -646,
    -646,  -646,  -646,   461,  -646,  -646,  -646,  -646,   461,  -646,
    2821,  -646,   692,   694,  -646,  2064,   654,  3728,  -646,  -646,
    -646,  1838,  -646,   696,  -646,  2597,  -646,  -646,   546,   699,
     634,  -646,   707,  -646,   708,  -646,  -646,  -646,  3788,  -646,
    -646,   171,    47,   171,  -646,  -646,   171,    47,   171,  -646,
    3788,   417,  3788,  -646,  -646,  -646,  -646,   714,  -646,  2821,
    2821,   595,   723,   201,  2947,  -646,  2821,  2821,  -646,  -646,
    -646,   226,  -646,  -646,  -646,  -646,   410,   724,  -646,  2821,
    -646,   709,  1838,   715,  1838,  1838,  -646,   720,   735,  -646,
     171,  -646,  -646,   171,  -646,  -646,   794,  -646,   595,   145,
     155,  -646,  -646,  -646,   736,   175,   191,   680,  -646,  -646,
    -646,   252,   219,  2821,   786,  2821,  -646,  -646,  3788,  -646,
    -646,  -646,   280,  -646,  -646,  -646,  -646,  -646,  -646,  -646,
    -646,   726,   740,  1838,  -646,  -646,   730,  -646,  1838,  -646,
     833,  -646,  -646
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -646,  -646,   -94,   827,   615,  -646,  -173,    62,  -646,  -646,
    -646,  -646,    50,  -646,  -646,  -646,   879,   596,  -176,     0,
    -646,  -252,   608,  -646,  -646,  -646,   292,  -646,  -646,  -646,
    -646,  -149,    68,   111,   130,   161,   147,   429,   432,   424,
     431,   413,  -186,  -170,   282,  -646,  -153,  -410,  -287,  -646,
     238,  -187,  -646,  -646,  -584,  -646,  -646,  -646,  -646,  -646,
     -28,    18,   239,   -38,    86,  -646,  -646,    48,  -646,    89,
    -646,  -646,  -646,   322,  -646,  -646,  -646,  -646,  -646,  -646,
      79,  -646,  -646,  -175,  -646,  -646,  -646,  -646,   568,   -36,
    -646,  -120,  -168,   -42,  -646,   -30,   -15,  -421,  -646,   266,
    -646,  -180,  -174,   251,  -646,  -425,  -646,  -646,  -646,  -646,
    -646,  -646,   540,   355,  -646,  -646,   526,  -646,   220,  -341,
    -646,  -646,  -646,  -646,   415,  -646,  -646,  -646,  -646,  -167,
     217,   218,  -646,  -646,   339,   434,  -646,  -646,  -646,  -177,
    -544,  -646,  -646,  -646,  -595,  -646,    34,  -255,  -450,  -646,
     500,  -645,   204,  -469,  -646,  -646,  -646,  -646,   286,  -242,
    -646,  -646,  -171,  -646,  -326,  -646,   682,  -646,  -646,  -646,
    -646
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -494
static const yytype_int16 yytable[] =
{
      57,   267,   171,   240,   159,   320,   168,    99,   329,   302,
     308,   155,   533,   326,   635,   106,   310,   311,    60,   521,
     339,   341,   343,   625,   330,   184,   153,   187,   172,   349,
     181,   610,    57,   357,    96,   225,   758,   165,     1,   618,
     172,   508,   167,     1,     3,   419,   448,   195,   188,     1,
      60,   739,   732,   462,   734,   456,     3,     4,    57,     6,
     188,     3,     4,    57,     6,   627,   420,    13,   108,   233,
       3,     4,   305,     6,   154,   664,    60,   105,   718,   189,
     210,   506,   610,   167,   305,   193,    63,   111,   194,   199,
     102,   189,   306,   733,  -483,   389,   100,   391,   392,     1,
     395,   650,   389,   206,   306,   225,   653,   408,    57,    57,
       1,    26,   216,   410,   411,   390,   801,    26,    63,    40,
     369,   160,   390,   320,   320,   176,    60,    60,   107,   171,
     418,   176,   449,   160,   673,   171,   383,   509,   381,   221,
     384,   780,   172,    43,    63,   567,   180,   388,   555,    43,
     177,   198,   204,   823,   153,   224,   173,   665,   109,   171,
     342,   229,   231,   234,   236,   205,   238,    26,   208,   339,
     341,   343,   303,   241,   276,   577,   808,   453,   349,     3,
       4,     4,     6,     6,   223,   304,   710,   660,   202,   315,
     203,   630,   522,   153,    63,    63,    57,   352,   656,    43,
     377,   576,   154,   505,   615,   523,   640,   522,   577,    57,
     175,   616,   829,    57,   370,    57,     3,     4,   188,     6,
     651,   223,   154,   375,   214,   224,   215,    60,    57,   685,
     409,    60,   382,    60,   698,   385,   616,   762,   428,   429,
     562,   577,   180,   365,   174,   216,    60,   824,   408,   189,
     516,   314,  -483,   574,   577,   100,   196,   825,   338,   351,
     276,   355,   706,   584,   577,   200,   577,   461,   359,   360,
     588,   589,    13,   661,   548,   207,   550,   827,   666,   323,
      44,    45,   340,     1,   577,   184,   267,   504,   556,   329,
     773,   378,   367,   828,   372,    63,   608,   224,   637,    63,
     577,    63,   184,   167,   514,   330,   803,   213,   154,   342,
     577,   690,   470,   645,    63,   430,   431,    44,    45,   276,
     217,   831,   533,    57,    40,   329,   218,   202,   577,   649,
     329,  -482,   453,   453,  -482,   612,   165,   308,   613,   646,
      57,   330,   722,   310,   832,    57,   330,   219,   339,   341,
     343,   220,   735,   530,   804,   810,   153,   349,   329,     3,
       4,   228,     6,   564,   232,   180,   566,   239,   549,   189,
     571,   572,   421,   573,   330,   319,   575,   422,   423,   353,
     267,   487,     1,   505,   570,   505,   424,   425,     3,     4,
     356,     6,   358,   153,   426,   427,   153,   432,   433,   153,
     153,   276,   338,   153,   741,   743,   276,   338,   366,   746,
     748,   458,   459,     1,   526,   373,   683,   670,   671,     3,
       4,   374,     6,   177,   166,     3,     4,   329,     6,   701,
     162,   340,   326,   379,   778,     3,     4,     3,     6,   387,
     235,   154,   323,   330,   154,   755,   459,   154,   154,   154,
     693,   154,   224,   224,   154,   674,   295,     3,     4,   276,
       6,   184,   223,   461,     1,   171,   393,   168,   396,   195,
       3,     4,   315,     6,     3,     4,   397,     6,   276,   223,
     728,    26,   406,   728,   400,   728,   654,   790,   342,   590,
     591,   592,   793,   276,   403,   814,   434,   816,   817,    57,
     435,     3,     4,   167,     6,   167,   368,   154,   164,   153,
     436,   503,   437,    43,  -481,     2,   472,     4,     5,     6,
      44,    45,   167,   473,    57,   796,   671,   658,   216,   507,
     756,   511,    26,   216,   314,   593,   594,   763,   686,   404,
     487,   510,   632,   512,   634,   519,   839,   542,   570,   452,
     524,   841,  -481,   276,   543,   487,   595,   596,    44,    45,
     678,   467,   468,   153,    43,   525,   452,   544,   153,   553,
     224,   545,   728,   693,   546,    44,    45,   547,   329,   601,
     602,   551,   412,   413,   338,   414,   338,   463,   465,   597,
     598,   599,   600,   552,   330,   323,   201,   667,   554,   669,
     557,   154,   560,   807,   559,   360,   799,   800,   565,   620,
     340,   154,   153,   805,   806,    49,   154,   578,   730,   626,
     628,   730,    49,   730,   830,   629,   812,     3,     4,   276,
       6,   276,   742,   276,   631,   633,   276,     1,   276,   276,
     636,    49,   753,     3,     4,   638,     6,    49,   166,   415,
     757,   639,   416,   179,   417,   577,   505,   641,   169,   216,
     216,   642,   643,   530,   216,   216,   644,   842,   153,   663,
      57,   153,   178,    49,   668,   676,     1,   677,    49,   463,
     153,   154,     3,     4,   154,     6,   154,   103,    60,   679,
     682,   487,   696,   224,   783,   179,   687,   463,   323,   684,
       1,   487,   776,   699,   705,    26,     3,     4,   786,     6,
     730,   197,   695,   697,   178,   616,   178,   153,   711,   715,
     795,   276,   797,    49,    49,   276,   717,   721,   154,   171,
     167,     3,     4,   609,     6,    42,   747,    43,   153,   720,
     809,   295,   216,   723,    44,    45,   465,   216,   727,   214,
     153,   731,   153,     1,   323,   463,    63,   323,   230,     3,
       4,   237,     6,   179,   312,   154,   738,   645,   178,    49,
     516,   750,   301,   154,   752,   759,   167,   760,   774,   761,
     766,    49,   276,   487,   276,   276,   154,   764,   835,    49,
       3,     4,   767,     6,   771,   162,     1,   779,   154,   772,
     154,   782,     3,     4,   313,     6,     1,   166,    49,   784,
     785,    49,     3,     4,     1,     6,   798,   579,   153,     2,
       3,     4,     5,     6,    49,   802,   811,   380,    49,   818,
      49,   813,   386,   276,   179,   295,   815,   819,   276,   822,
     833,   826,   838,    49,   487,     6,   487,   487,   837,     1,
     163,   840,   110,   178,     2,   681,     4,     5,     6,   700,
     605,   607,   402,   603,    26,   672,   154,   604,   606,   724,
     726,   460,   179,   164,    26,    49,   169,   655,   712,    54,
     515,   534,    26,   745,   836,   751,    98,   624,   580,   754,
     563,   178,   675,   614,   503,   487,    43,   765,   714,   713,
     487,     0,     0,    44,    45,     0,    43,   376,     0,     0,
       0,    54,     0,     0,    43,     0,     0,    26,     0,     0,
       0,    54,     0,     0,   179,   736,   737,   469,     0,     0,
     471,   176,     0,     0,    49,     0,     0,    54,    49,     1,
       0,     0,    54,     0,     0,     3,     4,     0,     6,    43,
     703,     0,     0,     0,     0,    49,   177,     0,     0,     0,
      49,     0,    54,     0,     0,     0,     0,     0,   529,   463,
       0,    49,     0,     1,   242,   243,   244,   107,     0,     3,
       4,   558,     6,     0,   327,     0,     1,    54,    54,     0,
       0,     2,   770,     4,     5,     6,     0,   465,     0,     0,
       0,     0,     0,     0,   246,   247,     0,    26,    49,     0,
       0,    49,     0,     0,    49,    49,    49,   248,    49,     0,
     249,    49,     0,   250,     0,     0,     0,     0,     1,   251,
       0,     0,     0,     2,     0,     4,     5,     6,     0,    43,
     252,    26,     0,     0,     0,    98,   253,     0,     3,     4,
     254,     6,   255,   659,    26,     0,   256,     0,   258,     0,
       0,   259,     0,     0,     0,     0,     0,     0,   176,     0,
       0,   260,     0,   261,    49,    54,     0,     0,     0,     0,
     262,   263,   264,   265,   266,   623,    43,   313,    54,     0,
       0,     0,    54,    49,    54,   652,    26,   834,     0,     0,
       0,     3,     4,     0,     6,     0,   527,    54,    49,     0,
     176,   333,   334,   335,    49,   438,   439,   440,   441,   442,
     443,   444,   445,     0,    49,   446,   447,     0,    43,     0,
       0,     0,   448,     0,     0,   201,     0,     0,     0,    49,
       0,     0,   657,     0,     0,   662,     0,     0,     0,     1,
     242,   243,   244,   107,     0,     3,     4,     0,     6,     0,
     327,     0,     0,     1,   333,   334,   335,     0,    49,     3,
       4,     0,     6,     0,   585,     0,     0,     0,    49,     0,
     246,   247,    54,    49,     0,     0,     0,     0,   528,     0,
       0,     0,     0,   248,     0,     0,   249,     1,     0,   250,
       0,     0,    54,     3,     4,   251,     6,     0,   708,     0,
       0,     0,     0,     0,     0,     0,   252,    26,   449,    54,
     450,     0,   253,     0,    54,     0,   254,    49,   255,     0,
       0,    26,   256,   257,   258,     0,     0,   259,     0,     0,
       0,     0,     0,     0,    49,   586,    49,   260,    49,   261,
       0,    49,     0,    49,    49,     0,   262,   263,   264,   265,
     266,     0,     0,    43,     0,    26,     0,     0,     0,   464,
     617,     0,     0,   740,     0,     0,   744,     0,   529,     0,
       0,   749,     0,    49,     0,    49,    49,     0,     0,     0,
       0,     0,     0,   581,     0,    49,   587,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,    49,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,   789,     0,   791,     0,
       0,   792,     0,   794,     0,    49,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,    54,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,    49,
      49,    54,     0,    54,     0,   820,     0,     0,   821,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     1,   242,   243,   244,   107,
       2,     3,     4,     5,     6,     0,   245,     0,    49,     0,
       0,     0,     0,    49,     0,     0,     0,     0,   702,   704,
       0,     0,     0,     0,   707,   709,   246,   247,     0,     0,
       8,     9,    10,   474,   475,     0,    11,    12,    13,   248,
     476,   477,   249,   478,    14,   250,     0,    15,    16,     0,
     182,   251,    19,   479,    20,   480,   481,    21,    22,    23,
      24,   482,   252,    26,     0,     0,     0,    27,   253,   483,
      28,    29,   254,    30,   255,    31,   484,     0,   256,   257,
     258,   485,    33,   259,    34,    35,    36,    37,    38,    39,
      40,    41,   486,   260,     0,   261,     0,     0,     0,     0,
       0,     0,   262,   263,   264,   265,   266,     0,     0,    54,
       0,     0,     0,     0,     0,   319,  -467,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   768,     0,     0,     0,     0,   769,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     1,   242,   243,   244,   107,
       2,     3,     4,     5,     6,     0,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   246,   247,     0,     0,
       8,     9,    10,   474,   475,    54,    11,    12,    13,   248,
     476,   477,   249,   478,    14,   250,     0,    15,    16,     0,
     182,   251,    19,   479,    20,   480,   481,    21,    22,    23,
      24,   482,   252,    26,     0,     0,     0,    27,   253,   483,
      28,    29,   254,    30,   255,    31,   484,     0,   256,   257,
     258,   485,    33,   259,    34,    35,    36,    37,    38,    39,
      40,    41,   486,   260,     0,   261,     0,     0,     0,     0,
       0,     0,   262,   263,   264,   265,   266,     0,     0,     0,
       0,     0,     1,     0,     0,   319,  -468,     2,     3,     4,
       5,     6,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,    10,
       0,     0,     0,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,    15,    16,    17,   182,     0,    19,
       0,    20,     0,     0,    21,    22,    23,    24,     0,     0,
      26,   333,   334,   335,    27,     0,     0,    28,    29,     0,
      30,     0,    31,     0,  -493,     0,     0,     0,     0,    33,
       0,    34,    35,    36,   336,    38,    39,    40,    41,     0,
      42,     0,    43,     0,     0,     0,     0,     0,     0,    44,
      45,     1,   242,   243,   244,   107,     2,     3,     4,     5,
       6,   337,   245,  -487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   247,     0,     0,     8,     9,    10,   474,
     475,     0,    11,    12,    13,   248,   476,   477,   249,   478,
      14,   250,     0,    15,    16,     0,   182,   251,    19,   479,
      20,   480,   481,    21,    22,    23,    24,   482,   252,    26,
       0,     0,     0,    27,   253,   483,    28,    29,   254,    30,
     255,    31,   484,     0,   256,   257,   258,   485,    33,   259,
      34,    35,    36,    37,    38,    39,    40,    41,   486,   260,
       0,   261,     0,     0,     0,     0,     0,     0,   262,   263,
     264,   265,   266,     0,     0,     0,     0,     1,     0,     0,
       0,   319,     2,     3,     4,     5,     6,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,    17,    18,     0,    19,     0,    20,     0,     0,    21,
      22,    23,    24,    25,     0,    26,     0,     0,     0,    27,
       0,     0,    28,    29,     0,    30,     0,    31,     0,    32,
       0,     0,     0,     0,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,     0,    43,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     1,   242,   243,
     244,   107,     0,     3,     4,     0,     6,   209,   327,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,     0,     0,   249,     0,     0,   250,     0,     0,
       0,     0,     0,   251,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   252,    26,     0,     0,     0,     0,
     253,     0,     0,     0,   254,     0,   255,     0,     0,     0,
     256,   257,   258,     1,     0,   259,     0,     0,     2,     3,
       4,     5,     6,     0,     7,   260,     0,   261,     0,     0,
       0,     0,     0,     0,   262,   263,   264,   265,   266,     0,
       0,     0,     0,     0,     0,     0,     0,   464,     0,     9,
      10,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,     0,   182,     0,
      19,     0,    20,     0,     0,    21,    22,    23,    24,     0,
       0,    26,     0,     0,     0,    27,     0,     0,    28,    29,
       0,    30,     0,    31,     0,     0,     0,     0,     0,     0,
      33,     0,    34,    35,    36,     0,    38,    39,    40,    41,
       0,    42,     0,    43,     0,     0,     0,     1,     0,     0,
      44,    45,     2,     3,     4,     5,     6,     0,     7,     0,
       0,     0,   183,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    10,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,     0,   182,     0,    19,     0,    20,     0,     0,    21,
      22,    23,    24,     0,     0,    26,     0,     0,     0,    27,
       0,     0,    28,    29,     0,    30,     0,    31,     0,     0,
       0,     0,     0,     0,    33,     0,    34,    35,    36,     0,
      38,    39,    40,    41,     0,    42,     0,    43,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,     2,
       3,     4,     5,     6,     0,   112,   513,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,     0,
       0,    10,     0,     0,     0,    11,    12,    13,     0,     0,
       0,   135,     0,    14,     0,     0,    15,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,    22,    23,     0,
       0,   136,     0,     0,     0,     0,     0,     0,     0,    28,
      29,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    36,     0,     0,    39,    40,
      41,     0,   137,     0,   138,   139,     0,     0,   140,   141,
     142,   143,   144,   145,     0,   146,   147,   148,   149,   150,
       0,     0,   151,     0,     0,     0,     0,   152,     1,   242,
     243,   244,   107,     2,     3,     4,     5,     6,     0,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     247,     0,     0,     0,     9,    10,     0,     0,     0,    11,
      12,    13,   248,     0,     0,   249,     0,    14,   250,     0,
      15,    16,     0,   182,   251,    19,     0,    20,     0,     0,
      21,    22,    23,    24,     0,   252,    26,     0,     0,     0,
      27,   253,     0,    28,    29,   254,    30,   255,    31,     0,
       0,   256,   257,   258,     0,    33,   259,    34,    35,    36,
       0,    38,    39,    40,    41,     0,   260,     0,   261,     0,
       0,     0,     0,     0,     0,   262,   263,   264,   265,   266,
       1,   242,   243,   244,   107,     2,     3,     4,     5,     6,
       0,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   247,     0,     0,     0,     0,    10,     0,     0,
       0,    11,    12,    13,   248,     0,     0,   249,     0,    14,
     250,     0,    15,     0,     0,     0,   251,    19,     0,     0,
       0,     0,     0,    22,    23,     0,     0,   252,    26,     0,
       0,     0,     0,   253,     0,    28,    29,   254,     0,   255,
      31,     0,     0,   256,   257,   258,     0,     0,   259,    34,
      35,    36,     0,     0,    39,    40,    41,     0,   260,     0,
     261,     0,     0,     0,     0,     0,     0,   262,   263,   264,
     265,   266,     1,   242,   243,   244,   107,     0,     3,     4,
       0,     6,     0,   327,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,     0,     0,   249,
       0,     0,   250,     0,     0,     0,     0,     0,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   252,
      26,     0,     0,     0,     0,   253,     0,     0,     0,   254,
       0,   255,     0,     0,     0,   256,     0,   258,     0,     0,
     259,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     260,     0,   261,   394,     0,     0,     0,     0,     0,   262,
     263,   264,   265,   266,     1,   242,   243,   244,   107,     0,
       3,     4,     0,     6,     0,   327,     0,     0,     1,   242,
     243,   244,   107,     0,     3,     4,     0,     6,     0,   327,
       0,     0,     0,     0,     0,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   246,
     247,   249,     0,     0,   250,     0,     0,     0,     0,     0,
     251,     0,   248,     0,     0,   249,     0,     0,   250,     0,
       0,   252,    26,     0,   251,     0,     0,   253,     0,     0,
       0,   254,     0,   255,     0,   252,    26,   256,   257,   258,
       0,   253,   259,     0,     0,   254,     0,   255,     0,     0,
       0,   256,   260,   258,   261,     0,   259,     0,     0,     0,
       0,   262,   263,   264,   265,   266,   260,     0,   261,   561,
       0,     0,     0,     0,     0,   262,   263,   264,   265,   266,
       1,   242,   243,   244,   107,     0,     3,     4,     0,     6,
       0,   327,     0,     0,     1,   242,   243,   244,   107,     0,
       3,     4,     0,     6,     0,   327,     0,     0,     0,     0,
       0,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   246,   247,   249,     0,     0,
     250,     0,     0,     0,     0,     0,   251,     0,   248,     0,
       0,   249,     0,     0,   250,     0,     0,   252,    26,     0,
     251,     0,     0,   253,     0,     0,     0,   254,     0,   255,
       0,   252,    26,   256,     0,   258,     0,   253,   259,     0,
       0,   254,     0,   255,     0,     0,     0,   256,   260,   258,
     261,     0,   259,     0,     0,     0,     0,   262,   263,   264,
     265,   266,   401,     0,   261,     0,     0,     0,     0,     0,
       0,   262,   263,   264,   265,   266,     1,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     9,    10,     0,     0,     0,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,    15,    16,
      17,    18,     0,    19,     0,    20,     0,     0,    21,    22,
      23,    24,    25,     0,    26,     0,     0,     0,    27,     0,
       0,    28,    29,     0,    30,     0,    31,     0,    32,     0,
       0,     0,     0,    33,     0,    34,    35,    36,    37,    38,
      39,    40,    41,     0,    42,     0,    43,     0,     0,     0,
     158,     1,     0,    44,    45,     0,     2,     3,     4,     5,
       6,     0,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     9,    10,     0,
       0,     0,    11,    12,    13,     0,     0,     0,     0,     0,
      14,     0,     0,    15,    16,    17,    18,     0,    19,     0,
      20,     0,     0,    21,    22,    23,    24,    25,     0,    26,
       0,     0,     0,    27,     0,     0,    28,    29,     0,    30,
       0,    31,     0,    32,     0,     0,     0,     0,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,     0,    42,
       0,    43,     0,     0,     0,     1,     0,     0,    44,    45,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    10,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,    15,    16,     0,
     182,     0,    19,     0,    20,     0,     0,    21,    22,    23,
      24,     0,     0,    26,     0,     0,     0,    27,     0,     0,
      28,    29,     0,    30,     0,    31,     0,     2,     3,     4,
       5,     6,    33,   112,    34,    35,    36,     0,    38,    39,
      40,    41,     0,   503,     0,    43,  -481,     0,     0,     0,
       0,     0,    44,    45,     0,     0,     0,     0,     0,    10,
       0,     0,     0,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,    15,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    22,    23,     2,     3,     4,
       5,     6,     0,   112,     0,     0,     0,    28,    29,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    35,    36,     0,     0,    39,    40,    41,    10,
     568,     0,     0,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,    15,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    22,    23,     0,     0,     0,
       2,     3,     4,     5,     6,   322,   112,    28,    29,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    35,    36,     0,     0,    39,    40,    41,     0,
     680,     9,    10,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,    15,    16,     0,
     182,     0,    19,     0,    20,     0,     0,    21,    22,    23,
      24,     0,     2,     3,     4,     5,     6,    27,   112,     0,
      28,    29,     0,    30,     0,    31,     0,     0,     0,     0,
       0,     0,    33,     0,    34,    35,    36,     0,    38,    39,
      40,    41,     0,     9,    10,     0,     0,     0,    11,   535,
      13,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,     0,   182,     0,    19,     0,    20,     0,     0,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,    29,     0,    30,     0,    31,     0,   536,
       0,     0,     0,     0,    33,     0,   537,    35,    36,     0,
      38,    39,    40,    41,     2,     3,     4,     5,     6,   648,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,    10,     0,     0,     0,
      11,    12,    13,     0,     0,     0,     0,     0,    14,     0,
       0,    15,    16,     0,   182,     0,    19,     0,    20,     0,
       0,    21,    22,    23,    24,     0,     0,     0,     0,     0,
       0,    27,     0,     0,    28,    29,     0,    30,     0,    31,
       0,     0,     0,     0,     0,     0,    33,     0,    34,    35,
      36,     0,    38,    39,    40,    41,     2,     3,     4,     5,
       6,   775,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,     0,
       0,     0,    11,    12,    13,     0,     0,     0,     0,     0,
      14,     0,     0,    15,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,    22,    23,     2,     3,     4,     5,
       6,     0,   112,     0,     0,     0,    28,    29,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,    36,     0,     0,    39,    40,    41,    10,     0,
       0,     0,    11,    12,    13,     0,     0,     0,     0,     0,
      14,     0,     0,    15,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    29,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,    36,     0,     0,    39,    40,    41
};

static const yytype_int16 yycheck[] =
{
       0,   174,    44,   171,    32,   192,    42,     7,   194,   177,
     187,    26,   353,   193,   483,    15,   187,   188,     0,   345,
     196,   196,   196,   473,   194,    63,    26,    63,    14,   196,
      58,   452,    32,   201,     0,   155,   681,    37,     3,   464,
      14,    13,    42,     3,     9,    15,    33,    83,    89,     3,
      32,   646,   636,   305,   638,   297,     9,    10,    58,    12,
      89,     9,    10,    63,    12,   475,    36,    46,    18,   163,
       9,    10,   101,    12,    26,    14,    58,    15,   622,   120,
     108,   323,   503,    83,   101,   101,     0,    25,   104,    89,
     101,   120,   121,   637,   123,    50,     7,   246,   247,     3,
     249,   511,    50,   103,   121,   225,   516,   260,   108,   109,
       3,    71,   112,   262,   263,    70,   761,    71,    32,    98,
     214,    14,    70,   310,   311,    85,   108,   109,     7,   171,
     279,    85,   119,    14,   544,   177,   122,   109,   232,   154,
     234,   725,    14,   103,    58,   397,    57,   241,   122,   103,
     110,    89,   102,   798,   154,   155,    14,    96,   123,   201,
     196,   161,   162,   163,   164,   103,   166,    71,   106,   345,
     345,   345,   109,   173,   174,   109,   771,   297,   345,     9,
      10,    10,    12,    12,    14,   122,   120,   528,    99,   189,
     101,   478,   109,   193,   108,   109,   196,   197,   524,   103,
     228,   102,   154,   323,   102,   122,   493,   109,   109,   209,
       0,   109,   807,   213,   214,   215,     9,    10,    89,    12,
     122,    14,   174,   223,   121,   225,   123,   209,   228,   102,
     260,   213,   232,   215,   102,   235,   109,   687,    30,    31,
     389,   109,   153,   209,   107,   245,   228,   102,   401,   120,
     121,   189,   123,   406,   109,   166,   123,   102,   196,   197,
     260,   199,   105,   416,   109,    85,   109,   303,   206,   207,
     419,   420,    46,   528,   368,   123,   370,   102,   533,   193,
     110,   111,   196,     3,   109,   323,   459,   323,   382,   475,
     715,   229,   213,   102,   215,   209,   449,   297,   485,   213,
     109,   215,   340,   303,   340,   475,   105,   123,   260,   345,
     109,   104,   312,    87,   228,   107,   108,   110,   111,   319,
     104,   102,   663,   323,    98,   511,   104,   238,   109,   509,
     516,   101,   452,   453,   104,   101,   336,   514,   104,   507,
     340,   511,   629,   514,   813,   345,   516,   102,   524,   524,
     524,   105,   639,   353,   764,   776,   356,   524,   544,     9,
      10,   108,    12,   393,    14,   276,   396,   102,   368,   120,
     400,   401,   110,   403,   544,   123,   406,   115,   116,   120,
     553,   319,     3,   503,   399,   505,   112,   113,     9,    10,
     107,    12,   102,   393,    24,    25,   396,    28,    29,   399,
     400,   401,   340,   403,   659,   660,   406,   345,   124,   664,
     665,   108,   109,     3,   352,   105,   565,   108,   109,     9,
      10,   105,    12,   110,    14,     9,    10,   613,    12,   578,
      14,   345,   612,   122,   721,     9,    10,     9,    12,   122,
      14,   393,   356,   613,   396,   108,   109,   399,   400,   401,
     570,   403,   452,   453,   406,   549,   174,     9,    10,   459,
      12,   499,    14,   499,     3,   507,   107,   503,   107,   505,
       9,    10,   472,    12,     9,    10,   101,    12,   478,    14,
     633,    71,   101,   636,   107,   638,   522,   742,   524,   421,
     422,   423,   747,   493,   107,   782,   111,   784,   785,   499,
     117,     9,    10,   503,    12,   505,    14,   459,    92,   509,
     118,   101,    32,   103,   104,     8,   109,    10,    11,    12,
     110,   111,   522,   101,   524,   108,   109,   527,   528,   102,
     679,   120,    71,   533,   472,   424,   425,   690,   568,   257,
     478,   105,   480,   122,   482,   122,   833,   122,   563,   101,
     120,   838,   104,   553,   109,   493,   426,   427,   110,   111,
     560,   310,   311,   563,   103,   124,   101,   121,   568,   107,
     570,   124,   725,   693,   124,   110,   111,   124,   764,   432,
     433,   122,    34,    35,   522,    37,   524,   305,   306,   428,
     429,   430,   431,   124,   764,   509,   110,   535,   122,   537,
     122,   553,    14,   771,   122,   543,   759,   760,   105,    43,
     524,   563,   612,   766,   767,     0,   568,   102,   633,   122,
     122,   636,     7,   638,   811,   120,   779,     9,    10,   629,
      12,   631,    14,   633,   101,   101,   636,     3,   638,   639,
     101,    26,   670,     9,    10,   101,    12,    32,    14,   101,
     680,   120,   104,    57,   106,   109,   776,   122,    43,   659,
     660,   124,   121,   663,   664,   665,   121,   840,   668,   109,
     670,   671,    57,    58,   107,   122,     3,   122,    63,   397,
     680,   633,     9,    10,   636,    12,   638,    14,   670,   105,
     108,   629,   102,   693,   730,    99,   101,   415,   612,   108,
       3,   639,   717,   102,   102,    71,     9,    10,   738,    12,
     725,    14,   108,   108,    99,   109,   101,   717,   102,   109,
     750,   721,   752,   108,   109,   725,   101,   120,   680,   771,
     730,     9,    10,   451,    12,   101,    14,   103,   738,   102,
     776,   459,   742,   100,   110,   111,   464,   747,   122,   121,
     750,   122,   752,     3,   668,   473,   670,   671,   162,     9,
      10,   165,    12,   167,    14,   717,   101,    87,   153,   154,
     121,   121,   176,   725,   121,   101,   776,   101,   124,   102,
     101,   166,   782,   721,   784,   785,   738,   104,   818,   174,
       9,    10,   101,    12,   102,    14,     3,   101,   750,   105,
     752,   102,     9,    10,   189,    12,     3,    14,   193,   102,
     102,   196,     9,    10,     3,    12,   102,    14,   818,     8,
       9,    10,    11,    12,   209,   102,   102,   231,   213,   109,
     215,   122,   236,   833,   238,   553,   121,   102,   838,    45,
      54,   105,   102,   228,   782,    12,   784,   785,   122,     3,
      69,   121,    25,   238,     8,   563,    10,    11,    12,   577,
     436,   448,   254,   434,    71,   543,   818,   435,   437,   631,
     631,   303,   276,    92,    71,   260,   261,   522,   612,     0,
     340,   355,    71,   663,   822,   668,     7,   472,    85,   671,
     390,   276,   553,   459,   101,   833,   103,   693,   616,   613,
     838,    -1,    -1,   110,   111,    -1,   103,   225,    -1,    -1,
      -1,    32,    -1,    -1,   103,    -1,    -1,    71,    -1,    -1,
      -1,    42,    -1,    -1,   328,   643,   644,   312,    -1,    -1,
     315,    85,    -1,    -1,   319,    -1,    -1,    58,   323,     3,
      -1,    -1,    63,    -1,    -1,     9,    10,    -1,    12,   103,
      14,    -1,    -1,    -1,    -1,   340,   110,    -1,    -1,    -1,
     345,    -1,    83,    -1,    -1,    -1,    -1,    -1,   353,   687,
      -1,   356,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,   385,    12,    -1,    14,    -1,     3,   108,   109,    -1,
      -1,     8,   710,    10,    11,    12,    -1,   715,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    71,   393,    -1,
      -1,   396,    -1,    -1,   399,   400,   401,    47,   403,    -1,
      50,   406,    -1,    53,    -1,    -1,    -1,    -1,     3,    59,
      -1,    -1,    -1,     8,    -1,    10,    11,    12,    -1,   103,
      70,    71,    -1,    -1,    -1,   166,    76,    -1,     9,    10,
      80,    12,    82,    14,    71,    -1,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,   101,    -1,   103,   459,   196,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   470,   103,   472,   209,    -1,
      -1,    -1,   213,   478,   215,   125,    71,   815,    -1,    -1,
      -1,     9,    10,    -1,    12,    -1,    14,   228,   493,    -1,
      85,    72,    73,    74,   499,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,   509,    26,    27,    -1,   103,    -1,
      -1,    -1,    33,    -1,    -1,   110,    -1,    -1,    -1,   524,
      -1,    -1,   527,    -1,    -1,   530,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    12,    -1,
      14,    -1,    -1,     3,    72,    73,    74,    -1,   553,     9,
      10,    -1,    12,    -1,    14,    -1,    -1,    -1,   563,    -1,
      34,    35,   303,   568,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,     3,    -1,    53,
      -1,    -1,   323,     9,    10,    59,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,   119,   340,
     121,    -1,    76,    -1,   345,    -1,    80,   612,    82,    -1,
      -1,    71,    86,    87,    88,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,   629,    85,   631,   101,   633,   103,
      -1,   636,    -1,   638,   639,    -1,   110,   111,   112,   113,
     114,    -1,    -1,   103,    -1,    71,    -1,    -1,    -1,   123,
     124,    -1,    -1,   658,    -1,    -1,   661,    -1,   663,    -1,
      -1,   666,    -1,   668,    -1,   670,   671,    -1,    -1,    -1,
      -1,    -1,    -1,   414,    -1,   680,   417,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   717,    -1,    -1,    -1,   721,    -1,    -1,    -1,
     725,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   738,    -1,    -1,   741,    -1,   743,    -1,
      -1,   746,    -1,   748,    -1,   750,    -1,   752,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   499,    -1,
      -1,    -1,   503,    -1,   505,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   782,    -1,   784,
     785,   522,    -1,   524,    -1,   790,    -1,    -1,   793,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   818,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,   833,    -1,
      -1,    -1,    -1,   838,    -1,    -1,    -1,    -1,   579,   580,
      -1,    -1,    -1,    -1,   585,   586,    34,    35,    -1,    -1,
      38,    39,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,    -1,    -1,   670,
      -1,    -1,    -1,    -1,    -1,   123,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   703,    -1,    -1,    -1,    -1,   708,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   730,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      38,    39,    40,    41,    42,   776,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,   123,   124,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,    60,
      -1,    62,    -1,    -1,    65,    66,    67,    68,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    -1,    78,    79,    -1,
      81,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
     101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   122,    14,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    38,    39,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      -1,   123,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    57,    58,    -1,    60,    -1,    62,    -1,    -1,    65,
      66,    67,    68,    69,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,   101,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,    -1,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    12,   123,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,
      86,    87,    88,     3,    -1,    91,    -1,    -1,     8,     9,
      10,    11,    12,    -1,    14,   101,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    39,
      40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    55,    56,    -1,    58,    -1,
      60,    -1,    62,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,   101,    -1,   103,    -1,    -1,    -1,     3,    -1,    -1,
     110,   111,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    -1,    58,    -1,    60,    -1,    62,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    -1,    81,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,   101,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,    -1,    -1,    -1,     8,
       9,    10,    11,    12,    -1,    14,   122,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    50,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    -1,    -1,    97,    98,
      99,    -1,   101,    -1,   103,   104,    -1,    -1,   107,   108,
     109,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
      -1,    -1,   121,    -1,    -1,    -1,    -1,   126,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    58,    59,    60,    -1,    62,    -1,    -1,
      65,    66,    67,    68,    -1,    70,    71,    -1,    -1,    -1,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,    86,    87,    88,    -1,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,   101,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    -1,    52,
      53,    -1,    55,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    70,    71,    -1,
      -1,    -1,    -1,    76,    -1,    78,    79,    80,    -1,    82,
      83,    -1,    -1,    86,    87,    88,    -1,    -1,    91,    92,
      93,    94,    -1,    -1,    97,    98,    99,    -1,   101,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,
      -1,    82,    -1,    -1,    -1,    86,    -1,    88,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,   103,   104,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    12,    -1,    14,    -1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    34,
      35,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,    -1,
      -1,    70,    71,    -1,    59,    -1,    -1,    76,    -1,    -1,
      -1,    80,    -1,    82,    -1,    70,    71,    86,    87,    88,
      -1,    76,    91,    -1,    -1,    80,    -1,    82,    -1,    -1,
      -1,    86,   101,    88,   103,    -1,    91,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   101,    -1,   103,   104,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    -1,    -1,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    34,    35,    50,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    59,    -1,    47,    -1,
      -1,    50,    -1,    -1,    53,    -1,    -1,    70,    71,    -1,
      59,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    82,
      -1,    70,    71,    86,    -1,    88,    -1,    76,    91,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    86,   101,    88,
     103,    -1,    91,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,     3,    -1,    -1,    -1,
      -1,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,
      57,    58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,
      67,    68,    69,    -1,    71,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    -1,    81,    -1,    83,    -1,    85,    -1,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,   101,    -1,   103,    -1,    -1,    -1,
     107,     3,    -1,   110,   111,    -1,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    55,    56,    57,    58,    -1,    60,    -1,
      62,    -1,    -1,    65,    66,    67,    68,    69,    -1,    71,
      -1,    -1,    -1,    75,    -1,    -1,    78,    79,    -1,    81,
      -1,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,   101,
      -1,   103,    -1,    -1,    -1,     3,    -1,    -1,   110,   111,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,
      58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,    79,    -1,    81,    -1,    83,    -1,     8,     9,    10,
      11,    12,    90,    14,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,   101,    -1,   103,   104,    -1,    -1,    -1,
      -1,    -1,   110,   111,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    78,    79,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    -1,    -1,    97,    98,    99,    40,
     101,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    78,    79,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    -1,    -1,    97,    98,    99,    -1,
     101,    39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,
      58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,
      68,    -1,     8,     9,    10,    11,    12,    75,    14,    -1,
      78,    79,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    39,    40,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    -1,    58,    -1,    60,    -1,    62,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,
      96,    97,    98,    99,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    55,    56,    -1,    58,    -1,    60,    -1,    62,    -1,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    78,    79,    -1,    81,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    99,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    66,    67,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    78,    79,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    -1,    -1,    97,    98,    99,    40,    -1,
      -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    -1,    -1,    97,    98,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,     8,     9,    10,    11,    12,    14,    38,    39,
      40,    44,    45,    46,    52,    55,    56,    57,    58,    60,
      62,    65,    66,    67,    68,    69,    71,    75,    78,    79,
      81,    83,    85,    90,    92,    93,    94,    95,    96,    97,
      98,    99,   101,   103,   110,   111,   128,   129,   130,   131,
     132,   133,   134,   141,   143,   144,   145,   146,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   202,   203,   204,   205,   206,   208,   210,   211,   212,
     213,   216,   217,   218,   220,   221,   229,   234,   235,   236,
     247,   254,   256,   260,   263,   264,   273,   294,   143,   146,
     196,   274,   101,    14,   131,   134,   146,     7,   139,   123,
     130,   134,    14,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    50,    70,   101,   103,   104,
     107,   108,   109,   110,   111,   112,   114,   115,   116,   117,
     118,   121,   126,   146,   194,   223,   248,   255,   107,   187,
      14,   276,    14,    69,    92,   146,    14,   146,   216,   131,
     219,   220,    14,    14,   107,     0,    85,   110,   131,   144,
     196,   187,    58,   122,   190,   214,   215,   216,    89,   120,
     250,   266,   289,   101,   104,   216,   123,    14,   134,   146,
      85,   110,   196,   196,   139,   134,   146,   123,   134,   123,
     187,   207,   273,   123,   121,   123,   146,   104,   104,   102,
     105,   223,   287,    14,   146,   218,   249,   293,   108,   146,
     144,   146,    14,   129,   146,    14,   146,   144,   146,   102,
     219,   146,     4,     5,     6,    14,    34,    35,    47,    50,
      53,    59,    70,    76,    80,    82,    86,    87,    88,    91,
     101,   103,   110,   111,   112,   113,   114,   133,   135,   136,
     137,   138,   139,   140,   142,   143,   146,   147,   149,   150,
     151,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   222,   223,   261,   262,
     270,   144,   219,   109,   122,   101,   121,   231,   266,   284,
     289,   289,    14,   131,   134,   146,   251,   252,   253,   123,
     178,   230,    13,   191,   226,   227,   228,    14,   146,   169,
     170,   174,   285,    72,    73,    74,    95,   122,   134,   145,
     191,   210,   216,   229,   237,   238,   239,   240,   246,   256,
     291,   134,   146,   120,   243,   134,   107,   219,   102,   134,
     134,   199,   200,   201,   283,   273,   124,   207,    14,   129,
     146,   209,   207,   105,   105,   146,   293,   187,   134,   122,
     144,   129,   146,   122,   129,   146,   144,   122,   129,    50,
      70,   158,   158,   107,   104,   158,   107,   101,   152,   277,
     107,   101,   149,   107,   171,   296,   101,   171,   173,   222,
     158,   158,    34,    35,    37,   101,   104,   106,   158,    15,
      36,   110,   115,   116,   112,   113,    24,    25,    30,    31,
     107,   108,    28,    29,   111,   117,   118,    32,    16,    17,
      18,    19,    20,    21,    22,    23,    26,    27,    33,   119,
     121,   172,   101,   218,   224,   225,   286,   288,   108,   109,
     215,   216,   148,   171,   123,   171,   232,   230,   230,   131,
     146,   131,   109,   101,    41,    42,    48,    49,    51,    61,
      63,    64,    69,    77,    84,    89,   100,   134,   173,   175,
     176,   177,   178,   179,   180,   182,   184,   185,   188,   191,
     265,   280,   281,   101,   216,   218,   286,   102,    13,   109,
     105,   120,   122,   122,   216,   239,   121,   241,   242,   122,
     292,   291,   109,   122,   120,   124,   134,    14,    96,   131,
     146,   244,   245,   246,   243,    45,    85,    92,   228,   257,
     258,   259,   122,   109,   121,   124,   124,   124,   129,   146,
     129,   122,   124,   107,   122,   122,   129,   122,   144,   122,
      14,   104,   158,   277,   222,   105,   222,   148,   101,   153,
     223,   222,   222,   222,   173,   222,   102,   109,   102,    14,
      85,   143,   148,   275,   173,    14,    85,   143,   158,   158,
     159,   159,   159,   160,   160,   161,   161,   162,   162,   162,
     162,   163,   163,   164,   165,   166,   167,   168,   173,   171,
     224,   286,   101,   104,   262,   102,   109,   124,   232,   233,
      43,   267,   268,   131,   251,   275,   122,   174,   122,   120,
     175,   101,   134,   101,   134,   280,   101,   178,   101,   120,
     175,   122,   124,   121,   121,    87,   219,   271,    13,   228,
     174,   122,   125,   174,   216,   240,   291,   131,   146,    14,
     246,   274,   131,   109,    14,    96,   274,   134,   107,   134,
     108,   109,   200,   174,   129,   261,   122,   122,   146,   105,
     101,   153,   108,   158,   108,   102,   222,   101,   156,   278,
     104,   154,   155,   218,   279,   108,   102,   108,   102,   102,
     171,   158,   143,    14,   143,   102,   105,   143,    14,   143,
     120,   102,   226,   285,   171,   109,   290,   101,   267,   295,
     102,   120,   175,   100,   177,   183,   189,   122,   173,   181,
     223,   122,   181,   267,   181,   175,   171,   171,   101,   271,
     131,   274,    14,   274,   131,   245,   274,    14,   274,   131,
     121,   257,   121,   187,   258,   108,   158,   222,   278,   101,
     101,   102,   275,   173,   104,   279,   101,   101,   143,   143,
     171,   102,   105,   232,   124,    13,   223,   269,   175,   101,
     181,   282,   102,   216,   102,   102,   222,   272,   297,   131,
     274,   131,   131,   274,   131,   222,   108,   222,   102,   173,
     173,   278,   102,   105,   174,   173,   173,   219,   271,   216,
     224,   102,   173,   122,   175,   121,   175,   175,   109,   102,
     131,   131,    45,   278,   102,   102,   105,   102,   102,   271,
     178,   102,   280,    54,   171,   222,   134,   122,   102,   175,
     121,   175,   133
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
#line 3024 "y.tab.c"
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
#line 1176 "120gram.y"

/*
static void yyerror(char *s)
{
	fprintf(stderr, "%d: %s\n", lineno, s);
}*/

void yyerror(char *s)
{
   errors++;
   fprintf(stderr, "error #%d: %s, line: %d ", errors, fname, lineno);
	if(e_message){
		if(s != NULL) fprintf(stderr, "%s\t\'%s\' %s\n",e_message->errorType, s, e_message->message);
		else fprintf(stderr, "%s\t%s\n",e_message->errorType, e_message->message);
	} else {fprintf(stderr, "\n");}
	fflush(stderr);
}

/*
int main(void)
{
	lineno = 1;
	yyparse();

	return 0;
}*/

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

