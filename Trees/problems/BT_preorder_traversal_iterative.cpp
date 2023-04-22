/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        stack<TreeNode *> s;
        if (root == nullptr)
            return v;

        s.push(root);
        while (s.size() > 0)
        {
            TreeNode *node = s.top();
            s.pop();
            v.push_back(node->val);

            if (node->right)
                s.push(node->right);
            if (node->left)
                s.push(node->left);
        }
        return v;
    }
};