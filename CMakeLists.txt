cmake_minimum_required(VERSION 3.18)
project(acab)

# Do not run cmake in the main project directory, to keep
# build artifacts from becoming clutter
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In source builds not allowed.
    Please make a build directory and run CMake from there.
    You may need to remove CMakeCache.txt")
endif()

set(CMAKE_CXX_STANDARD 11)

# Enable cmake testing
include(CTest)
enable_testing()

# Enable GoogleTest
include(GoogleTest)
add_subdirectory(/usr/src/googletest googletest)

# Enable compiler warnings
add_compile_options(-Wall -Wextra -pedantic)

# Point to libraries path
include_directories(${CMAKE_SOURCE_DIR}/src/lib)

# Build executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_library(deck src/lib/deck.cc)
add_library(pet src/lib/pet.cc)
add_library(bounded_value src/lib/bounded_value.cc)
# add_executable()
# target_link_libraries()

# Tests
add_executable(bounded_value_test tests/bounded_value_test.cc)
target_link_libraries(bounded_value_test bounded_value gtest_main)
gtest_discover_tests(bounded_value_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)

add_executable(pet_test tests/pet_test.cc)
target_link_libraries(pet_test pet gtest_main)
gtest_discover_tests(pet_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)

add_executable(deck_test tests/deck_test.cc)
target_link_libraries(deck_test deck pet gtest_main)
gtest_discover_tests(deck_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# add_test()
