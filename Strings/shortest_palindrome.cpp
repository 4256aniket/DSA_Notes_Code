#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

// kmp 
// we have to find length of longest palindrome starting at index 0
// it can be done by finding lps of (s + "$" + (reverse(s)))

class Solution {
public:

    vector<int> getLps(string& st) {
        int n = st.size();
        vector<int> lps(n);
        int i = 1, len = 0;
        while (i < n) {
            if (st[i] == st[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    len = lps[len - 1];
                }
            }
        }
        return lps;
    }

    string shortestPalindrome(string s) {
        string r = s;
        int n = s.size();
        reverse(s.begin(), s.end());
        string st = r + "$" + s;
        vector<int>lps = getLps(st);
        int x = lps[lps.size() - 1];
        string add = s.substr(0, n - x);
        return add + r;

    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::ios::sync_with_stdio(false);

    string s;
    cin >> s;
    Solution obj;
    cout << obj.shortestPalindrome(s) << endl;

}







