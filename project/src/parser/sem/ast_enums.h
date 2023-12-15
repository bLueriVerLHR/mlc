#pragma once

namespace sem {

enum class CONSTANT_TYPE {
  UNDEFINED = 0,
  OCTAL_INTEGER,
  DECIMAL_INTEGER,
  DECIMAL_FLOAT,
  HEXADECIMAL_INTEGER,
  HEXADECIMAL_FLOAT,
  CSTRING,
};

enum class TYPE_QUALIFIER {
  UNDEFINED = 0,
  CONST,
};

enum class TYPE_SPECIFIER {
  UNDEFINED = 0,
  INT,
  FLOAT,
  VOID,
};

enum class ARITH_BINARY {
  LOR,
  LAND,
  EQU,
  NEQ,
  GTH,
  LTH,
  GEQ,
  LEQ,
  ADD,
  SUB,
  MUL,
  DIV,
  MOD,
};

enum class ARITH_UNARY {
  LNOT,
  NEG,
};

} // namespace sem