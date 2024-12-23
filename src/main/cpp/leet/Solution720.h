//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION720_H
#define SOLUTION720_H

class Solution720 {
public:
    static std::string longestWord(const std::vector<std::string>& words) {
        std::pmr::set<std::string> set;
        for (const auto& word : words)
        {
            set.insert(word);
        }

        auto lo = set.begin();
        auto hi = std::next(lo);
        while (lo != hi)
        {
            auto prefix = *lo;
            auto string = *hi;
            if (!string.starts_with(prefix) || prefix.size() + 1 != string.size())
            {
                break;
            }
            ++lo;
            ++hi;
        }
        return *lo;
    }
};

#endif //SOLUTION720_H
