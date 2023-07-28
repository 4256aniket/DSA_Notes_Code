/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size(), s = 0, ans = 1000000;
        
        for(int i = 0; i < n ; i++) s += nums[i];
        
        if(s < x) return -1;
        
        int st = 0, end = 0, windowSum = 0;
        
        while(end < n){            
            windowSum += nums[end];            
            while(windowSum > (s - x)){
                windowSum -= nums[st];
                st++;
            }            
            if(windowSum == s - x){
                ans = min(ans, n - (end - st + 1));
            }            
            end++;            
        }
		
        return (ans == 1000000 ? -1 : ans);
        
    }
};