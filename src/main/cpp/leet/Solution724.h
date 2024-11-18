//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION724_H
#define SOLUTION724_H

class Solution724 {
public:
    static int pivotIndex(const std::vector<int>& nums)
    {
        int lo = 0;
        int hi = 0;
        int loIndex = 0;
        const size_t size = nums.size();
        size_t hiIndex = size - 1;
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
                lo += nums[loIndex];
                ++loIndex;
                hi += nums[hiIndex];
                --hiIndex;
            }
        }

        if (hi == -1)
        {
            return 0;
        }
        return loIndex == hiIndex && lo < hi ? -1 : loIndex;
    }
};

#endif //SOLUTION724_H
