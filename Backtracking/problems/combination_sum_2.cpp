// https://leetcode.com/problems/combination-sum-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	void helper(vector<int>& candidates, int target, int index, int n, vector<int>& asf, vector<vector<int>>& ans) {
		if (index == n) {
			if (target == 0) ans.push_back(asf);
			return;
		}

		// take
		if (candidates[index] <= target) {
			asf.push_back(candidates[index]);
			helper(candidates, target - candidates[index], index + 1, n, asf, ans);
			asf.pop_back();
		}
		while (index + 1 < n && candidates[index] == candidates[index + 1]) ++index;
		// not take
		helper(candidates, target, index + 1, n, asf, ans);
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> asf;
		int n = candidates.size();
		helper(candidates, target, 0, n, asf, ans);
		return ans;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Solution obj;
	int n, target;
	cin >> n >> target;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<vector<int>> ans = obj.combinationSum2(v, target);

	for (auto r : ans) {
		for (auto e : r) cout << e <<" ";
		cout << endl;
	}
}







