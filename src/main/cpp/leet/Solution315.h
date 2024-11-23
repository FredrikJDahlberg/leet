//
// Created by Fredrik Dahlberg on 2024-11-23.
//

#ifndef SOLUTION315_H
#define SOLUTION315_H

#include <vector>

class Solution315
{
public:
    static auto countSmaller(const std::vector<int>& numbers)
    {
        std::vector counts(numbers.size(), 0);
        for (auto i = 0; i < numbers.size() - 1; ++i)
        {
            for (auto j = i + 1; j < numbers.size(); ++j)
            {
                if (numbers[i] > numbers[j])
                {
                    ++counts[i];
                }
            }
        }
        return counts;
    }

    static auto countSmaller2(const std::vector<int>& numbers)
    {
        std::vector result(numbers.size(), 0);
        std::multiset<int> set;
        for (int i = static_cast<int>(numbers.size()) - 1; i >= 0; --i)
        {
            auto number = numbers[i];
            set.insert(number);
            result[i] = static_cast<int>(std::distance(set.begin(), set.lower_bound(number)));
        }
        return result;
    }
};

#endif //SOLUTION315_H
