#include <mlc/config.h>
#include <mlc/parser/sem_ast.h>

#include "pass.h"
#include "tagging.h"

#include <climits>
#include <fstream>
#include <string>

extern std::vector<sem_region *> ast_forest;

namespace sem {

void pass() {
  std::unique_ptr<simple_symbol_table> symtbl = std::make_unique<simple_symbol_table>();

  sem_context ctx;
  ctx.symtbl = symtbl.get();

  std::unique_ptr<symbol_tagging> tagger = std::make_unique<symbol_tagging>(&ctx);

  for (sem_region *region : ast_forest) {
    tagger->visit(region);
  }

  if (config.output_file and config.output_ast_tree) {
    std::fstream fs(config.output_file_path, std::ios::out);
    for (sem_region *region : ast_forest) {
      fs << region->to_string() << std::endl;
    }

#ifndef NDEBUG
  // print symbol table information
  symtbl->print(fs);
#endif

  }
}

} // namespace sem