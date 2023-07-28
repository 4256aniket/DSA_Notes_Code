/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
*/



class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		unordered_map<int, int> m;
		for (int i = 0; i < inorder.size(); i++) {
			m[inorder[i]] = i;
		}

		return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, m);
	}

private:
	TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& m) {
		if (postStart > postEnd || inStart > inEnd)return nullptr;

		TreeNode* root = new TreeNode(postorder[postEnd]);

		int inRoot = m[root->val];
		int numLeft = inRoot - inStart;

		root->left = helper(inorder, postorder, inStart, inRoot - 1, postStart, postStart + numLeft - 1, m);
		root->right = helper(inorder, postorder, inRoot + 1, inEnd, postStart + numLeft, postEnd - 1, m);

		return root;
	}
};

