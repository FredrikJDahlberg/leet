#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <thread>
#include "Print.h"

//
// Created by Fredrik Dahlberg on 2024-09-28.
//

namespace example53
{
    class Solution
    {
    public:
        static int maxSubArray(const std::vector<int>& nums) {
            auto max = std::numeric_limits<int>::min();
            for (int length = 1; length <= nums.size(); ++length)
            {
                for (auto it = nums.begin(); it != nums.end() - length; ++it)
                {
                    auto sum = std::accumulate(it, it + length + 1, 0);
                    max = std::max(max, sum);
                }
            }
            return max;
        }
    };

    void test1()
    {
        auto c = Solution::maxSubArray({-2,1,-3,4,-1,2,1,-5,4});
        std::cout << "count = " << c << std::endl;
        auto d = Solution::maxSubArray({5,4,-1,7,8});
        std::cout << "count = " << d << std::endl;
    }
}

namespace example930
{
    class Solution
    {
    public:
        static int numSubarraysWithSum(const std::vector<int>& nums, int goal)
        {
            int count = 0;
            for (int length = 1; length < nums.size(); ++length)
            {
                for (auto it = nums.begin(); it != nums.end() - length; ++it)
                {
                    if (goal == std::accumulate(it, it + length + 1, 0))
                    {
                        ++count;
                    }
                }
            }
            return count;
        }
    };

    void test1()
    {
        std::cout << "count = " << Solution::numSubarraysWithSum(std::vector<int>{1,0,1,0,1}, 2) << std::endl;
    }
}

namespace example2546
{
    class Solution {
    public:
        // 1010 -> 0110: {2,0} {2,1}
        // {0,1} {0,2} {0,3} {1,2} {1,3} {2,3}
        // {0,1} = 0110
        // {2,0} = 0010 {2,1} = 0110
        bool makeStringsEqual(std::string s, std::string target) {
            auto len = s.size();
            auto x = s;
            for (int i = 0; i < len; ++i)
            {
                for (int j = i + 1; j < len; ++j)
                {
                    char n1 = x[i] | x[j];
                    char n2 = x[i] ^ x[j];
                    x[i] = n1;
                    x[j] = n2;
                    if (x == target)
                    {
                        return true;
                    }
                }
            }
            auto y = s;
            for (int i = 0; i < len; ++i)
            {
                for (int j = i + 1; j < len; ++j)
                {
                    char n1 = y[j] | y[i];
                    char n2 = y[j] ^ y[i];
                    std::printf("i = %d, j = %d\n", i, j);
                    y[j] = n1;
                    y[i] = n2;
                    if (y == target)
                    {
                        std::cout << y << std::endl;
                        return true;
                    }
                }
            }
            return false;
        }
    };

    void test1()
    {
        Solution s;
        s.makeStringsEqual("1010", "0110");
    }
}

namespace example5
{
    class Solution {
    private:
        bool palindrome(int offset, int length, std::string& s)
        {
            if (length == 1 || length == 2 && s[offset] == s[offset + 1])
            {
                return true;
            }
            if (s[offset] == s[offset + length - 1])
            {
                if (palindrome(offset + 1, length - 2, s))
                {
                    return true;
                }
            }
            return false;
        }

    public:
        std::string longestPalindrome(std::string s)
        {
            int m = std::numeric_limits<int>::min();
            std::string longest;
            for (int length = 1; length < s.size(); ++length)
            {
                for (int offset = 0; offset <= s.size() - length; ++offset)
                {
                    if (palindrome(offset, length, s))
                    {
                        m = std::max(m, length);
                        longest = s.substr(offset, length);
                    }
                }
            }
            return longest;
        }
    };

    void test1()
    {
        Solution s;
        //std::cout << s.longestPalindrome("babad") << std::endl;
        std::cout << s.longestPalindrome("xxabay") << std::endl;
        //std::cout << s.longestPalindrome("bbababd") << std::endl;
    }
}

namespace example214
{
    class Solution {
    public:
        static std::string shortestPalindrome(const std::string& str) {
            size_t len = 0;
            size_t left = 0;
            auto right = str.length() - 1;
            while (left < right)
            {
                if (str[left] == str[right])
                {
                    ++left;
                    ++len;
                }
                --right;
            }

            std::string pal;
            for (auto i = str.length() - 1; i > right + len; --i)
            {
                pal += str[i];
            }
            pal += str;
            return pal;
        }
    };

    void test1()
    {
        std::cout << Solution::shortestPalindrome("a") << std::endl;
        std::cout << Solution::shortestPalindrome("ab") << std::endl;
        std::cout << Solution::shortestPalindrome("abcd") << std::endl;
        std::cout << Solution::shortestPalindrome("aacecaaa") << std::endl;
    }
}

