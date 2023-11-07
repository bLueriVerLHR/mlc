%{
#include <iostream>

#include "parser.h"
#include "lexer.h"

int yyerror(YYLTYPE *yylloc, yyscan_t scanner, const char *msg) {
  (void)scanner;
  fprintf(stderr,"line %d, column %d: Error: %s\n", yylloc->first_line, yylloc->first_column, msg);
  return 0;
}

%}

%code requires {
#include <list>
#include "ast_def.h"

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void *yyscan_t;
#endif

}

%output "parser.cpp"
%defines "parser.h"

%define api.pure full
%define parse.error verbose
%locations
%lex-param { yyscan_t scanner }
%parse-param { yyscan_t scanner }

%union {
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
}


%token <constant> LEX_CONSTANT
%token <identifier> LEX_IDENTIFIER

// type specifiers
%token LEX_INT LEX_FLOAT LEX_VOID

// type qualifiers
%token LEX_CONST

// punctuator
%token LEX_GEQ LEX_LEQ LEX_LAND LEX_LOR LEX_EQU LEX_NEQ

// program structure
%token LEX_IF LEX_ELSE LEX_WHILE LEX_BREAK LEX_CONTINUE LEX_RETURN

%type <type_qualifier> type_qualifier
%type <type_specifier> type_specifier

%type <identifier> identifier
%type <constant> constant
%type <init_list> initializer initializer_list
%type <left_value> left_value

%type <block> translation_unit block block_items
%type <operation> statement

%type <expression> expression condition
  lor_expression land_expression
  equ_expression rel_expression
  add_expression mul_expression
  unary_expression primary_expression

%type <declaration>  variable_definition declarator
%type <param_declaration> function_fake_param param_declarator
%type <function_definition> function_definition

%type <declarations> variable_definitions declaration
%type <param_declarations> function_fake_params
%type <expressions> function_real_params

%start top_scope

%%

top_scope:
  translation_unit
  {
    sem_ast = $1;
  }
  ;

translation_unit:
    declaration
  {
    $$ = new sem_region;
    std::list<sem_declaration *> &decls = *$1;
    for (sem_declaration *&decl : decls) {
      decl->set_is_global();
      $$->add_operation(decl);
      decl = nullptr;
    }
    delete $1;
  }
  | translation_unit declaration
  {
    $$ = $1;
    std::list<sem_declaration *> &decls = *$2;
    for (sem_declaration *&decl : decls) {
      decl->set_is_global();
      $$->add_operation(decl);
      decl = nullptr;
    }
    delete $2;
  }
  | function_definition
  {
    $$ = new sem_region;
    $$->add_operation($1);
  }
  | translation_unit function_definition
  {
    $$ = $1;
    $$->add_operation($2);
  }
  ;

declaration:
    type_qualifier type_specifier variable_definitions ';'
  {
    $$ = $3;
    std::list<sem_declaration *> &decls = *$$;
    for (sem_declaration *decl : decls) {
      decl->set_type_info($1, $2);
    }
  }
  ;

variable_definitions:
    variable_definition
  {
    $$ = new std::list<sem_declaration *>;
    $$->push_back($1);
  }
  | variable_definitions ',' variable_definition
  {
    $$ = $1;
    $$->push_back($3);
  }
  ;

variable_definition:
    declarator '=' initializer
  {
    $$ = $1;
    $1->set_init_list($3);
  }
  | declarator
  {
    $$ = $1;
  }
  ;

declarator:
    declarator '[' expression ']'
  {
    $$->add_dimension($3);
  }
  | identifier
  {
    $$ = new sem_declaration($1);
  }
  ;

param_declarator:
    param_declarator '[' expression ']'
  {
    $$->add_dimension($3);
  }
  | identifier '[' ']'
  {
    $$ = new sem_param_declaration($1);
    $$->set_is_pointer();
  }
  | identifier
  {
    $$ = new sem_param_declaration($1);
  }
  ;

initializer:
    '{' '}'
  {
    $$ = new sem_init_list();
  }
  | expression
  {
    $$ = new sem_init_list($1);
  }
  | '{' initializer_list '}'
  {
    $$ = $2;
  }
  | '{' initializer_list ',' '}'
  {
    $$ = $2;
  }
  ;

initializer_list:
    initializer
  {
    $$ = new sem_init_list($1);
  }
  | initializer_list ',' initializer
  {
    $$->add_init_list($3);
  }
  ;

function_definition:
    type_qualifier type_specifier identifier '(' function_fake_params ')' block
  {
    $$ = new sem_function_definition($1, $2, $3, $5, $7);
  }
  | type_qualifier type_specifier identifier '(' ')' block
  {
    $$ = new sem_function_definition($1, $2, $3, nullptr, $6);
  }
  ;

function_fake_params:
    function_fake_param
  {
    $$ = new std::list<sem_param_declaration *>;
    $$->push_back($1);
  }
  | function_fake_params ',' function_fake_param
  {
    $$ = $1;
    $$->push_back($3);
  }
  ;

function_fake_param:
    type_qualifier type_specifier param_declarator
  {
    $$ = $3;
    $$->set_type_info($1, $2);
  }
  ;

block:
    '{' block_items '}'
  {
    $$ = $2;
  }
  | '{' '}'
  {
    $$ = new sem_region;
  }
  ;

