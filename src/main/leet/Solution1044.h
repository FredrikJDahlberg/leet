//
// Created by Fredrik Dahlberg on 2024-11-18.
//

#ifndef SOLUTION1044_H
#define SOLUTION1044_H

#include <string>

class Solution1044 {
public:
    static std::string longestDupSubstring(const std::string& str) {
        const auto size = str.length();
        int max = INT32_MIN;
        std::string maxSub{};
        int count = 0;
        for (int len = 1; len < size - 1; ++len)
        {
            for (int w = 0; w < size - len; ++w)
            {
                std::string sub = str.substr(w, len);
                for (int j = 1; j < size - len - 1; ++j)
                {
                    if (str.substr(j, len) == sub)
                    {
                        max = std::max(len, max);
                        maxSub = sub;
                        ++count;
                    }
                }
            }
        }
        return count >= 2 ? maxSub : "";
    }
};

#endif //SOLUTION1044_H
