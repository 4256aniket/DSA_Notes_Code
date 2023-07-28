/*
Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.
A grandparent of a node is the parent of its parent if it exists.
*/

#include<bits/stdc++.h>
using namespace std;
#include "TreeNode.h"

class Solution {
public:

    int sum = 0;

    int sumEvenGrandparent(TreeNode* root) {
        if (root->val % 2 == 0) {
            if (root->left && root->left->left)sum += root->left->left->val;
            if (root->left && root->left->right)sum += root->left->right->val;
            if (root->right && root->right->left)sum += root->right->left->val;
            if (root->right && root->right->right)sum +=root->right->right->val;
        }

        if (root->left)int lans = sumEvenGrandparent(root->left);
        if (root->right)int rans = sumEvenGrandparent(root->right);

        return sum;
    }
};