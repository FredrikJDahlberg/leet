//
// Created by Fredrik Dahlberg on 2024-11-19.
//

#ifndef SOLUTION212_H
#define SOLUTION212_H

#include <vector>
#include <string>

class Solution212 {
private:
    static constexpr char SKIP = '_';

    std::vector<std::vector<char>>* board;
    const std::vector<std::string>* words;

    void findWords(const size_t x,
                   const size_t y,
                   const int xm,
                   const int ym,
                   std::string word,
                   std::vector<std::string>& result)
    {
        if (x >= xm || y >= ym)
        {
            word.clear();
            return;
        }

        const auto ch = board->at(y).at(x);
        if (ch == SKIP)
        {
            return;
        }

        word.push_back(ch);
        if (std::ranges::find(*words, word) != words->end())
        {
            result.emplace_back(word);
        }
        board->at(y).at(x) = SKIP;
        findWords(x + 1, y, xm, ym, word, result);
        findWords(x - 1, y, xm, ym, word, result);
        findWords(x, y + 1, xm, ym, word, result);
        findWords(x, y - 1, xm, ym, word, result);
        board->at(y).at(x) = ch;
        word.pop_back();
    }

public:
    Solution212() = default;

    std::vector<std::string> findWords(std::vector<std::vector<char>>& board,
                                       const std::vector<std::string>& words) {
        this->board = &board;
        this->words = &words;
        std::vector<std::string> result;
        std::string word;
        for (int r = 0; r < board.size(); ++r)
        {
            for (int c = 0; c < board[0].size(); ++c)
            {
                findWords(c, r, board[0].size(), board.size(), word, result);
            }
        }
        return result;
    }
};

#endif //SOLUTION212_H
