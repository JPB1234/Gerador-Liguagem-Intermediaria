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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatica.y"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
	int tamanhoTemp = 10000;
};


typedef struct
{
	string nomeVal;
	string tempName;
	string tipoVal;
	int tamanho = 10000;

} TIPO_SIMBOLO;


vector<atributos> tabela_de_temporarias;
int escopo = 0;
std::vector<std::list<TIPO_SIMBOLO>> pilha_de_simbolos;

list<TIPO_SIMBOLO> novaTabela()
{
	std::list<TIPO_SIMBOLO> nova_tabela;
	return nova_tabela;
}

void printVals(){ 

	for (const std::list<TIPO_SIMBOLO>& lista : pilha_de_simbolos) {
		for (const TIPO_SIMBOLO& index : lista) {
			if(index.tamanho != 0 && index.tipoVal == "string")
			{
				if(empty(index.tempName))
				{
					cout<< "	" <<"char" <<'['<<index.tamanho<<']'<< " " <<index.nomeVal << ";" <<endl;
				}
				else
				{
					cout<< "	" <<"char" << '['<<index.tamanho<<']'<<" "<<index.tempName << ";" <<endl;
				}
			}
			else if (index.tipoVal == "bool") {
				if (empty(index.tempName)) {
					cout << "\t" << "int" << " " << index.nomeVal << ";" << endl;
				} else {
					cout << "\t" << "int" << " " << index.tempName << ";" << endl;
				}
			} else {
				if (empty(index.tempName)) {
					cout << "\t" << index.tipoVal << " " << index.nomeVal << ";" << endl;
				} else {
					cout << "\t" << index.tipoVal << " " << index.tempName << ";" << endl;
				}
			}
		}
}
	
}

int contador = 0;
string genLabel(){

	stringstream ss;
	ss <<"temp" << contador++;
	return ss.str(); 
}




int yylex(void);
void yyerror(string);

