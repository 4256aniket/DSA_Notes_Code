/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/


class Solution {
public:
	int res = 0;
	void inorder(TreeNode* root, int& k) {
		if (!root || res != 0) return;

		inorder(root->left, k);

		k--;
		if (k == 0) {
			res = root->val;
			return;
		}

		inorder(root->right, k);
	}

	int kthSmallest(TreeNode* root, int k) {
		inorder(root, k);
		return res;
	}
};