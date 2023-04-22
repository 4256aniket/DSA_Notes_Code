/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.



Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".


Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/



class Solution {
public:
	int longestPalindromeSubseq(string s) {
		string x = s;
		reverse(x.begin(), x.end());
		return LCS(x, s, s.size(), s.size());
	}

private:
	int LCS(string x, string y, int n, int m) {
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