//
// Created by Fredrik Dahlberg on 2024-11-25.
//

#ifndef SOLUTION51_H
#define SOLUTION51_H

#include <vector>
#include <string>

class Solution51
{
public:
    using Presence = std::vector<bool>;
    using Board = std::vector<std::string>;

    static std::vector<Board> solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> result;
        solve(n, 0, Presence(n), Presence(2 * n - 1), Presence(2 * n - 1),
              std::vector(n, std::string(n, '.')), result);
        return result;
    }

private:
    static void solve(const int n,
                      const int i,
                      Presence&& cols,
                      Presence&& diags1,
                      Presence&& diags2,
                      Board&& board,
                      std::vector<Board>& result)
    {
        if (i == n)
        {
            result.push_back(board);
            return;
        }
        for (int j = 0; j < n; ++j)
        {
            if (!cols[j] && !diags1[i + j] && !diags2[j - i + n - 1])
            {
                board[i][j] = 'Q';
                cols[j] = true;
                diags1[i + j] = true;
                diags2[j - i + n - 1] = true;
                solve(n, i + 1, std::move(cols), std::move(diags1), std::move(diags2),
                      std::move(board), result);
                cols[j] = false;
                diags1[i + j] = false;
                diags2[j - i + n - 1] = false;
                board[i][j] = '.';
            }
        }
    }
};

#endif //SOLUTION51_H
