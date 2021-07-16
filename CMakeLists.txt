# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("Compiler")

# Включите подпроекты.
add_subdirectory ("Compiler")

set_property (TARGET "Compiler"
  PROPERTY
    # Enable C++17 standard compliance
    CXX_STANDARD 20
)