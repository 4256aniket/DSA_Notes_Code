#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

class Solution {
public:

    vector<int> solve(string s) {
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> ans1 = solve(s.substr(0, i));
                vector<int> ans2 = solve(s.substr(i + 1));

                for (int k = 0; k < ans1.size(); k++) {
                    for (int j = 0; j < ans2.size(); j++) {
                        if (s[i] == '+') ans.push_back(ans1[k] + ans2[j]);
                        else if (s[i] == '*') ans.push_back(ans1[k] * ans2[j]);
                        else ans.push_back(ans1[k] - ans2[j]);
                    }
                }
            }
        }
        if (ans.size() == 0) ans.push_back(stoi(s)); //Base case (No operator) only one operand
        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
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
    vector<int> ans = obj.diffWaysToCompute(s);
    for (auto i : ans) cout << i << " ";

}