//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION2547_H
#define SOLUTION2547_H

class Solution2547
{
private:
    std::vector<int> lengths;
    std::array<std::uint8_t, 1000> used; // 0 = zero, 1 = once, 2 = more

    int importance(int offset, int length, int k, std::vector<int> &nums)
    {
        used.fill(0);
        for (int i = offset; i < offset + length; ++i)
        {
            auto num = nums[i];
            if (used[num] < 2)
            {
                ++used[num];
            }
        }

        int cost = k;
        for (int i = offset; i < offset + length; ++i)
        {
            auto num = nums[i];
            if (used[num] == 2)
            {
                ++cost;
            }
        }
        return cost;
    }

    int minCost(int offset, int length, int k1, int k, std::vector<int> &nums)
    {
        if (k1 == 1)
        {
            auto remaining = nums.size() - offset;
            lengths.emplace_back(remaining);
            std::cout << lengths << std::endl;

            int pos = 0;
            int cost = 0;
            for (auto len: lengths)
            {
                cost += importance(pos, len, k, nums);
                pos += len;
            }
            lengths.pop_back();
            return cost;
        }
        auto min = std::numeric_limits<int>::max();
        for (int i = 1; i < length; ++i)
        {
            lengths.push_back(i);
            min = std::min(min, minCost(offset + i, length - 1, k - 1, k, nums));
            lengths.pop_back();
        }
        return min;
    }

public:
    Solution2547()
    {
    }

    int minCost(std::vector<int> &nums, int k)
    {
        return minCost(0, nums.size(), k, k, nums);
    }
};

#endif //SOLUTION2547_H
