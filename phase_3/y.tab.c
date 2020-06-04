/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "mini_l.y"

  #include <stdio.h>
  #include <stddef.h>
  #include <cstring>
  #include <string>
  #include <map>
  #include <set>
  #include <vector>
  #include <sstream>
  #include "heading.h"

  // Externs
  extern FILE * yyin;
  extern int lineNum;
  extern int linePos;
  extern "C" int yylex();

  //Function forward declarations
  void yyerror (const char * msg);
  int yylex();
  struct SymbolTable;

  using namespace std;

struct Symbol{
  string type;
  string value;
  string code;
};

struct SymbolTable {
  map<string, Symbol> table = map<string, Symbol>(); // The table in which we insert symbols at the current scope
  SymbolTable* parentTable = nullptr;  // The symbol table for the next-widest scope. This is null only for the global table;
};

bool exists(string name); // Checks if a symbol already exists in the current scope's symboltable
bool exists(string name, SymbolTable* table); // Checks if a symbol already exists in a given symbol table
bool increaseScope();            // Move up in scope by one layer if poible.
bool add(string name, Symbol symbol);  // Attempts to add a symbol to the current scope
string new_label();
string new_temp();



  // Global variables;
  SymbolTable globalTable;   // The top-level table
  SymbolTable* currentScope = &globalTable; // The current table, may not be top-level
  vector<string> param_id;   // List of parameters for current function
  vector<string> param_type; // List of parameters' types for current function
  set<string> functions;
  set<string> function_calls;
  int label_count = 0;
  int temp_count = 0;
  bool store_as_param = false;


#line 127 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    IDENT = 307,
    NUMBER = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 58 "mini_l.y"

  int ival;
  char* sval;
  double dval;

struct VarContainer{
  char* place;
  char* code;
  char* type;  // can be VARIABLE or ARRAY
  char* index; // index for if this is an array
  char* index2;
} varContainer;

struct StatementContainer{
  char* code;
  char* place;
  char* label;
  char* type;
  char* array_name;
  } statementContainer;

struct ExpressionContainer {
  char* code;
  char* place;
  char* array_name;
  char* type; // VARIABLE, ARRAY, or 2DARRAY
} expressionContainer;
  
struct Generic{
   char* place; // Destination of value
   char* code;  // Code used to get value
} generic;

struct Comparator{
  char* operation;
} comparator;


#line 272 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   132,   135,   141,   146,   150,   153,   156,
     159,   162,   194,   200,   203,   214,   221,   248,   274,   297,
     309,   316,   321,   329,   345,   374,   395,   416,   454,   482,
     487,   530,   573,   589,   603,   610,   617,   637,   640,   643,
     646,   650,   657,   675,   692,   709,   752,   764,   770,   782,
     789,   802,   814,   819,   824,   829,   834,   839,   849,   853,
     857,   861,   865,   869,   874,   892,   911,   917,   924,   930,
     937,   957,   964,   971
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
  "COMMA", "IDENT", "NUMBER", "$accept", "program", "functions",
  "begin_params", "end_params", "params", "locals", "body", "function",
  "declarations", "declaration", "statements", "statement", "term",
  "multiplicative_expression_0", "multiplicative_expression", "bool-expr",
  "relation-and-expr", "relation-expr", "comp", "expression",
  "expression_chain", "vars", "var", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,    29,    70,    10,   -56,    36,   -56,   -56,    79,   -56,
      56,    92,    -3,    -8,   -56,    56,    94,    39,    56,   -56,
      56,   -56,    -5,    67,   -56,   -56,    71,   -56,   -56,   -56,
       0,     0,   107,    72,   -56,    50,    72,    72,    75,    11,
     -56,    84,    74,    20,   -56,   -56,    37,     0,   -28,   -56,
      -4,   -12,   119,   125,   127,    53,   -56,   117,    67,    95,
     -56,    82,   -56,    82,    50,   -56,    67,    50,    87,   -56,
     -56,     0,    53,    50,    12,   -56,   -56,    90,    50,    50,
      50,    50,    50,    50,    67,     0,     0,   -56,   -56,   -56,
     -56,   -56,   -56,    50,    67,   -13,    85,    72,    89,   -56,
     -56,   -29,    93,    50,    96,    50,   -56,   -56,    18,   -56,
     -56,   -56,   -56,   -56,   -56,     1,   -56,   -56,   -56,     9,
     128,    98,   -56,    99,   113,    91,   -56,   -56,   -56,    41,
     -56,    50,    67,   -56,   -56,     0,     0,    50,   -56,   100,
     -56,   -56,    -7,   -56,   101,   103,   115,   -56,    72,   -56,
     121,   104,   -56,    50,   138,    67,    13,   -56
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     2,     5,     0,     1,     4,     0,     6,
      13,     0,     0,     0,    15,    13,     0,     0,     0,     7,
      12,     8,     0,    21,    11,    17,     0,    16,    14,     9,
       0,     0,     0,     0,    32,     0,     0,     0,    71,     0,
      23,     0,     0,     0,    52,    53,     0,     0,    71,    35,
      45,    66,     0,    47,    49,     0,    34,     0,    21,     0,
      33,    30,    70,    31,     0,    10,    20,     0,     0,    54,
      55,     0,     0,     0,    71,    38,    37,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,    58,    59,    60,
      61,    62,    63,     0,    21,     0,     0,     0,     0,    22,
      24,     0,     0,     0,     0,     0,    56,    68,     0,    42,
      41,    43,    44,    64,    65,     0,    46,    48,    50,     0,
       0,     0,    69,    72,     0,     0,    57,    51,    39,     0,
      36,     0,    21,    25,    27,     0,     0,     0,    18,     0,
      40,    67,     0,    28,     0,     0,     0,    26,     0,    73,
       0,     0,    19,     0,     0,    21,     0,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   150,   139,
      97,   -55,   102,   -56,    31,    26,   -22,    69,   -56,    86,
     -27,    51,   120,   -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    10,    21,    11,    16,    24,     4,    13,
      14,    39,    40,    50,   109,    51,    52,    53,    54,    93,
      55,   108,    61,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,   124,   120,    95,   147,    43,    44,    45,    60,    57,
      59,   132,   133,    62,    62,    19,    72,    78,   125,    64,
      29,    82,    83,    76,   134,    77,    69,    70,   157,   115,
       1,    79,    80,    81,    46,    41,    66,    98,    65,   119,
     100,    20,    66,    41,    20,    47,   104,    17,    18,   102,
      66,   107,    48,    49,    46,   113,   114,   105,    66,    64,
      66,    41,    66,   116,   130,    71,   118,    25,    26,   131,
       6,    41,    48,    49,   122,    30,   127,   142,   107,    31,
      32,     5,    73,    33,    46,     8,    34,   140,    35,    74,
      75,    87,   131,    88,    89,    90,    91,    92,    36,    37,
     156,     9,    48,    49,   141,   110,   110,   110,    12,    41,
     145,   111,   112,   143,   144,    27,    15,    28,    42,    38,
      23,    58,    64,    67,    38,   151,   154,    68,    84,    85,
      86,    94,    41,    97,    96,   101,   106,   123,   121,   126,
     135,   138,   128,   153,   139,   150,   137,   136,   146,   152,
     148,   149,   155,     7,    22,   117,   129,    63,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99
};

