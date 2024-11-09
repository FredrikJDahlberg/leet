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


namespace example26
{
    static size_t removeDuplicates(std::vector<int> &nums)
    {
        auto value = nums.front();
        for (auto it = nums.begin() + 1; it != nums.end(); ++it)
        {
            if (value == *it)
            {
                nums.erase(it);
            }
            else
            {
                value = *it;
            }
        }
        return nums.size();
    }

    static int removeDuplicates2(std::vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        auto value = nums.front();
        auto in = nums.begin() + 1;
        auto out = nums.begin();
        int count = 1;
        while (in != nums.end())
        {
            if (value != *in)
            {
                value = *in;
                *++out = *in;
                ++count;
            }
            ++in;
        }
        return count;
    }


    void test1()
    {
        std::vector nums{1, 1, 2};
        std::cout << nums << std::endl;
        int count = removeDuplicates2(nums);
        std::cout << "c = " << count << nums << std::endl;
    }

    void test2()
    {
        std::vector nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        std::cout << nums << std::endl;
        int count = removeDuplicates2(nums);
        std::cout << "c = " << count << nums << std::endl;
    }
}

namespace example27
{
    size_t removeElement(std::vector<int> &nums, int val)
    {
        auto it = nums.begin();
        while (it != nums.end())
        {
            if (*it == val)
            {
                nums.erase(it);
            } else
            {
                ++it;
            }
        }
        for (int num: nums)
        {
            printf("val = %d\n", num);
        }
        return nums.size();
    }

    void test1()
    {
        std::vector<int> v = {0, 1, 2, 2, 3, 0, 4, 2};
        removeElement(v, 2);
    }
}

namespace example69
{
    int majorityElement(const std::vector<int> &nums)
    {
        constexpr size_t MAX = 50'000;
        int counts[MAX];
        for (auto num: nums)
        {
            ++counts[num];
        }

        const auto limit = nums.size() / 2;
        for (auto majority = 0; majority < MAX; ++majority)
        {
            if (counts[majority] > limit)
            {
                return majority;
            }
        }
        return 0;
    }

    int majorityElement2(const std::vector<int> &nums)
    {
        std::map<int, int> counts;
        for (auto num: nums)
        {
            auto count = counts.find(num);
            if (count == counts.end())
            {
                counts.insert(std::make_pair(num, 1));
            } else
            {
                ++count->second;
            }
        }

        const auto limit = nums.size() / 2;
        for (auto count: counts)
        {
            if (count.second > limit)
            {
                return count.first;
            }
        }
        return 0;
    }

    void test1()
    {
        std::vector nums{3, 2, 3};
        std::cout << "majority = " << majorityElement(nums) << std::endl;
    }

    void test2()
    {
        std::vector nums{3, 2, 3};
        std::cout << "majority = " << majorityElement2(nums) << std::endl;
    }
}

namespace example88
{
    void merge(std::vector<int> &nums1, const int m, std::vector<int> &nums2, const int n)
    {
        nums1.insert(nums1.begin() + m, nums2.begin(), nums2.begin() + n);
        nums1.erase(nums1.begin() + m + n, nums1.end());
        std::ranges::sort(nums1);
    }

    void test1()
    {
        std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
        std::vector<int> nums2 = {2, 5, 6};
        merge(nums1, 3, nums2, 3);

        std::cout << (nums1 == std::vector<int>{1, 2, 2, 3, 5, 6} ? "true" : "false") << std::endl;
    }

    void test2()
    {
        std::vector<int> nums3 = {1};
        std::vector<int> nums4;
        merge(nums3, 1, nums4, 0);
    }

    void test3()
    {
        std::vector<int> nums5 = {0};
        std::vector<int> nums6 = {1};
        merge(nums5, 0, nums6, 1);
    }
}

namespace example80
{
    int removeDuplicates(int nums[], int count)
    {
        enum class State { NEW, SKIP, KEEP };

        State state = State::NEW;
        int value = 0;
        int position = 0;
        int length = 0;
        int remaining = 0;
        while (position < count)
        {
            switch (state)
            {
                case State::NEW:
                    value = nums[position];
                    nums[remaining++] = nums[position++];
                    state = State::KEEP;
                    break;
                case State::KEEP:
                    if (++length < 2 && nums[position] == value)
                    {
                        nums[remaining++] = nums[position++];
                    } else
                    {
                        state = State::SKIP;
                        length = 0;
                    }
                    break;
                case State::SKIP:
                    if (value == nums[position])
                    {
                        ++position;
                    } else
                    {
                        state = State::NEW;
                    }
                    break;
            }
        }
        return remaining;
    }

    static int removeDuplicates2(std::vector<int> &nums)
    {
        int length = 1;
        int count = 1;
        auto value = nums.front();
        auto out = nums.begin();
        for (auto in = nums.begin() + 1; in != nums.end(); ++in)
        {
            const auto equal = value == *in;
            if (equal && ++length <= 2 || !equal)
            {
                *++out = *in;
                ++count;
            }
            if (!equal)
            {
                length = 1;
                value = *in;
            }
            ++in;
        }
        return count;
    }

