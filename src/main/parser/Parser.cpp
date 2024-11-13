//
// Created by Fredrik Dahlberg on 2024-10-03.
//

#include "Parser.h"

#include <iostream>


Parser::Parser() : success(true), position{0}, count{0}, typeByChar{}
{
    std::ranges::fill(typeByChar, Type::ERROR);
    typeByChar['('] = Type::LPAREN;
    typeByChar[')'] = Type::RPAREN;
    typeByChar['+'] = Type::PLUS;
    typeByChar['-'] = Type::MINUS;
    typeByChar[' '] = Type::SPACE;
    for (auto digit = '0'; digit < '9'; ++digit) {
        typeByChar[digit] = Type::NUMBER;
    }
}

bool Parser::valid() const
{
    return success;
}

int Parser::calculate(const std::string_view& str)
{
    const size_t size = str.size();
    count = 0;
    int offset = 0;
    while (offset < size && tokenize(str, offset, tokens[count]))
    {
        ++count;
    }
    tokens[count++] = Token{};  // sentinel

    clear();
    const auto result = expr();
    success &= tokens[position].type == Type::EMPTY;
    return result;
}

int Parser::expr()
{
    int sum = term();
    if (!success)
    {
        return sum;
    }

    auto type = tokens[position].type;
    if (type == Type::PLUS || type == Type::MINUS)
    {
        while (type == Type::PLUS || type == Type::MINUS)
        {
            if (type == Type::PLUS)
            {
                ++position;
                sum += term();
            }
            else
            {
                ++position;
                sum -= term();
            }
            type = tokens[position].type;
        }
    }
    return sum;
}

int Parser::term()
{
    auto&[type, value] = tokens[position++];
    int sum = 0;
    success &= (type == Type::LPAREN || type == Type::NUMBER);
    if (type == Type::LPAREN)
    {
        sum = expr();
        success &= tokens[position].type == Type::RPAREN;
        if (success)
        {
            ++position;
        }
    }
    else if (type == Type::NUMBER)
    {
        sum = value;
    }
    return sum;
}

bool Parser::tokenize(const std::string_view& string, int& offset, Token& token) const
{
    token.type = Type::SPACE;
    token.value = 0;
    const auto size = string.size();
    while (offset < size)
    {
        const auto ch = string[offset];
        switch (Type type = typeByChar[ch])
        {
            case Type::NUMBER:
                token.type = type;
                token.value *= 10;
                token.value += ch - '0';
                ++offset;
                break;
            case Type::ERROR:
                return false;
            default:
                if (token.type != Type::NUMBER)
                {
                    token.type = type;
                    ++offset;
                }
                if (token.type != Type::SPACE)
                {
                    return true;
                }
                break;
        }
    }
    return true;
}
