//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION5_H
#define SOLUTION5_H

class Solution5 {
private:
    static bool palindrome(int offset, int length, std::string& s)
    {
        if (length == 1 || length == 2 && s[offset] == s[offset + 1])
        {
            return true;
        }
        if (s[offset] == s[offset + length - 1])
        {
            if (palindrome(offset + 1, length - 2, s))
            {
                return true;
            }
        }
        return false;
    }

public:
    static std::string longestPalindrome(std::string s)
    {
        int m = std::numeric_limits<int>::min();
        std::string longest;
        for (int length = 1; length < s.size(); ++length)
        {
            for (int offset = 0; offset <= s.size() - length; ++offset)
            {
                if (palindrome(offset, length, s))
                {
                    m = std::max(m, length);
                    longest = s.substr(offset, length);
                }
            }
        }
        return longest;
    }
};

#endif //SOLUTION5_H
