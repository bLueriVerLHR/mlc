#pragma once

#include <any>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <list>
#include <sstream>

#include "ast_enums.h"

namespace sem {

class constant_value final {
  std::any value_;
  CONSTANT_TYPE type_;

public:
  constant_value(const char *cstring) : value_(cstring), type_(CONSTANT_TYPE::CSTRING) {}

  constant_value(long ival) : value_(ival), type_(CONSTANT_TYPE::DECIMAL_INTEGER) {}

  constant_value(float fval) : value_(fval), type_(CONSTANT_TYPE::DECIMAL_FLOAT) {}

  constant_value(CONSTANT_TYPE type) : value_(), type_(type) {
    switch (type_) {
    case CONSTANT_TYPE::OCTAL_INTEGER:
    case CONSTANT_TYPE::DECIMAL_INTEGER:
    case CONSTANT_TYPE::HEXADECIMAL_INTEGER: {
      value_ = 0ull;
    } break;

    case CONSTANT_TYPE::DECIMAL_FLOAT:
    case CONSTANT_TYPE::HEXADECIMAL_FLOAT: {
      value_ = double(0.0);
    } break;

    case CONSTANT_TYPE::CSTRING: {
      value_ = nullptr;
    } break;

    default:
      break;
    }
  }

  constant_value(const char *text, CONSTANT_TYPE type) : value_(), type_(type) {
    switch (type_) {
    case CONSTANT_TYPE::OCTAL_INTEGER: {
      char *endp = nullptr;
      const unsigned long long value = std::strtoull(text, &endp, 8);
      if (errno != 0) {
        perror("error when parsing constant");
        type_ = CONSTANT_TYPE::UNDEFINED;
        break;
      }
      value_ = value;
    } break;

    case CONSTANT_TYPE::DECIMAL_INTEGER: {
      char *endp = nullptr;
      const unsigned long long value = std::strtoull(text, &endp, 10);
      if (errno != 0) {
        perror("error when parsing constant");
        type_ = CONSTANT_TYPE::UNDEFINED;
        break;
      }
      value_ = value;
    } break;

    case CONSTANT_TYPE::DECIMAL_FLOAT: {
      char *endp = nullptr;
      const double value = std::strtod(text, &endp);
      if (errno != 0) {
        perror("error when parsing constant");
        type_ = CONSTANT_TYPE::UNDEFINED;
        break;
      }
      value_ = value;
    } break;

    case CONSTANT_TYPE::HEXADECIMAL_INTEGER: {
      char *endp = nullptr;
      const unsigned long long value = std::strtoull(text, &endp, 16);
      if (errno != 0) {
        perror("error when parsing constant");
        type_ = CONSTANT_TYPE::UNDEFINED;
        break;
      }
      value_ = value;
    } break;

    case CONSTANT_TYPE::HEXADECIMAL_FLOAT: {
      char *endp = nullptr;
      const double value = std::strtod(text, &endp);
      if (errno != 0) {
        perror("error when parsing constant");
        type_ = CONSTANT_TYPE::UNDEFINED;
        break;
      }
      value_ = value;
    } break;

    case CONSTANT_TYPE::CSTRING: {
      value_ = strdup(text);
    } break;

    default:
      break;
    }
  }

  ~constant_value() {
    if (type_ == CONSTANT_TYPE::CSTRING) {
      const char *str = std::any_cast<const char *>(value_);
      free((void *)str);
    }
  }

  inline CONSTANT_TYPE type() const { return type_; }
  inline const std::any &value() const { return value_; }
};

class identifier final {
  const char *name_;

public:
  identifier(const char *text) : name_(strdup(text)) {}

  ~identifier() { free((void *)name_); }

  inline const char *name() const { return name_; }
};

class operation {
public:
  operation() = default;
  virtual ~operation() = default;
};

class region final {
  std::list<operation *> opers_;

public:
  region() = default;

  ~region() {
    for (operation *&oper : opers_) {
      if (oper == nullptr)
        continue;

      delete oper;
      oper = nullptr;
    }
  }

  inline void push_back(operation *oper) {
    if (oper == nullptr)
      return;
    opers_.push_back(oper);
  }

  inline const std::list<operation *> &operations() const { return opers_; }
};

class expression : public operation {
public:
  expression() = default;
  virtual ~expression() = default;
};

class initializer final {
  bool is_expr_;
  expression *expr_;
  std::list<initializer *> inits_;

public:
  initializer() : is_expr_(false), expr_(nullptr), inits_() {}

  initializer(expression *expr) : is_expr_(true), expr_(expr), inits_() {}

  initializer(initializer *init) : is_expr_(false), expr_(nullptr), inits_() { inits_.push_back(init); }

  ~initializer() {
    if (is_expr_ and expr_ != nullptr) {
      delete expr_;
      expr_ = nullptr;
    }

    for (initializer *&init : inits_) {
      if (init == nullptr)
        continue;

      delete init;
      init = nullptr;
    }
  }

  inline void push_back(initializer *init) { inits_.push_back(init); }
};

class declaration final : public operation {
  TYPE_QUALIFIER qual_;
  TYPE_SPECIFIER spec_;
  identifier *ident_;
  std::list<expression *> *dims_;
  initializer *init_;

public:
  declaration(identifier *ident) : ident_(ident) {}

  ~declaration() {
    if (ident_ != nullptr) {
      delete ident_;
      ident_ = nullptr;
    }
    if (dims_ != nullptr) {
      std::list<expression *> &vdim = *dims_;
      for (expression *&dim : vdim) {
        if (dim != nullptr) {
          delete dim;
          dim = nullptr;
        }
      }
      delete dims_;
      dims_ = nullptr;
    }
    if (init_ != nullptr) {
      delete init_;
      init_ = nullptr;
    }
  }

  void set_type_info(TYPE_QUALIFIER qualifier, TYPE_SPECIFIER specifier) {
    qual_ = qualifier;
    spec_ = specifier;
  }

  void set_init_list(initializer *init) { init_ = init; }

  void push_back(expression *expr) {
    if (dims_ == nullptr) {
      dims_ = new std::list<expression *>;
    }

    dims_->push_back(expr);
  }
};

} // namespace sem