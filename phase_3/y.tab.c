/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mini_l.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stddef.h>
  #include <cstring>
  #include <string>
  #include <map>
  #include <vector>
  #include <sstream>
  extern FILE * yyin;
  extern int lineNum;
  extern int linePos;
  void yyerror(const char * msg);
  int yylex();
  struct SymbolTable;

  using namespace std;

  struct Symbol{
    string type;
    string value;
    string* place;
    string* code;
  };

  struct SymbolTable {
    map<string, Symbol> table = map<string, Symbol>(); // The table in which we insert symbols at the current scope
    SymbolTable* parentTable = nullptr;  // The symbol table for the next-widest scope. This is null only for the global table;
  };

  // Global variables;
  SymbolTable globalTable;   // The top-level table
  SymbolTable* currentScope = &globalTable; // The current table, may not be top-level
  vector<string> param_id;   // List of parameters for current function
  vector<string> param_type; // List of parameters' types for current function


#line 103 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    OR = 259,
    NOT = 260,
    TRUE = 261,
    FALSE = 262,
    IF = 263,
    THEN = 264,
    ELSE = 265,
    ENDIF = 266,
    WHILE = 267,
    DO = 268,
    BEGINLOOP = 269,
    ENDLOOP = 270,
    FOR = 271,
    FOREACH = 272,
    IN = 273,
    CONTINUE = 274,
    FUNCTION = 275,
    RETURN = 276,
    BEGIN_PARAMS = 277,
    END_PARAMS = 278,
    BEGIN_LOCALS = 279,
    END_LOCALS = 280,
    BEGIN_BODY = 281,
    END_BODY = 282,
    INTEGER = 283,
    ARRAY = 284,
    OF = 285,
    READ = 286,
    WRITE = 287,
    ADD = 288,
    SUB = 289,
    MULT = 290,
    DIV = 291,
    MOD = 292,
    EQ = 293,
    ASSIGN = 294,
    NEQ = 295,
    LT = 296,
    GT = 297,
    LTE = 298,
    GTE = 299,
    L_PAREN = 300,
    R_PAREN = 301,
    L_SQUARE_BRACKET = 302,
    R_SQUARE_BRACKET = 303,
    SEMICOLON = 304,
    COLON = 305,
    COMMA = 306,
    NUMBER = 307,
    IDENT = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "mini_l.y" /* yacc.c:355  */

  int ival;
  char* sval;
  double dval;


