/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
*/

#include <bits/stdc++.h>
using namespace std;

bool isOk(vector<int> &stalls, int mid, int k)
{
    int count = 1;
    int prev = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - prev >= mid)
        {
            count++;
            prev = stalls[i];
        }
    }
    return (count >= k);
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0, e = stalls[stalls.size() - 1] - stalls[0], ans = 0;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (isOk(stalls, mid, k))
        {
            s = mid + 1;
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}