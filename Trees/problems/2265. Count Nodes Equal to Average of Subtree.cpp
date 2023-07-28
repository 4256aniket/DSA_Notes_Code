/*
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:
The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
*/

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;


// My solution
class Solution {
public:
    pair<int,int> avg(TreeNode* root){
        pair<int,int> p{0,0};
        if(root == nullptr)return p;
        
        pair<int,int>l{0,0}; pair<int,int> r{0,0};
        if(root->left)l = avg(root->left);
        if(root->right)r= avg(root->right);
        
        p.first = 1+ l.first + r.first;
        p.second = root->val + l.second + r.second;
        
        return p;
    }
    
    int helper(TreeNode* root){
        pair<int,int> p = avg(root);
        int average = p.second / p.first;
        return average;
    }
    
    int averageOfSubtree(TreeNode* root) {
        int average = helper(root);
        int ans = 0;
        if(root->val == average) ans = 1;
        if(root->left) ans += averageOfSubtree(root->left);
        if(root->right) ans += averageOfSubtree(root->right);
        
        return ans;
    }
};


// Better Solution
int dfs(struct TreeNode* root, int* no_nodes, int* subtree_sum)
{
    // amount of nodes in left and right branches
    int left = 0;
    int right = 0;
    
    int left_sum = 0;
    int right_sum = 0;

    if(root->left)
        left = dfs(root->left,no_nodes,&left_sum);
    
    if(root->right)
        right = dfs(root->right,no_nodes,&right_sum);
    
    *subtree_sum = left_sum + right_sum + root->val;
    
    // check if avarage is equal to current node value
    if((*subtree_sum / (left + right + 1)) == root->val)
        (*no_nodes)++;
    
    return left + right + 1;
}

int averageOfSubtree(struct TreeNode* root){

    int no_nodes = 0;
    int tree_sum = 0;
    
    dfs(root,&no_nodes,&tree_sum);
    
    return no_nodes;
}