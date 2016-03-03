cmake_minimum_required(VERSION 2.8)	 # Проверка версии CMake.
project (lab1)


list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)
list(APPEND CMAKE_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

file(GLOB_RECURSE lab1_SOURCES src/*.c src/*.h)
include_directories(AFTER ${CMAKE_SOURCE_DIR}/src/)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=c11)
endif()

add_executable(${PROJECT_NAME} ${lab1_SOURCES})
