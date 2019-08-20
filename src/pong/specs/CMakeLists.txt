cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(pong_spec_tests LANGUAGES CXX)

add_executable(pong_spec_tests
  main.cpp)

target_include_directories(pong_spec_tests
  PRIVATE
    ../../../thirdparties/catch2)

target_link_libraries(pong_spec_tests
  pong)


if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  add_custom_command(
    TARGET
      pong_spec_tests
    POST_BUILD
    COMMAND
	  ${CMAKE_COMMAND} -E copy_if_different
      $<TARGET_FILE:pong>
      $<TARGET_FILE_DIR:pong_spec_tests>)
endif()
