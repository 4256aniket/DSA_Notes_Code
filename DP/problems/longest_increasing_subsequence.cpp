#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

// Recursion
class Solution {
public:

	int solve(vector<int>& nums, int n, int ind, int prev) {
		if (ind == n) return 0;

		int op1 = 0, op2  = 0;

		if (prev == -1 || nums[ind] > nums[prev]) {
			op1 = max(1 + solve(nums, n, ind + 1, ind), solve(nums, n, ind + 1, prev));
		} else {
			op2 = solve(nums, n, ind + 1, prev);
		}
		return max(op1 , op2);
	}

	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		return solve(nums, n, 0, -1);
	}
};


// Tabulation
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int ans = 1, n = size(nums);
		vector<int> dp(n, 1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				if (nums[i] > nums[j])
					dp[i] = max(dp[i], dp[j] + 1), ans = max(ans, dp[i]);
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
	cout << obj.lengthOfLIS(v) << endl;

}