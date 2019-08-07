cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	add_executable(pong
	  WIN32
	  main.cpp
	  game.cpp)

  add_custom_command(
    TARGET
      pong
    POST_BUILD
    COMMAND
	  ${CMAKE_COMMAND} -E copy_if_different
  	  "${SDL2_LIB_DIR}/SDL2.dll"
  	  $<TARGET_FILE_DIR:pong>)

else()
	add_executable(pong
	  main.cpp
	  game.cpp)
endif()

set_target_properties(pong
  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(pong
  PRIVATE
    ${SDL2_INCLUDE_DIR}
  )

target_link_libraries(pong
  PRIVATE
    ${SDL2MAIN_LIB}
    ${SDL2_LIB})

enable_testing()