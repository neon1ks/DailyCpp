cmake_minimum_required(VERSION 3.5)

project(2023_03_07_rebind LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(2023_03_07_rebind main.cpp)

install(TARGETS 2023_03_07_rebind
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
