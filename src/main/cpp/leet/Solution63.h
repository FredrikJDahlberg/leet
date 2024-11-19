//
// Created by Fredrik Dahlberg on 2024-11-19.
//

#ifndef SOLUTION63_2_H
#define SOLUTION63_2_H

#include <vector>

class Solution63 {
private:
    static int uniquePathsWithObstacles(const int x,
                                         const int y,
                                         const size_t ex,
                                         const size_t ey,
                                         const std::vector<std::vector<int>>& grid)
    {
        if (x == ex && y == ey)
        {
            return 1;
        }
        if (x < 0 || y < 0 || x == grid[0].size() || y == grid.size())
        {
            return 0;
        }
        if (grid[y][x] == 1)
        {
            return 0;
        }
        return uniquePathsWithObstacles(x + 1, y, ex, ey, grid) +
               uniquePathsWithObstacles(x, y + 1, ex, ey, grid);
    }

public:
    static int uniquePathsWithObstacles(const std::vector<std::vector<int>>& grid) {
        return uniquePathsWithObstacles(0, 0, grid[0].size() - 1, grid.size() - 1, grid);
    }
};

#endif //SOLUTION63_2_H