    void test1()
    {
        // 1 1 2 2 3
        int values[] = {1, 1, 1, 2, 2, 3};
        int count = removeDuplicates(values, 6);
        std::printf("count = %d\n", count);
        for (int i = 0; i < count; ++i)
        {
            std::printf("values[%d] = %d\n", i, values[i]);
        }
    }

    void test2()
    {
        // 1 1 2 2 3
        std::vector values = {1, 1, 1, 2, 2, 3};
        int count = removeDuplicates2(values);
        std::printf("count = %d\n", count);
        std::cout << values << std::endl;
    }
}

namespace example135
{
    /* You are giving candies to these children subjected to the following requirements:
    - Each child must have at least one candy
    - Children with a higher rating get more candies than their neighbors
    - Return the minimum number of candies you need to have to distribute the candies to the children.
    */
    int candy(const int *ratings, const int size)
    {
        std::cout << "size = " << size << std::endl;
        int candy[size];
        std::ranges::fill(candy, candy + 3, 1);

        int count = size;
        for (auto i = 0; i < size - 1; ++i)
        {
            const auto ratings1 = ratings[i];
            const auto ratings2 = ratings[i + 1];
            if (ratings1 > ratings2)
            {
                ++candy[i];
                ++count;
            }
            if (ratings1 < ratings2)
            {
                ++candy[i + 1];
                ++count;
            }
        }
        std::cout << "min = " << count << std::endl;
        return count;
    }

    void test1()
    {
        constexpr int ratings[3] = {1, 0, 2};
        candy(ratings, 3);
    }

    void test2()
    {
        constexpr int ratings[3] = {1, 2, 2};
        candy(ratings, 3);
    }
}


namespace example1116
{
    class ZeroEvenOdd
    {
    private:
        int max;
        int value;
        int state = 0;

        std::mutex lock;

    public:
        explicit ZeroEvenOdd(const int n) : max(n), value(0)
        {
        }

        void zero(std::function<void(int)>&& printNumber) {
            for (int index = 0; index < max; )
            {
                lock.lock();
                if (state == 0)
                {
                    printNumber(0);
                    index = ++value;
                    state = index % 2 + 1;
                }
                lock.unlock();
            }
        }

        void odd(std::function<void(int)>&& printNumber) {
            for (int index = 0; index < max; )
            {
                lock.lock();
                if (state == 2)
                {
                    printNumber(value);
                    state = 0;
                }
                index = value;
                lock.unlock();
            }
        }

        void even(std::function<void(int)>&& printNumber) {
            for (int index = 0; index < max; )
            {
                lock.lock();
                if (state == 1)
                {
                    printNumber(value);
                    state = 0;
                }
                index = value;
                lock.unlock();
            }
        }
    };

    void test1()
    {
           auto print = [](int number) {
               std::cout << number << std::endl;
           };

           ZeroEvenOdd zeo{5};
           std::thread thread0([&]() { zeo.zero(print); });
           std::thread thread1([&]() { zeo.odd(print); });
           std::thread thread2([&]() { zeo.even(print); });
           thread0.join();
           thread1.join();
           thread2.join();
    }
}

namespace example36
{
    std::ostream& operator<<(std::ostream& os, const std::vector<char>& values)
    {
        for (auto ch : values)
        {
            std::cout << ch;
        }
        return os;
    }

