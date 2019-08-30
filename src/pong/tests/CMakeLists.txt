cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(pong_unit_tests LANGUAGES CXX)

add_executable(pong_unit_tests
  main.cpp)

target_include_directories(pong_unit_tests
  PRIVATE
    ../../../thirdparties/catch2)

target_link_libraries(pong_unit_tests
  pong_domain)


if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  add_custom_command(
    TARGET
      pong_unit_tests
    POST_BUILD
    COMMAND
	  ${CMAKE_COMMAND} -E copy_if_different
      $<TARGET_FILE:pong_domain>
      $<TARGET_FILE_DIR:pong_unit_tests>)
endif()
