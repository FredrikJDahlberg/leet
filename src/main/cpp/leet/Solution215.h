//
// Created by Fredrik Dahlberg on 2024-11-22.
//

#ifndef SOLUTION215_H
#define SOLUTION215_H

#include <vector>

class Solution215 {
public:
    static int findKthLargest(const std::vector<int>& nums, const int k) {
        std::priority_queue<int, std::vector<int>, std::greater<>> minQueue;
        for (auto num : nums) {
            minQueue.push(num);
            if (minQueue.size() > k)
            {
                minQueue.pop();
            }
        }
        return minQueue.top();
    }
};

#endif //SOLUTION215_H
