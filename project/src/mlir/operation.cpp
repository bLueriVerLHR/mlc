#include "mlir/operation.h"

namespace mlir {

operation::operation() : dialect_(nullptr), name_(nullptr), arguments_() {}

} // namespace mlir