// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return {};
		vector<string> ans;
		string sof = "";
		helper(digits, 0, sof, ans);
		return ans;
	}

private:
	vector<string> s = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	void helper(string digits, int i, string& sof, vector<string>& ans) {
		if (i == digits.size()) {
			ans.push_back(sof);
			return;
		}

		int d = digits[i] - '0';
		for (auto ch : s[d]) {
			sof += ch;
			helper(digits, i + 1, sof, ans);
			sof.pop_back();
		}
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Solution obj;
	string s;
	cin >> s;
	vector<string> ans = obj.letterCombinations(s);
	for (auto x : ans) cout << x << endl;

}