#line 159 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_INT = 258,                  /* TK_INT  */
    TK_FLOAT = 259,                /* TK_FLOAT  */
    TK_CHAR = 260,                 /* TK_CHAR  */
    TK_STRING = 261,               /* TK_STRING  */
    TK_BOOLEAN = 262,              /* TK_BOOLEAN  */
    TK_MAIN = 263,                 /* TK_MAIN  */
    TK_ID = 264,                   /* TK_ID  */
    TK_TIPO_INT = 265,             /* TK_TIPO_INT  */
    TK_TIPO_FLOAT = 266,           /* TK_TIPO_FLOAT  */
    TK_TIPO_CHAR = 267,            /* TK_TIPO_CHAR  */
    TK_TIPO_STRING = 268,          /* TK_TIPO_STRING  */
    TK_TIPO_BOOLEAN = 269,         /* TK_TIPO_BOOLEAN  */
    TK_OPERADORES = 270,           /* TK_OPERADORES  */
    TK_CONV_FLOAT = 271,           /* TK_CONV_FLOAT  */
    TK_CONV_INT = 272,             /* TK_CONV_INT  */
    TK_AND = 273,                  /* TK_AND  */
    TK_OR = 274,                   /* TK_OR  */
    TK_REL_IGUALD = 275,           /* TK_REL_IGUALD  */
    TK_REL_MAIOR = 276,            /* TK_REL_MAIOR  */
    TK_REL_MENOR = 277,            /* TK_REL_MENOR  */
    TK_REL_DIF = 278,              /* TK_REL_DIF  */
    TK_IF = 279,                   /* TK_IF  */
    TK_ELSE = 280,                 /* TK_ELSE  */
    TK_FOR = 281,                  /* TK_FOR  */
    TK_WHILE = 282,                /* TK_WHILE  */
    TK_COUT = 283,                 /* TK_COUT  */
    TK_ESPACOS = 284,              /* TK_ESPACOS  */
    TK_FIM = 285,                  /* TK_FIM  */
    TK_ERROR = 286                 /* TK_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_INT 258
#define TK_FLOAT 259
#define TK_CHAR 260
#define TK_STRING 261
#define TK_BOOLEAN 262
#define TK_MAIN 263
#define TK_ID 264
#define TK_TIPO_INT 265
#define TK_TIPO_FLOAT 266
#define TK_TIPO_CHAR 267
#define TK_TIPO_STRING 268
#define TK_TIPO_BOOLEAN 269
#define TK_OPERADORES 270
#define TK_CONV_FLOAT 271
#define TK_CONV_INT 272
#define TK_AND 273
#define TK_OR 274
#define TK_REL_IGUALD 275
#define TK_REL_MAIOR 276
#define TK_REL_MENOR 277
#define TK_REL_DIF 278
#define TK_IF 279
#define TK_ELSE 280
#define TK_FOR 281
#define TK_WHILE 282
#define TK_COUT 283
#define TK_ESPACOS 284
#define TK_FIM 285
#define TK_ERROR 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_INT = 3,                     /* TK_INT  */
  YYSYMBOL_TK_FLOAT = 4,                   /* TK_FLOAT  */
  YYSYMBOL_TK_CHAR = 5,                    /* TK_CHAR  */
  YYSYMBOL_TK_STRING = 6,                  /* TK_STRING  */
  YYSYMBOL_TK_BOOLEAN = 7,                 /* TK_BOOLEAN  */
  YYSYMBOL_TK_MAIN = 8,                    /* TK_MAIN  */
  YYSYMBOL_TK_ID = 9,                      /* TK_ID  */
  YYSYMBOL_TK_TIPO_INT = 10,               /* TK_TIPO_INT  */
  YYSYMBOL_TK_TIPO_FLOAT = 11,             /* TK_TIPO_FLOAT  */
  YYSYMBOL_TK_TIPO_CHAR = 12,              /* TK_TIPO_CHAR  */
  YYSYMBOL_TK_TIPO_STRING = 13,            /* TK_TIPO_STRING  */
  YYSYMBOL_TK_TIPO_BOOLEAN = 14,           /* TK_TIPO_BOOLEAN  */
  YYSYMBOL_TK_OPERADORES = 15,             /* TK_OPERADORES  */
  YYSYMBOL_TK_CONV_FLOAT = 16,             /* TK_CONV_FLOAT  */
  YYSYMBOL_TK_CONV_INT = 17,               /* TK_CONV_INT  */
  YYSYMBOL_TK_AND = 18,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 19,                     /* TK_OR  */
  YYSYMBOL_TK_REL_IGUALD = 20,             /* TK_REL_IGUALD  */
  YYSYMBOL_TK_REL_MAIOR = 21,              /* TK_REL_MAIOR  */
  YYSYMBOL_TK_REL_MENOR = 22,              /* TK_REL_MENOR  */
  YYSYMBOL_TK_REL_DIF = 23,                /* TK_REL_DIF  */
  YYSYMBOL_TK_IF = 24,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 25,                   /* TK_ELSE  */
  YYSYMBOL_TK_FOR = 26,                    /* TK_FOR  */
  YYSYMBOL_TK_WHILE = 27,                  /* TK_WHILE  */
  YYSYMBOL_TK_COUT = 28,                   /* TK_COUT  */
  YYSYMBOL_TK_ESPACOS = 29,                /* TK_ESPACOS  */
  YYSYMBOL_TK_FIM = 30,                    /* TK_FIM  */
  YYSYMBOL_TK_ERROR = 31,                  /* TK_ERROR  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '>'  */
  YYSYMBOL_37_ = 37,                       /* '<'  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '='  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_S = 45,                         /* S  */
  YYSYMBOL_BLOCO = 46,                     /* BLOCO  */
  YYSYMBOL_NEWBLOCO = 47,                  /* NEWBLOCO  */
  YYSYMBOL_INICIO = 48,                    /* INICIO  */
  YYSYMBOL_FIM = 49,                       /* FIM  */
  YYSYMBOL_COMANDOS = 50,                  /* COMANDOS  */
  YYSYMBOL_COMANDO = 51,                   /* COMANDO  */
  YYSYMBOL_IMP = 52,                       /* IMP  */
  YYSYMBOL_COISAS = 53,                    /* COISAS  */
  YYSYMBOL_E = 54                          /* E  */
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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  85

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,    34,    32,     2,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      37,    43,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   123,   123,   132,   141,   150,   163,   169,   176,   181,
     182,   183,   187,   188,   211,   228,   245,   262,   281,   288,
     289,   298,   334,   371,   420,   459,   504,   550,   594,   638,
     683,   729,   766,   803,   853,   869,   885,   901,   920,   937,
     956,   980
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_INT", "TK_FLOAT",
  "TK_CHAR", "TK_STRING", "TK_BOOLEAN", "TK_MAIN", "TK_ID", "TK_TIPO_INT",
  "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_STRING", "TK_TIPO_BOOLEAN",
  "TK_OPERADORES", "TK_CONV_FLOAT", "TK_CONV_INT", "TK_AND", "TK_OR",
  "TK_REL_IGUALD", "TK_REL_MAIOR", "TK_REL_MENOR", "TK_REL_DIF", "TK_IF",
  "TK_ELSE", "TK_FOR", "TK_WHILE", "TK_COUT", "TK_ESPACOS", "TK_FIM",
  "TK_ERROR", "'+'", "'-'", "'*'", "'/'", "'>'", "'<'", "'('", "')'",
  "'{'", "'}'", "';'", "'='", "$accept", "S", "BLOCO", "NEWBLOCO",
  "INICIO", "FIM", "COMANDOS", "COMANDO", "IMP", "COISAS", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,    36,    46,    12,   -31,    30,    11,   -31,   -31,    21,
     -31,   -31,   -31,   -31,   -31,    15,    50,    51,    61,    62,
      63,    70,    37,    47,   -31,   -31,    33,    21,   -31,    20,
     182,    41,    49,    52,    53,    55,   -31,   182,   182,    21,
     -31,   -31,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   -31,    87,   -31,   -31,   -31,   -31,
     -31,    45,    67,   -31,   143,   139,   -19,   -12,   -17,    69,
      93,   113,   113,   119,   143,   147,    11,   182,    56,    76,
     -31,    67,   -31,   -31,   -31
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     5,     2,     8,
      36,    37,    38,    39,    40,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     5,    10,     0,     8,    12,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     8,
       3,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,    33,    13,    14,    15,    17,
      16,     0,    19,     6,    32,    31,    27,    29,    30,    28,
      23,    24,    21,    22,    25,    26,     0,     0,     0,     0,
      11,    19,    18,     4,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,    17,   -31,    94,   -31,     9,   -31,   -31,    44,
     -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,    25,     9,    79,    26,    27,    28,    78,
      29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      55,    44,    45,    46,    47,    46,    47,    61,    62,    45,
      46,    47,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    10,    11,    12,    13,    14,     1,
      15,    16,    17,    18,    19,    20,    41,    21,    42,    43,
      44,    45,    46,    47,     3,    22,     4,    81,    63,    23,
       5,     7,    48,    49,    50,    51,    52,    53,    30,    31,
      32,    24,    54,    42,    43,    44,    45,    46,    47,     6,
      33,    34,    35,    36,    40,    37,    38,    48,    49,    50,
      51,    52,    53,    56,    76,    42,    43,    44,    45,    46,
      47,    57,    47,    80,    58,    59,    77,    60,    82,    48,
      49,    50,    51,    52,    53,    42,    43,    44,    45,    46,
      47,    42,    43,    44,    45,    46,    47,    83,    39,    48,
      49,    50,    51,    52,    53,    84,    49,    50,    51,    52,
      53,    42,    43,    44,    45,    46,    47,    42,    43,    44,
      45,    46,    47,     0,     0,     0,     0,    50,    51,    52,
      53,     0,     0,     0,    51,    52,    53,    42,     0,    44,
      45,    46,    47,    44,    45,    46,    47,    44,    45,    46,
      47,     0,     0,     0,     0,    52,    53,     0,     0,    52,
      53,     0,     0,     0,    53,    10,    11,    12,    13,    14,
       0,    15,     0,     0,     0,     0,     0,     0,    21
};

