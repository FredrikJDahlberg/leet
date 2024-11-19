//
// Created by Fredrik Dahlberg on 2024-10-11.
//


#include <iostream>
#include <thread>
#include <gtest/gtest.h>

#include "../../../main/cpp/leet/Solution5.h"
#include "../../../main/cpp/leet/Solution12.h"
#include "../../../main/cpp/leet/Solution17.h"
#include "../../../main/cpp/leet/Solution20.h"
#include "../../../main/cpp/leet/Solution22.h"
#include "../../../main/cpp/leet/Solution25.h"
#include "../../../main/cpp/leet/Solution26.h"
#include "../../../main/cpp/leet/Solution27.h"
#include "../../../main/cpp/leet/Solution36.h"
#include "../../../main/cpp/leet/Solution39.h"
#include "../../../main/cpp/leet/Solution40.h"
#include "../../../main/cpp/leet/Solution53.h"
#include "../../../main/cpp/leet/Solution60.h"
#include "../../../main/cpp/leet/Solution61.h"
#include "../../../main/cpp/leet/Solution62.h"
#include "../../../main/cpp/leet/Solution63.h"
#include "../../../main/cpp/leet/Solution65.h"
#include "../../../main/cpp/leet/Solution69.h"
#include "../../../main/cpp/leet/Solution80.h"
#include "../../../main/cpp/leet/Solution88.h"
#include "../../../main/cpp/leet/Solution123.h"
#include "../../../main/cpp/leet/Solution124.h"
#include "../../../main/cpp/leet/Solution127.h"
#include "../../../main/cpp/leet/Solution135.h"
#include "../../../main/cpp/leet/Solution146.h"
#include "../../../main/cpp/leet/Solution154.h"
#include "../../../main/cpp/leet/Solution188.h"
#include "../../../main/cpp/leet/Solution208.h"
#include "../../../main/cpp/leet/Solution214.h"
#include "../../../main/cpp/leet/Solution224.h"
#include "../../../main/cpp/leet/Solution239.h"
#include "../../../main/cpp/leet/Solution295.h"
#include "../../../main/cpp/leet/Solution720.h"
#include "../../../main/cpp/leet/Solution396.h"
#include "../../../main/cpp/leet/Solution410.h"
#include "../../../main/cpp/leet/Solution676.h"
#include "../../../main/cpp/leet/Solution722.h"
#include "../../../main/cpp/leet/Solution724.h"
#include "../../../main/cpp/leet/Solution725.h"
#include "../../../main/cpp/leet/Solution930.h"
#include "../../../main/cpp/leet/Solution931.h"
// #include "../../../main/cpp/leet/Solution980.h"
#include "../../../main/cpp/leet/Solution980.h"
#include "../../../main/cpp/leet/Solution150.h"
#include "../../../main/cpp/leet/Solution1044.h"
#include "../../../main/cpp/leet/Solution1116.h"
#include "../../../main/cpp/leet/Solution1289.h"
#include "../../../main/cpp/leet/Solution2302.h"
#include "../../../main/cpp/leet/Solution2546.h"
#include "../../../main/cpp/leet/Solution2547.h"

