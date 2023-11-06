#include "ast_def.h"

void sem_block::add_operation(sem_operation *operation) {
  if (operation == nullptr)
    return;
  operations_.push_back(operation);
}

sem_block::~sem_block() {
  for (sem_operation *&operation : operations_) {
    if (operation == nullptr)
      continue;

    delete operation;
    operation = nullptr;
  }
}

std::string sem_block::to_string() const {
  static size_t block_print_indent = 0;

  block_print_indent += 1;
  std::string indent = "\n";
  for (size_t i = 0; i < block_print_indent; ++i) {
    indent += " ";
  }

  std::string out = "{";
  for (sem_operation *const &operation : operations_) {
    out += indent + operation->to_string();
  }
  block_print_indent -= 1;
  indent.pop_back();
  out += indent + "}";

  return out;
}