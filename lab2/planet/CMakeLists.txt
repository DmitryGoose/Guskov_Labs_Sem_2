cmake_minimum_required(VERSION 3.10)

project(PlanetLibrary)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    Planet.cpp
)

set(HEADERS
    Planet.h
)

add_library(Planet STATIC ${SOURCES} ${HEADERS})
