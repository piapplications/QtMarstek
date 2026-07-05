cmake_minimum_required(VERSION 3.21)

project(QtMarstek
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Network
    Test
)

qt_standard_project_setup()

enable_testing()

add_subdirectory(src)
add_subdirectory(examples/Console)
add_subdirectory(tests)
