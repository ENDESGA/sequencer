cmake_minimum_required(VERSION 3.10)

set(CMAKE_SUPPRESS_REGENERATION TRUE)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native")

set(PROJECT_NAME "sequencer" CACHE STRING "PROJECT_NAME")
set(SOURCES "src/main.c" CACHE STRING "SOURCES")
set(INCLUDE "inc/")

project(${PROJECT_NAME} C)

IF (WIN32)
    include_directories(${INCLUDE})
    link_directories(${INCLUDE})
    add_executable(${PROJECT_NAME} ${SOURCES})
    target_link_libraries(${PROJECT_NAME} SDL3 )
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".exe")
ELSEIF (UNIX)
    add_executable(${PROJECT_NAME} ${SOURCES})
    target_link_libraries(${PROJECT_NAME} SDL3 )
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".bin")
ENDIF ()
