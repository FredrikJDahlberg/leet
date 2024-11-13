//
// Created by Fredrik Dahlberg on 2024-10-11.
//


#include <iostream>

#include <gtest/gtest.h>
#include "../../main/leet/Solution20.h"
#include "../../main/leet/Solution25.h"
#include "../../main/leet/Solution26.h"
#include "../../main/leet/Solution27.h"
#include "../../main/leet/Solution60.h"
#include "../../main/leet/Solution62.h"
#include "../../main/leet/Solution69.h"
#include "../../main/leet/Solution80.h"
#include "../../main/leet/Solution123.h"
#include "../../main/leet/Solution188.h"
#include "../../main/leet/Solution224.h"
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
