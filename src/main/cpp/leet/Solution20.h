//
// Created by Fredrik Dahlberg on 2024-10-23.
//

#ifndef SOLUTION20_H
#define SOLUTION20_H

class Solution20
{
private:
    std::stack<char> stack;

public:
    // true: ()[]{}, false (], true: ([])
    bool isValid(std::string&& s)
    {
        std::cout << "str = " << s << std::endl;
        for (char ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                stack.push(ch);
            }
            else
            {
                if (stack.empty())
                {
                    std::cout << "false\n";
                    return false;
                }
                const auto match = stack.top();
                stack.pop();
                if ((match != '(' || ch != ')') && (match != '{' || ch != '}') && (match != '[' || ch != ']'))
                {
                    std::cout << "false\n";
                    return false;
                }
            }
        }
        std::cout << "true\n";
        return true;
    }
};

#endif //SOLUTION20_H
