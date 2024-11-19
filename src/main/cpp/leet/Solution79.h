//
// Created by Fredrik Dahlberg on 2024-11-19.
//

#ifndef SOLUTION79_H
#define SOLUTION79_H

#include <vector>
#include <string>

class Solution79 {
private:
    static bool findWord(const int x,
                         const int y,
                         const std::vector<std::vector<char>>& board,
                         const int offset,
                         const std::string& word)
    {
        if (offset == word.length())
        {
            return true;
        }
        if (x < 0 || y < 0 || x >= board[0].size() || y >= board.size())
        {
            return false;
        }
        if (board[y][x] != word[offset])
        {
            return false;
        }
        return findWord(x + 1, y, board, offset + 1, word) ||
               findWord(x - 1, y, board, offset + 1, word) ||
               findWord(x, y + 1, board, offset + 1, word) ||
               findWord(x, y - 1, board, offset + 1, word);
    }

public:
    static bool exist(const std::vector<std::vector<char>>& board, const std::string& word) {
        return findWord(0, 0, board, 0, word);
    }
};

#endif //SOLUTION79_H
