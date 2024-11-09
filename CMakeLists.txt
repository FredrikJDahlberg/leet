cmake_minimum_required(VERSION 3.29)
project(leet)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src/test/gtest-lib)
include_directories(src/test/gtest-lib/googletest/include src/test/gtest-lib/googletest)

add_executable(parser src/main/parser/Parser.cpp src/main/parser/Parser.h
        src/main/parser/ParserApp.cpp)

add_executable(leet src/main/leet/main.cpp src/main/leet/Print.h
        src/main/leet/Solution25.h
        src/main/leet/Solution224.h
        src/main/leet/Solution62.h)

add_executable(queue src/main/concurrency/QueueApp.cpp src/main/concurrency/BlockingQueue.h)

add_executable(test src/test/leet/LeetTest.cpp src/main/leet/Solution20.h src/main/leet/Solution25.h
        src/main/leet/Solution2302.h)
target_link_libraries(test gtest gtest_main)
