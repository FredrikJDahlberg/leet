//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION22_H
#define SOLUTION22_H

class Solution22
{
private:
    static void generate(const int n, std::vector<std::string> &result)
    {
        for (int i = 0; i < n -1; ++i)
        {
            const auto size = result.size();
            for (auto j = 0; j < size; ++j)
            {
                auto str = result[j];
                result.push_back("(" + str + ")");
                result.push_back(str + "()");
                if (str.find("((") != std::string::npos)
                {  // skip duplicates
                    result.push_back("()" + str);
                }
            }
            result.erase(result.begin(), result.begin() + size);
        }
    }

public:
    static auto generateParenthesis(const int n) {
        std::vector<std::string> result{"()"};
        generate(n, result);
        return result;
    }
};

#endif //SOLUTION22_H
