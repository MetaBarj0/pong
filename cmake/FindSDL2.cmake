if(NOT SDL2_ROOT)
  set(SDL2_ROOT "$ENV{SDL2_ROOT}")
endif()

find_path(_SDL2_ROOT NAMES include/SDL.h HINTS ${SDL2_ROOT})
find_path(SDL2_INCLUDE_DIR NAMES SDL.h HINTS ${_SDL2_ROOT}/include)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(SDL2_LIB_DIR_SUFFIX "x64")
  else()
    set(SDL2_LIB_DIR_SUFFIX "x86")
  endif()

  find_path(SDL2_LIB_DIR NAMES SDL2.dll HINTS ${_SDL2_ROOT}/lib/${SDL2_LIB_DIR_SUFFIX})

  find_library(SDL2_LIB NAMES SDL2 HINTS ${_SDL2_ROOT}/lib/x64)
  find_library(SDL2MAIN_LIB NAMES SDL2MAIN HINTS ${_SDL2_ROOT}/lib/x64)
else()
  find_library(SDL2_LIB NAMES SDL2 HINTS ${_SDL2_ROOT}/lib)
  find_library(SDL2MAIN_LIB NAMES SDL2MAIN HINTS ${_SDL2_ROOT}/lib)
endif()
