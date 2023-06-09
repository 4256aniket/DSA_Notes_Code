/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


Constraints:

1 <= n <= 45
*/


// Recursive
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int t[50];
    int helper(int n)
    {

        if (n == 0)
            return 1;
        if (n >= 0 && t[n] != -1)
            return t[n];
        if (n < 0)
            return 0;
        int a = helper(n - 1);
        int b = helper(n - 2);
        return t[n] = a + b;
    }

    int climbStairs(int n)
    {
        memset(t, -1, sizeof(t));
        return helper(n);
    }
};


// Top Down
class Solution {
public:
    int climbStairs(int n) {
        vector<int> t(50);
        int i = 0;
        t[1] = 1;
        t[2] = 2;
        for(int i = 3; i <= n; i++){
            t[i] = t[i-1]+t[i-2];
        }
        
        return t[n];
    }
};