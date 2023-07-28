class Solution
{
public:
    int equilibriumPoint(long long a[], int n)
    {
        // Your code here
        if (n == 1)
            return n;
        for (int i = 1; i < n; i++)
        {
            a[i] = a[i - 1] + a[i];
        }
        for (int i = 1; i < n; i++)
        {
            int sum = a[n - 1] - a[i];
            if (sum == a[i - 1])
                return i + 1;
        }
        return -1;
    }
};