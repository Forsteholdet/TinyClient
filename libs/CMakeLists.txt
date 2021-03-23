## Catch testing framework
add_subdirectory(catch)

include(FetchContent)
# This particular version of projD requires workarounds
FetchContent_Declare(
        unity
        GIT_REPOSITORY git@github.com:ThrowTheSwitch/Unity.git
)
FetchContent_GetProperties(unity)
if(NOT unity_POPULATED)
    FetchContent_Populate(unity)

    add_library(unity STATIC  ${unity_SOURCE_DIR}/src/unity.c)
    target_include_directories(unity PUBLIC ${unity_SOURCE_DIR}/src)
endif()