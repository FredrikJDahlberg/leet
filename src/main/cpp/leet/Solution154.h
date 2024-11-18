//
// Created by Fredrik Dahlberg on 2024-11-17.
//

#ifndef SOLUTION154_H
#define SOLUTION154_H

#include <vector>

class Solution154 {
public:
    static int findMin(const std::vector<int>& nums) {
        auto lo = INT_MIN;
        auto hi = INT_MAX;
        const auto size = nums.size();
        auto b = 0;
        auto e = size - 1;
        while (b < e)
        {
            if (nums[b] >= lo)
            {
                lo = nums[b];
                ++b;
            }
            else
            {
                return nums[b];
            }
            if (nums[e] <= hi)
            {
                hi = nums[e];
                --e;
            }
        }
        if (size % 2 == 1)
        {
            lo = std::min(nums[b], lo);
        }
        return std::min(hi, lo);
    }
};

#endif //SOLUTION154_H
