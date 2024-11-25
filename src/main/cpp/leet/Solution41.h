//
// Created by Fredrik Dahlberg on 2024-11-25.
//

#ifndef SOLUTION41_H
#define SOLUTION41_H

#include <vector>

class Solution41
{
public:
    static int firstMissingPositive(const std::vector<int>& nums)
    {
        int lo = 0;
        int hi = INT_MAX;
        for (const auto n : nums)
        {
            if (n >= 1)
            {
                if (lo + 1 == n)
                {
                    lo = n;
                }
                else if (hi == INT_MAX || hi - 1 == n)
                {
                    hi = n;
                }
            }
        }
        return lo + 1;
    }
};

#endif //SOLUTION41_H
