//
// Created by Fredrik Dahlberg on 2024-10-11.
//


#include <iostream>
#include <thread>
#include <gtest/gtest.h>

#include "../../main/leet/Print.h"
#include "../../main/leet/Solution12.h"
#include "../../main/leet/Solution17.h"
#include "../../main/leet/Solution20.h"
#include "../../main/leet/Solution22.h"
#include "../../main/leet/Solution25.h"
#include "../../main/leet/Solution26.h"
#include "../../main/leet/Solution27.h"
#include "../../main/leet/Solution36.h"
#include "../../main/leet/Solution39.h"
#include "../../main/leet/Solution60.h"
#include "../../main/leet/Solution62.h"
#include "../../main/leet/Solution69.h"
#include "../../main/leet/Solution80.h"
#include "../../main/leet/Solution88.h"
#include "../../main/leet/Solution123.h"
#include "../../main/leet/Solution135.h"
#include "../../main/leet/Solution146.h"
#include "../../main/leet/Solution188.h"
#include "../../main/leet/Solution224.h"
#include "../../main/leet/Solution1116.h"
#include "../../main/leet/Solution2302.h"

TEST(Leet, Solution2302)
{
    ASSERT_EQ(5, Solution2302::countSubArrays(std::vector<int>{1,0,1,0,1}, 2));
}

TEST(Leet, Solution20)
{
    Solution20 s;
    ASSERT_TRUE(s.isValid("()[]{}"));
    ASSERT_FALSE(s.isValid("(]"));
    ASSERT_FALSE(s.isValid("([]))"));
}

TEST(Leet, Solution25)
{
    Solution25 solution25{1,2,3,4,5};

    auto* rev1 = solution25.reverse(4);
    int p = 0;
    //int expected[] = {5,4,3,2,1};
    for (auto node = rev1; node != nullptr; node = node->next)
    {
      //  ASSERT_EQ(expected[p++], rev1->val);
        std::cout << "val = " << node->val << std::endl;
    }
}

TEST(Leet, Solution224)
{
    Solution224 calculator;
    ASSERT_EQ(2, calculator.calculate("1 + 1"));
    ASSERT_EQ(1, calculator.calculate("(1)"));
    EXPECT_THROW(calculator.calculate("1+(5-2"), std::invalid_argument);
    ASSERT_EQ(23, calculator.calculate("(1+(4+5+2)-3)+(6+8)"));
    ASSERT_EQ(6, calculator.calculate("1 + 2 + 3"));
    ASSERT_EQ(10, calculator.calculate("(1 + (2 + 3 + 4))"));
    EXPECT_THROW(calculator.calculate("(1 + (2 + 3 + 4)"), std::invalid_argument);
}

TEST(Leet, Solution62)
{
    ASSERT_EQ(1, Solution62::uniquePaths(0, 0));
    ASSERT_EQ(3, Solution62::uniquePaths(3, 2));
    ASSERT_EQ(28, Solution62::uniquePaths(3, 7));
}

TEST(Leet, Solution60)
{
    ASSERT_EQ("213", Solution60::getPermutation(3, 2));
}

TEST(Leet, Solution123)
{
    ASSERT_EQ(7, Solution123::maxProfit({1,4,2,2,6}));
    ASSERT_EQ(10, Solution123::maxProfit({1,4,2,2,6,3,1,6}));
}

TEST(Leet, Solution188)
{
    std::vector v = {1,2,3,4};
    for (auto i = v.rbegin(); i != v.rend() - 1; ++i)
    {
        std::cout << *i << " " << *(i + 1) << std::endl;
    }

    ASSERT_EQ(7, Solution188::maxProfit(2, {1,4,2,2,6}));
    ASSERT_EQ(10, Solution188::maxProfit(2, {1,4,2,2,6,3,1,6}));
    ASSERT_EQ(11, Solution188::maxProfit(3, {1,4,2,2,5,3,1,6}));
}

TEST(Leet, Solution26)
{
    std::vector v1 = {1,1,2};
    ASSERT_EQ(2, Solution26::removeDuplicates(v1));
    ASSERT_EQ(2, Solution26::removeDuplicates2(v1));
    std::vector v2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
//    ASSERT_EQ(5, Solution26::removeDuplicates(v2));
    ASSERT_EQ(5, Solution26::removeDuplicates2(v2));
}