    class Solution {
    public:
        static bool isValidSudoku(const std::vector<std::vector<char>>& board) {
            std::bitset<16> presence;

            for (auto& row : board)
            {
                presence.reset();
                if (!checkRow(row, 0, row.size(), presence))
                {
                    return false;
                }
            }
            for (int i = 0; i < 9; ++i)
            {
                presence.reset();
                for (auto& row : board)
                {
                    auto ch = row[i];
                    if (!valid(ch, presence))
                    {
                        return false;
                    }
                }
            }
            for (int r = 0; r < board.size(); r += 3)
            {
                for (int c = 0; c < board[r].size(); c += 3)
                {
                    presence.reset();
                    for (int j = 0; j < 2; ++j)
                    {
                        if (auto& row = board[r + j]; !checkRow(row, c, 3, presence))
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }

    private:
        static bool checkRow(const std::vector<char>& row, int offset, size_t length, std::bitset<16>& presence)
        {
            for (int i = 0; i < length; ++i)
            {
                if (!valid(row[i + offset], presence))
                {
                    return false;
                }
            }
            return true;
        }

        static bool valid(char ch, std::bitset<16>& presence)
        {
            if (ch == '.')
            {
                return true;
            }
            const auto digit = ch - '0';
            if (presence.test(digit))
            {
                return false;
            }
            presence.set(digit);
            return true;
        }
    };

    void test1()
    {
        std::vector<std::vector<char>> board =
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
        auto result = Solution::isValidSudoku(board);
        std::cout << std::boolalpha << result << std::endl;
        Solution::isValidSudoku(board);
    }
    void test2()
    {
        std::vector<std::vector<char>> board =
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
        auto result = Solution::isValidSudoku(board);
        std::cout << std::boolalpha << result << std::endl;
    }

}

namespace example146
{
    class LRUCache {
        struct Item
        {
            int key;
            int value;

            Item* prev;
            Item* next;

            Item(const int key, const int value, const int sequence)
            {
                this->key = key;
                this->value = value;
                this->prev = nullptr;
                this->next = nullptr;
            }
        };

        std::unordered_map<int, Item*> cache;
        Item* head;
        Item* tail;

        int count;
        int capacity;

    public:
        explicit LRUCache(const int capacity) {
            count = 0;
            this->capacity = capacity;
            head = nullptr;
            tail = nullptr;
        }

        int get(const int key) {
            if (count == -1)
            {
                return -1;
            }
            const auto entry = cache.find(key);
            auto result = entry != cache.end() ? entry->second->value : -1;
            std::cout << "get: key = " << key << " val = " << result << std::endl;
            return entry != cache.end() ? entry->second->value : -1;
        }

        void put(int key, const int value)
        {
            std::cout << "put: key = " << key << " val = " << value << std::endl;
            const auto it = cache.find(key);
            Item* item = nullptr;
            if (it != cache.end())
            { // found
                item = it->second;
            }
            else
            { // missing
                if (count < capacity)
                {
                    ++count;
                    item = new Item(key, value, count);
                    if (head == nullptr)
                    {
                        head = item;
                    }
                    if (tail == nullptr)
                    {
                        tail = item;
                    }
                    cache.insert(std::pair(key, item));
                }
                else
                {
                    //std::printf("replace: (%d, %d) -> (%d, %d)\n", tail->key, tail->value, key, value);
                    cache.erase(tail->key);
                    tail->key = key;
                    tail->value = value;
                    cache.insert(std::pair(key, tail));
                    if (tail->prev != nullptr)
                    {
                        tail = tail->prev;
                        tail->next = item;
                    }
                    tail->next = head;
                    item = tail;
                    head = tail;
                }
            }
            item->next = head;
            head->prev = item;
        }
    };

    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */

    void test1()
    {
        LRUCache lRUCache = LRUCache(2);
        lRUCache.put(1, 1); // cache is {1=1}
        lRUCache.put(2, 2); // cache is {1=1, 2=2}
        lRUCache.get(1);    // return 1
        lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
        lRUCache.get(2);    // returns -1 (not found)
        lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
        lRUCache.get(1);    // return -1 (not found)
        lRUCache.get(3);    // return 3
        lRUCache.get(4);    // return 4

    }
}

namespace example12
{
    class Solution {
    private:
        struct Numeral
        {
            int value;
            std::string string;
        };
        static constexpr Numeral numerals[20] = {
            {1, "I" },
            { 4, "IV"},
            { 5, "V" },
            { 9, "IX" },
            { 10, "X"},
            { 20, "XX"},
            { 30, "XXX" },
            { 40, "XL" },
            { 50, "L" },
            { 90, "XC" },
            { 100, "C" },
            { 200, "CC" },
            { 300, "CCC" },
            { 400, "CD" },
            { 500, "D", },
            { 900, "CM" },
            { 1000, "M" },
            { 2000, "MM" },
            { 3000, "MMM" },
            { 9999, "_" }
        };
    public:
        static std::string intToRoman(const int number)
        {
            auto i = std::ranges::count_if(numerals, [&](const auto& numeral) {
                return numeral.value < number;
            });

            int remaining = number;
            std::string result;
            while (remaining >= 1)
            {
                auto&[value, string] = numerals[i];
                if (remaining < value)
                {
                    --i;
                }
                else
                {
                    remaining -= value;
                    result.append(string);
                }
            }
            std::cout << "result = " << result << std::endl;
            return result;
        }
    };

    void test1()
    {
        std::cout << std::boolalpha << (Solution::intToRoman(3749) == "MMMDCCXLIX") << std::endl;
        std::cout << std::boolalpha << (Solution::intToRoman(58) == "LVIII") << std::endl;
        std::cout << std::boolalpha << (Solution::intToRoman(1994) == "MCMXCIV") << std::endl;
        std::cout << std::boolalpha << (Solution::intToRoman(9) == "IX") << std::endl;
    }
}

namespace example22
{
    class Solution {
    private:
        // n = 1: ()
        // n = 2: (()), ()()
        // n = 3: ()()(), (()()), (())(), ()(())

    public:
        static std::vector<std::string> generateParenthesis(int n) {
            std::string str;

            return std::vector<std::string>{};
        }
    };

    void generate(int n, std::vector<std::string> &result)
    {
        for (int i = 0; i < n -1; ++i)
        {
            const auto size = result.size();
            for (auto j = 0; j < size; ++j)
            {
                auto str = result[j];
                result.push_back("(" + str + ")");
                result.push_back(str + "()");
                if (str.find("((") != std::string::npos)
                {  // skip duplicates
                    result.push_back("()" + str);
                }
            }
            result.erase(result.begin(), result.begin() + size);
        }
    }

    void fibonacci(int n)
    {
        std::vector sequence = { 0, 1 };
        for (auto i = sequence.size(); i < n; ++i)
        {
            auto result = sequence[i - 1] + sequence[i - 2];
            sequence.push_back(result);
        }
        std::cout << sequence << std::endl;
    }

    void test1()
    {
        std::vector<std::string> result = { "()" };
        generate(3, result);
        std::cout <<  result << std::endl;
    }

}

namespace example17
{
    class Solution
    {
    private:
        struct Letters
        {
            char chars[5];
        };
        char letters[10][5] =
        {
             {'?', '\0' },
            {'?', '\0' },
            { 'a', 'b', 'c', '\0' },
            { 'd', 'e', 'f', '\0' },
            { 'g', 'h', 'i', '\0' },
            { 'j', 'k', 'l', '\0' },
            { 'm', 'n', 'o', '\0' },
            { 'p', 'q', 'r', 's', '\0' },
            { 't', 'u', 'v', '\0'},
            { 'w', 'x', 'y', 'z', '\0'}
        };

    public:
        std::vector<std::string> letterCombinations(const std::string& digits)
        {
            std::vector<std::string> results = { "" };
            for (const auto digit : digits)
            {
                const auto* chars = letters[digit - '0'];
                const auto limit = results.size();
                for (int i = 0; i < limit; ++i)
                {
                    for (auto chp = chars; *chp != '\0'; ++chp)
                    {
                        results.push_back(results[i] + *chp);
                    }
                }
                results.erase(results.begin(), results.begin() + limit);
            }
            return results;
        }
    };

    void test1()
    {
        Solution s;
        const auto result = s.letterCombinations("235");
        std::cout << result << std::endl;
    }
}

namespace example39
{
    class Solution {
    private:
        static void combinationSum(const std::vector<int>& candidates,
                                   const int remaining,
                                   std::vector<std::vector<int>>& results,
                                   std::vector<int>& result,
                                   int offset)
        {
            int i = offset;
            if (remaining == 0) {
                results.push_back(result);  // done
            }
            else
            {
                auto candidate = candidates[i];
                while (i < candidates.size() && remaining - candidate >= 0) {
                    result.push_back(candidate); // add candidate
                    combinationSum(candidates, remaining - candidate, results, result, i);
                    candidate = candidates[++i];
                    result.pop_back();  // backtrack
                }
            }
        }
    public:
        static auto combinationSum(const std::vector<int>& candidates, const int target) -> std::vector<std::vector<int>>
        {
            std::vector<std::vector<int>> results;
            std::vector<int> result;
            combinationSum(candidates, target, results, result, 0);
            return results;
        }
    };

    void test1()
    {
        std::cout << "test1\n";
        const auto results = Solution::combinationSum({ 2, 3, 6, 7 }, 7);
        for (const auto& result : results)
        {
            std::cout << result << std::endl;
        }
    }

    void test2()
    {
        std::cout << "test2\n";
        const auto results = Solution::combinationSum({ 2, 3, 5 }, 8);
        for (const auto& result : results)
        {
            std::cout << result << std::endl;
        }
    }
}

namespace example40
{
    class Solution {
    private:

        static void combinationSum(std::vector<int>& candidates,
                                   const int remaining,
                                   const int offset,
                                   std::vector<int>& result,
                                   std::vector<std::vector<int>>& results)
        {
            if (remaining == 0)
            {
                if (std::ranges::find(results, result) == results.end())
                {
                    results.push_back(result);
                }
            }
            else
            {
                int i = offset;
                auto candidate = candidates[i];
                while(i < candidates.size() && remaining - candidate >= 0)
                {
                    result.push_back(candidate);
                    combinationSum(candidates, remaining - candidate, i + 1, result, results);
                    result.pop_back();
                    ++i;
                    candidate = candidates[i];
                }
            }
        }

    public:
        static std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
            std::vector<std::vector<int>> results;
            std::vector<int> result;
            std::ranges::sort(candidates);
            combinationSum(candidates, target, 0, result, results);
            return results;
        }
    };

    void test1()
    {
        std::vector v = {10,1,2,7,6,1,5};
        std::cout << "test1\n";
        const auto& result = example40::Solution::combinationSum(v, 8);
        for (const auto& result : result)
        {
            std::cout << result << std::endl;
        }
    }
    void test2()
    {
        std::vector v = {2,5,2,1,2};
        std::cout << "test2\n";
        const auto& result = example40::Solution::combinationSum(v, 5);
        for (const auto& result : result)
        {
            std::cout << result << std::endl;
        }
    }
}

namespace example63
{
    class Solution {
    private:
        using Path = std::vector<char>;
        static void uniquePathsWithObstacles(int m,
                                             int n,
                                             int x,
                                             int y,
                                             const std::vector<std::vector<int>>& grid,
                                             Path& path,
                                             std::vector<Path>& paths)
        {
            if (m == x && n == y)
            {
                paths.push_back(path);
            }
            else
            {
                if (grid[y][x] != 0)
                {
                    return;
                }
                if (x < m)
                {
                    path.emplace_back('R');
                    uniquePathsWithObstacles(m, n, x + 1, y, grid, path, paths);
                    path.pop_back();
                }
                if (y < n)
                {
                    path.emplace_back('D');
                    uniquePathsWithObstacles(m, n, x, y + 1, grid, path, paths);
                    path.pop_back();
                }
            }
        }

