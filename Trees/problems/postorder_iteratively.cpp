/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.
*/

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;


// Using 2 stacks (here I have used a vector and reversed it instead of 2nd stack)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root==nullptr)return postorder;
        stack<TreeNode*> s;
        s.push(root);
        while(s.size()>0){
            TreeNode* node = s.top();
            s.pop();
            postorder.push_back(node->val);
            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }
};


// Using only 1 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root==nullptr)return postorder;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr!=nullptr || s.size()>0){
            if(curr){
                s.push(curr);
                curr = curr->left;
            }else{
                TreeNode* temp = s.top()->right;
                if(temp == nullptr){
                    temp = s.top();
                    s.pop();
                    postorder.push_back(temp->val);
                    
                    while(s.size()>0 && temp==s.top()->right){
                        temp = s.top();
                        s.pop();
                        postorder.push_back(temp->val);
                    }
                }else{
                    curr = temp;
                }
                
            }
        }
        return postorder;
    }
};

