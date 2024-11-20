//
// Created by Fredrik Dahlberg on 2024-11-20.
//

#ifndef SOLUTION10_H
#define SOLUTION10_H

#include <string>

class Solution10
{
    enum class State { CHAR, WILD, MISMATCH };

    constexpr static char ANY = '.';
    constexpr static char WILD = '*';

public:
    static bool isMatch(const std::string& string, const std::string& pattern)
    {
        const size_t stringSize = string.size();
        size_t stringPos = 0;
        size_t patternPos = 0;
        char match = ANY;
        auto state = State::CHAR;
        while (stringPos < stringSize)
        {
            auto p = pattern[patternPos];
            auto s = string[stringPos];
            switch (state)
            {
                case State::CHAR:
                    if (s == p || p == ANY)
                    {
                        match = p;
                        ++stringPos;
                        ++patternPos;
                    }
                    else if (p == WILD)
                    {
                        state = State::WILD;
                    }
                    else
                    {
                        state = State::MISMATCH;
                        ++patternPos;
                    }
                    break;
                case State::WILD:
                    if (match == s || match == ANY)
                    {
                        ++stringPos;
                    }
                    else
                    {
                        state = State::CHAR;
                        ++patternPos;
                    }
                    break;
                case State::MISMATCH:
                    if (p == WILD)
                    {
                        state = State::WILD;
                    }
                    else
                    {
                        stringPos = stringSize;
                    }
                    break;
                default:
                    break;
            }
        }
        return state != State::MISMATCH;
    }
};

#endif //SOLUTION10_H
