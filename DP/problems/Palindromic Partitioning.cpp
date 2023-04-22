/*
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as the input parameter and returns the minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ length of str ≤ 500
*/


class Solution {
public:
	int palindromicPartition(string str)
	{
		// code here
		int n = str.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				t[i][j] = -1;
			}
		}
		return solve(str, 0, n - 1);
	}

private:
	int t[505][505];
	int solve(string &s, int i, int j) {
		if (i >= j)return 0;
		if (isPalindrome(s, i, j)) return 0;
		if (t[i][j] != -1) return t[i][j];
		int mn = INT_MAX;
		for (int k = i; k < j; k++) {
			int left = 0, right = 0;
			if (t[i][k] != -1) left = t[i][k];
			else left = t[i][k] = solve(s, i, k);

			if (t[k + 1][j] != -1) right = t[k + 1][j];
			else right = t[k + 1][j] = solve(s, k + 1, j);

			int temp = left + right + 1;
			if (temp < mn) mn = temp;
		}
		return t[i][j] = mn;
	}

	bool isPalindrome(string s, int i, int j) {
		while (i < j) {
			if (s[i++] != s[j--]) return false;
		}
		return true;
	}
};