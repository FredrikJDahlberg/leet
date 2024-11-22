//
// Created by Fredrik Dahlberg on 2024-11-22.
//

#ifndef SOLUTION406_H
#define SOLUTION406_H

#include <vector>

class Solution406
{
public:
    static auto reconstructQueue(std::vector<std::vector<int>>& peoples)
    {
        std::ranges::sort(peoples, [](const std::vector<int>& a, const std::vector<int>& b)
        {
            const auto height0 = a.front();
            const auto count0 = a.back();
            const auto height1 = b.front();
            const auto count1 = b.back();
            return  height0 > height1 || height0 == height1 && count0 < count1;
        });

        std::vector<std::vector<int>> result;
        for (const auto& people : peoples)
        {
            const auto count = people[1];
            result.insert(result.begin() + count, people);
        }
        return result;
    }
};

#endif //SOLUTION406_H
