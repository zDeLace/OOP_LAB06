cmake_minimum_required(VERSION 3.16)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# Для MSVC отключаем предупреждения о безопасных функциях
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

file(GLOB TEST_SRC tests.cpp)

add_executable(UnitTests ${TEST_SRC})
target_include_directories(UnitTests PRIVATE ../include)

file(GLOB APP_SRC ../src/*.cpp)

target_link_libraries(UnitTests
    gtest
    gtest_main
)

# Чтобы тесты видели исходники проекта
target_sources(UnitTests PRIVATE ${APP_SRC})
