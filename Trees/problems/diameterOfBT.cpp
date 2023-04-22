/*
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 
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

// O(n*h) solution
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root){
        if (root == nullptr)return 0 ;
        return (1+ max(height(root->left) , height(root->right)));
    }

   int diameter(Node* root) {
        // Your code here
        if(root == nullptr)return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        
        int d = lh+rh+1;
        return max(d,max(diameter(root->left), diameter(root->right)));
    }
};


// O(n) solution
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int,int> heightDiameter(Node* root){
        pair<int,int>p{0,0};
        if(root == nullptr)return p;
        
        pair<int,int>l{0,0};
        pair<int,int>r{0,0};
        
        l = heightDiameter(root->left);
        r = heightDiameter(root->right);
        
        p.first = 1 + max(l.first, r.first);
        p.second = max((l.first + r.first + 1) , max(l.second , r.second));
        
        return p;
    }
    
    int diameter(Node* root) {
        // Your code here
        if(root == nullptr)return 0;
        return heightDiameter(root).second;
    }
};