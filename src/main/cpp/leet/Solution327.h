//
// Created by Fredrik Dahlberg on 2024-11-23.
//

#ifndef SOLUTION327_H
#define SOLUTION327_H

#include <vector>

class Solution327 {
public:
    static int countRangeSum(const std::vector<int>& numbers, const int lower, const int upper) {
        int count = 0;
        for (int length = 1; length <= numbers.size(); ++length)
        {
            for (int j = 0; j <= numbers.size() - length; ++j)
            {
                int sum = 0;
                for (int i = j; i < j + length; ++i)
                {
                    sum += numbers[i];
                }
                if (sum >= lower && sum <= upper)
                {
                    ++count;
                }
            }
        }
        return count;
    }

    static size_t countRangeSum2(const std::vector<int>& numbers, const int lower, const int upper) {
        std::vector sums(numbers.size() + 1, 0);
        for (int i = 0; i < numbers.size(); ++i)
        {
            sums[i + 1] = sums[i] + numbers[i];
        }

        int count = 0;
        for (int i = 0; i < sums.size(); ++i)
        {
            for (int j = i + 1; j < sums.size(); ++j)
            {
                const auto sum = sums[j] - sums[i];
                if (sum >= lower && sum <= upper)
                {
                    ++count;
                }
            }
        }
        return count;
    }
};

#endif //SOLUTION327_H
