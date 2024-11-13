//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION214_H
#define SOLUTION214_H

class Solution214 {
public:
    static std::string shortestPalindrome(const std::string& str) {
        size_t len = 0;
        size_t left = 0;
        auto right = str.length() - 1;
        while (left < right)
        {
            if (str[left] == str[right])
            {
                ++left;
                ++len;
            }
            --right;
        }

        std::string pal;
        for (auto i = str.length() - 1; i > right + len; --i)
        {
            pal += str[i];
        }
        pal += str;
        return pal;
    }
};

#endif //SOLUTION214_H
