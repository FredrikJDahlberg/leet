//
// Created by Fredrik Dahlberg on 2024-11-16.
//

#ifndef SOLUTION127_H
#define SOLUTION127_H

#include <unordered_set>

class Solution127
{
public:
    static int ladderLength(const std::string &beginWord,
                            const std::string &endWord,
                            std::vector<std::string> words)
    {
        std::unordered_set wordSet(words.begin(), words.end());
        if (!wordSet.contains(endWord))
        {
            return 0;
        }
        std::queue<std::string> queue{{beginWord}};
        for (int step = 1; !queue.empty(); ++step)
        {
            for (auto sz = queue.size(); sz > 0; --sz)
            {
                std::string word = queue.front();
                queue.pop();
                for (int i = 0; i < word.length(); ++i)
                {
                    const char cache = word[i];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        word[i] = c;
                        if (word == endWord)
                        {
                            return step + 1;
                        }
                        if (wordSet.contains(word))
                        {
                            queue.push(word);
                            wordSet.erase(word);
                        }
                    }
                    word[i] = cache;
                }
            }
        }
        return 0;
    }
};

#endif //SOLUTION127_H
