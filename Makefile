PROJECT_SRC			:= $(shell find project -name "*.cpp" -or -name "*.c")
PROJECT_INC			:= $(shell find project -name "*.hpp" -or -name "*.h")
PROJECT_PARSER	:= $(shell find project -name "*.l" -or -name "*.y")
NPROC						:= $(shell nproc)

$(shell mkdir -p build)

.ONESHELL:
all: $(PROJECT_SRC) $(PROJECT_INC) parser
	cd build
	cmake ..
	cmake --build . -j$(NPROC)

parser: $(PROJECT_PARSER)
	cd project/src/parser && flex lexer.l && bison parser.y

clean:
	rm -r build