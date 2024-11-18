//
// Created by Fredrik Dahlberg on 2024-11-13.
//
#ifndef SOLUTION63_H
#define SOLUTION63_H

class Solution63
{
private:
    using Path = std::vector<char>;

    static void uniquePathsWithObstacles(const int m,
                                         const int n,
                                         const int x,
                                         const int y,
                                         const std::vector<std::vector<int> > &grid,
                                         Path &path,
                                         std::vector<Path> &paths)
    {
        if (m == x && n == y)
        {
            paths.push_back(path);
        } else
        {
            if (grid[y][x] != 0)
            {
                return;
            }
            if (x < m)
            {
                path.emplace_back('R');
                uniquePathsWithObstacles(m, n, x + 1, y, grid, path, paths);
                path.pop_back();
            }
            if (y < n)
            {
                path.emplace_back('D');
                uniquePathsWithObstacles(m, n, x, y + 1, grid, path, paths);
                path.pop_back();
            }
        }
    }

public:
    static int uniquePathsWithObstacles(const std::vector<std::vector<int> > &grid)
    {
        Path path;
        std::vector<Path> paths;
        const auto m = grid[0].size();
        const auto n = grid.size();
        uniquePathsWithObstacles(m - 1, n - 1, 0, 0, grid, path, paths);
        for (auto &p: paths)
        {
            std::cout << p << std::endl;
        }
        return paths.size();
    }
};

#endif //SOLUTION63_H
