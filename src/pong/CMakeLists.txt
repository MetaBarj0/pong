cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

add_library(pong
  SHARED
  src/pong.cpp)


set_target_properties(pong
  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
	CXX_VISIBILITY_PRESET HIDDEN
)

include(GenerateExportHeader)
generate_export_header(pong)

target_include_directories(pong
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    $<TARGET_FILE_DIR:pong>)

enable_testing()

add_test(
  NAME spec_tests
  COMMAND $<TARGET_FILE:pong_spec_tests> -s
  )

add_test(
  NAME unit_tests
  COMMAND $<TARGET_FILE:pong_unit_tests>
  )

add_subdirectory(specs)
add_subdirectory(tests)
