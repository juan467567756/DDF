cmake_minimum_required(VERSION 3.10)
project(DDF)
set(CMAKE_CXX_STANDARD 17)

# --- Habilitar cobertura de código (ON por defecto) ---
option(CODE_COVERAGE "Enable coverage reporting" ON)
if(CODE_COVERAGE)
  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Building with coverage flags")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
  endif()
endif()

# --- Preparar tests ---
enable_testing()

# --- Archivos fuente ---
file(GLOB SRC "src/*.cpp")

# --- Ejecutable principal ---
add_executable(ddf ${SRC})
install(TARGETS ddf DESTINATION bin)

# --- GoogleTest submódulo ---
add_subdirectory(extern/googletest)
include_directories(extern/googletest/googletest/include)

# --- Test de utilidades (test_ddf) ---
file(GLOB TEST_UTILS_SRC "tests/test_utils.cpp")
add_executable(test_ddf ${TEST_UTILS_SRC} ${SRC})
target_link_libraries(test_ddf gtest_main)
add_test(NAME core_tests COMMAND test_ddf)
install(TARGETS test_ddf DESTINATION bin)

# --- Test de parser skeleton (test_parser) ---
file(GLOB TEST_PARSER_SRC "tests/test_parser.cpp")
add_executable(test_parser ${TEST_PARSER_SRC} ${SRC})
target_link_libraries(test_parser gtest_main)
add_test(NAME parser_tests COMMAND test_parser)
install(TARGETS test_parser DESTINATION bin)
