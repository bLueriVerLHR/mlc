#include "pass.h"
#include "visitor.h"

class symbol_tagging : public sem_visitor {
  sem_context *ctx_;

public:
  symbol_tagging(sem_context *ctx);

  virtual void visit(sem_operation *operation) override;
  virtual void visit(sem_region *region) override;
};