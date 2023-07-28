/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/


class Solution {
public:
	string shortestCommonSupersequence(string str1, string str2) {

		string lcs = printLCS(str1, str2, str1.size(), str2.size());
		string temp = str1 + str2;
		string res = "";
		int i = 0, j = 0;
		for (char c : lcs) {
			while (str1[i] != c)
				res += str1[i++];
			while (str2[j] != c)
				res += str2[j++];
			res += c, i++, j++;
		}
		return res + str1.substr(i) + str2.substr(j);
	}

private:
	int t[1005][1005];
	string printLCS(string& text1, string& text2, int n, int m) {
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < m + 1; j++) {
				t[i][j] = -1;
				if (i == 0 || j == 0) t[i][j] = 0;
			}
		}

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (text1[i - 1] == text2[j - 1]) {
					t[i][j] = 1 + t[i - 1][j - 1];
				} else {
					t[i][j] = max(t[i][j - 1], t[i - 1][j]);
				}
			}
		}
		string res = "";
		int i = n, j = m;
		while (i > 0 && j > 0) {
			if (text1[i - 1] == text2[j - 1]) {
				res += text1[i - 1];
				i--;
				j--;
			} else {
				if (t[i - 1][j] > t[i][j - 1]) {
					i--;
				} else {
					j--;
				}
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};