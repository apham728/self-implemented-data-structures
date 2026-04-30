cmake_minimum_required(VERSION 3.14)

project(hw CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRC_FILES_EXCEPT_MAIN
    src/List.cpp
)

add_executable(hw
    ${SRC_FILES_EXCEPT_MAIN}
    src/main.cpp
)

target_include_directories(hw PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

find_package(GTest REQUIRED)

add_executable(hw_gtests
    ${SRC_FILES_EXCEPT_MAIN}
    tests/test_list.cpp
)

target_include_directories(hw_gtests PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(hw_gtests PRIVATE
    GTest::gtest
    GTest::gtest_main
)

enable_testing()

include(GoogleTest)
gtest_discover_tests(hw_gtests)
