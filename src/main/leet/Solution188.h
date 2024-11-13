//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION188_H
#define SOLUTION188_H

#include <vector>
#include <mach/host_info.h>

class Solution188 {

    struct Position
    {
        int buyPrice = std::numeric_limits<int>::min();
        int profit = 0;
    };

public:
    static int maxProfit(const int k, const std::vector<int>& prices) {
        std::vector<Position> positions(k);
        for(const auto price : prices)
        {
            auto pos = positions.rbegin();
            while (pos != positions.rend() - 1)
            {
                pos->profit = std::max(pos->profit, pos->buyPrice + price);
                pos->buyPrice = std::max(pos->buyPrice, (pos + 1)->profit - price);
                ++pos;
            }
            pos->profit = std::max(pos->profit, pos->buyPrice + price);
            pos->buyPrice = std::max(pos->buyPrice, -price);
        }
        return positions[k - 1].profit;
    }
};

#endif //SOLUTION188_H

