#include <iostream>
#include <map>
#include <thread>

//
// Created by Fredrik Dahlberg on 2024-09-28.
//
void changeWords(std::string& word)
{
    int first = 0;
    int last = 0;
    bool move = false;
    while (first < word.size())
    {
        if (move)
        {
            if (word[first] == ' ')
            {
                ++first;
            }
            else
            {
                last = first;
                move = false;
            }
        }
        else
        {
            if (last < word.size() && word[last] != ' ')
            {
                ++last;
            }
            else
            {
                word[first] = ::toupper(word[first]);
                word[last - 1] = ::toupper(word[last - 1]);
                first = last;
                move = true;
            }
        }
    }
}


int main(int argc, const char *argv[])
{

    std::array aa = { 1,2,3,4,5 };
    for (const auto a : aa)
    {
        std::cout << "a = " << a << std::endl;
    }
    std::ranges::for_each(aa, [](auto v) {
        std::cout << "b = " << v << std::endl;
    });
    std::ranges::for_each(aa, [](auto v) {
        std::cout << "c = " << v << std::endl;
    });
}
