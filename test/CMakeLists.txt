### UNITY
## request
add_executable(test_request request_test/test_http_request.cpp)
target_link_libraries(test_request ${LIB_NAME})
target_link_libraries(test_request unity)

add_test(request test_request)

## get
add_executable(test_get get_test/test_get_request.cpp)
target_link_libraries(test_get ${LIB_NAME})
target_link_libraries(test_get unity)

add_test(get test_get)


## post
add_executable(test_post post_test/test_post_request.cpp)
target_link_libraries(test_post ${LIB_NAME})
target_link_libraries(test_post unity)

add_test(post test_post)

## delete
add_executable(test_delete delete_test/test_delete_request.cpp)
target_link_libraries(test_delete ${LIB_NAME})
target_link_libraries(test_delete unity)

add_test(delete test_delete)

## string implementation
add_executable(test_string string_test/test_string_impl.cpp)
target_link_libraries(test_string ${LIB_NAME})
target_link_libraries(test_string unity)

add_test(string test_string)
