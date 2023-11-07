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

enum class TYPE_QUALIFIER {
  UNDEFINED,
  CONST,
};

static inline const char *qualifier_to_cstring(TYPE_QUALIFIER qualifier) {
  switch (qualifier) {
  case TYPE_QUALIFIER::UNDEFINED:
    return "undefined";
  case TYPE_QUALIFIER::CONST:
    return "const";
  }
  return "unknow";
}

enum class TYPE_SPECIFIER {
  UNDEFINED,
  INT,
  FLOAT,
  VOID,
};

static inline const char *specifier_to_cstring(TYPE_SPECIFIER qualifier) {
  switch (qualifier) {
  case TYPE_SPECIFIER::UNDEFINED:
    return "undefined";
  case TYPE_SPECIFIER::INT:
    return "int";
  case TYPE_SPECIFIER::FLOAT:
    return "float";
  case TYPE_SPECIFIER::VOID:
    return "void";
  }
  return "unknow";
}

enum class EXPR_OPERATOR {
  CONSTANT,
  LEFT_VALUE,
  FUNC_CALL,

  NEGATIVE,
  ADDITION,
  SUBTRACTION,
  MULTIPLICATION,
  DIVISION,
  MODULO,

  LOGIC_AND,
  LOGIC_OR,
  LOGIC_NOT,
  COMP_GEQ,
  COMP_GTH,
  COMP_LEQ,
  COMP_LTH,
  COMP_EQU,
  COMP_NEQ,
};

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

class sem_block {
  std::list<sem_operation *> operations_;

public:
  sem_block() = default;
  virtual ~sem_block();

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
  TYPE_QUALIFIER qualifier_;
  TYPE_SPECIFIER specifier_;
  sem_identifier *identifier_;
  std::list<sem_expression *> *dims_;
  sem_init_list *init_list_;

  bool is_global_;

public:
  sem_declaration(sem_identifier *identifier);
  virtual ~sem_declaration();

  void set_type_info(TYPE_QUALIFIER qualifier, TYPE_SPECIFIER specifier);
  void set_init_list(sem_init_list *init_list);
  void set_is_global();
  void add_dimension(sem_expression *expression);

  std::string to_string() const;
};

class sem_param_declaration {
  TYPE_QUALIFIER qualifier_;
  TYPE_SPECIFIER specifier_;
  sem_identifier *identifier_;
  std::list<sem_expression *> *dims_;

  bool is_pointer_;

public:
  sem_param_declaration(sem_identifier *identifier);
  virtual ~sem_param_declaration();

  void set_type_info(TYPE_QUALIFIER qualifier, TYPE_SPECIFIER specifier);
  void set_is_pointer();
  void add_dimension(sem_expression *expression);

  std::string to_string() const;
};

class sem_function_definition : public sem_operation {
  TYPE_QUALIFIER qualifier_;
  TYPE_SPECIFIER specifier_;
  sem_identifier *identifier_;
  std::list<sem_param_declaration *> *fake_params_;
  sem_block *body_;

public:
  sem_function_definition(TYPE_QUALIFIER qualifier, TYPE_SPECIFIER specifier, sem_identifier *identifier,
                          std::list<sem_param_declaration *> *fake_params, sem_block *body);
  virtual ~sem_function_definition();

  std::string to_string() const;
};

extern sem_block *sem_ast;

/* expressions */

class sem_arith_constant : public sem_expression {
  sem_constant *constant_;

public:
  sem_arith_constant(sem_constant *constant);
  virtual ~sem_arith_constant();

  std::string to_string() const;
};

