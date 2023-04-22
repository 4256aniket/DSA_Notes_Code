/*

*/


class Solution {
public:

	void tree(TreeNode* root, vector<int>& ans) {
		if (root == nullptr) return;
		tree(root->left, ans);
		ans.push_back(root->val);
		tree(root->right, ans);

	}

	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

		vector<int> t1;
		tree(root1, t1);
		vector<int> t2;
		tree(root2, t2);
		vector<int> res;
		int i = 0, j = 0;
		while (i < t1.size() && j < t2.size()) {
			if (t1[i] <= t2[j]) {
				res.push_back(t1[i]);
				i++;
			} else {
				res.push_back(t2[j]);
				j++;
			}
		}

		while (i < t1.size()) {
			res.push_back(t1[i]);
			i++;
		}

		while (j < t2.size()) {
			res.push_back(t2[j]);
			j++;
		}
		return res;
	}
};