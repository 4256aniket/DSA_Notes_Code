#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

// Tabulation
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		vector<vector<int>> dp(n + 1, vector<int>(2, 0));
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < 2; j++) {
				if (j == 1) {
					dp[i][j] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
				} else {
					dp[i][j] = max(prices[i] + dp[i + 1][1] - fee, dp[i + 1][0]);
				}
			}
		}
		return dp[0][1];
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);



}