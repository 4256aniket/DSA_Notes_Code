/*
You are given N number of books. Every ith book has Ai number of pages. The books are arranged in ascending order.

You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:{12} and {34, 67, 90} 
Maximum Pages = 191{12, 34} and {67, 90} 
Maximum Pages = 157{12, 34, 67} and {90} 
Maximum Pages =113. Therefore, the minimum 
of these cases is 113, which is selected 
as the output.

Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:32
Explanation: Allocation is done as
{15,17} and {20}
Your Task:
You don't need to read input or print anything. Your task is to complete the function findPages() which takes 2 Integers N, and m and an array A[] of length N as input and returns the expected answer.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    bool isValid(int A[], int N, int M, long long mx){
        int student = 1;
        long long sum = 0;
        for(int i =0; i< N;i++){
            sum += A[i];
            
            if(sum > mx){
                student++;
                sum = A[i];
            }
            
            if(student > M)return false;
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M > N)return -1;
        long long sum = 0;
        int res = -1;
        int max = A[0];
        
        for(int i = 0;i<N;i++){
            if(A[i]>max) max = A[i];
            
            sum += A[i];
        }
        
        long long s = max;
        long long e = sum;
        long long mid = s + (e-s)/2;
        
        while(s<=e){
            if(isValid(A,N,M,mid)){
                res = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
             mid = s + (e-s)/2;
        }
        return res;
    }
};