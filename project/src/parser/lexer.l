%top{
#include "ast_def.h"
#include "parser.y.h"

#define YY_USER_ACTION do {                   \
  yylloc->first_column = yylloc->last_column; \
  yylloc->last_column += strlen(yytext);      \
} while (0);

#define YY_NEWLINE_ACTION do {                    \
  yylloc->first_line += 1;                        \
  yylloc->last_line += 1;                         \
  yylloc->first_column = yylloc->last_column = 1; \
} while (0);
}

%option outfile="lexer.l.cpp" header-file="lexer.l.h"
%option noinput nounput
%option reentrant noyywrap never-interactive nounistd
%option bison-bridge bison-locations
%option yylineno

%x COMMENT

oct     [0-7]
dec     [0-9]
nzero   [1-9]
hex     [a-fA-F0-9]
prehex  (0[xX])
ident1  [a-zA-Z_]
ident2  [a-zA-Z_0-9]
dexp    ([eE][+-]?{dec}+)
hexp    ([pP][+-]?{hex}+)
fsuf    [fFlL]
isuf    (([uU](l|L|ll|LL)?)|((l|L|ll|LL)[uU]?))
newline \r?\n
ws      [ \t\v\f]

%%

  /* float */

{dec}+{dexp}{fsuf}?                     { yylval->constant = new sem_constant(yytext, SEM_CONSTANT_TYPE::DECIMAL_FLOAT); return LEX_CONSTANT; }
{dec}*"."{dec}+{dexp}?{fsuf}?           { yylval->constant = new sem_constant(yytext, SEM_CONSTANT_TYPE::DECIMAL_FLOAT); return LEX_CONSTANT; }
{dec}+"."{dexp}?{fsuf}?                 { yylval->constant = new sem_constant(yytext, SEM_CONSTANT_TYPE::DECIMAL_FLOAT); return LEX_CONSTANT; }
{prehex}{hex}+"."?{hexp}{fsuf}?         { yylval->constant = new sem_constant(yytext, SEM_CONSTANT_TYPE::HEXADECIMAL_FLOAT); return LEX_CONSTANT; }
{prehex}{hex}*"."{hex}+{hexp}?{fsuf}?   { yylval->constant = new sem_constant(yytext, SEM_CONSTANT_TYPE::HEXADECIMAL_FLOAT); return LEX_CONSTANT; }

  /* integers */

0{oct}*{isuf}?                          { yylval->constant = new sem_constant(yytext, SEM_CONSTANT_TYPE::OCTAL_INTEGER); return LEX_CONSTANT; }
{nzero}{dec}*{isuf}?                    { yylval->constant = new sem_constant(yytext, SEM_CONSTANT_TYPE::DECIMAL_INTEGER); return LEX_CONSTANT; }
{prehex}{hex}+{isuf}?                   { yylval->constant = new sem_constant(yytext, SEM_CONSTANT_TYPE::HEXADECIMAL_INTEGER); return LEX_CONSTANT; }

  /* keywords */

"int"           { return LEX_INT; }
"float"         { return LEX_FLOAT; }
"void"          { return LEX_VOID; }
"const"         { return LEX_CONST; }
"if"            { return LEX_IF; }
"else"          { return LEX_ELSE; }
"while"         { return LEX_WHILE; }
"break"         { return LEX_BREAK; }
"continue"      { return LEX_CONTINUE; }
"return"        { return LEX_RETURN; }

  /* punctuator*/

">="                  { return LEX_GEQ; }
"<="                  { return LEX_LEQ; }
"&&"                  { return LEX_LAND; }
"||"                  { return LEX_LOR; }
"=="                  { return LEX_EQU; }
"!="                  { return LEX_NEQ; }

";"|","|"["|"]"|"{"|"}"|"("|")"|"+"|"-"|"*"|"/"|"%"|"!"|">"|"<"|"="    { return yytext[0]; }

  /* identifier */

{ident1}{ident2}*   { yylval->identifier = new sem_identifier(yytext); return LEX_IDENTIFIER; }

  /* comments */

"/*"                    { BEGIN(COMMENT); }
<COMMENT>"*/"           { BEGIN(INITIAL); }
<COMMENT><<EOF>>        { fprintf(stderr, "unclosed comment\n"); }
<COMMENT>{newline}      { YY_NEWLINE_ACTION }
<COMMENT>.              { }
"//".*{newline}         { YY_NEWLINE_ACTION }

  /* white space */

{newline}           { YY_NEWLINE_ACTION }
{ws}                { }
.                   { fprintf(stderr, "unexpected charactor: %s\n", yytext); }

%%