// https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[n - 1][m - 1] == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n - 1][m - 1] = 1;


        for (int i = n - 1; i >= 0; i--) {
            if (grid[i][m - 1] == 1) break;
            dp[i][m - 1] = 1;
        }
        for (int i = m - 1; i >= 0; i--) {
            if (grid[n - 1][i] == 1) break;
            dp[n - 1][i] = 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



}