#pragma once

class sem_constant;
class sem_identifier;
class sem_operation;
class sem_region;
class sem_init_list;
class sem_param_declaration;
class sem_left_value;

class sem_visitor {
public:
  virtual void visit(sem_constant *constant) = 0;
  virtual void visit(sem_identifier *constant) = 0;
  virtual void visit(sem_operation *constant) = 0;
  virtual void visit(sem_region *constant) = 0;
  virtual void visit(sem_init_list *constant) = 0;
  virtual void visit(sem_param_declaration *constant) = 0;
  virtual void visit(sem_left_value *constant) = 0;
};