/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
int firstOccurance(vector<int> &arr, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e){
        
        if (arr[mid] == k){
            ans = mid;
            e = mid-1;
        }
        else if (arr[mid] > k){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOccurance(vector<int> &arr, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e){
        if (arr[mid] == k){
            ans = mid;
            s = mid+1;
        }
        else if (arr[mid] > k){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> p(2);
        p[0] = firstOccurance(nums, nums.size(), target);
        p[1] = lastOccurance(nums, nums.size(), target);
        return p;
    }
};