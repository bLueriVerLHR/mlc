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

CLANG			:= $(shell which clang)
CLANGXX			:= $(shell which clang++)
CCACHE			:= $(shell which ccache)
NINJA			:= $(shell which ninja)

# set compile info

CC				:= $(CLANG)
CXX				:= $(CLANGXX)

ifeq ($(NINJA),)
CMAKE_BUILDER	:= 
else
CMAKE_BUILDER	:= -G Ninja
endif

# make dir
$(shell mkdir -p $(PROJECT_BUILD_DIR))

# build binary
.PHONY: all build debug release clean

all: build

build: debug

debug:
	cmake \
		-S . -B $(PROJECT_BUILD_DIR) \
		$(CMAKE_BUILDER) \
		-DMANUAL:BOOL=TRUE \
		-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
		-DCMAKE_BUILD_TYPE:STRING=Debug \
		-DCMAKE_C_COMPILER:FILEPATH=$(CC) \
		-DCMAKE_CXX_COMPILER:FILEPATH=$(CXX) \
		-DCMAKE_C_COMPILER_LAUNCHER:FILEPATH=$(CCACHE) \
		-DCMAKE_CXX_COMPILER_LAUNCHER:FILEPATH=$(CCACHE)
	cmake --build $(PROJECT_BUILD_DIR) -j$(NPROC)

release:
	cmake \
		-S . -B $(PROJECT_BUILD_DIR) \
		$(CMAKE_BUILDER) \
		-DMANUAL:BOOL=TRUE \
		-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
		-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_C_COMPILER:FILEPATH=$(CC) \
		-DCMAKE_CXX_COMPILER:FILEPATH=$(CXX) \
		-DCMAKE_C_COMPILER_LAUNCHER:FILEPATH=$(CCACHE) \
		-DCMAKE_CXX_COMPILER_LAUNCHER:FILEPATH=$(CCACHE)
	cmake --build $(PROJECT_BUILD_DIR) -j$(NPROC)

clean:
	rm -r $(PROJECT_BUILD_DIR)

# test binary
.PHONY: run test-ast

run: release
	$(BINARY) $(TEST_DIR)/$(TEST_CASE).sy -Sast -o $(TEST_DIR)/$(TEST_CASE).ast

test: test-ast

test-ast: build
	$(BINARY) $(TEST_DIR)/$(TEST_CASE).sy -Sast -o $(TEST_DIR)/$(TEST_CASE).ast

# build parser
.PHONY: parser

.ONESHELL:
parser:
	cd project/src/parser
	flex lexer.l
	bison parser.y # -Wcounterexamples

# formatter and git
.PHONY: format push

FORMAT_FILES	:= $(addprefix format/, $(PROJECT_SRC) $(PROJECT_INC))

PROXY_WSL		:= ALL_PROXY=$(shell cat /etc/resolv.conf | grep nameserver | awk '{print $$2}'):7890
PROXY 			:= $(PROXY_WSL)

$(FORMAT_FILES): format/%:%
	clang-format -i $<

format: $(FORMAT_FILES)

push:
	$(PROXY) git push
