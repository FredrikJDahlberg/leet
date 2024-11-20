//
// Created by Fredrik Dahlberg on 2024-11-18.
//

#ifndef SOLUTION239_H
#define SOLUTION239_H

#include <vector>

class Solution239 {
public:
    static std::vector<int> maxSlidingWindow(const std::vector<int>& nums, const int k) {
        std::vector<int> result;
        for (int i = 0; i <= nums.size() - k; ++i)
        {
            auto max = INT32_MIN;
            for (int j = i; j < i + k; ++j)
            {
                max = std::max(nums[j], max);
            }
            result.emplace_back(max);
        }
        return result;
    }

    static std::vector<int> maxSlidingWindow2(const std::vector<int>& nums, const int k) {
        std::vector<int> result;
        for (auto i = nums.begin(); i != nums.end() - k + 1; ++i)
        {
            result.emplace_back(*std::ranges::max_element(i, i + k));
        }
        return result;
    }
};
#endif //SOLUTION239_H
