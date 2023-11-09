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

# for test and build
.PHONY: all build parser clean run
,PHONY: test-ast

# for version control
.PHONY: format push

all: build

build:
	cmake -S . -B $(PROJECT_BUILD_DIR) \
		-DMANUAL=ON \
		-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
		-DCMAKE_C_COMPILER:FILEPATH=`which clang` \
		-DCMAKE_CXX_COMPILER:FILEPATH=`which clang++`
	cmake --build $(PROJECT_BUILD_DIR) -j$(NPROC)

.ONESHELL:
parser: 
	cd project/src/parser
	flex lexer.l
	bison parser.y # -Wcounterexamples

clean:
	rm -r $(PROJECT_BUILD_DIR)

run: test-ast

test-ast: build
	$(BINARY) $(TEST_DIR)/$(TEST_CASE).sy -Sast -o $(TEST_DIR)/$(TEST_CASE).ast

FORMAT_FILES	:= $(addprefix format/, $(PROJECT_SRC) $(PROJECT_INC))

PROXY_WSL		:= ALL_PROXY=$(shell cat /etc/resolv.conf | grep nameserver | awk '{print $$2}'):7890
PROXY 			:= $(PROXY_WSL)

$(FORMAT_FILES): format/%:%
	clang-format -i $<

format: $(FORMAT_FILES)

push:
	$(PROXY) git push
