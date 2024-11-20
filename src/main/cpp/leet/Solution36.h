//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION36_H
#define SOLUTION36_H

#include <bitset>
#include <vector>

class Solution36
{
public:
    static bool isValidSudoku(const std::vector<std::vector<char> > &board)
    {
        std::bitset<16> presence;

        for (auto &row: board)
        {
            presence.reset();
            if (!checkRow(row, 0, row.size(), presence))
            {
                return false;
            }
        }
        for (int i = 0; i < 9; ++i)
        {
            presence.reset();
            for (auto &row: board)
            {
                auto ch = row[i];
                if (!valid(ch, presence))
                {
                    return false;
                }
            }
        }
        for (int r = 0; r < board.size(); r += 3)
        {
            for (int c = 0; c < board[r].size(); c += 3)
            {
                presence.reset();
                for (int j = 0; j < 2; ++j)
                {
                    if (auto &row = board[r + j]; !checkRow(row, c, 3, presence))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

private:
    static bool checkRow(const std::vector<char> &row, const int offset, const size_t length, std::bitset<16> &presence)
    {
        for (int i = 0; i < length; ++i)
        {
            if (!valid(row[i + offset], presence))
            {
                return false;
            }
        }
        return true;
    }

    static bool valid(const char ch, std::bitset<16> &presence)
    {
        if (ch == '.')
        {
            return true;
        }
        const auto digit = ch - '0';
        if (presence.test(digit))
        {
            return false;
        }
        presence.set(digit);
        return true;
    }
};

#endif //SOLUTION36_H
