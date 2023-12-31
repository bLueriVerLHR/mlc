#include "ast_def.h"

sem_arith_constant::sem_arith_constant(sem_constant *constant) : constant_(constant) {}

sem_arith_constant::~sem_arith_constant() {
  if (constant_ != nullptr) {
    delete constant_;
    constant_ = nullptr;
  }
}

SEM_CONSTANT_TYPE sem_arith_constant::type() const { return constant_->type(); }

const std::any &sem_arith_constant::value() const { return constant_->value(); }

std::string sem_arith_constant::to_string() const { return constant_->to_string(); }

sem_arith_binary::sem_arith_binary(SEM_ARITH_BINARY type, sem_expression *left, sem_expression *right)
    : type_(type), left_(left), right_(right) {}

sem_arith_binary::~sem_arith_binary() {
  if (left_ != nullptr) {
    delete left_;
    left_ = nullptr;
  }
  if (right_ != nullptr) {
    delete right_;
    right_ = nullptr;
  }
}

SEM_ARITH_BINARY sem_arith_binary::type() const { return type_; }

sem_expression *sem_arith_binary::left() const { return left_; }

sem_expression *sem_arith_binary::right() const { return right_; }

std::string sem_arith_binary::to_string() const {
  std::string out = arith_to_cstring(type_);
  out += " " + left_->to_string() + " " + right_->to_string();
  out = "(" + out + ")";
  return out;
}

sem_arith_unary::sem_arith_unary(SEM_ARITH_UNARY type, sem_expression *expression)
    : type_(type), expression_(expression) {}

sem_arith_unary::~sem_arith_unary() {
  if (expression_ != nullptr) {
    delete expression_;
    expression_ = nullptr;
  }
}

SEM_ARITH_UNARY sem_arith_unary::type() const { return type_; }

sem_expression *sem_arith_unary::expression() const { return expression_; }

std::string sem_arith_unary::to_string() const {
  std::string out = arith_to_cstring(type_);
  out += " " + expression_->to_string();
  out = "(" + out + ")";
  return out;
}

sem_arith_left_value::sem_arith_left_value(sem_left_value *left_value) : left_value_(left_value) {}

sem_arith_left_value::~sem_arith_left_value() {
  if (left_value_ != nullptr) {
    delete left_value_;
    left_value_ = nullptr;
  }
}

sem_left_value *sem_arith_left_value::left_value() const { return left_value_; }

std::string sem_arith_left_value::to_string() const { return left_value_->to_string(); }

sem_function_call::sem_function_call(sem_identifier *identifier, std::list<sem_expression *> *real_param)
    : identifier_(identifier), real_param_(real_param) {}

sem_function_call::~sem_function_call() {
  if (identifier_ != nullptr) {
    delete identifier_;
    identifier_ = nullptr;
  }
  if (real_param_ != nullptr) {
    std::list<sem_expression *> &rparams = *real_param_;
    for (sem_expression *&param : rparams) {
      if (param != nullptr) {
        delete param;
        param = nullptr;
      }
    }
    delete real_param_;
    real_param_ = nullptr;
  }
}

std::string sem_function_call::to_string() const {
  std::string out = "func.call @" + identifier_->to_string();
  out += "(";
  if (real_param_ != nullptr and not real_param_->empty()) {
    std::list<sem_expression *>::iterator it = real_param_->begin();
    out += (*it)->to_string();
    for (++it; it != real_param_->end(); ++it) {
      out += ", " + (*it)->to_string();
    }
  }
  out += ")";
  return out;
}