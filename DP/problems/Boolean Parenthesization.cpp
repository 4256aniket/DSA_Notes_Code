/*
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
*/


#include <bits/stdc++.h>
using namespace std;

int t[202][202][2];

class Solution {
public:

    int countWays(int N, string S) {
        int ans = solve(S, 0, N - 1, 1);
        return ans;
    }

private:
    int solve(string &s, int i, int j, int isTrue) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue == 1) return s[i] == 'T';
            else return s[i] == 'F';
        }

        if (t[i][j][isTrue] != -1) return t[i][j][isTrue];

        int ans = 0;

        for (int k = i + 1; k <= j - 1; k = k + 2) {

            int lt = (t[i][k - 1][1] != -1) ? t[i][k - 1][1] : t[i][k - 1][1] = solve(s, i, k - 1, 1);
            int lf = (t[i][k - 1][0] != -1) ? t[i][k - 1][0] : t[i][k - 1][0] = solve(s, i, k - 1, 0);

            int rt = (t[k + 1][j][1] != -1) ? t[k + 1][j][1] : t[k + 1][j][1] = solve(s, k + 1, j, 1);
            int rf = (t[k + 1][j][0] != -1) ? t[k + 1][j][0] : t[k + 1][j][0] = solve(s, k + 1, j, 0);

            if (s[k] == '&') {
                if (isTrue == 1) {
                    ans = ans + (lt * rt);
                } else {
                    ans = ans + (lt * rf) + (lf * rt) + (lf * rf);
                }
            } else if (s[k] == '|') {
                if (isTrue == 1) {
                    ans = ans + (lt * rf) + (lf * rt) + (lt * rt);
                } else {
                    ans = ans + (lf * rf);
                }
            } else if (s[k] == '^') {
                if (isTrue == 1) {
                    ans = ans + (lf * rt) + (rf * lt);
                } else {
                    ans = ans + (lt * rt) + (rf * lf);
                }
            }
        }
        return t[i][j][isTrue] = ans % 1003;
    }
};


int main() {


    int N;
    cin >> N;
    string S;
    cin >> S;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < 2; k++)
                t[i][j][k] = -1;
    Solution ob;
    cout << ob.countWays(N, S) << "\n";

    return 0;
}


// using map of string and int
class Solution {
public:
    unordered_map<string, long long> m;

    int countWays(int N, string S) {
        int ans = solve(S, 0, N - 1, true);
        return ans;
    }

private:
    int solve(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue == true) return s[i] == 'T';
            else return s[i] == 'F';
        }

        string temp = to_string(i);
        temp.push_back(' ');
        temp += (to_string(j));
        temp.push_back(' ');
        temp.append(to_string(isTrue));

        if (m.find(temp) != m.end()) return m[temp];

        int ans = 0;

        for (int k = i + 1; k <= j - 1; k = k + 2) {

            int lt = solve(s, i, k - 1, true);
            int lf = solve(s, i, k - 1, false);
            int rt = solve(s, k + 1, j, true);
            int rf = solve(s, k + 1, j, false);

            if (s[k] == '&') {
                if (isTrue == true) {
                    ans = ans + (lt * rt);
                } else {
                    ans = ans + (lt * rf) + (lf * rt) + (lf * rf);
                }
            } else if (s[k] == '|') {
                if (isTrue == true) {
                    ans = ans + (lt * rf) + (lf * rt) + (lt * rt);
                } else {
                    ans = ans + (lf * rf);
                }
            } else if (s[k] == '^') {
                if (isTrue == true) {
                    ans = ans + (lf * rt) + (rf * lt);
                } else {
                    ans = ans + (lt * rt) + (rf * lf);
                }
            }
        }
        return m[temp] = ans % 1003;
    }
};