    public:
        static int uniquePathsWithObstacles(const std::vector<std::vector<int>>& grid) {
            Path path;
            std::vector<Path> paths;
            auto m = grid[0].size();
            auto n = grid.size();
            uniquePathsWithObstacles(m - 1, n - 1, 0, 0, grid, path, paths);
            for (auto& p : paths)
            {
                std::cout << p << std::endl;
            }
            return paths.size();
        }
    };

    void test1()
    {
        auto c = Solution::uniquePathsWithObstacles({{0,0,0},{0,1,0},{0,0,0}});
        std::cout << "res = " << c << std::endl;
    }
    void test2()
    {
        auto c = Solution::uniquePathsWithObstacles({{0,1},{0,0}});
        std::cout << "res = " << c << std::endl;
    }
}

namespace example980
{
    class Solution
    {
    public:
        enum class Direction {UP, DOWN, LEFT, RIGHT};

    private:
        using Path = std::vector<std::pair<int, int>>;

        static void uniquePaths(const int m,
                                const int n,
                                std::vector<std::vector<int>>& grid,
                                const int stopX,
                                const int stopY,
                                Direction dir,
                                int x,
                                int y,
                                Path& path,
                                std::vector<Path>& paths)
        {
            if (x == stopX && y == stopY)
            {
                path.emplace_back(y, x);
                paths.push_back(path);
                path.pop_back();
            }
            else
            {
                int deltaX = 0;
                int deltaY = 0;
                Direction newDir = dir;
                switch (dir)
                {
                    case Direction::RIGHT:
                        if (x < m)
                        {
                            deltaX = 1;
                        }
                        else
                        {
                            deltaY = 1;
                            newDir = Direction::LEFT;
                        }
                        break;
                    case Direction::LEFT:
                        if (x > 0)
                        {
                            deltaX = -1;
                        }
                        else
                        {
                            deltaY = 1;
                            newDir = Direction::RIGHT;
                        }
                        break;
                    case Direction::DOWN:
                        if (y < n)
                        {
                            deltaY = 1;
                        }
                        else
                        {
                            deltaX = 1;
                            newDir = Direction::UP;
                        }
                        break;
                    case Direction::UP:
                        if (y > 0)
                        {
                            deltaY = -1;
                        }
                        else
                        {
                            deltaX = 1;
                            newDir = Direction::DOWN;
                        }
                        break;
                }

                const auto& row = grid[y];
                auto newValue = grid[y + deltaY][x + deltaX];
                if (std::ranges::find(path, std::make_pair(y, x)) == path.end())
                {
                    path.emplace_back(y, x);
                    uniquePaths(m, n, grid, stopX, stopY, newDir, x + deltaX, y + deltaY, path, paths);
                    path.pop_back();
                }

                /*
                else
                {
                    if (newValue == 2 && m * n - 1 == grid.size())
                    {
                        path.emplace_back(y, x);
                        uniquePaths(m, n, grid, stopX, stopY, newDir, x + deltaX, y + deltaY, path, paths);
                        path.pop_back();
                    }
                    else
                    {
                        switch (dir)
                        {
                            case Direction::RIGHT:
                                newDir = Direction::DOWN;
                                break;
                            case Direction::DOWN:
                                newDir = Direction::RIGHT;
                                break;
                            case Direction::LEFT:
                                newDir = Direction::UP;
                                break;
                            case Direction::UP:
                                newDir = Direction::LEFT;
                                break;
                        }
                        path.emplace_back(y, x);
                        uniquePaths(m, n, grid, stopX, stopY, newDir, x, y, path, paths);
                        path.pop_back();
                    }
                }
                */
            }
        }

