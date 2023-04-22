/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
*/


class Solution {
public:

	void helper(TreeNode* root, vector<int> v, int sum, vector<vector<int>> & ans) {
		if (root == nullptr) return ;
		if (!root->left && !root->right) {
			if (sum == root->val) {
				v.push_back(root->val);
				ans.push_back(v);
				return;
			}
		}

		sum -= root->val;
		v.push_back(root->val);
		helper(root->left, v, sum, ans);
		helper(root->right, v, sum, ans);
	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<int> v;
		vector<vector<int>> ans;
		helper(root, v, targetSum, ans);
		return ans;
	}
};