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

        std::vector<bool> used(nums.size(), false);
        return splitArraySameAverage(0, 0, 0, 0, nums, used);
    }

private:
    static bool splitArraySameAverage(const int sum1,
                                      const int sum2,
                                      const int count1,
                                      const int count2,
                                      const std::vector<int>& nums,
                                      std::vector<bool>& used)
    {
        const auto size = nums.size();
        if (count1 >= size || count2 >= size || count1 + count2 >= size)
        {
            return  static_cast<double>(sum1) / count1 == static_cast<double>(sum2) / count2;
        }

        const auto found = std::ranges::find(used, false);
        if (found == used.end())
        {
            return false;
        }

        const auto pos = std::distance(used.begin(), found);
        const auto num = nums[pos];
        used[pos] = true;
        const auto result = splitArraySameAverage(sum1 + num, sum2, count1 + 1, count2, nums, used) ||
                            splitArraySameAverage(sum1, sum2 + num, count1, count2 + 1, nums, used);
        used[pos] = false;
        return result;
    }
};

#endif //SOLUTION805_H