    public:
        static size_t uniquePathsWithObstacles(std::vector<std::vector<int>> &grid)
        {
            std::vector<Path> paths;
            Path path;
            auto m = grid[0].size();
            auto n = grid.size();
            int startX = 0;
            int startY = 0;
            int stopX = 0;
            int stopY = 0;
            int count = 2;
            for (int x = 0; x < m; ++x)
            {
                for (int y = 0; y < n; ++y)
                {
                    auto& row = grid[y];
                    auto& ch = row[x];
                    switch (ch)
                    {
                        case 0:
                            ++count;
                            break;
                        case 1:
                            startX = x;
                            startY = y;
                            break;
                        case 2:
                            stopX = x;
                            stopY = y;
                            break;
                        default:
                            break;
                    }
                }
            }
            // uniquePaths(m - 1, n - 1, grid, stopX, stopY, Direction::RIGHT, startX, startY, path, paths);
            uniquePaths(m - 1, n - 1, grid, stopX, stopY, Direction::DOWN, startX, startY, path, paths);
            for (auto& p : paths)
            {
                std::cout << p << std::endl;
            }
            return paths.size();
        }
    };

    void test1()
    {
        std::vector<std::vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
        auto c = Solution::uniquePathsWithObstacles(grid);
        std::cout << "res = " << c << std::endl;
    }
}

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

namespace example2302
{
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

namespace example150
{
    class Solution {

