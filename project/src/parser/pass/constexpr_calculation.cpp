#include "constexpr_calculation.h"
#include "../ast_def.h"

constexpr_calculation::constexpr_calculation(sem_context *ctx) : ctx_(ctx) {}

void constexpr_calculation::visit(sem_operation *operation) { operation->simple_const_folding(this, ctx_); }

void constexpr_calculation::visit(sem_region *region) {
  ctx_->enter_block();
  for (sem_operation *operation : region->operations()) {
    operation->simple_const_folding(this, ctx_);
  }
  ctx_->exit_block();
}

void sem_operation::simple_const_folding(sem_visitor *visitor, sem_context *ctx) {}

void sem_declaration::simple_const_folding(sem_visitor *visitor, sem_context *ctx) {
  if (dims_ != nullptr) {
    for (sem_expression *&expr : *dims_) {
      simple_expression_result &&result = calculate_constexpr(expr, *ctx);
      if (result.type == SER_TYPE::ERROR) {
        fprintf(stderr, "dimension should be constexpr\n");
        exit(EXIT_FAILURE);
      }

      delete expr;
      expr = nullptr;

      switch (result.type) {
      case SER_TYPE::FLOAT: {
        sem_constant *constant = new sem_constant(long(result.fval));
        expr = new sem_arith_constant(constant);
      } break;

      case SER_TYPE::INT: {
        sem_constant *constant = new sem_constant(result.ival);
        expr = new sem_arith_constant(constant);
      } break;

      case SER_TYPE::CSTRING: {
        sem_constant *constant = new sem_constant(result.cstring);
        expr = new sem_arith_constant(constant);
      } break;

      default:
        break;
      }
    }
  }

  ctx->symtbl->add_symbol(qualifier_ == SEM_TYPE_QUALIFIER::CONST, identifier_->name(), dims_, init_list_);
}

void sem_param_declaration::simple_const_folding(sem_visitor *visitor, sem_context *ctx) {
  if (dims_ != nullptr) {
    for (sem_expression *&expr : *dims_) {
      simple_expression_result &&result = calculate_constexpr(expr, *ctx);
      if (result.type == SER_TYPE::ERROR) {
        fprintf(stderr, "dimension should be constexpr\n");
        exit(EXIT_FAILURE);
      }

      delete expr;
      expr = nullptr;

      switch (result.type) {
      case SER_TYPE::FLOAT: {
        sem_constant *constant = new sem_constant(long(result.fval));
        expr = new sem_arith_constant(constant);
      } break;

      case SER_TYPE::INT: {
        sem_constant *constant = new sem_constant(result.ival);
        expr = new sem_arith_constant(constant);
      } break;

      case SER_TYPE::CSTRING: {
        sem_constant *constant = new sem_constant(result.ival);
        expr = new sem_arith_constant(constant);
      } break;

      default:
        break;
      }
    }
  }

  ctx->symtbl->add_symbol(false, identifier_->name(), dims_, nullptr);
}

void sem_function_definition::simple_const_folding(sem_visitor *visitor, sem_context *ctx) {
  if (fake_params_ != nullptr) {
    for (sem_param_declaration *fake_param : *fake_params_) {
      visitor->visit(fake_param);
    }
  }
  visitor->visit(body_);
}

void sem_plain_block::simple_const_folding(sem_visitor *visitor, sem_context *ctx) {
  if (block_ != nullptr) {
    visitor->visit(block_);
  }
}