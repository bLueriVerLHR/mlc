#pragma once

[[nodiscard("check return code")]] int prepare_sem_ast_generator();

[[nodiscard("check return code")]] int parse_file(const char *file);

[[nodiscard("check return code")]] int destroy_sem_ast_generator();