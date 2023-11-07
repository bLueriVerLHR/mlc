#include "ast_def.h"

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
  if (init_list_.empty()) {
    return std::string("[]");
  }

  std::string out = "[";
  std::list<sem_init_list *>::const_iterator it = init_list_.begin();
  out += (*it)->to_string();
  for (++it; it != init_list_.end(); ++it) {
    out += ", " + (*it)->to_string();
  }
  out += "]";

  return out;
}

sem_declaration::sem_declaration(sem_identifier *identifier)
    : qualifier_(TYPE_QUALIFIER::UNDEFINED), specifier_(TYPE_SPECIFIER::UNDEFINED), identifier_(identifier),
      dims_(nullptr), init_list_(nullptr), is_global_(false) {}

sem_declaration::~sem_declaration() {
  if (identifier_ != nullptr) {
    delete identifier_;
    identifier_ = nullptr;
  }
  if (dims_ != nullptr) {
    std::list<sem_expression *> &vdim = *dims_;
    for (sem_expression *&dim : vdim) {
      if (dim != nullptr) {
        delete dim;
        dim = nullptr;
      }
    }
    delete dims_;
    dims_ = nullptr;
  }
  if (init_list_ != nullptr) {
    delete init_list_;
    init_list_ = nullptr;
  }
}

void sem_declaration::set_type_info(TYPE_QUALIFIER qualifier, TYPE_SPECIFIER specifier) {
  qualifier_ = qualifier;
  specifier_ = specifier;

  if (init_list_ == nullptr) {
    SEM_CONSTANT_TYPE sct = SEM_CONSTANT_TYPE::ERROR;

    switch (specifier_) {
    case TYPE_SPECIFIER::INT:
      sct = SEM_CONSTANT_TYPE::DECIMAL_INTEGER;
      break;
    case TYPE_SPECIFIER::FLOAT:
      sct = SEM_CONSTANT_TYPE::DECIMAL_FLOAT;
      break;
    default:
      break;
    }

    sem_constant *dummy = new sem_constant(sct);
    sem_expression *expr = new sem_arith_constant(dummy);
    init_list_ = new sem_init_list(expr);
  }
}

void sem_declaration::set_init_list(sem_init_list *init_list) { init_list_ = init_list; }

void sem_declaration::set_is_global() { is_global_ = true; }

void sem_declaration::add_dimension(sem_expression *expression) {
  if (dims_ == nullptr) {
    dims_ = new std::list<sem_expression *>;
  }

  dims_->push_back(expression);
}

std::string sem_declaration::to_string() const {
  std::string out = (is_global_ ? "@" : "%") + identifier_->to_string();

  if (init_list_ != nullptr) {
    out += " = ";
    if (dims_ == nullptr or dims_->empty()) {
      out += "arith.constant";
    } else {
      out += "arith.initializer";
    }
    out += " ";
    out += init_list_->to_string();
  }

  out += " : ";
  if (qualifier_ != TYPE_QUALIFIER::UNDEFINED) {
    out += qualifier_to_cstring(qualifier_);
    out += " ";
  }
  out += specifier_to_cstring(specifier_);

  if (dims_ != nullptr and not dims_->empty()) {
    out += '[';
    std::list<sem_expression *>::iterator it = dims_->begin();
    out += (*it)->to_string();
    for (++it; it != dims_->end(); ++it) {
      out += "x" + (*it)->to_string();
    }
    out += ']';
  }

  return out;
}

sem_param_declaration::sem_param_declaration(sem_identifier *identifier)
    : qualifier_(TYPE_QUALIFIER::UNDEFINED), specifier_(TYPE_SPECIFIER::UNDEFINED), identifier_(identifier),
      dims_(nullptr), is_pointer_(false) {}

sem_param_declaration::~sem_param_declaration() {
  if (identifier_ != nullptr) {
    delete identifier_;
    identifier_ = nullptr;
  }

  if (dims_ != nullptr) {
    std::list<sem_expression *> &vdim = *dims_;
    for (sem_expression *&dim : vdim) {
      if (dim != nullptr) {
        delete dim;
        dim = nullptr;
      }
    }
    delete dims_;
    dims_ = nullptr;
  }
}

void sem_param_declaration::set_type_info(TYPE_QUALIFIER qualifier, TYPE_SPECIFIER specifier) {
  qualifier_ = qualifier;
  specifier_ = specifier;
}

void sem_param_declaration::set_is_pointer() { is_pointer_ = true; }

void sem_param_declaration::add_dimension(sem_expression *expression) {
  if (dims_ == nullptr) {
    dims_ = new std::list<sem_expression *>;
  }
  dims_->push_front(expression);
}

std::string sem_param_declaration::to_string() const {
  std::string out = "%" + identifier_->to_string();

  out += " : ";
  if (qualifier_ != TYPE_QUALIFIER::UNDEFINED) {
    out += qualifier_to_cstring(qualifier_);
    out += " ";
  }
  out += specifier_to_cstring(specifier_);

  if (is_pointer_) {
    out += "[]";
  }

  if (dims_ != nullptr and not dims_->empty()) {
    out += '[';
    std::list<sem_expression *>::iterator it = dims_->begin();
    out += (*it)->to_string();
    for (++it; it != dims_->end(); ++it) {
      out += "x" + (*it)->to_string();
    }
    out += ']';
  }

  return out;
}

sem_function_definition::sem_function_definition(TYPE_QUALIFIER qualifier, TYPE_SPECIFIER specifier,
                                                 sem_identifier *identifier,
                                                 std::list<sem_param_declaration *> *fake_params, sem_block *body)
    : qualifier_(qualifier), specifier_(specifier), identifier_(identifier), fake_params_(fake_params), body_(body) {}

sem_function_definition::~sem_function_definition() {
  if (identifier_ != nullptr) {
    delete identifier_;
    identifier_ = nullptr;
  }
  if (fake_params_ != nullptr) {
    std::list<sem_param_declaration *> &fparams = *fake_params_;
    for (sem_param_declaration *&param : fparams) {
      if (param != nullptr) {
        delete param;
        param = nullptr;
      }
    }
    delete fake_params_;
    fake_params_ = nullptr;
  }
  if (body_ != nullptr) {
    delete body_;
    body_ = nullptr;
  }
}

std::string sem_function_definition::to_string() const {
  std::string out = "func.func";
  out += " ";
  out += "@" + identifier_->to_string();
  out += "(";
  if (not fake_params_->empty()) {
    std::list<sem_param_declaration *>::iterator it = fake_params_->begin();
    out += (*it)->to_string();
    for (++it; it != fake_params_->end(); ++it) {
      out += ", " + (*it)->to_string();
    }
  }
  out += ") -> ";
  if (qualifier_ != TYPE_QUALIFIER::UNDEFINED) {
    out += qualifier_to_cstring(qualifier_);
    out += " ";
  }
  out += specifier_to_cstring(specifier_);
  out += " ";
  out += body_->to_string();

  return out;
}