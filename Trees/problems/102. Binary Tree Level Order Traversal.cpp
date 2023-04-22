/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
*/

#include <bits/stdc++.h>
using namespace std;
#include "TreeNode.h"

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root == nullptr)
            return ans;

        q.push(root);

        while (q.size() > 0)
        {
            int size = q.size(); 
            vector<int> lvl;
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                lvl.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};