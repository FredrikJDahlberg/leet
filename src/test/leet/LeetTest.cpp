//
// Created by Fredrik Dahlberg on 2024-10-11.
//


#include <iostream>
#include <thread>
#include <gtest/gtest.h>

#include "../../main/leet/Print.h"
#include "../../main/leet/Solution5.h"
#include "../../main/leet/Solution12.h"
#include "../../main/leet/Solution17.h"
#include "../../main/leet/Solution20.h"
#include "../../main/leet/Solution22.h"
#include "../../main/leet/Solution25.h"
#include "../../main/leet/Solution26.h"
#include "../../main/leet/Solution27.h"
#include "../../main/leet/Solution36.h"
#include "../../main/leet/Solution39.h"
#include "../../main/leet/Solution40.h"
#include "../../main/leet/Solution53.h"
#include "../../main/leet/Solution60.h"
#include "../../main/leet/Solution61.h"
#include "../../main/leet/Solution62.h"
#include "../../main/leet/Solution63.h"
#include "../../main/leet/Solution69.h"
#include "../../main/leet/Solution80.h"
#include "../../main/leet/Solution88.h"
#include "../../main/leet/Solution123.h"
#include "../../main/leet/Solution124.h"
#include "../../main/leet/Solution127.h"
#include "../../main/leet/Solution135.h"
#include "../../main/leet/Solution146.h"
#include "../../main/leet/Solution188.h"
#include "../../main/leet/Solution208.h"
#include "../../main/leet/Solution214.h"
#include "../../main/leet/Solution224.h"
#include "../../main/leet/Solution720.h"
#include "../../main/leet/Solution396.h"
#include "../../main/leet/Solution410.h"
#include "../../main/leet/Solution676.h"
#include "../../main/leet/Solution722.h"
#include "../../main/leet/Solution724.h"
#include "../../main/leet/Solution725.h"
#include "../../main/leet/Solution930.h"
#include "../../main/leet/Solution980.h"
#include "../../main/leet/Solution1050.h"
#include "../../main/leet/Solution1116.h"
#include "../../main/leet/Solution2302.h"
#include "../../main/leet/Solution2546.h"
#include "../../main/leet/Solution2547.h"

TEST(Leet, Solution124)
{
    using TreeNode = Solution124::TreeNode;
    const auto tree1 = new TreeNode{1, new TreeNode{2}, new TreeNode{3}};
    std::cout << Solution124::maxPathSum(tree1) << std::endl;

    const auto tree2 = new TreeNode{-10, new TreeNode{9}, new TreeNode{20, new TreeNode{15}, new TreeNode{7}}};
    std::cout << Solution124::maxPathSum(tree2) << std::endl;
}

TEST(Leet, DISABLED_Solution676)
{
    Solution676::MagicDictionary dict;
    dict.buildDict({"hello", "leetcode"});
    std::cout << std::boolalpha << dict.search("hello") << std::endl;
    std::cout << std::boolalpha << dict.search("leetcoded") << std::endl;
    std::cout << std::boolalpha << dict.search("hhllo") << std::endl;
}

TEST(Leet, Solution720)
{
    std::vector<std::string> v{"w","wo","wor","worl","world"};
    std::cout << "v = " << Solution720::longestWord(v) << std::endl;

    std::vector<std::string> u{"a","banana","app","appl","ap","apply","apple"};
    std::cout << "v = " << Solution720::longestWord(u) << std::endl;
}

TEST(Leet, Solution724)
{
    auto v = std::vector<int>({1,7,3,6,5,6});
    std::cout << "i = " << Solution724::pivotIndex(v) << std::endl;
    auto u = std::vector<int>({1,2,3});
    std::cout << "i = " << Solution724::pivotIndex(u) << std::endl;
}

TEST(Leet, Solution5)
{
        //std::cout << s.longestPalindrome("babad") << std::endl;
        Solution5::longestPalindrome("xxabay");
        //std::cout << s.longestPalindrome("bbababd") << std::endl;
}

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

    const auto* rev1 = solution25.reverse(4);
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
    const std::vector nums{3, 2, 3};
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

