
### CATCH
set(TEST_NAME tests)

set(LIB_NAME ${PROJECT_NAME}_lib)

# Add testfiles here
set (TEST_FILES old/test_http_client.cpp)

#The test program
add_executable(${TEST_NAME} old/test_main.cpp ${TEST_FILES})

# Specify all Libraries to use
target_link_libraries(${TEST_NAME} PRIVATE catch ${LIB_NAME})

### UNITY
## request
add_executable(test_request test_http_request.cpp)
target_link_libraries(test_request ${LIB_NAME})
target_link_libraries(test_request unity)

add_test(request test_request)

## get
add_executable(test_get requests/test_get_request.cpp)
target_link_libraries(test_get ${LIB_NAME})
target_link_libraries(test_get unity)

add_test(get test_get)

