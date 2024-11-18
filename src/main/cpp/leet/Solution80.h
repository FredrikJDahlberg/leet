//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION80_H
#define SOLUTION80_H

class Solution80
{
public:

    static int removeDuplicates(int nums[], int count)
    {
        enum class State { NEW, SKIP, KEEP };

        auto state = State::NEW;
        int value = 0;
        int position = 0;
        int length = 0;
        int remaining = 0;
        while (position < count)
        {
            switch (state)
            {
                case State::NEW:
                    value = nums[position];
                    nums[remaining++] = nums[position++];
                    state = State::KEEP;
                    break;
                case State::KEEP:
                    if (++length < 2 && nums[position] == value)
                    {
                        nums[remaining++] = nums[position++];
                    } else
                    {
                        state = State::SKIP;
                        length = 0;
                    }
                    break;
                case State::SKIP:
                    if (value == nums[position])
                    {
                        ++position;
                    } else
                    {
                        state = State::NEW;
                    }
                    break;
            }
        }
        return remaining;
    }

    static int removeDuplicates2(std::vector<int> &nums)
    {
        int length = 1;
        int count = 1;
        auto value = nums.front();
        auto out = nums.begin();
        for (auto in = nums.begin() + 1; in != nums.end(); ++in)
        {
            const auto equal = value == *in;
            if (equal && ++length <= 2 || !equal)
            {
                *++out = *in;
                ++count;
            }
            if (!equal)
            {
                length = 1;
                value = *in;
            }
            ++in;
        }
        return count;
    }
};

#endif //SOLUTION80_H
