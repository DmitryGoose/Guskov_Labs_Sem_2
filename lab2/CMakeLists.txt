cmake_minimum_required(VERSION 3.10)

project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(planet)
add_subdirectory(candidate)

add_executable(lab2 main.cpp)

target_link_libraries(lab2 Planet Candidate)

target_include_directories(lab2 PRIVATE planet candidate)
