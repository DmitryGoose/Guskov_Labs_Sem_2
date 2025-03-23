add_library(mystack STATIC Stack.cpp Stack.h)

target_include_directories(mystack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})