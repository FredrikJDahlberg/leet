//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION22_H
#define SOLUTION22_H

class Solution22
{
private:
    // n = 1: ()
    // n = 2: (()), ()()
    // n = 3: ()()(), (()()), (())(), ()(())

public:
    static std::vector<std::string> generateParenthesis(int n) {
        std::string str;

        return std::vector<std::string>{};
    }

    static void generate(int n, std::vector<std::string> &result)
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

    static void fibonacci(int n)
    {
        std::vector sequence = { 0, 1 };
        for (auto i = sequence.size(); i < n; ++i)
        {
            auto result = sequence[i - 1] + sequence[i - 2];
            sequence.push_back(result);
        }
        std::cout << sequence << std::endl;
    }

};

#endif //SOLUTION22_H
