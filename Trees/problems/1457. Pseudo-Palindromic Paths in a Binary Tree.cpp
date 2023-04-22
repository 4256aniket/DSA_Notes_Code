/*
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
*/

class Solution {

public:
	int pseudoPalindromicPaths (TreeNode* root) {
		int n = 0;
		unordered_map<int, int> m;
		helper(root, m, n);
		return n;
	}

private:

	void helper(TreeNode* root, unordered_map<int, int>& m, int& n) {
		if (root == nullptr) return;

		if (!root->left && !root->right) {
			m[root->val]++;
			int oddCount = 0;
			for (auto i : m) {
				if (i.second % 2 == 1) oddCount++;
			}

			if (oddCount <= 1) n++;
			m[root->val]--;
			return;
		}

		m[root->val]++;
		helper(root->left, m, n);
		helper(root->right, m, n);
		m[root->val]--;
	}

};