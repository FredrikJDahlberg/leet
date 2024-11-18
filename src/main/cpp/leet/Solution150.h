//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION1050_H
#define SOLUTION1050_H

class Solution150
{
    enum class Type { PLUS, MINUS, DIV, MULT, NUMBER };

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

    static long term(const std::string &str)
    {
        return std::strtol(str.c_str(), nullptr, 10);
    }

public:
    long evalRPN(const std::vector<std::string> &tokens)
    {
        for (auto &str: tokens)
        {
            long result = 0;
            if (std::isdigit(str[0]))
            {
                result = std::stoi(str);
            } else
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
        return stack.top().value;
    }
};

#endif //SOLUTION1050_H
