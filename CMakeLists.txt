cmake_minimum_required(VERSION 2.6)

project(hex-blob)

add_subdirectory(sample)

execute_process(COMMAND git describe --tags OUTPUT_VARIABLE VERSION)
string(REGEX REPLACE "\n" "" VERSION "${VERSION}")
set( VERSION_STR \"${VERSION}\" )
message( "Got version: " ${VERSION_STR} )

configure_file (${CMAKE_CURRENT_SOURCE_DIR}/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/version.h)
