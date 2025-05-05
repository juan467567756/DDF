cmake_minimum_required(VERSION 3.10)
project(DDF)
set(CMAKE_CXX_STANDARD 17)

# Fuerza CRT dinámico en MSVC (/MD /MDd)
if (MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
      CACHE STRING "" FORCE)
endif()

# Indica a GoogleTest que use también CRT compartido
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Habilitar cobertura de código (ON por defecto)
option(CODE_COVERAGE "Enable coverage reporting" ON)
if (CODE_COVERAGE)
  if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Building with coverage flags")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
  endif()
endif()

enable_testing()

# Archivos fuente
file(GLOB SRC "src/*.cpp")

# Ejecutable principal
add_executable(ddf ${SRC})
install(TARGETS ddf DESTINATION bin)

# GoogleTest submódulo
add_subdirectory(extern/googletest)
include_directories(extern/googletest/googletest/include)

file(GLOB TEST_UTILS_SRC "tests/test_utils.cpp")

add_executable(core_tests ${TEST_UTILS_SRC} src/utils.cpp)
target_link_libraries(core_tests gtest_main)
add_test(NAME core_tests COMMAND core_tests)
install(TARGETS core_tests DESTINATION bin)

add_executable(parser_tests ${TEST_PARSER_SRC} src/parser.cpp)
target_link_libraries(parser_tests gtest_main)
add_test(NAME parser_tests COMMAND parser_tests)
install(TARGETS parser_tests DESTINATION bin)

add_executable(semantic_tests ${TEST_SEMANTIC_SRC} src/parser.cpp src/semantic.cpp)
target_link_libraries(semantic_tests gtest_main)
add_test(NAME semantic_tests COMMAND semantic_tests)
install(TARGETS semantic_tests DESTINATION bin)

