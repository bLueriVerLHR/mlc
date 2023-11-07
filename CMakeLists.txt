cmake_minimum_required(VERSION 3.20)

project(mlc)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED On)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(PROJECT_PATH project)
set(SRC_PATH ${PROJECT_PATH}/src)
set(INC_PATH ${PROJECT_PATH}/include)
set(PSR_PATH ${PROJECT_PATH}/src/parser)

add_compile_options(-g)
if(${MANUAL})
    add_compile_options(-g -fsanitize=address -mllvm -asan-detect-invalid-pointer-pair=true)
    add_link_options(-fsanitize=address)
endif()


include_directories(${INC_PATH})
include_directories(${PSR_PATH})

file(GLOB_RECURSE SRC_FILES ${SRC_PATH}/*.cpp ${SRC_PATH}/*.c)

add_executable(${PROJECT_NAME} ${SRC_FILES})