#pragma once

#include "../ast_def.h"

#include <memory>
#include <unordered_map>
#include <vector>

enum class SER_TYPE { INT, FLOAT, CSTRING, ERROR };

struct sem_context;

struct simple_expression_result {
  union {
    long ival;
    float fval;
    const char *cstring;
  };

  SER_TYPE type;

  simple_expression_result() : ival(0), type(SER_TYPE::ERROR) {}
  simple_expression_result(long val) : ival(val), type(SER_TYPE::INT) {}
  simple_expression_result(float val) : fval(val), type(SER_TYPE::FLOAT) {}
  simple_expression_result(const char *val) : cstring(val), type(SER_TYPE::CSTRING) {}

  [[nodiscard("expression result lost")]] simple_expression_result operator-() const;

  [[nodiscard("expression result lost")]] simple_expression_result
  operator+(const simple_expression_result &right) const;

  [[nodiscard("expression result lost")]] simple_expression_result
  operator-(const simple_expression_result &right) const;

  [[nodiscard("expression result lost")]] simple_expression_result
  operator*(const simple_expression_result &right) const;

  [[nodiscard("expression result lost")]] simple_expression_result
  operator/(const simple_expression_result &right) const;

  [[nodiscard("expression result lost")]] simple_expression_result
  operator%(const simple_expression_result &right) const;
};

simple_expression_result calculate_constexpr(sem_expression *expr, sem_context &ctx);

class simple_symbol {
  bool is_global_;
  bool is_constexpr_;
  size_t idx_;
  const std::list<sem_expression *> *dimensions_;
  const sem_init_list *init_list_;

public:
  simple_symbol(bool is_constexpr, size_t idx, const std::list<sem_expression *> *dimensions,
                const sem_init_list *init_list, bool is_global = false);

  bool is_constexpr() const;
  bool is_global() const;
  size_t idx() const;
  const sem_init_list *init_list() const;

  [[nodiscard("expression result lost")]] simple_expression_result
  get_value(const std::list<sem_expression *> *dimensions, sem_context &ctx) const;
};

class sem_symbol_table {
  size_t sym_idx_;
  std::unordered_map<std::string, simple_symbol> sym_map_;
  sem_symbol_table *father_;
  std::vector<std::unique_ptr<sem_symbol_table>> children_;

  simple_symbol *find_symbol(const char *, sem_symbol_table *father);
  const simple_symbol *find_symbol(const char *, sem_symbol_table *father) const;

public:
  sem_symbol_table();

  sem_symbol_table(sem_symbol_table *father);

  sem_symbol_table *father() const;

  [[nodiscard("child pointer lost")]] sem_symbol_table *make_child();

  simple_symbol *find_symbol(const char *name);
  const simple_symbol *find_symbol(const char *name) const;

  void add_symbol(bool is_constexpr, const char *name, const std::list<sem_expression *> *dimensions,
                  const sem_init_list *init_list);

  [[nodiscard("left value lost")]] simple_expression_result
  get_left_value(sem_identifier *identifier, const std::list<sem_expression *> *dimensions, sem_context &ctx) const;

  void print(std::ostream &os) const;
};

struct sem_context {
  sem_symbol_table *symtbl;

  void enter_block();

  void exit_block();
};