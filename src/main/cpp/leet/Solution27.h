//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION27_H
#define SOLUTION27_H

#include  <vector>

class Solution27
{
public:
    static size_t removeElement(std::vector<int> &nums, const int val)
    {
        auto it = nums.begin();
        while (it != nums.end())
        {
            if (*it == val)
            {
                nums.erase(it);
            } else
            {
                ++it;
            }
        }
        return nums.size();
    }
};

#endif //SOLUTION27_H
