//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION724_H
#define SOLUTION724_H

class Solution724 {
public:
    static size_t pivotIndex(const std::vector<int>& nums)
    {
        const size_t size = nums.size();
        int lo = nums[0];
        int hi = nums[size - 1];
        size_t loIndex = 1;
        size_t hiIndex = size - 2;
        while (loIndex < hiIndex)
        {
            if (lo < hi)
            {
                lo += nums[loIndex];
                ++loIndex;
            }
            else if (lo > hi)
            {
                hi += nums[hiIndex];
                --hiIndex;
            }
            else
            {
                break;
            }
        }
        if (size % 2 == 1)
        {
            --loIndex;
            lo -= nums[loIndex];
            hi += nums[hiIndex];
        }
        return hi == lo ? loIndex : -1;
    }
};

#endif //SOLUTION724_H
