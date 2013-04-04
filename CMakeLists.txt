cmake_minimum_required(VERSION 2.6)

project(hex-blob)

# Compiler flags definition
set(CMAKE_CXX_FLAGS_COMMON "-std=c++0x -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_COMMON} -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_COMMON} -O2")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS_RELEASE})

# GIT tag based versioning
execute_process(COMMAND git describe --tags OUTPUT_VARIABLE VERSION)
string(REGEX REPLACE "\n" "" VERSION "${VERSION}")
set( VERSION_STR \"${VERSION}\" )
message( "Got version: " ${VERSION_STR} )
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/hex_blob/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/hex_blob/version.h)

# Google test framework (built from source)
include(ExternalProject)
set(THIRD_PARTY_DIR ${CMAKE_BINARY_DIR})
ExternalProject_Add(
  GoogleTest
  PREFIX  ${CMAKE_BINARY_DIR}/GoogleTest
  DOWNLOAD_DIR ${THIRD_PARTY_DIR}/GoogleTest
  URL http://googletest.googlecode.com/files/gtest-1.6.0.zip
  URL_MD5 4577b49f2973c90bf9ba69aa8166b786
  CMAKE_ARGS 	-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY:PATH=${THIRD_PARTY_DIR}/libs/gtest
        -DCMAKE_LIBRARY_OUTPUT_DIRECTORY:PATH=${THIRD_PARTY_DIR}/libs/gtest
        -DCMAKE_TOOLCHAIN_FILE:PATH=${CMAKE_TOOLCHAIN_FILE}
        -DCMAKE_C_FLAGS:STRING=${CMAKE_C_FLAGS}
        -DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
  INSTALL_COMMAND ""
)
SET(GTEST_DIR "${CMAKE_BINARY_DIR}/GoogleTest/src/GoogleTest")
SET(GTEST_INCLUDE_DIR "${GTEST_DIR}/include")
SET(GTEST_LIB_DIR "${THIRD_PARTY_DIR}/libs/gtest")

# Testing
enable_testing()

# Subdirectories 
add_subdirectory(sample)
add_subdirectory(hex_blob)
add_subdirectory(test)

# Custom command - cpplint
file(
  GLOB_RECURSE ALL_SRC 
  sample/*.cc 
  sample/*.h
  hex_blob/*.cc
  hex_blob/*/h
  test/*.cc
  test/*.h)
set(CPPLINT_CMD /opt/cpplint.py)
foreach(SRC_FILE ${ALL_SRC})
  add_custom_command(
    OUTPUT  ${SRC_FILE}.out
    COMMAND ${CPPLINT_CMD} ${SRC_FILE}
    )
  list(APPEND cpplint_out_files ${SRC_FILE}.out)
endforeach()
add_custom_target(cpplint DEPENDS ${cpplint_out_files})

# Custom command - cppcheck
set(CPPCHECK_CMD cppcheck --enable=all --error-exitcode=1 -i${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(
  OUTPUT  cppcheck.out
  COMMAND ${CPPCHECK_CMD} ${PROJECT_SOURCE_DIR}
)
add_custom_target(cppcheck DEPENDS cppcheck.out)
