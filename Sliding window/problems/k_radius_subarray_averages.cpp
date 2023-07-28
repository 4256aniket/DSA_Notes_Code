// https://leetcode.com/problems/k-radius-subarray-averages/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> getAverages(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> ans(n, -1);
		if (n <= 2 * k) return ans;
		long long sum = 0, d = 2 * k + 1;
		for (int i = 0; i <= 2 * k; i++) {
			sum += nums[i];
		}

		for (int i = k; i < n - k; i++) {
			int avg = sum / d;
			ans[i] = avg;
			sum -= nums[i - k];
			if (i + k + 1 < n) sum += nums[i + k  + 1];
		}
		return ans;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Solution obj;
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	vector<int> ans = obj.getAverages(v, k);
	for (auto i : ans) cout << i << " ";

}