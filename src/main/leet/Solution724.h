//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION724_H
#define SOLUTION724_H

class Solution724 {
public:
    static int pivotIndex(std::vector<int>& nums)
    {
        int lo = 0;
        int hi = 0;
        int loIndex = 0;
        int hiIndex = nums.size() - 1;
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
        if (lo != hi)
        {
            return -1;
        }
        else
        {
            return loIndex + (loIndex == hiIndex ? 0 : 1);
        }
    }
};

#endif //SOLUTION724_H
