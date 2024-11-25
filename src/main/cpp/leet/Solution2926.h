//
// Created by Fredrik Dahlberg on 2024-11-24.
//

#ifndef SOLUTION2926_H
#define SOLUTION2926_H

#include <vector>

class Solution2926
{
public:
    static int64_t maxBalancedSubsequenceSum(const std::vector<int>& nums)
    {
        const auto size = nums.size();
        std::vector<int> sub;
        int maxSum = INT_MIN;
        for (int len = 1; len <= size; ++len)
        {
            for (int i = 0; i < size - len; ++i)
            {
                if ((i == 0 || balanced(nums, 0, i - 1)) && balanced(nums, i + len, size - len))
                {
                    int sum = 0;
                    if (i >= 1)
                    {
                        sum += nums[0];
                        sum = std::accumulate(nums.begin() + 1, nums.begin() + i, sum);
                    }
                    sum += nums[i + len];
                    sum = std::accumulate(nums.begin() + i + len + 1, nums.end(), sum);
                    maxSum = std::max(maxSum, sum);
                }
            }
        }
        return maxSum;
    }

private:
    static bool balanced(const std::vector<int>&nums, const int offset, const int length)
    {
        bool balanced = true;
        for (int i = offset; i < offset + length; ++i)
        {
            for (int j = i + 1; j < length; ++j)
            {
                balanced &= nums[i] - nums[j - 1] <= j - i;
            }
        }
        return balanced;
    }

};

#endif //SOLUTION2926_H