namespace example396
{
    class Solution {
    public:
        static void rotateRight(std::vector<int>& nums, int k)
        {
            const auto size = nums.size();
            for (int j = 0; j < k; ++j)
            {
                auto tmp = nums[size - 1];
                for (auto i = size - 1; i >= 1; --i)
                {
                    nums[i] = nums[i - 1];
                }
                nums[0] = tmp;
            }
        }

    public:
        static int maxRotateFunction(std::vector<int>& nums) {
            auto t = nums;

            rotateRight(t,2);
            std::cout << t << std::endl;
            return 0;
        }
    };

    void test1()
    {
        //std::vector<int> v = {4,3,2,6};
        std::vector<int> v = {1,2,3,4,5};
        Solution::maxRotateFunction(v);
    }
}


namespace example724
{
    class Solution {
    public:
        static int pivotIndex(std::vector<int>& nums)
        {
            int lo = 0;
            int hi = 0;
            int loIndex = 0;
            int hiIndex = nums.size() - 1;
            while (loIndex < hiIndex)
            {
                if (lo < hi)
                {
                    lo += nums[loIndex];
                    ++loIndex;
                }
                else if (lo > hi)
                {
                    hi += nums[hiIndex];
                    --hiIndex;
                }
                else
                {
                    lo += nums[loIndex];
                    ++loIndex;
                    hi += nums[hiIndex];
                    --hiIndex;
                }
            }
            if (lo != hi)
            {
                return -1;
            }
            else
            {
                return loIndex + (loIndex == hiIndex ? 0 : 1);
            }
        }
    };

    void test1()
    {
        auto v = std::vector<int>({1,7,3,6,5,6});
        std::cout << "i = " << Solution::pivotIndex(v) << std::endl;
        auto u = std::vector<int>({1,2,3});
        std::cout << "i = " << Solution::pivotIndex(u) << std::endl;
    }
}

namespace example720
{
    class Solution {
    public:
        static std::string longestWord(std::vector<std::string>& words) {
            std::pmr::set<std::string> set;
            for (auto word : words)
            {
                set.insert(word);
            }

            auto lo = set.begin();
            auto hi = std::next(lo);
            while (lo != hi)
            {
                std::cout << *lo << " " << *std::next(lo) << std::endl;
                auto prefix = *lo;
                auto string = *hi;
                if (!string.starts_with(prefix) || prefix.size() + 1 != string.size())
                {
                    break;
                }
                ++lo;
                ++hi;
            }
            return *lo;
        }
    };
    void test1()
    {
        std::vector<std::string> v{"w","wo","wor","worl","world"};
        std::cout << "v = " << Solution::longestWord(v) << std::endl;

        std::vector<std::string> u{"a","banana","app","appl","ap","apply","apple"};
        std::cout << "v = " << Solution::longestWord(u) << std::endl;
    }
}
namespace example676
{
    class MagicDictionary {
    private:
        std::set<std::string> words;
    public:
        MagicDictionary() {
        }

        void buildDict(std::vector<std::string> dictionary) {
            for (auto word : dictionary)
            {
                words.insert(word);
            }
        }

        bool search(std::string searchWord) {
            for (auto& word : words)
            {
                if (word.size() == searchWord.size())
                {
                    int diffs = 0;
                    auto sw = searchWord.begin();
                    for (const auto w : word)
                    {
                        if (w != *sw)
                        {
                            ++diffs;
                        }
                        ++sw;
                    }
                    if (diffs == 1)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    };

    void test1()
    {
        MagicDictionary dict;
        dict.buildDict({"hello", "leetcode"});
        std::cout << std::boolalpha << dict.search("hello") << std::endl;
        std::cout << std::boolalpha << dict.search("leetcoded") << std::endl;
        std::cout << std::boolalpha << dict.search("hhllo") << std::endl;
    }
}

void changeWords(std::string& word)
{
    int first = 0;
    int last = 0;
    bool move = false;
    while (first < word.size())
    {
        if (move)
        {
            if (word[first] == ' ')
            {
                ++first;
            }
            else
            {
                last = first;
                move = false;
            }
        }
        else
        {
            if (last < word.size() && word[last] != ' ')
            {
                ++last;
            }
            else
            {
                word[first] = ::toupper(word[first]);
                word[last - 1] = ::toupper(word[last - 1]);
                first = last;
                move = true;
            }
        }
    }
}


int main(int argc, const char *argv[])
{

    std::array aa = { 1,2,3,4,5 };
    for (auto a : aa)
    {
        std::cout << "a = " << a << std::endl;
    }
    std::for_each(aa.begin(), aa.end(), [](auto v) {
        std::cout << "b = " << v << std::endl;
    });
    std::ranges::for_each(aa, [](auto v) {
        std::cout << "c = " << v << std::endl;
    });
}
