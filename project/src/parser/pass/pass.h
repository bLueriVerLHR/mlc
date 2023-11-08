#pragma once

#include "../ast_def.h"

#include <memory>
#include <unordered_map>
#include <vector>

enum class SER_TYPE { INT, FLOAT, CSTRING, ERROR };

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

  simple_expression_result operator-() const;
  simple_expression_result operator+(const simple_expression_result &right) const;
  simple_expression_result operator-(const simple_expression_result &right) const;
  simple_expression_result operator*(const simple_expression_result &right) const;
  simple_expression_result operator/(const simple_expression_result &right) const;
  simple_expression_result operator%(const simple_expression_result &right) const;
};

class simple_symbol {};

struct sem_context;

class simple_symbol_table {
  size_t sym_idx_;
  std::unordered_map<std::string, simple_symbol> sym_map_;
  simple_symbol_table *father_;
  std::vector<std::unique_ptr<simple_symbol_table>> children_;

public:
  simple_expression_result get_left_value(sem_identifier *identifier, const std::list<sem_expression *> *dimensions,
                                          sem_context &ctx) const;
};

struct sem_context {
  simple_symbol_table symtbl;
};