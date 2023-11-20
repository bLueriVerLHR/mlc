#pragma once

class sem_region;
class sem_operation;
class sem_expression;
class sem_declaration;
class sem_function_definition;
class sem_plain_block;
class sem_branch;
class sem_loop;
class sem_break;
class sem_continue;
class sem_return;
class sem_assignment;

class sem_visitor {
public:
  virtual void visit(sem_operation *operation) = 0;
  virtual void visit(sem_region *region) = 0;
};