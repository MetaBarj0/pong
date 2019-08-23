cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

add_library(pong
  SHARED
  src/game.cpp
  src/playground.cpp
  src/wall.cpp
  src/paddle.cpp)


set_target_properties(pong
  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
	CXX_VISIBILITY_PRESET HIDDEN
	POSITION_INDEPENDENT_CODE 1
	SOVERSION ${PROJECT_VERSION_MAJOR}
	OUTPUT_NAME "libpong"
	DEBUG_POSTFIX "_d"
)

include(GenerateExportHeader)
generate_export_header(pong)

target_include_directories(pong
  PUBLIC
    src
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

install(TARGETS
  pong
  ARCHIVE
    DESTINATION ${INSTALL_LIBDIR}
    COMPONENT lib
  RUNTIME
    DESTINATION ${INSTALL_BINDIR}
    COMPONENT bin
  LIBRARY
    DESTINATION ${INSTALL_LIBDIR}
    COMPONENT lib
  PUBLIC_HEADER
    DESTINATION ${INSTALL_INCLUDEDIR}/pong
    COMPONENT dev)
