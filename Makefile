PROJECT_NAME	:= mlc
PROJECT_DIR		:= project
PROJECT_SRC_DIR	:= $(PROJECT_DIR)/src
PROJECT_INC_DIR	:= $(PROJECT_DIR)/include

PROJECT_SRC		:= $(shell find $(PROJECT_DIR) -name "*.cpp" -or -name "*.c")
PROJECT_INC		:= $(shell find $(PROJECT_DIR) -name "*.hpp" -or -name "*.h")
PROJECT_PARSER	:= $(shell find $(PROJECT_DIR) -name "*.l" -or -name "*.y")
NPROC			:= $(shell nproc)

PROJECT_BUILD_DIR	:= build
BINARY				:= $(PROJECT_BUILD_DIR)/$(PROJECT_NAME)

TEST_DIR	:= test
TEST_CASE	?= fb

$(shell mkdir -p $(PROJECT_BUILD_DIR))

all: build

build: $(PROJECT_SRC) $(PROJECT_INC) parser
	cmake -S . -B $(PROJECT_BUILD_DIR)
	cmake --build $(PROJECT_BUILD_DIR) -j$(NPROC)

parser: $(PROJECT_PARSER)
	cd project/src/parser && flex lexer.l && bison parser.y

clean:
	rm -r $(PROJECT_BUILD_DIR)

run: build
	$(BINARY) $(TEST_DIR)/$(TEST_CASE).txt