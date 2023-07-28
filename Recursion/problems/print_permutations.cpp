#include <bits/stdc++.h>
using namespace std;
// ------------------------------------------------------------------------
// void helper(string input, string& sof) {
// 	if (input.size() == 0) {
// 		cout << sof << endl;
// 		return;
// 	}

// 	for (int i = 0; i < input.size(); i++) {
// 		string l = input.substr(0, i);
// 		string r = input.substr(i + 1);
// 		sof += input[i];
// 		string nw_input = l + r;
// 		helper(nw_input, sof);
// 		sof.pop_back();
// 	}
// }

// void printPermutations(string input) {
// 	string sof = "";
// 	helper(input, sof);
// }

// ------------------------------------------------------------------------


void helper(string input, int index) {
	if (index == input.size()) {
		cout << input << endl;
		return;
	}

	for (int i = index; i < input.size(); i++) {
		swap(input[index], input[i]);
		helper(input, index + 1);
		swap(input[index], input[i]);
	}
}

void printPermutations(string input) {
	helper(input, 0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	printPermutations(s);

}