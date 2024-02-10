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

foreach(test_suite list_tests stl_sequence_container_tests vector_tests)
    add_executable(
        "${test_suite}"
        "./tests/${test_suite}.cpp"
    )
    target_link_libraries("${test_suite}" GTest::gtest_main)
    gtest_discover_tests("${test_suite}")
endforeach()
