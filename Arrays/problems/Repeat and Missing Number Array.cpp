/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:
Input:[3 1 2 5 3]
Output:[3, 4]
A = 3, B = 4
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A)
{
    vector<int> v(A.size() + 1, 0);
    for (int i = 0; i < A.size(); i++)
    {
        v[A[i]] += 1;
    }
    int a, b;
    for (int i = 1; i <= A.size(); i++)
    {
        if (v[i] == 0)
            b = i;
        else if (v[i] == 2)
            a = i;
    }
    return {a, b};
}