//
// Created by Fredrik Dahlberg on 2024-11-17.
//

#ifndef SOLUTION154_H
#define SOLUTION154_H

#include <vector>

class Solution154 {
public:
    static int findMin(const std::vector<int>& nums) {
        auto max = INT_MIN;
        auto min = INT_MAX;
        const auto size = nums.size();
        auto b = 0;
        auto e = size - 1;
        while (b < e)
        {
            if (nums[b] >= max)
            {
                max = nums[b];
                ++b;
            }
            else
            {
                return nums[b];
            }
            if (nums[e] <= min)
            {
                min = nums[e];
                --e;
            }
            else
            {
                return min;
            }
        }
        if (size % 2 == 1)
        {
            max = std::min(nums[b], max);
        }
        return std::min(min, max);
    }
};

#endif //SOLUTION154_H
