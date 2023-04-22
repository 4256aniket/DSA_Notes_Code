/*
For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').

Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
*/

#include <bits/stdc++.h>
using namespace std;

long long merge(long long arr[], long long temp[], int left, int mid, int right)
{
    int inv_count = 0;
    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long merge_Sort(long long arr[], long long temp[], int left, int right)
{
    long long mid, inv_count = 0;
    if (right > left)
    {
        mid = (left + right) / 2;

        inv_count += merge_Sort(arr, temp, left, mid);
        inv_count += merge_Sort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

long long getInversions(long long *arr, int n)
{
    // Write your code here.
    long long temp[n];
    long long ans = merge_Sort(arr, temp, 0, n - 1);

    return ans;
}
