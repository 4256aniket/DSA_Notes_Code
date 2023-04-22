/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
*/

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr) return nullptr;
        TreeNode* ans = nullptr;
        if(root->val == val){
            return root;
        }
        if(root->right!=nullptr && root->val < val){
            ans = searchBST(root->right,val);
        }else{
            if(root->left!=nullptr)ans = searchBST(root->left,val);
        }
        return ans;
    }
};