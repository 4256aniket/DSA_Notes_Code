/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.
*/


class Solution {
public:
	int change(int amount, vector<int>& coins) {
		int n = coins.size();
		int w = amount;

		int t[n + 1][w + 1];

		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < w + 1; j++) {
				t[i][j] = 0;
				if (i == 0) t[i][j] = 0;
				if (j == 0) t[i][j] = 1;
			}
		}

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < w + 1; j++) {
				if (coins[i - 1] <= j) {
					t[i][j] = (t[i][j - coins[i - 1]]) + (t[i - 1][j]);
				}
				else {
					t[i][j] = t[i - 1][j];
				}
			}
		}
		return t[n][w];
	}
};
