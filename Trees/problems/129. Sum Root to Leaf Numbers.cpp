/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
*/

class Solution {
public:

	void helper(TreeNode* root, int s, int& sum) {
		if (root == nullptr)return;
		if (!root->left && !root->right) {
			s *= 10;
			s += root->val;
			sum += s;
			return;
		}
		s *= 10;
		s += (root->val);
		helper(root->left, s, sum);
		helper(root->right, s, sum);

	}

	int sumNumbers(TreeNode* root) {
		int sum = 0, s = 0;
		helper(root, s, sum);
		return sum;
	}
};