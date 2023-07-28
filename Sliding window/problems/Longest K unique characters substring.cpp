/*
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest
substring with K distinct characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // your code here
        int mx = -1;
        unordered_map<int, int> m;
        int i = 0, j = 0;
        while (j < s.size())
        {
            m[s[j]]++;
            if (m.size() < k)
            {
                j++;
            }
            else if (m.size() == k)
            {
                mx = max(mx, j - i + 1);
                j++;
            }
            else if (m.size() > k)
            {
                while (m.size() > k)
                {
                    m[s[i]]--;
                    if (m[s[i]] == 0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};