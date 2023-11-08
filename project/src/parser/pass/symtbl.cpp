#include "pass.h"

simple_expression_result simple_symbol_table::get_left_value(sem_identifier *identifier,
                                                             const std::list<sem_expression *> *dimensions,
                                                             sem_context &ctx) const {
  return simple_expression_result();
}
