//
// Created by Fredrik Dahlberg on 2024-11-09.
//

#ifndef SOLUTION62_H
#define SOLUTION62_H

class Solution62
{
public:
    static int uniquePaths(const int m, const int n)
    {
        return (m <= 1 || n <= 1) ? 1 : uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

#endif //SOLUTION62_H
