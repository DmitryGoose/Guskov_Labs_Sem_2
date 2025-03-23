cmake_minimum_required(VERSION 3.10)
project(lab4)

set(CMAKE_CXX_STANDARD 11)

include_directories(stack)

add_subdirectory(stack)

add_executable(lab4 main.cpp)

target_link_libraries(lab4 mystack)