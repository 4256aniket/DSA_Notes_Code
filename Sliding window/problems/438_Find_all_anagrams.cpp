/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        vector<int>ans;
        unordered_map<int, int> m;
        for (int i = 0; i < k; ++i)
        {
            m[p[i]]++; 
        }
        int i = 0, j = 0, count = m.size();
        while (j < s.size()) {

            if (m.find(s[j]) != m.end()) {
                m[s[j]]--;
                if (m[s[j]] == 0)count--;
            }
            if (j - i + 1 < k)j++;
            else if (j - i + 1 == k) {

                if (count == 0)
                    ans.push_back(i);

                if (m.find(s[i]) != m.end()) {
                    m[s[i]]++;
                    if (m[s[i]] == 1)count++;
                }
                i++;
                j++; 
            }
        }
        return ans;
    }
};

int main() {
    string s, p;
    cin >> s >> p;
    vector<int> ans;
    Solution ob;
    ans = ob.findAnagrams(s, p);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
}