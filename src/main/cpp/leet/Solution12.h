//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION12_H
#define SOLUTION12_H

#include <ranges>

class Solution12 {
private:
    struct Numeral
    {
        int value;
        std::string string;
    };
    static constexpr Numeral numerals[20] = {
        {1, "I" },
        { 4, "IV"},
        { 5, "V" },
        { 9, "IX" },
        { 10, "X"},
        { 20, "XX"},
        { 30, "XXX" },
        { 40, "XL" },
        { 50, "L" },
        { 90, "XC" },
        { 100, "C" },
        { 200, "CC" },
        { 300, "CCC" },
        { 400, "CD" },
        { 500, "D", },
        { 900, "CM" },
        { 1000, "M" },
        { 2000, "MM" },
        { 3000, "MMM" },
        { 9999, "_" }
    };
public:
    static std::string intToRoman(const int number)
    {
        auto i = std::ranges::count_if(numerals, [&](const auto& numeral) {
            return numeral.value < number;
        });

        int remaining = number;
        std::string result;
        while (remaining >= 1)
        {
            auto&[value, string] = numerals[i];
            if (remaining < value)
            {
                --i;
            }
            else
            {
                remaining -= value;
                result.append(string);
            }
        }
        return result;
    }
};

#endif //SOLUTION12_H
