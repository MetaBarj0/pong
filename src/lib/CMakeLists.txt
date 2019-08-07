cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

add_library(sum_up
  SHARED
  sum_integers.cpp)


set_target_properties(sum_up
  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
	CXX_VISIBILITY_PRESET HIDDEN
)

include(GenerateExportHeader)
generate_export_header(sum_up)

target_include_directories(sum_up
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    $<TARGET_FILE_DIR:sum_up>)

add_subdirectory(specs)
add_subdirectory(tests)

enable_testing()

add_test(
  NAME spec_tests
  COMMAND $<TARGET_FILE:sum_up_spec_tests> -s
  )

add_test(
  NAME unit_tests
  COMMAND $<TARGET_FILE:sum_up_unit_tests>
  )