#line 204 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 221 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    60,    61,    63,    65,    69,    72,    73,
      75,    79,    81,    83,    85,    89,    92,    93,    95,    98,
     100,   102,   104,   106,   108,   110,   112,   114,   116,   119,
     121,   123,   125,   127,   129,   131,   133,   136,   140,   142,
     144,   146,   149,   151,   154,   156,   160,   162,   164,   166,
     168,   170,   172,   174,   177,   179,   181,   183,   185,   187,
     190,   192,   194,   197,   199,   202,   204,   207,   209,   211
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "OR", "NOT", "TRUE", "FALSE",
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "BEGINLOOP", "ENDLOOP",
  "FOR", "FOREACH", "IN", "CONTINUE", "FUNCTION", "RETURN", "BEGIN_PARAMS",
  "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY",
  "INTEGER", "ARRAY", "OF", "READ", "WRITE", "ADD", "SUB", "MULT", "DIV",
  "MOD", "EQ", "ASSIGN", "NEQ", "LT", "GT", "LTE", "GTE", "L_PAREN",
  "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "SEMICOLON", "COLON",
  "COMMA", "NUMBER", "IDENT", "$accept", "program", "functions",
  "function", "declarations", "declaration", "statements", "statement",
  "term", "multiplicative_expression_0", "multiplicative_expression",
  "bool-expr", "relation-and-expr", "relation-expr", "comp", "expression",
  "expression_chain", "vars", "var", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -52

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-52)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      57,   -19,    39,    57,   -52,    31,   -52,   -52,    60,    33,
     -23,     8,   -52,    40,    33,    65,    33,   -52,    37,   -52,
      33,   -52,    41,    -6,    76,    69,   -18,    75,    77,    56,
      19,    19,   109,    72,   -52,    47,    72,    72,    79,   -16,
     -52,   104,   -52,    82,    45,   -52,   -52,    14,    19,   -52,
      11,    80,    68,   135,   141,   143,    98,   -52,   133,    75,
     110,    47,   -52,    97,   -52,    97,    47,   -52,    75,    47,
     120,   -52,   -52,    19,    98,    47,   -52,    16,   -52,   105,
      91,    47,    47,    47,    47,    47,    47,    75,    19,    19,
     -52,   -52,   -52,   -52,   -52,   -52,    47,    75,   -12,   100,
     107,    72,   106,   -52,   -52,   127,   111,    47,   112,    47,
     -52,   -52,   -52,   -30,   -52,   -52,   -52,   -52,   -52,   -52,
      -9,   -52,   -52,   -52,    -1,   144,   113,   -52,   114,   -52,
     -52,   -52,   -52,   -28,   -52,    47,    75,   -52,   -52,    19,
      19,    47,   -52,   -52,    -4,   -52,   115,   117,   -52,    72,
     -52,   121,    47,   145,    75,     0,   -52
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     5,     0,     1,     4,     0,     8,
       0,     0,    10,     0,     0,     0,     7,    12,     0,    11,
       8,     9,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,    67,     0,
      18,     0,    13,     0,     0,    48,    49,     0,     0,    30,
      67,    41,    62,     0,    43,    45,     0,    29,     0,    16,
       0,     0,    28,    25,    66,    26,     0,     6,    15,     0,
       0,    50,    51,     0,     0,     0,    34,    67,    33,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
      54,    55,    56,    57,    58,    59,     0,    16,     0,     0,
       0,     0,     0,    17,    19,     0,     0,     0,     0,     0,
      52,    31,    64,     0,    38,    37,    39,    40,    60,    61,
       0,    42,    44,    46,     0,     0,     0,    65,    68,    14,
      53,    47,    35,     0,    32,     0,    16,    20,    22,     0,
       0,     0,    36,    63,     0,    23,     0,     0,    21,     0,
      69,     0,     0,     0,    16,     0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   -52,   160,   146,    59,   -51,    99,   -52,    28,
      36,   -26,    81,   -52,    94,   -31,    62,   132,   -27
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    12,    39,    40,    51,   114,
      52,    53,    54,    55,    96,    56,   113,    63,    57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,   136,   137,   125,    62,    58,    60,   148,    98,    64,
      64,    67,    28,    74,   138,   156,   134,    80,   142,    25,
      78,   135,    79,   135,    44,    45,    46,    13,    14,    29,
     100,    15,    41,    68,     5,   102,   120,    68,   104,     6,
      68,    41,    80,    16,   108,    68,   124,   106,    68,    68,
     112,    71,    72,    47,   118,   119,    81,    16,    66,    75,
      41,   109,   121,    66,    48,   123,    76,    77,    17,    18,
      41,    49,    50,    19,   127,    21,   131,     1,   112,    47,
       8,    47,     9,    30,    22,   144,    10,    31,    32,    20,
      73,    33,    61,    24,    34,    27,    35,    49,    50,    49,
      50,    85,    86,   155,   143,    42,    36,    37,    43,    41,
     147,   116,   117,   145,   146,    82,    83,    84,   115,   115,
     115,   153,   151,    59,    26,    38,    66,    41,    38,    90,
      70,    91,    92,    93,    94,    95,    90,   111,    91,    92,
      93,    94,    95,    69,    87,    88,    89,    97,   101,    99,
     105,   110,   126,   111,   128,   129,   139,   130,   132,   154,
     152,   141,   140,     7,   149,   150,    23,   103,   107,    65,
     122,   133
};

