/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
      
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> s;
        TreeNode* node = root;
        
        while(true){
            if(node){
                s.push(node);
                node = node->left;
            }else{
                if(s.empty()) break;
                
                node = s.top();
                s.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};