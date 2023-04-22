/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
*/


class Solution {
public:

	void buildGraph(TreeNode* root, unordered_map<int, vector<int>>& graph) {

		if (root->left != NULL) {
			graph[root->val].push_back(root->left->val);
			graph[root->left->val].push_back(root->val);
			buildGraph(root->left, graph);
		}
		if (root->right != NULL) {
			graph[root->val].push_back(root->right->val);
			graph[root->right->val].push_back(root->val);
			buildGraph(root->right, graph);
		}
	}


	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {

		if (K == 0)
			return {target->val};

		unordered_map<int, vector<int>> graph;
		unordered_map<int, bool> visited;
		vector<int> res;
		queue<int> q;
		int cnt = 0;
		buildGraph(root, graph);
		q.push(target->val);

		while (!q.empty()) {
			int sz = q.size();
			for (int i = 0; i < sz; i++) {

				int curr = q.front();
				q.pop();
				visited[curr] = true;

				for (int x : graph[curr])
					if (!visited[x])
						q.push(x);
			}
			cnt++;
			if (cnt == K) {
				while (!q.empty()) {
					res.push_back(q.front());
					q.pop();
				}
				break;
			}

		}

		return res;
	}
};