TEST(Leet, DISABLED_Solution722)
{
    // FIXME
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

TEST(Leet, DISABLED_Solution208)
{   // FIXME: not implemented
    auto trie = Solution208::Trie();
    trie.insert("apple");
    ASSERT_TRUE(trie.search("apple"));
    ASSERT_FALSE(trie.search("app"));
    ASSERT_TRUE(trie.startsWith("app"));
    trie.insert("app");
    ASSERT_TRUE(trie.search("app"));
}

TEST(Leet, DISABLED_Solution396)
{
    // FIXME: not implemented
    ASSERT_EQ(26, Solution396::maxRotateFunction({4,3,2,6}));
}

TEST(Leet, Solution127)
{
    Solution127 solution;
    ASSERT_EQ(5, solution.ladderLength("hit", "cog", {"hot","dot","dog","lot","log","cog"}));
}

TEST(Leet, Solution931)
{
    ASSERT_EQ(12, Solution931::minFallingPathSum({{2,1,3},{6,5,4},{7,8,9}}));
    ASSERT_EQ(-59, Solution931::minFallingPathSum({{-19,57},{-40,-5}}));
}

TEST(Leet, Solution1289)
{
    ASSERT_EQ(5, Solution1289::minFallingPathSum({{1,2},{3,4}}));
    ASSERT_EQ(13, Solution1289::minFallingPathSum({{1,2,3},{4,5,6},{7,8,9} }));
}

TEST(Leet, Solution1043)
{
    ASSERT_EQ("ana", Solution1044::longestDupSubstring("banana"));
    ASSERT_EQ("", Solution1044::longestDupSubstring("abcd"));
}

TEST(Leet, Solution295)
{
    auto medianFinder = solution295::MedianFinder{};
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    EXPECT_NEAR(1.5, medianFinder.findMedian(), 1e-5);
    medianFinder.addNum(3);
    EXPECT_NEAR(2.0, medianFinder.findMedian(), 1e-5);
}

TEST(Leet, Solution239)
{
    const std::vector res{3,3,5,5,6,7};
    ASSERT_EQ(res, Solution239::maxSlidingWindow({1,3,-1,-3,5,3,6,7}, 3));
    ASSERT_EQ(res, Solution239::maxSlidingWindow2({1,3,-1,-3,5,3,6,7}, 3));
}

TEST(Leet, Solution154)
{
    ASSERT_EQ(0, Solution154::findMin(std::vector{5,6,7,0,1,4,5}));
    ASSERT_EQ(0, Solution154::findMin(std::vector{5,6,7,0,1,4,5,5}));
    ASSERT_EQ(0, Solution154::findMin(std::vector{4,5,6,7,0,1,4}));
    ASSERT_EQ(1, Solution154::findMin(std::vector{1,3,5}));
    ASSERT_EQ(0, Solution154::findMin(std::vector{2,2,2,0,1}));
}

TEST(Leet, Solution65)
{
    ASSERT_TRUE(Solution65::isNumber("2"));
    ASSERT_TRUE(Solution65::isNumber("0089"));
    ASSERT_TRUE(Solution65::isNumber("-0.1"));
    ASSERT_TRUE(Solution65::isNumber("+3.14"));
    ASSERT_TRUE(Solution65::isNumber("-.9"));
    ASSERT_TRUE(Solution65::isNumber("2e10"));
    ASSERT_TRUE(Solution65::isNumber("-90E3"));
    ASSERT_TRUE(Solution65::isNumber("3e+7"));
    ASSERT_TRUE(Solution65::isNumber("+6e-1"));
    ASSERT_TRUE(Solution65::isNumber("53.5e93"));
    ASSERT_TRUE(Solution65::isNumber("-123.456e789"));
    ASSERT_FALSE(Solution65::isNumber("abc"));
    ASSERT_FALSE(Solution65::isNumber("1a"));
    ASSERT_FALSE(Solution65::isNumber("1e"));
    ASSERT_FALSE(Solution65::isNumber("e3"));
    ASSERT_FALSE(Solution65::isNumber("99e2.5"));
    ASSERT_FALSE(Solution65::isNumber("--6"));
    ASSERT_FALSE(Solution65::isNumber("-+3"));
    ASSERT_FALSE(Solution65::isNumber("95a54e53"));
}

TEST(Leet, Solution124)
{
    using TreeNode = Solution124::TreeNode;
    const auto tree1 = new TreeNode{1, new TreeNode{2}, new TreeNode{3}};
    ASSERT_EQ(6, Solution124::maxPathSum(tree1));

    const auto tree2 = new TreeNode{-10, new TreeNode{9}, new TreeNode{20, new TreeNode{15}, new TreeNode{7}}};
    ASSERT_EQ(42, Solution124::maxPathSum(tree2));
}

TEST(Leet, Solution676)
{
    Solution676::MagicDictionary dict;
    dict.buildDict({"hello", "leetcode"});
    ASSERT_FALSE(dict.search("hello"));
    ASSERT_TRUE(dict.search("hhllo"));
    ASSERT_FALSE(dict.search("hell"));
    ASSERT_FALSE(dict.search("leetcoded"));
}

TEST(Leet, Solution720)
{
    ASSERT_EQ("world", Solution720::longestWord({"w","wo","wor","worl","world"}));;
    ASSERT_EQ("apple", Solution720::longestWord({"a","banana","app","appl","ap","apply","apple"}));
}

TEST(Leet, Solution724)
{
    ASSERT_EQ(3, Solution724::pivotIndex({1,7,3,6,5,6}));
    ASSERT_EQ(-1, Solution724::pivotIndex({1,2,3}));
    ASSERT_EQ(2, Solution724::pivotIndex({1,2,0,3}));
    ASSERT_EQ(0, Solution724::pivotIndex({2,1,-1}));
}

TEST(Leet, Solution5)
{
    ASSERT_EQ("aba", Solution5::longestPalindrome("babad"));
    ASSERT_EQ("aba", Solution5::longestPalindrome("xxabay"));
    ASSERT_EQ("bb", Solution5::longestPalindrome("cbbd"));
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
    // FIXME
    Solution25 solution25{1,2,3,4,5};

    // 1 2 3 4 5, k = 2 -> 2 1 4 3 5
    // 1 2 3 4 5, k = 3 -> 3 2 1 4 5
    const auto* rev1 = solution25.reverse(2);
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
    // ASSERT_EQ(2, Solution26::removeDuplicates(v1));
    ASSERT_EQ(2, Solution26::removeDuplicates2(v1));
    std::vector v2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    // FIXME
    // ASSERT_EQ(5, Solution26::removeDuplicates(v2));
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
    int values1[] = {1, 1, 1, 2, 2, 3};
    ASSERT_EQ(5, Solution80::removeDuplicates(values1, 6));

    int values2[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    ASSERT_EQ(7, Solution80::removeDuplicates(values2, 9));
}

TEST(Leet, Solution88)
{
    std::vector nums1 = {1, 2, 3, 0, 0, 0};
    std::vector nums2 = {2, 5, 6};
    Solution88::merge(nums1, 3, nums2, 3);
    auto expected1 = std::vector{1, 2, 2, 3, 5, 6};
    ASSERT_EQ(expected1, nums1);

    std::vector<int> nums3{0};
    std::vector<int> nums4  = {1};;
    auto expected2 = std::vector{1};
    Solution88::merge(nums3, 0, nums4, 1);
    ASSERT_EQ(nums3, expected2);
}

TEST(Leet, Solution135)
{
    constexpr int ratings1[3] = {1, 0, 2};
    ASSERT_EQ(5, Solution135::candy(ratings1, 3));

    constexpr int ratings2[3] = {1, 2, 2};
    ASSERT_EQ(4, Solution135::candy(ratings2, 3));
}

static std::string runner1116(const int n)
{
    std::mutex mutex;
    std::string output;

    auto print = [&](const int number) {
        mutex.lock();
        output.push_back('0' + number);
        mutex.unlock();
    };

    ZeroEvenOdd zeo{n};
    std::thread thread0([&]() { zeo.zero(print); });
    std::thread thread1([&]() { zeo.odd(print); });
    std::thread thread2([&]() { zeo.even(print); });
    thread0.join();
    thread1.join();
    thread2.join();
    return output;
}

TEST(Leet, Solution1116)
{
    ASSERT_EQ("0102", runner1116(2));
    ASSERT_EQ("0102030405", runner1116(5));
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
    const auto expected1 = std::vector<std::string>{ "((()))", "(())()", "()(())", "(()())", "()()()" };
    ASSERT_EQ(expected1, Solution22::generateParenthesis(3));

    const auto expected2 = std::vector<std::string>{"()"};
    ASSERT_EQ(expected2, Solution22::generateParenthesis(1));
}

TEST(Leet, Solution17)
{
    const auto expected = std::vector<std::string>{"ad","ae","af","bd","be","bf","cd","ce","cf"};
    ASSERT_EQ(expected, Solution17::letterCombinations("23"));
}

TEST(Leet, Solution39)
{
    const auto results1 = Solution39::combinationSum({ 2, 3, 6, 7 }, 7);
    const auto expected1 = std::vector<std::vector<int>>{{2,2,3},{7}};
    ASSERT_EQ(expected1, results1);

    const auto results2 = Solution39::combinationSum({ 2, 3, 5 }, 8);
    const auto expected2 = std::vector<std::vector<int>>{{2,2,2,2},{2,3,3},{3,5}};
    ASSERT_EQ(expected2, results2);
}

TEST(Leet, Solution40)
{
    std::vector v1 = {10,1,2,7,6,1,5};
    const auto& result1 = Solution40::combinationSum(v1, 8);
    const auto expected1 = std::vector<std::vector<int>>{{1,1,6},{1,2,5},{1,7},{2,6}};
    ASSERT_EQ(expected1, result1);

    std::vector v2 = {2,5,2,1,2};
    const auto& result2 = Solution40::combinationSum(v2, 5);
    const auto expected2 = std::vector<std::vector<int>>{{1,2,2},{5}};
    ASSERT_EQ(expected2, result2);
}

TEST(Leet, Solution63)
{
    ASSERT_EQ(2, Solution63::uniquePathsWithObstacles({{0,0,0},{0,1,0},{0,0,0}}));
    ASSERT_EQ(1, Solution63::uniquePathsWithObstacles({{0,1},{0,0}}));
}

TEST(Leet, Solution980)
{
    auto grid = std::vector<std::vector<int>>{{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    ASSERT_EQ(2, Solution980::uniquePaths(grid));
}

TEST(Leet, Solution1050)
{
    Solution150 rpn;
    ASSERT_EQ(9, rpn.evalRPN(std::vector<std::string>{"2","1","+","3","*"}));
    ASSERT_EQ(22, rpn.evalRPN(std::vector<std::string>{"10","6","9","3","+","-11","*","/","*","17","+","5","+"}));
}

TEST(Leet, Solution410)
{
    Solution410 solution;
    ASSERT_EQ(18, solution.splitArray({7,2,5,10,8}, 2));
    ASSERT_EQ(9, solution.splitArray({1,2,3,4,5}, 2));
}

TEST(Leet, 2547)
{
    Solution2547 solution;
    auto values = std::vector{1, 2, 1, 2, 1, 3, 3};
    ASSERT_EQ(8, solution.minCost(values, 2));
}

TEST(Leet, Solution725)
{
    using Solution725::ListNode;
    using Solution725::Solution;

    auto* list = new ListNode(1, nullptr);
    ListNode* prev = list;
    for (int i = 2; i <= 10; ++i)
    {
        const auto node = new ListNode(i, nullptr);
        prev->next = node;
        prev = node;
    }

    auto res = Solution::splitListToParts(list, 3);
    ASSERT_EQ(3, res.size());
    auto r1 = res[0];
    ASSERT_EQ(1, r1->val);
    ASSERT_EQ(2, r1->next->val);
    ASSERT_EQ(3, r1->next->next->val);
    ASSERT_EQ(4, r1->next->next->next->val);
    auto r2 = res[1];
    ASSERT_EQ(5, r2->val);
    ASSERT_EQ(6, r2->next->val);
    ASSERT_EQ(7, r2->next->next->val);
    auto r3 = res[2];
    ASSERT_EQ(8, r3->val);
    ASSERT_EQ(9, r3->next->val);
    ASSERT_EQ(10, r3->next->next->val);
}

TEST(Leet, Solution61)
{
    using Solution61::ListNode;
    using Solution61::Solution;

    auto list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    const auto result = Solution::rotateRight(list, 2);
    ASSERT_EQ(4, result->val);
    ASSERT_EQ(5, result->next->val);
    ASSERT_EQ(1, result->next->next->val);
    ASSERT_EQ(2, result->next->next->next->val);
    ASSERT_EQ(3, result->next->next->next->next->val);
}

TEST(Leet, Solution53)
{
    ASSERT_EQ(6, Solution53::maxSubArray({-2,1,-3,4,-1,2,1,-5,4}));
    ASSERT_EQ(23, Solution53::maxSubArray({5,4,-1,7,8}));
}

TEST(Leet, Solution2546)
{
    ASSERT_TRUE(Solution2546::makeStringsEqual("1010", "0110"));
}

TEST(Leet, Solution930)
{
    ASSERT_EQ(4, Solution930::numSubArraysWithSum(std::vector<int>{1,0,1,0,1}, 2));
}

TEST(Leet, Solution214)
{
    ASSERT_EQ("a", Solution214::shortestPalindrome("a"));
    ASSERT_EQ("bab", Solution214::shortestPalindrome("ab"));
    ASSERT_EQ("dcbabcd", Solution214::shortestPalindrome("abcd"));
    ASSERT_EQ("aaacecaaa", Solution214::shortestPalindrome("aacecaaa"));
}
