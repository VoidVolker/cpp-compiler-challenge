# CMakeList.txt: проект CMake для Compiler; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Compiler "Compiler.cpp" "Compiler.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
