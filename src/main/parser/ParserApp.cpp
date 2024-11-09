#include <iostream>

#include "Parser.h"
//
// Created by Fredrik Dahlberg on 2024-10-03.
//
void test(Parser& parser, const char* str)
{
    std::string_view expr(str);
    int result = parser.calculate(expr);
    std::printf("%s = %d, %s\n", expr.data(), result, parser.valid() ? "true" : "false");
}

int main(int argc, const char * argv[])
{
    Parser parser;
    test(parser, "(10 + (20 + 30 + 40) - 70)");
    test(parser, "10 20");
    test(parser, "10 + 200 + 3000)");
    test(parser, " + 20");
}
