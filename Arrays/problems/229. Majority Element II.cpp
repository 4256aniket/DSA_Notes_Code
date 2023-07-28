/*
Given an integer array of size n, find all elements that appear more than   ⌊n/3⌋ times.

Input: nums = [3,2,3]
Output: [3]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = n/3;
        int nums1 = -1;
        int nums2 = -1;
        int c1 = 0;
        int c2 = 0;
        for(auto x : nums){
            if(x == nums1){c1++;}
            else if(x == nums2){c2++;}
            else if(c1 == 0){nums1 = x;c1++;}
            else if(c2 == 0){nums2 = x;c2++;}
            else{
                c1--;c2--;
            }
        }
        c1 = 0;c2 = 0;
        for(auto x : nums){
            if(x == nums1)c1++;
            if(x == nums2)c2++;
        }
        vector<int> ans;
        if(c1 > cnt)ans.push_back(nums1);
        if(c2 > cnt)ans.push_back(nums2);
        if(nums1 == nums2)ans.pop_back();
        
        return ans;
    }
};