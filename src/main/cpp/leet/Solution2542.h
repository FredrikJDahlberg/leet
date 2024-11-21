//
// Created by Fredrik Dahlberg on 2024-11-21.
//

#ifndef SOLUTION2542_H
#define SOLUTION2542_H

#include <vector>
#include <queue>

class Solution2542 {
public:
    static int64_t maxScore(const std::vector<int>& nums1,
                            const std::vector<int>& nums2,
                            const int length) {
        std::vector<std::pair<int, int>> values{};
        values.reserve(nums1.size());
        for (int i = 0; i < nums1.size(); ++i)
        {
            values.emplace_back(nums2[i], nums1[i]);
        }
        // values in descending order: (4,2) (3,3) (2,1) (1,3)
        std::ranges::sort(values, std::greater<>{});

        int sum = 0;
        int score = 0;
        std::priority_queue<int, std::vector<int>, std::greater<>> queue;
        for (const auto& [value2, value1] : values) {
            queue.push(value1);
            sum += value1;
            if (queue.size() > length)
            {
                sum -= queue.top();
                queue.pop();
            }
            if (queue.size() == length)
            {
                score = std::max(score, sum * value2);
            }
        }
        return score;
    }
};

#endif //SOLUTION2542_H
