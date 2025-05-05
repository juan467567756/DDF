cmake_minimum_required(VERSION 3.10)
project(DDF)
set(CMAKE_CXX_STANDARD 17)

# Incluir submódulo GoogleTest
add_subdirectory(extern/googletest)
include_directories(extern/googletest/googletest/include)

# Ficheros fuente
file(GLOB SRC "src/*.cpp")

# Ejecutable principal
add_executable(ddf ${SRC})

# Tests con GoogleTest
file(GLOB TEST_SRC "tests/*.cpp")
add_executable(test_ddf ${TEST_SRC} ${SRC})
target_link_libraries(test_ddf gtest_main)
