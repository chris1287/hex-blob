add_executable(test01 test01.cc)

include_directories(${GTEST_INCLUDE_DIR})
target_link_libraries(test01 ${GTEST_LIB_DIR}/libgtest.a pthread)

include_directories(${hex-blob_SOURCE_DIR})
target_link_libraries(test01 hex_blob)

add_test(test01 test01 "--gtest_output=xml:report.xml")

