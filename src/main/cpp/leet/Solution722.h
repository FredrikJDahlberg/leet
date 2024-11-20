//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION722_H
#define SOLUTION722_H

class Solution722
{
private:

    enum class State { CODE, MULTI, NONE };

public:
    static std::vector<std::string> removeComments(const std::vector<std::string>& source)
    {
        std::vector<std::string> result;
        auto state = State::CODE;
        for (auto line : source)
        {
            const size_t length = line.size();
            size_t begin = 0;
            std::string value;
            size_t col = 0;
            while (col < length)
            {
                switch (state)
                {
                    case State::CODE:
                        if (line[col] == '/' && col + 1 < length && line[col + 1] == '*')
                        {
                            state = State::MULTI;
                            if (begin != col)
                            {
                                value.append(line.substr(begin, col - begin - 1));
                            }
                            ++col;
                        }
                        else if (line[col] == '/' && col + 1 < length && line[col + 1] == '/')
                        {
                            state = State::NONE;
                            if (begin != col)
                            {
                                value.append(line.substr(begin, col - begin - 1));
                                col += length;
                            }
                            break;
                        }
                        else
                        {
                            value.push_back(line[col]);
                        }
                        ++col;
                        break;
                    case State::MULTI:
                        if (line[col] == '*' && col + 1 < length && line[col + 1] == '/')
                        {
                            state = State::CODE;
                            begin = col + 2;
                            ++col;
                        }
                        ++col;
                        break;
                    default:
                        break;
                }
            }
            if (state != State::MULTI)
            {
                state = State::CODE;
                if (!value.empty())
                {
                    result.emplace_back(value);
                    value.clear();
                }
            }
        }
        return result;
    }
};

#endif //SOLUTION722_H
