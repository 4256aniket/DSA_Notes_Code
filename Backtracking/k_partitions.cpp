#include <bits/stdc++.h>
using namespace std;

// partion [1,n] int to k subsets
// eg n = 3, k = 2
// 1. [1,2], 3
// 2. [1,3], 2
// 3. 1, [1,2]

void solve(int i, int n, int k, int nos, vector<vector<int>>& ans) {
	if (i > n) {
		if (nos == k) {
			for (auto it : ans) {
				for (auto i : it) cout << i << " ";
				cout << endl;
			}
		}
		return;
	}
	for (int j = 0; j < ans.size(); j++) {
		if (ans[j].size() > 0) {
			ans[j].push_back(i);
			solve(i + 1, n, k, nos, ans);
			ans[j].pop_back();
		} else {
			ans[j].push_back(i);
			solve(i + 1, n, k, nos + 1, ans);
			ans[j].pop_back();
			break;
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<vector<int>> ans(k);
	solve(1, n, k, 0, ans);
}