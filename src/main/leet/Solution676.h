//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION676_H
#define SOLUTION676_H

namespace Solution676 {

class MagicDictionary
{
private:
    std::set<std::string> words;

public:
    MagicDictionary()
    {
    }

    void buildDict(std::vector<std::string> dictionary)
    {
        for (auto word: dictionary)
        {
            words.insert(word);
        }
    }

    bool search(std::string searchWord) const
    {
        for (auto &word: words)
        {
            if (word.size() == searchWord.size())
            {
                int diffs = 0;
                auto sw = searchWord.begin();
                for (const auto w: word)
                {
                    if (w != *sw)
                    {
                        ++diffs;
                    }
                    ++sw;
                }
                if (diffs == 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
}

#endif //SOLUTION676_H