TEST(Leet, DISABLED_Solution88)
{
    std::vector nums1 = {1, 2, 3, 0, 0, 0};
    std::vector nums2 = {2, 5, 6};
    Solution88::merge(nums1, 3, nums2, 3);
    const auto res = std::vector<int>{1, 2, 2, 3, 5, 6};
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

TEST(Leet, DISABLED_Solution1116)
{
    auto print = [](const int number) {
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
    const std::vector<std::vector<char>> board1 =
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

    const std::vector<std::vector<char>> board2 =
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
    ASSERT_FALSE(Solution36::isValidSudoku(board2));
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

TEST(Leet, DISABLED_Solution40)
{
    // FIXME
    std::vector v1 = {10,1,2,7,6,1,5};
    std::cout << "test1\n";
    const auto& result1 = Solution40::combinationSum(v1, 8);
    for (const auto& result : result1)
    {
        std::cout << result << std::endl;
    }

    std::vector v2 = {2,5,2,1,2};
    std::cout << "test2\n";
    const auto& result2 = Solution40::combinationSum(v2, 5);
    for (const auto& result : result2)
    {
        std::cout << result << std::endl;
    }
}

TEST(Leet, Solution63)
{
    const auto c1 = Solution63::uniquePathsWithObstacles({{0,0,0},{0,1,0},{0,0,0}});
    std::cout << "res = " << c1 << std::endl;

    const auto c2 = Solution63::uniquePathsWithObstacles({{0,1},{0,0}});
    std::cout << "res = " << c2 << std::endl;
}

TEST(Leet, DISABLED_Solution900)
{
    // FIXME
    std::vector<std::vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    const auto c = Solution980::uniquePathsWithObstacles(grid);
    std::cout << "res = " << c << std::endl;
}

TEST(Leet, DISABLED_Solution1050)
{
    Solution1050 s;
    auto v1 = std::vector<std::string>{"2","1","+","3","*"};
    std::cout << "result = " << s.evalRPN(v1) << std::endl;

    auto v2 = std::vector<std::string>{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    std::cout << "result = " << s.evalRPN(v2) << std::endl;
}

TEST(Leet, DISABLED_Solution410)
{
    Solution410 solution;
    std::vector<int> v = {7,2,5,10,8};
    std::cout << "min = " << solution.splitArray(v, 2) << std::endl;
    //std::vector<int> v = {1,2,3,4,5};
    //std::cout << s.splitArray(v, 3) << std::endl;
}

TEST(Leet, DISABLED_2547)
{
    Solution2547 solution;
    std::vector v = {1, 2, 1, 2, 1, 3, 3};
    const auto minVal = solution.minCost(v, 2);
    std::cout << "min cost = " << minVal << std::endl;
}

TEST(Leet, Solution722)
{
    std::vector<std::string> source =
    {"/*Test program */", "int main()",
        "{ ",
        "  // variable declaration ",
        "int a, b, c;",
        "/* This is a test",
        "   multiline  ",
        "   comment for ",
        "   testing */",
        "a = b + c;",
        "}"};
    Solution722::removeComments(source);
    for (const auto& s : source)
    {
        std::cout << s << std::endl;
    }
}

TEST(Leet, Solution208)
{
    auto trie = Solution208::Trie();
    trie.insert("apple");
    ASSERT_TRUE(trie.search("apple"));   // return True
    ASSERT_FALSE(trie.search("app"));     // return False
    ASSERT_TRUE(trie.startsWith("app")); // return True
    trie.insert("app");
    ASSERT_TRUE(trie.search("app"));
}

TEST(Leet, DISABLED_Solution725)
{
    using Solution725::ListNode;
    using Solution725::Solution;
    //ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, nullptr)));
    auto* list = new ListNode(1, nullptr);
    ListNode* prev = list;
    for (int i = 2; i <= 10; ++i)
    {
        const auto node = new ListNode(i, nullptr);
        prev->next = node;
        prev = node;
    }
    auto res = Solution::splitListToParts(list, 3);
    for (auto list : res)
    {
        std::cout << "[";
        for (auto node = list; node != nullptr; node = node->next)
        {
            std::cout << "{" << node->val << "} ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}

TEST(Leet, DISABLED_Solution61)
{
    using Solution61::ListNode;
    using Solution61::Solution;

    // new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    auto list = new ListNode(1, nullptr); // new ListNode(2, nullptr));
    for (auto node = list; node != nullptr; node = node->next)
    {
        std::cout << "{" << node->val << "} ";
    }
    std::cout << std::endl;

    const auto res = Solution::rotateRight(list, 2);
    for (auto node = res; node != nullptr; node = node->next)
    {
        std::cout << "{" << node->val << "} ";
    }
    std::cout << std::endl;
}

TEST(Leet, DISABLED_Solution53)
{
    const auto c = Solution53::maxSubArray({-2,1,-3,4,-1,2,1,-5,4});
    std::cout << "count = " << c << std::endl;
    const auto d = Solution53::maxSubArray({5,4,-1,7,8});
    std::cout << "count = " << d << std::endl;
}

TEST(Leet, DISABLED_Solution2546)
{
    Solution2546::makeStringsEqual("1010", "0110");
}

TEST(Leet, DISABLED_Solution930)
{
    Solution930::numSubArraysWithSum(std::vector<int>{1,0,1,0,1}, 2);
}

TEST(Leet, DISABLED_Solution214)
{
    std::cout << Solution214::shortestPalindrome("a") << std::endl;
    std::cout << Solution214::shortestPalindrome("ab") << std::endl;
    std::cout << Solution214::shortestPalindrome("abcd") << std::endl;
    std::cout << Solution214::shortestPalindrome("aacecaaa") << std::endl;
}

TEST(Leet, DISABLED_Solution396)
{
    //std::vector<int> v = {4,3,2,6};
    std::vector<int> v = {1,2,3,4,5};
    Solution396::maxRotateFunction(v);
}

TEST(Leet, Solution127)
{
    Solution127 solution;
    std::vector<std::string> words = {"hot","dot","dog","lot","log","cog"};
    std::cout << solution.ladderLength("hit", "cog", words) << std::endl;
}
