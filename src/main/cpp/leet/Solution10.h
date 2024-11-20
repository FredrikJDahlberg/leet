//
// Created by Fredrik Dahlberg on 2024-11-20.
//

#ifndef SOLUTION10_H
#define SOLUTION10_H

#include <string>

class Solution10 {

    enum class State { CHAR, WILD, MISMATCH };

    constexpr static char ANY = CHAR_MIN;

public:

    static bool isMatch(std::string string, std::string pattern)
    {
        int stringPos = 0;
        auto stringSize = string.size();
        int patternPos = 0;
        char match = ANY;
        State state = State::CHAR;
        while (stringPos < stringSize)
        {
            auto p = pattern[patternPos];
            auto s = string[stringPos];
            switch (state)
            {
                case State::CHAR:
                    if (s == p)
                    {
                        match = s;
                        ++stringPos;
                        ++patternPos;
                    }
                    else if (p == '.')
                    {
                        match = ANY;
                        ++patternPos;
                        ++stringPos;
                    }
                    else if (p == '*')
                    {
                        state = State::WILD;
                    }
                    else
                    {
                        ++patternPos;
                        state = State::MISMATCH;
                    }
                    break;
                case State::WILD:
                    if (s == match || match == ANY)
                    {
                        ++stringPos;
                    }
                    else
                    {
                        ++patternPos;
                        state = State::CHAR;
                    }
                    break;
                case State::MISMATCH:
                    if (p == '*')
                    {
                        state = State::WILD;
                    }
                    else
                    {
                        return false;
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
