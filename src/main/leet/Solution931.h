//
// Created by Fredrik Dahlberg on 2024-11-18.
//

#ifndef SOLUTION931_H
#define SOLUTION931_H

#include <vector>

class Solution931 {
public:
    static int minFallingPathSum(const std::vector<std::vector<int>>& matrix) {
        return minFallingPathSum(matrix, matrix.size() - 1, matrix.size() - 1, 0, INT32_MAX);
    }

private:
    static size_t minFallingPathSum(const std::vector<std::vector<int>>& matrix,
                                    const size_t row,
                                    const size_t col,
                                    const size_t sum,
                                    const size_t min) {
        if (row == 0 || col == 0)
        {
            return std::min(sum, min);
        }

        const auto value = matrix[row][col];
        return std::min(minFallingPathSum(matrix, row - 1, col, sum + value, min),
                        minFallingPathSum(matrix, row, col - 1, sum + value, min));
    }
};

#endif //SOLUTION931_H
