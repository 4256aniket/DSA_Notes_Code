/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.


Input: m = 3, n = 7
Output: 28
*/

#include <bits/stdc++.h>
using namespace std;

// DP solution with recursion

class Solution
{
public:
    int countPaths(int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if (i == (n - 1) && j == (m - 1))
            return 1;
        if (i >= n || j >= m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        else
            return dp[i][j] = countPaths(i + 1, j, n, m, dp) + countPaths(i, j + 1, n, m, dp);
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        int num = countPaths(0, 0, m, n, dp);
        if (m == 1 && n == 1)
            return num;
        return dp[0][0];
    }
};

// Optimal solution with combination

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int N = n + m - 2;
        int r = m - 1;
        double res = 1;
        for (int i = 1; i <= r; i++)
        {
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};