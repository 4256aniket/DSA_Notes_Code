/*
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.
*/


class Solution {
public:
	TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
		unordered_map<int, int> m;
		for (int i = 0; i < postorder.size(); i++) {
			m[postorder[i]] = i;
		}
		return helper(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1, m);
	}

private:
	TreeNode* helper(vector<int> & preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd, unordered_map<int, int>& m) {
		if (preStart > preEnd || postStart > postEnd) return nullptr;
		TreeNode* root = new TreeNode(preorder[preStart]);
		if (preStart == preEnd) return root;
		int i = m[preorder[preStart + 1]];
		int l = i - postStart + 1;

		root->left = helper(preorder, postorder, preStart + 1, preStart + l, postStart, i, m);
		root->right = helper(preorder, postorder, preStart + l + 1, preEnd, i + 1, postEnd - 1, m);

		return root;
	}
};