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

#include "errors.h"
#include "token.h"
#include "120parse.h"
#include "parsedef.h"

extern int lineno;
extern Token *yytoken;
int yydebug=1;
FILE *yyin;
char *fname;
int errors;
ErrorMessage *e_message;

//static void yyerror(char *s);


/* Line 189 of yacc.c  */
#line 95 "y.tab.c"

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
#line 75 "120gram.y"

	Token *t;
	struct TreeNode *n;



/* Line 214 of yacc.c  */
#line 340 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 352 "y.tab.c"

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
#define YYLAST   4041

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  128
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  171
/* YYNRULES -- Number of rules.  */
#define YYNRULES  502
/* YYNRULES -- Number of states.  */
#define YYNSTATES  842

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
     879,   885,   890,   895,   899,   901,   904,   906,   909,   913,
     917,   922,   924,   927,   929,   931,   933,   936,   940,   943,
     946,   949,   952,   954,   961,   967,   973,   978,   983,   987,
     990,   992,   994,   995,   999,  1001,  1005,  1008,  1013,  1016,
    1021,  1025,  1030,  1033,  1037,  1039,  1042,  1046,  1048,  1053,
    1056,  1058,  1062,  1067,  1070,  1074,  1078,  1083,  1085,  1087,
    1089,  1092,  1096,  1100,  1103,  1106,  1108,  1111,  1114,  1116,
    1118,  1120,  1124,  1125,  1127,  1130,  1133,  1137,  1140,  1143,
    1146,  1148,  1152,  1156,  1159,  1162,  1164,  1170,  1175,  1180,
    1184,  1190,  1195,  1200,  1204,  1206,  1208,  1210,  1213,  1216,
    1219,  1222,  1224,  1228,  1233,  1237,  1240,  1243,  1245,  1247,
    1250,  1252,  1254,  1258,  1262,  1264,  1266,  1268,  1270,  1272,
    1274,  1276,  1278,  1280,  1282,  1284,  1286,  1288,  1290,  1292,
    1294,  1296,  1298,  1300,  1302,  1304,  1306,  1308,  1310,  1312,
    1314,  1316,  1318,  1320,  1322,  1324,  1326,  1328,  1330,  1332,
    1334,  1337,  1340,  1347,  1349,  1353,  1355,  1357,  1360,  1365,
    1368,  1373,  1380,  1389,  1394,  1396,  1400,  1402,  1404,  1406,
    1409,  1414,  1418,  1423,  1426,  1432,  1435,  1438,  1440,  1442,
    1445,  1450,  1452,  1456,  1457,  1459,  1460,  1462,  1463,  1465,
    1466,  1468,  1469,  1471,  1472,  1474,  1475,  1477,  1478,  1480,
    1481,  1483,  1484,  1486,  1487,  1489,  1490,  1492,  1493,  1495,
    1496,  1498,  1499,  1501,  1502,  1504,  1505,  1507,  1508,  1510,
    1511,  1513,  1514,  1516,  1517,  1519,  1520,  1522,  1523,  1525,
    1526,  1528,  1529
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
     218,   105,   286,   106,    -1,   102,   217,   103,    -1,   111,
      -1,   111,   220,    -1,   112,    -1,   147,   111,    -1,   147,
     111,   220,    -1,    14,   147,   111,    -1,    14,   147,   111,
     220,    -1,   221,    -1,   221,   220,    -1,    46,    -1,    98,
      -1,   144,    -1,    14,   144,    -1,    14,   147,   197,    -1,
      14,   197,    -1,   224,   287,    -1,   195,   288,    -1,   219,
     287,    -1,   226,    -1,   289,   102,   227,   103,   220,   272,
      -1,   289,   102,   227,   103,   220,    -1,   289,   102,   227,
     103,   272,    -1,   289,   102,   227,   103,    -1,   289,   105,
     286,   106,    -1,   102,   225,   103,    -1,   228,    13,    -1,
     228,    -1,    13,    -1,    -1,   228,   110,    13,    -1,   229,
      -1,   228,   110,   229,    -1,   192,   217,    -1,   192,   217,
     122,   172,    -1,   192,   287,    -1,   192,   287,   122,   172,
      -1,   217,   290,   231,    -1,   192,   217,   290,   231,    -1,
     217,   267,    -1,   192,   217,   267,    -1,   179,    -1,   122,
     233,    -1,   102,   149,   103,    -1,   172,    -1,   124,   234,
     291,   125,    -1,   124,   125,    -1,   233,    -1,   234,   110,
     233,    -1,   236,   124,   292,   125,    -1,   237,   135,    -1,
     237,   135,   244,    -1,   237,   147,   135,    -1,   237,   147,
     135,   244,    -1,    45,    -1,    83,    -1,    93,    -1,   239,
     292,    -1,   247,   121,   292,    -1,   192,   240,   123,    -1,
     192,   123,    -1,   240,   123,    -1,   123,    -1,   230,   293,
      -1,   146,   123,    -1,   211,    -1,   257,    -1,   241,    -1,
     240,   110,   241,    -1,    -1,   217,    -1,   217,   242,    -1,
     217,   243,    -1,   135,   121,   175,    -1,   122,   126,    -1,
     122,   175,    -1,   121,   245,    -1,   246,    -1,   245,   110,
     246,    -1,    14,   147,   132,    -1,    14,   132,    -1,   147,
     132,    -1,   132,    -1,    96,   247,    14,   275,   132,    -1,
      96,   247,   275,   132,    -1,    96,    14,   275,   132,    -1,
      96,   275,   132,    -1,   247,    96,    14,   275,   132,    -1,
     247,    96,   275,   132,    -1,   247,    14,   275,   132,    -1,
     247,   275,   132,    -1,    72,    -1,    73,    -1,    74,    -1,
      71,   249,    -1,   224,   294,    -1,   219,   294,    -1,   121,
     252,    -1,   253,    -1,   253,   110,   252,    -1,   254,   102,
     276,   103,    -1,    14,   147,   132,    -1,    14,   132,    -1,
     147,   132,    -1,   132,    -1,   135,    -1,    71,   256,    -1,
      70,    -1,    50,    -1,    70,   105,   106,    -1,    50,   105,
     106,    -1,   113,    -1,   127,    -1,   111,    -1,   116,    -1,
     117,    -1,   118,    -1,   112,    -1,   119,    -1,   104,    -1,
     115,    -1,   122,    -1,   108,    -1,   109,    -1,    16,    -1,
      17,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,
      32,    -1,    33,    -1,    34,    -1,    35,    -1,   110,    -1,
      36,    -1,    37,    -1,   102,   103,    -1,   105,   106,    -1,
     295,    85,   108,   258,   109,   188,    -1,   259,    -1,   258,
     110,   259,    -1,   260,    -1,   229,    -1,    45,   135,    -1,
      45,   135,   122,   223,    -1,    92,   135,    -1,    92,   135,
     122,   223,    -1,    85,   108,   258,   109,    45,   135,    -1,
      85,   108,   258,   109,    45,   135,   122,   134,    -1,   134,
     108,   262,   109,    -1,   263,    -1,   262,   110,   263,    -1,
     172,    -1,   223,    -1,   134,    -1,    85,   188,    -1,    85,
     108,   109,   188,    -1,    89,   179,   268,    -1,    89,   290,
     231,   268,    -1,   269,   296,    -1,    43,   102,   270,   103,
     179,    -1,   224,   217,    -1,   224,   225,    -1,   224,    -1,
      13,    -1,    87,   297,    -1,    87,   102,   298,   103,    -1,
     223,    -1,   273,   110,   223,    -1,    -1,   187,    -1,    -1,
     147,    -1,    -1,   149,    -1,    -1,    14,    -1,    -1,   153,
      -1,    -1,   157,    -1,    -1,   155,    -1,    -1,   174,    -1,
      -1,   180,    -1,    -1,   182,    -1,    -1,   200,    -1,    -1,
     232,    -1,    -1,   175,    -1,    -1,   225,    -1,    -1,   224,
      -1,    -1,   226,    -1,    -1,   251,    -1,    -1,   110,    -1,
      -1,   238,    -1,    -1,   123,    -1,    -1,   250,    -1,    -1,
      57,    -1,    -1,   268,    -1,    -1,   172,    -1,    -1,   273,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   145,   150,   155,   156,   161,   166,   174,
     178,   179,   180,   181,   182,   186,   190,   194,   198,   202,
     203,   211,   219,   220,   221,   222,   226,   227,   231,   232,
     233,   234,   238,   239,   243,   244,   245,   246,   250,   251,
     252,   253,   255,   256,   257,   258,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   274,   275,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   292,
     293,   294,   295,   299,   301,   303,   305,   310,   314,   318,
     319,   323,   324,   328,   332,   333,   334,   335,   339,   340,
     344,   345,   346,   350,   351,   352,   353,   357,   358,   359,
     363,   364,   365,   369,   370,   371,   372,   373,   377,   378,
     379,   383,   384,   388,   389,   393,   394,   398,   399,   404,
     405,   409,   410,   415,   416,   418,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   436,   437,   441,
     449,   450,   451,   452,   453,   454,   455,   456,   460,   461,
     462,   466,   470,   474,   475,   479,   480,   481,   485,   486,
     491,   492,   493,   498,   499,   503,   504,   505,   506,   510,
     518,   519,   523,   524,   525,   526,   527,   528,   529,   533,
     534,   535,   536,   537,   541,   542,   546,   547,   548,   549,
     550,   554,   555,   559,   560,   561,   562,   563,   567,   568,
     569,   573,   574,   575,   576,   577,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   599,   600,   601,   605,   606,   607,   608,   609,   610,
     612,   623,   627,   628,   632,   633,   637,   652,   653,   657,
     658,   662,   666,   671,   675,   685,   690,   691,   692,   693,
     697,   699,   701,   703,   704,   708,   710,   711,   713,   717,
     721,   722,   730,   731,   735,   739,   740,   744,   745,   747,
     749,   751,   753,   754,   758,   759,   760,   761,   762,   763,
     764,   769,   770,   774,   775,   779,   780,   781,   782,   786,
     790,   794,   795,   799,   801,   803,   805,   807,   809,   813,
     814,   815,   816,   817,   821,   822,   827,   828,   830,   831,
     836,   837,   839,   840,   844,   848,   849,   853,   854,   855,
     859,   860,   868,   872,   873,   874,   875,   880,   881,   882,
     886,   887,   891,   892,   893,   894,   895,   896,   897,   898,
     902,   903,   906,   907,   908,   909,   910,   919,   923,   931,
     935,   936,   940,   941,   942,   943,   944,   946,   948,   950,
     951,   953,   955,   957,   962,   963,   964,   972,   976,   980,
     984,   988,   989,   993,   997,   998,   999,  1000,  1001,  1009,
    1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,
    1043,  1044,  1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,  1054,  1062,  1067,  1068,  1072,  1073,  1077,  1078,  1079,
    1080,  1081,  1083,  1088,  1092,  1093,  1097,  1098,  1099,  1103,
    1107,  1115,  1119,  1123,  1127,  1132,  1133,  1134,  1135,  1139,
    1143,  1147,  1148,  1156,  1157,  1161,  1162,  1166,  1167,  1171,
    1172,  1176,  1177,  1181,  1182,  1186,  1187,  1191,  1192,  1196,
    1197,  1201,  1202,  1206,  1207,  1211,  1212,  1216,  1217,  1221,
    1222,  1226,  1227,  1231,  1232,  1236,  1237,  1241,  1242,  1246,
    1247,  1251,  1252,  1256,  1257,  1261,  1262,  1266,  1267,  1271,
    1272,  1276,  1277
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
     218,   218,   218,   218,   219,   219,   219,   219,   219,   219,
     219,   220,   220,   221,   221,   222,   222,   222,   222,   223,
     224,   225,   225,   226,   226,   226,   226,   226,   226,   227,
     227,   227,   227,   227,   228,   228,   229,   229,   229,   229,
     230,   230,   230,   230,   231,   232,   232,   233,   233,   233,
     234,   234,   235,   236,   236,   236,   236,   237,   237,   237,
     238,   238,   239,   239,   239,   239,   239,   239,   239,   239,
     240,   240,   241,   241,   241,   241,   241,   242,   243,   244,
     245,   245,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   247,   247,   247,   248,   249,   250,
     251,   252,   252,   253,   254,   254,   254,   254,   254,   255,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   257,   258,   258,   259,   259,   260,   260,   260,
     260,   260,   260,   261,   262,   262,   263,   263,   263,   264,
     265,   266,   267,   268,   269,   270,   270,   270,   270,   271,
     272,   273,   273,   274,   274,   275,   275,   276,   276,   277,
     277,   278,   278,   279,   279,   280,   280,   281,   281,   282,
     282,   283,   283,   284,   284,   285,   285,   286,   286,   287,
     287,   288,   288,   289,   289,   290,   290,   291,   291,   292,
     292,   293,   293,   294,   294,   295,   295,   296,   296,   297,
     297,   298,   298
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
       5,     4,     4,     3,     1,     2,     1,     2,     3,     3,
       4,     1,     2,     1,     1,     1,     2,     3,     2,     2,
       2,     2,     1,     6,     5,     5,     4,     4,     3,     2,
       1,     1,     0,     3,     1,     3,     2,     4,     2,     4,
       3,     4,     2,     3,     1,     2,     3,     1,     4,     2,
       1,     3,     4,     2,     3,     3,     4,     1,     1,     1,
       2,     3,     3,     2,     2,     1,     2,     2,     1,     1,
       1,     3,     0,     1,     2,     2,     3,     2,     2,     2,
       1,     3,     3,     2,     2,     1,     5,     4,     4,     3,
       5,     4,     4,     3,     1,     1,     1,     2,     2,     2,
       2,     1,     3,     4,     3,     2,     2,     1,     1,     2,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     6,     1,     3,     1,     1,     2,     4,     2,
       4,     6,     8,     4,     1,     3,     1,     1,     1,     2,
       4,     3,     4,     2,     5,     2,     2,     1,     1,     2,
       4,     1,     3,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     453,     9,     2,     4,     5,     7,     8,     0,     0,   193,
     211,   209,   327,   283,   218,     0,   200,   496,   196,   217,
     189,   198,   213,   214,   197,     0,     0,   194,   212,   215,
     195,   328,     0,   190,   459,   329,   216,     0,   199,   219,
     284,   210,   220,     0,     0,   274,   276,   223,     0,     3,
     221,   222,     0,    28,     0,   285,    26,    27,     0,   454,
     170,   172,   179,   191,     0,   186,   188,   187,   201,   206,
     204,   203,   178,   237,   239,   240,   238,   181,   182,   183,
     180,   177,   485,   265,     0,   205,   267,   173,   202,     0,
       0,    30,    29,   174,     6,   175,   176,    21,     0,   286,
       0,   288,     0,     0,     0,     0,     0,     0,    18,     0,
     453,     0,     0,   455,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   418,   419,   381,   380,     0,   392,
       0,   395,   396,   417,   386,   390,   384,   393,   387,   388,
     389,   391,   394,   385,     0,   481,   493,   367,   379,     0,
     439,   460,     0,     0,     0,     0,     0,     0,     0,     0,
      31,   275,   281,    37,    36,     0,     1,     0,   277,   221,
      32,   207,   171,   196,   185,   192,     0,   262,   475,   485,
       0,   486,   312,     0,   302,   477,   266,   342,     0,   323,
       0,     0,   279,   287,   208,     0,   227,     0,   473,   228,
     453,   261,     0,   244,   453,     0,   453,   456,     0,     0,
     420,   421,   482,   290,     0,     0,   493,   494,   368,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,   282,    35,    34,    15,    17,    16,   455,     0,     0,
       0,     0,     0,    20,   461,     0,     0,     0,    23,   499,
      19,     0,     0,    72,     0,     0,    69,    70,    71,   438,
      22,    10,    11,    12,    13,    14,    38,    25,     0,    59,
      88,     0,    67,    68,    90,    93,    97,   100,   103,   108,
     111,   113,   115,   117,   119,   121,   123,   436,   437,   479,
       0,   434,   125,    33,   278,     0,   184,     0,     0,   476,
     313,   264,     0,     0,     0,   377,   378,     0,   370,   371,
       0,   467,   314,   310,   301,   479,     0,   300,   304,     0,
       0,   121,   139,   478,     0,   364,   365,   366,     0,   335,
      28,    27,   342,   338,   343,   491,   490,   342,     0,   340,
       0,   339,     0,   225,     0,     0,   324,   325,     0,   280,
       0,   226,   236,   474,   232,   234,     0,     0,   243,     0,
       0,   249,     0,     0,     0,   383,   382,     0,   369,   440,
     229,   254,     0,     0,     0,   258,     0,     0,     0,   253,
       0,   461,    60,    61,     0,     0,    84,     0,     0,   462,
       0,     0,     0,    65,     0,   500,   449,     0,   137,     0,
       0,    62,    63,    49,    50,     0,   457,     0,     0,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   127,   128,   129,   135,   134,   136,   132,   133,     0,
       0,   126,     0,   483,   479,   480,   292,   289,     0,   433,
       0,   263,   475,     0,    57,     0,   317,   315,   311,     0,
     375,     0,   376,     0,   457,     0,     0,     0,     0,   467,
       0,     0,     0,     0,   467,     0,     0,     0,    28,   468,
     153,   140,   141,   142,   467,   143,   144,   145,   146,   169,
       0,   147,     0,     0,   483,   306,   479,   308,   271,   299,
       0,   272,     0,   337,   333,   343,     0,     0,   344,   345,
     492,   336,   330,   342,   334,   342,   322,   224,     0,     0,
     355,     0,   349,   350,     0,   326,   327,     0,   459,   426,
       0,   423,   425,   259,     0,     0,   231,   260,   242,   247,
       0,   248,   245,   241,     0,   252,   256,     0,   257,     0,
     251,     0,    85,     0,     0,     0,     0,     0,     0,   463,
     465,     0,     0,     0,     0,     0,    24,     0,     0,     0,
       0,    48,   458,     0,     0,     0,     0,    44,    91,    92,
      94,    95,    96,    98,    99,   101,   102,   106,   107,   104,
     105,   109,   110,   112,   114,   116,   118,   120,     0,   124,
       0,   291,   302,   477,   435,   316,     0,   319,   320,   487,
       0,   442,   497,   374,   372,     0,   165,     0,   166,   467,
       0,   467,     0,     0,     0,     0,     0,     0,     0,   467,
     154,   151,   152,     0,     0,     0,   269,   270,   303,   305,
     346,   332,   347,   348,   343,   341,   331,   353,     0,     0,
       0,     0,   354,     0,     0,     0,     0,   427,     0,   429,
       0,     0,   233,   235,   246,     0,   255,   250,     0,     0,
     463,     0,    86,     0,    77,     0,   457,   464,    73,     0,
     466,    80,   465,    78,     0,    66,     0,    55,    56,   138,
      89,    47,     0,    46,    40,    39,    43,     0,    42,     0,
     298,     0,     0,    58,   488,     0,     0,   498,   443,   373,
     467,   150,     0,   163,   471,   164,   168,   158,     0,     0,
     167,     0,   441,     0,   148,   307,   309,   501,   268,   352,
       0,     0,     0,   359,   351,     0,     0,     0,   363,     0,
       0,     0,   422,   424,   230,    87,     0,    74,     0,     0,
     463,     0,     0,     0,    79,     0,     0,    45,    41,   122,
     296,   297,   321,   318,   448,   447,     0,   149,     0,   472,
       0,   467,     0,   467,   467,   451,   502,     0,   358,     0,
     357,   362,     0,   361,   428,     0,   430,   463,     0,     0,
      75,    83,    81,     0,     0,     0,   294,   295,   445,   446,
       0,     0,   467,   155,     0,   157,   160,     0,   450,   356,
     360,     0,    76,    54,    51,    82,    53,    52,   293,   444,
       0,     0,   467,   159,   452,   431,   161,   467,   156,     0,
     162,   432
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    47,    48,    49,   105,    51,    52,    53,   270,   271,
     272,   273,   274,   275,    54,   276,   277,    56,    57,   330,
     279,   582,   280,   281,   282,   399,   569,   690,   691,   687,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   408,   452,   489,   333,   490,   491,
     492,   493,   494,   495,   728,   496,   724,   497,   498,    59,
      60,   499,    62,    63,   500,    65,    66,    67,    68,    69,
      70,    71,   363,   364,   365,    72,    73,    74,    75,    76,
     212,    77,   373,    78,    79,    80,    81,   186,   187,    82,
      83,    84,   171,    85,    86,   298,   299,   455,   456,   326,
     327,   539,    87,   323,   309,   467,   619,    88,    89,    90,
     346,   347,   348,   349,   518,   519,   356,   532,   533,   350,
      91,   157,   227,   191,   318,   319,   320,    92,   158,    93,
     540,   541,   542,    94,   300,   301,    95,    96,   501,   192,
     621,   622,   776,   302,   647,   786,   213,   102,   583,   162,
     400,   688,   693,   502,   503,   780,   366,   311,   334,   611,
     223,   458,   193,   715,   352,   521,   228,    98,   718,   406,
     787
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -665
static const yytype_int16 yypact[] =
{
    3297,  -665,  -665,  -665,  -665,  -665,  -665,   898,   -32,  -665,
    -665,  -665,  -665,  -665,  -665,   855,  -665,  -665,   113,  -665,
    -665,  -665,  -665,  -665,  -665,    36,  2400,  -665,  -665,  -665,
    -665,  -665,  3191,  -665,    86,  -665,  -665,   472,  -665,  -665,
    -665,  -665,  -665,   573,   282,    10,  -665,  -665,   132,  -665,
     140,  -665,    41,  -665,   188,  -665,  -665,  -665,   833,  3297,
    -665,  -665,  -665,  -665,  2187,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,   -38,   -20,   573,  -665,  -665,  -665,  -665,    76,
    1021,  -665,  -665,  -665,  -665,  -665,  -665,  -665,   136,  -665,
     849,  -665,   428,   113,   493,   140,   108,   237,  -665,  1990,
    3297,   125,   213,   625,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,   170,   176,   186,  -665,
     196,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,   428,  3940,   199,  -665,  -665,   223,
    -665,  -665,   625,    77,   483,   583,    65,   898,    55,   205,
    -665,  -665,    10,   625,   625,  2638,  -665,    65,    10,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,    -4,  -665,   239,   201,
    1089,  -665,  -665,   232,  3615,  3018,  -665,  1640,   493,   272,
     237,   301,    10,  -665,  -665,   309,  -665,   237,   237,  -665,
    3297,  -665,   289,  -665,  3297,   703,  3297,  -665,   310,   313,
    -665,  -665,  -665,  -665,   625,   315,   199,  -665,  -665,  3297,
     237,   307,    65,   625,    27,   424,   625,    65,   321,   849,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,   273,  3018,  3018,
     340,  2751,   344,  -665,   364,   363,  3107,   366,  -665,  2840,
    -665,   374,  2638,   282,  3018,  3018,  -665,  -665,  -665,    41,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  1004,   222,
    -665,  3018,  -665,  -665,  -665,    56,   180,     1,   147,   207,
     290,   356,   365,   359,   455,  1147,  -665,  -665,  -665,   396,
     255,  -665,  -665,  -665,  -665,   573,  -665,  2840,  2101,  -665,
    -665,  -665,   232,   232,   625,   140,  -665,   282,  -665,   380,
     407,  1350,  -665,  -665,  -665,  3402,   413,    35,  -665,    25,
     184,    -3,  -665,  -665,   408,  -665,  -665,  -665,   208,  -665,
     403,   404,  2292,  -665,   367,   409,  -665,  1640,     2,  -665,
     405,  -665,   417,  -665,   237,  1179,  -665,   272,  3692,  -665,
     420,  -665,  -665,   437,  -665,   429,   431,   433,  -665,   435,
     625,   132,   424,   438,   442,  -665,  -665,   419,  -665,  -665,
     454,  -665,   448,    28,   424,  -665,   449,    65,   452,  -665,
    2929,   364,  -665,  -665,  3940,   474,  -665,  3940,  2840,  -665,
    3479,  3940,  2638,  -665,  3940,  -665,  -665,  2638,  -665,    20,
     485,  -665,  -665,  -665,  -665,   869,  2840,  2840,  1048,  -665,
    3018,  3018,  3018,  3018,  3018,  3018,  3018,  3018,  3018,  3018,
    3018,  3018,  3018,  3018,  3018,  3018,  3018,  3018,  3018,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  3018,
    2840,  -665,  2840,   815,   396,  -665,    75,  -665,   149,  -665,
    2638,  -665,   -25,    93,  -665,  1750,  -665,  -665,  -665,   546,
     140,   282,  -665,  1089,  2840,   471,  3018,   477,   481,  1873,
     501,   237,   502,   237,  2840,   505,   232,   507,   490,   506,
    -665,  -665,  -665,  -665,  1522,  -665,  -665,  -665,  -665,  -665,
    2187,  -665,   495,   499,   784,   498,   543,   504,     7,  -665,
    3786,  -665,  3018,  -665,  -665,   367,    72,  1215,  -665,  -665,
    -665,  -665,  -665,   573,  -665,  1640,  -665,  -665,   625,  1056,
     140,   282,   520,  -665,    89,  -665,   237,   524,   104,  -665,
     270,  -665,  -665,  -665,   237,  3018,  -665,  -665,  -665,   132,
     424,  -665,  -665,  -665,  2638,  -665,  -665,   518,  -665,   526,
    -665,   537,  -665,  3539,   542,  3018,   544,   109,  3940,   550,
     264,   547,   554,   549,   120,   558,  -665,  2840,  3018,    77,
     921,  -665,   552,   563,   -34,    77,   974,  -665,  -665,  -665,
      56,    56,    56,   180,   180,     1,     1,   147,   147,   147,
     147,   207,   207,   290,   356,   365,   359,   455,    14,  -665,
     564,  -665,  3615,  3018,  -665,  -665,  2840,  -665,  -665,   562,
     574,  -665,   546,  -665,  -665,   575,  -665,   559,  -665,  1873,
     581,  2525,   560,  2638,   565,   567,  2638,   546,  2638,  1873,
    -665,  -665,  -665,  2840,  2840,   580,   599,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,   566,  -665,  -665,   140,   282,   625,
     936,   282,  -665,  1179,   625,   966,   282,   572,  3692,   576,
    3297,  3692,  -665,  -665,  -665,   312,  -665,  -665,  3018,  3940,
     550,   589,  -665,   593,  -665,   594,  2840,  -665,  -665,  2840,
    -665,   591,   264,  -665,   601,  -665,   605,  -665,  -665,  -665,
    -665,  -665,    77,  -665,  -665,  -665,  -665,    77,  -665,  2840,
    -665,   606,   608,  -665,  2101,   586,  3880,  -665,  -665,  -665,
    1873,  -665,   616,  -665,  2638,  -665,  -665,   506,   619,   573,
    -665,   620,  -665,   624,  -665,  -665,  -665,  3940,  -665,  -665,
     282,   625,   282,  -665,  -665,   282,   625,   282,  -665,  3940,
     341,  3940,  -665,  -665,  -665,  -665,   628,  -665,  2840,  2840,
     550,   630,   203,  3018,  -665,  2840,  2840,  -665,  -665,  -665,
       7,  -665,  -665,  -665,  -665,   543,   631,  -665,  2840,  -665,
     596,  1873,   617,  1873,  1873,  -665,   632,   635,  -665,   282,
    -665,  -665,   282,  -665,  -665,   695,  -665,   550,   131,   143,
    -665,  -665,  -665,   637,   161,   169,   599,  -665,  -665,  -665,
     232,   183,  2840,   693,  2840,  -665,  -665,  3940,  -665,  -665,
    -665,   237,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
     633,   645,  1873,  -665,  -665,   646,  -665,  1873,  -665,   743,
    -665,  -665
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -665,  -665,  -104,   734,   411,  -665,  -170,   227,  -665,  -665,
    -665,  -665,    44,  -665,  -665,  -665,   790,   135,  -179,     0,
    -665,  -257,   514,  -665,  -665,  -665,   209,  -665,  -665,  -665,
    -665,  -229,   -35,    33,    90,   107,   116,   338,   343,   337,
     339,   327,  -172,  -146,   569,  -665,   328,  -443,  -352,  -665,
     151,  -191,  -665,  -665,  -571,  -665,  -665,  -665,  -665,  -665,
     -28,    29,   154,   -58,    34,  -665,  -665,   360,  -665,   345,
    -665,  -665,  -665,   236,  -665,  -665,  -665,  -665,  -665,  -665,
     137,  -665,  -665,  -143,  -665,  -665,  -665,  -665,   484,    73,
    -665,  -147,  -164,   -44,  -665,  -218,   -23,  -413,  -665,   174,
    -665,  -184,  -142,   150,  -665,  -453,  -665,  -665,  -665,  -665,
    -665,  -665,   446,   268,  -665,  -665,   443,  -665,   129,  -330,
    -665,  -665,  -665,  -665,   322,  -665,  -665,  -665,  -665,  -140,
     133,   128,  -665,  -665,   249,   346,  -665,  -665,  -665,  -167,
    -559,  -665,  -665,  -665,  -600,  -665,    17,  -269,  -461,  -665,
     416,  -664,   112,  -473,  -665,  -665,  -665,  -665,   197,  -252,
    -665,  -665,  -161,  -665,  -323,  -665,   588,  -665,  -665,  -665,
    -665
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -496
static const yytype_int16 yytable[] =
{
      58,   172,   322,   156,   160,   269,   185,   100,   241,   226,
     328,   635,   618,   625,   304,   107,   757,    97,   341,   392,
     393,   310,   396,   331,   522,   534,   154,   312,   313,    61,
     449,   182,    58,   627,    64,   411,   412,   166,   359,     1,
     610,   173,   173,   168,   410,     3,   738,   457,   509,   332,
     463,   189,   419,    13,   343,   345,    13,   351,     1,    58,
     234,    61,   109,   717,    58,   731,    64,   733,     1,   650,
     103,   420,   705,   507,   653,   390,   577,   307,   732,   226,
       1,   211,   194,   190,   168,   195,     3,     4,    61,     6,
     200,   610,   421,    64,   645,   391,   800,   308,     3,     4,
     161,     6,   673,   664,   207,    40,   305,     1,    40,    58,
      58,   371,   523,   217,   425,   426,   169,   450,   161,   306,
     108,   322,   322,   576,   577,   524,    26,   630,   172,   383,
     577,   386,   222,   822,   172,   709,    26,   188,    61,    61,
     177,   567,   640,    64,    64,   510,   173,   205,    26,   175,
     385,   556,   454,   779,   174,   154,   225,   196,   172,    44,
     110,   562,   230,   232,   235,   237,   178,   239,   341,    44,
     807,   427,   428,   242,   243,   278,   564,  -484,   506,   566,
    -484,    44,   523,   571,   572,   665,   573,     1,   176,   575,
     317,   588,   589,   180,   154,   651,   615,    58,   354,   660,
     197,   379,   656,   616,   343,   345,   828,   351,     3,     4,
      58,     6,   684,   224,    58,   372,    58,     3,     4,   616,
       6,   201,   163,   697,   377,   761,   225,   367,   325,    58,
     577,   342,   208,   384,   823,   180,   387,   429,   430,    61,
       1,   577,   106,    61,    64,    61,   824,   217,    64,   214,
      64,   612,   112,   577,   613,    26,   413,   414,    61,   415,
     661,   772,   278,    64,   826,   666,   549,   185,   551,   177,
     344,   577,   827,     3,     4,   218,     6,   721,   224,   577,
     557,   219,     3,     4,   185,     6,   830,   734,    44,   220,
     269,   422,     4,   577,     6,   637,   423,   424,   231,   225,
     165,   238,   221,   180,   331,   168,   454,   454,   240,   802,
      45,    46,   303,   577,   471,   431,   432,   199,   433,   434,
     803,   278,   190,   390,   416,    58,   649,   417,   189,   418,
     332,   206,   229,   534,   209,   215,   682,   216,   166,   831,
     331,   307,    58,   391,   646,   331,   341,    58,   310,   700,
     685,   369,   101,   374,   312,   531,   321,   506,   154,   506,
     190,   308,   809,  -485,   459,   460,   332,   382,   777,   689,
     550,   332,   388,   331,   180,    45,    46,   570,   462,   670,
     671,   342,   343,   345,   269,   351,   155,   590,   591,   592,
     740,   742,   325,   355,   154,   745,   747,   154,   505,   332,
     154,   154,   278,   181,   154,     3,     4,   278,     6,   358,
     224,    50,   360,   180,   368,   515,   375,   316,    50,   376,
     344,   754,   460,   692,   340,   353,   178,   357,   328,   813,
     381,   815,   816,     3,   361,   362,     2,    50,     4,     5,
       6,   331,   185,    50,   389,   203,   674,   204,   394,   755,
     795,   671,   397,   225,   225,   170,   189,   380,   593,   594,
     278,   756,   468,   469,   172,   180,   398,   332,   435,   179,
      50,   401,   789,   317,   404,    50,   407,   792,   437,   278,
     838,     3,     4,   436,     6,   840,   163,   438,   190,   517,
     473,  -485,     3,     4,   278,     6,     1,   233,   453,   181,
      58,  -483,     3,     4,   168,     6,   168,    45,    46,   474,
     154,   179,   101,   179,   511,   155,   508,   595,   596,   785,
      50,    50,   559,   168,   512,    58,   525,   513,   658,   217,
     202,   794,   520,   796,   217,   155,   597,   598,   599,   600,
     570,   164,   526,   543,   325,   692,     1,   544,   488,   601,
     602,   545,     3,     4,   278,     6,   546,   167,   547,   342,
     548,   552,   554,   154,   165,   179,    50,   553,   154,   340,
     225,   555,   558,   462,   340,   560,     1,   169,    50,   196,
     565,   527,     3,     4,   203,     6,    50,   167,   578,   620,
     409,   331,     3,     4,   626,     6,   654,   236,   344,   834,
     628,   315,   629,   631,   633,    50,   806,   636,    50,   638,
     729,   639,   154,   729,    26,   729,   577,   332,   641,   829,
     643,    50,   155,   181,   642,    50,   644,    50,   506,   278,
     663,   278,   668,   278,     3,     4,   278,     6,   278,   278,
      50,   676,   752,   678,    26,   504,   325,    44,  -483,   677,
     179,   681,   686,   683,    45,    46,   694,   695,   696,   217,
     217,   698,   616,   531,   217,   217,   704,   710,   154,   841,
      58,   154,   714,    50,   170,    43,   716,    44,   719,   154,
     720,   722,   737,   726,    45,    46,   645,   215,   517,   179,
     730,   758,   225,   775,   749,   759,   763,   760,   751,    61,
     316,   729,   325,   765,    64,   325,   488,   766,   632,   770,
     634,   773,     3,     4,   771,     6,   154,   370,   778,   812,
     278,   488,   781,   783,   278,   470,   172,   784,   472,   168,
     409,   797,    50,   801,   810,   574,    50,   154,   818,   814,
     821,   217,   817,   825,   297,   584,   217,   832,   837,   154,
     340,   154,   340,    50,   155,     6,   836,   155,    50,   111,
     155,   155,   155,   667,   155,   669,   530,   155,   839,    50,
     403,   362,   680,   603,   605,   168,   607,   606,   608,   604,
     672,   278,   723,   278,   278,   725,   711,     1,   516,   461,
      55,   655,   744,     3,     4,   624,     6,    99,   167,   753,
     535,   750,   782,   675,   764,    50,   614,   563,    50,     0,
     712,    50,    50,    50,   378,    50,     0,   154,    50,     0,
     155,     0,    55,     0,     3,     4,     0,     6,   405,   224,
       0,     0,   278,    55,     0,     0,     1,   278,     0,     0,
       0,     2,     0,     4,     5,     6,     0,     0,   808,    55,
       0,     0,     1,     0,    55,    26,   488,     2,     1,     4,
       5,     6,     0,     0,     3,     4,   488,     6,     0,   104,
       0,    50,     1,     0,    55,     0,   464,   466,     3,     4,
       0,     6,   623,   579,   315,     0,   504,     0,    44,     0,
      50,     0,     0,     0,     0,    45,    46,     0,     0,    55,
      55,     1,     0,     0,    26,    50,     2,     3,     4,     5,
       6,    50,     0,     0,   155,     0,     0,   453,   177,     0,
      26,    50,     0,   155,     1,     0,    45,    46,   155,     0,
       3,     4,     0,     6,   177,   702,    50,    44,     0,   657,
      26,     0,   662,     0,   178,     3,     4,   488,     6,     0,
     741,     0,     0,    44,   580,     0,     0,    99,     0,     0,
     202,   727,     0,     0,   727,    50,   727,   464,     0,    26,
       0,     0,     0,    44,    50,     3,     4,     1,     6,    50,
     746,     0,     0,     3,     4,   464,     6,    55,   707,     0,
       0,     0,    26,   155,     0,     0,   155,     0,   155,     0,
      55,     0,    44,     0,    55,     0,    55,     1,   488,     0,
     488,   488,     2,     0,     4,     5,     6,   762,     0,    55,
       0,   609,     0,    50,     1,    44,     0,     0,     0,   297,
       3,     4,     0,     6,   466,   198,     0,     0,     0,   155,
      50,     0,    50,   464,    50,    26,     0,    50,   835,    50,
      50,     1,   727,     0,     0,     0,     0,     3,     4,   488,
       6,     0,   585,     0,   488,     3,     4,     0,     6,   739,
     659,     0,   743,     0,   530,    26,   155,   748,    44,    50,
       0,    50,    50,     0,   155,     0,   798,   799,     0,   177,
      50,     0,     1,   804,   805,    55,     0,   155,     3,     4,
       0,     6,     0,   314,     0,     0,   811,     0,    44,   155,
       0,   155,     0,     0,     0,    55,     0,     0,     0,    26,
       0,     0,     0,   297,     0,     0,     0,    50,   335,   336,
     337,    50,    55,   586,     0,    50,     0,    55,     0,     0,
       0,     0,     0,     0,     0,     0,   699,     0,    50,     0,
       0,   788,    44,   790,     0,     0,   791,     0,   793,     0,
      50,     0,    50,   439,   440,   441,   442,   443,   444,   445,
     446,     0,     0,   447,   448,     0,     0,   155,     0,     0,
     449,     0,     0,     0,     0,   713,     0,     0,     3,     4,
       0,     6,    50,   528,    50,    50,     0,     0,     0,     0,
     819,     0,     0,   820,     0,   581,     0,     0,   587,     0,
       0,     0,   735,   736,     0,     0,     0,     0,     1,   244,
     245,   246,   108,     0,     3,     4,     0,     6,    50,   329,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,    50,   248,
     249,   335,   336,   337,     0,   464,     0,     0,     0,     0,
       0,     0,   250,     0,     0,   251,     0,   450,   252,   451,
       0,     0,     0,     0,   253,   529,     0,     0,   769,     0,
       0,     0,     0,   466,     0,   254,    26,     0,     0,     0,
      55,   255,     0,     0,    55,   256,    55,   257,     0,     0,
       0,   258,     0,   260,     0,     0,   261,     0,     0,     0,
       0,     0,     0,    55,     0,    55,     0,   262,     0,   263,
       0,     0,     0,     0,     0,     0,   264,   265,   266,   267,
     268,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   652,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,   244,   245,   246,   108,     2,     3,
       4,     5,     6,     0,   247,     0,     0,     0,     0,   701,
     703,     0,     0,     0,     0,   706,   708,     0,     0,     0,
       0,     0,     0,   833,   248,   249,     0,     0,     8,     9,
      10,   475,   476,     0,    11,    12,    13,   250,   477,   478,
     251,   479,    14,   252,     0,    15,    16,     0,   183,   253,
      19,   480,    20,   481,   482,    21,    22,    23,    24,   483,
     254,    26,     0,     0,     0,    27,   255,   484,    28,    29,
     256,    30,   257,    31,   485,     0,   258,   259,   260,   486,
      33,   261,    34,    35,    36,    37,    38,    39,    40,    41,
     487,    42,   262,     0,   263,     0,     0,     0,     0,     0,
      55,   264,   265,   266,   267,   268,     0,     0,     0,     0,
       0,     0,     0,     0,   321,  -469,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   767,     0,     0,     0,     0,   768,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     1,   244,   245,   246,   108,
       2,     3,     4,     5,     6,     0,   247,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   249,     0,     0,
       8,     9,    10,   475,   476,    55,    11,    12,    13,   250,
     477,   478,   251,   479,    14,   252,     0,    15,    16,     0,
     183,   253,    19,   480,    20,   481,   482,    21,    22,    23,
      24,   483,   254,    26,     0,     0,     0,    27,   255,   484,
      28,    29,   256,    30,   257,    31,   485,     0,   258,   259,
     260,   486,    33,   261,    34,    35,    36,    37,    38,    39,
      40,    41,   487,    42,   262,     0,   263,     0,     0,     0,
       0,     0,     0,   264,   265,   266,   267,   268,     0,     0,
       0,     0,     0,     1,     0,     0,   321,  -470,     2,     3,
       4,     5,     6,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,    17,   183,     0,
      19,     0,    20,     0,     0,    21,    22,    23,    24,     0,
       0,    26,   335,   336,   337,    27,     0,     0,    28,    29,
       0,    30,     0,    31,     0,  -495,     0,     0,     0,     0,
      33,     0,    34,    35,    36,   338,    38,    39,    40,    41,
       0,    42,    43,     0,    44,     0,     0,     0,     0,     0,
       0,    45,    46,     1,   244,   245,   246,   108,     0,     3,
       4,     0,     6,   339,   329,  -489,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   250,     0,     0,
     251,     0,     0,   252,     0,     0,     0,     0,     0,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,    26,     0,     0,     0,     0,   255,     0,     0,     0,
     256,     0,   257,     0,     0,     0,   258,   259,   260,     0,
       0,   261,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,   263,     0,     0,     0,     0,     0,
       0,   264,   265,   266,   267,   268,     0,     0,     0,     0,
       0,     0,     0,     0,   465,   617,     1,   244,   245,   246,
     108,     2,     3,     4,     5,     6,     0,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   249,     0,
       0,     8,     9,    10,   475,   476,     0,    11,    12,    13,
     250,   477,   478,   251,   479,    14,   252,     0,    15,    16,
       0,   183,   253,    19,   480,    20,   481,   482,    21,    22,
      23,    24,   483,   254,    26,     0,     0,     0,    27,   255,
     484,    28,    29,   256,    30,   257,    31,   485,     0,   258,
     259,   260,   486,    33,   261,    34,    35,    36,    37,    38,
      39,    40,    41,   487,    42,   262,     0,   263,     0,     0,
       0,     0,     0,     0,   264,   265,   266,   267,   268,     0,
       0,     0,     0,     1,     0,     0,     0,   321,     2,     3,
       4,     5,     6,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     9,
      10,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,    17,    18,     0,
      19,     0,    20,     0,     0,    21,    22,    23,    24,    25,
       0,    26,     0,     0,     0,    27,     0,     0,    28,    29,
       0,    30,     0,    31,     0,    32,     0,     0,     0,     0,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,     0,    44,     0,     0,     0,     0,     0,
       0,    45,    46,     0,     1,   244,   245,   246,   108,     0,
       3,     4,     0,     6,   210,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,   251,     0,     0,   252,     0,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,    26,     0,     0,     0,     0,   255,     0,     0,
       0,   256,     0,   257,     0,     0,     0,   258,   259,   260,
       1,     0,   261,     0,     0,     2,     3,     4,     5,     6,
       0,     7,     0,   262,     0,   263,     0,     0,     0,     0,
       0,     0,   264,   265,   266,   267,   268,     0,     0,     0,
       0,     0,     0,     0,     0,   465,     9,    10,     0,     0,
       0,    11,    12,    13,     0,     0,     0,     0,     0,    14,
       0,     0,    15,    16,     0,   183,     0,    19,     0,    20,
       0,     0,    21,    22,    23,    24,     0,     0,    26,     0,
       0,     0,    27,     0,     0,    28,    29,     0,    30,     0,
      31,     0,     0,     0,     0,     0,     0,    33,     0,    34,
      35,    36,     0,    38,    39,    40,    41,     0,    42,    43,
       0,    44,     0,     0,     0,     1,     0,     0,    45,    46,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     0,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    10,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,    15,    16,     0,
     183,     0,    19,     0,    20,     0,     0,    21,    22,    23,
      24,     0,     0,    26,     0,     0,     0,    27,     0,     0,
      28,    29,     0,    30,     0,    31,     0,     0,     0,     0,
       0,     0,    33,     0,    34,    35,    36,     0,    38,    39,
      40,    41,     0,    42,    43,     0,    44,     0,     0,     0,
       0,     0,     0,    45,    46,     0,     0,     0,     2,     3,
       4,     5,     6,     0,   113,   514,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
      10,     0,     0,     0,    11,    12,    13,     0,     0,     0,
     136,     0,    14,     0,     0,    15,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,    22,    23,     0,     0,
     137,     0,     0,     0,     0,     0,     0,     0,    28,    29,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    35,    36,     0,     0,    39,    40,    41,
       0,    42,   138,     0,   139,   140,     0,     0,   141,   142,
     143,   144,   145,   146,     0,   147,   148,   149,   150,   151,
       0,     0,   152,     0,     0,     0,     0,   153,     1,   244,
     245,   246,   108,     2,     3,     4,     5,     6,     0,   247,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,     0,     0,     0,     9,    10,     0,     0,     0,    11,
      12,    13,   250,     0,     0,   251,     0,    14,   252,     0,
      15,    16,     0,   183,   253,    19,     0,    20,     0,     0,
      21,    22,    23,    24,     0,   254,    26,     0,     0,     0,
      27,   255,     0,    28,    29,   256,    30,   257,    31,     0,
       0,   258,   259,   260,     0,    33,   261,    34,    35,    36,
       0,    38,    39,    40,    41,     0,    42,   262,     0,   263,
       0,     0,     0,     0,     0,     0,   264,   265,   266,   267,
     268,     1,   244,   245,   246,   108,     2,     3,     4,     5,
       6,     0,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,     0,     0,     0,     0,    10,     0,
       0,     0,    11,    12,    13,   250,     0,     0,   251,     0,
      14,   252,     0,    15,     0,     0,     0,   253,    19,     0,
       0,     0,     0,     0,    22,    23,     0,     0,   254,    26,
       0,     0,     0,     0,   255,     0,    28,    29,   256,     0,
     257,    31,     0,     0,   258,   259,   260,     0,     0,   261,
      34,    35,    36,     0,     0,    39,    40,    41,     0,    42,
     262,     0,   263,     0,     0,     0,     0,     0,     0,   264,
     265,   266,   267,   268,     1,   244,   245,   246,   108,     0,
       3,     4,     0,     6,     0,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,   251,     0,     0,   252,     0,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,    26,     0,     0,     0,     0,   255,     0,     0,
       0,   256,     0,   257,     0,     0,     0,   258,     0,   260,
       0,     0,   261,     1,   244,   245,   246,   108,     0,     3,
       4,     0,     6,   262,   329,   263,   395,     0,     0,     0,
       0,     0,   264,   265,   266,   267,   268,     0,     0,     0,
       0,     0,     0,     0,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   250,     0,     0,
     251,     0,     0,   252,     0,     0,     0,     0,     0,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,    26,     0,     0,     0,     0,   255,     0,     0,     0,
     256,     0,   257,     0,     0,     0,   258,   259,   260,     0,
       0,   261,     1,   244,   245,   246,   108,     0,     3,     4,
       0,     6,   262,   329,   263,     0,     0,     0,     0,     0,
       0,   264,   265,   266,   267,   268,     0,     0,     0,     0,
       0,     0,     0,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   250,     0,     0,   251,
       0,     0,   252,     0,     0,     0,     0,     0,   253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
      26,     0,     0,     0,     0,   255,     0,     0,     0,   256,
       0,   257,     0,     0,     0,   258,     0,   260,     0,     0,
     261,     1,   244,   245,   246,   108,     0,     3,     4,     0,
       6,   262,   329,   263,   561,     0,     0,     0,     0,     0,
     264,   265,   266,   267,   268,     0,     0,     0,     0,     0,
       0,     0,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,     0,     0,   251,     0,
       0,   252,     0,     0,     0,     0,     0,   253,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,    26,
       0,     0,     0,     0,   255,     0,     0,     0,   256,     0,
     257,     0,     0,     0,   258,     0,   260,     0,     0,   261,
       1,   244,   245,   246,   108,     0,     3,     4,     0,     6,
     262,   329,   263,     0,     0,     0,     0,     0,     0,   264,
     265,   266,   267,   268,     0,     0,     0,     0,     0,     0,
       0,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,     0,     0,   251,     0,     0,
     252,     0,     0,     0,     0,     0,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,    26,     0,
       0,     0,     0,   255,     0,     0,     0,   256,     0,   257,
       0,     0,     0,   258,     1,   260,     0,     0,   261,     2,
       3,     4,     5,     6,     0,     7,     0,     0,     0,   402,
       0,   263,     0,     0,     0,     0,     0,     0,   264,   265,
     266,   267,   268,     0,     0,     0,     0,     0,     0,     8,
       9,    10,     0,     0,     0,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,    15,    16,    17,    18,
       0,    19,     0,    20,     0,     0,    21,    22,    23,    24,
      25,     0,    26,     0,     0,     0,    27,     0,     0,    28,
      29,     0,    30,     0,    31,     0,    32,     0,     0,     0,
       0,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,     0,    44,     0,     0,     0,   159,
       1,     0,    45,    46,     0,     2,     3,     4,     5,     6,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,     0,     0,
       0,    11,    12,    13,     0,     0,     0,     0,     0,    14,
       0,     0,    15,    16,    17,    18,     0,    19,     0,    20,
       0,     0,    21,    22,    23,    24,    25,     0,    26,     0,
       0,     0,    27,     0,     0,    28,    29,     0,    30,     0,
      31,     0,    32,     0,     0,     0,     0,    33,     0,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
       0,    44,     0,     0,     0,     1,     0,     0,    45,    46,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    10,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,    15,    16,     0,
     183,     0,    19,     0,    20,     0,     0,    21,    22,    23,
      24,     0,     0,    26,     0,     0,     0,    27,     0,     0,
      28,    29,     0,    30,     0,    31,     0,     2,     3,     4,
       5,     6,    33,   113,    34,    35,    36,     0,    38,    39,
      40,    41,     0,    42,   504,     0,    44,  -483,     0,     0,
       0,     0,     0,    45,    46,     0,     0,     0,     0,    10,
       0,     0,     0,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,    15,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    22,    23,     2,     3,     4,
       5,     6,     0,   113,     0,     0,     0,    28,    29,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    35,    36,     0,     0,    39,    40,    41,    10,
      42,   568,     0,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,    15,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,     0,
       0,     0,    31,     2,     3,     4,     5,     6,   324,   113,
       0,    34,    35,    36,     0,     0,    39,    40,    41,     0,
      42,   679,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,    10,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,     0,    14,     0,     0,
      15,    16,     0,   183,     0,    19,     0,    20,     0,     0,
      21,    22,    23,    24,     0,     0,     0,     0,     0,     0,
      27,     0,     0,    28,    29,     0,    30,     0,    31,     0,
       2,     3,     4,     5,     6,    33,   113,    34,    35,    36,
       0,    38,    39,    40,    41,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    10,     0,     0,     0,    11,   536,    13,     0,
       0,     0,     0,     0,    14,     0,     0,    15,    16,     0,
     183,     0,    19,     0,    20,     0,     0,    21,    22,    23,
      24,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      28,    29,     0,    30,     0,    31,     0,   537,     0,     0,
       0,     0,    33,     0,   538,    35,    36,     0,    38,    39,
      40,    41,     0,    42,     2,     3,     4,     5,     6,   648,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,    10,     0,     0,     0,
      11,    12,    13,     0,     0,     0,     0,     0,    14,     0,
       0,    15,    16,     0,   183,     0,    19,     0,    20,     0,
       0,    21,    22,    23,    24,     0,     0,     0,     0,     0,
       0,    27,     0,     0,    28,    29,     0,    30,     0,    31,
       0,     0,     0,     0,     0,     0,    33,     0,    34,    35,
      36,     0,    38,    39,    40,    41,     0,    42,     2,     3,
       4,     5,     6,   774,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,    15,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,    22,    23,     2,     3,
       4,     5,     6,     0,   113,     0,     0,     0,    28,    29,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    35,    36,     0,     0,    39,    40,    41,
      10,    42,     0,     0,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,    15,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    29,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    35,    36,     0,     0,    39,    40,    41,
       0,    42
};

static const yytype_int16 yycheck[] =
{
       0,    45,   193,    26,    32,   175,    64,     7,   172,   156,
     194,   484,   465,   474,   178,    15,   680,     0,   197,   248,
     249,   188,   251,   195,   347,   355,    26,   188,   189,     0,
      33,    59,    32,   476,     0,   264,   265,    37,   202,     3,
     453,    14,    14,    43,   262,     9,   646,   299,    13,   195,
     307,    89,   281,    46,   197,   197,    46,   197,     3,    59,
     164,    32,    18,   622,    64,   636,    32,   638,     3,   512,
     102,    15,   106,   325,   517,    50,   110,   102,   637,   226,
       3,   109,   102,   121,    84,   105,     9,    10,    59,    12,
      90,   504,    36,    59,    87,    70,   760,   122,     9,    10,
      14,    12,   545,    14,   104,    98,   110,     3,    98,   109,
     110,   215,   110,   113,   113,   114,    43,   120,    14,   123,
       7,   312,   313,   103,   110,   123,    71,   479,   172,   233,
     110,   235,   155,   797,   178,   121,    71,    64,   109,   110,
      85,   398,   494,   109,   110,   110,    14,   103,    71,   108,
     123,   123,   299,   724,    14,   155,   156,    84,   202,   104,
     124,   390,   162,   163,   164,   165,   111,   167,   347,   104,
     770,    24,    25,   173,   174,   175,   394,   102,   325,   397,
     105,   104,   110,   401,   402,    96,   404,     3,     0,   407,
     190,   420,   421,    58,   194,   123,   103,   197,   198,   529,
     124,   229,   525,   110,   347,   347,   806,   347,     9,    10,
     210,    12,   103,    14,   214,   215,   216,     9,    10,   110,
      12,    85,    14,   103,   224,   686,   226,   210,   194,   229,
     110,   197,   124,   233,   103,   100,   236,    30,    31,   210,
       3,   110,    15,   214,   210,   216,   103,   247,   214,   124,
     216,   102,    25,   110,   105,    71,    34,    35,   229,    37,
     529,   714,   262,   229,   103,   534,   370,   325,   372,    85,
     197,   110,   103,     9,    10,   105,    12,   629,    14,   110,
     384,   105,     9,    10,   342,    12,   103,   639,   104,   103,
     460,   111,    10,   110,    12,   486,   116,   117,   163,   299,
      92,   166,   106,   168,   476,   305,   453,   454,   103,   106,
     111,   112,   177,   110,   314,   108,   109,    90,    28,    29,
     763,   321,   121,    50,   102,   325,   510,   105,    89,   107,
     476,   104,   109,   663,   107,   122,   565,   124,   338,   812,
     512,   102,   342,    70,   508,   517,   525,   347,   515,   578,
     568,   214,     7,   216,   515,   355,   124,   504,   358,   506,
     121,   122,   775,   124,   109,   110,   512,   232,   720,   105,
     370,   517,   237,   545,   239,   111,   112,   400,   305,   109,
     110,   347,   525,   525,   554,   525,    26,   422,   423,   424,
     659,   660,   358,   121,   394,   664,   665,   397,   325,   545,
     400,   401,   402,    58,   404,     9,    10,   407,    12,   108,
      14,     0,   103,   278,   125,   342,   106,   190,     7,   106,
     347,   109,   110,   570,   197,   198,   111,   200,   612,   781,
     123,   783,   784,     9,   207,   208,     8,    26,    10,    11,
      12,   613,   500,    32,   123,   100,   550,   102,   108,   678,
     109,   110,   108,   453,   454,    44,    89,   230,   425,   426,
     460,   679,   312,   313,   508,   330,   102,   613,   112,    58,
      59,   108,   741,   473,   108,    64,   102,   746,   119,   479,
     832,     9,    10,   118,    12,   837,    14,    32,   121,   122,
     110,   124,     9,    10,   494,    12,     3,    14,   102,   154,
     500,   105,     9,    10,   504,    12,   506,   111,   112,   102,
     510,   100,   167,   102,   106,   155,   103,   427,   428,   737,
     109,   110,   387,   523,   121,   525,   121,   123,   528,   529,
     111,   749,   123,   751,   534,   175,   429,   430,   431,   432,
     563,    69,   125,   123,   510,   692,     3,   110,   321,   433,
     434,   122,     9,    10,   554,    12,   125,    14,   125,   525,
     125,   123,   108,   563,    92,   154,   155,   125,   568,   342,
     570,   123,   123,   500,   347,   123,     3,   504,   167,   506,
     106,   354,     9,    10,   239,    12,   175,    14,   103,    43,
     262,   763,     9,    10,   123,    12,   523,    14,   525,   817,
     123,   190,   121,   102,   102,   194,   770,   102,   197,   102,
     633,   121,   612,   636,    71,   638,   110,   763,   123,   810,
     122,   210,   262,   278,   125,   214,   122,   216,   775,   629,
     110,   631,   108,   633,     9,    10,   636,    12,   638,   639,
     229,   123,   670,   106,    71,   102,   612,   104,   105,   123,
     239,   109,   102,   109,   111,   112,   109,   103,   109,   659,
     660,   103,   110,   663,   664,   665,   103,   103,   668,   839,
     670,   671,   110,   262,   263,   102,   102,   104,   103,   679,
     121,   100,   102,   123,   111,   112,    87,   122,   122,   278,
     123,   102,   692,   716,   122,   102,   105,   103,   122,   670,
     473,   724,   668,   102,   670,   671,   479,   102,   481,   103,
     483,   125,     9,    10,   106,    12,   716,    14,   102,   123,
     720,   494,   103,   103,   724,   314,   770,   103,   317,   729,
     402,   103,   321,   103,   103,   407,   325,   737,   103,   122,
      45,   741,   110,   106,   175,   417,   746,    54,   103,   749,
     523,   751,   525,   342,   394,    12,   123,   397,   347,    25,
     400,   401,   402,   536,   404,   538,   355,   407,   122,   358,
     256,   544,   563,   435,   437,   775,   449,   438,   450,   436,
     544,   781,   631,   783,   784,   631,   612,     3,   342,   305,
       0,   523,   663,     9,    10,   473,    12,     7,    14,   671,
     357,   668,   729,   554,   692,   394,   460,   391,   397,    -1,
     613,   400,   401,   402,   226,   404,    -1,   817,   407,    -1,
     460,    -1,    32,    -1,     9,    10,    -1,    12,   259,    14,
      -1,    -1,   832,    43,    -1,    -1,     3,   837,    -1,    -1,
      -1,     8,    -1,    10,    11,    12,    -1,    -1,   775,    59,
      -1,    -1,     3,    -1,    64,    71,   629,     8,     3,    10,
      11,    12,    -1,    -1,     9,    10,   639,    12,    -1,    14,
      -1,   460,     3,    -1,    84,    -1,   307,   308,     9,    10,
      -1,    12,   471,    14,   473,    -1,   102,    -1,   104,    -1,
     479,    -1,    -1,    -1,    -1,   111,   112,    -1,    -1,   109,
     110,     3,    -1,    -1,    71,   494,     8,     9,    10,    11,
      12,   500,    -1,    -1,   554,    -1,    -1,   102,    85,    -1,
      71,   510,    -1,   563,     3,    -1,   111,   112,   568,    -1,
       9,    10,    -1,    12,    85,    14,   525,   104,    -1,   528,
      71,    -1,   531,    -1,   111,     9,    10,   720,    12,    -1,
      14,    -1,    -1,   104,    85,    -1,    -1,   167,    -1,    -1,
     111,   633,    -1,    -1,   636,   554,   638,   398,    -1,    71,
      -1,    -1,    -1,   104,   563,     9,    10,     3,    12,   568,
      14,    -1,    -1,     9,    10,   416,    12,   197,    14,    -1,
      -1,    -1,    71,   633,    -1,    -1,   636,    -1,   638,    -1,
     210,    -1,   104,    -1,   214,    -1,   216,     3,   781,    -1,
     783,   784,     8,    -1,    10,    11,    12,   689,    -1,   229,
      -1,   452,    -1,   612,     3,   104,    -1,    -1,    -1,   460,
       9,    10,    -1,    12,   465,    14,    -1,    -1,    -1,   679,
     629,    -1,   631,   474,   633,    71,    -1,   636,   821,   638,
     639,     3,   724,    -1,    -1,    -1,    -1,     9,    10,   832,
      12,    -1,    14,    -1,   837,     9,    10,    -1,    12,   658,
      14,    -1,   661,    -1,   663,    71,   716,   666,   104,   668,
      -1,   670,   671,    -1,   724,    -1,   758,   759,    -1,    85,
     679,    -1,     3,   765,   766,   305,    -1,   737,     9,    10,
      -1,    12,    -1,    14,    -1,    -1,   778,    -1,   104,   749,
      -1,   751,    -1,    -1,    -1,   325,    -1,    -1,    -1,    71,
      -1,    -1,    -1,   554,    -1,    -1,    -1,   716,    72,    73,
      74,   720,   342,    85,    -1,   724,    -1,   347,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   577,    -1,   737,    -1,
      -1,   740,   104,   742,    -1,    -1,   745,    -1,   747,    -1,
     749,    -1,   751,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    27,    -1,    -1,   817,    -1,    -1,
      33,    -1,    -1,    -1,    -1,   616,    -1,    -1,     9,    10,
      -1,    12,   781,    14,   783,   784,    -1,    -1,    -1,    -1,
     789,    -1,    -1,   792,    -1,   415,    -1,    -1,   418,    -1,
      -1,    -1,   643,   644,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    12,   817,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   832,    -1,    -1,    -1,    -1,   837,    34,
      35,    72,    73,    74,    -1,   686,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    -1,   120,    53,   122,
      -1,    -1,    -1,    -1,    59,    96,    -1,    -1,   709,    -1,
      -1,    -1,    -1,   714,    -1,    70,    71,    -1,    -1,    -1,
     500,    76,    -1,    -1,   504,    80,   506,    82,    -1,    -1,
      -1,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,   523,    -1,   525,    -1,   102,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,   579,
     580,    -1,    -1,    -1,    -1,   585,   586,    -1,    -1,    -1,
      -1,    -1,    -1,   814,    34,    35,    -1,    -1,    38,    39,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,
     670,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   702,    -1,    -1,    -1,    -1,   707,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   729,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      38,    39,    40,    41,    42,   775,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,   124,   125,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    62,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    78,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,   123,    14,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    86,    87,    88,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    38,    39,    40,    41,    42,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,   124,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    62,    -1,    -1,    65,    66,    67,    68,    69,
      -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,    -1,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    12,   124,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    86,    87,    88,
       3,    -1,    91,    -1,    -1,     8,     9,    10,    11,    12,
      -1,    14,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,    39,    40,    -1,    -1,
      -1,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    56,    -1,    58,    -1,    60,    -1,    62,
      -1,    -1,    65,    66,    67,    68,    -1,    -1,    71,    -1,
      -1,    -1,    75,    -1,    -1,    78,    79,    -1,    81,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,   101,   102,
      -1,   104,    -1,    -1,    -1,     3,    -1,    -1,   111,   112,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,
      58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,    79,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,   101,   102,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    -1,    14,   123,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      50,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    -1,    -1,    97,    98,    99,
      -1,   101,   102,    -1,   104,   105,    -1,    -1,   108,   109,
     110,   111,   112,   113,    -1,   115,   116,   117,   118,   119,
      -1,    -1,   122,    -1,    -1,    -1,    -1,   127,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    58,    59,    60,    -1,    62,    -1,    -1,
      65,    66,    67,    68,    -1,    70,    71,    -1,    -1,    -1,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,    86,    87,    88,    -1,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,   101,   102,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,    -1,
      52,    53,    -1,    55,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    70,    71,
      -1,    -1,    -1,    -1,    76,    -1,    78,    79,    80,    -1,
      82,    83,    -1,    -1,    86,    87,    88,    -1,    -1,    91,
      92,    93,    94,    -1,    -1,    97,    98,    99,    -1,   101,
     102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      80,    -1,    82,    -1,    -1,    -1,    86,    87,    88,    -1,
      -1,    91,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    12,   102,    14,   104,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,
      -1,    82,    -1,    -1,    -1,    86,    -1,    88,    -1,    -1,
      91,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      12,   102,    14,   104,   105,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    -1,    86,    -1,    88,    -1,    -1,    91,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    12,
     102,    14,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    82,
      -1,    -1,    -1,    86,     3,    88,    -1,    -1,    91,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,   102,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,
      -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,    68,
      69,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,
      79,    -1,    81,    -1,    83,    -1,    85,    -1,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,   101,   102,    -1,   104,    -1,    -1,    -1,   108,
       3,    -1,   111,   112,    -1,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    56,    57,    58,    -1,    60,    -1,    62,
      -1,    -1,    65,    66,    67,    68,    69,    -1,    71,    -1,
      -1,    -1,    75,    -1,    -1,    78,    79,    -1,    81,    -1,
      83,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,   101,   102,
      -1,   104,    -1,    -1,    -1,     3,    -1,    -1,   111,   112,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,
      58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,    79,    -1,    81,    -1,    83,    -1,     8,     9,    10,
      11,    12,    90,    14,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,   101,   102,    -1,   104,   105,    -1,    -1,
      -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    78,    79,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    -1,    -1,    97,    98,    99,    40,
     101,   102,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,
      -1,    -1,    83,     8,     9,    10,    11,    12,    13,    14,
      -1,    92,    93,    94,    -1,    -1,    97,    98,    99,    -1,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      55,    56,    -1,    58,    -1,    60,    -1,    62,    -1,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    -1,    81,    -1,    83,    -1,
       8,     9,    10,    11,    12,    90,    14,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,
      58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      78,    79,    -1,    81,    -1,    83,    -1,    85,    -1,    -1,
      -1,    -1,    90,    -1,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,   101,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    55,    56,    -1,    58,    -1,    60,    -1,    62,    -1,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    78,    79,    -1,    81,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,   101,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    66,    67,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    78,    79,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    -1,    -1,    97,    98,    99,
      40,   101,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    -1,    -1,    97,    98,    99,
      -1,   101
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
     103,   220,   147,   147,     4,     5,     6,    14,    34,    35,
      47,    50,    53,    59,    70,    76,    80,    82,    86,    87,
      88,    91,   102,   104,   111,   112,   113,   114,   115,   134,
     136,   137,   138,   139,   140,   141,   143,   144,   147,   148,
     150,   151,   152,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   223,   224,
     262,   263,   271,   145,   220,   110,   123,   102,   122,   232,
     267,   285,   290,   290,    14,   132,   135,   147,   252,   253,
     254,   124,   179,   231,    13,   192,   227,   228,   229,    14,
     147,   170,   171,   175,   286,    72,    73,    74,    95,   123,
     135,   146,   192,   211,   217,   230,   238,   239,   240,   241,
     247,   257,   292,   135,   147,   121,   244,   135,   108,   220,
     103,   135,   135,   200,   201,   202,   284,   274,   125,   208,
      14,   130,   147,   210,   208,   106,   106,   147,   294,   188,
     135,   123,   145,   130,   147,   123,   130,   147,   145,   123,
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
     123,   105,   159,   278,   223,   106,   223,   149,   102,   154,
     224,   223,   223,   223,   174,   223,   103,   110,   103,    14,
      85,   144,   149,   276,   174,    14,    85,   144,   159,   159,
     160,   160,   160,   161,   161,   162,   162,   163,   163,   163,
     163,   164,   164,   165,   166,   167,   168,   169,   174,   172,
     225,   287,   102,   105,   263,   103,   110,   125,   233,   234,
      43,   268,   269,   132,   252,   276,   123,   175,   123,   121,
     176,   102,   135,   102,   135,   281,   102,   179,   102,   121,
     176,   123,   125,   122,   122,    87,   220,   272,    13,   229,
     175,   123,   126,   175,   217,   241,   292,   132,   147,    14,
     247,   275,   132,   110,    14,    96,   275,   135,   108,   135,
     109,   110,   201,   175,   130,   262,   123,   123,   106,   102,
     154,   109,   159,   109,   103,   223,   102,   157,   279,   105,
     155,   156,   219,   280,   109,   103,   109,   103,   103,   172,
     159,   144,    14,   144,   103,   106,   144,    14,   144,   121,
     103,   227,   286,   172,   110,   291,   102,   268,   296,   103,
     121,   176,   100,   178,   184,   190,   123,   174,   182,   224,
     123,   182,   268,   182,   176,   172,   172,   102,   272,   132,
     275,    14,   275,   132,   246,   275,    14,   275,   132,   122,
     258,   122,   188,   259,   109,   159,   223,   279,   102,   102,
     103,   276,   174,   105,   280,   102,   102,   144,   144,   172,
     103,   106,   233,   125,    13,   224,   270,   176,   102,   182,
     283,   103,   217,   103,   103,   223,   273,   298,   132,   275,
     132,   132,   275,   132,   223,   109,   223,   103,   174,   174,
     279,   103,   106,   175,   174,   174,   220,   272,   217,   225,
     103,   174,   123,   176,   122,   176,   176,   110,   103,   132,
     132,    45,   279,   103,   103,   106,   103,   103,   272,   179,
     103,   281,    54,   172,   223,   135,   123,   103,   176,   122,
     176,   134
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
#line 141 "120gram.y"
    { (yyval.n) = alacnary(TYPEDEF_NAMEr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 145 "120gram.y"
    { (yyval.n) = alacnary(NAMESPACE_NAMEr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 150 "120gram.y"
    { (yyval.n) = alacnary(ORIGINAL_NAMESPACE_NAMEr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 155 "120gram.y"
    { (yyval.n) = alacnary(CLASS_NAMEr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 156 "120gram.y"
    { (yyval.n) = alacnary(CLASS_NAMEr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 161 "120gram.y"
    { (yyval.n) = alacnary(ENUM_NAMEr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 166 "120gram.y"
    { (yyval.n) = alacnary(TEMPLATE_NAMEr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 174 "120gram.y"
    { (yyval.n) = alacnary(IDENTIFIERr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 178 "120gram.y"
    { (yyval.n) = alacnary(LITERALr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 179 "120gram.y"
    { (yyval.n) = alacnary(LITERALr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 180 "120gram.y"
    { (yyval.n) = alacnary(LITERALr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 181 "120gram.y"
    { (yyval.n) = alacnary(LITERALr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 182 "120gram.y"
    { (yyval.n) = alacnary(LITERALr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 186 "120gram.y"
    { (yyval.n) = alacnary(INTEGER_LITERALr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 190 "120gram.y"
    { (yyval.n) = alacnary(CHARACTER_LITERALr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 194 "120gram.y"
    { (yyval.n) = alacnary(FLOATING_LITERALr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 198 "120gram.y"
    { (yyval.n) = alacnary(STRING_LITERALr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 202 "120gram.y"
    { (yyval.n) = alacnary(BOOLEAN_LITERALr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 203 "120gram.y"
    { (yyval.n) = alacnary(BOOLEAN_LITERALr2, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 211 "120gram.y"
    { (yyval.n) = alacnary(TRANSLATION_UNITr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 219 "120gram.y"
    { (yyval.n) = alacnary(PRIMARY_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 220 "120gram.y"
    { (yyval.n) = alacnary(PRIMARY_EXPRESSIONr2, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 221 "120gram.y"
    { (yyval.n) = alacnary(PRIMARY_EXPRESSIONr3, 1, (yyvsp[(2) - (3)].n),); }
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 222 "120gram.y"
    { (yyval.n) = alacnary(PRIMARY_EXPRESSIONr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 226 "120gram.y"
    { (yyval.n) = alacnary(PRIMARY_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 227 "120gram.y"
    { (yyval.n) = alacnary(PRIMARY_EXPRESSIONr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 231 "120gram.y"
    { (yyval.n) = alacnary(PRIMARY_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 232 "120gram.y"
    { (yyval.n) = alacnary(PRIMARY_EXPRESSIONr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 233 "120gram.y"
    { (yyval.n) = alacnary(PRIMARY_EXPRESSIONr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 234 "120gram.y"
    { (yyval.n) = alacnary(PRIMARY_EXPRESSIONr4, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 238 "120gram.y"
    { (yyval.n) = alacnary(QUALIFIED_IDr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 239 "120gram.y"
    { (yyval.n) = alacnary(QUALIFIED_IDr1, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 243 "120gram.y"
    { (yyval.n) = alacnary(NESTED_NAME_SPECIFIERr1, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 244 "120gram.y"
    { (yyval.n) = alacnary(NESTED_NAME_SPECIFIERr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 245 "120gram.y"
    { (yyval.n) = alacnary(NESTED_NAME_SPECIFIERr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].t)); }
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 246 "120gram.y"
    { (yyval.n) = alacnary(NESTED_NAME_SPECIFIERr4, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].t)); }
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 250 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 251 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr2, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 252 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr3, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 254 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr4, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].t), (yyvsp[(4) - (5)].t)); }
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 255 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr5, 3, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].n)); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 256 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr6, 3, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].n)); }
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 257 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr7, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 259 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr8, 5, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].t), (yyvsp[(4) - (5)].t), (yyvsp[(5) - (5)].n)); }
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 260 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr9, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].n)); }
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 261 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr10, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].n)); }
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 262 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr11, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 263 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr12, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].t)); }
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 264 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr13, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].t)); }
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 265 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr14, 3, (yyvsp[(1) - (7)].t), (yyvsp[(3) - (7)].n), (yyvsp[(6) - (7)].n)); }
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 266 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr15, 3, (yyvsp[(1) - (7)].t), (yyvsp[(3) - (7)].n), (yyvsp[(6) - (7)].n)); }
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 267 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr16, 3, (yyvsp[(1) - (7)].t), (yyvsp[(3) - (7)].n), (yyvsp[(6) - (7)].n)); }
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 268 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr17, 3, (yyvsp[(1) - (7)].t), (yyvsp[(3) - (7)].n), (yyvsp[(6) - (7)].n)); }
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 269 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr18, 2, (yyvsp[(1) - (4)].t), (yyvsp[(3) - (4)].n)); }
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 270 "120gram.y"
    { (yyval.n) = alacnary(POSTFIX_EXRESSIONr19, 2, (yyvsp[(1) - (4)].t), (yyvsp[(3) - (4)].n)); }
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 274 "120gram.y"
    { (yyval.n) = alacnary(EXPRESSION_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 275 "120gram.y"
    { (yyval.n) = alacnary(EXPRESSION_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 279 "120gram.y"
    { (yyval.n) = alacnary(UNARY_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 280 "120gram.y"
    { (yyval.n) = alacnary(UNARY_EXPRESSIONr2, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 281 "120gram.y"
    { (yyval.n) = alacnary(UNARY_EXPRESSIONr3, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 282 "120gram.y"
    { (yyval.n) = alacnary(UNARY_EXPRESSIONr4, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 283 "120gram.y"
    { (yyval.n) = alacnary(UNARY_EXPRESSIONr5, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 284 "120gram.y"
    { (yyval.n) = alacnary(UNARY_EXPRESSIONr6, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 285 "120gram.y"
    { (yyval.n) = alacnary(UNARY_EXPRESSIONr7, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 286 "120gram.y"
    { (yyval.n) = alacnary(UNARY_EXPRESSIONr8, 2, (yyvsp[(1) - (4)].t), (yyvsp[(3) - (4)].n)); }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 287 "120gram.y"
    { (yyval.n) = alacnary(UNARY_EXPRESSIONr9, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 288 "120gram.y"
    { (yyval.n) = alacnary(UNARY_EXPRESSIONr10, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 292 "120gram.y"
    { (yyval.n) = alacnary(UNARY_OPERATOR1, 0); }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 293 "120gram.y"
    { (yyval.n) = alacnary(UNARY_OPERATOR2, 0); }
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 294 "120gram.y"
    { (yyval.n) = alacnary(UNARY_OPERATOR3, 0); }
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 295 "120gram.y"
    { (yyval.n) = alacnary(UNARY_OPERATOR4, 0); }
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 300 "120gram.y"
    { (yyval.n) = alacnary(NEW_EXPRESSIONr1, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 302 "120gram.y"
    { (yyval.n) = alacnary(NEW_EXPRESSIONr2, 5, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 304 "120gram.y"
    { (yyval.n) = alacnary(NEW_EXPRESSIONr3, 4, (yyvsp[(1) - (6)].t), (yyvsp[(2) - (6)].n), (yyvsp[(4) - (6)].n), (yyvsp[(6) - (6)].n)); }
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 306 "120gram.y"
    { (yyval.n) = alacnary(NEW_EXPRESSIONr4, 5, (yyvsp[(1) - (7)].t), (yyvsp[(2) - (7)].t), (yyvsp[(3) - (7)].n), (yyvsp[(5) - (7)].n), (yyvsp[(7) - (7)].n)); }
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 310 "120gram.y"
    { (yyval.n) = alacnary(NEW_PLACEMENTr1, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 314 "120gram.y"
    { (yyval.n) = alacnary(NEW_TYPE_IDr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 318 "120gram.y"
    { (yyval.n) = alacnary(NEW_DECLARATORr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 319 "120gram.y"
    { (yyval.n) = alacnary(NEW_DECLARATORr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 323 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_NEW_DECLARATORr1, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 324 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_NEW_DECLARATORr2, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 328 "120gram.y"
    { (yyval.n) = alacnary(NEW_INITIALIZERr1, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 332 "120gram.y"
    { (yyval.n) = alacnary(DELETE_EXPRESSIONr1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 333 "120gram.y"
    { (yyval.n) = alacnary(DELETE_EXPRESSIONr2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 334 "120gram.y"
    { (yyval.n) = alacnary(DELETE_EXPRESSIONr3, 2, (yyvsp[(1) - (4)].t), (yyvsp[(4) - (4)].n)); }
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 335 "120gram.y"
    { (yyval.n) = alacnary(DELETE_EXPRESSIONr4, 3, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].t), (yyvsp[(5) - (5)].n)); }
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 339 "120gram.y"
    { (yyval.n) = alacnary(CAST_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 340 "120gram.y"
    { (yyval.n) = alacnary(CAST_EXPRESSIONr2, 2, (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 344 "120gram.y"
    { (yyval.n) = alacnary(PM_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 345 "120gram.y"
    { (yyval.n) = alacnary(PM_EXPRESSIONr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 346 "120gram.y"
    { (yyval.n) = alacnary(PM_EXPRESSIONr3, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 350 "120gram.y"
    { (yyval.n) = alacnary(MULTIPLICATIVE_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 351 "120gram.y"
    { (yyval.n) = alacnary(MULTIPLICATIVE_EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 352 "120gram.y"
    { (yyval.n) = alacnary(MULTIPLICATIVE_EXPRESSIONr3, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 353 "120gram.y"
    { (yyval.n) = alacnary(MULTIPLICATIVE_EXPRESSIONr4, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 357 "120gram.y"
    { (yyval.n) = alacnary(ADDITIVE_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 358 "120gram.y"
    { (yyval.n) = alacnary(ADDITIVE_EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 359 "120gram.y"
    { (yyval.n) = alacnary(ADDITIVE_EXPRESSIONr3, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 363 "120gram.y"
    { (yyval.n) = alacnary(SHIFT_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 364 "120gram.y"
    { (yyval.n) = alacnary(SHIFT_EXPRESSIONr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 365 "120gram.y"
    { (yyval.n) = alacnary(SHIFT_EXPRESSIONr3, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 369 "120gram.y"
    { (yyval.n) = alacnary(RELATIONAL_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 370 "120gram.y"
    { (yyval.n) = alacnary(RELATIONAL_EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 371 "120gram.y"
    { (yyval.n) = alacnary(RELATIONAL_EXPRESSIONr3, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 372 "120gram.y"
    { (yyval.n) = alacnary(RELATIONAL_EXPRESSIONr4, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 373 "120gram.y"
    { (yyval.n) = alacnary(RELATIONAL_EXPRESSIONr5, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 377 "120gram.y"
    { (yyval.n) = alacnary(EQUALITY_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 378 "120gram.y"
    { (yyval.n) = alacnary(EQUALITY_EXPRESSIONr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 379 "120gram.y"
    { (yyval.n) = alacnary(EQUALITY_EXPRESSIONr3, 1, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 383 "120gram.y"
    { (yyval.n) = alacnary(AND_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 384 "120gram.y"
    { (yyval.n) = alacnary(AND_EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 388 "120gram.y"
    { (yyval.n) = alacnary(EXCLUSIVE_OR_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 389 "120gram.y"
    { (yyval.n) = alacnary(EXCLUSIVE_OR_EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 393 "120gram.y"
    { (yyval.n) = alacnary(INCLUSIVE_OR_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 394 "120gram.y"
    { (yyval.n) = alacnary(INCLUSIVE_OR_EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 398 "120gram.y"
    { (yyval.n) = alacnary(LOGICAL_AND_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 400 "120gram.y"
    { (yyval.n) = alacnary(LOGICAL_AND_EXPRESSIONr1, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 404 "120gram.y"
    { (yyval.n) = alacnary(LOGICAL_OR_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 405 "120gram.y"
    { (yyval.n) = alacnary(LOGICAL_OR_EXPRESSIONr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 409 "120gram.y"
    { (yyval.n) = alacnary(CONDITIONAL_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 411 "120gram.y"
    { (yyval.n) = alacnary(CONDITIONAL_EXPRESSIONr2, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 415 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 417 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_EXPRESSIONr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 418 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_EXPRESSIONr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 422 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_OPERATORr1, 0); }
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 423 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_OPERATORr2, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 424 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_OPERATORr3, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 425 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_OPERATORr4, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 426 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_OPERATORr5, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 427 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_OPERATORr6, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 428 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_OPERATORr7, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 429 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_OPERATORr8, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 430 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_OPERATORr9, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 431 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_OPERATORr10, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 432 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_OPERATORr11, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 436 "120gram.y"
    { (yyval.n) = alacnary(EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 437 "120gram.y"
    { (yyval.n) = alacnary(EXPRESSIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 441 "120gram.y"
    { (yyval.n) = alacnary(CONSTANT_EXPRESSIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 449 "120gram.y"
    { (yyval.n) = alacnary(STATEMENTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 450 "120gram.y"
    { (yyval.n) = alacnary(STATEMENTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 451 "120gram.y"
    { (yyval.n) = alacnary(STATEMENTr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 452 "120gram.y"
    { (yyval.n) = alacnary(STATEMENTr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 453 "120gram.y"
    { (yyval.n) = alacnary(STATEMENTr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 454 "120gram.y"
    { (yyval.n) = alacnary(STATEMENTr6, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 455 "120gram.y"
    { (yyval.n) = alacnary(STATEMENTr7, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 456 "120gram.y"
    { (yyval.n) = alacnary(STATEMENTr8, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 460 "120gram.y"
    { (yyval.n) = alacnary(LABELED_STATEMENTr1, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 461 "120gram.y"
    { (yyval.n) = alacnary(LABELED_STATEMENTr2, 3, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 462 "120gram.y"
    { (yyval.n) = alacnary(LABELED_STATEMENTr3, 2, (yyvsp[(1) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 466 "120gram.y"
    { (yyval.n) = alacnary(EXPRESSION_STATEMENTr1, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 470 "120gram.y"
    { (yyval.n) = alacnary(COMPOUND_STATEMENTr1, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 474 "120gram.y"
    { (yyval.n) = alacnary(STATEMENT_SEQr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 475 "120gram.y"
    { (yyval.n) = alacnary(STATEMENT_SEQr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 479 "120gram.y"
    { (yyval.n) = alacnary(SELECTION_STATEMENT_SEQr1, 3, (yyvsp[(1) - (5)].t), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 480 "120gram.y"
    { (yyval.n) = alacnary(SELECTION_STATEMENT_SEQr2, 5, (yyvsp[(1) - (7)].t), (yyvsp[(3) - (7)].n), (yyvsp[(5) - (7)].n), (yyvsp[(6) - (7)].t), (yyvsp[(7) - (7)].n)); }
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 481 "120gram.y"
    { (yyval.n) = alacnary(SELECTION_STATEMENT_SEQr3, 3, (yyvsp[(1) - (5)].t), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 485 "120gram.y"
    { (yyval.n) = alacnary(CONDITIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 487 "120gram.y"
    { (yyval.n) = alacnary(CONDITIONr2, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 491 "120gram.y"
    { (yyval.n) = alacnary(ITERATION_STATEMENTr1, 3, (yyvsp[(1) - (5)].t), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 492 "120gram.y"
    { (yyval.n) = alacnary(ITERATION_STATEMENTr2, 4, (yyvsp[(1) - (7)].t), (yyvsp[(2) - (7)].n), (yyvsp[(3) - (7)].t), (yyvsp[(5) - (7)].n)); }
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 494 "120gram.y"
    { (yyval.n) = alacnary(ITERATION_STATEMENTr3, 5, (yyvsp[(1) - (8)].t), (yyvsp[(3) - (8)].n), (yyvsp[(4) - (8)].n), (yyvsp[(6) - (8)].n), (yyvsp[(8) - (8)].n)); }
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 498 "120gram.y"
    { (yyval.n) = alacnary(FOR_INIT_STATEMENTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 499 "120gram.y"
    { (yyval.n) = alacnary(FOR_INIT_STATEMENTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 503 "120gram.y"
    { (yyval.n) = alacnary(JUMP_STATEMENTr1, 1, (yyvsp[(1) - (2)].t)); }
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 504 "120gram.y"
    { (yyval.n) = alacnary(JUMP_STATEMENTr2, 1, (yyvsp[(1) - (2)].t)); }
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 505 "120gram.y"
    { (yyval.n) = alacnary(JUMP_STATEMENTr3, 2, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].n)); }
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 506 "120gram.y"
    { (yyval.n) = alacnary(JUMP_STATEMENTr4, 2, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].n)); }
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 510 "120gram.y"
    { (yyval.n) = alacnary(DECLARATION_STATEMENTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 518 "120gram.y"
    { (yyval.n) = alacnary(DECLARATION_SEQr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 519 "120gram.y"
    { (yyval.n) = alacnary(DECLARATION_SEQr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 523 "120gram.y"
    { (yyval.n) = alacnary(DECLARATIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 524 "120gram.y"
    { (yyval.n) = alacnary(DECLARATIONr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 525 "120gram.y"
    { (yyval.n) = alacnary(DECLARATIONr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 526 "120gram.y"
    { (yyval.n) = alacnary(DECLARATIONr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 527 "120gram.y"
    { (yyval.n) = alacnary(DECLARATIONr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 177:

/* Line 1464 of yacc.c  */
#line 528 "120gram.y"
    { (yyval.n) = alacnary(DECLARATIONr6, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 529 "120gram.y"
    { (yyval.n) = alacnary(DECLARATIONr7, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 533 "120gram.y"
    { (yyval.n) = alacnary(BLOCK_DECLARATIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 534 "120gram.y"
    { (yyval.n) = alacnary(BLOCK_DECLARATIONr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 535 "120gram.y"
    { (yyval.n) = alacnary(BLOCK_DECLARATIONr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 536 "120gram.y"
    { (yyval.n) = alacnary(BLOCK_DECLARATIONr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 537 "120gram.y"
    { (yyval.n) = alacnary(BLOCK_DECLARATIONr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 541 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_DECLARATIONr1, 2, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n)); }
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 542 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_DECLARATIONr2, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 546 "120gram.y"
    { (yyval.n) = alacnary(DECL_SPECIFIERr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 547 "120gram.y"
    { (yyval.n) = alacnary(DECL_SPECIFIERr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 548 "120gram.y"
    { (yyval.n) = alacnary(DECL_SPECIFIERr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 549 "120gram.y"
    { (yyval.n) = alacnary(DECL_SPECIFIERr4, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 550 "120gram.y"
    { (yyval.n) = alacnary(DECL_SPECIFIERr5, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 554 "120gram.y"
    { (yyval.n) = alacnary(DECL_SPECIFIER_SEQr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 555 "120gram.y"
    { (yyval.n) = alacnary(DECL_SPECIFIER_SEQr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 559 "120gram.y"
    { (yyval.n) = alacnary(STORAGE_CLASS_SPECIFIERr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 560 "120gram.y"
    { (yyval.n) = alacnary(STORAGE_CLASS_SPECIFIERr2, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 561 "120gram.y"
    { (yyval.n) = alacnary(STORAGE_CLASS_SPECIFIERr3, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 562 "120gram.y"
    { (yyval.n) = alacnary(STORAGE_CLASS_SPECIFIERr4, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 563 "120gram.y"
    { (yyval.n) = alacnary(STORAGE_CLASS_SPECIFIERr5, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 567 "120gram.y"
    { (yyval.n) = alacnary(FUNCTION_SPECIFIERr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 568 "120gram.y"
    { (yyval.n) = alacnary(FUNCTION_SPECIFIERr2, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 569 "120gram.y"
    { (yyval.n) = alacnary(FUNCTION_SPECIFIERr3, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 573 "120gram.y"
    { (yyval.n) = alacnary(TYPE_SPECIFIERr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 574 "120gram.y"
    { (yyval.n) = alacnary(TYPE_SPECIFIERr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 575 "120gram.y"
    { (yyval.n) = alacnary(TYPE_SPECIFIERr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 576 "120gram.y"
    { (yyval.n) = alacnary(TYPE_SPECIFIERr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 577 "120gram.y"
    { (yyval.n) = alacnary(TYPE_SPECIFIERr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 581 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 582 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 583 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr3, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 584 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr4, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 585 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr5, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 586 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr6, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 587 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr7, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 588 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr8, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 589 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr9, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 590 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr10, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 591 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr11, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 592 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr12, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 593 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr13, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 594 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr14, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 595 "120gram.y"
    { (yyval.n) = alacnary(SIMPLE_TYPE_SPECIFIERr15, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 599 "120gram.y"
    { (yyval.n) = alacnary(TYPE_NAMEr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 600 "120gram.y"
    { (yyval.n) = alacnary(TYPE_NAMEr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 601 "120gram.y"
    { (yyval.n) = alacnary(TYPE_NAMEr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 605 "120gram.y"
    { (yyval.n) = alacnary(ELABORATED_TYPE_SPECIFIERr1, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 606 "120gram.y"
    { (yyval.n) = alacnary(ELABORATED_TYPE_SPECIFIERr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 607 "120gram.y"
    { (yyval.n) = alacnary(ELABORATED_TYPE_SPECIFIERr3, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 608 "120gram.y"
    { (yyval.n) = alacnary(ELABORATED_TYPE_SPECIFIERr4, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].n)); }
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 609 "120gram.y"
    { (yyval.n) = alacnary(ELABORATED_TYPE_SPECIFIERr5, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 611 "120gram.y"
    { (yyval.n) = alacnary(ELABORATED_TYPE_SPECIFIERr6, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 613 "120gram.y"
    { (yyval.n) = alacnary(ELABORATED_TYPE_SPECIFIERr7, 5, (yyvsp[(1) - (7)].t), (yyvsp[(2) - (7)].n), (yyvsp[(3) - (7)].n), (yyvsp[(4) - (7)].n), (yyvsp[(6) - (7)].n)); }
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 623 "120gram.y"
    { (yyval.n) = alacnary(ENUM_SPECIFIERr1, 3, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 627 "120gram.y"
    { (yyval.n) = alacnary(ENUMERATOR_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 628 "120gram.y"
    { (yyval.n) = alacnary(ENUMERATOR_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 632 "120gram.y"
    { (yyval.n) = alacnary(ENUMERATOR_DEFINITIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 633 "120gram.y"
    { (yyval.n) = alacnary(ENUMERATOR_DEFINITIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 637 "120gram.y"
    { (yyval.n) = alacnary(ENUMERATORr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 652 "120gram.y"
    { (yyval.n) = alacnary(NAMESPACE_DEFINITIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 653 "120gram.y"
    { (yyval.n) = alacnary(NAMESPACE_DEFINITIONr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 657 "120gram.y"
    { (yyval.n) = alacnary(NAMED_NAMESPACE_DEFINITIONr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 658 "120gram.y"
    { (yyval.n) = alacnary(NAMED_NAMESPACE_DEFINITIONr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 662 "120gram.y"
    { (yyval.n) = alacnary(ORIGINAL_NAMESPACE_DEFINITIONr1, 3, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 667 "120gram.y"
    { (yyval.n) = alacnary(EXTENSION_NAMESPACE_DEFINITIONr1, 3, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 671 "120gram.y"
    { (yyval.n) = alacnary(UNNAMED_NAMESPACE_DEFINITIONr1, 2, (yyvsp[(1) - (4)].t), (yyvsp[(3) - (4)].n)); }
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 675 "120gram.y"
    { (yyval.n) = alacnary(NAMESPACE_BODYr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 686 "120gram.y"
    { (yyval.n) = alacnary(NAMESPACE_ALIAS_DEFINITIONr1, 3, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 690 "120gram.y"
    { (yyval.n) = alacnary(NAMESPACE_ALIAS_DEFINITIONr1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 691 "120gram.y"
    { (yyval.n) = alacnary(NAMESPACE_ALIAS_DEFINITIONr2, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 692 "120gram.y"
    { (yyval.n) = alacnary(NAMESPACE_ALIAS_DEFINITIONr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 693 "120gram.y"
    { (yyval.n) = alacnary(NAMESPACE_ALIAS_DEFINITIONr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 698 "120gram.y"
    { (yyval.n) = alacnary(USING_DECLARATIONr1, 5, (yyvsp[(1) - (6)].t), (yyvsp[(2) - (6)].t), (yyvsp[(3) - (6)].t), (yyvsp[(4) - (6)].n), (yyvsp[(5) - (6)].n)); }
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 700 "120gram.y"
    { (yyval.n) = alacnary(USING_DECLARATIONr2, 4, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 702 "120gram.y"
    { (yyval.n) = alacnary(USING_DECLARATIONr3, 4, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 703 "120gram.y"
    { (yyval.n) = alacnary(USING_DECLARATIONr4, 3, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 704 "120gram.y"
    { (yyval.n) = alacnary(USING_DECLARATIONr5, 3, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].n)); }
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 709 "120gram.y"
    { (yyval.n) = alacnary(USING_DIRECTIVEr1, 5, (yyvsp[(1) - (6)].t), (yyvsp[(2) - (6)].t), (yyvsp[(3) - (6)].t), (yyvsp[(4) - (6)].n), (yyvsp[(5) - (6)].n)); }
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 710 "120gram.y"
    { (yyval.n) = alacnary(USING_DIRECTIVEr2, 4, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].t), (yyvsp[(4) - (5)].n)); }
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 712 "120gram.y"
    { (yyval.n) = alacnary(USING_DIRECTIVEr3, 4, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 713 "120gram.y"
    { (yyval.n) = alacnary(USING_DIRECTIVEr4, 3, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].n)); }
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 717 "120gram.y"
    { (yyval.n) = alacnary(ASM_DEFINITIONr1, 2, (yyvsp[(1) - (5)].t), (yyvsp[(3) - (5)].n)); }
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 721 "120gram.y"
    { (yyval.n) = alacnary(LINKAGE_SPECIFICATIONr1, 3, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].n)); }
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 722 "120gram.y"
    { (yyval.n) = alacnary(LINKAGE_SPECIFICATIONr2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 730 "120gram.y"
    { (yyval.n) = alacnary(INIT_DECLARATOR_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 731 "120gram.y"
    { (yyval.n) = alacnary(INIT_DECLARATOR_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 735 "120gram.y"
    { (yyval.n) = alacnary(INIT_DECLARATORr1, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 739 "120gram.y"
    { (yyval.n) = alacnary(DECLARATORr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 740 "120gram.y"
    { (yyval.n) = alacnary(DECLARATORr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 744 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_DECLARATORr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 746 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_DECLARATORr2, 4, (yyvsp[(1) - (6)].n), (yyvsp[(3) - (6)].n), (yyvsp[(5) - (6)].n), (yyvsp[(6) - (6)].n)); }
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 748 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_DECLARATORr3, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 750 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_DECLARATORr4, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 752 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_DECLARATORr5, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 753 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_DECLARATORr6, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 754 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_DECLARATORr7, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 758 "120gram.y"
    { (yyval.n) = alacnary(PTR_OPERATORr1, 0); }
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 759 "120gram.y"
    { (yyval.n) = alacnary(PTR_OPERATORr2, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 760 "120gram.y"
    { (yyval.n) = alacnary(PTR_OPERATORr3, 0); }
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 761 "120gram.y"
    { (yyval.n) = alacnary(PTR_OPERATORr4, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 762 "120gram.y"
    { (yyval.n) = alacnary(PTR_OPERATORr5, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 763 "120gram.y"
    { (yyval.n) = alacnary(PTR_OPERATORr6, 2, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].n)); }
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 765 "120gram.y"
    { (yyval.n) = alacnary(PTR_OPERATORr7, 3, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 769 "120gram.y"
    { (yyval.n) = alacnary(CV_QUALIFIER-SEQr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 770 "120gram.y"
    { (yyval.n) = alacnary(CV_QUALIFIER-SEQr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 774 "120gram.y"
    { (yyval.n) = alacnary(CV_QUALIFIERr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 775 "120gram.y"
    { (yyval.n) = alacnary(CV_QUALIFIERr2, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 779 "120gram.y"
    { (yyval.n) = alacnary(DECLARATOR_IDr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 780 "120gram.y"
    { (yyval.n) = alacnary(DECLARATOR_IDr2, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 781 "120gram.y"
    { (yyval.n) = alacnary(DECLARATOR_IDr3, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 782 "120gram.y"
    { (yyval.n) = alacnary(DECLARATOR_IDr4, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 786 "120gram.y"
    { (yyval.n) = alacnary(TYPE_IDr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 790 "120gram.y"
    { (yyval.n) = alacnary(TYPE_SPECIFIER_SEQr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 794 "120gram.y"
    { (yyval.n) = alacnary(ABSTRACT_DECLARATORr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 795 "120gram.y"
    { (yyval.n) = alacnary(ABSTRACT_DECLARATORr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 800 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_ABSTRACT_DECLARATORr1, 4, (yyvsp[(1) - (6)].n), (yyvsp[(3) - (6)].n), (yyvsp[(5) - (6)].n), (yyvsp[(6) - (6)].n)); }
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 802 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_ABSTRACT_DECLARATORr2, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 804 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_ABSTRACT_DECLARATORr3, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 806 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_ABSTRACT_DECLARATORr4, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 808 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_ABSTRACT_DECLARATORr5, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 809 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_ABSTRACT_DECLARATORr6, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 813 "120gram.y"
    { (yyval.n) = alacnary(PARAMETER_DECLARATION_CLAUSEr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].t)); }
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 814 "120gram.y"
    { (yyval.n) = alacnary(PARAMETER_DECLARATION_CLAUSEr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 815 "120gram.y"
    { (yyval.n) = alacnary(PARAMETER_DECLARATION_CLAUSEr3, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 816 "120gram.y"
    { (yyval.n) = alacnary(PARAMETER_DECLARATION_CLAUSEr4, 0); }
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 817 "120gram.y"
    { (yyval.n) = alacnary(PARAMETER_DECLARATION_CLAUSEr5, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].t)); }
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 821 "120gram.y"
    { (yyval.n) = alacnary(PARAMETER_DECLARATION_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 823 "120gram.y"
    { (yyval.n) = alacnary(PARAMETER_DECLARATION_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 827 "120gram.y"
    { (yyval.n) = alacnary(PARAMETER_DECLARATIONr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 829 "120gram.y"
    { (yyval.n) = alacnary(PARAMETER_DECLARATIONr2, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 830 "120gram.y"
    { (yyval.n) = alacnary(PARAMETER_DECLARATIONr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 832 "120gram.y"
    { (yyval.n) = alacnary(PARAMETER_DECLARATIONr4, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 836 "120gram.y"
    { (yyval.n) = alacnary(FUNCTION_DEFINITIONr1, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 838 "120gram.y"
    { (yyval.n) = alacnary(FUNCTION_DEFINITIONr2, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 839 "120gram.y"
    { (yyval.n) = alacnary(FUNCTION_DEFINITIONr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 840 "120gram.y"
    { (yyval.n) = alacnary(FUNCTION_DEFINITIONr4, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 844 "120gram.y"
    { (yyval.n) = alacnary(FUNCTION_BODYr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 848 "120gram.y"
    { (yyval.n) = alacnary(INITIALIZERr1, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 849 "120gram.y"
    { (yyval.n) = alacnary(INITIALIZERr2, 1, (yyvsp[(2) - (3)].n)); }
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 853 "120gram.y"
    { (yyval.n) = alacnary(INITIALIZER_CLAUSEr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 854 "120gram.y"
    { (yyval.n) = alacnary(INITIALIZER_CLAUSEr2, 2, (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 855 "120gram.y"
    { (yyval.n) = alacnary(INITIALIZER_CLAUSEr3, 0); }
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 859 "120gram.y"
    { (yyval.n) = alacnary(INITIALIZER_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 860 "120gram.y"
    { (yyval.n) = alacnary(INITIALIZER_LISTr1, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 868 "120gram.y"
    { (yyval.n) = alacnary(CLASS_SPECIFIERr1, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 872 "120gram.y"
    { (yyval.n) = alacnary(CLASS_HEADr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 873 "120gram.y"
    { (yyval.n) = alacnary(CLASS_HEADr2, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 874 "120gram.y"
    { (yyval.n) = alacnary(CLASS_HEADr3, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 876 "120gram.y"
    { (yyval.n) = alacnary(CLASS_HEADr4, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 880 "120gram.y"
    { (yyval.n) = alacnary(CLASS_KEYr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 881 "120gram.y"
    { (yyval.n) = alacnary(CLASS_KEYr2, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 882 "120gram.y"
    { (yyval.n) = alacnary(CLASS_KEYr3, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 886 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_SPECIFICATIONr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 887 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_SPECIFICATIONr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 891 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATIONr1, 2, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n)); }
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 892 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATIONr2, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 893 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATIONr3, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 894 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATIONr4, 0); }
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 895 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATIONr5, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 896 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATIONr6, 1, (yyvsp[(1) - (2)].n)); }
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 897 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATIONr7, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 898 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATIONr8, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 902 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATOR_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 903 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATOR_LISTr1, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 907 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATORr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 908 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATORr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 909 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATORr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 910 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_DECLARATORr4, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 919 "120gram.y"
    { (yyval.n) = alacnary(PURE_SPECIFIERr1, 0); }
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 923 "120gram.y"
    { (yyval.n) = alacnary(CONSTANT_INITIALIZERr1, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 931 "120gram.y"
    { (yyval.n) = alacnary(BASE_CLAUSEr1, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 935 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIER_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 936 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIER_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 940 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIERr1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 941 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIERr2, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 942 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIERr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 943 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIERr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 945 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIERr5, 5, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].n), (yyvsp[(3) - (5)].t), (yyvsp[(4) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 947 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIERr6, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 949 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIERr7, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 950 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIERr8, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 952 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIERr9, 5, (yyvsp[(1) - (5)].n), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].t), (yyvsp[(4) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 954 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIERr10, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 956 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIERr11, 4, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 958 "120gram.y"
    { (yyval.n) = alacnary(BASE_SPECIFIERr12, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 962 "120gram.y"
    { (yyval.n) = alacnary(ACCESS_SPECIFIERr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 963 "120gram.y"
    { (yyval.n) = alacnary(ACCESS_SPECIFIERr2, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 964 "120gram.y"
    { (yyval.n) = alacnary(ACCESS_SPECIFIERr3, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 972 "120gram.y"
    { (yyval.n) = alacnary(CONVERSION_FUNCTION_IDr1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 976 "120gram.y"
    { (yyval.n) = alacnary(CONVERSION_TYPE_IDr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 980 "120gram.y"
    { (yyval.n) = alacnary(CONVERSION_DECLARATORr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 984 "120gram.y"
    { (yyval.n) = alacnary(CTOR_INITIALIZERr1, 1, (yyvsp[(2) - (2)].n)); }
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 988 "120gram.y"
    { (yyval.n) = alacnary(MEM_INITIALIZER_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 989 "120gram.y"
    { (yyval.n) = alacnary(MEM_INITIALIZER_LISTr1, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 993 "120gram.y"
    { (yyval.n) = alacnary(MEM_INITIALIZERr1, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 997 "120gram.y"
    { (yyval.n) = alacnary(MEM_INITIALIZER_IDr1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 998 "120gram.y"
    { (yyval.n) = alacnary(MEM_INITIALIZER_IDr2, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 999 "120gram.y"
    { (yyval.n) = alacnary(MEM_INITIALIZER_IDr3, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 1000 "120gram.y"
    { (yyval.n) = alacnary(MEM_INITIALIZER_IDr4, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 1001 "120gram.y"
    { (yyval.n) = alacnary(MEM_INITIALIZER_IDr5, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 1009 "120gram.y"
    { (yyval.n) = alacnary(OPERATOR_FUNCTION_IDr1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 1013 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr1, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 1014 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr2, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 1015 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr3, 1, (yyvsp[(1) - (3)].t)); }
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 1016 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr4, 1, (yyvsp[(1) - (3)].t)); }
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 1017 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr5, 0); }
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 1018 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr6, 0); }
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 1019 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr7, 0); }
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 1020 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr8, 0); }
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 1021 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr9, 0); }
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 1022 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr10, 0); }
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 1023 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr11, 0); }
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 1024 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr12, 0); }
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 1025 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr13, 0); }
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 1026 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr14, 0); }
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 1027 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr15, 0); }
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 1028 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr16, 0); }
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 1029 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr17, 0); }
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 1030 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr18, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 1031 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr19, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 1032 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr20, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 1033 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr21, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 1034 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr22, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 1035 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr23, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 1036 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr24, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 1037 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr25, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 1038 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr26, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 1039 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr27, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 1040 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr28, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 1041 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr29, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 1042 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr30, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 1043 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr31, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 1044 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr32, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 1045 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr33, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 1046 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr34, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 1047 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr35, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 1048 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr36, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 1049 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr37, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 1050 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr38, 0); }
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 1051 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr39, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 1052 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr40, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 1053 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr41, 0); }
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 1054 "120gram.y"
    { (yyval.n) = alacnary(OPERATORr42, 0); }
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 1063 "120gram.y"
    { (yyval.n) = alacnary(TEMPLATE_DECLARATIONr1, 4, (yyvsp[(1) - (6)].n), (yyvsp[(2) - (6)].t), (yyvsp[(4) - (6)].n), (yyvsp[(6) - (6)].n)); }
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 1067 "120gram.y"
    { (yyval.n) = alacnary(TEMPLATE_PARAMETER_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 1068 "120gram.y"
    { (yyval.n) = alacnary(TEMPLATE_PARAMETER_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 1072 "120gram.y"
    { (yyval.n) = alacnary(TEMPLATE_PARAMETERr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 1073 "120gram.y"
    { (yyval.n) = alacnary(TEMPLATE_PARAMETERr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 1077 "120gram.y"
    { (yyval.n) = alacnary(TYPE_PARAMETERr1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 1078 "120gram.y"
    { (yyval.n) = alacnary(TYPE_PARAMETERr2, 3, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 1079 "120gram.y"
    { (yyval.n) = alacnary(TYPE_PARAMETERr3, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 1080 "120gram.y"
    { (yyval.n) = alacnary(TYPE_PARAMETERr4, 3, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); }
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 1082 "120gram.y"
    { (yyval.n) = alacnary(TYPE_PARAMETERr5, 4, (yyvsp[(1) - (6)].t), (yyvsp[(3) - (6)].n), (yyvsp[(5) - (6)].t), (yyvsp[(6) - (6)].n)); }
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 1084 "120gram.y"
    { (yyval.n) = alacnary(TYPE_PARAMETERr6, 5, (yyvsp[(1) - (8)].t), (yyvsp[(3) - (8)].n), (yyvsp[(5) - (8)].t), (yyvsp[(6) - (8)].n), (yyvsp[(8) - (8)].n)); }
    break;

  case 433:

/* Line 1464 of yacc.c  */
#line 1088 "120gram.y"
    { (yyval.n) = alacnary(TEMPLATE_IDr1, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 1092 "120gram.y"
    { (yyval.n) = alacnary(TEMPLATE_ARGUMENT_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 1093 "120gram.y"
    { (yyval.n) = alacnary(TEMPLATE_ARGUMENT_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 1097 "120gram.y"
    { (yyval.n) = alacnary(TEMPLATE_ARGUMENTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 1098 "120gram.y"
    { (yyval.n) = alacnary(TEMPLATE_ARGUMENTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 438:

/* Line 1464 of yacc.c  */
#line 1099 "120gram.y"
    { (yyval.n) = alacnary(TEMPLATE_ARGUMENTr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 439:

/* Line 1464 of yacc.c  */
#line 1103 "120gram.y"
    { (yyval.n) = alacnary(EXPLICIT_INSTANTIATIONr1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 1107 "120gram.y"
    { (yyval.n) = alacnary(EXPLICIT_SPECIALIZATIONr1, 2, (yyvsp[(1) - (4)].t), (yyvsp[(4) - (4)].n)); }
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 1115 "120gram.y"
    { (yyval.n) = alacnary(TRY_BLOCKr1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 1119 "120gram.y"
    { (yyval.n) = alacnary(FUNCTION_TRY_BLOCKr1, 3, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n)); }
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 1123 "120gram.y"
    { (yyval.n) = alacnary(HANDLER_SEQr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 1128 "120gram.y"
    { (yyval.n) = alacnary(HANDLERr1, 3, (yyvsp[(1) - (5)].t), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n)); }
    break;

  case 445:

/* Line 1464 of yacc.c  */
#line 1132 "120gram.y"
    { (yyval.n) = alacnary(EXECEPTION_DECLARATIONr1, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 446:

/* Line 1464 of yacc.c  */
#line 1133 "120gram.y"
    { (yyval.n) = alacnary(EXECEPTION_DECLARATIONr2, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 447:

/* Line 1464 of yacc.c  */
#line 1134 "120gram.y"
    { (yyval.n) = alacnary(EXECEPTION_DECLARATIONr3, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 448:

/* Line 1464 of yacc.c  */
#line 1135 "120gram.y"
    { (yyval.n) = alacnary(EXECEPTION_DECLARATIONr4, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 1139 "120gram.y"
    { (yyval.n) = alacnary(THROW_EXPRESSIONr1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].n)); }
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 1143 "120gram.y"
    { (yyval.n) = alacnary(EXCEPTION_SPECIFICATIONr1, 2, (yyvsp[(1) - (4)].t), (yyvsp[(3) - (4)].n)); }
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 1147 "120gram.y"
    { (yyval.n) = alacnary(TYPE_ID_LISTr1, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 1148 "120gram.y"
    { (yyval.n) = alacnary(TYPE_ID_LISTr2, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); }
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 1156 "120gram.y"
    { (yyval.n) = alacnary(DECLARATION_SEQ_OPTr1, 0); }
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 1157 "120gram.y"
    { (yyval.n) = alacnary(DECLARATION_SEQ_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 1161 "120gram.y"
    { (yyval.n) = alacnary(NESTED_NAME_SPECIFIER_OPTr1, 0); }
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 1162 "120gram.y"
    { (yyval.n) = alacnary(NESTED_NAME_SPECIFIER_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 1166 "120gram.y"
    { (yyval.n) = alacnary(EXPRESSION_LIST_OPTr1, 0); }
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 1167 "120gram.y"
    { (yyval.n) = alacnary(EXPRESSION_LIST_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 1171 "120gram.y"
    { (yyval.n) = alacnary(COLONCOLON_OPTr1, 0); }
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 1172 "120gram.y"
    { (yyval.n) = alacnary(COLONCOLON_OPTr2, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 1176 "120gram.y"
    { (yyval.n) = alacnary(NEW_PLACEMENT_OPTr1, 0); }
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 1177 "120gram.y"
    { (yyval.n) = alacnary(NEW_PLACEMENT_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 1181 "120gram.y"
    { (yyval.n) = alacnary(NEW_INITIALIZER_OPTr1, 0); }
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 1182 "120gram.y"
    { (yyval.n) = alacnary(NEW_INITIALIZER_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 1186 "120gram.y"
    { (yyval.n) = alacnary(NEW_DECLARATOR_OPTr1, 0); }
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 1187 "120gram.y"
    { (yyval.n) = alacnary(NEW_DECLARATOR_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 1191 "120gram.y"
    { (yyval.n) = alacnary(NEW_EXPRESSION_OPTr1, 0); }
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 1192 "120gram.y"
    { (yyval.n) = alacnary(NEW_EXPRESSION_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 1196 "120gram.y"
    { (yyval.n) = alacnary(STATEMENT_SEQ_OPTr1, 0); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 1197 "120gram.y"
    { (yyval.n) = alacnary(STATEMENT_SEQ_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 1201 "120gram.y"
    { (yyval.n) = alacnary(CONDITION_OPTr1, 0); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 1202 "120gram.y"
    { (yyval.n) = alacnary(CONDITION_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 1206 "120gram.y"
    { (yyval.n) = alacnary(ENUMERATOR_LIST_OPTr1, 0); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 1207 "120gram.y"
    { (yyval.n) = alacnary(ENUMERATOR_LIST_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 1211 "120gram.y"
    { (yyval.n) = alacnary(INITIALIZER_OPTr1, 0); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 1212 "120gram.y"
    { (yyval.n) = alacnary(INITIALIZER_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 1216 "120gram.y"
    { (yyval.n) = alacnary(CONSTANT_EXPRESSION_OPTr1, 0); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 1217 "120gram.y"
    { (yyval.n) = alacnary(CONSTANT_EXPRESSION_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 1221 "120gram.y"
    { (yyval.n) = alacnary(ABSTRACT_DECLARATOR_OPTr1, 0); }
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 1222 "120gram.y"
    { (yyval.n) = alacnary(ABSTRACT_DECLARATOR_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 1226 "120gram.y"
    { (yyval.n) = alacnary(TYPE_SPECIFIER_SEQ_OPTr1, 0); }
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 1227 "120gram.y"
    { (yyval.n) = alacnary(TYPE_SPECIFIER_SEQ_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 1231 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_ABSTRACT_DECLARATOR_OPTr1, 0); }
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 1232 "120gram.y"
    { (yyval.n) = alacnary(DIRECT_ABSTRACT_DECLARATOR_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 1236 "120gram.y"
    { (yyval.n) = alacnary(CTOR_INITIALIZER_OPTr1, 0); }
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 1237 "120gram.y"
    { (yyval.n) = alacnary(CTOR_INITIALIZER_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 1241 "120gram.y"
    { (yyval.n) = alacnary(COMMA_OPTr1, 0); }
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 1242 "120gram.y"
    { (yyval.n) = alacnary(COMMA_OPTr2, 0); }
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 1246 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_SPECIFICATION_OPTr1, 0); }
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 1247 "120gram.y"
    { (yyval.n) = alacnary(MEMBER_SPECIFICATION_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 1251 "120gram.y"
    { (yyval.n) = alacnary(SEMICOLON_OPTr1, 0); }
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 1252 "120gram.y"
    { (yyval.n) = alacnary(SEMICOLON_OPTr2, 0); }
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 1256 "120gram.y"
    { (yyval.n) = alacnary(CONVERSION_DECLARATOR_OPTr1, 0); }
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 1257 "120gram.y"
    { (yyval.n) = alacnary(CONVERSION_DECLARATOR_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 495:

/* Line 1464 of yacc.c  */
#line 1261 "120gram.y"
    { (yyval.n) = alacnary(EXPORT_OPTr1, 0); }
    break;

  case 496:

/* Line 1464 of yacc.c  */
#line 1262 "120gram.y"
    { (yyval.n) = alacnary(EXPORT_OPTr2, 1, (yyvsp[(1) - (1)].t)); }
    break;

  case 497:

/* Line 1464 of yacc.c  */
#line 1266 "120gram.y"
    { (yyval.n) = alacnary(HANDLER_SEQ_OPTr1, 0); }
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 1267 "120gram.y"
    { (yyval.n) = alacnary(HANDLER_SEQ_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 499:

/* Line 1464 of yacc.c  */
#line 1271 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_EXPRESSION_OPTr1, 0); }
    break;

  case 500:

/* Line 1464 of yacc.c  */
#line 1272 "120gram.y"
    { (yyval.n) = alacnary(ASSIGNMENT_EXPRESSION_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;

  case 501:

/* Line 1464 of yacc.c  */
#line 1276 "120gram.y"
    { (yyval.n) = alacnary(TYPE_ID_LIST_OPTr1, 0); }
    break;

  case 502:

/* Line 1464 of yacc.c  */
#line 1277 "120gram.y"
    { (yyval.n) = alacnary(TYPE_ID_LIST_OPTr2, 1, (yyvsp[(1) - (1)].n)); }
    break;



/* Line 1464 of yacc.c  */
#line 6579 "y.tab.c"
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
#line 1280 "120gram.y"


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

struct TreeNode * alacnary(int prodRule, int children,...){
	struct TreeNode * nd = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
	if(!nd)memoryError();
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

