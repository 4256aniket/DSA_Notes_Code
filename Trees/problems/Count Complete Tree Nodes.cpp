/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
*/

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Brute Force
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int count = 1;

        if (root->left)
            count += countNodes(root->left);
        if (root->right)
            count += countNodes(root->right);

        return count;
    }
};

// Better Solution
class Solution {
public:
    int lheight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->left;
        }
        return h;
    }
    int rheight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
     if(!root){
         return 0;
     }
     int lh=lheight(root);
     int rh=rheight(root);
        if(lh==rh){
            return (1<<lh)-1;
        }
      return 1+countNodes(root->left)+countNodes(root->right);  
    }
};