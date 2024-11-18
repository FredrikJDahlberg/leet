//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION930_H
#define SOLUTION930_H

class Solution930
{
public:
    static int numSubArraysWithSum(const std::vector<int>& nums, const int goal)
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

#endif //SOLUTION930_H
