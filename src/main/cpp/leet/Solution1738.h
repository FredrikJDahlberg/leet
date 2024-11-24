//
// Created by Fredrik Dahlberg on 2024-11-24.
//

#ifndef SOLUTION1738_H
#define SOLUTION1738_H

#include <vector>

class Solution1738
{
public:
    static int kthLargestValue(const std::vector<std::vector<int>>& matrix, const int k)
    {
        const auto m = static_cast<int>(matrix.size());
        const auto n = static_cast<int>(matrix[0].size());
        std::vector<std::vector<int>> xors(m + 1, std::vector<int>(n + 1));
        std::priority_queue<int, std::vector<int>, std::greater<>> minQueue;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                xors[i][j] = xors[i - 1][j] ^ xors[i][j - 1] ^ xors[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                minQueue.push(xors[i][j]);
                if (minQueue.size() > k)
                {
                    minQueue.pop();
                }
            }
        }
        return minQueue.top();
    }
};

#endif //SOLUTION1738_H
