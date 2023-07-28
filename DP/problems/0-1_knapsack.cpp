/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        int t[n + 1][W + 1];
        for (int i = 0; i < n + 1; i++)
            t[i][0] = 0;
        for (int j = 0; j < W + 1; j++)
            t[0][j] = 0;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < W + 1; j++)
            {
                if (wt[i - 1] <= j)
                {
                    t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][W];
    }
};



// -------------------- Recursive memoized code --------------------

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lld long double
#define endl "\n"
#define M 1000000007
#define forn(i, n) for (int i = 0; i < int(n); i++)
const int inf = 1e9 + 7;

int t[100][100];

int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    // Your code here

    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (t[n][W] != -1)
    {
        return t[n][W];
    }

    if (wt[n - 1] <= W)
    {
        return t[n][W] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
    }
    else if (wt[n - 1] > W)
    {
        return t[n][W] = knapSack(W, wt, val, n - 1);
    }
    return t[n][W];
}

int main()
{
    // Aniket Kumar
    int n, w;
    cin >> n >> w;
    memset(t, -1, sizeof(t));
    vector<int> wt(n);
    vector<int> val(n);
    forn(i, n) cin >> wt[i];
    forn(i, n) cin >> val[i];
    int ans = knapSack(w, wt, val, n);
    cout << ans << endl;
    return 0;
}
