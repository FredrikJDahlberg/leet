//
// Created by Fredrik Dahlberg on 2024-11-18.
//

#ifndef SOLUTION931_H
#define SOLUTION931_H

#include <vector>

class Solution931 {
public:
    static int minFallingPathSum(const std::vector<std::vector<int>>& matrix) {
        return minFallingPathSum(matrix, matrix.size(), 0, INT32_MAX);
    }

private:
    static int minFallingPathSum(const std::vector<std::vector<int>>& matrix,
                                 const size_t row,
                                 const int sum,
                                 const int min)
    {
        if (row == 0)
        {
            return std::min(sum, min);
        }

        auto nextMin = min;
        for (int c = 0; c < matrix.size(); ++c)
        {
            nextMin = minFallingPathSum(matrix, row - 1, sum + matrix[row - 1][c], nextMin);
        }
        return nextMin;
    }
};

#endif //SOLUTION931_H
