//
// Created by Fredrik Dahlberg on 2024-11-17.
//

#ifndef SOLUTION65_H
#define SOLUTION65_H

class Solution65
{
    enum class State
    {
        INT, EXP, DEC
    };

public:

    static bool isNumber(const std::string& str) {
        if (str.empty())
        {
            return false;
        }

        State state = State::INT;
        bool digits = false;
        for (int position = 0; position < str.length(); ++position)
        {
            const auto ch = str[position];
            switch (state)
            {
                case State::INT:
                    if (ch == '+' || ch == '-')
                    {
                        if (position != 0)
                        {
                            return false;
                        }
                        digits = false;
                    }
                    else if (std::isdigit(ch))
                    {
                        digits = true;
                    }
                    else if ((ch == 'e' || ch == 'E') && digits)
                    {
                        state = State::EXP;
                        digits = false;
                    }
                    else if (ch == '.')
                    {
                        state = State::DEC;
                        digits = false;
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case State::DEC:
                    if (ch == 'e' || ch == 'E')
                    {
                        state = State::EXP;
                        digits = false;
                    }
                    else if (std::isdigit(ch))
                    {
                        digits = true;
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case State::EXP:
                    if (ch == '+' || ch == '-')
                    {
                    }
                    else if (std::isdigit(ch))
                    {
                        digits = true;
                    }
                    else
                    {
                        return false;
                    }
                    break;
            }
        }
        return digits;
    }
};

#endif //SOLUTION65_H
