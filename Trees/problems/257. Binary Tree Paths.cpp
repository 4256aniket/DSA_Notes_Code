/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.
*/

class Solution {
public:

	void helper(TreeNode* root, string s, vector<string> & ans) {
		if (root == nullptr)return;
		if (!root->left && !root->right) {
			if (!s.empty())s += ("->");
			s += (to_string(root->val));
			ans.push_back(s);
		}
		if (!s.empty())s += ("->");
		s += (to_string(root->val));
		if (root->left) helper(root->left, s, ans);
		if (root->right) helper(root->right, s, ans);
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ans;
		string s = "";
		helper(root, s, ans);
		return ans;
	}
};