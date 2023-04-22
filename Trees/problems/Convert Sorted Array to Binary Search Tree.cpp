/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.



Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
*/

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution
{
public:
    TreeNode *helper(vector<int> &nums, int s, int e)
    {
        if (s > e || e >= nums.size() || s < 0)
        {
            return nullptr;
        }

        int mid = s + (e - s) / 2;

        TreeNode *root = new TreeNode(nums[mid], helper(nums, s, mid - 1), helper(nums, mid + 1, e));

        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int e = nums.size() - 1;
        TreeNode *root = helper(nums, 0, e);
        return root;
    }
};