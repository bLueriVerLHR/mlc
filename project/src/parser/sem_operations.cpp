#include "ast_def.h"

std::string sem_operation::to_string() const { return "meta.unimplemented()"; }

sem_expression::sem_expression(sem_constant *constant) : constant_(constant) {}

sem_expression::~sem_expression() {
  if (constant_ != nullptr) {
    delete constant_;
    constant_ = nullptr;
  }
}

std::string sem_expression::to_string() const { return constant_->to_string(); }

sem_init_list::sem_init_list() : is_expression_(false), expression_(nullptr), init_list_() {}

sem_init_list::sem_init_list(sem_expression *expression)
    : is_expression_(true), expression_(expression), init_list_() {}

sem_init_list::sem_init_list(sem_init_list *init_list) : is_expression_(false), expression_(nullptr), init_list_() {
  init_list_.push_back(init_list);
}

sem_init_list::~sem_init_list() {
  if (is_expression_ and expression_ != nullptr) {
    delete expression_;
    expression_ = nullptr;
  }

  for (sem_init_list *&init_list : init_list_) {
    if (init_list == nullptr)
      continue;

    delete init_list;
    init_list = nullptr;
  }
}

void sem_init_list::add_init_list(sem_init_list *init_list) { init_list_.push_back(init_list); }

std::string sem_init_list::to_string() const {
  if (is_expression_) {
    return expression_->to_string();
  }

  std::string out = "{ ";
  for (sem_init_list *const &init_list : init_list_) {
    out += init_list->to_string() + ", ";
  }
  out += "}";

  return out;
}

sem_declarator::sem_declarator(sem_identifier *identifier) : identifier_(identifier), dims_(), init_list_(nullptr) {}

sem_declarator::~sem_declarator() {
  if (identifier_ != nullptr) {
    delete identifier_;
    identifier_ = nullptr;
  }

  for (sem_expression *&dim : dims_) {
    if (dim == nullptr)
      continue;

    delete dim;
    dim = nullptr;
  }

  if (init_list_ != nullptr) {
    delete init_list_;
    init_list_ = nullptr;
  }
}

void sem_declarator::set_init_list(sem_init_list *init_list) { init_list_ = init_list; }

void sem_declarator::add_dimension(sem_expression *expression) { dims_.push_front(expression); }

std::string sem_declarator::to_string() const {
  std::string out = "meta.declarator(";
  out += identifier_->to_string() + ", ";
  out += "[";
  for (sem_expression *const &dim : dims_) {
    out += dim->to_string() + ", ";
  }
  out += "], ";
  out += init_list_->to_string();
  out += ")";

  return out;
}

sem_declaration::sem_declaration(TYPE_QUALIFIER qualifier, TYPE_SPECIFIER specifier, sem_block *declarators)
    : qualifier_(qualifier), specifier_(specifier), declarators_(declarators) {}

sem_declaration::~sem_declaration() {
  if (declarators_ != nullptr) {
    delete declarators_;
    declarators_ = nullptr;
  }
}

std::string sem_declaration::to_string() const {
  std::string out = "meta.declaraions(";
  out += qualifier_to_cstring(qualifier_);
  out += ", ";
  out += specifier_to_cstring(specifier_);
  out += ", ";
  out += declarators_->to_string() + ")";

  return out;
}

sem_param_declarator::sem_param_declarator(sem_identifier *identifier)
    : qualifier_(TYPE_QUALIFIER::UNDEFINED), specifier_(TYPE_SPECIFIER::UNDEFINED), identifier_(identifier), dims_(),
      is_pointer_(false) {}

sem_param_declarator::~sem_param_declarator() {
  if (identifier_ != nullptr) {
    delete identifier_;
    identifier_ = nullptr;
  }

  for (sem_expression *&dim : dims_) {
    if (dim == nullptr)
      continue;

    delete dim;
    dim = nullptr;
  }
}

void sem_param_declarator::set_type_info(TYPE_QUALIFIER qualifier, TYPE_SPECIFIER specifier) {
  qualifier_ = qualifier;
  specifier_ = specifier;
}

void sem_param_declarator::set_is_pointer() { is_pointer_ = true; }

void sem_param_declarator::add_dimension(sem_expression *expression) { dims_.push_front(expression); }

std::string sem_param_declarator::to_string() const {
  std::string out = "meta.param(";
  out += qualifier_to_cstring(qualifier_);
  out += ", ";
  out += specifier_to_cstring(specifier_);
  out += ", ";
  out += (is_pointer_ ? "meta.type.pointer" : "meta.type.common");
  out += ", ";
  out += identifier_->to_string() + ", ";
  out += "[";
  for (sem_expression *const &dim : dims_) {
    out += dim->to_string() + ", ";
  }
  out += "])";

  return out;
}

sem_function_definition::sem_function_definition(TYPE_QUALIFIER qualifier, TYPE_SPECIFIER specifier,
                                                 sem_identifier *identifier, sem_block *fake_params, sem_block *body)
    : qualifier_(qualifier), specifier_(specifier), identifier_(identifier), fake_params_(fake_params), body_(body) {}

sem_function_definition::~sem_function_definition() {
  if (identifier_ != nullptr) {
    delete identifier_;
    identifier_ = nullptr;
  }
  if (fake_params_ != nullptr) {
    delete fake_params_;
    fake_params_ = nullptr;
  }
  if (body_ != nullptr) {
    delete body_;
    body_ = nullptr;
  }
}

std::string sem_function_definition::to_string() const {
  std::string out = "meta.function(";
  out += qualifier_to_cstring(qualifier_);
  out += ", ";
  out += specifier_to_cstring(specifier_);
  out += ", ";
  out += identifier_->to_string() + ", ";
  out += fake_params_->to_string() + ", ";
  out += body_->to_string();
  out += ")";

  return out;
}

sem_simple_embedding::sem_simple_embedding(sem_block *block) : block_(block) {}

sem_simple_embedding::~sem_simple_embedding() {
  if (block_ != nullptr) {
    delete block_;
    block_ = nullptr;
  }
}

std::string sem_simple_embedding::to_string() const {
  return block_->to_string();
}
