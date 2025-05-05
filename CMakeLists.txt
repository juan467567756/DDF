cmake_minimum_required(VERSION 3.10)
project(DDF)
set(CMAKE_CXX_STANDARD 17)

# Código fuente
file(GLOB SRC "src/*.cpp")

# Ejecutable principal
add_executable(ddf ${SRC})

# Instalación
install(TARGETS ddf DESTINATION bin)

# GoogleTest submódulo (para v0.8)
add_subdirectory(extern/googletest)
include_directories(extern/googletest/googletest/include)

# Tests
file(GLOB TEST_SRC "tests/*.cpp")
add_executable(test_ddf ${TEST_SRC} ${SRC})
target_link_libraries(test_ddf gtest_main)
install(TARGETS test_ddf DESTINATION bin)
