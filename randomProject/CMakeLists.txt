# Указываем минимальную требуемую версию CMake
cmake_minimum_required(VERSION 3.23)

# Устанавливаем имя проекта
set(project "rand")
# Объявляем проект с указанным именем
project(${project})

# Устанавливаем стандарт C++ для компиляции
set(CMAKE_CXX_STANDARD 17)

# Добавляем директорию с заголовочными файлами в список директорий для поиска
include_directories(${CMAKE_SOURCE_DIR}/h)

# Добавляем директорию с библиотеками для линковки
link_directories(${CMAKE_SOURCE_DIR}/a)

# Определяем список исходных файлов проекта
set(${project}_SOURCES
        main.cpp)

# Создаем список исходных файлов, используя ранее определенный список
set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

# Создаем исполняемый файл из исходных файлов проекта
add_executable(${project}
        ${${project}_SOURCE_LIST})

# Линкуем библиотеку 'hohma' с исполняемым файлом проекта
target_link_libraries(${project}
        hohma)