//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION980_H
#define SOLUTION980_H

class Solution980
{
public:
    enum class Direction { UP, DOWN, LEFT, RIGHT };

private:
    using Path = std::vector<std::pair<int, int> >;

    static void uniquePaths(const int m,
                            const int n,
                            std::vector<std::vector<int> > &grid,
                            const int stopX,
                            const int stopY,
                            Direction dir,
                            int x,
                            int y,
                            Path &path,
                            std::vector<Path> &paths)
    {
        if (x == stopX && y == stopY)
        {
            path.emplace_back(y, x);
            paths.push_back(path);
            path.pop_back();
        } else
        {
            int deltaX = 0;
            int deltaY = 0;
            Direction newDir = dir;
            switch (dir)
            {
                case Direction::RIGHT:
                    if (x < m)
                    {
                        deltaX = 1;
                    } else
                    {
                        deltaY = 1;
                        newDir = Direction::LEFT;
                    }
                    break;
                case Direction::LEFT:
                    if (x > 0)
                    {
                        deltaX = -1;
                    } else
                    {
                        deltaY = 1;
                        newDir = Direction::RIGHT;
                    }
                    break;
                case Direction::DOWN:
                    if (y < n)
                    {
                        deltaY = 1;
                    } else
                    {
                        deltaX = 1;
                        newDir = Direction::UP;
                    }
                    break;
                case Direction::UP:
                    if (y > 0)
                    {
                        deltaY = -1;
                    } else
                    {
                        deltaX = 1;
                        newDir = Direction::DOWN;
                    }
                    break;
            }

            //const auto &row = grid[y];
            //auto newValue = grid[y + deltaY][x + deltaX];
            if (std::ranges::find(path, std::make_pair(y, x)) == path.end())
            {
                path.emplace_back(y, x);
                uniquePaths(m, n, grid, stopX, stopY, newDir, x + deltaX, y + deltaY, path, paths);
                path.pop_back();
            }

            /*
            else
            {
                if (newValue == 2 && m * n - 1 == grid.size())
                {
                    path.emplace_back(y, x);
                    uniquePaths(m, n, grid, stopX, stopY, newDir, x + deltaX, y + deltaY, path, paths);
                    path.pop_back();
                }
                else
                {
                    switch (dir)
                    {
                        case Direction::RIGHT:
                            newDir = Direction::DOWN;
                            break;
                        case Direction::DOWN:
                            newDir = Direction::RIGHT;
                            break;
                        case Direction::LEFT:
                            newDir = Direction::UP;
                            break;
                        case Direction::UP:
                            newDir = Direction::LEFT;
                            break;
                    }
                    path.emplace_back(y, x);
                    uniquePaths(m, n, grid, stopX, stopY, newDir, x, y, path, paths);
                    path.pop_back();
                }
            }
            */
        }
    }

public:
    static size_t uniquePathsWithObstacles(std::vector<std::vector<int> > &grid)
    {
        std::vector<Path> paths;
        Path path;
        const auto m = grid[0].size();
        const auto n = grid.size();
        int startX = 0;
        int startY = 0;
        int stopX = 0;
        int stopY = 0;
        int count = 2;
        for (int x = 0; x < m; ++x)
        {
            for (int y = 0; y < n; ++y)
            {
                auto &row = grid[y];
                switch (auto &ch = row[x])
                {
                    case 0:
                        ++count;
                        break;
                    case 1:
                        startX = x;
                        startY = y;
                        break;
                    case 2:
                        stopX = x;
                        stopY = y;
                        break;
                    default:
                        break;
                }
            }
        }
        // uniquePaths(m - 1, n - 1, grid, stopX, stopY, Direction::RIGHT, startX, startY, path, paths);
        uniquePaths(m - 1, n - 1, grid, stopX, stopY, Direction::DOWN, startX, startY, path, paths);
        for (auto &p: paths)
        {
            std::cout << p << std::endl;
        }
        return paths.size();
    }
};

#endif //SOLUTION980_H
