add_executable(test01 test01.cc)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})
target_link_libraries(test01 ${GTEST_BOTH_LIBRARIES} pthread)

include_directories(${hex-blob_SOURCE_DIR})
target_link_libraries(test01 hex_blob)

add_test(test01 test01)

