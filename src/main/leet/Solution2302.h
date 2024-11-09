//
// Created by Fredrik Dahlberg on 2024-10-11.
//

#ifndef SOLUTION2302_H
#define SOLUTION2302_H

#include <numeric>

class Solution2302 {
public:
    static std::int64_t countSubArrays(const std::vector<int>& nums, int64_t limit) {
        int count = 0;
        for (int length = 1; length <= nums.size(); ++length)
        {
            for (auto it = nums.begin(); it != nums.end() - length + 1; ++it)
            {
                if (std::accumulate(it, it + length, static_cast<int64_t>(0)) * length < limit)
                {
                    ++count;
                }
            }
        }
        return count;
    }
};

#endif //SOLUTION2302_H
