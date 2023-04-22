/*
Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int>levelorder;
      deque<Node*> pendingNodes;
      pendingNodes.push_back(node);
      while(pendingNodes.size() > 0){
          Node* front = pendingNodes.front();
          pendingNodes.pop_front();
          levelorder.push_back(front->data);
          if(front->left)pendingNodes.push_back(front->left);
          if(front->right)pendingNodes.push_back(front->right);
          
      }
      return levelorder;
    }
};