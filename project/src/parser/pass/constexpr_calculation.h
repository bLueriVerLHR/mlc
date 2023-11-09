#include "pass.h"
#include "visitor.h"

class constexpr_calculation : public sem_visitor {
  sem_context *ctx_;

public:
  constexpr_calculation(sem_context *ctx);

  virtual void visit(sem_operation *operation) override;
  virtual void visit(sem_region *region) override;
};