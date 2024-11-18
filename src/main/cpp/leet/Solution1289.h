//
// Created by Fredrik Dahlberg on 2024-11-18.
//

#ifndef SOLUTION1289_H
#define SOLUTION1289_H

#include <vector>

class Solution1289 {
public:
    static int minFallingPathSum(const std::vector<std::vector<int>>& grid)
    {
        return minFallingPathSum(grid, grid.size(), grid.size(), 0, INT32_MAX);
    }

private:
    static size_t minFallingPathSum(const std::vector<std::vector<int>>& grid,
                                    const size_t row,
                                    const size_t col,
                                    const size_t sum,
                                    const size_t min)
    {
        if (row == 0)
        {
            return std::min(sum, min);
        }

        size_t nextMin = min;
        for (int c = 0; c < grid.size(); ++c)
        {
            if (col != c)
            {
                nextMin = minFallingPathSum(grid, row - 1, c, sum + grid[row - 1][c], nextMin);
            }
        }
        return nextMin;
    }
};

#endif //SOLUTION1289_H
