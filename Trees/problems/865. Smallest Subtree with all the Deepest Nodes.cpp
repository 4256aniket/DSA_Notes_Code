/*
Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.
*/


class Solution {
public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		if (root == nullptr) return root;
		int d = depth(root);

		vector<TreeNode*> v;
		deepestNodes(root, d, v);
		int i = v.size() - 1;
		if (v.size() == 1) return v[0];
		else return LCA(root, v[0]->val, v[i]->val);
	}

private:

	TreeNode* LCA(TreeNode*root, int p, int q) {
		if (root == nullptr) return root;

		if (root->val == p || root->val == q) return root;

		TreeNode* left = LCA(root->left, p, q);
		TreeNode* right = LCA(root->right, p, q);

		if (!left) return right;
		if (!right) return left;

		return root;
	}

	void deepestNodes(TreeNode* root, int d, vector<TreeNode*> &v) {
		if (root == nullptr) return;
		deepestNodes(root->left, d - 1, v);
		deepestNodes(root->right, d - 1, v);

		if (d == 1) v.push_back(root);
		return;
	}

	int depth(TreeNode* root) {
		if (root == nullptr) return 0;
		return 1 + max(depth(root->left), depth(root->right));
	}
};