//
// Created by Fredrik Dahlberg on 2024-11-26.
//

#ifndef SOLUTION805_H
#define SOLUTION805_H

#include <vector>

class Solution805
{
public:
    static bool splitArraySameAverage(std::vector<int>&& nums)
    {
        if (nums.size() <= 1)
        {
            return false;
        }

        std::vector used(nums.size(), false);
        return splitArraySameAverage(0, 0, 0, 0, nums.size(), nums, used);
    }

private:
    static bool splitArraySameAverage(const int sum1,
                                      const int sum2,
                                      const int count1,
                                      const int count2,
                                      const size_t size,
                                      const std::vector<int>& numbers,
                                      std::vector<bool>& used)
    {
        if (count1 >= size || count2 >= size || count1 + count2 >= size)
        {
            return sum1 / count1 == sum2 / count2 && sum1 % count1 == sum2 % count2;
        }

        const auto found = std::ranges::find(used, false);
        if (found == used.end())
        {
            return false;
        }
        const auto pos = std::distance(used.begin(), found);
        const auto number = numbers[pos];
        used[pos] = true;
        const auto result = splitArraySameAverage(sum1 + number, sum2, count1 + 1, count2, size, numbers, used) ||
                            splitArraySameAverage(sum1, sum2 + number, count1, count2 + 1, size, numbers, used);
        used[pos] = false;
        return result;
    }
};

#endif //SOLUTION805_H
