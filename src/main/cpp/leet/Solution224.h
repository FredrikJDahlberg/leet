//
// Created by Fredrik Dahlberg on 2024-10-23.
//

#ifndef SOLUTION224_H
#define SOLUTION224_H

enum class Type { PLUS, MINUS, LPAREN, RPAREN, NUMBER, SPACE, EMPTY };

class Solution224
{
private:

    struct Token
    {
        int value;
        Type type;

        [[nodiscard]] bool match(Type type) const
        {
            return this->type == type;
        }
    };

    std::array<Token, 32> tokens{};
    int paren{};

    static int tokenize(const std::string_view &str, const size_t position, size_t remaining, Token &token)
    {
        if (remaining <= 0)
        {
            return 0;
        }

        token.value = 0;
        token.type = Type::SPACE;
        int consumed = 0;
        for (auto i = position; i < position + remaining; ++i)
        {
            auto ch = str[i];
            if (std::isdigit(ch))
            {
                token.type = Type::NUMBER;
                token.value *= 10;
                token.value += ch - '0';
                ++consumed;
            }
            else
            {
                if (token.type == Type::NUMBER)
                {
                    return consumed;
                }
                switch (ch)
                {
                    case '+':
                        token.type = Type::PLUS;
                        return consumed + 1;
                    case '-':
                        token.type = Type::MINUS;
                        return consumed + 1;
                    case '(':
                        token.type = Type::LPAREN;
                        return consumed + 1;
                    case ')':
                        token.type = Type::RPAREN;
                        return consumed + 1;
                    case ' ':
                        ++consumed;
                    break;
                    default:
                        break;
                }
            }
        }
        return consumed;
    }

public:
    Solution224() = default;

    int calculate(const std::string &expr) // copy
    {
        const std::string_view str{expr};
        int position = 0;
        auto remaining = expr.size();
        paren = 0;
        size_t count = 0;
        while (position < expr.size())
        {
            const auto consumed = tokenize(str, position, remaining, tokens[count]);
            ++count;
            remaining -= consumed;
            position += consumed;
        }
        tokens[count].type = Type::EMPTY;
        tokens[count].value = 0;
        ++count;
        int result = 0;
        int offset = 0;
        while (hasRemaining(offset))
        {
            if (!eval(offset, result))
            {
                throw std::invalid_argument("Invalid eval");
            }
        }
        if (paren != 0)
        {
            throw std::invalid_argument("Invalid parenthesis");
        }
        if (tokens[offset].type != Type::EMPTY)
        {
            throw std::invalid_argument("incomplete expression");
        }
        return result;
    }

    bool eval(int &position, int &result)
    {
        if (tokens[position].type == Type::EMPTY)
        {
            // return false;
        }
        int term2 = 0;
        auto [value, type] = tokens[position];
        switch (type)
        {
            case Type::NUMBER:
                result = value;
                ++position;
                if (!eval(position, result))
                {
                    return false;
                }
                break;
            case Type::LPAREN:
                ++position;
                ++paren;
                if (!eval(position, result))
                {
                    return false;
                }
                break;
            case Type::RPAREN:
                ++position;
                --paren;
                break;
            case Type::PLUS:
                ++position;
                if (!eval(position, term2))
                {
                    return false;
                }
                result += term2;
                break;
            case Type::MINUS:
                ++position;
                if (!eval(position, term2))
                {
                    return false;
                }
                result -= term2;
                break;
            default:
                break;
        }
        return true;
    }

    [[nodiscard]] bool hasRemaining(int position) const
    {
        return tokens[position].type != Type::EMPTY;
    }
};

#endif //SOLUTION224_H