block_items:
    statement
  {
    $$ = new sem_region;
    $$->add_operation($1);
  }
  | block_items statement
  {
    $$ = $1;
    $$->add_operation($2);
  }
  | declaration
  {
    $$ = new sem_region;
    std::list<sem_declaration *> &decls = *$1;
    for (sem_declaration *&decl : decls) {
      $$->add_operation(decl);
      decl = nullptr;
    }
    delete $1;
  }
  | block_items declaration
  {
    $$ = $1;
    std::list<sem_declaration *> &decls = *$2;
    for (sem_declaration *&decl : decls) {
      $$->add_operation(decl);
      decl = nullptr;
    }
    delete $2;
  }
  ;

statement:
    ';'
  {
    $$ = nullptr;
  }
  | expression ';'
  {
    $$ = $1;
  }
  | left_value '=' expression ';'
  {
    $$ = new sem_assignment($1, $3);
  }
  | block
  {
    $$ = new sem_plain_block($1);
  }
  | LEX_IF '(' condition ')' statement
  {
    $$ = new sem_branch($3, $5);
  }
  | LEX_IF '(' condition ')' statement LEX_ELSE statement
  {
    $$ = new sem_branch($3, $5, $7);
  }
  | LEX_WHILE '(' condition ')' statement
  {
    $$ = new sem_loop($3, $5);
  }
  | LEX_BREAK ';'
  {
    $$ = new sem_break;
  }
  | LEX_CONTINUE ';'
  {
    $$ = new sem_continue;
  }
  | LEX_RETURN ';'
  {
    $$ = new sem_return;
  }
  | LEX_RETURN expression ';'
  {
    $$ = new sem_return($2);
  }
  ;

condition:
    lor_expression
  {
    $$ = $1;
  }
  ;

expression:
    add_expression
  {
    $$ = $1;
  }
  ;

lor_expression:
    land_expression
  {
    $$ = $1;
  }
  | lor_expression LEX_LOR land_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::LOR, $1, $3);
  }
  ;

land_expression:
    equ_expression
  {
    $$ = $1;
  }
  | land_expression LEX_LAND equ_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::LAND, $1, $3);
  }
  ;

equ_expression:
    rel_expression
  {
    $$ = $1;
  }
  | equ_expression LEX_EQU rel_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::EQU, $1, $3);
  }
  | equ_expression LEX_NEQ rel_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::NEQ, $1, $3);
  }
  ;

rel_expression:
    add_expression
  {
    $$ = $1;
  }
  | rel_expression LEX_GEQ add_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::GEQ, $1, $3);
  }
  | rel_expression LEX_LEQ add_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::LEQ, $1, $3);
  }
  | rel_expression '>' add_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::GTH, $1, $3);
  }
  | rel_expression '<' add_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::LTH, $1, $3);
  }
  ;

add_expression:
    mul_expression
  {
    $$ = $1;
  }
  | add_expression '+' mul_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::ADD, $1, $3);
  }
  | add_expression '-' mul_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::SUB, $1, $3);
  }
  ;

mul_expression:
    unary_expression
  {
    $$ = $1;
  }
  | unary_expression '*' mul_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::MUL, $1, $3);
  }
  | unary_expression '/' mul_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::DIV, $1, $3);
  }
  | unary_expression '%' mul_expression
  {
    $$ = new sem_arith_binary(SEM_ARITH_BINARY::MOD, $1, $3);
  }
  ;

unary_expression:
    primary_expression
  {
    $$ = $1;
  }
  | identifier '(' function_real_params ')'
  {
    $$ = new sem_function_call($1, $3);
  }
  | '+' unary_expression
  {
    $$ = $2;
  }
  | '-' unary_expression
  {
    $$ = new sem_arith_unary(SEM_ARITH_UNARY::NEG, $2);
  }
  | '!' unary_expression
  {
    $$ = new sem_arith_unary(SEM_ARITH_UNARY::LNOT, $2);
  }
  ;

primary_expression:
    '(' expression ')'
  {
    $$ = $2;
  }
  | left_value
  {
    $$ = new sem_arith_left_value($1);
  }
  | constant
  {
    $$ = new sem_arith_constant($1);
  }
  ;

left_value:
    identifier
  {
    $$ = new sem_left_value($1);
  }
  | left_value '[' expression ']'
  {
    $$ = $1;
    $$->add_dimension($3);
  }
  ;

function_real_params:
    expression
  {
    $$ = new std::list<sem_expression *>;
  }
  | function_real_params ',' expression
  {
    $$ = $1;
    $$->push_back($3);
  }
  ;

type_specifier:
    LEX_INT
  {
    $$ = SEM_TYPE_SPECIFIER::INT;
  }
  | LEX_FLOAT
  {
    $$ = SEM_TYPE_SPECIFIER::FLOAT;
  }
  | LEX_VOID
  {
    $$ = SEM_TYPE_SPECIFIER::VOID;
  }
  ;

type_qualifier:
    %empty
  {
    $$ = SEM_TYPE_QUALIFIER::UNDEFINED;
  }
  | LEX_CONST
  {
    $$ = SEM_TYPE_QUALIFIER::CONST;
  }
  ;

constant:
    LEX_CONSTANT
  {
    $$ = $1;
  }
  ;

identifier:
    LEX_IDENTIFIER
  {
    $$ = $1;
  }
  ;

%%