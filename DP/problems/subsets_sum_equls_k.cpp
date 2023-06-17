#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

bool helper(int n, int ind, int k, vector<int> &arr, vector<vector<int>>& dp) {
	if (ind == n) {
		if (k == 0) return true;
		return false;
	}
	if (dp[ind][k] != -1) return dp[ind][k];
	bool ans = false;
	// take
	if (arr[ind] <= k) ans |= helper(n, ind + 1, k - arr[ind], arr, dp);
	// not take
	ans |= helper(n, ind + 1, k, arr, dp);

	return dp[ind][k] = ans;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
	// Write your code here.
	vector<vector<int>> dp(n, vector<int> (k + 1, -1));
	return helper(n, 0, k, arr, dp);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	cout << subsetSumToK(n, k, v);
}