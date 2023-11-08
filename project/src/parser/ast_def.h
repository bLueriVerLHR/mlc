#pragma once

#include <any>
#include <list>
#include <string>

enum class SEM_CONSTANT_TYPE {
  OCTAL_INTEGER,
  DECIMAL_INTEGER,
  DECIMAL_FLOAT,
  HEXADECIMAL_INTEGER,
  HEXADECIMAL_FLOAT,
  CSTRING,
  ERROR,
};

enum class SEM_TYPE_QUALIFIER {
  UNDEFINED,
  CONST,
};

static inline const char *qualifier_to_cstring(SEM_TYPE_QUALIFIER qualifier) {
  switch (qualifier) {
  case SEM_TYPE_QUALIFIER::UNDEFINED:
    return "undefined";
  case SEM_TYPE_QUALIFIER::CONST:
    return "const";
  }
  return "unknow";
}

enum class SEM_TYPE_SPECIFIER {
  UNDEFINED,
  INT,
  FLOAT,
  VOID,
};

static inline const char *specifier_to_cstring(SEM_TYPE_SPECIFIER qualifier) {
  switch (qualifier) {
  case SEM_TYPE_SPECIFIER::UNDEFINED:
    return "undefined";
  case SEM_TYPE_SPECIFIER::INT:
    return "int";
  case SEM_TYPE_SPECIFIER::FLOAT:
    return "float";
  case SEM_TYPE_SPECIFIER::VOID:
    return "void";
  }
  return "unknow";
}

enum class SEM_ARITH_BINARY {
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

enum class SEM_ARITH_UNARY {
  LNOT,
  NEG,
};

static inline const char *arith_to_cstring(SEM_ARITH_BINARY type) {
  switch (type) {
  case SEM_ARITH_BINARY::LOR:
    return "logic.or";
  case SEM_ARITH_BINARY::LAND:
    return "logic.and";
  case SEM_ARITH_BINARY::EQU:
    return "comp.equ";
  case SEM_ARITH_BINARY::NEQ:
    return "comp.neq";
  case SEM_ARITH_BINARY::GTH:
    return "comp.gth";
  case SEM_ARITH_BINARY::LTH:
    return "comp.lth";
  case SEM_ARITH_BINARY::GEQ:
    return "comp.geq";
  case SEM_ARITH_BINARY::LEQ:
    return "comp.leq";
  case SEM_ARITH_BINARY::ADD:
    return "add";
  case SEM_ARITH_BINARY::SUB:
    return "sub";
  case SEM_ARITH_BINARY::MUL:
    return "mul";
  case SEM_ARITH_BINARY::DIV:
    return "div";
  case SEM_ARITH_BINARY::MOD:
    return "mod";
  }
  return "unknow";
}

static inline const char *arith_to_cstring(SEM_ARITH_UNARY type) {
  switch (type) {
  case SEM_ARITH_UNARY::LNOT:
    return "logic.not";
  case SEM_ARITH_UNARY::NEG:
    return "neg";
  }
  return "unknow";
}

class sem_constant {
  std::any value_;
  SEM_CONSTANT_TYPE type_;

public:
  sem_constant(SEM_CONSTANT_TYPE type);
  sem_constant(const char *text, SEM_CONSTANT_TYPE type);
  virtual ~sem_constant();

  SEM_CONSTANT_TYPE type() const;
  const std::any &value() const;

  std::string to_string() const;
};

class sem_identifier {
  const char *name_;

public:
  sem_identifier(const char *text);
  virtual ~sem_identifier();

  const char *name() const;

  std::string to_string() const;
};

class sem_operation {
public:
  sem_operation() = default;
  virtual ~sem_operation() = default;

  virtual std::string to_string() const = 0;
};

class sem_region {
  std::list<sem_operation *> operations_;

public:
  sem_region() = default;
  virtual ~sem_region();

  void add_operation(sem_operation *operation);

  std::string to_string() const;
};

class sem_expression : public sem_operation {
public:
  sem_expression() = default;
  virtual ~sem_expression() = default;

  std::string to_string() const = 0;
};

class sem_init_list {
  bool is_expression_;
  sem_expression *expression_;
  std::list<sem_init_list *> init_list_;

public:
  sem_init_list();
  sem_init_list(sem_expression *expression);
  sem_init_list(sem_init_list *init_list);
  virtual ~sem_init_list();

  void add_init_list(sem_init_list *init_list);

  std::string to_string() const;
};

class sem_declaration : public sem_operation {
  SEM_TYPE_QUALIFIER qualifier_;
  SEM_TYPE_SPECIFIER specifier_;
  sem_identifier *identifier_;
  std::list<sem_expression *> *dims_;
  sem_init_list *init_list_;

  bool is_global_;

public:
  sem_declaration(sem_identifier *identifier);
  virtual ~sem_declaration();

