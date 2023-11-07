#include "../ast_def.h"
#include "parser/sem_ast.h"

#include <vector>

extern std::vector<sem_region *> ast_forest;

void calculate_dims();

namespace sem {

void pass() {}

} // namespace sem