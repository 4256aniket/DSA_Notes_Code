/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/


class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();

		int w = amount;
		int t[n + 1][w + 1];
		for (int j = 0; j < w + 1; j++) t[0][j] = INT_MAX - 1;
		for (int i = 0; i < n + 1; i++) t[i][0] = 0;
		for (int j = 1; j < w + 1; j++) {
			if (j % coins[0] == 0) t[1][j] = j / coins[0];
			else t[1][j] = INT_MAX - 1;
		}

		for (int i = 2; i < n + 1; i++) {
			for (int j = 1; j < w + 1; j++) {
				if (coins[i - 1] <= j) {
					t[i][j] = min(1 + t[i][j - coins[i - 1]] , t[i - 1][j]);
				} else {
					t[i][j] = t[i - 1][j];
				}
			}
		}
		if (t[n][w] == INT_MAX - 1)return -1;
		return t[n][w];
	}
};