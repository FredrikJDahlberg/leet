//
// Created by Fredrik Dahlberg on 2024-11-25.
//

#ifndef SOLUTION1_H
#define SOLUTION1_H

#include <vector>

class Solution1
{
public:
    static std::vector<int> twoSum(const std::vector<int>& nums, const int target)
    {
        const auto size = nums.size();
        for (auto i = 0; i < size; ++i)
        {
            for (auto j = i + 1; j < size; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

#endif //SOLUTION1_H
