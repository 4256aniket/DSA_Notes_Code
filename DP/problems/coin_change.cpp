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
// 			return INT_MAX - 1;
// 		}

// 		if (amount == 0) {
// 			return 0;
// 		}

// 		int ans = 0;
// 		if (amount >= coins[ind]) {
// 			ans = min(1 + solve(coins, n, ind, amount - coins[ind]), solve(coins, n, ind + 1, amount));
// 		} else {
// 			ans = solve(coins, n, ind + 1, amount);
// 		}
// 		return ans;

// 	}

// 	int coinChange(vector<int>& coins, int amount) {
// 		int n = coins.size();
// 		int ans = solve(coins, n, 0, amount);

// 		return (ans == INT_MAX - 1) ? -1 : ans;
// 	}
// };


// Tabulation
class Solution {
public:

	int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();
		vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

		for (int j = 0; j <= amount; j++) dp[n][j] = INT_MAX - 1;
		for (int i = 0; i <= n; i++) dp[i][0] = 0;

		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j <= amount; j++) {
				if (j >= coins[i]) {
					dp[i][j] = min(1 + dp[i][j - coins[i]], dp[i + 1][j]);
				} else {
					dp[i][j] = dp[i + 1][j];
				}
			}
		}

		return (dp[0][amount] == INT_MAX - 1) ? -1 : dp[0][amount];
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
	cout << obj.coinChange(v, a) << endl;

}