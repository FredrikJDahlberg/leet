//
// Created by Fredrik Dahlberg on 2024-11-19.
//

#ifndef SOLUTION2435_H
#define SOLUTION2435_H

#include <vector>

class Solution2435 {
private:

    static int numberOfPaths(const int k,
                             const size_t x,
                             const size_t y,
                             int sum,
                             const size_t xm,
                             const size_t ym,
                             const std::vector<std::vector<int>>& grid)
    {
        if (x >= xm || y >= ym)
        {
            return 0;
        }

        int count = 0;
        sum += grid[y][x];
        if (x == xm - 1 && y == ym - 1)
        {
            if (sum % k == 0)
            {
                count = 1;
            }
        }
        else
        {
            count = numberOfPaths(k, x + 1, y, sum, xm, ym, grid) + numberOfPaths(k, x, y + 1, sum, xm, ym, grid);
        }
        return count;
    }

public:
    static int numberOfPaths(const std::vector<std::vector<int>>& grid, const int k)
    {
        return numberOfPaths(k, 0, 0, 0, grid[0].size(), grid.size(), grid);
    }
};

#endif //SOLUTION2435_H
