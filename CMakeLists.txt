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
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/hex_blob/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/hex_blob/version.h)

add_subdirectory(sample)
add_subdirectory(hex_blob)

file(GLOB_RECURSE ALL_SRC *.cc *.h)
set(CPPLINT_CMD /opt/cpplint.py)
foreach(SRC_FILE ${ALL_SRC})
  add_custom_command(
    OUTPUT  ${SRC_FILE}.out
    COMMAND ${CPPLINT_CMD} ${SRC_FILE}
    )
  list(APPEND cpplint_out_files ${SRC_FILE}.out)
endforeach()
add_custom_target(cpplint DEPENDS ${cpplint_out_files})
