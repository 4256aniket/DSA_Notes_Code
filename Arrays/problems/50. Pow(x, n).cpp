/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Input: x = 2.00000, n = 10
Output: 1024.00000

Input: x = 2.10000, n = 3
Output: 9.26100
*/

#include <bits/stdc++.h>
using namespace std;

// Binary Exponentiation

class Solution
{
public:
    double myNewPow(double x, int n)
    {
        double res = 1;
        while (n > 0)
        {
            if (n & 1)
            {
                res *= x;
            }
            x *= x;
            n = n >> 1;
        }
        return res;
    }
    double myPow(double x, int n)
    {
        if (n >= 0)
        {
            return myNewPow(x, n);
        }
        return 1.0 / myNewPow(x, abs(n));
    }
};

// Recursive

class Solution
{
public:
    double myNewPow(double x, int n)
    {

        if (n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return x;
        }
        double small_ans = myPow(x, n / 2);
        double final_ans = small_ans * small_ans;
        if (n % 2 != 0)
        {
            final_ans *= x;
        }
        return final_ans;
    }
    double myPow(double x, int n)
    {
        if (n >= 0)
        {
            return myNewPow(x, n);
        }
        return 1.0 / myNewPow(x, abs(n));
    }
};