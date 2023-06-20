#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums, int f, int s){
        int n = nums.size();
        vector<int> dp1(n, 0), dp2(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i < f) {
                sum += nums[i];
                dp1[i] = sum;
            } else {
                sum += nums[i] - nums[i - f];
                dp1[i] = max(dp1[i - 1], sum);
            }
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i + s >= n) {
                sum += nums[i];
                dp2[i] = sum;
            } else {
                sum += nums[i] - nums[i + s];
                dp2[i] = max(dp2[i + 1], sum);
            }
        }

        int ans = 0;
        for (int i = f-1; i < n - s; i++) {
            ans = max(ans, dp2[i + 1] + dp1[i]);
        }
        return ans;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        return max(helper(nums, f, s), helper(nums, s, f));
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    

}