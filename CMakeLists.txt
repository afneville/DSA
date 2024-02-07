cmake_minimum_required(VERSION 3.20)
project(Dsa)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)
include(GoogleTest)

foreach(test list_test stl_list_test vector_test)
    add_executable(
        "${test}"
        "./tests/${test}.cpp"
    )
    target_link_libraries("${test}" GTest::gtest_main)
    gtest_discover_tests("${test}")
endforeach()

# include(GoogleTest)
# gtest_discover_tests(hello_test)
