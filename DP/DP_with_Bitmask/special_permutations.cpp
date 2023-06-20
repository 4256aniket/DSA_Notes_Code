#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int per(vector<int>& nums, int ind, int n, int mask, vector<int>& aof) {
        if (ind == n) {
            for (int i = 0; i < n; ++i) cout << aof[i] << " ";
            cout << endl;
            return 1;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            aof.push_back(nums[i]);
            ans = (ans + per(nums, ind + 1, n, mask | (1 << i), aof)) % mod;
            aof.pop_back();
        }
        return ans;
    }

    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<int> aof;
        return per(nums, 0, n, 0, aof);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution obj;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans = obj.specialPerm(v);
    cout << ans << endl;

}
