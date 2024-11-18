//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION26_H
#define SOLUTION26_H

#include <vector>


class Solution26
{
public:

    static size_t removeDuplicates(std::vector<int> &nums)
    {
        auto value = nums.front();
        for (auto it = nums.begin() + 1; it != nums.end(); ++it)
        {
            if (value == *it)
            {
                nums.erase(it);
            }
            else
            {
                value = *it;
            }
        }
        return nums.size();
    }

    static int removeDuplicates2(std::vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        auto value = nums.front();
        auto in = nums.begin() + 1;
        auto out = nums.begin();
        int count = 1;
        while (in != nums.end())
        {
            if (value != *in)
            {
                value = *in;
                *++out = *in;
                ++count;
            }
            ++in;
        }
        return count;
    }

};




#endif //SOLUTION26_H
