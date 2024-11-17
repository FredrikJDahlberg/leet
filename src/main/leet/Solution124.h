//
// Created by Fredrik Dahlberg on 2024-11-17.
//

#ifndef SOLUTION124_H
#define SOLUTION124_H

/**
 * Definition for a binary tree node.
 */
class Solution124 {
public:
     struct TreeNode
     {
         int val;
         TreeNode* left;
         TreeNode* right;

         TreeNode() : val(0), left(nullptr), right(nullptr)
         {
         }
         explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr)
         {
         }
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
         {
         }
     };

    static int maxPathSum(const TreeNode* node)
    {
        int sum = INT32_MIN;
        return maxPathSum(node, sum);
    }

    static int maxPathSum(const TreeNode* node, int& sum)
    {
        if (node != nullptr)
        {
            sum = std::max(pathSum(node), sum);
            sum = std::max(pathSum(node->left), sum);
            sum = std::max(pathSum(node->right), sum);
        }
        return sum;
    }

    static int pathSum(const TreeNode* node)
    {
        if (node != nullptr)
        {
            return node->val + maxPathSum(node->left) + maxPathSum(node->right);
        }
        return 0;
    }
};

#endif // SOLUTION124_H
