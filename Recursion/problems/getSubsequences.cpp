#include <bits/stdc++.h>
using namespace std;

// take non take recursion
void helper(string s, int i, string& sof, vector<string>& ans) {
	if (i == s.size()) {
		ans.push_back(sof);
		return;
	}
	// take
	sof += s[i];
	helper(s, i + 1, sof, ans);
	sof.pop_back();
	helper(s, i + 1, sof, ans);
	// not take
}

vector<string> subsequences(string str) {

	vector<string> ans;
	string sof = "";
	helper(str, 0, sof, ans);
	sort(ans.begin(), ans.end());
	return ans;
}


// simple recusion with faith that recursion returns ans for substring

vector<string> subsequences(string str) {
	if (str.size() == 0) return {""};
	vector<string> small_ans = subsequences(str.substr(1));
	vector<string> ans;
	for (auto s : small_ans) {
		string ns;
		ns += str[0];
		ns += s;
		ans.push_back(ns);
	}
	for (auto s : small_ans) {
		ans.push_back(s);
	}
	return ans;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



}