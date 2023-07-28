#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

class Solution {
public:

    int getMin(string& s) {
        stack<char> st;
        int i = 0, n = s.size();
        while (i < n) {
            if (s[i] == '(') {
                st.push('(');
            } else if (s[i] == ')') {
                if (st.size() > 0 && st.top() == '(') st.pop();
                else st.push(')');
            }
            i++;
        }
        return st.size();
    }

    void solve(string& s, int minChanges, set<string>& ans, set<string>& vis) {
        if (vis.count(s)) return;
        if (minChanges == 0) {
            if (getMin(s) == 0) {
                ans.insert(s);
            }
            return;
        }
        vis.insert(s);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(' && s[i] != ')') continue;
            string left = s.substr(0, i);
            string right = s.substr(i + 1);
            string new_s = left + right;
            solve(new_s, minChanges - 1, ans, vis);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        set<string> vis;
        int n = s.size();
        string asf = "";
        vector<string> res;
        int minChanges = getMin(s);
        cout << minChanges << endl;
        solve(s, minChanges, ans, vis);
        for (auto st : ans) res.push_back(st);
        return res;
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
    vector<string> ans = obj.removeInvalidParentheses(s);
    for (auto st : ans) cout << st << endl;

}