//
// Created by Fredrik Dahlberg on 2024-11-24.
//

#ifndef SOLUTION2426_H
#define SOLUTION2426_H

#include <vector>

class Solution2426 {
    public:
    static long long numberOfPairs(const std::vector<int>& nums1, const std::vector<int>& nums2, const int diff) {
        const auto size1 = nums1.size();
        const auto size2 = nums2.size();
        int count = 0;
        for (int i = 0; i < size1; ++i)
        {
            for (int j = i + 1; j < size2; ++j)
            {
                if (nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff)
                {
                    ++count;
                }
            }
        }
        return count;
    }
};

#endif //SOLUTION2426_H
