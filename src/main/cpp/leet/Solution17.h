//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION17_H
#define SOLUTION17_H

class Solution17
{
private:
    struct Letters
    {
        char chars[5];
    };
    const char letters[10][5] =
    {
        {'?', '\0' },
       {'?', '\0' },
       { 'a', 'b', 'c', '\0' },
       { 'd', 'e', 'f', '\0' },
       { 'g', 'h', 'i', '\0' },
       { 'j', 'k', 'l', '\0' },
       { 'm', 'n', 'o', '\0' },
       { 'p', 'q', 'r', 's', '\0' },
       { 't', 'u', 'v', '\0'},
       { 'w', 'x', 'y', 'z', '\0'}
    };

public:
    [[nodiscard]] std::vector<std::string> letterCombinations(const std::string& digits) const
    {
        std::vector<std::string> results = { "" };
        for (const auto digit : digits)
        {
            const auto* chars = letters[digit - '0'];
            const auto limit = results.size();
            for (int i = 0; i < limit; ++i)
            {
                for (auto chp = chars; *chp != '\0'; ++chp)
                {
                    results.push_back(results[i] + *chp);
                }
            }
            results.erase(results.begin(), results.begin() + limit);
        }
        return results;
    }
};


#endif //SOLUTION17_H
