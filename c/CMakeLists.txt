cmake_minimum_required(VERSION 3.20)
project(List LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(ItemTest "run/item_test.c")
add_executable(ListTest "run/list_test.c")
add_subdirectory(src)

foreach(executable ItemTest ListTest)
    target_link_libraries("${executable}" PUBLIC src)
    target_include_directories("${executable}" PUBLIC "${PROJECT_SOURCE_DIR}/inc" "${PROJECT_BINARY_DIR}")
endforeach()
