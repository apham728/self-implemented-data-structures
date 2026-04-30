cmake_minimum_required(VERSION 3.14)

project(data_structures CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRC_FILES_EXCEPT_MAIN
    src/List.cpp
)

add_executable(benchmarks
    ${SRC_FILES_EXCEPT_MAIN}
    src/main.cpp
)

target_include_directories(benchmarks PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

find_package(GTest REQUIRED)

enable_testing()
include(GoogleTest)

set(TEST_FILES
    tests/test_list.cpp
)

foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    add_executable(${TEST_NAME}
        ${SRC_FILES_EXCEPT_MAIN}
        ${TEST_FILE}
    )

    target_include_directories(${TEST_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/src
    )

    target_link_libraries(${TEST_NAME} PRIVATE
        GTest::gtest
        GTest::gtest_main
    )

    gtest_discover_tests(${TEST_NAME})
endforeach()
