cmake_minimum_required(VERSION 3.10)
project(lab5)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем библиотеку
add_subdirectory(lib)

# Добавляем исполняемый файл
add_executable(lab5 main.cpp)

# Линкуем библиотеку к исполняемому файлу
target_link_libraries(lab5 SetLibrary)

# Добавляем путь к заголовочным файлам
target_include_directories(lab5 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)