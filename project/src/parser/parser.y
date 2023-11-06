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
  sem_constant *constant;
  sem_identifier *identifier;
  sem_operation *operation;
  sem_block *block;

  TYPE_SPECIFIER type_specifier;
  TYPE_QUALIFIER type_qualifier;

  sem_expression *expression;
  sem_declarator *declarator;
  sem_init_list *init_list;

  sem_function_definition *function_definition;
  sem_param_declarator *param_declarator;
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

%type <identifier> identifier
%type <constant> constant

%type <block> translation_unit variable_definitions function_fake_params block block_items
%type <operation> declaration function_definition block_item statement

%type <init_list> initializer initializer_list

%type <type_qualifier> type_qualifier
%type <type_specifier> type_specifier

%type <declarator> variable_definition declarator
%type <param_declarator> function_fake_param param_declarator

%type <expression> expression condition
  lor_expression land_expression
  equ_expression rel_expression
  add_expression mul_expression
  unary_expression primary_expression

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
    $$ = new sem_block;
    $$->add_operation($1);
  }
  | translation_unit declaration
  {
    $$ = $1;
    $$->add_operation($2);
  }
  | function_definition
  {
    $$ = new sem_block;
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
    $$ = new sem_declaration($1, $2, $3);
  }
  ;

function_definition:
    type_qualifier type_specifier identifier '(' function_fake_params ')' block
  {
    $$ = new sem_function_definition($1, $2, $3, $5, $7);
  }
  ;

function_fake_params:
    function_fake_param
  {
    $$ = new sem_block;
    $$->add_operation($1);
  }
  | function_fake_params ',' function_fake_param
  {
    $$ = $1;
    $$->add_operation($3);
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
  ;

block_items:
    block_item
  {
    $$ = new sem_block;
    $$->add_operation($1);
  }
  | block_items block_item
  {
    $$ = $1;
    $$->add_operation($2);
  }
  ;

block_item:
    declaration
  {
    $$ = $1;
  }
  | statement
  {
    $$ = $1;
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
  | block
  {
    $$ = new sem_simple_embedding($1);
  }
  | LEX_IF '(' condition ')' statement
  {

  }
  | LEX_IF '(' condition ')' statement LEX_ELSE statement
  {

  }
  | LEX_WHILE '(' condition ')' statement
  {

  }
  | LEX_BREAK ';'
  {

  }
  | LEX_CONTINUE ';'
  {

  }
  | LEX_RETURN ';'
  {

  }
  | LEX_RETURN expression ';'
  {

  }
  ;

variable_definitions:
    variable_definition
  {
    $$ = new sem_block;
    $$->add_operation($1);
  }
  | variable_definitions ',' variable_definition
  {
    $$ = $1;
    $$->add_operation($3);
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
    $$ = new sem_declarator($1);
  }
  ;

param_declarator:
    param_declarator '[' expression ']'
  {
    $$->add_dimension($3);
  }
  | identifier '[' ']'
  {
    $$ = new sem_param_declarator($1);
    $$->set_is_pointer();
  }
  | identifier
  {
    $$ = new sem_param_declarator($1);
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

  }
  ;

land_expression:
    equ_expression
  {
    $$ = $1;
  }
  | land_expression LEX_LAND equ_expression
  ;

equ_expression:
    rel_expression
  {
    $$ = $1;
  }
  | equ_expression LEX_EQU rel_expression
  | equ_expression LEX_NEQ rel_expression
  ;

rel_expression:
    add_expression
  {
    $$ = $1;
  }
  | rel_expression LEX_GEQ add_expression
  | rel_expression LEX_LEQ add_expression
  | rel_expression '>' add_expression
  | rel_expression '<' add_expression
  ;

add_expression:
    mul_expression
  {
    $$ = $1;
  }
  | add_expression '+' mul_expression
  | add_expression '-' mul_expression
  ;

mul_expression:
    unary_expression
  {
    $$ = $1;
  }
  | unary_expression '*' mul_expression
  | unary_expression '/' mul_expression
  | unary_expression '%' mul_expression
  ;

unary_expression:
    primary_expression
  {
    $$ = $1;
  }
  | identifier '(' function_real_params ')'
  {
    $$ = nullptr;
  }
  | '+' unary_expression
  {
    $$ = $2;
  }
  | '-' unary_expression
  {
    $$ = nullptr;
  }
  | '!' unary_expression
  {
    $$ = nullptr;
  }
  ;

primary_expression:
    '(' expression ')'
  {
    $$ = $2;
  }
  | left_value
  | constant
  {
    $$ = new sem_expression($1);
  }
  ;

left_value:
    identifier
  | left_value '[' expression ']'
  ;

function_real_params:
    expression
  | function_real_params expression
  ;

type_specifier:
    LEX_INT
  {
    $$ = TYPE_SPECIFIER::INT;
  }
  | LEX_FLOAT
  {
    $$ = TYPE_SPECIFIER::FLOAT;
  }
  | LEX_VOID
  {
    $$ = TYPE_SPECIFIER::VOID;
  }
  ;

type_qualifier:
    %empty
  {
    $$ = TYPE_QUALIFIER::UNDEFINED;
  }
  | LEX_CONST
  {
    $$ = TYPE_QUALIFIER::CONST;
  }
  ;

constant:
    LEX_CONSTANT
  ;

identifier:
    LEX_IDENTIFIER
  ;

%%