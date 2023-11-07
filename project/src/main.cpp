#include "parser/sem_ast.h"
#include "config.h"

#include <getopt.h>
#include <unistd.h>

#include <cstdlib>
#include <cstdio>
#include <cstring>

configurations config;
optimization_flags optflgs;

[[noreturn]] static inline void usage(int status) {
  fprintf(stderr, "cr [ -o <path> ] <file | options>\n");
  exit(status);
}

static inline void parse_command_line_arguments(int argc, char **argv) {
  while (true) {
    int opt = getopt(argc, argv, "ho:O::S::");

    if (opt == -1) break;

    switch (opt) {
      case 'h':
        usage(0);

      case 'o':
        config.output_file = true;
        config.output_file_path = optarg;
        break;

      case 'O':
        config.optimization_level = optarg;
        break;

      case 'S': {
        if (optarg == nullptr)
          config.output_asm_code = true;

        else if (strcmp(optarg, "asm") == 0)
          config.output_asm_code = true;

        else if (strcmp(optarg, "llvm") == 0)
          config.output_llvm_ir = true;

        else if (strcmp(optarg, "ast") == 0)
          config.output_ast_tree = true;

        else
          fprintf(stderr, "illegel -S argument\n");
      } break;
    }
  }

  for (int idx = optind; idx < argc; ++idx)
    config.input_file_paths.push_back(argv[idx]);

  if (auto lvl = config.optimization_level; lvl == nullptr) {

  } else if (strcmp(lvl, "1") == 0) {
    optflgs.constant_folding = true;
    optflgs.simple_inlining = true;
    optflgs.tail_recursive_inlining = true;

  }

  if (config.input_file_paths.size() > 1 and config.output_file)
    fprintf(stderr, "cannot specify '-o' with multiple files\n");
}

int main(int argc, char **argv) {
  parse_command_line_arguments(argc, argv);

  if (int code = sem::prepare(); code != 0)
    exit(EXIT_FAILURE);

  for (const char *path : config.input_file_paths) {
    if (int code = sem::parse_file(path); code != 0)
      exit(EXIT_FAILURE);
  }

  sem::pass();

  if (int code = sem::destroy(); code != 0)
    exit(EXIT_FAILURE);

  return 0;
}