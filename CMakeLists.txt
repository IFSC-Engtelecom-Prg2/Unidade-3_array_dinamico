cmake_minimum_required(VERSION 3.21)
project(vetor_dinamico)

set(CMAKE_CXX_STANDARD 14)

add_executable(vetor main.cpp vetor.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)
include_directories(googletest/include googletest .)
add_executable(runTest  runTest.cpp vetor.cpp)
target_link_libraries(runTest gtest gtest_main)