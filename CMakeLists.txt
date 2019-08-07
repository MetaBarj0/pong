cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(pong LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)

add_subdirectory(src)
add_subdirectory(src/lib)

enable_testing()
