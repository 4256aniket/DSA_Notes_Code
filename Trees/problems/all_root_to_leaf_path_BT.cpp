/*
257. Binary Tree Paths

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
*/

#include<bits/stdc++.h>
using namespace std;


// Faith :
// 	children return root to leaf path 
// 	just add root->val in each path if subtree returns a path
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root->left && !root->right){
            return {to_string(root->val)};
        }
        vector<string> left, right, ans;
        if(root->left) left = binaryTreePaths(root->left);
        if(root->right) right = binaryTreePaths(root->right);

        if(left.size() > 0){
            string s = to_string(root->val) + "->";
            for(auto path : left){
                ans.push_back(s + path);
            }
        }

        if(right.size() > 0){
            string s = to_string(root->val) + "->";
            for(auto path : right){
                ans.push_back(s + path);
            }
        }

        return ans;
    }
};


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	
}