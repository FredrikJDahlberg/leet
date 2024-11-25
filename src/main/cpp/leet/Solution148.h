//
// Created by Fredrik Dahlberg on 2024-11-25.
//

#ifndef SOLUTION148_H
#define SOLUTION148_H

class Solution148
{
public:
    struct ListNode
    {
        int val;
        ListNode* next;

        ListNode() : val(0), next(nullptr)
        {
        }

        ListNode(int x) : val(x), next(nullptr)
        {
        }

        ListNode(int x, ListNode* next) : val(x), next(next)
        {
        }
    };

    static ListNode* selectionSort(ListNode* root)
    {
        for (auto i = root; i != nullptr; i = i->next)
        {
            auto min = i;
            for (auto j = i->next; j != nullptr; j = j->next)
            {
                if (j->val < min->val)
                {
                    min = j;
                }
            }
            std::swap(i->val, min->val);
        }
        return root;
    }
};


#endif //SOLUTION148_H
