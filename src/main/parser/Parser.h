//
// Created by Fredrik Dahlberg on 2024-10-03.
//

#ifndef PARSER_H
#define PARSER_H
#include <array>
#include <string>

class Parser {
private:

    enum class Type { EMPTY, NUMBER, PLUS, MINUS, LPAREN, RPAREN, SPACE, ERROR };
    struct Token {
        Type type;
        int value;

        Token() : type(Type::EMPTY), value(0) {
        }
    };
    Type typeByChar[256];

    std::array<Token, 32> tokens;
    bool success;
    int position;
    int count;


    static void print(Token& token)
    {
        std::printf("{ type = %d, value = %d }\n", static_cast<int>(token.type), token.value);
    }

    int term();
    int expr();

    void clear()
    {
        success = true;
        position = 0;
        count = 0;
    }

    bool tokenize(const std::string_view& string, int& offset, Token& token) const;

public:
    Parser();

    int calculate(const std::string_view& input);

    bool valid() const;
};

#endif //PARSER_H
