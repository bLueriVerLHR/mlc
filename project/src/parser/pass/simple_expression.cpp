#include "pass.h"

simple_expression_result simple_expression_result::operator-() const {
  switch (type) {
  case SER_TYPE::ERROR:
  case SER_TYPE::CSTRING:
    return simple_expression_result();

  case SER_TYPE::FLOAT:
    return simple_expression_result(-fval);

  case SER_TYPE::INT:
    return simple_expression_result(-ival);
  }

  return simple_expression_result();
}

simple_expression_result simple_expression_result::operator+(const simple_expression_result &right) const {
  switch (right.type) {
  case SER_TYPE::ERROR:
  case SER_TYPE::CSTRING:
    return simple_expression_result();

  default:
    break;
  }

  switch (type) {
  case SER_TYPE::ERROR:
  case SER_TYPE::CSTRING:
    return simple_expression_result();

  case SER_TYPE::FLOAT:
    if (right.type == SER_TYPE::INT) {
      return simple_expression_result(fval + ival);
    } else if (right.type == SER_TYPE::FLOAT) {
      return simple_expression_result(fval + fval);
    }
    break;

  case SER_TYPE::INT:
    if (right.type == SER_TYPE::INT) {
      return simple_expression_result(ival + ival);
    } else if (right.type == SER_TYPE::FLOAT) {
      return simple_expression_result(ival + fval);
    }
    break;
  }

  return simple_expression_result();
}

simple_expression_result simple_expression_result::operator-(const simple_expression_result &right) const {
  switch (right.type) {
  case SER_TYPE::ERROR:
  case SER_TYPE::CSTRING:
    return simple_expression_result();

  default:
    break;
  }

  switch (type) {
  case SER_TYPE::ERROR:
  case SER_TYPE::CSTRING:
    return simple_expression_result();

  case SER_TYPE::FLOAT:
    if (right.type == SER_TYPE::INT) {
      return simple_expression_result(fval - ival);
    } else if (right.type == SER_TYPE::FLOAT) {
      return simple_expression_result(fval - fval);
    }
    break;

  case SER_TYPE::INT:
    if (right.type == SER_TYPE::INT) {
      return simple_expression_result(ival - ival);
    } else if (right.type == SER_TYPE::FLOAT) {
      return simple_expression_result(ival - fval);
    }
    break;
  }

  return simple_expression_result();
}

simple_expression_result simple_expression_result::operator*(const simple_expression_result &right) const {
  switch (right.type) {
  case SER_TYPE::ERROR:
  case SER_TYPE::CSTRING:
    return simple_expression_result();

  default:
    break;
  }

  switch (type) {
  case SER_TYPE::ERROR:
  case SER_TYPE::CSTRING:
    return simple_expression_result();

  case SER_TYPE::FLOAT:
    if (right.type == SER_TYPE::INT) {
      return simple_expression_result(fval * ival);
    } else if (right.type == SER_TYPE::FLOAT) {
      return simple_expression_result(fval * fval);
    }
    break;

  case SER_TYPE::INT:
    if (right.type == SER_TYPE::INT) {
      return simple_expression_result(ival * ival);
    } else if (right.type == SER_TYPE::FLOAT) {
      return simple_expression_result(ival * fval);
    }
    break;
  }

  return simple_expression_result();
}

simple_expression_result simple_expression_result::operator/(const simple_expression_result &right) const {
  switch (right.type) {
  case SER_TYPE::ERROR:
  case SER_TYPE::CSTRING:
    return simple_expression_result();

  default:
    break;
  }

  switch (type) {
  case SER_TYPE::ERROR:
  case SER_TYPE::CSTRING:
    return simple_expression_result();

  case SER_TYPE::FLOAT:
    if (right.type == SER_TYPE::INT) {
      return simple_expression_result(fval / ival);
    } else if (right.type == SER_TYPE::FLOAT) {
      return simple_expression_result(fval / fval);
    }
    break;

  case SER_TYPE::INT:
    if (right.type == SER_TYPE::INT) {
      return simple_expression_result(ival / ival);
    } else if (right.type == SER_TYPE::FLOAT) {
      return simple_expression_result(ival / fval);
    }
    break;
  }

  return simple_expression_result();
}

simple_expression_result simple_expression_result::operator%(const simple_expression_result &right) const {
  if (type == SER_TYPE::INT and right.type == SER_TYPE::INT) {
    return simple_expression_result(ival % ival);
  }
  return simple_expression_result();
}

simple_expression_result calculate_constexpr(sem_expression *expr, sem_context &ctx) {
  if (sem_arith_binary *bin = dynamic_cast<sem_arith_binary *>(expr); bin != nullptr) {
    switch (bin->type()) {
    case SEM_ARITH_BINARY::ADD:
      return calculate_constexpr(bin->left(), ctx) + calculate_constexpr(bin->right(), ctx);
    case SEM_ARITH_BINARY::SUB:
      return calculate_constexpr(bin->left(), ctx) - calculate_constexpr(bin->right(), ctx);
    case SEM_ARITH_BINARY::MUL:
      return calculate_constexpr(bin->left(), ctx) * calculate_constexpr(bin->right(), ctx);
    case SEM_ARITH_BINARY::DIV:
      return calculate_constexpr(bin->left(), ctx) / calculate_constexpr(bin->right(), ctx);
    case SEM_ARITH_BINARY::MOD:
      return calculate_constexpr(bin->left(), ctx) % calculate_constexpr(bin->right(), ctx);
    default:
      break;
    }
    return simple_expression_result();
  }

  if (sem_arith_constant *cstexpr = dynamic_cast<sem_arith_constant *>(expr); cstexpr != nullptr) {
    switch (cstexpr->type()) {
    case SEM_CONSTANT_TYPE::OCTAL_INTEGER:
    case SEM_CONSTANT_TYPE::DECIMAL_INTEGER:
    case SEM_CONSTANT_TYPE::HEXADECIMAL_INTEGER: {
      unsigned long long value = std::any_cast<unsigned long long>(cstexpr->value());
      if (value > unsigned(INT32_MAX) + 1) {
        return simple_expression_result();
      }
      return simple_expression_result(long(value));
    } break;

    case SEM_CONSTANT_TYPE::DECIMAL_FLOAT:
    case SEM_CONSTANT_TYPE::HEXADECIMAL_FLOAT: {
      double value = std::any_cast<double>(cstexpr->value());
      return simple_expression_result(float(value));
    } break;

    case SEM_CONSTANT_TYPE::CSTRING: {
      const char *value = std::any_cast<const char *>(cstexpr->value());
      return simple_expression_result(value);
    } break;

    default:
      break;
    }

    return simple_expression_result();
  }

  if (sem_arith_unary *unary = dynamic_cast<sem_arith_unary *>(expr); unary != nullptr) {
    switch (unary->type()) {
    case SEM_ARITH_UNARY::NEG:
      return -calculate_constexpr(unary->expression(), ctx);
    default:
      break;
    }
    return simple_expression_result();
  }

  if (sem_arith_left_value *lvalexpr = dynamic_cast<sem_arith_left_value *>(expr); lvalexpr != nullptr) {
    sem_left_value *lval = lvalexpr->left_value();

    sem_identifier *ident = lval->identifier();
    const std::list<sem_expression *> *dims = lval->dimensions();

    return ctx.symtbl->get_left_value(ident, dims, ctx);
  }

  return simple_expression_result();
}