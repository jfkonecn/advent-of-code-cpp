cmake_minimum_required(VERSION 3.12)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

add_subdirectory(extern)
add_subdirectory(src)
add_subdirectory(tests)

