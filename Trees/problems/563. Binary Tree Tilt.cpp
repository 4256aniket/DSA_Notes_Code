/*
Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.
*/


class Solution {
public:

	int helper(TreeNode* root, int & tilt) {
		if (root == NULL) return 0;

		int lsum = helper(root->left, tilt);
		int rsum = helper(root->right, tilt);

		tilt += (abs(lsum - rsum));

		return lsum + rsum + root->val;
	}

	int findTilt(TreeNode* root) {
		int tilt = 0;
		int a = helper(root, tilt);
		return tilt;
	}
};