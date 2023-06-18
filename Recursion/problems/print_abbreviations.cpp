#include <bits/stdc++.h>
using namespace std;

void printAbbreviations(string s, int ind, int n, int count, string& aof) {
	if (ind == n) {
		if (count > 0) aof += to_string(count);
		cout << aof << endl;
		return;
	}

	// take
	if (count > 0) {
		string st = aof;
		st += to_string(count);
		st += s[ind];
		printAbbreviations(s, ind + 1, n, 0, st);
	} else {
		string st = aof;
		st += s[ind];
		printAbbreviations(s, ind + 1, n, 0, st);

	}
	// not take
	printAbbreviations(s, ind + 1, n, count + 1, aof);

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	string s, aof;
	cin >> s;
	printAbbreviations(s, 0, n, 0, aof);

}