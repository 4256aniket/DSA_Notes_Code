/*
Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
*/


class Solution {
public:
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
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
