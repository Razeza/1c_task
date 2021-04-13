project(1c_task)

cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(
        -Wfatal-errors
        -Wall -Wextra
)

OPTION(TEST "Test Option" OFF)

if (TEST)
    ADD_DEFINITIONS(-DTEST)
endif (TEST)

set(SOURCES src/main.cpp)
# set(TEST_DIR ${1c-submission_SOURCE_DIR}/test)


add_executable(
        solution
        ${SOURCES}
)