  void set_type_info(SEM_TYPE_QUALIFIER qualifier, SEM_TYPE_SPECIFIER specifier);
  void set_init_list(sem_init_list *init_list);
  void set_is_global();
  void add_dimension(sem_expression *expression);

  std::string to_string() const;
};

class sem_param_declaration {
  SEM_TYPE_QUALIFIER qualifier_;
  SEM_TYPE_SPECIFIER specifier_;
  sem_identifier *identifier_;
  std::list<sem_expression *> *dims_;

  bool is_pointer_;

public:
  sem_param_declaration(sem_identifier *identifier);
  virtual ~sem_param_declaration();

  void set_type_info(SEM_TYPE_QUALIFIER qualifier, SEM_TYPE_SPECIFIER specifier);
  void set_is_pointer();
  void add_dimension(sem_expression *expression);

  std::string to_string() const;
};

class sem_function_definition : public sem_operation {
  SEM_TYPE_QUALIFIER qualifier_;
  SEM_TYPE_SPECIFIER specifier_;
  sem_identifier *identifier_;
  std::list<sem_param_declaration *> *fake_params_;
  sem_region *body_;

public:
  sem_function_definition(SEM_TYPE_QUALIFIER qualifier, SEM_TYPE_SPECIFIER specifier, sem_identifier *identifier,
                          std::list<sem_param_declaration *> *fake_params, sem_region *body);
  virtual ~sem_function_definition();

  std::string to_string() const;
};

class sem_plain_block : public sem_operation {
  sem_region *block_;

public:
  sem_plain_block(sem_region *block_);
  virtual ~sem_plain_block();

  std::string to_string() const;
};

class sem_branch : public sem_operation {
  sem_expression *condition_;
  sem_operation *on_true_;
  sem_operation *on_false_;

public:
  sem_branch(sem_expression *condition, sem_operation *on_true, sem_operation *on_false = nullptr);
  virtual ~sem_branch();

  std::string to_string() const;
};

class sem_loop : public sem_operation {
  sem_expression *condition_;
  sem_operation *body_;

public:
  sem_loop(sem_expression *condition, sem_operation *body);
  virtual ~sem_loop();

  std::string to_string() const;
};

class sem_break : public sem_operation {
public:
  sem_break() = default;
  virtual ~sem_break() = default;

  std::string to_string() const;
};

class sem_continue : public sem_operation {
public:
  sem_continue() = default;
  virtual ~sem_continue() = default;

  std::string to_string() const;
};

class sem_return : public sem_operation {
  sem_expression *retval_;

public:
  sem_return(sem_expression *retval = nullptr);
  virtual ~sem_return();

  std::string to_string() const;
};

class sem_left_value {
  sem_identifier *identifier_;
  std::list<sem_expression *> *dims_;

public:
  sem_left_value(sem_identifier *identifier);
  virtual ~sem_left_value();

  sem_identifier *identifier() const;
  const std::list<sem_expression *> *dimensions() const;
  void add_dimension(sem_expression *expression);


  std::string to_string() const;
};

class sem_assignment : public sem_operation {
  sem_left_value *left_value_;
  sem_expression *expression_;

public:
  sem_assignment(sem_left_value *left_value, sem_expression *expression);
  virtual ~sem_assignment();

  std::string to_string() const;
};

/* expressions */

class sem_arith_constant : public sem_expression {
  sem_constant *constant_;

public:
  sem_arith_constant(sem_constant *constant);
  virtual ~sem_arith_constant();

  SEM_CONSTANT_TYPE type() const;
  const std::any &value() const;

  std::string to_string() const;
};

class sem_arith_left_value : public sem_expression {
  sem_left_value *left_value_;

public:
  sem_arith_left_value(sem_left_value *left_value);
  virtual ~sem_arith_left_value();

  sem_left_value *left_value() const;

  std::string to_string() const;
};

class sem_function_call : public sem_expression {
  sem_identifier *identifier_;
  std::list<sem_expression *> *real_param_;

public:
  sem_function_call(sem_identifier *identifier, std::list<sem_expression *> *real_param);
  virtual ~sem_function_call();

  std::string to_string() const;
};

class sem_arith_binary : public sem_expression {
  SEM_ARITH_BINARY type_;
  sem_expression *left_;
  sem_expression *right_;

public:
  sem_arith_binary(SEM_ARITH_BINARY type, sem_expression *left, sem_expression *right);
  virtual ~sem_arith_binary();

  SEM_ARITH_BINARY type() const;
  sem_expression *left() const;
  sem_expression *right() const;

  std::string to_string() const;
};

class sem_arith_unary : public sem_expression {
  SEM_ARITH_UNARY type_;
  sem_expression *expression_;

public:
  sem_arith_unary(SEM_ARITH_UNARY type, sem_expression *expression);
  virtual ~sem_arith_unary();

  SEM_ARITH_UNARY type() const;
  sem_expression *expression() const;

  std::string to_string() const;
};

extern sem_region *sem_ast;
