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