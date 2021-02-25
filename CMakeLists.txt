cmake_minimum_required(VERSION 3.17)
project(tiny_client)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(thirdpatry/catch)
# add_subdirectory(thirdpatry/bourne)
add_subdirectory(src)
add_subdirectory(tests)
