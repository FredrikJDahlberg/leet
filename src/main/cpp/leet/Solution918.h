//
// Created by Fredrik Dahlberg on 2024-11-24.
//

#ifndef SOLUTION918_H
#define SOLUTION918_H

#include <vector>

class Solution918
{
public:
    static int maxSubarraySumCircular(const std::vector<int>& nums)
    {
        const auto size = nums.size();
        int max = INT_MIN;
        for (int len = 1; len <= size; ++len)
        {
            for (int i = 0; i < size; ++i)
            {
                int sum = nums[i];
                for (int j = 1; j < len; ++j)
                {
                    sum += nums[(i + j) % size];
                }
                max = std::max(max, sum);
            }
        }
        return max;
    }
};

#endif //SOLUTION918_H




