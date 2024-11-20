//
// Created by Fredrik Dahlberg on 2024-11-20.
//

#ifndef SOLUTION115_H
#define SOLUTION115_H

#include <string>

class Solution115 {
public:
    static int numDistinct(const std::string& longStr, const std::string& shortStr)
    {
        int count = 0;
        for (int preLen = 1; preLen < shortStr.length(); ++preLen)
        {
            for (int preOff = 0; preOff < longStr.length(); ++preOff)
            {
                auto longSize = longStr.size();
                auto shortSize = shortStr.size();
                const auto sufLen = shortSize - preLen;
                for (int sufOff = preOff + preLen; sufOff <= longSize - sufLen; ++sufOff)
                {
                    const auto prefix = longStr.substr(preOff, preLen);
                    const auto suffix = longStr.substr(sufOff, sufLen);
                    if (prefix.length() + suffix.length() == shortSize &&
                        shortStr.starts_with(prefix) && shortStr.ends_with(suffix))
                    {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};

#endif //SOLUTION115_H
