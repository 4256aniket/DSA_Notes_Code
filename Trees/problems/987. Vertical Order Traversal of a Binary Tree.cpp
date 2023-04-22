/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
*/


class Solution {
public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		map<int, map<int, multiset<int>>> mp;
		queue<pair<TreeNode*, pair<int, int>>> q;
		q.push({root, {0, 0}});
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			TreeNode* node = p.first;
			int x = p.second.first, y = p.second.second;
			mp[x][y].insert(node->val);
			if (node->left) {
				q.push({node->left, {x - 1, y + 1}});
			}
			if (node->right) {
				q.push({node->right, {x + 1, y + 1}});
			}
		}
		vector<vector<int>> ans;
		for (auto q : mp) {
			vector<int> col;
			for (auto p : q.second) {
				col.insert(col.end(), p.second.begin(), p.second.end());
			}
			ans.push_back(col);
		}
		return ans;
	}
};