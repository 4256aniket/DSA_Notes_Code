#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

class Solution {
public:
	int maxProfit(int K, vector<int>& prices) {
		int n = prices.size();
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(K + 1, 0)));

		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < 2; j++) {
				for (int k = 1; k <= K; k++) {
					if (j == 1) {
						dp[i][j][k] = max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
					} else {
						dp[i][j][k] = max(prices[i] + dp[i + 1][1][k - 1], dp[i + 1][0][k]);
					}
				}
			}
		}
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);



}