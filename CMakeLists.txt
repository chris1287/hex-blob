cmake_minimum_required(VERSION 2.6)

project(hex-blob)

set(CMAKE_CXX_FLAGS_COMMON "-std=c++0x -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_COMMON} -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_COMMON} -O2")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS_RELEASE})

execute_process(COMMAND git describe --tags OUTPUT_VARIABLE VERSION)
string(REGEX REPLACE "\n" "" VERSION "${VERSION}")
set( VERSION_STR \"${VERSION}\" )
message( "Got version: " ${VERSION_STR} )

add_subdirectory(sample)
add_subdirectory(hex_blob)

configure_file (${CMAKE_CURRENT_SOURCE_DIR}/hex_blob/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/hex_blob/version.h)
