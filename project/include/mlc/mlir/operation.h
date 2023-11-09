#pragma once

#include <string>
#include <vector>

namespace mlir {
class operation {

protected:
  size_t opidx_;
  const char *dialect_;
  const char *name_;
  std::vector<size_t> arguments_;

public:
  operation();
  virtual ~operation() = default;

  virtual std::string to_string() const = 0;
};
} // namespace mlir