cmake_minimum_required(VERSION 3.10)
project(lab5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)

add_executable(lab5 main.cpp)

target_link_libraries(lab5 SetLibrary)

target_include_directories(lab5 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
