//
// Created by Fredrik Dahlberg on 2024-11-23.
//

#ifndef SOLUTION4_H
#define SOLUTION4_H

#include <vector>

class Solution4 {
public:
    static double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2)
    {
        std::priority_queue<int> maxHeap;
        const auto size1 = nums1.size();
        const auto size2 = nums2.size();
        for (int i = 0; i < std::max(size1, size2); ++i)
        {
            if (i < size1)
            {
                maxHeap.push(nums1[i]);
            }
            if (i < size2)
            {
                maxHeap.push(nums2[i]);
            }
            if (maxHeap.size() > 2)
            {
                maxHeap.pop();
            }
        }

        const auto high = static_cast<double>(maxHeap.top());
        if ((size1 + size2) % 2 == 1)
        {
            return high;
        }
        maxHeap.pop();
        const auto low = static_cast<double>(maxHeap.top());
        return (low + high) / 2.0;
    }
};

#endif //SOLUTION4_H
