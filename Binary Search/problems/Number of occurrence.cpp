/*
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	

int firstOccurance(int arr[], int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid = s + (e-s)/2;
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
        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOccurance(int arr[], int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid = s + (e-s)/2;
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
        mid = s + (e-s)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(int arr[], int n, int k)
{
    pair<int, int> p;
    p.first = firstOccurance(arr, n, k);
    p.second = lastOccurance(arr, n, k);
    return p;
}
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    pair<int, int> p;
	    p = firstAndLastPosition(arr,n,x);
	    if(p.first == -1 || p.second ==- 1)return 0;
	    int ans = (p.second - p.first)+1;
	    return ans;
	}
};