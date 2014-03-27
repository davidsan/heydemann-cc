﻿/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         asm_mipsparse
#define yylex           asm_mipslex
#define yyerror         asm_mipserror
#define yylval          asm_mipslval
#define yychar          asm_mipschar
#define yydebug         asm_mipsdebug
#define yynerrs         asm_mipsnerrs


/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 10 "asm_mips.yac"

#include <iostream>
#include <Program.h>
#include <Directive.h>
#include <Label.h>
#include <stdlib.h>
#include <stdio.h>
extern "C" {
#include "utl200.h"
#include "asm200.h"
}
#include <asm_mipsyac.h>
#include<map>
#include <sstream>

#undef  yylex
#define yylex         asm_mipslex
#define yyrestart     asm_mipsrestart
#define yyin          asm_mipsin

extern "C" {extern int            yylex     (YYSTYPE *);}

extern void           yyrestart ();
extern int            yyparse   ();
extern FILE           *yyin       ;

Program prog ;


map<int,string> strmap ;
static int strmap_id ;

void programparse(string file) {
	// ###------------------------------------------------------### 
	//    initialize global and static variables			
	// ###------------------------------------------------------### 

//	std::cout << "Starting parsing" << std::endl;
	
	strmap_id = 0;

	yyin = fopen(file.c_str(), "r") ;
	yyparse() ;
	//std::cout << "Parsing done" << std::endl;
}


static void yyerror (char * str)
	{ std::cout << "yyerror at line " << ASM_LINENO << " : " << str <<std::endl ;	}



/* Line 268 of yacc.c  */
#line 132 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     _ALIGN_ = 258,
     _ASCII_ = 259,
     _ASCIIZ_ = 260,
     _BYTE_ = 261,
     _COMM_ = 262,
     _END_ = 263,
     _ENT_ = 264,
     _EQU_ = 265,
     _EXTERN_ = 266,
     _GLOBAL_ = 267,
     _LCOMM_ = 268,
     _NOREORDER_ = 269,
     _REORDER_ = 270,
     _SECTION_ = 271,
     _SET_ = 272,
     _SKIP_ = 273,
     _SPACE_ = 274,
     _WORD_ = 275,
     ARegister = 276,
     Ampersand = 277,
     Bar = 278,
     CarriageReturn = 279,
     Circomflex = 280,
     Codop_hint_mem = 281,
     Codop_label = 282,
     Codop_n = 283,
     Codop_od_rs = 284,
     Codop_rd = 285,
     Codop_rd_si16 = 286,
     Codop_rd_rs = 287,
     Codop_rd_rs_rt = 288,
     Codop_rd_rt_sham = 289,
     Codop_rd_rt_rs = 290,
     Codop_rd_rs_si16 = 291,
     Codop_rd_rs_ui16 = 292,
     Codop_rd_mem = 293,
     Codop_rs = 294,
     Codop_rs_label = 295,
     Codop_rs_rt = 296,
     Codop_rs_rt_label = 297,
     Codop_rs_si16 = 298,
     Codop_rt_cop0r = 299,
     Codop_rt_cop2r = 300,
     Codop_rt_mem = 301,
     Codop_ui20 = 302,
     Colon = 303,
     Comma = 304,
     Cop0Register = 305,
     DoubleGreat = 306,
     DoubleLess = 307,
     Identifier = 308,
     IntegerRegister = 309,
     LeftParen = 310,
     Litteral = 311,
     Macro_label = 312,
     Macro_n = 313,
     Macro_rd_i32 = 314,
     Macro_rd_rs = 315,
     Macro_rd_rt = 316,
     Macro_rd_label = 317,
     Macro_rs_label = 318,
     Minus = 319,
     Plus = 320,
     Register = 321,
     RightParen = 322,
     Slash = 323,
     Star = 324,
     String = 325,
     String2 = 326,
     GCC_operator = 327,
     Tilda = 328,
     Arobase = 329
   };
#endif
/* Tokens.  */
#define _ALIGN_ 258
#define _ASCII_ 259
#define _ASCIIZ_ 260
#define _BYTE_ 261
#define _COMM_ 262
#define _END_ 263
#define _ENT_ 264
#define _EQU_ 265
#define _EXTERN_ 266
#define _GLOBAL_ 267
#define _LCOMM_ 268
#define _NOREORDER_ 269
#define _REORDER_ 270
#define _SECTION_ 271
#define _SET_ 272
#define _SKIP_ 273
#define _SPACE_ 274
#define _WORD_ 275
#define ARegister 276
#define Ampersand 277
#define Bar 278
#define CarriageReturn 279
#define Circomflex 280
#define Codop_hint_mem 281
#define Codop_label 282
#define Codop_n 283
#define Codop_od_rs 284
#define Codop_rd 285
#define Codop_rd_si16 286
#define Codop_rd_rs 287
#define Codop_rd_rs_rt 288
#define Codop_rd_rt_sham 289
#define Codop_rd_rt_rs 290
#define Codop_rd_rs_si16 291
#define Codop_rd_rs_ui16 292
#define Codop_rd_mem 293
#define Codop_rs 294
#define Codop_rs_label 295
#define Codop_rs_rt 296
#define Codop_rs_rt_label 297
#define Codop_rs_si16 298
#define Codop_rt_cop0r 299
#define Codop_rt_cop2r 300
#define Codop_rt_mem 301
#define Codop_ui20 302
#define Colon 303
#define Comma 304
#define Cop0Register 305
#define DoubleGreat 306
#define DoubleLess 307
#define Identifier 308
#define IntegerRegister 309
#define LeftParen 310
#define Litteral 311
#define Macro_label 312
#define Macro_n 313
#define Macro_rd_i32 314
#define Macro_rd_rs 315
#define Macro_rd_rt 316
#define Macro_rd_label 317
#define Macro_rs_label 318
#define Minus 319
#define Plus 320
#define Register 321
#define RightParen 322
#define Slash 323
#define Star 324
#define String 325
#define String2 326
#define GCC_operator 327
#define Tilda 328
#define Arobase 329




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 63 "asm_mips.yac"

  struct utchn  *pchn    ;
  unsigned int   uval    ;
  char          *text    ;
  


