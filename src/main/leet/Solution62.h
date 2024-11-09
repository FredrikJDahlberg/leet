//
// Created by Fredrik Dahlberg on 2024-11-09.
//

#ifndef SOLUTION62_H
#define SOLUTION62_H

class Solution62
{
private:
    using Path = std::vector<char>;

    static void uniquePaths(const int m, const int n, int x, int y, Path& path, std::vector<Path>& paths)
    {
        if (m == x && n == y)
        {
            paths.push_back(path);
        }
        else
        {
            if (x < m)
            {
                path.emplace_back('R');
                uniquePaths(m, n, x + 1, y, path, paths);
                path.pop_back();
            }
            if (y < n)
            {
                path.emplace_back('D');
                uniquePaths(m, n, x, y + 1, path, paths);
                path.pop_back();
            }
        }
    }

public:
    static int uniquePaths(const int m, const int n)
    {
        return (m <= 1 || n <= 1) ? 1 : uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }

    /*
    static auto uniquePaths(int m, int n) -> size_t {
        std::vector<Path> paths;
        Path path;
        uniquePaths(m, n, 1, 1, path, paths);
        for (auto& p : paths)
        {
            std::cout << p << std::endl;
        }
        return paths.size();
    }
    */
};

#endif //SOLUTION62_H
