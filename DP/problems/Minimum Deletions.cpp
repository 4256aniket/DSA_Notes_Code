/*
Given a string of S as input. Your task is to write a program to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

Example 1:

Input: S = "aebcbda"
Output: 2
Explanation: Remove characters 'e'
and 'd'.
Example 2:

Input: S = "geeksforgeeks"
Output: 8
Explanation: One of the possible result
string can be "eefee", so answer is
13 - 5 = 8.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minimumNumberOfDeletions() which takes the string S as inputs and returns the minimum number of deletions required to convert S into a pallindrome.

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(|S|2)

Constraints:
1 ≤ |S| ≤ 103
*/


class Solution {
public:
	int minimumNumberOfDeletions(string S) {
		// code here
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