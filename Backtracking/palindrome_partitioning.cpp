#include <bits/stdc++.h>
using namespace std;

// get a palindromic prefix and call recursion

bool isPalindrome(string s) {
	int i = 0, j = s.size() - 1;
	while (i < j) {
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

void palindromicPartitioning(string& s, vector<string>& ans, vector<vector<string>>& res) {
	if (s.size() == 0) {
		res.push_back(ans);
		return;
	}

	for (int i = 0; i < s.size(); i++) {
		string prefix = s.substr(0, i + 1);
		string ros = s.substr(i + 1);
		if (isPalindrome(prefix)) {
			ans.push_back(prefix);
			palindromicPartitioning(ros, ans, res);
			ans.pop_back();
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	vector<string> ans;
	vector<vector<string>> res;
	palindromicPartitioning(s, ans, res);
	for (auto st : res) {
		for (auto i : st) cout << i << " ";
		cout << endl;
	}
}