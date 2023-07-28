/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
*/


class Solution {
public:
	int minInsertions(string S) {
		string x = S;
		reverse(x.begin(), x.end());
		int lps = LPS(S, x, S.size(), S.size());
		return S.size() - lps;
	}
private:
	int LPS(string x, string y, int n, int m) {
		int t[1005][1005];
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < m + 1; j++) {
				t[i][j] = -1;
				if (i == 0 || j == 0) t[i][j] = 0;
			}
		}

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (x[i - 1] == y[j - 1]) {
					t[i][j] = 1 + t[i - 1][j - 1];
				} else {
					t[i][j] = max(t[i - 1][j], t[i][j - 1]);
				}
			}
		}
		return t[n][m];
	}
};