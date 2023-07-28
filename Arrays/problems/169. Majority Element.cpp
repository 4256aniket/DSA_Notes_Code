/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Input: nums = [3,2,3]
Output: 3

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count  = 0;
        int ans = 0;
        for(auto x : nums){
            if(count == 0) ans = x;
            
            if(ans == x){
                count++;
            }else{
                count--;
            }
        }
        return ans;
    }
};