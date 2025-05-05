cmake_minimum_required(VERSION 3.10)
project(DDF)
set(CMAKE_CXX_STANDARD 17)

# --- Habilitar cobertura de código (ON por defecto) ---
option(CODE_COVERAGE "Enable coverage reporting" ON)
if (CODE_COVERAGE)
  if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Building with coverage flags")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
  endif()
endif()

# --- Archivos fuente y ejecutable principal ---
file(GLOB SRC "src/*.cpp")
add_executable(ddf ${SRC})
install(TARGETS ddf DESTINATION bin)

# --- GoogleTest submódulo y tests ---
add_subdirectory(extern/googletest)
include_directories(extern/googletest/googletest/include)
file(GLOB TEST_SRC "tests/*.cpp")
add_executable(test_ddf ${TEST_SRC} ${SRC})
target_link_libraries(test_ddf gtest_main)
install(TARGETS test_ddf DESTINATION bin)
