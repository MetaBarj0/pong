cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(pong
  LANGUAGES CXX
  VERSION 0.0.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)

add_subdirectory(src)

enable_testing()

include(GNUInstallDirs)

include (CPack)
