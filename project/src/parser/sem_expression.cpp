#include "ast_def.h"

sem_arith_constant::sem_arith_constant(sem_constant *constant) : constant_(constant) {}

sem_arith_constant::~sem_arith_constant() {
  if (constant_ != nullptr) {
    delete constant_;
    constant_ = nullptr;
  }
}

std::string sem_arith_constant::to_string() const { return constant_->to_string(); }