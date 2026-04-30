cmake_minimum_required(VERSION 4.3.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRC_FILES_EXCEPT_MAIN
	src/List.h
	src/List.cpp
)

project(hw CXX)

add_executable(${PROJECT_NAME} ${SRC_FILES_EXCEPT_MAIN} src/main.cpp)

find_package(GTest)
if (GTest_FOUND)
    project(hw_gtests CXX)

    
    set(GTEST_FILES
        tests/test_list.cpp
    )

    include_directories(${GTEST_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} ${SRC_FILES_EXCEPT_MAIN} ${GTEST_FILES})
    
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
    target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})
endif()