static const yytype_int8 yycheck[] =
{
      30,    20,    21,    22,    23,    22,    23,    37,    38,    21,
      22,    23,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     3,     4,     5,     6,     7,    10,
       9,    10,    11,    12,    13,    14,    27,    16,    18,    19,
      20,    21,    22,    23,     8,    24,     0,    77,    39,    28,
      38,    40,    32,    33,    34,    35,    36,    37,    43,     9,
       9,    40,    42,    18,    19,    20,    21,    22,    23,    39,
       9,     9,     9,     3,    41,    38,    29,    32,    33,    34,
      35,    36,    37,    42,    39,    18,    19,    20,    21,    22,
      23,    42,    23,    76,    42,    42,    29,    42,    42,    32,
      33,    34,    35,    36,    37,    18,    19,    20,    21,    22,
      23,    18,    19,    20,    21,    22,    23,    41,    24,    32,
      33,    34,    35,    36,    37,    81,    33,    34,    35,    36,
      37,    18,    19,    20,    21,    22,    23,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    -1,    -1,    -1,    35,    36,    37,    18,    -1,    20,
      21,    22,    23,    20,    21,    22,    23,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    36,
      37,    -1,    -1,    -1,    37,     3,     4,     5,     6,     7,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    45,     8,     0,    38,    39,    40,    46,    48,
       3,     4,     5,     6,     7,     9,    10,    11,    12,    13,
      14,    16,    24,    28,    40,    47,    50,    51,    52,    54,
      43,     9,     9,     9,     9,     9,     3,    38,    29,    48,
      41,    50,    18,    19,    20,    21,    22,    23,    32,    33,
      34,    35,    36,    37,    42,    54,    42,    42,    42,    42,
      42,    54,    54,    50,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    39,    29,    53,    49,
      46,    54,    42,    41,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    47,    48,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     5,     0,     0,     2,     0,     2,
       1,     5,     1,     3,     3,     3,     3,     3,     5,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     1,     1,     1,
       1,     1
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
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
  case 2: /* S: TK_TIPO_INT TK_MAIN '(' ')' BLOCO  */
#line 124 "sintatica.y"
                        {
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << endl; 
				printVals();
				cout << yyvsp[0].traducao << "\t\n	return 0;\n}" << endl; 	
				
				}
#line 1379 "y.tab.c"
    break;

  case 3: /* BLOCO: '{' INICIO COMANDOS '}'  */
#line 133 "sintatica.y"
                        {
		
				yyval.traducao = yyvsp[-1].traducao;
				
				
			
			}
#line 1391 "y.tab.c"
    break;

  case 4: /* NEWBLOCO: '{' INICIO COMANDOS FIM '}'  */
#line 142 "sintatica.y"
                        {
		
				yyval.traducao = yyvsp[-2].traducao;
				
				
			
			}
#line 1403 "y.tab.c"
    break;

  case 5: /* INICIO: %empty  */
#line 150 "sintatica.y"
                 {
				std::list<TIPO_SIMBOLO> newTabela;
				TIPO_SIMBOLO teste;
				if(!pilha_de_simbolos.empty())
				{
					escopo++;
				}
			
				pilha_de_simbolos.push_back(newTabela);
				
				

			}
#line 1421 "y.tab.c"
    break;

  case 6: /* FIM: %empty  */
#line 163 "sintatica.y"
                 {
				
				pilha_de_simbolos.pop_back();
				
			}
#line 1431 "y.tab.c"
    break;

  case 7: /* COMANDOS: COMANDO COMANDOS  */
#line 170 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;

				
			}
