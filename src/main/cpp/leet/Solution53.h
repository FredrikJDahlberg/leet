//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION53_H
#define SOLUTION53_H

#include <numeric>

class Solution53
{
public:
    static int maxSubArray(const std::vector<int> &nums)
    {
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

#endif //SOLUTION53_H
