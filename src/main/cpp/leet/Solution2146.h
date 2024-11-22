//
// Created by Fredrik Dahlberg on 2024-11-22.
//

#ifndef SOLUTION2146_H
#define SOLUTION2146_H

#include <vector>
#include <bitset>

class Solution2146
{
public:
    static auto highestRankedKItems(const std::vector<std::vector<int>>& grid,
                                    const std::vector<int>& pricing,
                                    const std::vector<int>& start,
                                    const int k)
    {
        constexpr int deltas[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        const auto xm = grid[0].size();
        const auto ym = grid.size();
        const auto x = start.back();
        const auto y = start.front();

        std::vector visited(ym, std::vector<bool>(xm));
        const auto low = pricing.front();
        const auto high = pricing.back();
        std::vector<std::vector<int>> result;

        if (grid[y][x] >= low && grid[y][x] <= high)
        {
            result.emplace_back(y, x);
            if (k == 1)
            {
                return result;
            }
        }

        std::queue<std::pair<int, int>> queue{{{y, x}}};
        std::vector<std::vector<int>> neighbours;
        while (!queue.empty())
        {
            for (auto sz = queue.size(); sz > 0; --sz) {
                const auto [i, j] = queue.front();
                queue.pop();
                for (const auto& [dx, dy] : deltas)
                {
                    const int cx = i + dx;
                    const int cy = j + dy;
                    if (cx >= 0 && cx < xm && cy >= 0 && cy < ym)
                    {
                        auto element = grid[cy][cx];
                        if (!visited[cy][cx])
                        {
                            if (element >= low && element <= high)
                            {
                                neighbours.push_back({cy, cx});
                            }
                            queue.emplace(cy, cx);
                            visited[cy][cx] = true;
                        }
                    }
                }
            }
            std::ranges::sort(neighbours, [&](const std::vector<int>& a, const std::vector<int>& b) {
                    const int y1 = a[0];
                    const int x1 = a[1];
                    const int y2 = b[0];
                    const int x2 = b[1];
                    const int p1 = grid[y1][x1];
                    const int p2 = grid[y2][x2];
                    return p1 != p2 ? p1 < p2 : (y1 == y2 ? x1 < x2 : y1 < y2);
            });
            for (const std::vector<int>& neighbour : neighbours) {
                const auto size = result.size();
                if (size < k)
                {
                    result.push_back(neighbour);
                }
                if (size == k)
                {
                    return result;
                }
            }
            neighbours.clear();
        }
        return result;
    }
};

#endif //SOLUTION2146_H
