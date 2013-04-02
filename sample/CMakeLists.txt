include_directories(${hex-blob_SOURCE_DIR})
add_executable(sample main.cc)
target_link_libraries(sample hex_blob)
