//
// Created by Fredrik Dahlberg on 2024-11-21.
//

#ifndef SOLUTION857_H
#define SOLUTION857_H

#include <vector>

class Solution857 {
public:
    static double minCostToHireWorkers(const std::vector<int>& qualities,
                                       const std::vector<int>& wages,
                                       const int length)
    {
        std::vector<std::pair<double, int>> workers;
        const auto size = wages.size();
        workers.reserve(size);
        for (int i = 0; i < size; ++i)
        {
            const auto wage = static_cast<double>(wages[i]);
            const auto quality = qualities[i];
            workers.emplace_back(wage / quality, quality);
        }
        std::ranges::sort(workers); // sorted by wages / quality

        int qualitySum = 0;
        double cost = DBL_MAX;
        std::priority_queue<int> qualityQueue; // 5, 4, 3, ...
        for (auto& [wageQuality, quality] : workers)
        {
            qualityQueue.push(quality);
            qualitySum += quality;
            if (qualityQueue.size() > length)
            {
                qualitySum -= qualityQueue.top();
                qualityQueue.pop();
            }
            if (qualityQueue.size() == length)
            {
                cost = std::min(cost, qualitySum * wageQuality);
            }
        }
        return cost;
    }
};

#endif //SOLUTION857_H
