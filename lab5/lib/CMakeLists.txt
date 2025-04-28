cmake_minimum_required(VERSION 3.10)
project(SetLibrary)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(SetLibrary INTERFACE)

target_include_directories(SetLibrary INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