#line 1441 "y.tab.c"
    break;

  case 8: /* COMANDOS: %empty  */
#line 176 "sintatica.y"
                        {
				yyval.traducao = "";
			}
#line 1449 "y.tab.c"
    break;

  case 11: /* COMANDO: TK_IF '(' E ')' BLOCO  */
#line 184 "sintatica.y"
                        {

			}
#line 1457 "y.tab.c"
    break;

  case 13: /* COMANDO: TK_TIPO_INT TK_ID ';'  */
#line 189 "sintatica.y"
                        {
				cout << "Teste de escopo" << endl;
				for (const std::list<TIPO_SIMBOLO>& lista : pilha_de_simbolos) {
					for (const TIPO_SIMBOLO& index : lista) {
						cout <<"llllllll" << endl;
						cout << yyvsp[-1].label << endl;
						if(index.nomeVal == yyvsp[-1].label){
							yyerror("Variavel já declarada (TK_TIPO_INT)");
						}
					}
				}
				cout << "Fim do teste de escopo" << endl;
				TIPO_SIMBOLO valor;
				valor.nomeVal = yyvsp[-1].label;
				valor.tempName = genLabel();
				valor.tipoVal = "int";
				

				yyval.traducao = "";
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 1483 "y.tab.c"
    break;

  case 14: /* COMANDO: TK_TIPO_FLOAT TK_ID ';'  */
#line 212 "sintatica.y"
                        {
				for(const TIPO_SIMBOLO& index : pilha_de_simbolos[escopo]){
					
					if(index.nomeVal == yyvsp[-1].label){
						yyerror("Variavel já declarada (TK_TIPO_FLOAT)");
					}
				}

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyvsp[-1].label;
				valor.tempName = genLabel();
				valor.tipoVal = "float";

				yyval.traducao = "";
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 1504 "y.tab.c"
    break;

  case 15: /* COMANDO: TK_TIPO_CHAR TK_ID ';'  */
#line 229 "sintatica.y"
                        {
				for(const TIPO_SIMBOLO& index : pilha_de_simbolos[escopo]){
					
					if(index.nomeVal == yyvsp[-1].label){
						yyerror("Variavel já declarada (TK_TIPO_CHAR)");
					}
				}

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyvsp[-1].label;
				valor.tempName = genLabel();
				valor.tipoVal = "char";

				yyval.traducao = "";
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 1525 "y.tab.c"
    break;

  case 16: /* COMANDO: TK_TIPO_BOOLEAN TK_ID ';'  */
#line 246 "sintatica.y"
                        {
				for(const TIPO_SIMBOLO& index : pilha_de_simbolos[escopo]){
					
					if(index.nomeVal == yyvsp[-1].label){
						yyerror("Variavel já declarada (TK_TIPO_BOOLEAN)");
					}
				}

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyvsp[-1].label;
				valor.tempName = genLabel();
				valor.tipoVal = "bool";

				yyval.traducao = "";
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 1546 "y.tab.c"
    break;

  case 17: /* COMANDO: TK_TIPO_STRING TK_ID ';'  */
#line 263 "sintatica.y"
                        {
				for(const TIPO_SIMBOLO& index : pilha_de_simbolos[escopo]){
					
					if(index.nomeVal == yyvsp[-1].label){
						yyerror("Variavel já declarada (TK_TIPO_STRING)");
					}
				}

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyvsp[-1].label;
				valor.tempName = genLabel();
				valor.tipoVal = "string";
			

				yyval.traducao = "";
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 1568 "y.tab.c"
    break;

  case 18: /* IMP: TK_COUT TK_ESPACOS E COISAS ';'  */
#line 282 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-2].traducao +"\tcout << " + yyvsp[-2].label + ";\n" + yyvsp[-1].traducao ;
				cout << yyvsp[-1].tipo << endl;
				
			}
#line 1578 "y.tab.c"
    break;

  case 20: /* COISAS: TK_ESPACOS E COISAS  */
#line 290 "sintatica.y"
                        {

				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao + "\tcout << " + yyvsp[-1].label + ";\n";
				
				
			}
#line 1589 "y.tab.c"
    break;

  case 21: /* E: E '*' E  */
#line 299 "sintatica.y"
                        {
				int convTest = 0;
				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						convTest = 1;

					}
					else if(yyvsp[0].tipo == "float" && yyvsp[-2].tipo == "int"){
						yyvsp[-2].tipo = "float";
						convTest = 2;
					}
					else{yyerror("Variaveis de tipos diferentes (Operação '*')");}
				}

				yyval.tipo = yyvsp[0].tipo;
				string label = genLabel();
				if(convTest == 1){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ yyvsp[-2].label +" * " + "(float)" +yyvsp[0].label + ";\n";
				}
				else if(convTest == 2){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ "(float)" + yyvsp[-2].label +" * "+yyvsp[0].label + ";\n";
				}
				else{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = " + yyvsp[-2].label +" * "+yyvsp[0].label + ";\n";
				}
				yyval.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = yyval.tipo;

				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 1629 "y.tab.c"
    break;

  case 22: /* E: E '/' E  */
#line 335 "sintatica.y"
                        {
				int convTest = 0;
				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						convTest = 1;

					}
					else if(yyvsp[0].tipo == "float" && yyvsp[-2].tipo == "int"){
						yyvsp[-2].tipo = "float";
						convTest = 2;
					}
					else{yyerror("Variaveis de tipos diferentes (Operação '/')");}
				}

				
				yyval.tipo = yyvsp[0].tipo;
				string label = genLabel();
				if(convTest == 1){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ yyvsp[-2].label +" / " + "(float)" +yyvsp[0].label + ";\n";
				}
				else if(convTest == 2){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ "(float)" + yyvsp[-2].label +" / "+yyvsp[0].label + ";\n";
				}
				else{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = " + yyvsp[-2].label +" / "+yyvsp[0].label + ";\n";
				}
				yyval.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = yyval.tipo;

				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 1670 "y.tab.c"
    break;

  case 23: /* E: E '+' E  */
#line 372 "sintatica.y"
                        {
				int convTest = 0;
				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						convTest = 1;

					}
					else if(yyvsp[0].tipo == "float" && yyvsp[-2].tipo == "int"){
						yyvsp[-2].tipo = "float";
						convTest = 2;
					}
					else{yyerror("Variaveis de tipos diferentes (Operação '+')");}
				}

				
				yyval.tipo = yyvsp[0].tipo;
				string label = genLabel();
				if(convTest == 1){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ yyvsp[-2].label +" + " + "(float)" +yyvsp[0].label + ";\n";
				}
				else if(convTest == 2){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ "(float)" + yyvsp[-2].label +" + "+yyvsp[0].label + ";\n";
				}
				else{
					if(yyvsp[-2].tipo == "string")
					{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\tstrcat(" + yyvsp[-2].label +","+yyvsp[0].label + ");\n"+"\tstrcpy("+label+","+yyvsp[-2].label+");\n";
					}
					else
					{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = " + yyvsp[-2].label +" + "+yyvsp[0].label + ";\n";
					}
					
				}
				yyval.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = yyval.tipo;
				yyval.tamanhoTemp = yyvsp[-2].tamanhoTemp + yyvsp[0].tamanhoTemp - 1;
				
				valor.tamanho = yyval.tamanhoTemp;

				
				pilha_de_simbolos[escopo].push_back(valor);
				
			}
