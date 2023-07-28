/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1){
            vector<vector <int> > v;
            v.push_back({nums[0]});
            return v;
        }
        int count = nums.size();
        int a = nums[nums.size()-1];
        nums.erase(nums.end()-1);
        vector<vector<int> >op = permute(nums);
        int size = op.size();
        vector<vector<int> > v;
        
       
        int i = 0;
        for(; i < (count*size) ;i++){
            v.push_back(op[i%size]);
        }
        i = 0;
        int k = 0;
        for(; k < count-1; k++){
            for(int j = 0; j < size ;j++ ){
                v[i].insert(v[i].begin()+k , a);
                i++;
            }
        }
        
        for(int j = 0; j < size ;j++ ){
                v[i].push_back(a);
                i++;
            }
        
        return v;
    }
};