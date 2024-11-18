//
// Created by Fredrik Dahlberg on 2024-11-12.
//

#ifndef SOLUTION60_H
#define SOLUTION60_H
#include <numeric>

class Solution60 {
private:

    static void generate(const int n, int& k, std::vector<int8_t>& numbers, std::string& string)
    {
        if (n == 1)
        {
            if (--k == 0)
            {
                for (const auto number : numbers)
                {
                    string.push_back(static_cast<char>(number) + '0');
                }
            }
        }
        else
        {
            generate(n - 1, k, numbers, string);
            for (int i = 0; i < n - 1; ++i)
            {
                const auto pos = n % 2 == 0 ? i : 0;
                std::swap(numbers[pos], numbers[n - 1]);
                generate(n - 1, k, numbers, string);
            }
        }
    }

public:

    static std::string getPermutation(const int n, const int k)
    {
        std::vector<int8_t> numbers(n);
        std::iota(numbers.begin(), numbers.end(), 1);
        std::string string;
        int count = k;
        generate(n, count, numbers, string);
        return string;
    }
};

#endif //SOLUTION60_H
