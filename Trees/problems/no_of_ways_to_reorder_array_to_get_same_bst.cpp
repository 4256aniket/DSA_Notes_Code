// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
#include <bits/stdc++.h>
using namespace std;

// Here relative order of elements in left-subtree and right-subtree should remain same
// So question is to find no of such permutations in which nums[0] remains at its place
// --> and relative order of elements in subtrees remains same
// it is C(n-1, left_size)
// Do it recursively 

class Solution {
public:
	int mod = 1e9 + 7;
	vector<vector<long long>> pascleTriangle;

	void build(int n) {
		pascleTriangle.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			pascleTriangle[i] = vector<long long>(i + 1, 1);
			for (int j = 1; j < i; j++) {
				pascleTriangle[i][j] = (pascleTriangle[i - 1][j - 1] + pascleTriangle[i - 1][j]) % mod;
			}
		}
	}

	int dfs(vector<int>& nums) {
		int n = nums.size();
		if (n <= 2) return 1;
		vector<int> left, right;
		for (int i = 1; i < n; i++) {
			if (nums[i] < nums[0]) left.push_back(nums[i]);
			else right.push_back(nums[i]);
		}
		long long lans = dfs(left) % mod;
		long long rans = dfs(right) % mod;
		int lsize = left.size();

		long long ans = (((pascleTriangle[n - 1][lsize] * lans) % mod) * rans) % mod;
		return ans;
	}

	int numOfWays(vector<int>& nums) {
		int n = nums.size();
		build(n);
		int ans = dfs(nums) % mod;
		return ans - 1;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	build(n);
	for (auto r : pascleTriangle) {
		for (auto e : r) {
			cout << e << " ";
		}
		cout << endl;
	}

}