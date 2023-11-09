#include <mlc/parser/sem_ast.h>

#include "pass.h"

#include <climits>
#include <string>

extern std::vector<sem_region *> ast_forest;

namespace sem {

void pass() {
  std::unique_ptr<simple_symbol_table> symtbl = std::make_unique<simple_symbol_table>();

  sem_context ctx;
  ctx.symtbl = symtbl.get();
}

} // namespace sem