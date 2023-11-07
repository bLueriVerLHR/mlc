#include "ast_def.h"
#include "lexer.h"
#include "parser.h"
#include "parser/sem_ast.h"

#include <iostream>

sem_region *sem_ast;

static char *yybuf = nullptr;
static yyscan_t scanner = nullptr;

int prepare_sem_ast_generator() {
  if (int code = yylex_init(&scanner); code != 0) {
    fprintf(stderr, "scanner initialize failed, code : %d", code);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int parse_file(const char *file) {
  size_t buflen = 0;

  FILE *fp = open_memstream(&yybuf, &buflen);
  if (fp == nullptr) {
    fprintf(stderr, "%s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  FILE *infp = fopen(file, "r");
  if (infp == nullptr) {
    fprintf(stderr, "%s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  for (;;) {
    char tmp[BUFSIZ];
    int n = fread(tmp, sizeof(char), BUFSIZ, infp);
    if (n == 0) {
      fclose(infp);
      break;
    }
    fwrite(tmp, sizeof(char), BUFSIZ, fp);
  }

  fclose(fp);

  YY_BUFFER_STATE state = yy_scan_string(yybuf, scanner);
  if (yyparse(scanner) != 0)
    return EXIT_FAILURE;
  yy_delete_buffer(state, scanner);
  free(yybuf);

  std::cout << "top " << sem_ast->to_string() << std::endl;
  return EXIT_SUCCESS;
}

int destroy_sem_ast_generator() { return yylex_destroy(scanner); }