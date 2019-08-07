cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(sum_up_spec_tests LANGUAGES CXX)

add_executable(sum_up_spec_tests
  main.cpp)

target_include_directories(sum_up_spec_tests
  PRIVATE
    ../../../thirdparties/catch2)

target_link_libraries(sum_up_spec_tests
  sum_up)


if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  add_custom_command(
    TARGET
      sum_up_spec_tests
    POST_BUILD
    COMMAND
	  ${CMAKE_COMMAND} -E copy_if_different
  	  $<TARGET_FILE_DIR:sum_up>/sum_up.dll
      $<TARGET_FILE_DIR:sum_up_spec_tests>)
endif()
