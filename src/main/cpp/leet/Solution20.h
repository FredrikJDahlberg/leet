//
// Created by Fredrik Dahlberg on 2024-10-23.
//

#ifndef SOLUTION20_H
#define SOLUTION20_H

class Solution20
{
private:
    std::stack<char> stack;

    void clear()
    {
        while (!stack.empty())
        {
            stack.pop();
        }
    }

public:
    bool isValid(std::string&& str)
    {
        clear();
        for (auto ch : str)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                stack.push(ch);
            }
            else
            {
                if (stack.empty())
                {
                    return false;
                }

                const auto match = stack.top();
                stack.pop();
                if ((match != '(' || ch != ')') && (match != '{' || ch != '}') && (match != '[' || ch != ']'))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif //SOLUTION20_H