#line 1723 "y.tab.c"
    break;

  case 24: /* E: E '-' E  */
#line 421 "sintatica.y"
                        {
				int convTest = 0;
				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						convTest = 1;

					}
					else if(yyvsp[0].tipo == "float" && yyvsp[-2].tipo == "int"){
						yyvsp[-2].tipo = "float";
						convTest = 2;
					}
					else{yyerror("Variaveis de tipos diferentes (Operação '-')");}
				}

				
				yyval.tipo = yyvsp[0].tipo;
				string label = genLabel();
				if(convTest == 1){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ yyvsp[-2].label +" - "+ "(float)" +yyvsp[0].label + ";\n";
				}
				else if(convTest == 2){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ "(float)" + yyvsp[-2].label +" - "+yyvsp[0].label + ";\n";
				}
				else{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = " + yyvsp[-2].label +" - "+yyvsp[0].label + ";\n";
				}
				yyval.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = yyval.tipo;

				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 1764 "y.tab.c"
    break;

  case 25: /* E: E '>' E  */
#line 460 "sintatica.y"
                        {
				
				int convTest = 0;
				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						convTest = 1;

					}
					else if(yyvsp[0].tipo == "float" && yyvsp[-2].tipo == "int"){
						yyvsp[-2].tipo = "float";
						convTest = 2;
					}
					else{
						yyerror("Variaveis de tipos diferentes, que nao suportao convercao (Operação '>')");
					}
				}

				
				string label = genLabel();
				
				if(convTest == 1){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ yyvsp[-2].label +" > "+ "(float)" +yyvsp[0].label + ";\n";
				}
				else if(convTest == 2){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ "(float)" + yyvsp[-2].label +" > "+yyvsp[0].label + ";\n";
				}
				else{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = " + yyvsp[-2].label +" > "+yyvsp[0].label + ";\n";
				}

				yyval.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = yyval.tipo;
				yyval.tipo = "bool";

				cout << valor.nomeVal << endl;
				cout << valor.tipoVal << endl;
				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 1812 "y.tab.c"
    break;

  case 26: /* E: E '<' E  */
