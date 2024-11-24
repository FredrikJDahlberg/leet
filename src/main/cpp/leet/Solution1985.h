//
// Created by Fredrik Dahlberg on 2024-11-23.
//

#ifndef SOLUTION1985_H
#define SOLUTION1985_H

#include <string>
#include <vector>
#include <queue>

class Solution1985 {
public:
    static std::string kthLargestNumber(const std::vector<std::string>& nums, const int k)
    {
        std::priority_queue<std::string> maxHeap;
        for (auto num : nums)
        {
            maxHeap.push(num);
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};

#endif //SOLUTION1985_H
