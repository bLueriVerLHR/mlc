#pragma once

namespace sem {

[[nodiscard("check return code")]] int parse_file(const char *file);

void destroy();

void pass();

} // namespace sem