#line 505 "sintatica.y"
                        {
				int convTest = 0;
				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						convTest = 1;

					}
					else if(yyvsp[0].tipo == "float" && yyvsp[-2].tipo == "int"){
						yyvsp[-2].tipo = "float";
						convTest = 2;
					}
					else{
						yyerror("Variaveis de tipos diferentes, que nao suportao convercao (Operação '<')");
					}
				}

				
	
				string label = genLabel();
				
				if(convTest == 1){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ yyvsp[-2].label +" < "+ "(float)" +yyvsp[0].label + ";\n";
				}
				else if(convTest == 2){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ "(float)" + yyvsp[-2].label +" < "+yyvsp[0].label + ";\n";
				}
				else{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = " + yyvsp[-2].label +" < "+yyvsp[0].label + ";\n";
				}

				yyval.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = yyval.tipo;
				yyval.tipo = "bool";

				cout << valor.nomeVal << endl;
				cout << valor.tipoVal << endl;
				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 1860 "y.tab.c"
    break;

  case 27: /* E: E TK_REL_IGUALD E  */
#line 551 "sintatica.y"
                        {
				int convTest = 0;
				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						convTest = 1;

					}
					else if(yyvsp[0].tipo == "float" && yyvsp[-2].tipo == "int"){
						yyvsp[-2].tipo = "float";
						convTest = 2;
					}
					else{
						yyerror("Variaveis de tipos diferentes, que nao suportao convercao (Operação '==')");
					}
				}

				
			
				string label = genLabel();
				
				if(convTest == 1){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ yyvsp[-2].label +" == "+ "(float)" +yyvsp[0].label + ";\n";
				}
				else if(convTest == 2){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ "(float)" + yyvsp[-2].label +" == "+yyvsp[0].label + ";\n";
				}
				else{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = " + yyvsp[-2].label +" == "+yyvsp[0].label + ";\n";
				}

				yyval.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = yyval.tipo;
				yyval.tipo = "bool";

				cout << valor.nomeVal << endl;
				cout << valor.tipoVal << endl;
				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 1908 "y.tab.c"
    break;

  case 28: /* E: E TK_REL_DIF E  */
#line 595 "sintatica.y"
                        {
				int convTest = 0;
				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						convTest = 1;

					}
					else if(yyvsp[0].tipo == "float" && yyvsp[-2].tipo == "int"){
						yyvsp[-2].tipo = "float";
						convTest = 2;
					}
					else{
						yyerror("Variaveis de tipos diferentes, que nao suportao convercao (Operação '!=')");
					}
				}

				
				
				string label = genLabel();
				
				if(convTest == 1){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ yyvsp[-2].label +" != "+ "(float)" +yyvsp[0].label + ";\n";
				}
				else if(convTest == 2){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ "(float)" + yyvsp[-2].label +" != "+yyvsp[0].label + ";\n";
				}
				else{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = " + yyvsp[-2].label +" != "+yyvsp[0].label + ";\n";
				}

				yyval.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = yyval.tipo;
				yyval.tipo = "bool";

				cout << valor.nomeVal << endl;
				cout << valor.tipoVal << endl;
				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 1956 "y.tab.c"
    break;

  case 29: /* E: E TK_REL_MAIOR E  */
#line 639 "sintatica.y"
                        {
				int convTest = 0;
				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						convTest = 1;

					}
					else if(yyvsp[0].tipo == "float" && yyvsp[-2].tipo == "int"){
						yyvsp[-2].tipo = "float";
						convTest = 2;
					}
					else{
						yyerror("Variaveis de tipos diferentes, que nao suportao convercao (Operação '>=')");
					}
				}

				
			
				string label = genLabel();
				
				if(convTest == 1){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ yyvsp[-2].label +" >= "+ "(float)" +yyvsp[0].label + ";\n";
				}
				else if(convTest == 2){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ "(float)" + yyvsp[-2].label +" >= "+yyvsp[0].label + ";\n";
				}
				else{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = " + yyvsp[-2].label +" >= "+yyvsp[0].label + ";\n";
				}

				yyval.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = yyval.tipo;
				yyval.tipo = "bool";
				

				cout << valor.nomeVal << endl;
				cout << valor.tipoVal << endl;
				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 2005 "y.tab.c"
    break;

  case 30: /* E: E TK_REL_MENOR E  */
