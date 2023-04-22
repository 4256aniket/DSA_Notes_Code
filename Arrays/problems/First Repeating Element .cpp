/*
Given an array arr[] of size n, find the first repeating element. The element should occurs more than once and the index of its first occurrence should be the smallest.

Input:
n = 7
arr[] = {1, 5, 3, 4, 3, 5, 6}
Output: 2
Explanation: 
5 is appearing twice and 
its first appearence is at index 2 
which is less than 3 whose first 
occuring index is 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        int ans = n;
        unordered_map<int,int> m;
        for(int i = n-1;i>=0;i--){
            if(!m.count(arr[i])){
                m[arr[i]] = i;
            }else{
                ans = i+1;
        }
    }
    if(ans == n)ans = -1;
    return ans;
    }
};