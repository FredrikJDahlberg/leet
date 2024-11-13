//
// Created by Fredrik Dahlberg on 2024-11-12.
//

#ifndef SOLUTION60_H
#define SOLUTION60_H
#include <numeric>

/*
class Solution60
{
public:
    std::string permutation(int n, int k)
    {
        std::vector<int> res;
        fact(n, res);
        for (auto r : res)
        {
            std::cout << r << "\n";
        }
        return {};
    }

private:

    // n = 1, k = 1 -> 1
    // n = 2, k = 1 -> 12, 21 -> 12
    // n = 2, k = 2 -> 12, 21 -> 21
    // n = 3, 123, 132, 213, 231, 312, 321
    //
    void fact(int n, std::vector<int>& res)
    {
        if (n == 1) {
            res.push_back(1);
            return;
        }

        //for (int i = 1; i <= n; i++) {
        //}
        res.push_back(n);
        fact(n - 1, res);
    }
};
*/
class Solution60 {
private:

    static void generate(const int n,
                         int& k,
                         std::vector<int8_t>& numbers,
                         std::string& string)
    {
        if (n == 1)
        {
            if (--k == 0)
            {
                for (const auto number : numbers)
                {
                    string.push_back(static_cast<char>(number + '0'));
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
