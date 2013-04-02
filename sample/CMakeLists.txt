add_executable(sample main.cc)

include_directories(${hex-blob_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Wextra -Werror")
