//
// Created by Fredrik Dahlberg on 2024-11-22.
//

#ifndef SOLUTION2512_H
#define SOLUTION2512_H

#include <vector>
#include <string>

class Solution2512
{
public:
    static auto topStudents(const std::vector<std::string>& positives,
                            const std::vector<std::string>& negatives,
                            const std::vector<std::string>& reports,
                            const std::vector<int>& studentIds,
                            const int k)
    {
        auto posSet = std::unordered_set(positives.begin(), positives.end());
        auto negSet = std::unordered_set(negatives.begin(), negatives.end());
        auto scoreAndIds = std::vector<std::pair<int, int>>();
        for (int i = 0; i < reports.size(); ++i)
        {
            int score = 0;
            std::istringstream iss(reports[i]);
            for (std::string word; iss >> word;)
            {
                if (posSet.contains(word))
                {
                    score += 3;
                }
                if (negSet.contains(word))
                {
                    score -= 1;
                }
            }
            scoreAndIds.emplace_back(-score, studentIds[i]);   // non-decreasing order
        }
        std::ranges::partial_sort(scoreAndIds, scoreAndIds.begin() + k);
        std::vector<int> result;
        std::transform(scoreAndIds.begin(), scoreAndIds.begin() + k, std::back_inserter(result),
                       [](const std::pair<int, int>& scoreAndId) { return scoreAndId.second; });
        return result;
    }
};

#endif //SOLUTION2512_H
