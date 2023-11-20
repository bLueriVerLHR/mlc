#include <mlc/parser/sem_ast.h>

#include "ast_def.h"
#include "lexer.l.h"
#include "parser.y.h"

#include <iostream>
#include <vector>

sem_region *sem_ast;

std::vector<sem_region *> ast_forest;

static yyscan_t scanner = nullptr;

namespace sem {

int parse_file(const char *file) {
  if (int code = yylex_init(&scanner); code != 0) {
    fprintf(stderr, "scanner initialize failed, code : %d\n", code);
    return code;
  }

  FILE *fp = fopen(file, "r");
  YY_BUFFER_STATE state = yy_create_buffer(fp, YY_BUF_SIZE, scanner);
  yy_switch_to_buffer(state, scanner);

  yyset_extra((void *)file, scanner);
  if (int code = yyparse(scanner); code != 0)
    return code;

  yy_delete_buffer(state, scanner);
  fclose(fp);

  return yylex_destroy(scanner);
}

void destroy() {
  for (sem_region *&ast : ast_forest) {
    if (ast != nullptr) {
      delete ast;
      ast = nullptr;
    }
  }
}

} // namespace sem
