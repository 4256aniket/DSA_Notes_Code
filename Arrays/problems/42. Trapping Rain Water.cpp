/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int ans = 0;
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        int lmax = 0;
        int rmax = 0;
        for (int i = 0; i < n; i++)
        {
            l[i] = lmax;
            lmax = max(lmax, height[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            r[i] = rmax;
            rmax = max(height[i], rmax);
        }
        for (int i = 0; i < n; i++)
        {
            int k = min(l[i], r[i]);
            if (k > height[i])
            {
                ans += (k - height[i]);
            }
        }
        return ans;
    }
};