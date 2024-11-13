//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION40_H
#define SOLUTION40_H

class Solution40
{
private:
    static void combinationSum(std::vector<int> &candidates,
                               const int remaining,
                               const int offset,
                               std::vector<int> &result,
                               std::vector<std::vector<int> > &results)
    {
        if (remaining == 0)
        {
            if (std::ranges::find(results, result) == results.end())
            {
                results.push_back(result);
            }
        } else
        {
            int i = offset;
            auto candidate = candidates[i];
            while (i < candidates.size() && remaining - candidate >= 0)
            {
                result.push_back(candidate);
                combinationSum(candidates, remaining - candidate, i + 1, result, results);
                result.pop_back();
                ++i;
                candidate = candidates[i];
            }
        }
    }

public:
    static std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target)
    {
        std::vector<std::vector<int> > results;
        std::vector<int> result;
        std::ranges::sort(candidates);
        combinationSum(candidates, target, 0, result, results);
        return results;
    }
};

#endif //SOLUTION40_H
