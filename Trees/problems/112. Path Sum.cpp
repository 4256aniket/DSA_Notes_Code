/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
*/

class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return false;
		}
		if (!root->left && !root->right) {
			if (targetSum == root->val)return true;
			else return false;
		}

		targetSum -= root->val;

		return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
	}
};