cmake_minimum_required(VERSION 3.16)
project(RPGEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_subdirectory(tests)

file(GLOB SRC_FILES src/*.cpp)

add_executable(RPG main.cpp ${SRC_FILES})
