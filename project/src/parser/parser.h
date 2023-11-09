/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 19 "parser.y"

#include <list>
#include "ast_def.h"

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void *yyscan_t;
#endif


#line 60 "parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LEX_CONSTANT = 258,            /* LEX_CONSTANT  */
    LEX_IDENTIFIER = 259,          /* LEX_IDENTIFIER  */
    LEX_INT = 260,                 /* LEX_INT  */
    LEX_FLOAT = 261,               /* LEX_FLOAT  */
    LEX_VOID = 262,                /* LEX_VOID  */
    LEX_CONST = 263,               /* LEX_CONST  */
    LEX_GEQ = 264,                 /* LEX_GEQ  */
    LEX_LEQ = 265,                 /* LEX_LEQ  */
    LEX_LAND = 266,                /* LEX_LAND  */
    LEX_LOR = 267,                 /* LEX_LOR  */
    LEX_EQU = 268,                 /* LEX_EQU  */
    LEX_NEQ = 269,                 /* LEX_NEQ  */
    LEX_IF = 270,                  /* LEX_IF  */
    LEX_ELSE = 271,                /* LEX_ELSE  */
    LEX_WHILE = 272,               /* LEX_WHILE  */
    LEX_BREAK = 273,               /* LEX_BREAK  */
    LEX_CONTINUE = 274,            /* LEX_CONTINUE  */
    LEX_RETURN = 275               /* LEX_RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "parser.y"

  SEM_TYPE_SPECIFIER type_specifier;
  SEM_TYPE_QUALIFIER type_qualifier;

  sem_constant *constant;
  sem_identifier *identifier;
  sem_init_list *init_list;
  sem_left_value *left_value;

  sem_region *block;
  sem_operation *operation;
    sem_expression *expression;
    sem_declaration *declaration;
    sem_param_declaration *param_declaration;
    sem_function_definition *function_definition;

  std::list<sem_operation *> *operations;
  std::list<sem_expression *> *expressions;
  std::list<sem_declaration *> *declarations;
  std::list<sem_param_declaration *> *param_declarations;

#line 119 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse (yyscan_t scanner);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
