include_directories(${hex-blob_SOURCE_DIR})
add_executable(sample main.cc)
target_link_libraries(sample hex_blob)

add_custom_command(
	OUTPUT valgrind.out
	COMMAND valgrind --tool=memcheck --leak-check=yes ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_EXECUTABLE_PATH}/sample
	)
add_custom_target(valgrind DEPENDS valgrind.out)
