//
// Created by Fredrik Dahlberg on 2024-11-20.
//

#ifndef SOLUTION502_H
#define SOLUTION502_H

#include <vector>

class Solution502 {
private:
    static int findMaxCap(const int count,
                          const int capital,
                          std::vector<int>& profits,
                          const std::vector<int>& costs)
    {
        if (count < 0)
        {
            return 0;
        }

        int profit = INT_MIN;
        int j = 0;
        for (int i = 0; i < profits.size(); ++i)
        {
            if (costs[i] <= capital && profits[i] > profit)
            {
                profit = profits[i];
                j = i;
            }
        }
        profits[j] = -profit;
        const auto newProfit = std::max(capital, findMaxCap(count - 1, capital + profit, profits, costs));
        profits[j] = profit;
        return newProfit;
    }

public:
    static int findMaximizedCapital(const int count,
                                    const int capital,
                                    const std::vector<int>& profits,
                                    const std::vector<int>& capitals)
    {
        return findMaxCap(count, capital, const_cast<std::vector<int>&>(profits), capitals);;
    }
};

#endif //SOLUTION502_H
