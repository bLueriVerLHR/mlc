#include "ast_def.h"

#include <cerrno>
#include <cstring>
#include <sstream>

#define CHECK_ERRNO()                                                                                                  \
  do {                                                                                                                 \
    if (errno != 0) {                                                                                                  \
      perror("error when parsing constant");                                                                           \
      type_ = SEM_CONSTANT_TYPE::ERROR;                                                                                \
      break;                                                                                                           \
    }                                                                                                                  \
  } while (0)

sem_constant::sem_constant(SEM_CONSTANT_TYPE type) : value_(), type_(type) {
  switch (type_) {
  case SEM_CONSTANT_TYPE::OCTAL_INTEGER:
  case SEM_CONSTANT_TYPE::DECIMAL_INTEGER:
  case SEM_CONSTANT_TYPE::HEXADECIMAL_INTEGER: {
    value_ = 0ull;
  } break;

  case SEM_CONSTANT_TYPE::DECIMAL_FLOAT:
  case SEM_CONSTANT_TYPE::HEXADECIMAL_FLOAT: {
    value_ = double(0.0);
  } break;

  case SEM_CONSTANT_TYPE::CSTRING: {
    value_ = nullptr;
  } break;

  default:
    break;
  }
}

sem_constant::sem_constant(const char *text, SEM_CONSTANT_TYPE type) : value_(), type_(type) {
  switch (type_) {
  case SEM_CONSTANT_TYPE::OCTAL_INTEGER: {
    char *endp = nullptr;
    const unsigned long long value = std::strtoull(text, &endp, 8);
    CHECK_ERRNO();
    value_ = value;
  } break;

  case SEM_CONSTANT_TYPE::DECIMAL_INTEGER: {
    char *endp = nullptr;
    const unsigned long long value = std::strtoull(text, &endp, 10);
    CHECK_ERRNO();
    value_ = value;
  } break;

  case SEM_CONSTANT_TYPE::DECIMAL_FLOAT: {
    char *endp = nullptr;
    const double value = std::strtod(text, &endp);
    CHECK_ERRNO();
    value_ = value;
  } break;

  case SEM_CONSTANT_TYPE::HEXADECIMAL_INTEGER: {
    char *endp = nullptr;
    const unsigned long long value = std::strtoull(text, &endp, 16);
    CHECK_ERRNO();
    value_ = value;
  } break;

  case SEM_CONSTANT_TYPE::HEXADECIMAL_FLOAT: {
    char *endp = nullptr;
    const double value = std::strtod(text, &endp);
    CHECK_ERRNO();
    value_ = value;
  } break;

  case SEM_CONSTANT_TYPE::CSTRING: {
    value_ = strdup(text);
  } break;

  default:
    break;
  }
}

sem_constant::~sem_constant() {
  if (type_ == SEM_CONSTANT_TYPE::CSTRING) {
    const char *str = std::any_cast<const char *>(value_);
    free((void *)str);
  }
}

SEM_CONSTANT_TYPE sem_constant::type() const { return type_; }

const std::any &sem_constant::value() const { return value_; }

std::string sem_constant::to_string() const {
  switch (type_) {
  case SEM_CONSTANT_TYPE::OCTAL_INTEGER:
  case SEM_CONSTANT_TYPE::DECIMAL_INTEGER:
  case SEM_CONSTANT_TYPE::HEXADECIMAL_INTEGER: {
    return std::to_string(std::any_cast<unsigned long long>(value_));
  } break;

  case SEM_CONSTANT_TYPE::DECIMAL_FLOAT:
  case SEM_CONSTANT_TYPE::HEXADECIMAL_FLOAT: {
    return std::to_string(std::any_cast<double>(value_));
  } break;

  case SEM_CONSTANT_TYPE::CSTRING: {
    return std::string(std::any_cast<const char *>(value_));
  } break;

  default:
    break;
  }

  return std::string("<error>");
}