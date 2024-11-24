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

    static std::vector<int> beautifulArray2(const int n)
    {
        std::vector<int> result(n);
        std::vector<int> numbers(n);
        std::iota(numbers.begin(), numbers.end(), 1);
        generate(n, numbers, result);
        return result;
    }
private:
    static void generate(const int n, std::vector<int>& numbers, std::vector<int>& result)
    {
        if (n == 1)
        {
            bool valid = true;
            for (int i = 0; i < n; i += 3)
            {
                valid = valid && (numbers[i] + numbers[i + 2] != numbers[i + 1] * 2);
            }
            if (valid)
            {
                std::ranges::copy(numbers, result.begin());
            }
        }
        else
        {
            generate(n - 1, numbers, result);
            for (int i = 0; i < n - 1; ++i)
            {
                const auto pos = n % 2 == 0 ? i : 0;
                std::swap(numbers[pos], numbers[n - 1]);
                generate(n - 1, numbers, result);
            }
        }
    }
};

#endif //SOLUTION932_H
