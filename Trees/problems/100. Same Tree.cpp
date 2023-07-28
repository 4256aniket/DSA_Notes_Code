/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if( p!=nullptr && q!=nullptr && p->val==q->val ){
            bool ans1 = isSameTree(p->left,q->left);
            bool ans2 = isSameTree(p->right,q->right);
            return ans1&&ans2;
        }else{
            return false;
        }
    }
};