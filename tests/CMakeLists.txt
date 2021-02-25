set(TEST_NAME tests)

set(LIB_NAME ${PROJECT_NAME}_lib)

# Add testfiles here
set (TEST_FILES test_client.cpp test_http_client.cpp)

#The test program
add_executable(${TEST_NAME} test_main.cpp ${TEST_FILES})

# Specify all Libraries to use
target_link_libraries(${TEST_NAME} PRIVATE catch ${LIB_NAME})
