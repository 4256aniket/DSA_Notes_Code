/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class triple
{
public:
    bool ans;
    long mx;
    long mn;
};

class Solution
{
public:
    long maxi(long a, long b)
    {
        return (a > b) ? a : b;
    }

    long mini(long a, long b)
    {
        return (a < b) ? a : b;
    }

    triple helper(TreeNode *root)
    {
        if (root == nullptr)
        {
            triple temp;
            temp.ans = true;
            temp.mx = -2147483650;
            temp.mn = 2147483650;
            return temp;
        }

        triple left = helper(root->left);
        triple right = helper(root->right);
        bool isOk = false;
        if (root->val < right.mn && root->val > left.mx)
            isOk = true;
        triple res;
        res.ans = (isOk && left.ans && right.ans);
        res.mx = maxi(right.mx, root->val);
        res.mn = mini(left.mn, root->val);
        return res;
    }

    bool isValidBST(TreeNode *root)
    {
        triple a = helper(root);
        return a.ans;
    }
};