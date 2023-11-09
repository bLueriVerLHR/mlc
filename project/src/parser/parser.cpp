/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"


#include <iostream>

#include "parser.h"
#include "lexer.h"

#define YYINITDEPTH 10000

int yyerror(YYLTYPE *yylloc, yyscan_t scanner, const char *msg) {
  (void)yylloc;
  (void)scanner;
  fprintf(stderr,"<file>:<line>:<column>: %s\n", msg);
  return 0;
}


#line 89 "parser.cpp"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LEX_CONSTANT = 3,               /* LEX_CONSTANT  */
  YYSYMBOL_LEX_IDENTIFIER = 4,             /* LEX_IDENTIFIER  */
  YYSYMBOL_LEX_INT = 5,                    /* LEX_INT  */
  YYSYMBOL_LEX_FLOAT = 6,                  /* LEX_FLOAT  */
  YYSYMBOL_LEX_VOID = 7,                   /* LEX_VOID  */
  YYSYMBOL_LEX_CONST = 8,                  /* LEX_CONST  */
  YYSYMBOL_LEX_GEQ = 9,                    /* LEX_GEQ  */
  YYSYMBOL_LEX_LEQ = 10,                   /* LEX_LEQ  */
  YYSYMBOL_LEX_LAND = 11,                  /* LEX_LAND  */
  YYSYMBOL_LEX_LOR = 12,                   /* LEX_LOR  */
  YYSYMBOL_LEX_EQU = 13,                   /* LEX_EQU  */
  YYSYMBOL_LEX_NEQ = 14,                   /* LEX_NEQ  */
  YYSYMBOL_LEX_IF = 15,                    /* LEX_IF  */
  YYSYMBOL_LEX_ELSE = 16,                  /* LEX_ELSE  */
  YYSYMBOL_LEX_WHILE = 17,                 /* LEX_WHILE  */
  YYSYMBOL_LEX_BREAK = 18,                 /* LEX_BREAK  */
  YYSYMBOL_LEX_CONTINUE = 19,              /* LEX_CONTINUE  */
  YYSYMBOL_LEX_RETURN = 20,                /* LEX_RETURN  */
  YYSYMBOL_21_ = 21,                       /* ';'  */
  YYSYMBOL_22_ = 22,                       /* ','  */
  YYSYMBOL_23_ = 23,                       /* '='  */
  YYSYMBOL_24_ = 24,                       /* '['  */
  YYSYMBOL_25_ = 25,                       /* ']'  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_31_ = 31,                       /* '<'  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '%'  */
  YYSYMBOL_37_ = 37,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_top_scope = 39,                 /* top_scope  */
  YYSYMBOL_translation_unit = 40,          /* translation_unit  */
  YYSYMBOL_declaration = 41,               /* declaration  */
  YYSYMBOL_variable_definitions = 42,      /* variable_definitions  */
  YYSYMBOL_variable_definition = 43,       /* variable_definition  */
  YYSYMBOL_declarator = 44,                /* declarator  */
  YYSYMBOL_param_declarator = 45,          /* param_declarator  */
  YYSYMBOL_initializer = 46,               /* initializer  */
  YYSYMBOL_initializer_list = 47,          /* initializer_list  */
  YYSYMBOL_function_definition = 48,       /* function_definition  */
  YYSYMBOL_function_fake_params = 49,      /* function_fake_params  */
  YYSYMBOL_function_fake_param = 50,       /* function_fake_param  */
  YYSYMBOL_block = 51,                     /* block  */
  YYSYMBOL_block_items = 52,               /* block_items  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_condition = 54,                 /* condition  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_lor_expression = 56,            /* lor_expression  */
  YYSYMBOL_land_expression = 57,           /* land_expression  */
  YYSYMBOL_equ_expression = 58,            /* equ_expression  */
  YYSYMBOL_rel_expression = 59,            /* rel_expression  */
  YYSYMBOL_add_expression = 60,            /* add_expression  */
  YYSYMBOL_mul_expression = 61,            /* mul_expression  */
  YYSYMBOL_unary_expression = 62,          /* unary_expression  */
  YYSYMBOL_primary_expression = 63,        /* primary_expression  */
  YYSYMBOL_left_value = 64,                /* left_value  */
  YYSYMBOL_function_real_params = 65,      /* function_real_params  */
  YYSYMBOL_type_specifier = 66,            /* type_specifier  */
  YYSYMBOL_type_qualifier = 67             /* type_qualifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   275


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,     2,     2,    36,     2,     2,
      28,    29,    34,    32,    22,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    21,
      31,    23,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   105,   105,   112,   123,   134,   139,   147,   158,   163,
     171,   176,   183,   187,   194,   198,   203,   210,   214,   218,
     222,   229,   233,   240,   244,   251,   256,   264,   272,   276,
     283,   288,   293,   303,   316,   320,   324,   328,   332,   336,
     340,   344,   348,   352,   356,   363,   370,   377,   381,   388,
     392,   399,   403,   407,   414,   418,   422,   426,   430,   437,
     441,   445,   452,   456,   460,   464,   471,   475,   479,   483,
     487,   491,   498,   502,   506,   513,   517,   525,   530,   538,
     542,   546,   553,   557
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LEX_CONSTANT",
  "LEX_IDENTIFIER", "LEX_INT", "LEX_FLOAT", "LEX_VOID", "LEX_CONST",
  "LEX_GEQ", "LEX_LEQ", "LEX_LAND", "LEX_LOR", "LEX_EQU", "LEX_NEQ",
  "LEX_IF", "LEX_ELSE", "LEX_WHILE", "LEX_BREAK", "LEX_CONTINUE",
  "LEX_RETURN", "';'", "','", "'='", "'['", "']'", "'{'", "'}'", "'('",
  "')'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "$accept",
  "top_scope", "translation_unit", "declaration", "variable_definitions",
  "variable_definition", "declarator", "param_declarator", "initializer",
  "initializer_list", "function_definition", "function_fake_params",
  "function_fake_param", "block", "block_items", "statement", "condition",
  "expression", "lor_expression", "land_expression", "equ_expression",
  "rel_expression", "add_expression", "mul_expression", "unary_expression",
  "primary_expression", "left_value", "function_real_params",
  "type_specifier", "type_qualifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      30,   -73,    44,    11,   -73,   -73,    17,   -73,   -73,   -73,
     -73,   -73,   -73,    48,    28,   -12,   -73,    49,     8,   -73,
      54,    22,   164,    39,    -2,   -73,    17,   -73,   -73,   -73,
      66,    14,   164,   164,   164,   164,   -73,   -73,    47,   -73,
      42,   -73,    99,    57,   101,   -73,    30,    39,   120,   149,
     -73,   -73,    12,   102,   -73,   -73,   -73,   164,   164,   164,
     164,   164,   164,   -73,   104,   107,   115,   123,   162,   -73,
     -73,   -73,   -73,   122,   -73,   124,    63,    17,   -73,   -73,
     127,   132,   -73,   -73,    -1,    80,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   145,   164,   164,   -73,   -73,   -73,   136,
     -73,   -73,   -73,   -73,   164,    54,   147,   164,   164,   -73,
     -73,   -73,   -73,   144,   167,   163,    97,     5,    47,   155,
     -73,   166,   -73,   160,   -73,   143,   164,   164,   164,   164,
     164,   164,   164,   164,   143,   -73,   -73,   172,   163,    97,
       5,     5,    47,    47,    47,    47,   -73,   143,   -73
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      82,    83,     0,    82,     3,     5,     0,     1,     4,     6,
      79,    80,    81,     0,    13,     0,     8,    11,    82,     7,
       0,     0,     0,     0,     0,    25,     0,    13,     9,    74,
      75,     0,     0,     0,     0,     0,    10,    18,    46,    59,
      62,    66,    73,     0,    82,    24,    82,     0,     0,     0,
      17,    21,     0,     0,    69,    70,    71,     0,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,    34,
      29,    32,    37,    82,    30,     0,    73,     0,    26,    23,
      16,    27,    67,    77,     0,     0,    19,    72,    60,    61,
      63,    64,    65,     0,     0,     0,    41,    42,    43,     0,
      28,    33,    31,    35,     0,     0,     0,     0,     0,    68,
      20,    22,    76,     0,    45,    47,    49,    51,    54,     0,
      44,     0,    15,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    14,    38,    48,    50,
      52,    53,    55,    56,    57,    58,    40,     0,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,     1,   -73,   169,   -73,   -73,   -24,   -73,
     188,   -73,   152,   -15,   -73,   -72,    98,   -19,   -73,    74,
      75,   -14,   -31,    10,    58,   -73,   -44,   -73,   -20,   -13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    15,    16,    17,    81,    36,    52,
       5,    24,    25,    72,    73,    74,   113,    75,   114,   115,
     116,   117,    38,    39,    40,    41,    42,    84,    13,     6
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,   102,    37,    43,     8,    26,    48,    51,    45,    19,
      20,    -2,    37,    53,   130,   131,     1,    29,    30,     1,
      46,   108,    10,    11,    12,    29,    30,    47,   109,    76,
      83,    77,    79,    26,    85,   132,   133,    23,     1,    86,
      31,    50,    32,    93,     7,    71,    33,    34,    31,    99,
      32,    35,    14,   137,    33,    34,    18,   105,    27,    35,
      77,   111,   146,   118,   118,    44,    37,    88,    89,    90,
      91,    92,    21,    22,   101,   148,    59,    60,    61,    57,
      58,    76,    63,    29,    30,   121,   104,    62,   123,   124,
      76,    54,    55,    56,    49,   118,   118,   118,   118,   142,
     143,   144,   145,    76,    29,    30,    31,   110,    32,     1,
     128,   129,    33,    34,   140,   141,    64,    35,    65,    66,
      67,    68,    69,    62,    80,    29,    30,    44,    70,    32,
       1,    87,    94,    33,    34,    95,    96,    64,    35,    65,
      66,    67,    68,    69,    97,   103,    29,    30,    44,   100,
      32,   106,    29,    30,    33,    34,   107,   120,    64,    35,
      65,    66,    67,    68,    69,    29,    30,    29,    30,    44,
     112,    32,   122,   125,   127,    33,    34,    32,    82,   126,
      35,    33,    34,    98,   134,   136,    35,   135,   147,    28,
      32,     9,    32,   119,    33,    34,    33,    34,    78,    35,
     138,    35,   139
};

static const yytype_uint8 yycheck[] =
{
      44,    73,    21,    22,     3,    18,    26,    31,    23,    21,
      22,     0,    31,    32,     9,    10,     8,     3,     4,     8,
      22,    22,     5,     6,     7,     3,     4,    29,    29,    73,
      49,    44,    47,    46,    22,    30,    31,    29,     8,    27,
      26,    27,    28,    62,     0,    44,    32,    33,    26,    68,
      28,    37,     4,   125,    32,    33,    28,    77,     4,    37,
      73,    85,   134,    94,    95,    26,    85,    57,    58,    59,
      60,    61,    23,    24,    73,   147,    34,    35,    36,    32,
      33,   125,    25,     3,     4,   104,    23,    24,   107,   108,
     134,    33,    34,    35,    28,   126,   127,   128,   129,   130,
     131,   132,   133,   147,     3,     4,    26,    27,    28,     8,
      13,    14,    32,    33,   128,   129,    15,    37,    17,    18,
      19,    20,    21,    24,     4,     3,     4,    26,    27,    28,
       8,    29,    28,    32,    33,    28,    21,    15,    37,    17,
      18,    19,    20,    21,    21,    21,     3,     4,    26,    27,
      28,    24,     3,     4,    32,    33,    24,    21,    15,    37,
      17,    18,    19,    20,    21,     3,     4,     3,     4,    26,
      25,    28,    25,    29,    11,    32,    33,    28,    29,    12,
      37,    32,    33,    21,    29,    25,    37,    21,    16,    20,
      28,     3,    28,    95,    32,    33,    32,    33,    46,    37,
     126,    37,   127
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    39,    40,    41,    48,    67,     0,    41,    48,
       5,     6,     7,    66,     4,    42,    43,    44,    28,    21,
      22,    23,    24,    29,    49,    50,    67,     4,    43,     3,
       4,    26,    28,    32,    33,    37,    46,    55,    60,    61,
      62,    63,    64,    55,    26,    51,    22,    29,    66,    28,
      27,    46,    47,    55,    62,    62,    62,    32,    33,    34,
      35,    36,    24,    25,    15,    17,    18,    19,    20,    21,
      27,    41,    51,    52,    53,    55,    64,    67,    50,    51,
       4,    45,    29,    55,    65,    22,    27,    29,    61,    61,
      61,    61,    61,    55,    28,    28,    21,    21,    21,    55,
      27,    41,    53,    21,    23,    66,    24,    24,    22,    29,
      27,    46,    25,    54,    56,    57,    58,    59,    60,    54,
      21,    55,    25,    55,    55,    29,    12,    11,    13,    14,
       9,    10,    30,    31,    29,    21,    25,    53,    57,    58,
      59,    59,    60,    60,    60,    60,    53,    16,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    40,    40,    41,    42,    42,
      43,    43,    44,    44,    45,    45,    45,    46,    46,    46,
      46,    47,    47,    48,    48,    49,    49,    50,    51,    51,
      52,    52,    52,    52,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    55,    56,    56,    57,
      57,    58,    58,    58,    59,    59,    59,    59,    59,    60,
      60,    60,    61,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    63,    63,    63,    64,    64,    65,    65,    66,
      66,    66,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     4,     1,     3,
       3,     1,     4,     1,     4,     3,     1,     2,     1,     3,
       4,     1,     3,     7,     6,     1,     3,     3,     3,     2,
       1,     2,     1,     2,     1,     2,     4,     1,     5,     7,
       5,     2,     2,     2,     3,     1,     1,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     4,     2,
       2,     2,     3,     1,     1,     1,     4,     1,     3,     1,
       1,     1,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (&yylloc, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, yyscan_t scanner)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* top_scope: translation_unit  */
