cmake_minimum_required(VERSION 3.1)

project(Infinet_tests)

# Добавляем googletest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.c")

add_executable(Infinet_tests tests/test_func_c.cpp)

# Линкуем с googletest
target_link_libraries(Infinet_tests ${GTEST_LIBRARIES} pthread)

enable_testing()
add_test(NAME FuncOkTest COMMAND FuncOkTest)