        enum class Type { PLUS, MINUS, DIV, MULT,NUMBER };
        struct Token
        {
            Type type;
            int value;

            Token() = default;
            Token(Type t, long val) : type(t), value(val)
            {
            }
        };

        std::stack<Token> stack;

        long term(std::string& str)
        {
            return std::strtol(str.c_str(), nullptr, 10);
        }

    public:

        int evalRPN(std::vector<std::string>& tokens) {
            for (auto& str : tokens)
            {
                int result = 0;
                if (std::isdigit(str[0]))
                {
                    result = std::stoi(str);
                }
                else
                {
                    const Token term1 = stack.top();
                    stack.pop();
                    const Token term2 = stack.top();
                    stack.pop();
                    switch (str[0])
                    {
                        case '+':
                            result = term1.value + term2.value;
                            break;
                        case '-':
                            result = term1.value - term2.value;
                            break;
                        case '*':
                            result = term1.value * term2.value;
                            break;
                        case '/':
                            result = term1.value / term2.value;
                            break;
                        default:
                            break;
                    }
                }
                stack.emplace(Type::NUMBER, result);
            }
            return stack.top().value;
        }
    };
    void test1()
    {
        Solution s;
        auto v = std::vector<std::string>{"2","1","+","3","*"};
        std::cout << "result = " << s.evalRPN(v) << std::endl;
    }
    void test2()
    {
        Solution s;
        auto v = std::vector<std::string>{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
        std::cout << "result = " << s.evalRPN(v) << std::endl;
    }
}

namespace example410
{
    class Solution {
    private:
        std::vector<int> lengths;

        int splitArray(const int size,
                       const int k,
                       const int offset,
                       const std::vector<int>& nums)
        {
            if (k == 1)
            {
                auto maxSum = std::numeric_limits<int>::min();
                auto remaining = nums.size() - offset;
                if (remaining >= 1)
                {
                    lengths.emplace_back(remaining);
                    auto it = nums.begin();
                    for (const auto length : lengths)
                    {
                        maxSum = std::max(maxSum, std::accumulate(it, it + length, 0));
                        it += length;
                    }
                    lengths.pop_back();
                }
                return maxSum; // per partition
            }

            auto minSum = std::numeric_limits<int>::max();
            for (int j = 1; j < size; ++j)
            {
                lengths.emplace_back(j);
                minSum = std::min(minSum, splitArray(size - 1, k - 1, offset + j, nums));
                lengths.pop_back();
            }
            return minSum;  // over all
        }

    public:
        int splitArray(std::vector<int>& nums, int k)
        {
            return splitArray(nums.size(), k, 0, nums);
        }
    };

    void test1()
    {
        Solution s;
        std::vector<int> v = {7,2,5,10,8};
        std::cout << "min = " << s.splitArray(v, 2) << std::endl;
        //std::vector<int> v = {1,2,3,4,5};
        //std::cout << s.splitArray(v, 3) << std::endl;
    }
}


namespace example2547
{
    class Solution
    {
    private:
        std::vector<int> lengths;
        std::array<std::uint8_t, 1000> used;     // 0 = zero, 1 = once, 2 = more

        int importance(int offset, int length, int k, std::vector<int>& nums)
        {
            used.fill(0);
            for (int i = offset; i < offset + length; ++i)
            {
                auto num = nums[i];
                if (used[num] < 2)
                {
                    ++used[num];
                }
            }

            int cost = k;
            for (int i = offset; i < offset + length; ++i)
            {
                auto num = nums[i];
                if (used[num] == 2)
                {
                    ++cost;
                }
            }
            return cost;
        }

