//
// Created by Fredrik Dahlberg on 2024-11-19.
//

#ifndef SOLUTION63_2_H
#define SOLUTION63_2_H

#include <vector>

class Solution63_2 {
private:
    static void uniquePathsWithObstacles(int x, int y, int ex, int ey, std::vector<std::vector<int>>& grid, int& count)
    {
        if (x < 0 || y < 0 || x == grid[0].size() || y == grid.size())
        {
            return;
        }
        if (x == ex && y == ey)
        {
            ++count;
            return;
        }

        auto element = grid[y][x];
        if (element == 1)
        {
            return;
        }

        uniquePathsWithObstacles(x + 1, y, ex, ey, grid, count);
        uniquePathsWithObstacles(x, y + 1, ex, ey, grid, count);
    }

public:
    static int uniquePathsWithObstacles(std::vector<std::vector<int>>& grid) {
        int ex = grid[0].size() - 1;
        int ey = grid.size() - 1;
        int count = 0;
        uniquePathsWithObstacles(0, 0, ex, ey, grid, count);
        return count;
    }
};

#endif //SOLUTION63_2_H
