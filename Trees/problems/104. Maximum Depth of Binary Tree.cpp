/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include <bits/stdc++.h>
#include "TreeNode.h"   
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return (max(maxDepth(root->left), maxDepth(root->right)) + 1);
    }
};