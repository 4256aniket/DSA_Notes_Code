#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

class Solution {
public:

    int solve(vector<int>& nums, int ind, int n, vector<int> & dp) {
        if (ind == n - 1) return 0;
        if (ind >= n) return 100000;

        int ans = 100000;
        if (dp[ind] != -1) return dp[ind];
        if (nums[ind] == 0) return ans;
        for (int i = 1; i <= nums[ind]; i++) {
            ans = min(ans, 1 + solve(nums, ind + i, n, dp));
        }

        return dp[ind] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = solve(nums, 0, n, dp);
        return (ans == 100000) ? -1 : ans;
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
    cout << obj.jump(v) << endl;

}











