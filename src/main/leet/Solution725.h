//
// Created by Fredrik Dahlberg on 2024-11-13.
//

#ifndef SOLUTION725_H
#define SOLUTION725_H

namespace Solution725
{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

   class Solution {
   public:
       static std::vector<ListNode*> splitListToParts(ListNode* head, int k)
       {
           std::vector<ListNode*> result;
           int remaining = 0;
           for (ListNode* node = head; node != nullptr; node = node->next)
           {
               ++remaining;
           }

           int size = (remaining + k - 1) / k;
           int groups = k;
           int count = 0;
           ListNode* first = head;
           for (ListNode* node = head; --remaining >= 0 && node != nullptr; )
           {
               if (++count >= size)
               {
                   --groups;
                   size = remaining / groups;
                   count = 0;

                   result.emplace_back(first);
                   ListNode* last = node;
                   node = node->next;
                   first = node;
                   last->next = nullptr;
               }
               else
               {
                   node = node->next;
               }
           }
           for (auto i = 0; i < groups; ++i)
           {
               result.push_back(nullptr);
           }
           return result;
       }
   };
}

#endif //SOLUTION725_H