#line 106 "parser.y"
  {
    sem_ast = (yyvsp[0].block);
  }
#line 1652 "parser.cpp"
    break;

  case 3: /* translation_unit: declaration  */
#line 113 "parser.y"
  {
    (yyval.block) = new sem_region;
    std::list<sem_declaration *> &decls = *(yyvsp[0].declarations);
    for (sem_declaration *&decl : decls) {
      decl->set_is_global();
      (yyval.block)->add_operation(decl);
      decl = nullptr;
    }
    delete (yyvsp[0].declarations);
  }
#line 1667 "parser.cpp"
    break;

  case 4: /* translation_unit: translation_unit declaration  */
#line 124 "parser.y"
  {
    (yyval.block) = (yyvsp[-1].block);
    std::list<sem_declaration *> &decls = *(yyvsp[0].declarations);
    for (sem_declaration *&decl : decls) {
      decl->set_is_global();
      (yyval.block)->add_operation(decl);
      decl = nullptr;
    }
    delete (yyvsp[0].declarations);
  }
#line 1682 "parser.cpp"
    break;

  case 5: /* translation_unit: function_definition  */
#line 135 "parser.y"
  {
    (yyval.block) = new sem_region;
    (yyval.block)->add_operation((yyvsp[0].function_definition));
  }
