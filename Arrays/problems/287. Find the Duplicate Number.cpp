/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Input: nums = [1,3,4,2,2]
Output: 2

Input: nums = [3,1,3,4,2]
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0];
        int f = nums[0];
        do{
            s = nums[s];
            f = nums[nums[f]];
        }while(s!=f);
        
        f = nums[0];
        while(s!=f){
            s = nums[s];
            f = nums[f];
        }
        
        return s;
    }
};