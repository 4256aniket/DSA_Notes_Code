// https://leetcode.com/problems/target-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // s1 -> subset sum of subset 1
    // s2 -> subset sum of subset 2
    // abs(s1 - s2) = target
    // s1 + s2 = sum of array
    // find no of valid s1

    int helper(vector<int>& arr, int n, int ind, int k, vector<vector<int>>& dp) {
        if (ind == n) {
            if (k == 0) return 1;
            return 0;
        }
        if (dp[ind][k] != -1) return dp[ind][k];
        int ans = 0;
        // take
        if (arr[ind] <= k) ans += helper(arr, n, ind + 1, k - arr[ind], dp);
        // not take
        ans += helper(arr, n, ind + 1, k, dp);

        return dp[ind][k] = ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, n = nums.size();
        target = abs(target);
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum < target || (sum + target) % 2 != 0) return 0;
        int s1 = (sum + target) / 2;
        vector<vector<int>> dp(n, vector<int>(s1 + 1, -1));
        helper(nums, n, 0, s1, dp);
        return dp[0][s1];
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    Solution obj;
    cout << obj.findTargetSumWays(v, k);

}