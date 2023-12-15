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
  std::unique_ptr<sem_symbol_table> symtbl = std::make_unique<sem_symbol_table>();

  sem_context ctx;
  ctx.symtbl = symtbl.get();

  std::unique_ptr<symbol_tagging> tagger = std::make_unique<symbol_tagging>(&ctx);

  /**
   * 这样子生成的符号表树，可以拥有一个预留的 root，
   * 并将其他所有的翻译单元都作为 root 的孩子。
   *
   * 这样的设计下，拥有文件作用域的变量就会在 root 的孩子里，
   * 拥有全局作用域的变量就会在 root 中。
   *
   * 但是目前还没有真正意义上的全局作用域的变量，
   * 本语言本身仅有一个文件。
   */
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