//
// Created by Fredrik Dahlberg on 2024-11-23.
//

#ifndef SOLUTION932_H
#define SOLUTION932_H

#include <vector>

class Solution932 {
public:
    static std::vector<int> beautifulArray(const int n)
    {
        if (n == 1)
        {
            return { 1 };
        }

        const std::vector<int> left = beautifulArray((n + 1) >> 1);
        const std::vector<int> right = beautifulArray(n >> 1);
        int pos = -1;
        std::vector<int> result(n);
        for (const auto& value : left)
        {
            result[++pos] = value * 2 - 1;
        }
        for (const auto& value : right)
        {
            result[++pos] = value * 2;
        }
        return result;
    }
};

#endif //SOLUTION932_H
