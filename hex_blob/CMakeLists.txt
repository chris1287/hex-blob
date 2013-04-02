set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Wextra -Werror")
include_directories(${hex-blob_SOURCE_DIR})
add_library(hex_blob hex_blob.cc)
