#include <mlc/parser/sem_ast.h>

#include "ast_def.h"
#include "lexer.h"
#include "parser.h"

#include <iostream>
#include <vector>

sem_region *sem_ast;

std::vector<sem_region *> ast_forest;

static yyscan_t scanner = nullptr;

namespace sem {

int prepare() {
  if (int code = yylex_init(&scanner); code != 0) {
    fprintf(stderr, "scanner initialize failed, code : %d", code);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int parse_file(const char *file) {
  FILE *fp = fopen(file, "r");
  YY_BUFFER_STATE state = yy_create_buffer(fp, YY_BUF_SIZE, scanner);
  yy_switch_to_buffer(state, scanner);

  if (yyparse(scanner) != 0)
    return EXIT_FAILURE;
  yy_delete_buffer(state, scanner);
  fclose(fp);

  ast_forest.push_back(sem_ast);
  sem_ast = nullptr;

  return EXIT_SUCCESS;
}

int destroy() {
  for (sem_region *&ast : ast_forest) {
    if (ast != nullptr) {
      delete ast;
      ast = nullptr;
    }
  }
  return yylex_destroy(scanner);
}

} // namespace sem
