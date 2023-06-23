#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

// memoizaton
class Solution {
public:

	int solve(vector<int>& nums, int ind, int diff, unordered_map<int, int> dp) {
		if (ind < 0) return 0;

		if (dp[ind].count(diff)) return dp[ind][diff];
		int ans = 0;
		for (int j = ind - 1; j >= 0; j--) {
			if (nums[ind] - nums[j] == diff) {
				ans = max(ans, 1 + solve(nums, j, diff, dp));
			}
		}

		return dp[ind][diff] = ans;
	}

	int longestArithSeqLength(vector<int>& nums) {
		int n = nums.size();
		if (n <= 2) return n;
		int ans = 0;
		unordered_map<int, int> dp[n + 1];
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = max(ans, 2 + solve(nums, i, nums[j] - nums[i], dp));
			}
		}

		return ans;
	}
};

// Tabulation
class Solution {
public:
	int longestArithSeqLength(vector<int>& nums) {
		int ans = 0, n = nums.size();
		unordered_map<int, int> dp[n + 1];

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				int diff = nums[i] - nums[j];
				int cnt = 1;
				// check if ans already present
				if (dp[i].count(diff)) cnt = dp[i][diff];

				dp[i][diff] = 1 + cnt;

				ans = max(ans, dp[i][diff]);
			}
		}
		return ans;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	Solution obj;
	cout << obj.longestArithSeqLength(v) << endl;

}


