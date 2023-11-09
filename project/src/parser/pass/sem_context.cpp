#include "pass.h"

void sem_context::enter_block() {
  simple_symbol_table *child = symtbl->make_child();
  if (child == nullptr) {
    fprintf(stderr, "make new symbol table failed\n");
    exit(EXIT_FAILURE);
  }

  symtbl = child;
}

void sem_context::exit_block() {
  symtbl = symtbl->father();

  if (symtbl == nullptr) {
    fprintf(stderr, "exit top symtbl\n");
    exit(EXIT_FAILURE);
  }
}