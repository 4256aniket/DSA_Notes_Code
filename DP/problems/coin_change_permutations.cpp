#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

// Tabulation
class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);

        dp[0] = 1;

        for (int j = 1; j <= amount; j++) {
            for (int i = 0; i < n; i++) {
                if (j >= coins[i]) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }

        return dp[amount];
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::ios::sync_with_stdio(false);


    int n, a;
    cin >> n >> a;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    Solution obj;
    cout << obj.change(a, v) << endl;

}