//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION396_H
#define SOLUTION396_H

class Solution396 {
public:
    static void rotateRight(std::vector<int>& nums, int k)
    {
        const auto size = nums.size();
        for (int j = 0; j < k; ++j)
        {
            const auto tmp = nums[size - 1];
            for (auto i = size - 1; i >= 1; --i)
            {
                nums[i] = nums[i - 1];
            }
            nums[0] = tmp;
        }
    }

public:
    static int maxRotateFunction(const std::vector<int>& nums) {
        auto t = nums;

        rotateRight(t,2);
        std::cout << t << std::endl;
        return 0;
    }
};

#endif //SOLUTION396_H
