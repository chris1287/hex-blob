include_directories(${hex-blob_SOURCE_DIR})
add_library(hex_blob SHARED hex_blob.cc)
set_target_properties(hex_blob PROPERTIES VERSION ${VERSION})
