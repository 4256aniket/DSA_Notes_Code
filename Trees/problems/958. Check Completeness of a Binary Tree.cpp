/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/


class Solution {
public:
	bool isCompleteTree(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);

		while (q.size() > 0) {
			TreeNode* node = q.front();
			q.pop();
			if (node == nullptr) {
				while (q.size() > 0 && node == nullptr) {
					node = q.front();
					q.pop();
				}

				if (q.size() == 0)return true;
				else return false;
			}
			if (!node->left && node->right) return false;
			q.push(node->left);
			q.push(node->right);
		}
		return true;
	}
};