//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION69_H
#define SOLUTION69_H

#include <vector>

class Solution69 {
public:
    static int majorityElement(const std::vector<int> &nums)
    {
        constexpr size_t MAX = 50'000;
        int counts[MAX];
        for (auto num: nums)
        {
            ++counts[num];
        }

        const auto limit = nums.size() / 2;
        for (auto majority = 0; majority < MAX; ++majority)
        {
            if (counts[majority] > limit)
            {
                return majority;
            }
        }
        return 0;
    }

    static int majorityElement2(const std::vector<int> &nums)
    {
        std::map<int, int> counts;
        for (auto num: nums)
        {
            auto count = counts.find(num);
            if (count == counts.end())
            {
                counts.insert(std::make_pair(num, 1));
            } else
            {
                ++count->second;
            }
        }

        const auto limit = nums.size() / 2;
        for (auto count: counts)
        {
            if (count.second > limit)
            {
                return count.first;
            }
        }
        return 0;
    }

};

#endif //SOLUTION69_H
