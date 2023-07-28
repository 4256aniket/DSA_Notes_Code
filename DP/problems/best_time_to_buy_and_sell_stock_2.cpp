#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define cll vector<long long int>

// Memoization
class Solution {
public:

	int solve(vector<int>& prices, int ind, int canTake, vector<vector<int>>& dp) {

		if (ind == prices.size()) return -1;

		if (dp[ind][canTake] != -1) return dp[ind][canTake];

		int op1 = 0, op2 = 0;
		if (canTake) {
			// didn't take previously
			op1 = max(-prices[ind] + solve(prices, ind + 1, 0, dp), solve(prices, ind + 1, 1, dp));
		} else {
			// holding prev stock
			op2 = max(prices[ind] + solve(prices, ind, 1, dp), solve(prices, ind + 1, 0, dp));
		}
		return dp[ind][canTake] = max(op1, op2);
	}

	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, -1));
		return solve(prices, 0, 1, dp);
	}
};


// Tabulation

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxPro = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > prices[i - 1]) {
				maxPro += prices[i] - prices[i - 1];
			}
		}
		return maxPro;
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
	cout << obj.maxProfit(v) << endl;

}