#line 1691 "parser.cpp"
    break;

  case 6: /* translation_unit: translation_unit function_definition  */
#line 140 "parser.y"
  {
    (yyval.block) = (yyvsp[-1].block);
    (yyval.block)->add_operation((yyvsp[0].function_definition));
  }
#line 1700 "parser.cpp"
    break;

  case 7: /* declaration: type_qualifier type_specifier variable_definitions ';'  */
#line 148 "parser.y"
  {
    (yyval.declarations) = (yyvsp[-1].declarations);
    std::list<sem_declaration *> &decls = *(yyval.declarations);
    for (sem_declaration *decl : decls) {
      decl->set_type_info((yyvsp[-3].type_qualifier), (yyvsp[-2].type_specifier));
    }
  }
#line 1712 "parser.cpp"
    break;

  case 8: /* variable_definitions: variable_definition  */
#line 159 "parser.y"
  {
    (yyval.declarations) = new std::list<sem_declaration *>;
    (yyval.declarations)->push_back((yyvsp[0].declaration));
  }
#line 1721 "parser.cpp"
    break;

  case 9: /* variable_definitions: variable_definitions ',' variable_definition  */
#line 164 "parser.y"
  {
    (yyval.declarations) = (yyvsp[-2].declarations);
    (yyval.declarations)->push_back((yyvsp[0].declaration));
  }
