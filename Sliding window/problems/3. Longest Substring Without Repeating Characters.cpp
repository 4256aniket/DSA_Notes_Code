/*
Given a string s, find the length of the longest substring without repeating characters.

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string str)
    {
        if (str.size() == 0)
            return 0;
        int maxans = INT_MIN;
        unordered_set<int> set;
        int l = 0;
        for (int r = 0; r < str.length(); r++)
        {
            if (set.find(str[r]) != set.end())
            {
                while (l < r && set.find(str[r]) != set.end())
                {
                    set.erase(str[l]);
                    l++;
                }
            }
            set.insert(str[r]);
            maxans = max(maxans, r - l + 1);
        }
        return maxans;
    }
};