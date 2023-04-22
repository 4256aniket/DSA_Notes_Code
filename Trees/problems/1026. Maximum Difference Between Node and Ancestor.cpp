/*
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
*/



class Solution {
public:

	pair<int, int> helper(TreeNode* root, int& ans) {

		pair<int, int> l{root->val, root->val};
		pair<int, int> r{root->val, root->val};
		if (root->left) l = helper(root->left, ans);
		if (root->right) r = helper(root->right, ans);
		int Cmax = max(l.first, r.first);
		int Cmin = min(l.second, r.second);

		int d = max(abs(root->val - Cmax), abs(root->val - Cmin));
		ans = max(d, ans);

		int Tmax = max(root->val, Cmax);
		int Tmin = min(root->val, Cmin);

		return make_pair(Tmax, Tmin);
	}

	int maxAncestorDiff(TreeNode* root) {
		int ans = 0;
		pair<int, int> p = helper(root, ans);
		return ans;
	}
};