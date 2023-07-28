/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {
        int sum  = 0;
        int maxi = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i)
        {
            sum += A[i];
            if (sum == 0) {
                maxi = i + 1;
            } else {
                if (m.count(sum)) {
                    maxi = max(maxi, i - m[sum]);
                } else {
                    m[sum] = i;
                }
            }
        }
        return maxi;
    }
};