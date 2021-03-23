# Variables
set(SOURCES constants.h http_request.cpp http_request.h fake_socket.cpp fake_socket.h t_socket.cpp t_socket.h response/response.cpp response/response.h macro/macro_defs.h internals/TCstring.h)
set(LIB_NAME ${PROJECT_NAME}_lib)



# Preparing files so they can be found in the test project
add_library(${LIB_NAME} STATIC ${SOURCES})
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})



# Specify all Libraries to use
## json bourne
##target_link_libraries(${LIB_NAME} bourne)

## json bourne
include(FetchContent)

FetchContent_Declare(
        bourne
        GIT_REPOSITORY https://github.com/steinwurf/bourne.git
        GIT_TAG        9.0.0
)
FetchContent_MakeAvailable(bourne)

target_link_libraries(${LIB_NAME} bourne)





