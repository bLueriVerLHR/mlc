# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/blur/code/mlc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/blur/code/mlc/build

# Include any dependencies generated for this target.
include CMakeFiles/mlc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mlc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mlc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mlc.dir/flags.make

CMakeFiles/mlc.dir/project/src/main.cpp.o: CMakeFiles/mlc.dir/flags.make
CMakeFiles/mlc.dir/project/src/main.cpp.o: /home/blur/code/mlc/project/src/main.cpp
CMakeFiles/mlc.dir/project/src/main.cpp.o: CMakeFiles/mlc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/blur/code/mlc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mlc.dir/project/src/main.cpp.o"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mlc.dir/project/src/main.cpp.o -MF CMakeFiles/mlc.dir/project/src/main.cpp.o.d -o CMakeFiles/mlc.dir/project/src/main.cpp.o -c /home/blur/code/mlc/project/src/main.cpp

CMakeFiles/mlc.dir/project/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mlc.dir/project/src/main.cpp.i"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/blur/code/mlc/project/src/main.cpp > CMakeFiles/mlc.dir/project/src/main.cpp.i

CMakeFiles/mlc.dir/project/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mlc.dir/project/src/main.cpp.s"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/blur/code/mlc/project/src/main.cpp -o CMakeFiles/mlc.dir/project/src/main.cpp.s

CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.o: CMakeFiles/mlc.dir/flags.make
CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.o: /home/blur/code/mlc/project/src/parser/lexer.cpp
CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.o: CMakeFiles/mlc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/blur/code/mlc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.o"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.o -MF CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.o.d -o CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.o -c /home/blur/code/mlc/project/src/parser/lexer.cpp

CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.i"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/blur/code/mlc/project/src/parser/lexer.cpp > CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.i

CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.s"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/blur/code/mlc/project/src/parser/lexer.cpp -o CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.s

CMakeFiles/mlc.dir/project/src/parser/parser.cpp.o: CMakeFiles/mlc.dir/flags.make
CMakeFiles/mlc.dir/project/src/parser/parser.cpp.o: /home/blur/code/mlc/project/src/parser/parser.cpp
CMakeFiles/mlc.dir/project/src/parser/parser.cpp.o: CMakeFiles/mlc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/blur/code/mlc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mlc.dir/project/src/parser/parser.cpp.o"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mlc.dir/project/src/parser/parser.cpp.o -MF CMakeFiles/mlc.dir/project/src/parser/parser.cpp.o.d -o CMakeFiles/mlc.dir/project/src/parser/parser.cpp.o -c /home/blur/code/mlc/project/src/parser/parser.cpp

CMakeFiles/mlc.dir/project/src/parser/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mlc.dir/project/src/parser/parser.cpp.i"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/blur/code/mlc/project/src/parser/parser.cpp > CMakeFiles/mlc.dir/project/src/parser/parser.cpp.i

CMakeFiles/mlc.dir/project/src/parser/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mlc.dir/project/src/parser/parser.cpp.s"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/blur/code/mlc/project/src/parser/parser.cpp -o CMakeFiles/mlc.dir/project/src/parser/parser.cpp.s

CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.o: CMakeFiles/mlc.dir/flags.make
CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.o: /home/blur/code/mlc/project/src/parser/sem_block.cpp
CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.o: CMakeFiles/mlc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/blur/code/mlc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.o"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.o -MF CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.o.d -o CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.o -c /home/blur/code/mlc/project/src/parser/sem_block.cpp

CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.i"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/blur/code/mlc/project/src/parser/sem_block.cpp > CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.i

CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.s"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/blur/code/mlc/project/src/parser/sem_block.cpp -o CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.s

CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.o: CMakeFiles/mlc.dir/flags.make
CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.o: /home/blur/code/mlc/project/src/parser/sem_constant.cpp
CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.o: CMakeFiles/mlc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/blur/code/mlc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.o"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.o -MF CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.o.d -o CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.o -c /home/blur/code/mlc/project/src/parser/sem_constant.cpp

CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.i"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/blur/code/mlc/project/src/parser/sem_constant.cpp > CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.i

CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.s"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/blur/code/mlc/project/src/parser/sem_constant.cpp -o CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.s

CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.o: CMakeFiles/mlc.dir/flags.make
CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.o: /home/blur/code/mlc/project/src/parser/sem_identifier.cpp
CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.o: CMakeFiles/mlc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/blur/code/mlc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.o"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.o -MF CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.o.d -o CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.o -c /home/blur/code/mlc/project/src/parser/sem_identifier.cpp

CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.i"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/blur/code/mlc/project/src/parser/sem_identifier.cpp > CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.i

CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.s"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/blur/code/mlc/project/src/parser/sem_identifier.cpp -o CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.s

CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.o: CMakeFiles/mlc.dir/flags.make
CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.o: /home/blur/code/mlc/project/src/parser/sem_operations.cpp
CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.o: CMakeFiles/mlc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/blur/code/mlc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.o"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.o -MF CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.o.d -o CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.o -c /home/blur/code/mlc/project/src/parser/sem_operations.cpp

CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.i"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/blur/code/mlc/project/src/parser/sem_operations.cpp > CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.i

CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.s"
	/usr/sbin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/blur/code/mlc/project/src/parser/sem_operations.cpp -o CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.s

# Object files for target mlc
mlc_OBJECTS = \
"CMakeFiles/mlc.dir/project/src/main.cpp.o" \
"CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.o" \
"CMakeFiles/mlc.dir/project/src/parser/parser.cpp.o" \
"CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.o" \
"CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.o" \
"CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.o" \
"CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.o"

# External object files for target mlc
mlc_EXTERNAL_OBJECTS =

mlc: CMakeFiles/mlc.dir/project/src/main.cpp.o
mlc: CMakeFiles/mlc.dir/project/src/parser/lexer.cpp.o
mlc: CMakeFiles/mlc.dir/project/src/parser/parser.cpp.o
mlc: CMakeFiles/mlc.dir/project/src/parser/sem_block.cpp.o
mlc: CMakeFiles/mlc.dir/project/src/parser/sem_constant.cpp.o
mlc: CMakeFiles/mlc.dir/project/src/parser/sem_identifier.cpp.o
mlc: CMakeFiles/mlc.dir/project/src/parser/sem_operations.cpp.o
mlc: CMakeFiles/mlc.dir/build.make
mlc: CMakeFiles/mlc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/blur/code/mlc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable mlc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mlc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mlc.dir/build: mlc
.PHONY : CMakeFiles/mlc.dir/build

CMakeFiles/mlc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mlc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mlc.dir/clean

CMakeFiles/mlc.dir/depend:
	cd /home/blur/code/mlc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/blur/code/mlc /home/blur/code/mlc /home/blur/code/mlc/build /home/blur/code/mlc/build /home/blur/code/mlc/build/CMakeFiles/mlc.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/mlc.dir/depend