#line 1730 "parser.cpp"
    break;

  case 10: /* variable_definition: declarator '=' initializer  */
#line 172 "parser.y"
  {
    (yyval.declaration) = (yyvsp[-2].declaration);
    (yyvsp[-2].declaration)->set_init_list((yyvsp[0].init_list));
  }
#line 1739 "parser.cpp"
    break;

  case 11: /* variable_definition: declarator  */
#line 177 "parser.y"
  {
    (yyval.declaration) = (yyvsp[0].declaration);
  }
#line 1747 "parser.cpp"
    break;

  case 12: /* declarator: declarator '[' expression ']'  */
#line 184 "parser.y"
  {
    (yyval.declaration)->add_dimension((yyvsp[-1].expression));
  }
#line 1755 "parser.cpp"
    break;

  case 13: /* declarator: LEX_IDENTIFIER  */
#line 188 "parser.y"
  {
    (yyval.declaration) = new sem_declaration((yyvsp[0].identifier));
  }
#line 1763 "parser.cpp"
    break;

  case 14: /* param_declarator: param_declarator '[' expression ']'  */
#line 195 "parser.y"
  {
    (yyval.param_declaration)->add_dimension((yyvsp[-1].expression));
  }
#line 1771 "parser.cpp"
    break;

  case 15: /* param_declarator: LEX_IDENTIFIER '[' ']'  */
