#include "pass.h"

#include <iostream>

simple_symbol::simple_symbol(bool is_constexpr, size_t idx, const std::list<sem_expression *> *dimensions,
                             const sem_init_list *init_list, bool is_global)
    : is_global_(is_global), is_constexpr_(is_constexpr), idx_(idx), dimensions_(dimensions), init_list_(init_list) {}

bool simple_symbol::is_global() const { return is_global_; }

bool simple_symbol::is_constexpr() const { return is_constexpr_; }

size_t simple_symbol::idx() const { return idx_; }

const sem_init_list *simple_symbol::init_list() const { return init_list_; }

simple_expression_result simple_symbol::get_value(const std::list<sem_expression *> *dimensions, sem_context &ctx) const {
  if (is_constexpr_) {
    if (dimensions_ == nullptr) {
      if (dimensions != nullptr) {
        return simple_expression_result();
      }

      sem_expression *expr = init_list_->find_element(dimensions);

      if (expr != nullptr) {
        return calculate_constexpr(expr, ctx);
      }
    } else {
      if (dimensions == nullptr) {
        return simple_expression_result();
      }

      sem_expression *expr = init_list_->find_element(dimensions);

      if (expr != nullptr) {
        return calculate_constexpr(expr, ctx);
      }
    }
  }
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

void simple_symbol_table::add_symbol(bool is_constexpr, const char *name, const std::list<sem_expression *> *dimensions,
                                     const sem_init_list *init_list) {
  std::pair<std::unordered_map<std::string, simple_symbol>::iterator, bool> &&result = sym_map_.emplace(std::string(name), simple_symbol(is_constexpr, sym_idx_, dimensions, init_list));
  if (not result.second) {
    fprintf(stderr, "multiple definition\n");
    exit(EXIT_FAILURE);
  }
  sym_idx_ += 1;
}

simple_expression_result simple_symbol_table::get_left_value(sem_identifier *identifier,
                                                             const std::list<sem_expression *> *dimensions,
                                                             sem_context &ctx) const {
  const simple_symbol *sym = find_symbol(identifier->name());

  return sym->get_value(dimensions, ctx);
}

void simple_symbol_table::print(std::ostream &os) const {
  static size_t print_indent = 0;

  std::string indent("//");
  for (size_t i = 0; i < print_indent; ++i) {
    indent += " ";
  }
  indent += "- ";

  for (const std::pair<std::string, simple_symbol> &pair : sym_map_) {
    os << indent << pair.first << std::endl;
    os << indent << "  idx: " << pair.second.idx() << std::endl;

    std::string qualifiers;
    qualifiers += (pair.second.is_global() ? "global " : "");
    qualifiers += (pair.second.is_constexpr() ? "const " : "");
    os << indent << "  qualifier: " << qualifiers << std::endl;

    os << indent << "  value: " << pair.second.init_list()->to_string() << std::endl;
  }

  print_indent += 1;
  for (const std::unique_ptr<simple_symbol_table> &symtbl : children_) {
    symtbl->print(os);
  }
}