//
// Created by Fredrik Dahlberg on 2024-11-19.
//

#ifndef SOLUTION79_H
#define SOLUTION79_H

#include <vector>
#include <string>

class Solution79 {
private:
    static bool findWord(const size_t x,
                         const size_t y,
                         const size_t xm,
                         const size_t ym,
                         const std::vector<std::vector<char>>& board,
                         const int offset,
                         const std::string& word)
    {
        if (offset == word.length())
        {
            return true;
        }
        if (x >= xm || y >= ym)
        {
            return false;
        }
        if (board[y][x] != word[offset])
        {
            return false;
        }
        return findWord(x + 1, y, xm, ym, board, offset + 1, word) ||
               findWord(x - 1, y, xm, ym, board, offset + 1, word) ||
               findWord(x, y + 1, xm, ym, board, offset + 1, word) ||
               findWord(x, y - 1, xm, ym, board, offset + 1, word);
    }

public:
    static bool exist(const std::vector<std::vector<char>>& board, const std::string& word) {
        return findWord(0, 0, board[0].size(), board.size(), board, 0, word);
    }
};

#endif //SOLUTION79_H