#line 684 "sintatica.y"
                        {
				int convTest = 0;
				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						convTest = 1;

					}
					else if(yyvsp[0].tipo == "float" && yyvsp[-2].tipo == "int"){
						yyvsp[-2].tipo = "float";
						convTest = 2;
					}
					else{
						yyerror("Variaveis de tipos diferentes, que nao suportao convercao (Operação '<=')");
					}
				}

				
				
				string label = genLabel();
				
				if(convTest == 1){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ yyvsp[-2].label +" <= "+ "(float)" +yyvsp[0].label + ";\n";
				}
				else if(convTest == 2){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ "(float)" + yyvsp[-2].label +" <= "+yyvsp[0].label + ";\n";
				}
				else{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = " + yyvsp[-2].label +" <= "+yyvsp[0].label + ";\n";
				}

				yyval.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = yyval.tipo;
				yyval.tipo = "bool";

				cout << valor.nomeVal << endl;
				cout << valor.tipoVal << endl;
				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 2053 "y.tab.c"
    break;

  case 31: /* E: E TK_OR E  */
#line 730 "sintatica.y"
                        {
				int convTest = 0;
				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						convTest = 1;

					}
					else if(yyvsp[0].tipo == "float" && yyvsp[-2].tipo == "int"){
						yyvsp[-2].tipo = "float";
						convTest = 2;
					}
					else{yyerror("Variaveis de tipos diferentes (Operação '||')");}
				}
				
		
				string label = genLabel();
				if(convTest == 1){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ yyvsp[-2].label +" || " + "(float)" +yyvsp[0].label + ";\n";
				}
				else if(convTest == 2){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ "(float)" + yyvsp[-2].label +" || "+yyvsp[0].label + ";\n";
				}
				else{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = " + yyvsp[-2].label +" || "+yyvsp[0].label + ";\n";
				}
				yyval.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = yyval.tipo;

				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 2093 "y.tab.c"
    break;

  case 32: /* E: E TK_AND E  */
#line 767 "sintatica.y"
                        {
				int convTest = 0;
				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						convTest = 1;

					}
					else if(yyvsp[0].tipo == "float" && yyvsp[-2].tipo == "int"){
						yyvsp[-2].tipo = "float";
						convTest = 2;
					}
					else{yyerror("Variaveis de tipos diferentes (Operação '&&')");}
				}

				
				
				string label = genLabel();
				if(convTest == 1){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ yyvsp[-2].label +" && " + "(float)" +yyvsp[0].label + ";\n";
				}
				else if(convTest == 2){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = "+ "(float)" + yyvsp[-2].label +" && "+yyvsp[0].label + ";\n";
				}
				else{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + label +" = " + yyvsp[-2].label +" && "+yyvsp[0].label + ";\n";
				}
				yyval.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = yyval.tipo;

			}
#line 2132 "y.tab.c"
    break;

  case 33: /* E: TK_ID '=' E  */
#line 804 "sintatica.y"
                        {
				bool missing = false;
				TIPO_SIMBOLO val;
				
				
				for (const std::list<TIPO_SIMBOLO>& lista : pilha_de_simbolos) {
					for (const TIPO_SIMBOLO& index : lista) {
						if(index.nomeVal == yyval.label){
						val = index;
						missing = true;

						}
					}
				}
				if(!missing){
					yyerror("Variavel não declarada");
				}
				yyvsp[-2].label = val.tempName;
				yyvsp[-2].tipo = val.tipoVal;
				yyvsp[-2].tamanhoTemp = yyvsp[0].tamanhoTemp;
				
				cout << yyvsp[-2].tipo << endl;
				cout << val.tempName << endl;
				cout << yyvsp[0].tipo << endl;


				if(yyvsp[-2].tipo != yyvsp[0].tipo){
					if(yyval.tipo == "float" && yyvsp[0].tipo == "int"){
						yyvsp[0].tipo = "float";
						yyval.traducao =  yyvsp[0].traducao + "\t"+ yyval.label + " = " + "(float)" +yyvsp[0].label + ";\n";
					}
					else{
						yyerror("Variaveis de tipos diferentes (Operação '=') ");
					}
				}
				else
				{
					if(yyvsp[-2].tipo == "string" && yyvsp[0].tipo == "string")
					{
						yyval.traducao =  yyvsp[0].traducao + "\t"+ "strcpy("+yyvsp[-2].label+"," + yyvsp[0].label +")"  + ";\n";
					}
					else
					{
						yyval.traducao =  yyvsp[0].traducao + "\t"+ yyvsp[-2].label + " = " + yyvsp[0].label + ";\n";
					}
					
				}
				
			}
