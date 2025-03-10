cmake_minimum_required(VERSION 3.10)

project(CandidateLibrary)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    Candidate.cpp
)

set(HEADERS
    Candidate.h
)

add_library(Candidate STATIC ${SOURCES} ${HEADERS})
