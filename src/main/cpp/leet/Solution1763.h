//
// Created by Fredrik Dahlberg on 2024-11-24.
//

#ifndef SOLUTION1763_H
#define SOLUTION1763_H

#include <string>

class Solution1763
{
public:
    static std::string longestNiceSubstring(const std::string& str)
    {
        const auto size = str.size();
        int maxLen = INT_MIN;
        int maxPos = -1;
        for (int len = 2; len <= size; ++len)
        {
            for (int pos = 0; pos <= size - len; ++pos)
            {
                std::vector<int8_t> counts(32);
                int unique = 0;
                for (int j = pos; j < pos + len; ++j)
                {
                    const auto ch = str[j];
                    const bool upper = std::isupper(ch);
                    const auto offset = upper ? 'A' : 'a';
                    const int position = ch - offset;
                    if (counts[position] == 0)
                    {
                        ++unique;
                    }
                    counts[position] |= static_cast<int8_t>(upper) + 1;
                }
                auto const count = std::ranges::count_if(counts, [](auto v) {
                    return v == 3;
                });
                if (count == unique && len > maxLen)
                {
                    maxLen = len;
                    maxPos = pos;
                }
                std::ranges::fill(counts, 0);
            }
        }
        return maxPos == -1 ? "" : str.substr(maxPos, maxLen);
    }
};

#endif //SOLUTION1763_H
