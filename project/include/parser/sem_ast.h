#pragma once

namespace sem {
[[nodiscard("check return code")]] int prepare();

[[nodiscard("check return code")]] int parse_file(const char *file);

[[nodiscard("check return code")]] int destroy();

void pass();

} // namespace sem