static const yytype_uint8 yycheck[] =
{
      27,    10,    11,    15,    35,    31,    33,    11,    59,    36,
      37,    27,    30,    44,    15,    15,    46,    48,    46,    25,
      47,    51,    48,    51,     5,     6,     7,    50,    51,    47,
      61,    23,    59,    49,    53,    66,    87,    49,    69,     0,
      49,    68,    73,    49,    75,    49,    97,    73,    49,    49,
      81,     6,     7,    34,    85,    86,    45,    49,    47,    45,
      87,    45,    88,    47,    45,    96,    52,    53,    28,    29,
      97,    52,    53,    14,   101,    16,   107,    20,   109,    34,
      49,    34,    22,     8,    47,   136,    53,    12,    13,    24,
      45,    16,    45,    52,    19,    26,    21,    52,    53,    52,
      53,    33,    34,   154,   135,    28,    31,    32,    52,   136,
     141,    83,    84,   139,   140,    35,    36,    37,    82,    83,
      84,   152,   149,    14,    48,    53,    47,   154,    53,    38,
      48,    40,    41,    42,    43,    44,    38,    46,    40,    41,
      42,    43,    44,    39,     9,     4,     3,    14,    51,    39,
      30,    46,    52,    46,    48,    28,    12,    46,    46,    14,
      39,    47,    49,     3,    49,    48,    20,    68,    74,    37,
      89,   109
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    55,    56,    57,    53,     0,    57,    49,    22,
      53,    58,    59,    50,    51,    23,    49,    28,    29,    59,
      24,    59,    47,    58,    52,    25,    48,    26,    30,    47,
       8,    12,    13,    16,    19,    21,    31,    32,    53,    60,
      61,    72,    28,    52,     5,     6,     7,    34,    45,    52,
      53,    62,    64,    65,    66,    67,    69,    72,    65,    14,
      72,    45,    69,    71,    72,    71,    47,    27,    49,    39,
      48,     6,     7,    45,    69,    45,    52,    53,    72,    65,
      69,    45,    35,    36,    37,    33,    34,     9,     4,     3,
      38,    40,    41,    42,    43,    44,    68,    14,    60,    39,
      69,    51,    69,    61,    69,    30,    65,    68,    69,    45,
      46,    46,    69,    70,    63,    64,    63,    63,    69,    69,
      60,    65,    66,    69,    60,    15,    52,    72,    48,    28,
      46,    69,    46,    70,    46,    51,    10,    11,    15,    12,
      49,    47,    46,    69,    60,    65,    65,    69,    11,    49,
      48,    72,    39,    69,    14,    60,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    57,    58,    58,    58,
      58,    59,    59,    59,    59,    60,    60,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    64,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    70,    70,    71,    71,    72,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,    12,     2,     0,     3,
       1,     3,     3,     8,    11,     2,     0,     3,     1,     3,
       5,     7,     5,     6,    13,     2,     2,     1,     2,     1,
       1,     3,     4,     2,     2,     4,     5,     1,     3,     3,
       3,     1,     3,     1,     3,     1,     3,     4,     1,     1,
       2,     2,     3,     4,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     1,     3,     1,     1,     4,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 56 "mini_l.y" /* yacc.c:1646  */
    {printf("program -> functions\n");}
#line 1405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 60 "mini_l.y" /* yacc.c:1646  */
    {printf("functions -> epsilon\n");}
#line 1411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 62 "mini_l.y" /* yacc.c:1646  */
    {printf("functions -> function functions\n");}
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 66 "mini_l.y" /* yacc.c:1646  */
    {printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY\n");}
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 70 "mini_l.y" /* yacc.c:1646  */
    {printf("declarations -> declarations SEMICOLON\n");}
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 72 "mini_l.y" /* yacc.c:1646  */
    {printf("declarations -> epsilon\n");}
#line 1435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 74 "mini_l.y" /* yacc.c:1646  */
    {printf("declarations SEMICOLON declaration\n");}
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 76 "mini_l.y" /* yacc.c:1646  */
    {printf("declaration\n");}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 80 "mini_l.y" /* yacc.c:1646  */
    {printf("decleration -> IDENT COMMA declaration\n");}
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 82 "mini_l.y" /* yacc.c:1646  */
    {printf("declaration -> IDENT COLON NUMBER\n");}
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 84 "mini_l.y" /* yacc.c:1646  */
    {printf("declaration -> IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 86 "mini_l.y" /* yacc.c:1646  */
    {printf("declaration -> IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 90 "mini_l.y" /* yacc.c:1646  */
    { printf("statements -> statement SEMICOLON statements\n");}
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 92 "mini_l.y" /* yacc.c:1646  */
    {printf("statements -> epsilon\n"); }
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 94 "mini_l.y" /* yacc.c:1646  */
    {printf("statements -> statements SEMICOLON statement\n");}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 96 "mini_l.y" /* yacc.c:1646  */
    {printf("statements -> statement\n");}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 99 "mini_l.y" /* yacc.c:1646  */
    {printf("statement -> var ASSIGN expression\n");}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 101 "mini_l.y" /* yacc.c:1646  */
    {printf("statement -> IF bool-expr THEN statements ENDIF\n");}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 103 "mini_l.y" /* yacc.c:1646  */
    {printf("statement -> IF bool-expr THEN statements ELSE statements ENDIF \n");}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 105 "mini_l.y" /* yacc.c:1646  */
    {printf("statement -> WHILE bool-expr BEGINLOOP statements ENDLOOP \n");}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 107 "mini_l.y" /* yacc.c:1646  */
    {printf("statement -> DO BEGINLOOP statements ENDLOOP WHILE bool-expr\n");}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 109 "mini_l.y" /* yacc.c:1646  */
    {printf("statement -> FOR var ASSIGN NUMBER SEMICOLON bool-expr SEMICOLON var ASSIGN expression BEGINLOOP statements ENDLOOP\n");}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 111 "mini_l.y" /* yacc.c:1646  */
    {printf("statement -> READ vars\n");}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 113 "mini_l.y" /* yacc.c:1646  */
    {printf("statement -> WRITE vars \n");}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 115 "mini_l.y" /* yacc.c:1646  */
    {printf("statement -> CONTINUE\n");}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 117 "mini_l.y" /* yacc.c:1646  */
    {printf("statement -> RETURN expression\n");}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 120 "mini_l.y" /* yacc.c:1646  */
    {printf("term -> var\n");}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 122 "mini_l.y" /* yacc.c:1646  */
    {printf("term -> NUMBER: %d\n", (yyvsp[0].ival));}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 124 "mini_l.y" /* yacc.c:1646  */
    {printf("term -> L_PAREN expression R_PAREN\n");}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 126 "mini_l.y" /* yacc.c:1646  */
    {printf("term -> IDENT L_PAREN expression_chain R_PAREN\n");}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 128 "mini_l.y" /* yacc.c:1646  */
    {printf("term -> SUB var\n");}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 130 "mini_l.y" /* yacc.c:1646  */
    {printf("term -> SUB NUMBER\n");}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 132 "mini_l.y" /* yacc.c:1646  */
    {printf("term -> SUB L_PAREN expression R_PAREN\n");}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 134 "mini_l.y" /* yacc.c:1646  */
    {printf("term -> SUB IDENT L_PAREN expression_chain R_PAREN\n");}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 137 "mini_l.y" /* yacc.c:1646  */
    {printf("multiplicative_expression_0 -> multiplicative_expression\n");}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 141 "mini_l.y" /* yacc.c:1646  */
    {printf("multiplicative_expression -> term MULT multiplicative_expression\n");}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 143 "mini_l.y" /* yacc.c:1646  */
    {printf("multiplicative_expression -> term DIV multiplicative_expression\n");}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 145 "mini_l.y" /* yacc.c:1646  */
    {printf("multiplicative_expression -> term MOD multiplicative_expression\n");}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 147 "mini_l.y" /* yacc.c:1646  */
    {printf("multiplicative_expression -> term\n");}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 150 "mini_l.y" /* yacc.c:1646  */
    {printf("bool-expr -> relation-and-expr OR bool-expr\n");}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 152 "mini_l.y" /* yacc.c:1646  */
    {printf("bool-expr -> relation-and-expr\n");}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 155 "mini_l.y" /* yacc.c:1646  */
    {printf("relation-and-expr -> relation-expr_0 AND relation-and-expr\n");}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 157 "mini_l.y" /* yacc.c:1646  */
    {printf("relation-and-expr -> relation-expr_0\n");}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 161 "mini_l.y" /* yacc.c:1646  */
    {printf("relation_expr -> expression comp expression\n");}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 163 "mini_l.y" /* yacc.c:1646  */
    {printf("relation_expr -> NOT expression comp expression\n");}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 165 "mini_l.y" /* yacc.c:1646  */
    {printf("relation_expr -> TRUE\n" );}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 167 "mini_l.y" /* yacc.c:1646  */
    {printf("relation_expr -> FALSE\n");}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 169 "mini_l.y" /* yacc.c:1646  */
    {printf("relation_expr -> NOT TRUE\n" );}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 171 "mini_l.y" /* yacc.c:1646  */
    {printf("relation_expr -> NOT FALSE\n");}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 173 "mini_l.y" /* yacc.c:1646  */
    {printf("relation_expr -> L_PAREN bool-expr R_PAREN\n");}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 175 "mini_l.y" /* yacc.c:1646  */
    {printf("relation_expr -> NOT L_PAREN bool-expr R_PAREN\n");}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 178 "mini_l.y" /* yacc.c:1646  */
    {printf("comp -> EQ\n");}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 180 "mini_l.y" /* yacc.c:1646  */
    {printf("comp -> NEQ\n");}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 182 "mini_l.y" /* yacc.c:1646  */
    {printf("comp -> LT\n");}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 184 "mini_l.y" /* yacc.c:1646  */
    {printf("comp -> GT\n");}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 186 "mini_l.y" /* yacc.c:1646  */
    {printf("comp -> LTE\n");}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 188 "mini_l.y" /* yacc.c:1646  */
    {printf("comp -> GTE\n");}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 191 "mini_l.y" /* yacc.c:1646  */
    {printf("expression -> multiplicative_expression PLUS expression\n");}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 193 "mini_l.y" /* yacc.c:1646  */
    {printf("expression -> multiplicative_expression SUB expression\n");}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 195 "mini_l.y" /* yacc.c:1646  */
    {printf("expression -> multiplicative_expression\n");}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 198 "mini_l.y" /* yacc.c:1646  */
    {printf("expression_chain -> expression_chain COMMA expression\n");}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 200 "mini_l.y" /* yacc.c:1646  */
    {printf("expression_chain -> expression\n");}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 203 "mini_l.y" /* yacc.c:1646  */
    {printf("vars -> vars COMMA var\n");}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 205 "mini_l.y" /* yacc.c:1646  */
    {printf("vars -> var\n");}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 208 "mini_l.y" /* yacc.c:1646  */
    {printf("var -> IDENT  %s \n", (yyvsp[0].sval));}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 210 "mini_l.y" /* yacc.c:1646  */
    {printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 212 "mini_l.y" /* yacc.c:1646  */
    {printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1805 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 214 "mini_l.y" /* yacc.c:1906  */

int main(int argc, char ** argv)
{
   if(argc > 1) {

      yyin = fopen(argv[1], "r"); // open the file

      if(yyin == NULL) yyin = stdin; // If something went wrong default back to stdin

   } else {

      yyin = stdin; // Default to stdin

   }

   yyparse(); // Finally call the parser.
}

void yyerror(const char * msg) {
  printf("Error: %s\n", msg);
}

bool exists(string name) {
  if (currentScope == nullptr) yyerror("Internal error: scope not set");

  auto itr = currentScope->table.find(name);
  if (itr == currentScope->table.end()) return false;

  return true;
}

// Checks if a symbol already exists in a given symbol table
bool exists(string name, SymbolTable* table) {
   if (table == nullptr) yyerror("Internal error: cannot check null symbol table");

  auto itr = table->table.find(name);
  if (itr == table->table.end()) return false;

  return true;
}

// Attempts to add a symbol to the current scope
bool add(string name, Symbol symbol) {
  stringstream ss;
  ss << "Error on line " << to_string(lineNum) << ":" << to_string(linePos) << " : Redefinition of" << name << "\n";
  if (exists(name), currentScope) yyerror(ss.str().c_str());

  if (currentScope == nullptr) yyerror("Internal error: scope not set");

  currentScope->table[name] = symbol;
  return true;

}
