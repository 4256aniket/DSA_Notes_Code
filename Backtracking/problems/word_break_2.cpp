#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

class Solution {
public:

    void solve(string& s, int idx, vector<string>& asf, vector<string>& ans, set<string>& dict) {
        if (idx == s.size()) {
            string op = "";
            for (int i = 0; i < asf.size(); i++) {
                op += asf[i];
                if(i < asf.size()-1)op += " ";
            }
            ans.push_back(op);
            return;
        }

        for (int i = 1; i <= s.size() - idx; i++) {
            string sm_s = s.substr(idx, i);
            if (dict.count(sm_s)) {
                asf.push_back(sm_s);
                solve(s, idx + i, asf, ans, dict);
                asf.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> ans;
        vector<string> asf;
        solve(s, 0, asf, ans, dict);
        return ans;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::ios::sync_with_stdio(false);



}