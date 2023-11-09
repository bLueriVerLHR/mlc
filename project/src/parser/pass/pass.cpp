#include <mlc/config.h>
#include <mlc/parser/sem_ast.h>

#include "pass.h"

#include <climits>
#include <fstream>
#include <string>

extern std::vector<sem_region *> ast_forest;

namespace sem {

void pass() {
  std::unique_ptr<simple_symbol_table> symtbl = std::make_unique<simple_symbol_table>();

  sem_context ctx;
  ctx.symtbl = symtbl.get();

  if (config.output_file and config.output_ast_tree) {
    std::fstream fs(config.output_file_path, std::ios::out);
    for (sem_region *region : ast_forest) {
      fs << region->to_string() << std::endl;
    }
  }
}

} // namespace sem