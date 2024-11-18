cmake_minimum_required(VERSION 3.29)
project(leet)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src/test/gtest-lib)
include_directories(src/test/gtest-lib/googletest/include src/test/gtest-lib/googletest)

add_executable(parser
        src/main/parser/Parser.cpp src/main/parser/Parser.h
        src/main/parser/ParserApp.cpp)

add_executable(leet src/main/leet/main.cpp src/main/leet/Print.h
        src/main/leet/Solution40.h
        src/main/leet/Solution63.h
        src/main/leet/Solution980.h
        src/main/leet/Solution1050.h
        src/main/leet/Solution410.h
        src/main/leet/Solution2547.h
        src/main/leet/Solution722.h
        src/main/leet/Solution208.h
        src/main/leet/Solution725.h
        src/main/leet/Solution61.h
        src/test/leet/LeetTest.cpp
        src/main/leet/Solution12.h
        src/main/leet/Solution17.h
        src/main/leet/Solution20.h
        src/main/leet/Solution22.h
        src/main/leet/Solution25.h
        src/main/leet/Solution26.h
        src/main/leet/Solution27.h
        src/main/leet/Solution36.h
        src/main/leet/Solution39.h
        src/main/leet/Solution62.h
        src/main/leet/Solution69.h
        src/main/leet/Solution80.h
        src/main/leet/Solution88.h
        src/main/leet/Solution135.h
        src/main/leet/Solution146.h
        src/main/leet/Solution188.h
        src/main/leet/Solution224.h
        src/main/leet/Solution1116.h
        src/main/leet/Solution2302.h
        src/main/leet/Solution53.h
        src/main/leet/Solution2546.h
        src/main/leet/Solution930.h
        src/main/leet/Solution5.h
        src/main/leet/Solution214.h
        src/main/leet/Solution396.h
        src/main/leet/Solution724.h
        src/main/leet/Solution720.h
        src/main/leet/Solution676.h
        src/main/leet/Solution127.h
        src/main/leet/Solution124.h
        src/main/leet/Solution65.h
        src/main/leet/Solution154.h
        src/main/leet/Solution239.h
        src/main/leet/Solution295.h
        src/main/leet/Solution1044.h
)

add_executable(coroutine
        src/main/concurrency/Generator.cpp
        src/main/concurrency/Generator.h)

add_executable(queue
        src/main/concurrency/QueueApp.cpp src/main/concurrency/BlockingQueue.h)

add_executable(test
        src/main/leet/Solution40.h
        src/main/leet/Solution63.h
        src/main/leet/Solution980.h
        src/main/leet/Solution1050.h
        src/main/leet/Solution410.h
        src/main/leet/Solution2547.h
        src/main/leet/Solution722.h
        src/main/leet/Solution208.h
        src/main/leet/Solution725.h
        src/main/leet/Solution61.h
        src/test/leet/LeetTest.cpp
        src/main/leet/Solution12.h
        src/main/leet/Solution17.h
        src/main/leet/Solution20.h
        src/main/leet/Solution22.h
        src/main/leet/Solution25.h
        src/main/leet/Solution26.h
        src/main/leet/Solution27.h
        src/main/leet/Solution36.h
        src/main/leet/Solution39.h
        src/main/leet/Solution62.h
        src/main/leet/Solution69.h
        src/main/leet/Solution80.h
        src/main/leet/Solution88.h
        src/main/leet/Solution135.h
        src/main/leet/Solution146.h
        src/main/leet/Solution188.h
        src/main/leet/Solution224.h
        src/main/leet/Solution1116.h
        src/main/leet/Solution2302.h
        src/main/leet/Solution53.h
        src/main/leet/Solution2546.h
        src/main/leet/Solution930.h
        src/main/leet/Solution5.h
        src/main/leet/Solution214.h
        src/main/leet/Solution396.h
        src/main/leet/Solution724.h
        src/main/leet/Solution720.h
        src/main/leet/Solution676.h
        src/main/leet/Solution127.h
        src/main/leet/Solution124.h
        src/main/leet/Solution65.h
        src/main/leet/Solution239.h
        src/main/leet/Solution154.h
        src/main/leet/Solution295.h
        src/main/leet/Solution1044.h
)
target_link_libraries(test gtest gtest_main)