#line 199 "parser.y"
  {
    (yyval.param_declaration) = new sem_param_declaration((yyvsp[-2].identifier));
    (yyval.param_declaration)->set_is_pointer();
  }
#line 1780 "parser.cpp"
    break;

  case 16: /* param_declarator: LEX_IDENTIFIER  */
#line 204 "parser.y"
  {
    (yyval.param_declaration) = new sem_param_declaration((yyvsp[0].identifier));
  }
#line 1788 "parser.cpp"
    break;

  case 17: /* initializer: '{' '}'  */
#line 211 "parser.y"
  {
    (yyval.init_list) = new sem_init_list();
  }
#line 1796 "parser.cpp"
    break;

  case 18: /* initializer: expression  */
#line 215 "parser.y"
  {
    (yyval.init_list) = new sem_init_list((yyvsp[0].expression));
  }
#line 1804 "parser.cpp"
    break;

  case 19: /* initializer: '{' initializer_list '}'  */
#line 219 "parser.y"
  {
    (yyval.init_list) = (yyvsp[-1].init_list);
  }
#line 1812 "parser.cpp"
    break;

  case 20: /* initializer: '{' initializer_list ',' '}'  */
#line 223 "parser.y"
  {
    (yyval.init_list) = (yyvsp[-2].init_list);
  }
#line 1820 "parser.cpp"
    break;

  case 21: /* initializer_list: initializer  */
#line 230 "parser.y"
  {
    (yyval.init_list) = new sem_init_list((yyvsp[0].init_list));
  }
#line 1828 "parser.cpp"
    break;

  case 22: /* initializer_list: initializer_list ',' initializer  */
#line 234 "parser.y"
  {
    (yyval.init_list)->add_init_list((yyvsp[0].init_list));
  }
#line 1836 "parser.cpp"
    break;

  case 23: /* function_definition: type_qualifier type_specifier LEX_IDENTIFIER '(' function_fake_params ')' block  */
#line 241 "parser.y"
  {
    (yyval.function_definition) = new sem_function_definition((yyvsp[-6].type_qualifier), (yyvsp[-5].type_specifier), (yyvsp[-4].identifier), (yyvsp[-2].param_declarations), (yyvsp[0].block));
  }
#line 1844 "parser.cpp"
    break;

  case 24: /* function_definition: type_qualifier type_specifier LEX_IDENTIFIER '(' ')' block  */
#line 245 "parser.y"
  {
    (yyval.function_definition) = new sem_function_definition((yyvsp[-5].type_qualifier), (yyvsp[-4].type_specifier), (yyvsp[-3].identifier), nullptr, (yyvsp[0].block));
  }
#line 1852 "parser.cpp"
    break;

  case 25: /* function_fake_params: function_fake_param  */
#line 252 "parser.y"
  {
    (yyval.param_declarations) = new std::list<sem_param_declaration *>;
    (yyval.param_declarations)->push_back((yyvsp[0].param_declaration));
  }
