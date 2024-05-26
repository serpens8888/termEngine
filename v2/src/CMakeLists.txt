cmake_minimum_required(VERSION 3.0)
project(termEngine)

add_executable(foo main.cpp initialize.cpp screen.cpp)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

execute_process(COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR})
