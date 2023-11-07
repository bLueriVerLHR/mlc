#pragma once

#include <vector>

struct configurations {
  bool output_file{false};

  bool output_ast_tree{false};
  bool output_llvm_ir{false};
  bool output_asm_code{false};

  char *optimization_level{nullptr};

  char *output_file_path{nullptr};

  std::vector<char *> input_file_paths{};
};

struct optimization_flags {
  bool simple_inlining{false};
  bool tail_recursive_inlining{false};
  bool constant_folding{false};
};

extern configurations config;

extern optimization_flags optflgs;