#line 2186 "y.tab.c"
    break;

  case 34: /* E: TK_CONV_FLOAT TK_INT  */
#line 854 "sintatica.y"
                        {
				yyval.tipo = "float";
				string label = genLabel();
				yyval.traducao = "\t" +label+ " = "  + "(float)" + yyvsp[0].traducao + ";\n";
				yyval.label = label;

				/*coloca na lista a temporaria*/

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = "float";

				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 2206 "y.tab.c"
    break;

  case 35: /* E: TK_CONV_FLOAT TK_INT  */
#line 870 "sintatica.y"
                        {
				yyval.tipo = "int";
				string label = genLabel();
				yyval.traducao = "\t" +label+ " = "  + "(int)" + yyvsp[0].traducao + ";\n";
				yyval.label = label;

				/*coloca na lista a temporaria*/

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = "int";

				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 2226 "y.tab.c"
    break;

  case 36: /* E: TK_INT  */
#line 886 "sintatica.y"
                        {
				yyval.tipo = "int";
				string label = genLabel();
				yyval.traducao = "\t"+label+ " = "  + yyvsp[0].traducao + ";\n";
				yyval.label = label;

				/*coloca na lista a temporaria*/

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = "int";

				
				pilha_de_simbolos[escopo].push_back(valor);
			}
#line 2246 "y.tab.c"
    break;

  case 37: /* E: TK_FLOAT  */
#line 902 "sintatica.y"
                        {
				yyval.tipo = "float";
				string label = genLabel();
				yyval.traducao = "\t"+label+ " = "  + yyvsp[0].traducao + ";\n";
				yyval.label = label;

				/*coloca na lista a temporaria*/

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = "float";

				
				pilha_de_simbolos[escopo].push_back(valor);

		

			}
#line 2269 "y.tab.c"
    break;

  case 38: /* E: TK_CHAR  */
#line 921 "sintatica.y"
                        {
				yyval.tipo = "char";
				string label = genLabel();
				yyval.traducao = "\t" +label+ " = "  + yyvsp[0].traducao + ";\n";
				yyval.label = label;

				/*coloca na lista a temporaria*/

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = "char";

				
				pilha_de_simbolos[escopo].push_back(valor);

			}
#line 2290 "y.tab.c"
    break;

  case 39: /* E: TK_STRING  */
#line 938 "sintatica.y"
                        {
				yyval.tipo = "string";
				string label = genLabel();
				yyval.traducao = "\tstrcpy(" +label+ ","  + yyvsp[0].traducao+")" + ";\n";
				yyval.label = label;
			

				TIPO_SIMBOLO valor;
				valor.nomeVal = yyval.label;
				valor.tipoVal = "string";
				yyvsp[0].tamanhoTemp = yyvsp[0].traducao.size()-1;
				cout << yyvsp[0].traducao << endl;
				yyval.tamanhoTemp = yyvsp[0].tamanhoTemp;
				valor.tamanho = yyvsp[0].tamanhoTemp;
				
				pilha_de_simbolos[escopo].push_back(valor);
	
			}
#line 2313 "y.tab.c"
    break;

  case 40: /* E: TK_BOOLEAN  */
#line 957 "sintatica.y"
                        {
				yyval.tipo = "bool";
				string label = genLabel();

				if(yyvsp[0].traducao == "true"){
					yyvsp[0].traducao = "1";
				}
				else{
					yyvsp[0].traducao = "0";
				}
				yyval.traducao = "\t" +label+ " = "  + yyvsp[0].traducao + ";\n";
				yyval.label = label;

				TIPO_SIMBOLO valor;

				valor.nomeVal = yyval.label;
				valor.tipoVal = "bool";

				
				pilha_de_simbolos[escopo].push_back(valor);
	
			}
#line 2340 "y.tab.c"
    break;

  case 41: /* E: TK_ID  */
#line 981 "sintatica.y"
                        {
				bool missing = false;
				TIPO_SIMBOLO val;
				
				for (const std::list<TIPO_SIMBOLO>& lista : pilha_de_simbolos) {
					for (const TIPO_SIMBOLO& index : lista) {
						if(index.nomeVal == yyval.label){
						val = index;
						missing = true;

						}
					}
				}
				if(!missing){
					yyerror("Variavel não declarada");
				}
				yyval.label = val.tempName;
				yyval.tipo = val.tipoVal;
				yyvsp[0].label = val.tempName;
				
				
				yyval.traducao = "";
			}
#line 2368 "y.tab.c"
    break;


#line 2372 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1006 "sintatica.y"


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	
	yyparse();
	
	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				
