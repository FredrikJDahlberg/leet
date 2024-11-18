//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION2546_H
#define SOLUTION2546_H

class Solution2546
{
public:
    // 1010 -> 0110: {2,0} {2,1}
    // {0,1} {0,2} {0,3} {1,2} {1,3} {2,3}
    // {0,1} = 0110
    // {2,0} = 0010 {2,1} = 0110
    static bool makeStringsEqual(const std::string &s, const std::string& target)
    {
        const auto len = s.size();
        auto x = s;
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                const auto n1 = static_cast<const char>(x[i] | x[j]);
                const auto n2 = static_cast<const char>(x[i] ^ x[j]);
                x[i] = n1;
                x[j] = n2;
                if (x == target)
                {
                    return true;
                }
            }
        }
        auto y = s;
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                const auto n1 = static_cast<const char>(y[j] | y[i]);
                const auto n2 = static_cast<const char>(y[j] ^ y[i]);
                std::printf("i = %d, j = %d\n", i, j);
                y[j] = n1;
                y[i] = n2;
                if (y == target)
                {
                    std::cout << y << std::endl;
                    return true;
                }
            }
        }
        return false;
    }
};

#endif //SOLUTION2546_H
