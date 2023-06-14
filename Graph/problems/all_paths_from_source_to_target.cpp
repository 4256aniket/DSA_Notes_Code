// https://leetcode.com/problems/all-paths-from-source-to-target/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

// Here we don't need vis because it is a DAG and we need all paths
	void dfs(vector<vector<int>>& graph, int s, int d, vector<int>& path, vector<vector<int>>& ans) {
		path.push_back(s);
		if (s == d) {
			ans.push_back(path);
		}
		for (auto adj : graph[s]) {
			dfs(graph, adj, d, path, ans);
		}
		path.pop_back();
	}

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> ans;
		int n = graph.size();
		vector<int> path;
		dfs(graph, 0, n - 1, path, ans);
		return ans;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


}