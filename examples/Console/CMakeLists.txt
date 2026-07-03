cmake_minimum_required(VERSION 3.21)

project(QtMarstekConsole LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Network)

qt_standard_project_setup()

qt_add_executable(QtMarstekConsole
    main.cpp
)

target_link_libraries(QtMarstekConsole
    PRIVATE
        Qt6::Core
        Qt6::Network
        QtMarstek
)
