/*
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                        long long int N, long long int K) {
    vector<long long>v;
    list<long long> l;
    long long i = 0,j = 0; 
    while(j<N){
        if(A[j]<0)l.push_back(A[j]);
        
        if((j-i+1)<K){
            j++;
        }else if((j-i+1) == K){
            if(l.size()==0){
                v.push_back(0);
            }else{
                v.push_back(l.front());
                if(A[i]==l.front()) l.pop_front();
            }
            j++;
            i++;
        }
    }
    return v;
    
 }