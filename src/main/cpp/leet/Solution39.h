//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION39_H
#define SOLUTION39_H

class Solution39 {
private:
    static void combinationSum(const std::vector<int>& candidates,
                               const int remaining,
                               std::vector<std::vector<int>>& results,
                               std::vector<int>& result,
                               const int offset)
    {
        int i = offset;
        if (remaining == 0) {
            results.push_back(result);  // done
        }
        else
        {
            auto candidate = candidates[i];
            while (i < candidates.size() && remaining - candidate >= 0) {
                result.push_back(candidate); // add candidate
                combinationSum(candidates, remaining - candidate, results, result, i);
                candidate = candidates[++i];
                result.pop_back();  // backtrack
            }
        }
    }
public:
    static auto combinationSum(const std::vector<int>& candidates, const int target) -> std::vector<std::vector<int>>
    {
        std::vector<std::vector<int>> results;
        std::vector<int> result;
        combinationSum(candidates, target, results, result, 0);
        return results;
    }
};


#endif //SOLUTION39_H