        int minCost(int offset, int length, int k1, int k, std::vector<int>& nums)
        {
            if (k1 == 1)
            {
                auto remaining = nums.size() - offset;
                lengths.emplace_back(remaining);
                std::cout << lengths << std::endl;

                int pos = 0;
                int cost = 0;
                for (auto len : lengths)
                {
                    cost += importance(pos, len, k, nums);
                    pos += len;
                }
                lengths.pop_back();
                return cost;
            }
            auto min = std::numeric_limits<int>::max();
            for (int i = 1; i < length; ++i)
            {
                lengths.push_back(i);
                min = std::min(min, minCost(offset + i, length - 1, k - 1, k, nums));
                lengths.pop_back();
            }
            return min;
        }

    public:
        Solution()
        {
        }

        int minCost(std::vector<int>& nums, int k)
        {
            return minCost(0, nums.size(), k, k, nums);
        }
    };

    void test1()
    {
        Solution s;
        std::vector<int> v = {1,2,1,2,1,3,3};
        auto minVal = s.minCost(v, 2);
        std::cout << "min cost = " << minVal << std::endl;
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

namespace example61
{
    /*
      Definition for singly-linked list.
    */
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
   class Solution {
    public:
       static ListNode* rotateRight(ListNode* head, int k)
       {
           if (head == nullptr || head->next == nullptr)
           {
               return head;
           }

           ListNode* rotated = head;
           for (int i = 0; i < k; ++i)
           {
               ListNode* newLast = nullptr;
               ListNode* last = rotated;
               while (last != nullptr && last->next != nullptr)
               {
                   newLast = last;
                   last = last->next;
               }
               if (newLast != nullptr)
               {
                   newLast->next = nullptr;
               }
               if (last != nullptr)
               {
                   last->next = rotated;
               }
               rotated = last;
           }
           return rotated;
       }
    };

    void test1()
    {
        // new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
        ListNode* list = new ListNode(1, nullptr); // new ListNode(2, nullptr));
        for (auto node = list; node != nullptr; node = node->next)
        {
            std::cout << "{" << node->val << "} ";
        }
        std::cout << std::endl;

        auto res = Solution::rotateRight(list, 2);
        for (auto node = res; node != nullptr; node = node->next)
        {
            std::cout << "{" << node->val << "} ";
        }
        std::cout << std::endl;
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

namespace example725
{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

   class Solution {
   public:
       static std::vector<ListNode*> splitListToParts(ListNode* head, int k)
       {
           std::vector<ListNode*> result;
           int remaining = 0;
           for (ListNode* node = head; node != nullptr; node = node->next)
           {
               ++remaining;
           }

           int size = (remaining + k - 1) / k;
           int groups = k;
           int count = 0;
           ListNode* first = head;
           for (ListNode* node = head; --remaining >= 0 && node != nullptr; )
           {
               if (++count >= size)
               {
                   --groups;
                   size = remaining / groups;
                   count = 0;

                   result.emplace_back(first);
                   ListNode* last = node;
                   node = node->next;
                   first = node;
                   last->next = nullptr;
               }
               else
               {
                   node = node->next;
               }
           }
           for (auto i = 0; i < groups; ++i)
           {
               result.push_back(nullptr);
           }
           return result;
       }
   };

    void test1()
    {
        //ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, nullptr)));
        ListNode* list = new ListNode(1, nullptr);
        ListNode* prev = list;
        for (int i = 2; i <= 10; ++i)
        {
            auto node = new ListNode(i, nullptr);
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
}

namespace example722
{
    class Solution
    {
    enum class State { COMMENT, MULTI, MULTI_END, REMOVE, KEEP, NEXT, DONE };
    public:
        static std::vector<std::string> removeComments(std::vector<std::string>& source) {
            for (auto s : source)
            {
                std::cout << s << std::endl;
            }

            State state = State::KEEP;
            int line = 0;
            int col = 0;
            while (state != State::DONE)
            {
                auto ch = source[line][col];
                std::cout << "c = " << ch << " " << int(state) << std::endl;
                switch (state)
                {
                    case State::KEEP:
                        if (ch == '/')
                        {
                            ++col;
                            state = State::COMMENT;
                        }
                        else
                        {
                            ++col;
                        }
                        break;
                    case State::COMMENT:
                        if (ch == '*')
                        {
                            state = State::MULTI;
                            source[line].erase(col);
                        }
                        else if (ch == '/')
                        {
                            source[line].erase(col);
                            state = State::KEEP;
                        }
                        else
                        {
                            source[line].erase(col);
                        }
                        break;
                    case State::MULTI:
                        if (ch == '*')
                        {
                            state = State::MULTI_END;
                        }
                        else
                        {
                            source[line].erase(col);
                        }
                        break;
                    case State::MULTI_END:
                        if (ch == '/')
                        {
                            source[line].erase(col, col + 1);
                        }
                        else
                        {
                            state = State::MULTI;
                        }
                        break;
                    default:
                        break;
                }
                if (col >= source[line].size())
                {
                    ++line;
                }
                if (line == source[line].size())
                {
                    state = State::DONE;
                }
            }
            return source;
        }
    };
    void test1()
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
        Solution::removeComments(source);
        for (auto s : source)
        {
            std::cout << s << std::endl;
        }
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

namespace example208
{
    class Trie {
    private:
        static const int EMPTY = 0;
        struct Node
        {
            Node() : value{0}, complete{false}, children{nullptr}
            {
            }

            Node(char ch, bool last) : value{ch}, complete{last}
            {
            }

            char value;
            bool complete;
            Node* children[256];
        };

        Node* root;

        Node* find(Node* node, std::string& word, int& offset)
        {
            auto next = node;
            auto size = word.size();
            while (next != nullptr && next->value == word[offset])
            {
                if (next->value == word[offset])
                {
                    if (offset == size)
                    {
                        return next->complete ? next : nullptr;
                    }
                    ++offset;

                    auto child = next->children[word[offset]];
                    ++offset;
                    if (child == nullptr)
                    {
                        return next;
                    }
                    next = child;
                }
            }
            return next;
        }

        bool insert(Node* node, std::string& word, int offset)
        {
            std::cout << "offset = " << offset << " " << node->value << std::endl;

            while (offset < word.size())
            {
                if (node->value == word[offset])
                {
                    ++offset;

                    auto child = node->children[word[offset]];
                    auto ch = word[offset];
                    if (child == nullptr)
                    {
                        node->children[ch]= new Node(ch, word.size() == offset);
                    }
                    else
                    {
                        // Node* parent = new Node(EMPTY, false);
                        // no common suffix
                    }
                    node = node->children[ch];
                }
            }
            return true;
        }

    public:
        Trie() {
        }

        void insert(std::string word) {
            int offset = 0;
            if (root == nullptr)
            {
                root = new Node(word[0], word.size() == 1);
                ++offset;
            }

            Node* node = find(root, word, offset);

        }

        bool search(std::string word) {
            int offset = 0;
            auto node = find(root, word, offset);
            return node != nullptr ? node->complete : false;
        }

        bool startsWith(std::string prefix) {
            int offset = 0;
            auto node = find(root, prefix, offset);
            return node != nullptr;
        }
    };
    void test1()
    {
        Trie trie = Trie();
        trie.insert("apple");
        trie.search("apple");   // return True
        trie.search("app");     // return False
        trie.startsWith("app"); // return True
        trie.insert("app");
        trie.search("app");
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

void test()
{
    std::string word = "apple";
    std::string out;
    std::transform(word.begin(), word.end(), std::back_inserter(out), ::toupper);
    std::cout << word << " " << out << std::endl;
    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
    std::cout << word << " " << out << std::endl;
    /*
       std::cout << "Input count = ";
       int count = 0;
       std::cin >> count;
       std::cout << "count = " << count << std::endl;

       int counts[3];
       for (auto& value : counts)
       {
           std::cin >> value;
       }
       for (auto& value : counts)
       {
           std::cout << value << std::endl;
       }
       */

    std::string xx = "hoppla";
    //xx.front() = ::toupper(xx.front());
    //xx.back() = ::toupper(xx.back());
    xx[0] = ::toupper(xx[0]);
    xx[xx.size() - 1] = ::toupper(xx[xx.size() - 1]);

    std::cout << xx << std::endl;

    std::string str;
    std::getline(std::cin, str);
    changeWords(str);
    std::cout << "str = " << str << std::endl;

    int yy = 0xdeadbeef;
    std::printf("%02x %02x\n", yy & 0xff, yy & 0xff000000);
    // big: 1234, 12 34
    // little:  34 12
    std::array<std::uint8_t, 256> data;
}

int main(int argc, const char *argv[])
{
    //test2();

    //test();

    //example26::test1();
    //example26::test2();

    //example27::test1();

    // example135::test1();
    //example135::test2();

    //example80::test1();
    //example80::test2();

    //example69::test1();
    //example69::test2();

    //example224::test1();

    //example20::test1();

    //example25::test1();

    //example1116::test1();

    //example36::test2();

    //example146::test1();

    //example12::test1();

    //example22::test1();

    //example17::test1();

    //example39::test1();
    //example39::test2();

    //example40::test1();
    //example40::test2();

    //example62::test1();

    //example63::test1();
    //example63::test2();

    //example980::test1();

    //example53::test1();

    // example2302::test1();
    // example2302::test2();

    //example930::test1();

    //example150::test1();
    //example150::test2();

    //example410::test1();

    //example2547::test1();
    //example2546::test1();
    //example5::test1();
    //example214::test1();
    //example396::test1();
    //example61::test1();
    //example725::test1();
    //example724::test1();
    //example722::test1();
    //example720::test1();
    ////example676::test1();
    //example208::test1();
}
