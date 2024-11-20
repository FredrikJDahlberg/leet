//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION150_H
#define SOLUTION150_H

class Solution150
{
    struct Token
    {
        Type type;
        long value;

        Token() = default;

        Token(const Type t, const long val) : type(t), value(val)
        {
        }
    };

    std::stack<Token> stack;

public:
    long evalRPN(const std::vector<std::string>& tokens)
    {
        for (auto& str: tokens)
        {
            long result = 0;
            if (std::isdigit(str[0]))
            {
                result = std::strtol(str.c_str(), nullptr, 10);
            }
            else if (stack.size() >= 2)
            {
                const Token term1 = stack.top();
                stack.pop();
                const Token term2 = stack.top();
                stack.pop();
                switch (str[0])
                {
                    case '+':
                        result = term1.value + term2.value;
                        break;
                    case '-':
                        result = term1.value - term2.value;
                        break;
                    case '*':
                        result = term1.value * term2.value;
                        break;
                    case '/':
                        result = term1.value / term2.value;
                        break;
                    default:
                        break;
                }
            }
            stack.emplace(Type::NUMBER, result);
        }

        const auto value = stack.top().value;
        stack.pop();
        return value;
    }
};

#endif //SOLUTION150_H
