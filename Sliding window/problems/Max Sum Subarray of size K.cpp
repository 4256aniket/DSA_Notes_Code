/*
Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    long long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i = 0;
        int j = 0;
        long long sum = 0;
        long long maxSum = INT_MIN;
        while(j<Arr.size()){
            sum += Arr[j];
            if((j-i+1) < K){
                j++;
            }else if((j-i+1) == K){
                maxSum = max(maxSum,sum);
                sum -= Arr[i];
                i++;
                j++;
            }
        }
        return maxSum;
    }
};
