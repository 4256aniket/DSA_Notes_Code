#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	int solve(vector<string>& words, vector<int>& freq, vector<int>& score, int ind, int n) {

		if (ind == n) {
			return 0;
		}

		int wordNotTaken = solve(words, freq, score, ind + 1, n);
		int sword = 0;
		bool flag = true; // if include call can be made

		for (int i = 0; i < words[ind].size(); i++) {
			int ch = words[ind][i];
			if (freq[ch - 'a'] == 0) {
				flag = false;
			}
			freq[ch - 'a']--;
			sword += score[ch - 'a'];
		}

		int wordTaken = 0;
		if (flag) {
			wordTaken = sword + solve(words, freq, score, ind + 1, n);
		}

		for (int i = 0; i < words[ind].size(); i++) {
			int ch = words[ind][i];
			freq[ch - 'a']++;
		}

		return max(wordTaken, wordNotTaken);
	}

	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
		vector<int> freq(26, 0);
		int n = words.size();
		for (auto ch : letters) {
			freq[ch - 'a']++;
		}

		return solve(words, freq, score, 0, n);
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



}