#line 1861 "parser.cpp"
    break;

  case 26: /* function_fake_params: function_fake_params ',' function_fake_param  */
#line 257 "parser.y"
  {
    (yyval.param_declarations) = (yyvsp[-2].param_declarations);
    (yyval.param_declarations)->push_back((yyvsp[0].param_declaration));
  }
#line 1870 "parser.cpp"
    break;

  case 27: /* function_fake_param: type_qualifier type_specifier param_declarator  */
#line 265 "parser.y"
  {
    (yyval.param_declaration) = (yyvsp[0].param_declaration);
    (yyval.param_declaration)->set_type_info((yyvsp[-2].type_qualifier), (yyvsp[-1].type_specifier));
  }
#line 1879 "parser.cpp"
    break;

  case 28: /* block: '{' block_items '}'  */
#line 273 "parser.y"
  {
    (yyval.block) = (yyvsp[-1].block);
  }
#line 1887 "parser.cpp"
    break;

  case 29: /* block: '{' '}'  */
#line 277 "parser.y"
  {
    (yyval.block) = new sem_region;
  }
#line 1895 "parser.cpp"
    break;

  case 30: /* block_items: statement  */
#line 284 "parser.y"
  {
    (yyval.block) = new sem_region;
    (yyval.block)->add_operation((yyvsp[0].operation));
  }
#line 1904 "parser.cpp"
    break;

  case 31: /* block_items: block_items statement  */
#line 289 "parser.y"
  {
    (yyval.block) = (yyvsp[-1].block);
    (yyval.block)->add_operation((yyvsp[0].operation));
  }
#line 1913 "parser.cpp"
    break;

  case 32: /* block_items: declaration  */
#line 294 "parser.y"
  {
    (yyval.block) = new sem_region;
    std::list<sem_declaration *> &decls = *(yyvsp[0].declarations);
    for (sem_declaration *&decl : decls) {
      (yyval.block)->add_operation(decl);
      decl = nullptr;
    }
    delete (yyvsp[0].declarations);
  }
#line 1927 "parser.cpp"
    break;

  case 33: /* block_items: block_items declaration  */
#line 304 "parser.y"
  {
    (yyval.block) = (yyvsp[-1].block);
    std::list<sem_declaration *> &decls = *(yyvsp[0].declarations);
    for (sem_declaration *&decl : decls) {
      (yyval.block)->add_operation(decl);
      decl = nullptr;
    }
    delete (yyvsp[0].declarations);
  }
#line 1941 "parser.cpp"
    break;

  case 34: /* statement: ';'  */
#line 317 "parser.y"
  {
    (yyval.operation) = nullptr;
  }
#line 1949 "parser.cpp"
    break;

  case 35: /* statement: expression ';'  */
#line 321 "parser.y"
  {
    (yyval.operation) = (yyvsp[-1].expression);
  }
#line 1957 "parser.cpp"
    break;

  case 36: /* statement: left_value '=' expression ';'  */
#line 325 "parser.y"
  {
    (yyval.operation) = new sem_assignment((yyvsp[-3].left_value), (yyvsp[-1].expression));
  }
#line 1965 "parser.cpp"
    break;

  case 37: /* statement: block  */
#line 329 "parser.y"
  {
    (yyval.operation) = new sem_plain_block((yyvsp[0].block));
  }
#line 1973 "parser.cpp"
    break;

  case 38: /* statement: LEX_IF '(' condition ')' statement  */
#line 333 "parser.y"
  {
    (yyval.operation) = new sem_branch((yyvsp[-2].expression), (yyvsp[0].operation));
  }
#line 1981 "parser.cpp"
    break;

  case 39: /* statement: LEX_IF '(' condition ')' statement LEX_ELSE statement  */
#line 337 "parser.y"
  {
    (yyval.operation) = new sem_branch((yyvsp[-4].expression), (yyvsp[-2].operation), (yyvsp[0].operation));
  }
#line 1989 "parser.cpp"
    break;

  case 40: /* statement: LEX_WHILE '(' condition ')' statement  */
#line 341 "parser.y"
  {
    (yyval.operation) = new sem_loop((yyvsp[-2].expression), (yyvsp[0].operation));
  }
#line 1997 "parser.cpp"
    break;

  case 41: /* statement: LEX_BREAK ';'  */