/* Line 293 of yacc.c  */
#line 324 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 336 "y.tab.c"

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   373

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNRULES -- Number of states.  */
#define YYNSTATES  319

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    11,    14,    15,    18,
      22,    25,    28,    30,    32,    35,    36,    40,    42,    44,
      46,    48,    50,    53,    56,    57,    59,    64,    66,    70,
      74,    79,    84,    86,    90,    94,    98,   102,   106,   109,
     117,   120,   123,   125,   128,   133,   136,   144,   152,   159,
     164,   169,   174,   179,   186,   193,   200,   207,   214,   221,
     228,   231,   236,   241,   248,   255,   262,   267,   272,   277,
     285,   292,   297,   300,   303,   305,   307,   309,   311,   313,
     315,   317,   319,   321,   323,   325,   327,   329,   331,   333,
     335,   337,   339,   341,   343,   345,   348,   350,   355,   360,
     365,   370,   375,   377,   379,   381,   383,   385,   387,   389,
     391,   394,   397,   400,   405,   412,   415,   418,   421,   423,
     425,   427,   429,   431,   433,   435,   437,   439,   441,   443,
     445,   447,   449,   451,   453,   455,   457,   459,   461,   463,
     465,   467,   469,   471,   473,   476,   478,   481,   484,   487,
     490,   491,   494,   497,   500,   503,   506,   509,   512,   514,
     516,   518,   521,   524,   526,   528,   530,   532,   534,   536,
     538,   540,   542,   543,   545,   547,   549,   552,   553
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      81,     0,    -1,    65,    -1,    64,    -1,    -1,   125,    48,
      -1,     3,    56,    -1,    -1,    79,    80,    -1,    77,   155,
      85,    -1,   154,    85,    -1,     1,    85,    -1,    82,    -1,
      79,    -1,   123,    84,    -1,    -1,    84,    49,   123,    -1,
      24,    -1,    50,    -1,    21,    -1,   145,    -1,   128,    -1,
       8,    91,    -1,     9,    53,    -1,    -1,    53,    -1,    10,
      53,    49,   123,    -1,    94,    -1,    93,    76,    94,    -1,
      55,   123,    67,    -1,    73,    55,   123,    67,    -1,    64,
      55,   123,    67,    -1,   153,    -1,    94,   127,    94,    -1,
      95,   127,    94,    -1,    94,   146,    94,    -1,    96,    69,
      94,    -1,    94,   152,    94,    -1,    11,   125,    -1,    26,
     123,    49,   122,    55,   124,    67,    -1,    27,   123,    -1,
      27,   124,    -1,    28,    -1,    29,   124,    -1,    29,   124,
      49,   124,    -1,    30,   124,    -1,    38,   124,    49,   122,
      55,   124,    67,    -1,    38,   124,    49,    72,    55,   124,
      67,    -1,    38,   124,    49,    55,   124,    67,    -1,    38,
     124,    49,   123,    -1,    31,   124,    49,   122,    -1,    31,
     124,    49,    72,    -1,    32,   124,    49,   124,    -1,    33,
     124,    49,   124,    49,   124,    -1,    36,   124,    49,   124,
      49,   122,    -1,    36,   124,    49,   124,    49,    72,    -1,
      33,   124,    49,   124,    49,   122,    -1,    37,   124,    49,
     124,    49,   156,    -1,    35,   124,    49,   124,    49,   124,
      -1,    34,   124,    49,   124,    49,   123,    -1,    39,   124,
      -1,    40,   124,    49,   123,    -1,    41,   124,    49,   124,
      -1,    41,   124,    49,   124,    49,   124,    -1,    42,   124,
      49,   124,    49,   123,    -1,    42,   124,    49,   124,    49,
      71,    -1,    43,   124,    49,   122,    -1,    44,   124,    49,
      86,    -1,    45,   124,    49,    87,    -1,    46,   124,    49,
     122,    55,   124,    67,    -1,    46,   124,    49,    55,   124,
      67,    -1,    46,   124,    49,   123,    -1,    47,   123,    -1,
      12,   125,    -1,   123,    -1,    93,    -1,    96,    -1,    95,
      -1,    97,    -1,    54,    -1,    21,    -1,    53,    -1,    56,
      -1,    71,    -1,   136,    -1,    23,    -1,    22,    -1,    25,
      -1,   131,    -1,   132,    -1,   133,    -1,   134,    -1,   135,
      -1,   129,    -1,   130,    -1,    57,   123,    -1,    58,    -1,
      59,   124,    49,   123,    -1,    62,   124,    49,   123,    -1,
      60,   124,    49,   124,    -1,    61,   124,    49,   124,    -1,
      63,   124,    49,   123,    -1,   144,    -1,   139,    -1,   137,
      -1,   138,    -1,   143,    -1,   142,    -1,   141,    -1,   140,
      -1,     4,    70,    -1,     5,    70,    -1,     6,    83,    -1,
      13,    53,    49,    56,    -1,     7,    53,    49,    56,    49,
      56,    -1,    19,    56,    -1,    18,    56,    -1,    20,   157,
      -1,    99,    -1,   100,    -1,   101,    -1,   102,    -1,   103,
      -1,   104,    -1,   106,    -1,   107,    -1,   108,    -1,   109,
      -1,   110,    -1,   111,    -1,   105,    -1,   112,    -1,   113,
      -1,   114,    -1,   115,    -1,   116,    -1,   119,    -1,   117,
      -1,   118,    -1,   120,    -1,    69,    -1,    68,    -1,    56,
      -1,    53,    -1,    16,    53,    -1,    53,    -1,    17,    15,
      -1,    17,    14,    -1,    17,   123,    -1,    53,   151,    -1,
      -1,   151,    70,    -1,   151,    49,    -1,   151,    74,    -1,
     151,   124,    -1,   151,    53,    -1,   151,    56,    -1,   151,
      64,    -1,    52,    -1,    51,    -1,   147,    -1,    64,   147,
      -1,    73,   147,    -1,    78,    -1,   148,    -1,    92,    -1,
     121,    -1,    98,    -1,   149,    -1,    90,    -1,    89,    -1,
     150,    -1,    -1,   126,    -1,    88,    -1,   123,    -1,   123,
     158,    -1,    -1,   158,    49,   123,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   177,   177,   179,   183,   185,   191,   199,   201,   206,
     209,   211,   216,   220,   224,   235,   239,   250,   254,   259,
     264,   265,   269,   275,   282,   283,   288,   299,   301,   313,
     317,   322,   327,   332,   340,   351,   358,   365,   375,   384,
     403,   416,   430,   446,   456,   471,   485,   507,   529,   550,
     572,   584,   599,   615,   644,   661,   678,   695,   714,   733,
     752,   767,   789,   814,   847,   863,   883,   903,   920,   937,
     955,   972,   990,  1003,  1012,  1017,  1019,  1021,  1023,  1028,
    1030,  1035,  1037,  1042,  1049,  1053,  1055,  1057,  1062,  1063,
    1064,  1065,  1066,  1067,  1068,  1072,  1084,  1094,  1114,  1137,
    1151,  1167,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1195,  1204,  1213,  1219,  1230,  1243,  1252,  1261,  1267,  1268,
    1269,  1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,
    1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,
    1292,  1294,  1299,  1301,  1310,  1315,  1322,  1325,  1328,  1336,
    1346,  1350,  1357,  1364,  1371,  1378,  1385,  1392,  1401,  1403,
    1408,  1410,  1413,  1419,  1420,  1421,  1422,  1423,  1424,  1425,
    1426,  1428,  1431,  1433,  1434,  1438,  1443,  1454,  1458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ALIGN_", "_ASCII_", "_ASCIIZ_",
  "_BYTE_", "_COMM_", "_END_", "_ENT_", "_EQU_", "_EXTERN_", "_GLOBAL_",
  "_LCOMM_", "_NOREORDER_", "_REORDER_", "_SECTION_", "_SET_", "_SKIP_",
  "_SPACE_", "_WORD_", "ARegister", "Ampersand", "Bar", "CarriageReturn",
  "Circomflex", "Codop_hint_mem", "Codop_label", "Codop_n", "Codop_od_rs",
  "Codop_rd", "Codop_rd_si16", "Codop_rd_rs", "Codop_rd_rs_rt",
  "Codop_rd_rt_sham", "Codop_rd_rt_rs", "Codop_rd_rs_si16",
  "Codop_rd_rs_ui16", "Codop_rd_mem", "Codop_rs", "Codop_rs_label",
  "Codop_rs_rt", "Codop_rs_rt_label", "Codop_rs_si16", "Codop_rt_cop0r",
  "Codop_rt_cop2r", "Codop_rt_mem", "Codop_ui20", "Colon", "Comma",
  "Cop0Register", "DoubleGreat", "DoubleLess", "Identifier",
  "IntegerRegister", "LeftParen", "Litteral", "Macro_label", "Macro_n",
  "Macro_rd_i32", "Macro_rd_rs", "Macro_rd_rt", "Macro_rd_label",
  "Macro_rs_label", "Minus", "Plus", "Register", "RightParen", "Slash",
  "Star", "String", "String2", "GCC_operator", "Tilda", "Arobase",
  "$accept", "adding_operator", ".a_label.", "align_directive",
  "..an_instruction..", "an_instruction", "assembly_file",
  "assembly_instructions", "byte_immediate_list", "...byte_immediate..",
  "CarriageReturn_ERR", "cop0_reg", "cop2_reg", "effective_instruction",
  "end_directive", "ent_directive", ".Identifier.", "equ_directive",
  "expr..addop__expr..", "expression", "expr__logop__expr..logop__expr..",
  "expr__mulop__expr..mulop__expr..", "expr__shfop__expr",
  "extern_directive", "format_hint_mem", "format_label", "format_n",
  "format_od_rs", "format_rd", "format_rd_mem", "format_rd_si16",
  "format_rd_rs", "format_rd_rs_rt", "format_rd_rs_si16",
  "format_rd_rs_ui16", "format_rd_rt_rs", "format_rd_rt_sham", "format_rs",
  "format_rs_label", "format_rs_rt", "format_rs_rt_label",
  "format_rs_si16", "format_rt_cop0r", "format_rt_cop2r", "format_rt_mem",
  "format_ui20", "global_directive", "signed_16_bit_immediate",
  "immediate", "integer_register", "label", "labelable_directive",
  "logic_operator", "macro_instruction", "macro_label", "macro_n",
  "macro_rd_i32", "macro_rd_label", "macro_rd_rs", "macro_rd_rt",
  "macro_rs_label", "memory_alloc_directive", "memory_ascii_alloc",
  "memory_asciiz_alloc", "memory_byte_alloc", "memory_lcomm_alloc",
  "memory_comm_alloc", "memory_space_alloc", "memory_skip_alloc",
  "memory_word_alloc", "mips_instruction", "mul_div_operator", "primary",
  "section_specification_directive", "set_directive", "other_directive",
  "_String", "shift_operator", "term", "unlabeled_directive",
  ".unlabeled_instruction.", "unsigned_16_bit_immediate",
  "word_immediate_list", "...word_immediate..", 0
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
     325,   326,   327,   328,   329
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    76,    77,    77,    78,    79,    79,    80,
      80,    80,    81,    82,    83,    84,    84,    85,    86,    87,
      88,    88,    89,    90,    91,    91,    92,    93,    93,    94,
      94,    94,    94,    95,    95,    96,    96,    97,    98,    99,
     100,   100,   101,   102,   102,   103,   104,   104,   104,   104,
     105,   105,   106,   107,   108,   108,   108,   109,   110,   111,
     112,   113,   114,   114,   115,   115,   116,   117,   118,   119,
     119,   119,   120,   121,   122,   123,   123,   123,   123,   124,
     124,   125,   125,   125,   126,   127,   127,   127,   128,   128,
     128,   128,   128,   128,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   136,   136,   136,   136,   136,   136,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     146,   146,   147,   147,   148,   148,   149,   149,   149,   150,
     151,   151,   151,   151,   151,   151,   151,   151,   152,   152,
     153,   153,   153,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   155,   155,   155,   156,   157,   158,   158
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     2,     0,     2,     3,
       2,     2,     1,     1,     2,     0,     3,     1,     1,     1,
       1,     1,     2,     2,     0,     1,     4,     1,     3,     3,
       4,     4,     1,     3,     3,     3,     3,     3,     2,     7,
       2,     2,     1,     2,     4,     2,     7,     7,     6,     4,
       4,     4,     4,     6,     6,     6,     6,     6,     6,     6,
       2,     4,     4,     6,     6,     6,     4,     4,     4,     7,
       6,     4,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     4,     4,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     4,     6,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     2,     2,     2,
       0,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     2,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,    12,     0,     0,    24,     0,     0,     0,
       0,     0,     0,   150,    82,    83,   172,   163,     8,   170,
     169,   165,   167,   166,     0,   164,   168,   171,     0,     1,
      17,    11,     6,    25,    22,    23,     0,    81,    38,    73,
     144,   147,   146,   143,     0,   142,     0,     0,    75,    27,
      77,    76,    78,   148,   160,    32,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,   174,   118,   119,   120,   121,   122,
     123,   130,   124,   125,   126,   127,   128,   129,   131,   132,
     133,   134,   135,   137,   138,   136,   139,   173,    21,    93,
      94,    88,    89,    90,    91,    92,    84,   104,   105,   103,
     109,   108,   107,   106,   102,    20,     0,     5,    10,     0,
       0,     0,   161,     0,   162,     3,     2,     0,    86,    85,
      87,   159,   158,   141,   140,     0,     0,     0,     0,     0,
      80,   152,   155,    79,   156,   157,   151,   153,   154,   110,
     111,   112,    15,     0,     0,   116,   115,   177,   117,     0,
      40,    41,    43,    45,     0,     0,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
      72,    95,     0,     0,     0,     0,     0,     9,    26,    29,
       0,     0,    28,    33,    35,    37,    34,    36,    14,     0,
       0,   176,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    30,     0,     0,   113,     0,
       0,    74,    44,    51,    50,    52,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    61,    62,     0,    66,    18,
      67,    19,    68,     0,     0,    71,    97,    99,   100,    98,
     101,    16,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,    56,
      53,    59,    58,    55,    54,   175,    57,    48,     0,     0,
      63,    65,    64,    70,     0,    39,    47,    46,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   147,    16,    17,     1,    18,     2,     3,   171,   218,
      31,   270,   272,    94,    19,    20,    34,    21,    48,    49,
      50,    51,    52,    22,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    23,   250,   251,   168,
      24,   117,   155,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   156,    54,    25,    26,    27,    56,   157,    55,    28,
     136,   306,   178,   221
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -224
static const yytype_int16 yypact[] =
{
    -224,   132,    11,  -224,   -11,   -37,   -24,   -23,   -16,   -35,
     -35,    -9,    -5,   -17,  -224,  -224,   310,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,    -2,  -224,  -224,  -224,   -11,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,     6,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,    61,  -224,   -33,   -29,   -60,   184,
      20,     3,  -224,  -224,  -224,  -224,     7,   -13,    -6,    61,
      25,    26,    24,    28,    61,    61,   -15,  -224,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,    61,    61,  -224,   -19,
     -19,   -19,   -19,   -19,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,   -11,  -224,  -224,    61,
       9,    61,  -224,    61,  -224,  -224,  -224,    61,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,    61,    61,    61,    61,    61,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,    33,    54,  -224,  -224,  -224,  -224,    55,
    -224,  -224,    56,  -224,    63,    64,    66,    69,    70,    71,
      72,    73,  -224,    74,    75,    77,    79,    81,    97,    98,
    -224,  -224,   104,   105,   106,   108,   131,  -224,  -224,  -224,
     114,   115,  -224,  -224,  -224,  -224,  -224,  -224,   134,   128,
     130,   138,    61,   -19,   -39,   -19,   -19,   -19,   -19,   -19,
     -19,   144,    61,   -19,   -19,    61,   146,    52,   159,    61,
     -19,   -19,    61,    61,  -224,  -224,    61,   152,  -224,    61,
     143,  -224,  -224,  -224,  -224,  -224,   161,   162,   169,   175,
     176,   -15,   173,   174,   178,  -224,   189,   190,  -224,  -224,
    -224,  -224,  -224,   -15,   186,   178,  -224,  -224,  -224,  -224,
    -224,  -224,   192,  -224,   -19,   -15,    61,   -19,   149,    61,
     187,   -19,   -19,   -19,   212,   188,   -19,  -224,   193,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,   195,   196,
    -224,  -224,  -224,  -224,   197,  -224,  -224,  -224,  -224
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
     -25,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,   137,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -223,   -12,    17,
      57,  -224,   206,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,    23,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -146
static const yytype_int16 yytable[] =
{
      53,   254,   160,   138,   145,   146,   160,  -145,   263,    41,
      42,    29,   268,    30,    43,   274,    44,    45,    37,    32,
      43,    14,   141,    45,    43,    46,   143,    45,   160,    33,
      35,   -81,   140,   253,    47,   163,    15,    36,    43,   163,
      44,    45,   148,   149,    40,   150,   137,   172,    43,    46,
      44,    45,   177,   179,   180,   139,   161,   169,    47,    46,
     162,   163,   299,   164,   170,   304,    38,    39,    47,   142,
     144,   165,   159,   271,   200,   201,   209,   166,   173,   174,
     175,   167,   219,   181,   176,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   220,   222,   223,   202,   203,   204,   205,
     206,   207,   224,   225,    43,   226,    44,    45,   227,   228,
     229,   230,   231,   232,   233,    46,   234,   208,   235,   210,
     236,   211,   -13,     4,    47,     5,    -4,    -4,    -4,    -4,
       6,     7,     8,     9,    10,    -4,   237,   238,    11,    12,
      -4,    -4,    -4,   239,   240,   241,    -4,   242,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
     243,   244,   245,   246,   247,    13,   248,   249,    14,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,   269,    43,   284,   261,
      45,   282,    43,    15,    44,    45,   148,   149,    46,   150,
     285,   286,    43,    46,   273,    45,   262,    47,   287,   264,
     265,   303,    47,    46,   288,   289,   275,   276,   291,   292,
     279,   280,    47,   -74,   281,   151,   152,   283,   293,   294,
     252,   296,   255,   256,   257,   258,   259,   260,   297,   140,
     266,   267,   153,   154,   307,   313,   158,   277,   278,     0,
     315,   140,   316,   317,   318,    43,     0,    44,    45,     0,
       0,     0,     0,     0,   301,     0,    46,   305,   290,     0,
       0,     0,   312,   311,   212,    47,     0,     0,     0,     0,
     295,     0,   213,   214,   215,   216,   217,     0,     0,     0,
       0,   298,   300,     0,   302,     0,     0,     0,   308,   309,
     310,     0,     0,   314,    57,    58,    59,    60,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,    62,    63,
      64,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,    91,    92,    93
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-224))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      12,   224,    21,    28,    64,    65,    21,    24,   231,    14,
      15,     0,   235,    24,    53,   238,    55,    56,    53,    56,
      53,    56,    55,    56,    53,    64,    55,    56,    21,    53,
      53,    48,    44,    72,    73,    54,    71,    53,    53,    54,
      55,    56,    22,    23,    53,    25,    48,    59,    53,    64,
      55,    56,    64,    65,    66,    49,    49,    70,    73,    64,
      53,    54,   285,    56,    70,   288,     9,    10,    73,    46,
      47,    64,    69,    21,    86,    87,    67,    70,    53,    53,
      56,    74,    49,    66,    56,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    49,    49,    49,    89,    90,    91,    92,
      93,   136,    49,    49,    53,    49,    55,    56,    49,    49,
      49,    49,    49,    49,    49,    64,    49,   139,    49,   141,
      49,   143,     0,     1,    73,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    49,    49,    16,    17,
      18,    19,    20,    49,    49,    49,    24,    49,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      49,    67,    67,    49,    56,    53,    56,    49,    56,    57,
      58,    59,    60,    61,    62,    63,    50,    53,    55,    55,
      56,    49,    53,    71,    55,    56,    22,    23,    64,    25,
      49,    49,    53,    64,    55,    56,    72,    73,    49,   231,
     232,    72,    73,    64,    49,    49,   238,   239,    55,    55,
     242,   243,    73,    55,   246,    51,    52,   249,    49,    49,
     223,    55,   225,   226,   227,   228,   229,   230,    56,   261,
     233,   234,    68,    69,    67,    67,    50,   240,   241,    -1,
      67,   273,    67,    67,    67,    53,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,   286,    -1,    64,   289,   261,    -1,
      -1,    -1,   294,    71,   147,    73,    -1,    -1,    -1,    -1,
     273,    -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,   284,   285,    -1,   287,    -1,    -1,    -1,   291,   292,
     293,    -1,    -1,   296,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    79,    81,    82,     1,     3,     8,     9,    10,    11,
      12,    16,    17,    53,    56,    71,    77,    78,    80,    89,
      90,    92,    98,   121,   125,   148,   149,   150,   154,     0,
      24,    85,    56,    53,    91,    53,    53,    53,   125,   125,
      53,    14,    15,    53,    55,    56,    64,    73,    93,    94,
      95,    96,    97,   123,   147,   153,   151,     4,     5,     6,
       7,    13,    18,    19,    20,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    57,    58,    59,
      60,    61,    62,    63,    88,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   126,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   155,    48,    85,    49,
     123,    55,   147,    55,   147,    64,    65,    76,    22,    23,
      25,    51,    52,    68,    69,   127,   146,   152,   127,    69,
      21,    49,    53,    54,    56,    64,    70,    74,   124,    70,
      70,    83,   123,    53,    53,    56,    56,   123,   157,   123,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     123,   123,   124,   124,   124,   124,   124,    85,   123,    67,
     123,   123,    94,    94,    94,    94,    94,    94,    84,    49,
      49,   158,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    67,    67,    49,    56,    56,    49,
     122,   123,   124,    72,   122,   124,   124,   124,   124,   124,
     124,    55,    72,   122,   123,   123,   124,   124,   122,    50,
      86,    21,    87,    55,   122,   123,   123,   124,   124,   123,
     123,   123,    49,   123,    55,    49,    49,    49,    49,    49,
     124,    55,    55,    49,    49,   124,    55,    56,   124,   122,
     124,   123,   124,    72,   122,   123,   156,    67,   124,   124,
     124,    71,   123,    67,   124,    67,    67,    67,    67
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/*----------.
| yyparse.  |
`----------*/

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
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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

