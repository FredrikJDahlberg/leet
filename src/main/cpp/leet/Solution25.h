//
// Created by Fredrik Dahlberg on 2024-10-23.
//

#ifndef SOLUTION25_H
#define SOLUTION25_H
#include <iostream>

class Solution25
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {
        }
        explicit ListNode(int x) : val(x), next(nullptr) {
        }
        ListNode(int x, ListNode *next) : val(x), next(next) {
        }
    };

private:
    void free(const ListNode* list)
    {
        auto node = list;
        while (node != nullptr)
        {
            const auto next = node->next;
            delete node;
            node = next;
        }
    }

    void print(const ListNode* list)
    {
        for (auto node = list; node != nullptr; node = node->next)
        {
            std::cout << "{ " << node->val << " }, ";
        }
        std::cout << std::endl;
    }

    int count(const ListNode* list)
    {
        int count = 0;
        for (auto node = list; node != nullptr; node = node->next)
        {
            ++count;
        }
        return count;
    }


    ListNode* head;

public:
    Solution25(const std::initializer_list<int> list)
    {
        head = makeList(list);
        /*
        ListNode* prev = nullptr;
        for (auto& value : list)
        {
            auto* node = new ListNode(value);
            if (prev == nullptr)
            {
                head = node;
            }
            else
            {
                prev->next = node;
            }
            prev = node;
        }
        */
    }

    ~Solution25()
    {
        free(head);
    }

    static ListNode* makeList(const std::initializer_list<int> values)
    {
        ListNode* prev = nullptr;
        ListNode* list = nullptr;
        for (const auto& value : values)
        {
            auto* node = new ListNode(value);
            if (prev == nullptr)
            {
                list = node;
            }
            else
            {
                prev->next = node;
            }
            prev = node;
        }
        return list;
    }

    ListNode* reverse(/*ListNode* node,*/ const int k)
    {
        ListNode* node = head;
        head = nullptr;
        ListNode* lastInGroup = nullptr;
        ListNode* lastInPrevGroup = nullptr;
        for (auto remaining = count(node); remaining >= k; remaining -= k)
        {
            lastInGroup = node;

            int i = k;
            ListNode* prev = nullptr;
            while (node != nullptr && --i >= 0)
            {
                auto* next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }
            if (head == nullptr)
            {
                head = prev;
            }
            if (lastInPrevGroup != nullptr)
            {
                lastInPrevGroup->next = prev;
            }
            lastInPrevGroup = lastInGroup;
        }
        if (lastInGroup != nullptr)
        {
            lastInGroup->next = node;
        }
        return head;
    }
};

#endif //SOLUTION25_H
