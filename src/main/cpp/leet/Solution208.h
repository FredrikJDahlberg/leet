//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION208_H
#define SOLUTION208_H

namespace Solution208 {
class Trie
{
private:
    static constexpr int EMPTY = 0;

    struct Node
    {
        Node() : value{0}, complete{false}, children{nullptr}
        {
        }

        Node(const char ch, const bool last) : value{ch}, complete{last}, children{}
        {
        }

        char value;
        bool complete;
        Node *children[256];
    };

    Node *root;

    static Node *find(Node *node, const std::string &word, int &offset)
    {
        auto next = node;
        const auto size = word.size();
        while (next != nullptr && next->value == word[offset])
        {
            if (next->value == word[offset])
            {
                if (offset == size)
                {
                    return next->complete ? next : nullptr;
                }
                ++offset;

                const auto child = next->children[word[offset]];
                ++offset;
                if (child == nullptr)
                {
                    return next;
                }
                next = child;
            }
        }
        return next;
    }

    static bool insert(Node *node, const std::string &word, int offset)
    {
        while (offset < word.size())
        {
            if (node->value == word[offset])
            {
                ++offset;

                const auto child = node->children[word[offset]];
                const auto ch = word[offset];
                if (child == nullptr)
                {
                    node->children[ch] = new Node(ch, word.size() == offset);
                } else
                {
                    // Node* parent = new Node(EMPTY, false);
                    // no common suffix
                }
                node = node->children[ch];
            }
        }
        return true;
    }

public:
    Trie(): root(nullptr)
    {
    }

    void insert(const std::string &word)
    {
        if (root == nullptr)
        {
            int offset = 0;
            root = new Node(word[0], word.size() == 1);
            ++offset;
        }

        // Node *node = find(root, word, offset);
    }

    [[nodiscard]] bool search(const std::string& word) const
    {
        int offset = 0;
        const auto node = find(root, word, offset);
        return node != nullptr ? node->complete : false;
    }

    [[nodiscard]] bool startsWith(const std::string& prefix) const
    {
        int offset = 0;
        const auto node = find(root, prefix, offset);
        return node != nullptr;
    }
};
}


#endif //SOLUTION208_H
