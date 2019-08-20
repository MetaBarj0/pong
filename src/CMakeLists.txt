cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	add_executable(game
	  WIN32)

  add_custom_command(
    TARGET
      game
    POST_BUILD
    COMMAND
	  ${CMAKE_COMMAND} -E copy_if_different
  	  "${SDL2_LIB_DIR}/SDL2.dll"
  	  $<TARGET_FILE_DIR:game>)

else()
	add_executable(game)
endif()

target_sources(game
  PRIVATE
  main.cpp)

set_target_properties(game
  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(game
  PRIVATE
    ${SDL2_INCLUDE_DIR}
  )

target_link_libraries(game
  PRIVATE
    ${SDL2MAIN_LIB}
    ${SDL2_LIB})

add_subdirectory(pong)

enable_testing()

install(TARGETS
  game
  RUNTIME
    DESTINATION ${INSTALL_BINDIR}
    COMPONENT bin)

install(FILES
  "${SDL2_LIB_DIR}/SDL2.dll"
  TYPE BIN)
