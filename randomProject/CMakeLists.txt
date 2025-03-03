cmake_minimum_required(VERSION 3.23)

set(project "rand")
project(${project})

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/h)

link_directories(${CMAKE_SOURCE_DIR}/a)

set(${project}_SOURCES
        main.cpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})


add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project}
        hohma)
