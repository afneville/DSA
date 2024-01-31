cmake_minimum_required(VERSION 3.20)
project(Dsa)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

# enable_testing()
#
add_executable(
    hello_test
    tests/hello_test.cpp
)
target_link_libraries(
    hello_test
    GTest::gtest_main
)
#
# include(GoogleTest)
# gtest_discover_tests(hello_test)
#
# add_subdirectory(src)
#
# foreach(executable ItemTest ListTest)
#     target_link_libraries("${executable}" PUBLIC src)
#     target_include_directories("${executable}" PUBLIC "${PROJECT_SOURCE_DIR}/inc" "${PROJECT_BINARY_DIR}")
# endforeach()
