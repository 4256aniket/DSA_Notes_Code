#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

class Solution {
public:

	int solve(vector<int>& prices, int prev, int ind, int canTake, int t, vector<vector<vector<int>>>& dp) {

		if (ind == prices.size() || t == 0) return 0;

		if (dp[ind][canTake][t] != -1) return dp[ind][canTake][t];

		int op1 = 0, op2 = 0;
		if (canTake) {
			// didn't take previously
			op1 = max(-prices[ind] + solve(prices, ind, ind + 1, 0, t, dp), solve(prices, prev, ind + 1, 1, t, dp));
		} else {
			// holding prev stock
			op2 = max(prices[ind] + solve(prices, -1, ind, 1, t - 1, dp), solve(prices, prev, ind + 1, 0, t, dp));
		}
		return dp[ind][canTake][t] = max(op1, op2);
	}

	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
		return solve(prices, -1, 0, 1, 2, dp);
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





