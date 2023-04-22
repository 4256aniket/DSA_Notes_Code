#include<bits/stdc++.h>
using namespace std;

void fillLps(string pat, vector<int>& lps) {
	int n = pat.size(), len = 0;
	int i = 1;
	while (i < n) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len == 0) {
				lps[i] = 0;
				i++;
			} else {
				len = lps[len - 1];
			}
		}
	}
}
void kmp(string txt, string pat) {
	int n = txt.size(), m = pat.size();
	vector<int> lps(m, 0);
	fillLps(pat, lps);
	int i = 0, j = 0;
	while (i < n) {
		if (pat[j] == txt[i]) {
			i++;
			j++;
		}
		if (j == m) {
			cout << (i - j) << endl;
			j = lps[j - 1];
		} else if (i < n && pat[j] != txt[i]) {
			if (j == 0)i++;
			else j = lps[j - 1];
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	string pattern, text;
	cin >> text >> pattern;
	kmp(text, pattern);

}