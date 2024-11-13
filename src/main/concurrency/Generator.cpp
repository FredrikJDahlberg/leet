//
// Created by Fredrik Dahlberg on 2024-11-10.
//

#include "Generator.h"

Generator<int> counter(int start, int end)
{
    while (start < end)
    {
        co_yield start;
        ++start;
    }
};


int main()
{

    auto generator = counter(1, 7);
    for (auto i = 1 : generator)
    {
        std::cout << "i = " << i << std::endl;
    }
    return 0;
*
}
