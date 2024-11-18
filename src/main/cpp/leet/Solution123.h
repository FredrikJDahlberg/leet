//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION123_H
#define SOLUTION123_H

#include <vector>

class Solution123
{
public:

    static int maxProfit(const std::vector<int>& prices)
    {
        int buyPrice1 = std::numeric_limits<int>::min(); // INT_MIN;
        int buyPrice2 = std::numeric_limits<int>::min(); //INT_MIN;
        int profit1 = 0;
        int profit2 = 0;

        for(const auto price : prices)
        { // buy negative, sell positive
            profit2 = std::max(profit2, buyPrice2 + price);     // The maximum if we've just sold 2nd stock so far.
            buyPrice2 = std::max(buyPrice2, profit1 - price);  // The maximum if we've just buy  2nd stock so far.
            profit1 = std::max(profit1, buyPrice1 + price);     // The maximum if we've just sold 1nd stock so far.
            buyPrice1 = std::max(buyPrice1, -price);          // The maximum if we've just buy  1st stock so far.
        }
        return profit2;
    }
};

#endif //SOLUTION123_H
