//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION396_H
#define SOLUTION396_H

class Solution396 {
public:
    static int maxRotateFunction(const std::vector<int>& nums) {
        int max = INT32_MIN;
        const auto size = nums.size();
        for (size_t i  = 0; i < size; ++i)
        {
            int value = 0;
            for (size_t j = 0; j < size; ++j)
            {
                value += j * nums[(i + j) % size];
            }
            max = std::max(value, max);
        }
        return max;
    }
};

#endif //SOLUTION396_H
