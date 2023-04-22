/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int flag  = 1;
        for(auto x : nums){
            if(x!=0)flag  = 0;
        }
        int len = 0;
        int l = 0, r = 0;
        for(;r<nums.size();r++){
            if(r<nums.size() && nums[r] == 0){
                while(r<nums.size() and nums[r] == 0)r++;
                l = r;
            }
            len = max(r-l+1,len);
        }
        if(flag){
            return 0;
        }else{
            return len;
        }
    }
};