#include <bits/stdc++.h>
using namespace std;

// Given string is always a possible palindrome
// get all permutations for half of string and add its reverse into it -> resulting string is palindrome
// if some char freq is odd, then stuff it in middle of half permutation and its reverse

void permutations(string& s, int ind, int n, vector<string>& perm) {
	if (ind == n) {
		perm.push_back(s);
		return;
	}
	unordered_set<char> st;
	for (int i = ind; i < n; i++) {
		if (st.count(s[i])) continue;
		st.insert(s[i]);
		swap(s[ind], s[i]);
		permutations(s, ind + 1, n, perm);
		swap(s[ind], s[i]);
	}
}

void palindromicPermutations(string& s) {
	vector<int> freq(26, 0);
	for (auto ch : s) {
		freq[ch - 'a']++;
	}
	char middle = '0';
	string half = "";
	for (int i = 0; i < 26; i++) {
		char ch = ('a' + i);
		int n = freq[i] / 2;
		freq[i] -= 2 * n;
		if (freq[i]) middle = ch;
		while (n--) {
			half += ch;
		}
	}
	sort(half.begin(), half.end());
	vector<string> perm;
	int n = half.size();
	permutations(half, 0, n, perm);

	for (auto &h : perm) {
		string pp = "";
		pp += h;
		if (middle != '0') pp += middle;
		reverse(h.begin(), h.end());
		pp += h;
		cout << pp << endl;
	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	palindromicPermutations(s);

}