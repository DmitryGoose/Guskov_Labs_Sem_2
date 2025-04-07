cmake_minimum_required(VERSION 3.10)
project(SetLibrary)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем INTERFACE библиотеку вместо STATIC
add_library(SetLibrary INTERFACE)

# Устанавливаем заголовочные файлы для экспорта
target_include_directories(SetLibrary INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)