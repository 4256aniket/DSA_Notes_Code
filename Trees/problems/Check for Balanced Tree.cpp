/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int height(Node* root){
        if(root==nullptr)return 0;
        return (1 + max(height(root->left), height(root->right)));
    }
    
    pair<bool,int> helper(Node *root){
        if(root == nullptr){
            return (make_pair(true,0));
        }
        
        pair<bool,int> l = helper(root->left);
        pair<bool,int> r = helper(root->right);
        
        int height = (1 + max(l.second,r.second));
        bool ans = (abs(l.second-r.second)<=1)&&(l.first)&&(r.first);
        
        pair<bool,int> p{ans,height};
        return p;
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root == nullptr)return true;
        
        pair<bool,int>p = helper(root);
        return p.first;
    }
};