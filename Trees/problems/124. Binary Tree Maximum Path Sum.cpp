/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/



class Solution {
public:

	int helper(TreeNode* root, int &maxSum) {
		if (root == nullptr)return 0;

		int left = helper(root->left, maxSum);
		int right = helper(root->right, maxSum);

		int maxLeftRight = max(left, right);
		int maxOneRoot = max(root->val, root->val + maxLeftRight);
		int maxAll = max(maxOneRoot, left + right + root->val);

		maxSum = max(maxSum, maxAll);

		return maxOneRoot;
	}

	int maxPathSum(TreeNode* root) {
		int maxSum = INT_MIN;
		int a = helper(root, maxSum);
		return maxSum;
	}
};