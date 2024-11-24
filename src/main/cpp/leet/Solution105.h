//
// Created by Fredrik Dahlberg on 2024-11-23.
//

#ifndef SOLUTION105_H
#define SOLUTION105_H

#include <vector>

class Solution105
{
public:

    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        explicit  TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(const int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    static TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder)
    {
        std::unordered_map<int, int> inorderPosByValue;
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorderPosByValue[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1,
                     inorderPosByValue);
    }

private:
    static TreeNode* build(const std::vector<int>& preorder,
                           const int preStart,
                           const int preEnd,
                           const std::vector<int>& inorder,
                           const int inStart,
                           const int inEnd,
                           const std::unordered_map<int, int>& inPosByValue)
    {
        if (preStart > preEnd)
        {
            return nullptr;
        }
        const int value = preorder[preStart];
        const int rootInPos = inPosByValue.at(value);
        const int leftSize = rootInPos - inStart;
        auto root = new TreeNode(value);
        root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart,rootInPos - 1, inPosByValue);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, rootInPos + 1, inEnd, inPosByValue);
        return root;
    }
};

#endif //SOLUTION105_H