static const yytype_int16 yycheck[] =
{
      23,    30,    15,    58,    11,     5,     6,     7,    35,    31,
      33,    10,    11,    36,    37,    23,    43,    45,    47,    47,
      25,    33,    34,    46,    15,    47,     6,     7,    15,    84,
      20,    35,    36,    37,    34,    58,    49,    64,    27,    94,
      67,    49,    49,    66,    49,    45,    73,    50,    51,    71,
      49,    78,    52,    53,    34,    82,    83,    45,    49,    47,
      49,    84,    49,    85,    46,    45,    93,    28,    29,    51,
       0,    94,    52,    53,    97,     8,   103,   132,   105,    12,
      13,    52,    45,    16,    34,    49,    19,    46,    21,    52,
      53,    38,    51,    40,    41,    42,    43,    44,    31,    32,
     155,    22,    52,    53,   131,    79,    80,    81,    52,   132,
     137,    80,    81,   135,   136,    18,    24,    20,    47,    52,
      26,    14,    47,    39,    52,   148,   153,    53,     9,     4,
       3,    14,   155,    51,    39,    48,    46,    48,    53,    46,
      12,    28,    46,    39,    53,    30,    47,    49,    48,    28,
      49,    48,    14,     3,    15,    86,   105,    37,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,    55,    56,    62,    52,     0,    62,    49,    22,
      57,    59,    52,    63,    64,    24,    60,    50,    51,    23,
      49,    58,    63,    26,    61,    28,    29,    64,    64,    25,
       8,    12,    13,    16,    19,    21,    31,    32,    52,    65,
      66,    77,    47,     5,     6,     7,    34,    45,    52,    53,
      67,    69,    70,    71,    72,    74,    77,    70,    14,    77,
      74,    76,    77,    76,    47,    27,    49,    39,    53,     6,
       7,    45,    74,    45,    52,    53,    77,    70,    45,    35,
      36,    37,    33,    34,     9,     4,     3,    38,    40,    41,
      42,    43,    44,    73,    14,    65,    39,    51,    74,    66,
      74,    48,    70,    73,    74,    45,    46,    74,    75,    68,
      69,    68,    68,    74,    74,    65,    70,    71,    74,    65,
      15,    53,    77,    48,    30,    47,    46,    74,    46,    75,
      46,    51,    10,    11,    15,    12,    49,    47,    28,    53,
      46,    74,    65,    70,    70,    74,    48,    11,    49,    48,
      30,    77,    28,    39,    74,    14,    65,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    57,    58,    59,    60,
      61,    62,    63,    63,    63,    63,    64,    64,    64,    64,
      65,    65,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    68,    69,    69,    69,    69,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    73,    73,    74,    74,    74,    75,    75,    76,
      76,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     3,     3,
       3,     6,     2,     0,     3,     1,     3,     3,     8,    11,
       2,     0,     3,     1,     3,     5,     7,     5,     6,    13,
       2,     2,     1,     2,     1,     1,     4,     2,     2,     4,
       5,     1,     3,     3,     3,     1,     3,     1,     3,     1,
       3,     4,     1,     1,     2,     2,     3,     4,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     1,     3,
       1,     1,     4,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 115 "mini_l.y"
          {//printf("program -> functions\n");

            // Check for any undefined function calls
            for (string call : function_calls) {
              if (functions.count(call) < 1) {
                ostringstream o;
                o << "Error at line " << /*lineNum << ":" << linePos <<*/ ": No definition for function " << call << endl;
                 cout << (o.str().c_str());
                 exit(-1);
              }
            }

            cout << (yyvsp[0].generic).code;
          }
#line 1570 "y.tab.c"
    break;

  case 3:
#line 132 "mini_l.y"
            {//printf("functions -> epsilon\n");
              (yyval.generic).code = "";
            }
#line 1578 "y.tab.c"
    break;

  case 4:
#line 136 "mini_l.y"
            {//printf("functions -> function functions\n");
              ostringstream o;
              o << (yyvsp[-1].generic).code << endl << (yyvsp[0].generic).code;
              (yyval.generic).code = strdup(o.str().c_str());
            }
#line 1588 "y.tab.c"
    break;

  case 5:
#line 142 "mini_l.y"
          {
            (yyval.generic).code = (yyvsp[0].generic).code;
          }
#line 1596 "y.tab.c"
    break;

  case 6:
#line 146 "mini_l.y"
                           {
  store_as_param = true;
}
#line 1604 "y.tab.c"
    break;

  case 7:
#line 150 "mini_l.y"
                       {
  store_as_param = false;
}
#line 1612 "y.tab.c"
    break;

  case 8:
#line 154 "mini_l.y"
        {(yyval.generic).code = (yyvsp[-1].expressionContainer).code;}
#line 1618 "y.tab.c"
    break;

  case 9:
#line 157 "mini_l.y"
        {(yyval.generic).code = (yyvsp[-1].expressionContainer).code;}
#line 1624 "y.tab.c"
    break;

  case 10:
#line 160 "mini_l.y"
        {(yyval.generic).code = (yyvsp[-1].statementContainer).code;}
#line 1630 "y.tab.c"
    break;

  case 11:
#line 163 "mini_l.y"
          {//printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY\n");
            currentScope->table.clear(); // Clear the scope since we're switching between functions

            ostringstream o;

            if (functions.count(string((yyvsp[-4].sval))) != 0) { // Check for duplicate declarations
              o << "Error on line " << lineNum << ":" << linePos << ": Redefinition of function " << (yyvsp[-4].sval) << endl;

              cout << (o.str().c_str());
              exit(-1);
            } else {
              functions.insert(string((yyvsp[-4].sval)));
            }

            // Check for misplaced continues
            if (string((yyvsp[0].generic).code).find("continue") != string::npos) {
              o << "Error on line " << lineNum << ":" << linePos << ": Misplaced Continue in body of " << (yyvsp[-4].sval) << endl;
              cout << (o.str().c_str());
              exit(-1);
            }

            // Build function code

            o << "func " << (yyvsp[-4].sval) << endl;
            o << (yyvsp[-2].generic).code << (yyvsp[-1].generic).code << (yyvsp[0].generic).code;
            o << "endfunc" << endl;

            (yyval.generic).code = strdup(o.str().c_str());
          }
#line 1664 "y.tab.c"
    break;

  case 12:
#line 195 "mini_l.y"
              {//printf("declarations -> declarations SEMICOLON\n");
                (yyval.expressionContainer).place = (yyvsp[-1].expressionContainer).place;
                (yyval.expressionContainer).code = (yyvsp[-1].expressionContainer).code;
              }
#line 1673 "y.tab.c"
    break;

  case 13:
#line 200 "mini_l.y"
              {//printf("declarations -> epsilon\n");
                (yyval.expressionContainer).code = "";
              }
#line 1681 "y.tab.c"
    break;

  case 14:
#line 204 "mini_l.y"
            {//printf("declarations SEMICOLON declaration\n");
              ostringstream o;
              o << (yyvsp[-2].expressionContainer).code;
              o << (yyvsp[0].expressionContainer).code;
              (yyval.expressionContainer).code =  strdup(o.str().c_str());

              ostringstream lss;
              lss << (yyvsp[-2].expressionContainer).place << "#" << (yyvsp[0].expressionContainer).place;
              (yyval.expressionContainer).place = strdup(lss.str().c_str());
            }
#line 1696 "y.tab.c"
    break;

  case 15:
#line 215 "mini_l.y"
            {//printf("declaration\n");
              (yyval.expressionContainer).code  = (yyvsp[0].expressionContainer).code;
              (yyval.expressionContainer).place = (yyvsp[0].expressionContainer).place;
            }
#line 1705 "y.tab.c"
    break;

  case 16:
#line 222 "mini_l.y"
              {//printf("decleration -> IDENT COMMA declaration\n");
                
                Symbol sym = Symbol();

                if (store_as_param == true) {
                  sym.type = "PARAM";
                } else {
                  sym.type = "VARIABLE";
                }

                sym.value = "0";

                add(string((yyvsp[-2].sval)), sym); // Try to add the variable to the symbol table
                ostringstream o;
                o << (yyvsp[-2].sval) << "#" << (yyvsp[0].expressionContainer).place;
                (yyval.expressionContainer).place = strdup(o.str().c_str());

                ostringstream _o;
                _o << (yyvsp[0].expressionContainer).code;
                _o << ". " << (yyvsp[-2].sval) << endl;
                if (store_as_param == true) {
                  _o << "= " << (yyvsp[-2].sval) << ", $0" << endl;
                }
                (yyval.expressionContainer).code = strdup(_o.str().c_str());
                
            }
#line 1736 "y.tab.c"
    break;

  case 17:
#line 249 "mini_l.y"
              {//printf("declaration -> IDENT COLON NUMBER\n");
                string s((yyvsp[-2].sval));
                Symbol sym = Symbol();
                if (store_as_param == true) {\
                  sym.type = "PARAM";
                } else {
                  sym.type = "VARIABLE";
                }
                
                sym.value = "null";
                sym.code  = "";

                ostringstream o;
                o << ". " << s << endl;

                if (store_as_param == true) {
                  o << "= " << (yyvsp[-2].sval) << ", $0" << endl;
                }

                sym.code = o.str();

                (yyval.expressionContainer).code = strdup(o.str().c_str());

                add((yyvsp[-2].sval), sym);
              }
#line 1766 "y.tab.c"
    break;

  case 18:
#line 275 "mini_l.y"
              {//printf("declaration -> IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");
                string s((yyvsp[-7].sval));
                Symbol sym = Symbol();
                sym.type = "ARRAY";
                sym.value = "null";
                sym.code  = "";

                ostringstream o;
                if ((yyvsp[-3].ival) < 0) {
                  ostringstream o;
                  o << "Index out of bounds: " << (yyvsp[-7].sval) << "on line " << lineNum << ":" << linePos << endl;
                  cout << (o.str().c_str());
                }

                o << ".[] " << (yyvsp[-7].sval) << ", " << (yyvsp[-3].ival) << endl;

                sym.code = o.str();

                (yyval.expressionContainer).code = strdup(o.str().c_str());

                add((yyvsp[-7].sval), sym);
              }
#line 1793 "y.tab.c"
    break;

  case 19:
#line 298 "mini_l.y"
              {//printf("declaration -> IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");
                string s((yyvsp[-10].sval));
                Symbol sym = Symbol();
                sym.type = "2DARRAY";
                sym.value = "null";
                sym.code  = "";

                add((yyvsp[-10].sval), sym);
              }
#line 1807 "y.tab.c"
    break;

  case 20:
#line 310 "mini_l.y"
            { //printf("statements -> statement SEMICOLON statements\n");
              (yyval.statementContainer).code = (yyvsp[-1].statementContainer).code;
              (yyval.statementContainer).place = (yyvsp[-1].statementContainer).place;
              (yyval.statementContainer).label = "";
            }
#line 1817 "y.tab.c"
    break;

  case 21:
#line 316 "mini_l.y"
            {//printf("statements -> epsilon\n"); 
              (yyval.statementContainer).code = "";
              (yyval.statementContainer).place = "";
              (yyval.statementContainer).label = "";
            }
#line 1827 "y.tab.c"
    break;

  case 22:
#line 322 "mini_l.y"
            {//printf("statements -> statements SEMICOLON statement\n");
              (yyval.statementContainer).label = "";
              ostringstream o;
              o << (yyvsp[-2].statementContainer).code;
              o << (yyvsp[0].statementContainer).code;
              (yyval.statementContainer).code = strdup(o.str().c_str());
            }
#line 1839 "y.tab.c"
    break;

  case 23:
#line 330 "mini_l.y"
            {//printf("statements -> statement\n");
              (yyval.statementContainer).label = "";
              (yyval.statementContainer).code = (yyvsp[0].statementContainer).code;
              (yyval.statementContainer).place = (yyvsp[0].statementContainer).place;

              string label = string((yyvsp[0].statementContainer).label);
                    
              // Fixes a seg-fault by manually setting  to an empty string
              if (label.length() > 0) {
                (yyval.statementContainer).label = (yyvsp[0].statementContainer).label;
              } else {
                (yyval.statementContainer).label = "";
              }
            }
#line 1858 "y.tab.c"
    break;

  case 24:
#line 346 "mini_l.y"
         {//printf("statement -> var ASSIGN expression\n");
            ostringstream o;
            (yyval.statementContainer).code = "";
            if (!exists(string((yyvsp[-2].expressionContainer).place))) {
              o << "Error on line" << lineNum << ":" << linePos << ": variable " << (yyvsp[-2].expressionContainer).place << " has not been delcared!" << endl;
              cout << o.str();
              exit(-1);
            }

            
            if(strcmp((yyvsp[-2].expressionContainer).type, "ARRAY") == 0) {

              o << (yyvsp[-2].expressionContainer).code << (yyvsp[0].expressionContainer).code;
              o << "[]= " << (yyvsp[-2].expressionContainer).array_name << ", " << (yyvsp[-2].expressionContainer).place << ", " << (yyvsp[0].expressionContainer).place << endl;
              (yyval.statementContainer).code = strdup(o.str().c_str());
            } else if (strcmp((yyvsp[-2].expressionContainer).type, "VARIABLE") == 0) {

              o << (yyvsp[0].expressionContainer).code;
              o << " = " << (yyvsp[-2].expressionContainer).place << ", " << (yyvsp[0].expressionContainer).place << endl;
              (yyval.statementContainer).code = strdup(o.str().c_str());

            } else if (strcmp((yyvsp[-2].expressionContainer).type, "2DARRAY") == 0) {

            }

            (yyval.statementContainer).label = "";

          }
#line 1891 "y.tab.c"
    break;

  case 25:
#line 375 "mini_l.y"
         {//printf("statement -> IF bool-expr THEN statements ENDIF\n");
            (yyval.statementContainer).code = "";
            (yyval.statementContainer).label = "";

            string if_label = new_label();
            string skip_label = new_label();

            ostringstream o;

            o << (yyvsp[-3].expressionContainer).code; // if condition code
            o << "?:= " << if_label << ", " << (yyvsp[-3].expressionContainer).place << endl; // set the jump to if label
            o << ":= " << skip_label << endl; // set jump to skip label

            o << ": " << if_label << endl;    // set if label
            o << (yyvsp[-1].statementContainer).code;                     // if-body code

            o << ": " << skip_label << endl;  // skip label

            (yyval.statementContainer).code = strdup(o.str().c_str());
         }
#line 1916 "y.tab.c"
    break;

  case 26:
#line 396 "mini_l.y"
         {//printf("statement -> IF bool-expr THEN statements ELSE statements ENDIF \n");
            (yyval.statementContainer).code = "";
            (yyval.statementContainer).label = "";

            string if_label = new_label();
            string else_label = new_label();
            ostringstream o;
          
            o << (yyvsp[-5].expressionContainer).code; // if condition code
            o << "?:= " << if_label << ", " << (yyvsp[-5].expressionContainer).place << endl; // set if label
            o << ":= " << else_label << endl;                        // set else label

            o << ": " << if_label << endl;                           // mark if label
            o << (yyvsp[-3].statementContainer).code;                                            // if code

            o << ": " << else_label << endl;                         // mark else label
            o << (yyvsp[-1].statementContainer).code;                                            // else code
            
            (yyval.statementContainer).code = strdup(o.str().c_str());                       // dump code to statement
         }
#line 1941 "y.tab.c"
    break;

  case 27:
#line 417 "mini_l.y"
         {//printf("statement -> WHILE bool-expr BEGINLOOP statements ENDLOOP \n");
            (yyval.statementContainer).code = "";
            (yyval.statementContainer).label = "";
            string while_body = new_label();
            string skip_label = new_label();
            string while_condition = new_label();
            ostringstream o;
            
            if (string((yyvsp[-1].statementContainer).label).length() == 0) { // if there's no labels within the statements block
              o << ": " << while_condition << endl;
              o << (yyvsp[-3].expressionContainer).code;
              o << "?:= " << while_body << ", " << (yyvsp[-3].expressionContainer).place << endl;
              o << ":= " << skip_label << endl;

              o << ": " << while_body << endl;
              o << (yyvsp[-1].statementContainer).code;

              o << ":= " << while_condition << endl;
              o << ": " << skip_label << endl;
            } else {
              o << ": " << while_condition << endl;
              o << (yyvsp[-3].expressionContainer).code;
              o << "?:= " << while_body << ", " << (yyvsp[-3].expressionContainer).place << endl;
              o << ":= " << skip_label << endl;

              o << ": " << while_body << endl;
              o << (yyvsp[-1].statementContainer).code;
              o << ": " << (yyvsp[-1].statementContainer).label << endl;  

              o << ":= " << while_condition << endl;
              o << ": " << skip_label << endl;
              
            }
          

          (yyval.statementContainer).code = strdup(o.str().c_str());
         }
#line 1983 "y.tab.c"
    break;

  case 28:
#line 455 "mini_l.y"
         {//printf("statement -> DO BEGINLOOP statements ENDLOOP WHILE bool-expr\n");
            (yyval.statementContainer).code = "";
            (yyval.statementContainer).label = "";

             string do_label = new_label();
             string m = new_label();
             string n = new_label();
             ostringstream o;
                    
          if (string((yyvsp[-3].statementContainer).label).length() == 0){
            o << ": " << do_label << endl;
            o << (yyvsp[-3].statementContainer).code << (yyvsp[0].expressionContainer).code;
            o << "?:= " << do_label << ", " << (yyvsp[0].expressionContainer).place << endl;  
          }
          else {
            o << ": " << do_label << endl;
            o << (yyvsp[-3].statementContainer).code;

            o << ": " << (yyvsp[-3].statementContainer).label << endl;
            o << (yyvsp[0].expressionContainer).code;

            o << "?:= " << do_label << ", " << (yyvsp[0].expressionContainer).place << endl; // Jump back
          }

          (yyval.statementContainer).code = strdup(o.str().c_str());

         }
#line 2015 "y.tab.c"
    break;

  case 29:
#line 483 "mini_l.y"
         {//printf("statement -> FOR var ASSIGN NUMBER SEMICOLON bool-expr SEMICOLON var ASSIGN expression BEGINLOOP statements ENDLOOP\n");
            (yyval.statementContainer).code = "";
            (yyval.statementContainer).label = "";
         }
#line 2024 "y.tab.c"
    break;

  case 30:
#line 488 "mini_l.y"
         {//printf("statement -> READ vars\n");
            (yyval.statementContainer).code = "";
            (yyval.statementContainer).label = "";

            ostringstream o;

            o << (yyvsp[0].expressionContainer).code;
            if (string((yyvsp[0].expressionContainer).place).find("#") == string::npos) { // Check if vars contains more than one variable
            //if (strchr($2.place, '#') == NULL) {

              // If the vars contains only one element and its an array
              if (string((yyvsp[0].expressionContainer).type) == "ARRAY") {
                o << ".[]< " << (yyvsp[0].expressionContainer).array_name << ", " << (yyvsp[0].expressionContainer).place << endl;
                (yyval.statementContainer).code = strdup(o.str().c_str());
                (yyval.statementContainer).place = (yyvsp[0].expressionContainer).place;

              } else if (string((yyvsp[0].expressionContainer).type) == "VARIABLE"){
                o << ".< " << (yyvsp[0].expressionContainer).place << endl;
                (yyval.statementContainer).code = strdup(o.str().c_str());
                (yyval.statementContainer).place = (yyvsp[0].expressionContainer).place;
              }       
            }  else { // The vars contains more than one element
              int index = 0;
              string values = string((yyvsp[0].expressionContainer).place);
              char current_char = values[index];
              
              while (index < values.length()) {
                current_char = (yyvsp[0].expressionContainer).place[index];
                ostringstream _o;

                while ((current_char != '#') && index < values.length()) {
                  _o << current_char;
                  index += 1;
                  current_char = values[index];
                }

                o << ".< " << _o.str().c_str() << endl;
                index += 1;
              }
          }  
          (yyval.statementContainer).code = strdup(o.str().c_str());
         }
#line 2071 "y.tab.c"
    break;

  case 31:
#line 531 "mini_l.y"
         {//printf("statement -> WRITE vars \n");
            (yyval.statementContainer).code = "";
            (yyval.statementContainer).label = "";

            ostringstream o;

            o << (yyvsp[0].expressionContainer).code;
            if (string((yyvsp[0].expressionContainer).place).find("#") == string::npos) { // Check if vars contains more than one variable
            //if (strchr($2.place, '#') == NULL) {

              // If the vars contains only one element and its an array
              if (string((yyvsp[0].expressionContainer).type) == "ARRAY") {
                o << ".[]> " << (yyvsp[0].expressionContainer).array_name << ", " << (yyvsp[0].expressionContainer).place << endl;
                (yyval.statementContainer).code = strdup(o.str().c_str());
                (yyval.statementContainer).place = (yyvsp[0].expressionContainer).place;

              } else if (string((yyvsp[0].expressionContainer).type) == "VARIABLE"){
                o << ".> " << (yyvsp[0].expressionContainer).place << endl;
                (yyval.statementContainer).code = strdup(o.str().c_str());
                (yyval.statementContainer).place = (yyvsp[0].expressionContainer).place;
              }       
            }  else { // The vars contains more than one element
              int index = 0;
              string values = string((yyvsp[0].expressionContainer).place);
              char current_char = values[index];
              
              while (index < values.length()) {
                current_char = (yyvsp[0].expressionContainer).place[index];
                ostringstream _o;

                while ((current_char != '#') && index < values.length()) {
                  _o << current_char;
                  index += 1;
                  current_char = values[index];
                }

                o << ".> " << _o.str().c_str() << endl;
                index += 1;
              }
          }  
          (yyval.statementContainer).code = strdup(o.str().c_str());
         }
#line 2118 "y.tab.c"
    break;

  case 32:
#line 574 "mini_l.y"
         {//printf("statement -> CONTINUE\n");
            (yyval.statementContainer).code = "";
            (yyval.statementContainer).label = "";

            ostringstream o;
            string label = new_label();

            o << ":= " << label << endl;

            (yyval.statementContainer).label = strdup(label.c_str());

            (yyval.statementContainer).code = strdup(o.str().c_str());

            (yyval.statementContainer).place = strdup(label.c_str());
         }
#line 2138 "y.tab.c"
    break;

  case 33:
#line 590 "mini_l.y"
         {//printf("statement -> RETURN expression\n");
            (yyval.statementContainer).code = "";
            (yyval.statementContainer).label = "";

            ostringstream o;

            o << (yyvsp[0].expressionContainer).code;

            o << "ret " << (yyvsp[0].expressionContainer).place << endl;

            (yyval.statementContainer).code = strdup(o.str().c_str());
         }
#line 2155 "y.tab.c"
    break;

  case 34:
#line 604 "mini_l.y"
      {//printf("term -> var\n");
        (yyval.expressionContainer).place = (yyvsp[0].expressionContainer).place;
        (yyval.expressionContainer).code = (yyvsp[0].expressionContainer).code;
        (yyval.expressionContainer).type = (yyvsp[0].expressionContainer).type;
        (yyval.expressionContainer).array_name = (yyvsp[0].expressionContainer).array_name;
      }
#line 2166 "y.tab.c"
    break;

  case 35:
#line 611 "mini_l.y"
      {//printf("term -> NUMBER: %d\n", $1);
        (yyval.expressionContainer).code = "";
        (yyval.expressionContainer).type = "VARIABLE";
        (yyval.expressionContainer).place = strdup(to_string((yyvsp[0].ival)).c_str());
      }
#line 2176 "y.tab.c"
    break;

  case 36:
#line 618 "mini_l.y"
      {//printf("term -> IDENT L_PAREN expression_chain R_PAREN\n");
        // Process the function call
        ostringstream o;
        if (function_calls.count((yyvsp[-3].sval)) < 1) {
          function_calls.insert((yyvsp[-3].sval));
        }

        o << (yyvsp[-1].expressionContainer).code;
        (yyval.expressionContainer).place = (yyvsp[-1].expressionContainer).place;
        (yyval.expressionContainer).type = (yyvsp[-1].expressionContainer).type;

        string temp = new_temp();
        o << "param " << (yyvsp[-1].expressionContainer).place << endl;
        o << ". " << temp << endl;
        o << "call " << (yyvsp[-3].sval) << ", " << temp << endl;

        (yyval.expressionContainer).code = strdup(o.str().c_str());
        (yyval.expressionContainer).place = strdup(temp.c_str());
      }
#line 2200 "y.tab.c"
    break;

  case 37:
#line 638 "mini_l.y"
      {//printf("term -> SUB var\n");
    }
#line 2207 "y.tab.c"
    break;

  case 38:
#line 641 "mini_l.y"
      {//printf("term -> SUB NUMBER\n");
    }
#line 2214 "y.tab.c"
    break;

  case 39:
#line 644 "mini_l.y"
      {//printf("term -> SUB L_PAREN expression R_PAREN\n");
    }
#line 2221 "y.tab.c"
    break;

  case 40:
#line 647 "mini_l.y"
      {//printf("term -> SUB IDENT L_PAREN expression_chain R_PAREN\n");
    }
#line 2228 "y.tab.c"
    break;

  case 41:
#line 651 "mini_l.y"
                            {//printf("multiplicative_expression_0 -> multiplicative_expression\n");
                              (yyval.expressionContainer).code = (yyvsp[0].expressionContainer).code;
                              (yyval.expressionContainer).place = (yyvsp[0].expressionContainer).place;
                            }
#line 2237 "y.tab.c"
    break;

  case 42:
#line 658 "mini_l.y"
                           {//printf("multiplicative_expression -> term MULT multiplicative_expression\n");
                            ostringstream o;
                            o << (yyvsp[-2].expressionContainer).code << (yyvsp[0].expressionContainer).code;
                            string temp = new_temp();
                            o << ". " << temp << endl;
                            o << "* " << temp << ", " << (yyvsp[-2].expressionContainer).place << ", " << (yyvsp[0].expressionContainer).place << endl;
                            
                            Symbol sym = Symbol();
                            sym.type = "VARIABLE";
                            sym.code = strdup( o.str().c_str() ); // Set code
                            sym.value = "";
                            add(temp, sym);

                            (yyval.expressionContainer).code = strdup(o.str().c_str());
                            (yyval.expressionContainer).place = strdup(temp.c_str());

                           }
#line 2259 "y.tab.c"
    break;

  case 43:
#line 676 "mini_l.y"
                           {//printf("multiplicative_expression -> term DIV multiplicative_expression\n");
                              ostringstream o;
                              string temp = new_temp();
                              o << (yyvsp[-2].expressionContainer).code << (yyvsp[0].expressionContainer).code;
                              o << ". " << temp << endl;
                              o << "/ " << temp << ", " << (yyvsp[-2].expressionContainer).place << ", " << (yyvsp[0].expressionContainer).place << endl;

                              Symbol sym = Symbol();
                              sym.type = "VARIABLE";
                              sym.code = strdup( o.str().c_str() ); // Set code
                              sym.value = "";
                              add(temp, sym);

                              (yyval.expressionContainer).code = strdup(o.str().c_str());
                              (yyval.expressionContainer).place = strdup(temp.c_str()); 
                           }
#line 2280 "y.tab.c"
    break;

  case 44:
#line 693 "mini_l.y"
                           {//printf("multiplicative_expression -> term MOD multiplicative_expression\n");
                              ostringstream o;
                              o << (yyvsp[-2].expressionContainer).code << (yyvsp[0].expressionContainer).code;
                              string temp = new_temp();
                              o << ". " << temp << endl;
                              o << "% " << temp << ", " << (yyvsp[-2].expressionContainer).place << ", " << (yyvsp[0].expressionContainer).place << endl;
                              
                              Symbol sym = Symbol();
                              sym.type = "VARIABLE";
                              sym.code = strdup( o.str().c_str() ); // Set code
                              sym.value = "";
                              add(temp, sym);

                              (yyval.expressionContainer).code = strdup(o.str().c_str());
                              (yyval.expressionContainer).place = strdup(temp.c_str());
                           }
#line 2301 "y.tab.c"
    break;

  case 45:
#line 710 "mini_l.y"
                           {//printf("multiplicative_expression -> term\n");
                            if (string((yyvsp[0].expressionContainer).code).length() > 0){

                              ostringstream o;
                              if (strcmp((yyvsp[0].expressionContainer).type, "ARRAY") == 0){

                                string temp = new_temp();
                                
                                o << (yyvsp[0].expressionContainer).code;
                                o << ". " << temp << endl;
                                o << "=[] " << temp << ", " << (yyvsp[0].expressionContainer).array_name << ", " << (yyvsp[0].expressionContainer).place << endl;


                                Symbol sym = Symbol();
                                sym.type = "VARIABLE";
                                sym.code = strdup( o.str().c_str() ); // Set code
                                sym.value = "";
                                add(temp, sym);

                                (yyval.expressionContainer).code = strdup(o.str().c_str());
                                (yyval.expressionContainer).place = strdup(temp.c_str());
                              } else {
                                (yyval.expressionContainer).code = (yyvsp[0].expressionContainer).code;
                                (yyval.expressionContainer).place = (yyvsp[0].expressionContainer).place;
                              }
                            } else {
                              ostringstream o;
                              string temp = new_temp();
                              o << ". " << temp << endl;
                              o << "= " << temp << ", " << (yyvsp[0].expressionContainer).place << endl;
                              
                              Symbol sym = Symbol();
                              sym.type = "VARIABLE";
                              sym.code = strdup( o.str().c_str() ); // Set code
                              sym.value = "";
                              add(temp, sym);
                              
                              (yyval.expressionContainer).code = strdup(o.str().c_str());
                              (yyval.expressionContainer).place = strdup(temp.c_str());
                            }
                           }
#line 2347 "y.tab.c"
    break;

  case 46:
#line 753 "mini_l.y"
            {//printf("bool-expr -> relation-and-expr OR bool-expr\n");
              ostringstream o;
              string temp = new_temp();

              o << (yyvsp[-2].expressionContainer).code << (yyvsp[0].expressionContainer).code;
              o << ". " << temp << endl;
              o << "|| " << temp << ", " << (yyvsp[-2].expressionContainer).place << ", " << (yyvsp[0].expressionContainer).place << endl;

              (yyval.expressionContainer).code = strdup(o.str().c_str());
              (yyval.expressionContainer).place = strdup(temp.c_str());
            }
#line 2363 "y.tab.c"
    break;

  case 47:
#line 765 "mini_l.y"
            {//printf("bool-expr -> relation-and-expr\n");
              (yyval.expressionContainer).code = (yyvsp[0].expressionContainer).code;
              (yyval.expressionContainer).place = (yyvsp[0].expressionContainer).place;
            }
#line 2372 "y.tab.c"
    break;

  case 48:
#line 771 "mini_l.y"
                    {//printf("relation-and-expr -> relation-expr_0 AND relation-and-expr\n");
                      ostringstream o;
                      string temp = new_temp();

                      o << (yyvsp[-2].expressionContainer).code << (yyvsp[0].expressionContainer).code;
                      o << ". " << temp << endl;
                      o << "&& " << temp << ", " << (yyvsp[-2].expressionContainer).place << ", " << (yyvsp[0].expressionContainer).place << endl;

                      (yyval.expressionContainer).code = strdup(o.str().c_str());
                      (yyval.expressionContainer).place = strdup(temp.c_str());
                    }
#line 2388 "y.tab.c"
    break;

  case 49:
#line 783 "mini_l.y"
                    {//printf("relation-and-expr -> relation-expr_0\n");
                      (yyval.expressionContainer).code = (yyvsp[0].expressionContainer).code;
                      (yyval.expressionContainer).place = (yyvsp[0].expressionContainer).place;
                    }
#line 2397 "y.tab.c"
    break;

  case 50:
#line 790 "mini_l.y"
                {//printf("relation_expr -> expression comp expression\n");
                  ostringstream o;
                  string temp = new_temp();

                  o << (yyvsp[-2].expressionContainer).code << (yyvsp[0].expressionContainer).code;
                  o << ". " << temp << "\n"; 
                  o << (yyvsp[-1].comparator).operation << " " << temp << ", " << (yyvsp[-2].expressionContainer).place << ", " << (yyvsp[0].expressionContainer).place << "\n";

                  (yyval.expressionContainer).code = strdup(o.str().c_str());
                  (yyval.expressionContainer).place = strdup(temp.c_str());

                }
#line 2414 "y.tab.c"
    break;

  case 51:
#line 803 "mini_l.y"
                {//printf("relation_expr -> NOT expression comp expression\n");
                  ostringstream o;
                  string temp = new_temp();

                  o << (yyvsp[-2].expressionContainer).code << (yyvsp[0].expressionContainer).code;
                  o << "!. " << temp << "\n"; 
                  o << (yyvsp[-1].comparator).operation << " " << temp << ", " << (yyvsp[-2].expressionContainer).place << ", " << (yyvsp[0].expressionContainer).place << "\n";

                  (yyval.expressionContainer).code = strdup(o.str().c_str());
                  (yyval.expressionContainer).place = strdup(temp.c_str());
                }
#line 2430 "y.tab.c"
    break;

  case 52:
#line 815 "mini_l.y"
                {//printf("relation_expr -> TRUE\n" );
                  (yyval.expressionContainer).code = "";
                  (yyval.expressionContainer).place = "1";
                }
#line 2439 "y.tab.c"
    break;

  case 53:
#line 820 "mini_l.y"
                {//printf("relation_expr -> FALSE\n");
                  (yyval.expressionContainer).code = "";
                  (yyval.expressionContainer).place = "0";
                }
#line 2448 "y.tab.c"
    break;

  case 54:
#line 825 "mini_l.y"
                {//printf("relation_expr -> NOT TRUE\n" );
                  (yyval.expressionContainer).code = "";
                  (yyval.expressionContainer).place = "!1";
                }
#line 2457 "y.tab.c"
    break;

  case 55:
#line 830 "mini_l.y"
                {//printf("relation_expr -> NOT FALSE\n");
                  (yyval.expressionContainer).code = "";
                  (yyval.expressionContainer).place = "!0";
                }
#line 2466 "y.tab.c"
    break;

  case 56:
#line 835 "mini_l.y"
                {//printf("relation_expr -> L_PAREN bool-expr R_PAREN\n");
                  (yyval.expressionContainer).code = (yyvsp[-1].expressionContainer).code;
                  (yyval.expressionContainer).place = (yyvsp[-1].expressionContainer).place;
                }
#line 2475 "y.tab.c"
    break;

  case 57:
#line 840 "mini_l.y"
                {//print f("relation_expr -> NOT L_PAREN bool-expr R_PAREN\n");
                    ostringstream o;

                    (yyval.expressionContainer).code = (yyvsp[-1].expressionContainer).code;

                    o << "!" << (yyvsp[-1].expressionContainer).place;
                    (yyval.expressionContainer).place = strdup(o.str().c_str());
                }
#line 2488 "y.tab.c"
    break;

  case 58:
#line 850 "mini_l.y"
      {//printf("comp -> EQ\n");
        (yyval.comparator).operation = "==";
      }
#line 2496 "y.tab.c"
    break;

  case 59:
#line 854 "mini_l.y"
      {//printf("comp -> NEQ\n");
        (yyval.comparator).operation = "!=";
      }
#line 2504 "y.tab.c"
    break;

  case 60:
#line 858 "mini_l.y"
      {//printf("comp -> LT\n");
        (yyval.comparator).operation = "<";
      }
#line 2512 "y.tab.c"
    break;

  case 61:
#line 862 "mini_l.y"
      {//printf("comp -> GT\n");
        (yyval.comparator).operation = ">";
      }
#line 2520 "y.tab.c"
    break;

  case 62:
#line 866 "mini_l.y"
      {//printf("comp -> LTE\n");
        (yyval.comparator).operation = "<=";
      }
#line 2528 "y.tab.c"
    break;

  case 63:
#line 870 "mini_l.y"
      {//printf("comp -> GTE\n");
        (yyval.comparator).operation = ">=";
      }
#line 2536 "y.tab.c"
    break;

  case 64:
#line 875 "mini_l.y"
            {//printf("expression -> multiplicative_expression PLUS expression\n");
              ostringstream o;
              string temp = new_temp();

              o << (yyvsp[-2].expressionContainer).code << (yyvsp[0].expressionContainer).code;   // append code for both expressions
              o << ". " << temp << endl; // create temp var
              o << "+ " << temp << ", " << (yyvsp[-2].expressionContainer).place << ", " << (yyvsp[0].expressionContainer).place << endl; // Add call

              Symbol sym = Symbol();
              sym.type = "VARIABLE";
              sym.code = strdup( o.str().c_str() ); // Set code
              sym.value = "";
              add(temp, sym);

              (yyval.expressionContainer).code      = strdup( o.str().c_str() ); // Set code
              (yyval.expressionContainer).place     = strdup( temp.c_str()      ); // Set value
            }
#line 2558 "y.tab.c"
    break;

  case 65:
#line 893 "mini_l.y"
            {//printf("expression -> multiplicative_expression SUB expression\n");
              ostringstream o;
              string temp = new_temp();

              o << (yyvsp[-2].expressionContainer).code << (yyvsp[0].expressionContainer).code;   // append code for both expressions
              o << ". " << temp << endl; // create temp var
              o << "- " << temp << ", " << (yyvsp[-2].expressionContainer).place << ", " << (yyvsp[0].expressionContainer).place << endl; // Sub call
              
              Symbol sym = Symbol();
              sym.type = "VARIABLE";
              sym.code = strdup( o.str().c_str() ); // Set code
              sym.value = "";
              add(temp, sym);

              (yyval.expressionContainer).code      = strdup( o.str().c_str() ); // Set code
              (yyval.expressionContainer).place     = strdup( temp.c_str()      ); // Set value

            }
#line 2581 "y.tab.c"
    break;

  case 66:
#line 912 "mini_l.y"
            {//printf("expression -> multiplicative_expression\n");
              (yyval.expressionContainer).place = (yyvsp[0].expressionContainer).place;
              (yyval.expressionContainer).code = (yyvsp[0].expressionContainer).code;
            }
#line 2590 "y.tab.c"
    break;

  case 67:
#line 918 "mini_l.y"
                  {//printf("expression_chain -> expression_chain COMMA expression\n");
                    ostringstream o;
                    o << (yyvsp[-2].expressionContainer).code << (yyvsp[0].expressionContainer).code;
                    (yyval.expressionContainer).code = strdup(o.str().c_str());
                    //$$.place = ""; // Tries to avoid any seg-faults from null values. This may, however, hide some incorrect logic.
                  }
#line 2601 "y.tab.c"
    break;

  case 68:
#line 925 "mini_l.y"
                  {//printf("expression_chain -> expression\n");
                    (yyval.expressionContainer).code = (yyvsp[0].expressionContainer).code;
                    (yyval.expressionContainer).place = (yyvsp[0].expressionContainer).place;
                  }
#line 2610 "y.tab.c"
    break;

  case 69:
#line 931 "mini_l.y"
      {//printf("vars -> vars COMMA var\n");
        ostringstream o;
        o << (yyvsp[-2].expressionContainer).place << "#" << (yyvsp[0].expressionContainer).place;
        (yyval.expressionContainer).place = strdup(o.str().c_str());
        (yyval.expressionContainer).code = "";
      }
#line 2621 "y.tab.c"
    break;

  case 70:
#line 938 "mini_l.y"
      {//printf("vars -> var\n");
        if(strcmp((yyvsp[0].expressionContainer).type, "ARRAY") == 0) {
          (yyval.expressionContainer).code = (yyvsp[0].expressionContainer).code;
          (yyval.expressionContainer).place = (yyvsp[0].expressionContainer).place;
          (yyval.expressionContainer).type == (yyvsp[0].expressionContainer).type;
        }

        if (strcmp((yyvsp[0].expressionContainer).type, "ARRAY2D") == 0) {
          (yyval.expressionContainer).code = (yyvsp[0].expressionContainer).code;
          (yyval.expressionContainer).place = (yyvsp[0].expressionContainer).place;
          (yyval.expressionContainer).type == (yyvsp[0].expressionContainer).type;
        }

        if (strcmp((yyvsp[0].expressionContainer).type, "VARIABLE") == 0) {
          (yyval.expressionContainer).code = (yyvsp[0].expressionContainer).code;
          (yyval.expressionContainer).place = (yyvsp[0].expressionContainer).place;
        }
      }
#line 2644 "y.tab.c"
    break;

  case 71:
#line 958 "mini_l.y"
    {//printf("var -> IDENT  %s \n", $1);
      (yyval.expressionContainer).code = "";
      (yyval.expressionContainer).type = "VARIABLE";
      (yyval.expressionContainer).place = (yyvsp[0].sval);

    }
#line 2655 "y.tab.c"
    break;

  case 72:
#line 965 "mini_l.y"
    {//printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");
      (yyval.expressionContainer).place = (yyvsp[-1].expressionContainer).place;
      (yyval.expressionContainer).array_name = (yyvsp[-3].sval);
      (yyval.expressionContainer).type  = "ARRAY";
      (yyval.expressionContainer).code  = (yyvsp[-1].expressionContainer).code;
    }
#line 2666 "y.tab.c"
    break;

  case 73:
#line 972 "mini_l.y"
    {//printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");
     // Not implemented yet (2D array)
    }
#line 2674 "y.tab.c"
    break;


#line 2678 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 976 "mini_l.y"

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

void yyerror (const char * msg) {
  printf("Error: %s\n", msg);
}

bool exists(string name) {
  auto itr = currentScope->table.find(name);

  if (itr == currentScope->table.end()) {
    return false;
  } else {
    return true;
  }
}

// Checks if a symbol already exists in a given symbol table
bool exists(string name, SymbolTable* table) {
   if (table == nullptr) cout << ("Internal error: cannot check null symbol table");

  auto itr = table->table.find(name);
  if (itr == table->table.end()) {
    return false;
  } else {
    return true;
  }
}

// Attempts to add a symbol to the current scope
bool add(string name, Symbol symbol) {
  stringstream ss;
 
  if (exists(name)) {
    ss << "Error on line " << to_string(lineNum) << ":" << to_string(linePos) << " : Redefinition of " << name << "\n";
    cout << (ss.str().c_str());
    cout << ss.str();
    exit(-1);
  }
  if (currentScope == nullptr) cout << ("Internal error: scope not set");

  currentScope->table.insert(make_pair(name, symbol));

  return true;
}

string new_label(){
  string temp = "__label__";
  temp += to_string(label_count);
  label_count += 1;
  return temp;
}

string new_temp(){
  string temp = "__temp__";
  temp += to_string(temp_count);
  temp_count += 1;
  return temp;
}
