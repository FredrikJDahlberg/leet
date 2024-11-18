//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION17_H
#define SOLUTION17_H

#include <string>
#include <vector>

class Solution17
{
private:
    struct Letters
    {
        char chars[5];
    };
    static const char letters[10][5];

public:
    static std::vector<std::string> letterCombinations(const std::string& digits)
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
