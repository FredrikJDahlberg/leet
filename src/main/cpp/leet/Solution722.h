//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION722_H
#define SOLUTION722_H

class Solution722
{
    enum class State { COMMENT, MULTI, MULTI_END, REMOVE, KEEP, NEXT, DONE };

public:
    static std::vector<std::string> removeComments(std::vector<std::string> &source)
    {
        auto state = State::KEEP;
        int line = 0;
        int col = 0;
        while (state != State::DONE)
        {
            const auto ch = source[line][col];
            switch (state)
            {
                case State::KEEP:
                    if (ch == '/')
                    {
                        ++col;
                        state = State::COMMENT;
                    } else
                    {
                        ++col;
                    }
                    break;
                case State::COMMENT:
                    if (ch == '*')
                    {
                        state = State::MULTI;
                        source[line].erase(col);
                    } else if (ch == '/')
                    {
                        source[line].erase(col);
                        state = State::KEEP;
                    } else
                    {
                        source[line].erase(col);
                    }
                    break;
                case State::MULTI:
                    if (ch == '*')
                    {
                        state = State::MULTI_END;
                    } else
                    {
                        source[line].erase(col);
                    }
                    break;
                case State::MULTI_END:
                    if (ch == '/')
                    {
                        source[line].erase(col, col + 1);
                    } else
                    {
                        state = State::MULTI;
                    }
                    break;
                default:
                    break;
            }
            if (col >= source[line].size())
            {
                ++line;
            }
            if (line == source[line].size())
            {
                state = State::DONE;
            }
        }
        return source;
    }
};

#endif //SOLUTION722_H