TEST(Leet, Solution27)
{
    std::vector<int> v = {0, 1, 2, 2, 3, 0, 4, 2};
    ASSERT_EQ(5, Solution27::removeElement(v, 2));
}

TEST(Leet, Solution69)
{
    std::vector nums{3, 2, 3};
    ASSERT_EQ(3, Solution69::majorityElement(nums));
    ASSERT_EQ(3, Solution69::majorityElement2(nums));
}

TEST(Leet, Solution80)
{
    // 1 1 2 2 3
    int values1[] = {1, 1, 1, 2, 2, 3};
    ASSERT_EQ(2, Solution80::removeDuplicates(values1, 6));

    std::vector values2 = {1, 1, 1, 2, 2, 3};
    ASSERT_EQ(3, Solution80::removeDuplicates2(values2));
}

TEST(Leet, Solution88)
{
    std::vector nums1 = {1, 2, 3, 0, 0, 0};
    std::vector nums2 = {2, 5, 6};
    Solution88::merge(nums1, 3, nums2, 3);
    std::vector res = std::vector<int>{1, 2, 2, 3, 5, 6};
    ASSERT_EQ(nums1, res);

    // FIXME
    std::vector nums3 = {1};
    std::vector<int> nums4;
    Solution88::merge(nums3, 1, nums4, 0);

    std::vector<int> nums5 = {0};
    std::vector<int> nums6 = {1};
    Solution88::merge(nums5, 0, nums6, 1);
}

TEST(Leet, Solution135)
{
    constexpr int ratings1[3] = {1, 0, 2};
    ASSERT_EQ(5, Solution135::candy(ratings1, 3));

    constexpr int ratings2[3] = {1, 2, 2};
    ASSERT_EQ(4, Solution135::candy(ratings2, 3));
}

TEST(Leet, Solution1116)
{
    auto print = [](int number) {
        std::cout << number << std::endl;
    };

    // FIXME
    ZeroEvenOdd zeo{5};
    std::thread thread0([&]() { zeo.zero(print); });
    std::thread thread1([&]() { zeo.odd(print); });
    std::thread thread2([&]() { zeo.even(print); });
    thread0.join();
    thread1.join();
    thread2.join();
}

TEST(Leet, Solution36)
{
    std::vector<std::vector<char>> board1 =
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    ASSERT_TRUE(Solution36::isValidSudoku(board1));

    std::vector<std::vector<char>> board2 =
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','5','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    ASSERT_TRUE(Solution36::isValidSudoku(board2));
}

TEST(Leet, Solution146)
{
    auto cache = Solution146::LRUCache(2);
    cache.put(1, 1); // cache is {1=1}
    cache.put(2, 2); // cache is {1=1, 2=2}
    ASSERT_EQ(1, cache.get(1));    // return 1
    cache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cache.get(2);    // returns -1 (not found)
    cache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    ASSERT_EQ(-1, cache.get(1));    // return -1 (not found)
    ASSERT_EQ(3, cache.get(3));    // return 3
    ASSERT_EQ(4, cache.get(4));    // return 4
}

TEST(Leet, Solution12)
{
    ASSERT_EQ("MMMDCCXLIX", Solution12::intToRoman(3749));
    ASSERT_EQ("LVIII", Solution12::intToRoman(58));
    ASSERT_EQ("MCMXCIV", Solution12::intToRoman(1994));
    ASSERT_EQ("IX", Solution12::intToRoman(9));
}

TEST(Leet, Solution22)
{
    // FIXME
    std::vector<std::string> result = { "()" };
    Solution22::generate(3, result);
    std::cout <<  result << std::endl;
}

TEST(Leet, Solution17)
{
    // FIXME
    Solution17 solution;
    const auto result = solution.letterCombinations("235");
    std::cout << result << std::endl;
}

TEST(Leet, Solution39)
{
    // FIXME
    const auto results1 = Solution39::combinationSum({ 2, 3, 6, 7 }, 7);
    for (const auto& result : results1)
    {
        std::cout << result << std::endl;
    }

    const auto results2 = Solution39::combinationSum({ 2, 3, 5 }, 8);
    for (const auto& result : results2)
    {
        std::cout << result << std::endl;
    }
}