/* Line 1806 of yacc.c  */
#line 178 "asm_mips.yac"
    { (yyval.uval) = ASM_OPR__PLUS ; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 180 "asm_mips.yac"
    { (yyval.uval) = ASM_OPR__MINUS; }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 187 "asm_mips.yac"
    { prog.add_line(new Label((yyvsp[(1) - (2)].text))) ; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 193 "asm_mips.yac"
    {	std::ostringstream lit ;
		    lit << (yyvsp[(2) - (2)].uval);
			prog.add_line(new Directive(".align",lit.str())) ;
		}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 226 "asm_mips.yac"
    {	std::ostringstream bylist ;
		    bylist << (yyvsp[(1) - (2)].uval) << strmap[(yyvsp[(2) - (2)].uval)] ;
			strmap[strmap_id] = bylist.str() ;
			(yyval.uval) = (yyvsp[(2) - (2)].uval) ;
		}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 235 "asm_mips.yac"
    {	strmap_id++ ;
			strmap[strmap_id] = "" ;
			(yyval.uval) = strmap_id ;
		}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 242 "asm_mips.yac"
    {	std::ostringstream bylist ;
		    bylist << strmap[(yyvsp[(1) - (3)].uval)] << "," << (yyvsp[(3) - (3)].uval);
			strmap[strmap_id] = bylist.str() ;
			(yyval.uval) = (yyvsp[(1) - (3)].uval) ;
		}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 255 "asm_mips.yac"
    { (yyval.uval) = (yyvsp[(1) - (1)].uval); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 260 "asm_mips.yac"
    { (yyval.uval) = (yyvsp[(1) - (1)].uval) & 0x00003fff; }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 271 "asm_mips.yac"
    {	prog.add_line(new Directive(".end",(yyvsp[(2) - (2)].text),false)) ; }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 277 "asm_mips.yac"
    { prog.add_line(new Directive(".ent",(yyvsp[(2) - (2)].text),true)) ; }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 282 "asm_mips.yac"
    { (yyval.text) = NULL; }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 284 "asm_mips.yac"
    { (yyval.text) = (yyvsp[(1) - (1)].text)  ; }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 292 "asm_mips.yac"
    {	std::ostringstream lit ;
		    lit << (yyvsp[(2) - (4)].text) << ",	" << (yyvsp[(4) - (4)].uval) ;
			prog.add_line(new Directive(".equ",lit.str())) ;
		}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 300 "asm_mips.yac"
    { (yyval.uval) = (yyvsp[(1) - (1)].uval); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 304 "asm_mips.yac"
    {
		if   ((yyvsp[(2) - (3)].uval) == ASM_OPR__PLUS)
			{(yyval.uval) = (yyvsp[(1) - (3)].uval) + (yyvsp[(3) - (3)].uval);}
		else
			{(yyval.uval) = (yyvsp[(1) - (3)].uval) - (yyvsp[(3) - (3)].uval);}
		}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 316 "asm_mips.yac"
    { (yyval.uval) =   (yyvsp[(2) - (3)].uval); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 321 "asm_mips.yac"
    { (yyval.uval) = ~ (yyvsp[(3) - (4)].uval); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 326 "asm_mips.yac"
    { (yyval.uval) = - (yyvsp[(3) - (4)].uval); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 328 "asm_mips.yac"
    { (yyval.uval) =   (yyvsp[(1) - (1)].uval); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 335 "asm_mips.yac"
    {
		if   ((yyvsp[(2) - (3)].uval) == ASM_OPR__OR  ) (yyval.uval) = (yyvsp[(1) - (3)].uval) | (yyvsp[(3) - (3)].uval);
		if   ((yyvsp[(2) - (3)].uval) == ASM_OPR__AND ) (yyval.uval) = (yyvsp[(1) - (3)].uval) & (yyvsp[(3) - (3)].uval);
		if   ((yyvsp[(2) - (3)].uval) == ASM_OPR__XOR ) (yyval.uval) = (yyvsp[(1) - (3)].uval) ^ (yyvsp[(3) - (3)].uval);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 343 "asm_mips.yac"
    {
		if   ((yyvsp[(2) - (3)].uval) == ASM_OPR__OR  ) (yyval.uval) = (yyvsp[(1) - (3)].uval) | (yyvsp[(3) - (3)].uval);
		if   ((yyvsp[(2) - (3)].uval) == ASM_OPR__AND ) (yyval.uval) = (yyvsp[(1) - (3)].uval) & (yyvsp[(3) - (3)].uval);
		if   ((yyvsp[(2) - (3)].uval) == ASM_OPR__XOR ) (yyval.uval) = (yyvsp[(1) - (3)].uval) ^ (yyvsp[(3) - (3)].uval);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 354 "asm_mips.yac"
    {
		if   ((yyvsp[(2) - (3)].uval) == ASM_OPR__MUL ) (yyval.uval) = (yyvsp[(1) - (3)].uval) * (yyvsp[(3) - (3)].uval);
		else                       (yyval.uval) = (yyvsp[(1) - (3)].uval) / (yyvsp[(3) - (3)].uval);
		}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 361 "asm_mips.yac"
    { (yyval.uval) = (yyvsp[(1) - (3)].uval) * (yyvsp[(3) - (3)].uval); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 368 "asm_mips.yac"
    {
		if   ((yyvsp[(2) - (3)].uval) == ASM_OPR__SHL ) (yyval.uval) = (yyvsp[(1) - (3)].uval) << (yyvsp[(3) - (3)].uval);
		else                       (yyval.uval) = (yyvsp[(1) - (3)].uval) >> (yyvsp[(3) - (3)].uval);
		}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 377 "asm_mips.yac"
    {	std::ostringstream lab ;
		    lab << (yyvsp[(2) - (2)].text);
			prog.add_line(new Directive(".extern",lab.str())) ;
		}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 391 "asm_mips.yac"
    {	t_Operator op ;
			string m = strmap[(yyvsp[(2) - (7)].uval)] ;
			
			switch((yyvsp[(1) - (7)].uval)) {
				case ASM_MPS__PREF : op = pref ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (7)].uval) << "is not an valid Codop_hint_mem for format_hint_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPImmediate((yyvsp[(2) - (7)].uval)),new OPImmediate((yyvsp[(4) - (7)].uval)),new OPRegister((yyvsp[(6) - (7)].uval),Src))) ;	
		}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 405 "asm_mips.yac"
    {	t_Operator op ;
			string m = strmap[(yyvsp[(2) - (2)].uval)] ;
			
			switch((yyvsp[(1) - (2)].uval)) {
				case ASM_MPS__J : op = j ; break ;
				case ASM_MPS__JAL : op = jal ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (2)].uval) << "is not an valid Codop_label for format_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPLabel(m))) ;	
		}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 418 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (2)].uval)) {
				case ASM_MPS__J : op = jr ; break ;
				case ASM_MPS__JAL : op = jalr ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (2)].uval) << "is not an valid Codop_label for format_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (2)].uval),Src))) ;
		}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 431 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (1)].uval)) {
				case ASM_MPS__SYSCALL : op = syscallu ; break ;
				case ASM_MPS__WAIT : op = waitn ; break ;
				case ASM_MPS__RFE : op = rfe ; break ;
				case ASM_MPS__ERET : op = eret ; break ;
				case ASM_MPS__SYNC : op = sync_ ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (1)].uval) << "is not an valid Codop_n for format_n" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op)) ;
		}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 448 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (2)].uval)) {
				case ASM_MPS__JALR : op = jalr ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (2)].uval) << "is not an valid Codop_od_rs for format_od_rs" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (2)].uval),Src))) ;
		}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 460 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (4)].uval)) {
				case ASM_MPS__JALR : op = jalr ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Codop_od_rs for format_od_rs" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (4)].uval),Dst),new OPRegister((yyvsp[(4) - (4)].uval),Src))) ;
		}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 473 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (2)].uval)) {
				case ASM_MPS__MFHI : op = mfhi ; break ;
				case ASM_MPS__MFLO : op = mflo ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (2)].uval) << "is not an valid Codop_rd for format_rd" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (2)].uval),Dst))) ;
		}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 492 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (7)].uval)) {
				case ASM_MPS__LB : op = lb ; break ;
				case ASM_MPS__LBU : op = lbu ; break ;
				case ASM_MPS__LH : op = lh ; break ;
				case ASM_MPS__LHU : op = lhu ; break ;
				case ASM_MPS__LW : op = lw ; break ;
				case ASM_MPS__LWL : op = lwl ; break ;
				case ASM_MPS__LWR : op = lwr ; break ;
				case ASM_MPS__LL : op = ll ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (7)].uval) << "is not an valid Codop_rd_mem for format_rd_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (7)].uval),Dst),new OPImmediate((yyvsp[(4) - (7)].uval)),new OPRegister((yyvsp[(6) - (7)].uval),Src))) ;
		}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 514 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (7)].uval)) {
				case ASM_MPS__LB : op = lb ; break ;
				case ASM_MPS__LBU : op = lbu ; break ;
				case ASM_MPS__LH : op = lh ; break ;
				case ASM_MPS__LHU : op = lhu ; break ;
				case ASM_MPS__LW : op = lw ; break ;
				case ASM_MPS__LWL : op = lwl ; break ;
				case ASM_MPS__LWR : op = lwr ; break ;
				case ASM_MPS__LL : op = ll ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (7)].uval) << "is not an valid Codop_rd_mem for format_rd_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (7)].uval),Dst),new OPExpression((yyvsp[(4) - (7)].text)),new OPRegister((yyvsp[(6) - (7)].uval),Src))) ;
		}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 535 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (6)].uval)) {
				case ASM_MPS__LB : op = lb ; break ;
				case ASM_MPS__LBU : op = lbu ; break ;
				case ASM_MPS__LH : op = lh ; break ;
				case ASM_MPS__LHU : op = lhu ; break ;
				case ASM_MPS__LW : op = lw ; break ;
				case ASM_MPS__LWL : op = lwl ; break ;
				case ASM_MPS__LWR : op = lwr ; break ;
				case ASM_MPS__LL : op = ll ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (6)].uval) << "is not an valid Codop_rd_mem for format_rd_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (6)].uval),Dst),new OPRegister((yyvsp[(5) - (6)].uval),Src))) ;
		}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 554 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (4)].uval)) {
				case ASM_MPS__LB : op = lb ; break ;
				case ASM_MPS__LBU : op = lbu ; break ;
				case ASM_MPS__LH : op = lh ; break ;
				case ASM_MPS__LHU : op = lhu ; break ;
				case ASM_MPS__LW : op = lw ; break ;
				case ASM_MPS__LWL : op = lwl ; break ;
				case ASM_MPS__LWR : op = lwr ; break ;
				case ASM_MPS__LL : op = ll ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Codop_rd_mem for format_rd_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (4)].uval),Dst),new OPImmediate((yyvsp[(4) - (4)].uval)))) ;
		}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 576 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (4)].uval)) {
				case ASM_MPS__LUI : op = lui ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Codop_rd_si16 for format_rd_si16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (4)].uval),Dst),new OPImmediate((yyvsp[(4) - (4)].uval)))) ;
		}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 588 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (4)].uval)) {
				case ASM_MPS__LUI : op = lui ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Codop_rd_si16 for format_rd_si16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (4)].uval),Dst),new OPExpression((yyvsp[(4) - (4)].text)))) ;
		}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 603 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (4)].uval)) {
				case ASM_MPS__CLO : op = clo ; break ;
				case ASM_MPS__CLZ : op = clz ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Codop_rd_rs for format_rd_rs" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (4)].uval),Dst),new OPRegister((yyvsp[(4) - (4)].uval),Src))) ;
		}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 621 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (6)].uval)) {
				case ASM_MPS__ADD :	op = add; break ;
				case ASM_MPS__ADDU :op = addu ; break ;
				case ASM_MPS__AND :	op = and_ ; break ;
				case ASM_MPS__MUL :	op = mul ; break ;
				case ASM_MPS__NOR :	op = nor ; break ;
				case ASM_MPS__OR :	op = or_ ; break ;
				case ASM_MPS__SLT :	op = slt ; break ;
				case ASM_MPS__SLTU :op = sltu ; break ;
				case ASM_MPS__SUB :	op = sub ; break ;
				case ASM_MPS__SUBU :op = subu ; break ;
				case ASM_MPS__XOR :	op = xor_ ; break ;
				case ASM_MPS__MOVN :op = movn ; break ;
				case ASM_MPS__MOVZ :op = movz ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (6)].uval) << "is not an valid Codop_rd_rs_rt for format_rd_rs_rt" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (6)].uval),Dst),new OPRegister((yyvsp[(4) - (6)].uval),Src),new OPRegister((yyvsp[(6) - (6)].uval),Src))) ;
		}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 650 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (6)].uval)) {
				case ASM_MPS__ADDI : op = addi ; break ;
				case ASM_MPS__ADDIU : op = addiu ; break ;
				case ASM_MPS__SLTI : op = slti ; break ;
				case ASM_MPS__SLTIU : op = sltiu ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (6)].uval) << "is not an valid Codop_rd_rs_si16 for format_rd_rs_si16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (6)].uval),Dst),new OPRegister((yyvsp[(4) - (6)].uval),Src),new OPImmediate((yyvsp[(6) - (6)].uval)))) ;
		}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 667 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (6)].uval)) {
				case ASM_MPS__ADDI : op = addi ; break ;
				case ASM_MPS__ADDIU : op = addiu ; break ;
				case ASM_MPS__SLTI : op = slti ; break ;
				case ASM_MPS__SLTIU : op = sltiu ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (6)].uval) << "is not an valid Codop_rd_rs_si16 for format_rd_rs_si16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (6)].uval),Dst),new OPRegister((yyvsp[(4) - (6)].uval),Src),new OPExpression((yyvsp[(6) - (6)].text)))) ;
		}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 684 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (6)].uval)) {
				case ASM_MPS__SLT : op = slti ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (6)].uval) << "is not an valid Codop_rd_rs_si16 for format_rd_rs_si16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (6)].uval),Dst),new OPRegister((yyvsp[(4) - (6)].uval),Src),new OPImmediate((yyvsp[(6) - (6)].uval)))) ;
		}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 701 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (6)].uval)) {
				case ASM_MPS__ANDI : op = andi ; break ;
				case ASM_MPS__ORI : op = ori ; break ;
				case ASM_MPS__XORI : op = xori ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (6)].uval) << "is not an valid Codop_rd_rs_ui16 for format_rd_rs_ui16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (6)].uval),Dst),new OPRegister((yyvsp[(4) - (6)].uval),Src),new OPImmediate((yyvsp[(6) - (6)].uval)))) ;
		}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 720 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (6)].uval)) {
				case ASM_MPS__SLLV : op = sllv ; break ;
				case ASM_MPS__SRLV : op = srlv ; break ;
				case ASM_MPS__SRAV : op = srav ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (6)].uval) << "is not an valid Codop_rd_rt_rs for format_rd_rt_rs" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (6)].uval),Dst),new OPRegister((yyvsp[(4) - (6)].uval),Src),new OPRegister((yyvsp[(6) - (6)].uval),Src))) ;
		}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 739 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (6)].uval)) {
				case ASM_MPS__SLL : op = sll ; break ;
				case ASM_MPS__SRL : op = srl ; break ;
				case ASM_MPS__SRA : op = sra ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (6)].uval) << "is not an valid Codop_rd_rt_sham for format_rd_rt_sham" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (6)].uval),Dst),new OPRegister((yyvsp[(4) - (6)].uval),Src),new OPImmediate((yyvsp[(6) - (6)].uval)))) ;
		}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 754 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (2)].uval)) {
				case ASM_MPS__JR : op = jr ; break ;
				case ASM_MPS__MTHI : op = mthi ; break ;
				case ASM_MPS__MTLO : op = mtlo ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (2)].uval) << "is not an valid Codop_rs for format_rs" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (2)].uval),Src))) ;
		}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 771 "asm_mips.yac"
    {
			t_Operator op ;
			string m = strmap[(yyvsp[(4) - (4)].uval)] ;
			switch((yyvsp[(1) - (4)].uval)) {
				case ASM_MPS__BGEZ : op = bgez ; break ;
				case ASM_MPS__BGEZAL : op = bgezal ; break ;
				case ASM_MPS__BGTZ : op = bgtz ; break ;
				case ASM_MPS__BLEZ : op = blez ; break ;
				case ASM_MPS__BLTZ : op = bltz ; break ;
				case ASM_MPS__BLTZAL : op = bltzal ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Codop_rs_label for format_rs_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (4)].uval),Src),new OPLabel(m))) ;
		}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 793 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (4)].uval)) {
				case ASM_MPS__MULT: op = mult; break ;
				case ASM_MPS__MULTU: op = multu; break ;
				case ASM_MPS__DIV: op = div_ ; break ;
				case ASM_MPS__DIVU: op = divu ; break ;
				case ASM_MPS__MADD: op = madd; break ;
				case ASM_MPS__MADDU: op = maddu; break ;
				case ASM_MPS__MSUB: op = msub; break ;
				case ASM_MPS__MSUBU: op = msubu; break ;
				case ASM_MPS__TEQ: op = teq; break ;
				case ASM_MPS__TGE: op = tge; break ;
				case ASM_MPS__TGEU: op = tgeu; break ;
				case ASM_MPS__TLT: op = tlt; break ;
				case ASM_MPS__TLTU: op = tltu; break ;
				case ASM_MPS__TNE: op = tne ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Codop_rs_label for format_rs_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (4)].uval),Src),new OPRegister((yyvsp[(4) - (4)].uval),Src))) ;
		}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 820 "asm_mips.yac"
    {
			t_Operator op ;
			if ((yyvsp[(2) - (6)].uval) != 0 ) {
				std::cerr << "Invalid $zero register for Codop_rs_label" << std::endl ;
			}
			switch((yyvsp[(1) - (6)].uval)) {
				case ASM_MPS__MULT: op = mult; break ;
				case ASM_MPS__MULTU: op = multu; break ;
				case ASM_MPS__DIV: op = div_ ; break ;
				case ASM_MPS__DIVU: op = divu ; break ;
				case ASM_MPS__MADD: op = madd; break ;
				case ASM_MPS__MADDU: op = maddu; break ;
				case ASM_MPS__MSUB: op = msub; break ;
				case ASM_MPS__MSUBU: op = msubu; break ;
				case ASM_MPS__TEQ: op = teq; break ;
				case ASM_MPS__TGE: op = tge; break ;
				case ASM_MPS__TGEU: op = tgeu; break ;
				case ASM_MPS__TLT: op = tlt; break ;
				case ASM_MPS__TLTU: op = tltu; break ;
				case ASM_MPS__TNE: op = tne ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (6)].uval) << "is not an valid Codop_rs_label for format_rs_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (6)].uval),Dst),new OPRegister((yyvsp[(4) - (6)].uval),Src),new OPRegister((yyvsp[(6) - (6)].uval),Src))) ;
		}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 853 "asm_mips.yac"
    {
			t_Operator op ;
			string m = strmap[(yyvsp[(6) - (6)].uval)] ;
			switch((yyvsp[(1) - (6)].uval)) {
				case ASM_MPS__BEQ : op = beq ; break ;
				case ASM_MPS__BNE : op = bne ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (6)].uval) << "is not an valid Codop_rs_rt_label for format_rs_rt_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (6)].uval),Src),new OPRegister((yyvsp[(4) - (6)].uval),Src),new OPLabel(m))) ;
		}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 869 "asm_mips.yac"
    {
			t_Operator op ;
			std::ostringstream lit ;
		    lit  << (yyvsp[(6) - (6)].text) ;
			switch((yyvsp[(1) - (6)].uval)) {
				case ASM_MPS__BEQ : op = beq ; break ;
				case ASM_MPS__BNE : op = bne ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (6)].uval) << "is not an valid Codop_rs_rt_label for format_rs_rt_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (6)].uval),Src),new OPRegister((yyvsp[(4) - (6)].uval),Src),new OPLabel(lit.str()))) ;
		}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 887 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (4)].uval)) {
				case ASM_MPS__TEQI: op = teqi; break ;
				case ASM_MPS__TGEI: op = tgei; break ;
				case ASM_MPS__TGEIU: op = tgeiu; break ;
				case ASM_MPS__TLTI: op = tlti; break ;
				case ASM_MPS__TLTIU: op = tltiu; break ;
				case ASM_MPS__TNEI: op = tnei; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Codop_rs_si16 for format_rs_si16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (4)].uval),Src),new OPImmediate((yyvsp[(4) - (4)].uval)))) ;
		}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 907 "asm_mips.yac"
    {
			t_Operator op ;
			t_Src_Dst spin, spinc0 ;
			switch((yyvsp[(1) - (4)].uval)) {
				case ASM_MPS__MFC0: op = mfc0; spin = Dst ; spinc0 = CopSrc ; break ;
				case ASM_MPS__MTC0: op = mtc0; spin = Src ; spinc0 = CopDst ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Codop_rt_cop0r for format_rt_cop0r" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (4)].uval),spin),new OPRegister((yyvsp[(4) - (4)].uval),spinc0))) ;
		}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 924 "asm_mips.yac"
    {
			t_Operator op ;
			t_Src_Dst spin, spinc0 ;
			switch((yyvsp[(1) - (4)].uval)) {
				case ASM_MPS__MFC2: op = mfc2; spin = Dst ; spinc0 = CopSrc ; break ;
				case ASM_MPS__MTC2: op = mtc2; spin = Src ; spinc0 = CopDst ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Codop_rt_cop2r for format_rt_cop2r" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (4)].uval),spin),new OPRegister((yyvsp[(4) - (4)].uval),spinc0))) ;
		}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 944 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (7)].uval)) {
				case ASM_MPS__SB: op = sb ; break ;
				case ASM_MPS__SH: op = sh ; break ;
				case ASM_MPS__SW: op = sw ; break ;
				case ASM_MPS__SC: op = sc ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (7)].uval) << "is not an valid Codop_rt_mem for format_rt_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (7)].uval),Src),new OPImmediate((yyvsp[(4) - (7)].uval)),new OPRegister((yyvsp[(6) - (7)].uval),Src))) ;
		}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 961 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (6)].uval)) {
				case ASM_MPS__SB: op = sb ; break ;
				case ASM_MPS__SH: op = sh ; break ;
				case ASM_MPS__SW: op = sw ; break ;
				case ASM_MPS__SC: op = sc ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (6)].uval) << "is not an valid Codop_rt_mem for format_rt_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (6)].uval),Src),new OPRegister((yyvsp[(5) - (6)].uval),Src))) ;
		}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 976 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (4)].uval)) {
				case ASM_MPS__SB: op = sb ; break ;
				case ASM_MPS__SH: op = sh ; break ;
				case ASM_MPS__SW: op = sw ; break ;
				case ASM_MPS__SC: op = sc ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Codop_rt_mem for format_rt_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[(2) - (4)].uval),Src),new OPImmediate((yyvsp[(4) - (4)].uval)))) ;
		}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 992 "asm_mips.yac"
    {
			t_Operator op ;
			switch((yyvsp[(1) - (2)].uval)) {
				case ASM_MPS__BREAK: op = break_ ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (2)].uval) << "is not an valid Codop_ui20 for format_ui20" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPImmediate((yyvsp[(2) - (2)].uval)))) ;
		}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1005 "asm_mips.yac"
    {	std::ostringstream lab ;
		    lab << (yyvsp[(2) - (2)].text);
			prog.add_line(new Directive(".global",lab.str())) ;
		}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1013 "asm_mips.yac"
    { (yyval.uval) = (yyvsp[(1) - (1)].uval) & 0x0000ffff; }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1018 "asm_mips.yac"
    {  (yyval.uval) = (yyvsp[(1) - (1)].uval); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 1020 "asm_mips.yac"
    {  (yyval.uval) = (yyvsp[(1) - (1)].uval); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1022 "asm_mips.yac"
    {  (yyval.uval) = (yyvsp[(1) - (1)].uval); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1024 "asm_mips.yac"
    {  (yyval.uval) = (yyvsp[(1) - (1)].uval); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1029 "asm_mips.yac"
    {  (yyval.uval) = (yyvsp[(1) - (1)].uval); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 1031 "asm_mips.yac"
    { (yyval.uval) = (yyvsp[(1) - (1)].uval) & 0x0000001f; }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 1036 "asm_mips.yac"
    { (yyval.text) = (yyvsp[(1) - (1)].text); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1038 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << (yyvsp[(1) - (1)].uval);
			(yyval.text) = const_cast<char*>(str.str().c_str()) ;
		}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1043 "asm_mips.yac"
    { 
		std::cout << "Label String2 " << (yyvsp[(1) - (1)].text) << std::endl ;
		(yyval.text) = (yyvsp[(1) - (1)].text); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1054 "asm_mips.yac"
    { (yyval.uval) = ASM_OPR__OR   ; }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1056 "asm_mips.yac"
    { (yyval.uval) = ASM_OPR__AND  ; }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1058 "asm_mips.yac"
    { (yyval.uval) = ASM_OPR__XOR  ; }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1074 "asm_mips.yac"
    {
			string m = strmap[(yyvsp[(2) - (2)].uval)] ;
	  		if ((yyvsp[(1) - (2)].uval) != ASM_MPS__B) {
				std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (2)].uval) << "is not an valid Macro_label" << std::endl ;
			}
			prog.add_line(new Instruction(bgez,new OPRegister(0,Src),new OPLabel(m))) ;
		}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1085 "asm_mips.yac"
    {
	  		if ((yyvsp[(1) - (1)].uval) != ASM_MPS__NOP) {
				std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (1)].uval) << "is not an valid Macro_n" << std::endl ;
			}
			prog.add_line(new Instruction(add,new OPRegister(0,Dst),new OPRegister(0,Src),new OPRegister(0,Src))) ;
		}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1098 "asm_mips.yac"
    {
	  		if ((yyvsp[(1) - (4)].uval) != ASM_MPS__LI) {
				std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Macro_rd_i32" << std::endl ;
			}
			int hi, lo ;
			hi = ((yyvsp[(4) - (4)].uval) >> 16) &  0x0000FFFF ;
			lo = ((yyvsp[(4) - (4)].uval)      ) &  0x0000FFFF ;
						
			prog.add_line(new Directive(".set","noat")) ; 
			prog.add_line(new Instruction(lui,new OPRegister(1,Dst),new OPImmediate(hi))) ;
			prog.add_line(new Instruction(ori,new OPRegister((yyvsp[(2) - (4)].uval),Dst),new OPRegister(1,Src),new OPImmediate(lo))) ;
			prog.add_line(new Directive(".set","at")) ; 
		}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1118 "asm_mips.yac"
    {
			string m = strmap[(yyvsp[(4) - (4)].uval)] ;
		    std::ostringstream oss_hi ;
		    std::ostringstream oss_lo ;
	  		if ((yyvsp[(1) - (4)].uval) != ASM_MPS__LI) {
				std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Macro_rd_i32" << std::endl ;
			}

		    oss_hi << "%hi(" << m << ")" ;
		    oss_lo << "%lo(" << m << ")" ;
						
			prog.add_line(new Directive(".set","noat")) ; 
			prog.add_line(new Instruction(lui,new OPRegister(1,Dst),new OPExpression(oss_hi.str()))) ;
			prog.add_line(new Instruction(ori,new OPRegister((yyvsp[(2) - (4)].uval),Dst),new OPRegister(1,Src),new OPExpression(oss_lo.str()))) ;
			prog.add_line(new Directive(".set","at")) ; 
		}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1141 "asm_mips.yac"
    {
	  		if ((yyvsp[(1) - (4)].uval) != ASM_MPS__MOVE) {
				std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Macro_rd_rs" << std::endl ;
			}
						
			prog.add_line(new Instruction(or_,new OPRegister((yyvsp[(2) - (4)].uval),Dst),new OPRegister((yyvsp[(4) - (4)].uval),Src),new OPRegister(0,Src))) ;
		}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1155 "asm_mips.yac"
    {
	  		if ((yyvsp[(1) - (4)].uval) == ASM_MPS__NEG) {
				prog.add_line(new Instruction(sub,new OPRegister((yyvsp[(2) - (4)].uval),Dst),new OPRegister(0,Src),new OPRegister((yyvsp[(4) - (4)].uval),Src))) ;
			} else if ((yyvsp[(1) - (4)].uval) == ASM_MPS__NEGU) {
				prog.add_line(new Instruction(subu,new OPRegister((yyvsp[(2) - (4)].uval),Dst),new OPRegister(0,Src),new OPRegister((yyvsp[(4) - (4)].uval),Src))) ;
			} else {
				std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Macro_rd_rt" << std::endl ; break ;
			}
		}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 1171 "asm_mips.yac"
    {
			string m = strmap[(yyvsp[(4) - (4)].uval)] ;
	  		if ((yyvsp[(1) - (4)].uval) == ASM_MPS__BEQZ) {
				prog.add_line(new Instruction(beq,new OPRegister(0,Src),new OPRegister((yyvsp[(2) - (4)].uval),Src),new OPLabel(m))) ;
			} else if ((yyvsp[(1) - (4)].uval) == ASM_MPS__BNEZ) {
				prog.add_line(new Instruction(bne,new OPRegister(0,Src),new OPRegister((yyvsp[(2) - (4)].uval),Src),new OPLabel(m))) ;
			} else {
				std::cerr<< "asm_mips.yac : " << (yyvsp[(1) - (4)].uval) << "is not an valid Macro_rs_label" << std::endl ; break ;
			}
		}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 1197 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << (yyvsp[(2) - (2)].text) ;
			prog.add_line(new Directive(".ascii",str.str())) ;
		}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 1206 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << (yyvsp[(2) - (2)].text) ;
			prog.add_line(new Directive(".asciiz",str.str())) ;
		}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1215 "asm_mips.yac"
    {prog.add_line(new Directive(".byte",strmap[(yyvsp[(2) - (2)].uval)])) ;}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 1223 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << (yyvsp[(2) - (4)].text) << "," << (yyvsp[(4) - (4)].uval) ;
			prog.add_line(new Directive(".lcomm",str.str())) ;
		}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1236 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << (yyvsp[(2) - (6)].text) << "," << (yyvsp[(4) - (6)].uval) << "," << (yyvsp[(6) - (6)].uval);
			prog.add_line(new Directive(".comm",str.str())) ;
		}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1245 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << (yyvsp[(2) - (2)].uval) ;
			prog.add_line(new Directive(".space",str.str())) ;
		}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 1254 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << (yyvsp[(2) - (2)].uval) ;
			prog.add_line(new Directive(".skip",str.str())) ;
		}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1263 "asm_mips.yac"
    {prog.add_line(new Directive(".word",strmap[(yyvsp[(2) - (2)].uval)])) ;}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 1293 "asm_mips.yac"
    { (yyval.uval) = ASM_OPR__MUL  ; }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 1295 "asm_mips.yac"
    { (yyval.uval) = ASM_OPR__DIV  ; }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 1300 "asm_mips.yac"
    { (yyval.uval) = (yyvsp[(1) - (1)].uval); }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 1302 "asm_mips.yac"
    {	
			strmap_id++ ;
			strmap[strmap_id] = (yyvsp[(1) - (1)].text) ;
			(yyval.uval) = strmap_id ;
		}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 1312 "asm_mips.yac"
    { 	
			prog.add_line(new Directive(".section",(yyvsp[(2) - (2)].text))) ;
		}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 1316 "asm_mips.yac"
    {
			prog.add_line(new Directive((yyvsp[(1) - (1)].text))) ;
		}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1324 "asm_mips.yac"
    {	prog.add_line(new Directive(".set","reorder")) ; }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1327 "asm_mips.yac"
    {	prog.add_line(new Directive(".set","noreorder")) ; }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1330 "asm_mips.yac"
    {	string m = strmap[(yyvsp[(2) - (2)].uval)] ;
			prog.add_line(new Directive(".set",m)) ; }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1338 "asm_mips.yac"
    {	std::ostringstream dir ;
		    dir << (yyvsp[(1) - (2)].text) ;
			prog.add_line(new Directive(dir.str(),strmap[strmap_id])) ;
		}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1346 "asm_mips.yac"
    {	strmap_id++ ;
			strmap[strmap_id] = "" ;
			(yyval.uval) = strmap_id ;
		}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1352 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[(1) - (2)].uval)] << " " << (yyvsp[(2) - (2)].text);
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[(1) - (2)].uval) ;
		}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1359 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[(1) - (2)].uval)] << "," ;
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[(1) - (2)].uval) ;
		}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1366 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[(1) - (2)].uval)] << "@";
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[(1) - (2)].uval) ;
		}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1373 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[(1) - (2)].uval)] << "$" << (yyvsp[(2) - (2)].uval) ;
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[(1) - (2)].uval) ;
		}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1380 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[(1) - (2)].uval)] << (yyvsp[(2) - (2)].text);
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[(1) - (2)].uval) ;
		}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1387 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[(1) - (2)].uval)] << (yyvsp[(2) - (2)].uval);
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[(1) - (2)].uval) ;
		}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1394 "asm_mips.yac"
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[(1) - (2)].uval)] << "-";
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[(1) - (2)].uval) ;
		}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1402 "asm_mips.yac"
    { (yyval.uval) = ASM_OPR__SHL  ; }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1404 "asm_mips.yac"
    { (yyval.uval) = ASM_OPR__SHR  ; }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1409 "asm_mips.yac"
    { (yyval.uval) =   (yyvsp[(1) - (1)].uval); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1412 "asm_mips.yac"
    { (yyval.uval) = - (yyvsp[(2) - (2)].uval); }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1415 "asm_mips.yac"
    { (yyval.uval) = ~ (yyvsp[(2) - (2)].uval); }
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1439 "asm_mips.yac"
    {	(yyval.uval) = (yyvsp[(1) - (1)].uval) & 0x0000ffff; }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1445 "asm_mips.yac"
    {	std::ostringstream bylist ;
		    bylist << (yyvsp[(1) - (2)].uval) << strmap[(yyvsp[(2) - (2)].uval)] ;
			strmap[strmap_id] = bylist.str() ;
			(yyval.uval) = (yyvsp[(2) - (2)].uval) ;
		}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1454 "asm_mips.yac"
    {	strmap_id++ ;
			strmap[strmap_id] = "" ;
			(yyval.uval) = strmap_id ;
		}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1461 "asm_mips.yac"
    {	std::ostringstream bylist ;
		    bylist << strmap[(yyvsp[(1) - (3)].uval)] << "," << (yyvsp[(3) - (3)].uval);
			strmap[strmap_id] = bylist.str() ;
			(yyval.uval) = (yyvsp[(1) - (3)].uval) ;
		}
    break;



/* Line 1806 of yacc.c  */
#line 3254 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 1468 "asm_mips.yac"


