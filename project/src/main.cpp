#include "parser.h"
#include "lexer.h"

#include <iostream>

sem_block *sem_ast;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 0;
  }
  char *buf = nullptr;
  size_t buflen = 0;

  FILE *fp = open_memstream(&buf, &buflen);
  FILE *infp = fopen(argv[1], "r");

  for (;;) {
    char inbuf[BUFSIZ];
    int rcnt = fread(inbuf, sizeof(char), BUFSIZ, infp);
    if (rcnt == 0)
      break;
    fwrite(inbuf, sizeof(char), BUFSIZ, fp);
  }

  fclose(fp);

  yyscan_t scanner;
  if (yylex_init(&scanner) != 0) {
    exit(EXIT_FAILURE);
  }
  YY_BUFFER_STATE state = yy_scan_string(buf, scanner);
  if (yyparse(scanner) != 0) {
    exit(EXIT_FAILURE);
  }
  yy_delete_buffer(state, scanner);
  yylex_destroy(scanner);

  free(buf);

  std::cout << sem_ast->to_string() << std::endl;
  return 0;
}