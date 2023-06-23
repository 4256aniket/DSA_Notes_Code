#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>


// Recursion
// class Solution {
// public:

// 	int solve(vector<int>& coins, int n, int ind, int amount) {
// 		if (ind == n) {
// 			return 0;
// 		}

// 		if (amount == 0) {
// 			return 1;
// 		}

// 		int ans = 0;
// 		if (amount >= coins[ind]) {
// 			ans += solve(coins, n, ind, amount - coins[ind]);
// 		}
// 		ans += solve(coins, n, ind + 1, amount);

// 		return ans;
// 	}

// 	int change(int amount, vector<int>& coins) {
// 		int n = coins.size();
// 		return solve(coins, n, 0, amount);
// 	}
// };


// Tabulation
class Solution {
public:

	int change(int amount, vector<int>& coins) {
		int n = coins.size();
		vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

		for (int j = 0; j <= amount; j++) dp[n][j] = 0;
		for (int i = 0; i <= n; i++) dp[i][0] = 1;

		for (int i = n - 1; i >= 0; i--) {
			for (int j = 1; j <= amount; j++) {
				if (j >= coins[i]) {
					dp[i][j] += dp[i][j - coins[i]];
				}
				dp[i][j] += dp[i + 1][j];
			}
		}

		return dp[0][amount];
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);


	int n, a;
	cin >> n >> a;
	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	Solution obj;
	cout << obj.change(a, v) << endl;

}