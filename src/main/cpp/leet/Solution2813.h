//
// Created by Fredrik Dahlberg on 2024-11-21.
//

#ifndef SOLUTION2813_H
#define SOLUTION2813_H

#include <vector>
#include <unordered_set>
#include <stack>

class Solution2813 {
public:
    static uint64_t findMaximumElegance(std::vector<std::vector<int>>& items, const int length)
    {
        size_t totalProfit = 0;
        std::unordered_set<int> categories;
        std::stack<int> duplicateProfits;
        std::ranges::sort(items, std::greater<>());
        for (int i = 0; i < length; i++) {
            const auto& item = items[i];
            const int profit = item.front();
            const int category = item.back();
            totalProfit += profit;
            if (categories.contains(category))
            {
                duplicateProfits.push(profit);
            }
            else
            {
                categories.insert(category);
            }
        }

        auto elegance = totalProfit + categories.size() * categories.size();
        for (int i = length; i < items.size(); ++i) {
            const auto& item = items[i];
            const int profit = item.front();
            const int category = item.back();
            if (!categories.contains(category) && !duplicateProfits.empty()) {
                totalProfit -= duplicateProfits.top();
                totalProfit += profit;
                duplicateProfits.pop();

                categories.insert(category);
                elegance = std::max(elegance, categories.size() * categories.size() + totalProfit);
            }
        }
        return elegance;
    }
};

#endif //SOLUTION2813_H
