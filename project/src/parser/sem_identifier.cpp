#include "ast_def.h"

#include <cstdlib>
#include <cstring>

sem_identifier::sem_identifier(const char *text) : name_(nullptr) { name_ = strdup(text); }

sem_identifier::~sem_identifier() { free((void *)name_); }

const char *sem_identifier::name() const { return name_; }

std::string sem_identifier::to_string() const { return std::string(name_); }
