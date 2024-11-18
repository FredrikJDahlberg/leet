cmake_minimum_required(VERSION 3.29)
project(leet)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src/test/gtest-lib)
include_directories(src/test/gtest-lib/googletest/include src/test/gtest-lib/googletest)

add_executable(test
        src/test/cpp/leet/LeetTest.cpp
        src/main/cpp/leet/Solution40.h
        src/main/cpp/leet/Solution63.h
        src/main/cpp/leet/Solution980.h
        src/main/cpp/leet/Solution1050.h
        src/main/cpp/leet/Solution410.h
        src/main/cpp/leet/Solution2547.h
        src/main/cpp/leet/Solution722.h
        src/main/cpp/leet/Solution208.h
        src/main/cpp/leet/Solution725.h
        src/main/cpp/leet/Solution61.h
        src/main/cpp/leet/Solution12.h
        src/main/cpp/leet/Solution17.h
        src/main/cpp/leet/Solution20.h
        src/main/cpp/leet/Solution22.h
        src/main/cpp/leet/Solution25.h
        src/main/cpp/leet/Solution26.h
        src/main/cpp/leet/Solution27.h
        src/main/cpp/leet/Solution36.h
        src/main/cpp/leet/Solution39.h
        src/main/cpp/leet/Solution62.h
        src/main/cpp/leet/Solution69.h
        src/main/cpp/leet/Solution80.h
        src/main/cpp/leet/Solution88.h
        src/main/cpp/leet/Solution135.h
        src/main/cpp/leet/Solution146.h
        src/main/cpp/leet/Solution188.h
        src/main/cpp/leet/Solution224.h
        src/main/cpp/leet/Solution1116.h
        src/main/cpp/leet/Solution2302.h
        src/main/cpp/leet/Solution53.h
        src/main/cpp/leet/Solution2546.h
        src/main/cpp/leet/Solution930.h
        src/main/cpp/leet/Solution5.h
        src/main/cpp/leet/Solution214.h
        src/main/cpp/leet/Solution396.h
        src/main/cpp/leet/Solution724.h
        src/main/cpp/leet/Solution720.h
        src/main/cpp/leet/Solution676.h
        src/main/cpp/leet/Solution127.h
        src/main/cpp/leet/Solution124.h
        src/main/cpp/leet/Solution65.h
        src/main/cpp/leet/Solution239.h
        src/main/cpp/leet/Solution154.h
        src/main/cpp/leet/Solution295.h
        src/main/cpp/leet/Solution1044.h
        src/main/cpp/leet/Solution1289.h
        src/main/cpp/leet/Solution931.h
)
target_link_libraries(test gtest gtest_main)
