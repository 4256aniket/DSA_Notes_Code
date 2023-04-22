/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;
        int n = nums.size();
        int ans = INT_MIN;
        if(n==1)return 0;
        
        while( s <= e ){
            if(mid>0 && mid<n-1){
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    return mid;
                }else if(nums[mid-1]>nums[mid]){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }else if(mid == 0){
                if(nums[0]>nums[1])return 0;
                else return 1;
            }else if(mid == n-1){
                if(nums[n-1]>nums[n-2])return n-1;
                else return n-2;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};