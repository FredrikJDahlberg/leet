//
// Created by Fredrik Dahlberg on 2024-11-19.
//

#ifndef SOLUTION980_1_H
#define SOLUTION980_1_H

#include <vector>

class Solution980 {
private:
    using Grid = std::vector<std::vector<int>>;

    static void uniquePaths(const int x, const int y, const int ex, const int ey, const int empty, Grid& grid, int& count)
    {
        if (x < 0 || x == grid[0].size() || y < 0 || y == grid.size())
        {
            return;
        }
        if (grid[y][x] < 0)
        {
            return;
        }
        if (x == ex && y == ey)
        {
            if (empty == 0)
            {
                ++count;
            }
        }
        else
        {
            grid[y][x] = -2;
            uniquePaths(x + 1, y, ex, ey, empty - 1, grid, count);
            uniquePaths(x - 1, y, ex, ey, empty - 1, grid, count);
            uniquePaths(x, y + 1, ex, ey, empty - 1, grid, count);
            uniquePaths(x, y - 1, ex, ey,  empty - 1, grid, count);
            grid[y][x] = 0;
        }
    }

public:
    static int uniquePaths(Grid& grid)
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

        int count = 0;
        uniquePaths(bx, by, ex, ey, empty, grid, count);
        return count;
    }
};

#endif //SOLUTION980_1_H
