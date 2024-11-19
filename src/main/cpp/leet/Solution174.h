//
// Created by Fredrik Dahlberg on 2024-11-19.
//

#ifndef SOLUTION174_H
#define SOLUTION174_H

#include <vector>

class Solution174 {
private:
    static int findMin(const size_t x,
                       const size_t y,
                       const size_t xm,
                       const size_t ym,
                       const int health,
                       const int minHealth,
                       std::vector<std::vector<int>>& dungeon) {
        if (x >= xm || y >= ym)
        {
            return INT32_MIN;
        }

        auto const newHealth = health + dungeon[y][x];
        auto const newMinHealth = std::min(newHealth, minHealth);
        if (x == xm - 1 && y == ym - 1)
        {
            return newMinHealth;
        }
        return std::max(findMin(x + 1, y, xm, ym, newHealth, newMinHealth, dungeon),
                        findMin(x, y + 1, xm, ym, newHealth, newMinHealth, dungeon));
    }

public:
    static int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        return 1 - findMin(0, 0, dungeon[0].size(), dungeon.size(), 0, INT32_MAX, dungeon);
    }
};

#endif //SOLUTION174_H
