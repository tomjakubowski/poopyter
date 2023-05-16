project(poopyter)
cmake_minimum_required(VERSION 3.25)

set(CPP_LIBRARY_TYPE "SHARED" CACHE STRING "Library type to build")
set_property(CACHE CPP_LIBRARY_TYPE PROPERTY STRINGS STATIC SHARED)

if (EMSCRIPTEN)
  message(STATUS "building for emscripten")
  set(CMAKE_EXECUTABLE_SUFFIX ".html")
  set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)
  set(CMAKE_SHARED_LIBRARY_CREATE_C_FLAGS "-s SIDE_MODULE=1")
endif ()

add_executable(poopyter 
  src/main.c
)
target_compile_options(poopyter PUBLIC
  -std=c17
  -fPIC
  -Wall 
  -Wextra 
)

add_library(add5 ${CPP_LIBRARY_TYPE} src/add5.c)
add_library(mul3 ${CPP_LIBRARY_TYPE} src/mul3.c)

# target_link_libraries(poopyter add5 mul3)
if (EMSCRIPTEN)
  target_compile_definitions(poopyter PRIVATE POOPYTER_EMSCRIPTEN POOPYTER_KERNEL_SUFFIX=".so")
  target_link_options(poopyter PUBLIC 
    -sMAIN_MODULE=1 

    -sUSE_PTHREADS=1
    -sPROXY_TO_PTHREAD=1
  )
  foreach(target add5 mul3)
    target_link_options(${target} PUBLIC
      -sUSE_PTHREADS=1
    )
  endforeach ()
endif ()
