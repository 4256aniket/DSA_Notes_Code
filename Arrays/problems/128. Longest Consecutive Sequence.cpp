/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        unordered_set<int> h;
        
        for(int i = 0 ; i < nums.size() ; i++)
            h.insert(nums[i]);

        int MAX_LEN = 1;
        int l,k;
        for(int i = 0 ; i < nums.size() ; i++){            
            if(h.find(nums[i]+1) == h.end() && h.find(nums[i]-1) == h.end() )
                continue;
            
            l = 1;
            h.erase(h.find(nums[i]));
            // inc
            k = nums[i]+1;
            while(h.find(k) != h.end()){
                h.erase(k);
                k++;
                l++;
            }
            
            // dec
            k = nums[i]-1;
            while(h.find(k) != h.end()){
                h.erase(k);
                k--;
                l++;
            }
            MAX_LEN = max(MAX_LEN, l);
        }    
        return MAX_LEN;        
    }
};