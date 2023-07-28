/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/



#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)


int countSubsets(vector<int>& nums, int n, int M)
{
	int t[n + 1][M + 1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (i == 0)
				t[i][j] = 0;
			if (j == 0)
				t[i][j] = 1;
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (nums[i - 1] <= j)
				t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][M];
}

int findTargetSumWays(vector<int>& nums, int target) {
	target = abs(target);
	int n = nums.size();
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += nums[i];

	int M = (sum + target) / 2;
	if (sum < target || (sum + target) % 2 != 0)
		return 0;

	return countSubsets(nums, n, M);
}


int main() {
	// Aniket Kumar
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	forn(i, n)cin >> v[i];
	cout << findTargetSumWays(v, m) << endl;

	return 0;
}