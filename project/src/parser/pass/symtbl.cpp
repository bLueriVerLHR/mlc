#include "pass.h"

simple_symbol::simple_symbol(bool is_constexpr, size_t idx, sem_init_list *init_list)
    : is_constexpr_(is_constexpr), idx_(idx), init_list_(init_list) {}

bool simple_symbol::is_constexpr() const { return is_constexpr_; }

simple_expression_result simple_symbol::get_value(const std::list<sem_expression *> *dimensions) const {
  return simple_expression_result(0l);
}

simple_symbol_table::simple_symbol_table() : sym_idx_(1), sym_map_(), father_(nullptr), children_() {}

simple_symbol_table::simple_symbol_table(simple_symbol_table *father)
    : sym_idx_(1), sym_map_(), father_(father), children_() {}

simple_symbol_table *simple_symbol_table::father() const { return father_; }

simple_symbol_table *simple_symbol_table::make_child() {
  std::unique_ptr<simple_symbol_table> child = std::make_unique<simple_symbol_table>(this);
  if (child.get() == nullptr) {
    return nullptr;
  }

  children_.push_back(std::move(child));
  return children_.back().get();
}

simple_symbol *simple_symbol_table::find_symbol(const char *name, simple_symbol_table *father) {
  if (father == nullptr)
    return nullptr;

  std::unordered_map<std::string, simple_symbol>::iterator fnd{};
  if (fnd = father->sym_map_.find(name); fnd == father->sym_map_.end()) {
    return find_symbol(name, father->father_);
  }

  return &fnd->second;
}

simple_symbol *simple_symbol_table::find_symbol(const char *name) {
  std::unordered_map<std::string, simple_symbol>::iterator fnd{};
  if (fnd = sym_map_.find(name); fnd == sym_map_.end()) {
    return find_symbol(name, father_);
  }

  return &fnd->second;
}

const simple_symbol *simple_symbol_table::find_symbol(const char *name, simple_symbol_table *father) const {
  if (father == nullptr)
    return nullptr;

  std::unordered_map<std::string, simple_symbol>::const_iterator fnd{};
  if (fnd = father->sym_map_.find(name); fnd == father->sym_map_.end()) {
    return find_symbol(name, father->father_);
  }

  return &fnd->second;
}

const simple_symbol *simple_symbol_table::find_symbol(const char *name) const {
  std::unordered_map<std::string, simple_symbol>::const_iterator fnd{};
  if (fnd = sym_map_.find(name); fnd == sym_map_.end()) {
    return find_symbol(name, father_);
  }

  return &fnd->second;
}

simple_expression_result simple_symbol_table::get_left_value(sem_identifier *identifier,
                                                             const std::list<sem_expression *> *dimensions,
                                                             sem_context &ctx) const {
  const simple_symbol *sym = find_symbol(identifier->name());

  return sym->get_value(dimensions);
}
