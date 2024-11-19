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

    void findWords(const int x,
                   const int y,
                   std::string word,
                   std::vector<std::string>& result)
    {
        if (x < 0 || y < 0 || x == board->at(0).size() || y == board->size())
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
        findWords(x + 1, y, word, result);
        findWords(x - 1, y, word, result);
        findWords(x, y + 1, word, result);
        findWords(x, y - 1, word, result);
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
                findWords(c, r, word, result);
            }
        }
        return result;
    }
};

#endif //SOLUTION212_H
