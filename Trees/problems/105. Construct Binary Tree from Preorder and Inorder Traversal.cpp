/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
*/


class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		unordered_map<int, int> m;
		for (int i = 0; i < inorder.size(); i++) {
			m[inorder[i]] = i;
		}

		return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, m);
	}

private:
	TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>&m) {

		if (preStart > preEnd || inStart > inEnd) return nullptr;

		TreeNode* root = new TreeNode(preorder[preStart]);
		int inRoot = m[root->val];
		int numLeft = inRoot - inStart;

		root->left = helper(preorder, inorder, preStart + 1, preStart + numLeft, inStart, inRoot - 1, m);
		root->right = helper(preorder, inorder, preStart + numLeft + 1, preEnd, inRoot + 1, inEnd, m);

		return root;

	}
};