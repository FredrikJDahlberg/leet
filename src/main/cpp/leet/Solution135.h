//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION135_H
#define SOLUTION135_H

class Solution135
{
public:

    /* You are giving candies to these children subjected to the following requirements:
    - Each child must have at least one candy
    - Children with a higher rating get more candies than their neighbors
    - Return the minimum number of candies you need to have to distribute the candies to the children.
    */
    static int candy(const int *ratings, const int size)
    {
        int candy[size];
        std::ranges::fill(candy, candy + 3, 1);

        int count = size;
        for (auto i = 0; i < size - 1; ++i)
        {
            const auto ratings1 = ratings[i];
            const auto ratings2 = ratings[i + 1];
            if (ratings1 > ratings2)
            {
                ++candy[i];
                ++count;
            }
            if (ratings1 < ratings2)
            {
                ++candy[i + 1];
                ++count;
            }
        }
        return count;
    }
};

#endif //SOLUTION135_H
