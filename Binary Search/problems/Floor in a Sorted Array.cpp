/*
Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. Find the index of K(0-based indexing).

Example 1:
Input:
N = 7, x = 0 
arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less 
than 0 is found. So output 
is "-1".

Example 2:
Input:
N = 7, x = 5 
arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest Number less than 5 is
2 (i.e K = 2), whose index is 1(0-based 
indexing).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        long long s = 0;
        long long e = n-1;
        long long ans = -1;
        long long mid = s + (e-s)/2;
        
        while( s <= e ){
            
            if(v[mid] == x){
                return mid;
            }else if(v[mid] < x){
                ans = mid;
                s = mid+1;
            }else if(v[mid] > x){
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};