#line 345 "parser.y"
  {
    (yyval.operation) = new sem_break;
  }
#line 2005 "parser.cpp"
    break;

  case 42: /* statement: LEX_CONTINUE ';'  */
#line 349 "parser.y"
  {
    (yyval.operation) = new sem_continue;
  }
#line 2013 "parser.cpp"
    break;

  case 43: /* statement: LEX_RETURN ';'  */
#line 353 "parser.y"
  {
    (yyval.operation) = new sem_return;
  }
#line 2021 "parser.cpp"
    break;

  case 44: /* statement: LEX_RETURN expression ';'  */
#line 357 "parser.y"
  {
    (yyval.operation) = new sem_return((yyvsp[-1].expression));
  }
#line 2029 "parser.cpp"
    break;

  case 45: /* condition: lor_expression  */
#line 364 "parser.y"
  {
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2037 "parser.cpp"
    break;

  case 46: /* expression: add_expression  */
#line 371 "parser.y"
  {
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2045 "parser.cpp"
    break;

  case 47: /* lor_expression: land_expression  */
#line 378 "parser.y"
  {
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2053 "parser.cpp"
    break;

  case 48: /* lor_expression: lor_expression LEX_LOR land_expression  */
#line 382 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::LOR, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2061 "parser.cpp"
    break;

  case 49: /* land_expression: equ_expression  */
#line 389 "parser.y"
  {
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2069 "parser.cpp"
    break;

  case 50: /* land_expression: land_expression LEX_LAND equ_expression  */
#line 393 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::LAND, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2077 "parser.cpp"
    break;

  case 51: /* equ_expression: rel_expression  */
#line 400 "parser.y"
  {
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2085 "parser.cpp"
    break;

  case 52: /* equ_expression: equ_expression LEX_EQU rel_expression  */
#line 404 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::EQU, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2093 "parser.cpp"
    break;

  case 53: /* equ_expression: equ_expression LEX_NEQ rel_expression  */
#line 408 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::NEQ, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2101 "parser.cpp"
    break;

  case 54: /* rel_expression: add_expression  */
#line 415 "parser.y"
  {
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2109 "parser.cpp"
    break;

  case 55: /* rel_expression: rel_expression LEX_GEQ add_expression  */
#line 419 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::GEQ, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2117 "parser.cpp"
    break;

  case 56: /* rel_expression: rel_expression LEX_LEQ add_expression  */
#line 423 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::LEQ, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2125 "parser.cpp"
    break;

  case 57: /* rel_expression: rel_expression '>' add_expression  */
#line 427 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::GTH, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2133 "parser.cpp"
    break;

  case 58: /* rel_expression: rel_expression '<' add_expression  */
#line 431 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::LTH, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2141 "parser.cpp"
    break;

  case 59: /* add_expression: mul_expression  */
#line 438 "parser.y"
  {
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2149 "parser.cpp"
    break;

  case 60: /* add_expression: add_expression '+' mul_expression  */
#line 442 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::ADD, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2157 "parser.cpp"
    break;

  case 61: /* add_expression: add_expression '-' mul_expression  */
#line 446 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::SUB, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2165 "parser.cpp"
    break;

  case 62: /* mul_expression: unary_expression  */
#line 453 "parser.y"
  {
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2173 "parser.cpp"
    break;

  case 63: /* mul_expression: unary_expression '*' mul_expression  */
#line 457 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::MUL, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2181 "parser.cpp"
    break;

  case 64: /* mul_expression: unary_expression '/' mul_expression  */
#line 461 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::DIV, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2189 "parser.cpp"
    break;

  case 65: /* mul_expression: unary_expression '%' mul_expression  */
#line 465 "parser.y"
  {
    (yyval.expression) = new sem_arith_binary(SEM_ARITH_BINARY::MOD, (yyvsp[-2].expression), (yyvsp[0].expression));
  }
#line 2197 "parser.cpp"
    break;

  case 66: /* unary_expression: primary_expression  */
#line 472 "parser.y"
  {
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2205 "parser.cpp"
    break;

  case 67: /* unary_expression: LEX_IDENTIFIER '(' ')'  */
#line 476 "parser.y"
  {
    (yyval.expression) = new sem_function_call((yyvsp[-2].identifier), nullptr);
  }
#line 2213 "parser.cpp"
    break;

  case 68: /* unary_expression: LEX_IDENTIFIER '(' function_real_params ')'  */
#line 480 "parser.y"
  {
    (yyval.expression) = new sem_function_call((yyvsp[-3].identifier), (yyvsp[-1].expressions));
  }
#line 2221 "parser.cpp"
    break;

  case 69: /* unary_expression: '+' unary_expression  */
#line 484 "parser.y"
  {
    (yyval.expression) = (yyvsp[0].expression);
  }
#line 2229 "parser.cpp"
    break;

  case 70: /* unary_expression: '-' unary_expression  */
#line 488 "parser.y"
  {
    (yyval.expression) = new sem_arith_unary(SEM_ARITH_UNARY::NEG, (yyvsp[0].expression));
  }
#line 2237 "parser.cpp"
    break;

  case 71: /* unary_expression: '!' unary_expression  */
#line 492 "parser.y"
  {
    (yyval.expression) = new sem_arith_unary(SEM_ARITH_UNARY::LNOT, (yyvsp[0].expression));
  }
#line 2245 "parser.cpp"
    break;

  case 72: /* primary_expression: '(' expression ')'  */
#line 499 "parser.y"
  {
    (yyval.expression) = (yyvsp[-1].expression);
  }
#line 2253 "parser.cpp"
    break;

  case 73: /* primary_expression: left_value  */
#line 503 "parser.y"
  {
    (yyval.expression) = new sem_arith_left_value((yyvsp[0].left_value));
  }
#line 2261 "parser.cpp"
    break;

  case 74: /* primary_expression: LEX_CONSTANT  */
#line 507 "parser.y"
  {
    (yyval.expression) = new sem_arith_constant((yyvsp[0].constant));
  }
#line 2269 "parser.cpp"
    break;

  case 75: /* left_value: LEX_IDENTIFIER  */
#line 514 "parser.y"
  {
    (yyval.left_value) = new sem_left_value((yyvsp[0].identifier));
  }
#line 2277 "parser.cpp"
    break;

  case 76: /* left_value: left_value '[' expression ']'  */
#line 518 "parser.y"
  {
    (yyval.left_value) = (yyvsp[-3].left_value);
    (yyval.left_value)->add_dimension((yyvsp[-1].expression));
  }
#line 2286 "parser.cpp"
    break;

  case 77: /* function_real_params: expression  */
#line 526 "parser.y"
  {
    (yyval.expressions) = new std::list<sem_expression *>;
    (yyval.expressions)->push_back((yyvsp[0].expression));
  }
#line 2295 "parser.cpp"
    break;

  case 78: /* function_real_params: function_real_params ',' expression  */
#line 531 "parser.y"
  {
    (yyval.expressions) = (yyvsp[-2].expressions);
    (yyval.expressions)->push_back((yyvsp[0].expression));
  }
#line 2304 "parser.cpp"
    break;

  case 79: /* type_specifier: LEX_INT  */
#line 539 "parser.y"
  {
    (yyval.type_specifier) = SEM_TYPE_SPECIFIER::INT;
  }
#line 2312 "parser.cpp"
    break;

  case 80: /* type_specifier: LEX_FLOAT  */
#line 543 "parser.y"
  {
    (yyval.type_specifier) = SEM_TYPE_SPECIFIER::FLOAT;
  }
#line 2320 "parser.cpp"
    break;

  case 81: /* type_specifier: LEX_VOID  */
#line 547 "parser.y"
  {
    (yyval.type_specifier) = SEM_TYPE_SPECIFIER::VOID;
  }
#line 2328 "parser.cpp"
    break;

  case 82: /* type_qualifier: %empty  */
#line 554 "parser.y"
  {
    (yyval.type_qualifier) = SEM_TYPE_QUALIFIER::UNDEFINED;
  }
#line 2336 "parser.cpp"
    break;

  case 83: /* type_qualifier: LEX_CONST  */
#line 558 "parser.y"
  {
    (yyval.type_qualifier) = SEM_TYPE_QUALIFIER::CONST;
  }
#line 2344 "parser.cpp"
    break;


#line 2348 "parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, scanner);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 563 "parser.y"
