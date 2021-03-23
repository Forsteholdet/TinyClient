
### CATCH
set(TEST_NAME tests)

set(LIB_NAME ${PROJECT_NAME}_lib)

# Add testfiles here
set (TEST_FILES old/test_http_client.cpp test_macro.cpp)

#The test program
add_executable(${TEST_NAME} old/test_main.cpp ${TEST_FILES})

# Specify all Libraries to use
target_link_libraries(${TEST_NAME} PRIVATE catch ${LIB_NAME})

### UNITY
add_executable(test_tinyclient test_http_request.cpp)

target_link_libraries(test_tinyclient ${LIB_NAME})
target_link_libraries(test_tinyclient unity)

add_test(test_meh test_tinyclient)
