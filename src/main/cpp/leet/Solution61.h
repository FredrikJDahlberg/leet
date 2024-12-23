//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION61_H
#define SOLUTION61_H

namespace solution61
{

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};

class Solution61 {
public:
    static ListNode* rotateRight(ListNode* head, const int k)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* rotated = head;
        for (int i = 0; i < k; ++i)
        {
            ListNode* newLast = nullptr;
            ListNode* last = rotated;
            while (last != nullptr && last->next != nullptr)
            {
                newLast = last;
                last = last->next;
            }
            if (newLast != nullptr)
            {
                newLast->next = nullptr;
            }
            if (last != nullptr)
            {
                last->next = rotated;
            }
            rotated = last;
        }
        return rotated;
    }
};

}

#endif //SOLUTION61_H
