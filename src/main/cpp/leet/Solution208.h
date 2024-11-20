//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION208_H
#define SOLUTION208_H

namespace Solution208 {

/**
 * A very simplified trie.
 */
class Trie
{
private:
    struct Node
    {
        Node() : value{CHAR_MAX}, complete{false}, children{nullptr}
        {
        }

        Node(const char ch, const bool last) : value{ch}, complete{last}, children{}
        {
        }

        char value;
        bool complete;
        Node* children[32];
    };

    Node* root;

public:
    Trie(): root(new Node())
    {
    }

    void insert(const std::string& word)
    {
        if (word.empty())
        {
            return;
        }

        int offset = 0;
        auto found = root;
        bool hasValue = true;
        if (find(word, offset, hasValue, found))
        {
            found->complete = true;
        }
        else
        {
            insert(found, word, offset, hasValue);
        }
    }

    bool search(const std::string& word) const
    {
        int position = 0;
        bool hasValue = true;
        auto node = root;
        return find(word, position, hasValue, node) && node->complete;
    }

    bool startsWith(const std::string& prefix) const
    {
        int position = 0;
        bool hasValue = true;
        auto node = root;
        return find(prefix, position, hasValue, node);
    }

    void clear()
    {
        const auto child = root;
        forEach(child);
    }

private:
    static bool find(const std::string& word, int& offset, bool& hasValue, Node*& found)
    {
        bool doValue = true;
        const auto size = word.size();
        while (found != nullptr && offset < size)
        {
            const auto key = word[offset] - 'a';
            if (doValue)
            {
                hasValue = true;
                if (key != found->value)
                {
                    return false;
                }
                doValue = false;
                ++offset;
            }
            else
            {
                hasValue = false;
                if (found->children[key] != nullptr)
                {
                    found = found->children[key];
                }
                else
                {
                    return false;
                }
                doValue = true;
            }
        }
        return offset == size;
    }

    static void insert(Node* node, const std::string& word, int offset, const bool hasValue)
    {
        const auto size = word.size();
        if (hasValue)
        {
            node->value = word[offset] - 'a';
            ++offset;
        }
        while (offset < size)
        {
            const auto key = word[offset] - 'a';
            const auto child = new Node();
            child->value = key;
            node->children[key] = child;
            node->complete = false;
            node = child;
            ++offset;
        }
        node->complete = true;
    }

    static void forEach(Node* node)
    {
        for (const auto child : node->children)
        {
            if (child != nullptr)
            {
                forEach(child);
            }
        }
        delete node;
    }
};
}

#endif //SOLUTION208_H
