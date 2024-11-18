//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION88_H
#define SOLUTION88_H

class Solution88
{
public:
    static void merge(std::vector<int> &nums1, const int m, std::vector<int> &nums2, const int n)
    {
        nums1.insert(nums1.begin() + m, nums2.begin(), nums2.begin() + n);
        nums1.erase(nums1.begin() + m + n, nums1.end());
        std::ranges::sort(nums1);
    }
};

#endif //SOLUTION88_H
