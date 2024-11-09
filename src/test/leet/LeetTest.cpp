//
// Created by Fredrik Dahlberg on 2024-10-11.
//


#include <iostream>

#include <gtest/gtest.h>
#include "../../main/leet/Solution20.h"
#include "../../main/leet/Solution25.h"
#include "../../main/leet/Solution62.h"
#include "../../main/leet/Solution224.h"
#include "../../main/leet/Solution2302.h"


TEST(Solution, Basic2302)
{
    ASSERT_EQ(5, Solution2302::countSubArrays(std::vector<int>{1,0,1,0,1}, 2));
}

TEST(Solution, Basic20)
{
    Solution20 s;
    ASSERT_TRUE(s.isValid("()[]{}"));
    ASSERT_FALSE(s.isValid("(]"));
    ASSERT_FALSE(s.isValid("([]))"));
}

TEST(Solution, Basic25)
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

TEST(Solution, Basic224)
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

TEST(Solution, Basic62)
{
    ASSERT_EQ(1, Solution62::uniquePaths(0, 0));
    ASSERT_EQ(3, Solution62::uniquePaths(3, 2));
    ASSERT_EQ(28, Solution62::uniquePaths(3, 7));
}