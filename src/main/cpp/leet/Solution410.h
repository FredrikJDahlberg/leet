//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION410_H
#define SOLUTION410_H

class Solution410
{
private:
    std::vector<int> lengths;

public:
    int splitArray(const size_t size, const size_t k, const size_t offset, const std::vector<int> &nums)
    {
        if (k == 1)
        {
            auto maxSum = std::numeric_limits<int>::min();
            auto remaining = nums.size() - offset;
            if (remaining >= 1)
            {
                lengths.emplace_back(remaining);
                auto it = nums.begin();
                for (const auto length: lengths)
                {
                    maxSum = std::max(maxSum, std::accumulate(it, it + length, 0));
                    it += length;
                }
                lengths.pop_back();
            }
            return maxSum; // per partition
        }

        auto minSum = std::numeric_limits<int>::max();
        for (int j = 1; j < size; ++j)
        {
            lengths.emplace_back(j);
            minSum = std::min(minSum, splitArray(size - 1, k - 1, offset + j, nums));
            lengths.pop_back();
        }
        return minSum; // over all
    }

    int splitArray(const std::vector<int> &nums, const int k)
    {
        return splitArray(nums.size(), k, 0, nums);
    }
};

#endif //SOLUTION410_H
