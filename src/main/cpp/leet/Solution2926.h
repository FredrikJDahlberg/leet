//
// Created by Fredrik Dahlberg on 2024-11-24.
//

#ifndef SOLUTION2926_H
#define SOLUTION2926_H

#include <vector>

class Solution2926 {
public:
    static int64_t maxBalancedSubsequenceSum(const std::vector<int>& nums) {

        //
        return 0;
    }

private:

    static std::vector<int> generate(int k, std::vector<int> nums)
    {
        if (k == 1)
        {
            return nums;
        }
        return {};
    }
};

#endif //SOLUTION2926_H
