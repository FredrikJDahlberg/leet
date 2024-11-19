//
// Created by Fredrik Dahlberg on 2024-11-19.
//

#ifndef SOLUTION980_1_H
#define SOLUTION980_1_H

#include <vector>

class Solution980 {
private:
    static int uniquePaths(const size_t x,
                           const size_t y,
                           const size_t ex,
                           const size_t ey,
                           const int empty,
                           std::vector<std::vector<int>>& grid)
    {
        if (x < 0 || x == grid[0].size() || y < 0 || y == grid.size())
        {
            return 0;
        }
        if (grid[y][x] < 0)
        {
            return 0;
        }
        int count = 0;
        if (x == ex && y == ey)
        {
            if (empty == 0)
            {
                count = 1;
            }
        }
        else
        {
            grid[y][x] = -2;
            count += uniquePaths(x + 1, y, ex, ey, empty - 1, grid);
            count += uniquePaths(x - 1, y, ex, ey, empty - 1, grid);
            count += uniquePaths(x, y + 1, ex, ey, empty - 1, grid);
            count += uniquePaths(x, y - 1, ex, ey,  empty - 1, grid);
            grid[y][x] = 0;
        }
        return count;
    }

public:
    static int uniquePaths( std::vector<std::vector<int>>& grid)
    {
        int bx = 0;
        int by = 0;
        int ex = 0;
        int ey = 0;
        int empty = 1;
        for (int y = 0; y < grid.size(); ++y)
        {
            for (int x = 0; x < grid[0].size(); ++x)
            {
                const auto element = grid[y][x];
                if (element == 0)
                {
                    ++empty;
                }
                else if (element == 1)
                {
                    bx = x;
                    by = y;
                }
                else if (element == 2)
                {
                    ex = x;
                    ey = y;
                }
            }
        }
        return uniquePaths(bx, by, ex, ey, empty, grid);
    }
};

#endif //SOLUTION980_1_H
