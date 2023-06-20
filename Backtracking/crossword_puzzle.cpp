#include <bits/stdc++.h>
using namespace std;

bool canPlaceHor(vector<string>& crossword, string& word, int r, int c) {
	if (c - 1 >= 0 && crossword[r][c - 1] != '+') return false;
	else if (c + word.size() < 10 && crossword[r][c + word.size()] != '+') return false;

	for (int j = 0; j < word.size(); j++) {
		if (j + c >= 10) return false;
		if (crossword[r][j + c] == '-' || crossword[r][j + c] == word[j]) {
			continue;
		} else {
			return false;
		}
	}
	return true;
}
bool canPlaceVer(vector<string>& crossword, string& word, int r, int c) {
	if (r - 1 >= 0 && crossword[r - 1][c] != '+') return false;
	else if (r + word.size() < 10 && crossword[r + word.size()][c] != '+') return false;

	for (int j = 0; j < word.size(); j++) {
		if (j + r >= 10) return false;
		if (crossword[r + j][c] == '-' || crossword[r + j][c] == word[j]) {
			continue;
		} else {
			return false;
		}
	}
	return true;
}

vector<bool> placeWordHor(vector<string>& crossword, string& word, int r, int c) {
	vector<bool> wePlaced(word.size(), false);
	for (int j = 0; j < word.size(); j++) {
		if (crossword[r][c + j] == '-') {
			crossword[r][c + j] = word[j];
			wePlaced[j] = true;
		}
	}
	return wePlaced;
}

vector<bool> placeWordVer(vector<string>& crossword, string& word, int r, int c) {
	vector<bool> wePlaced(word.size(), false);
	for (int j = 0; j < word.size(); j++) {
		if (crossword[r + j][c] == '-') {
			crossword[r + j][c] = word[j];
			wePlaced[j] = true;
		}
	}
	return wePlaced;
}

void unplaceWordHor(vector<string>& crossword, vector<bool>& wePlaced, int r, int c) {
	for (int j = 0; j < wePlaced.size(); j++) {
		if (wePlaced[j] == true) {
			crossword[r][c + j] = '-';
		}
	}
}

void unplaceWordVer(vector<string>& crossword, vector<bool>& wePlaced, int r, int c) {
	for (int j = 0; j < wePlaced.size(); j++) {
		if (wePlaced[j] == true) {
			crossword[r + j][c] = '-';
		}
	}
}

void print(vector<string>& crossword) {
	for (auto st : crossword) {
		cout << st << endl;
	}
}

void solve(vector<string>& crossword, vector<string> words, int ind) {
	if (ind == words.size()) {
		print(crossword);
		return;
	}
	string word = words[ind];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (crossword[i][j] == '-' || crossword[i][j] == word[0]) {
				if (canPlaceHor(crossword, word, i, j)) {
					vector<bool> wePlaced = placeWordHor(crossword, word, i, j);
					solve(crossword, words, ind + 1);
					unplaceWordHor(crossword, wePlaced, i, j);
				}

				if (canPlaceVer(crossword, word, i, j)) {
					vector<bool> wePlaced = placeWordVer(crossword, word, i, j);
					solve(crossword, words, ind + 1);
					unplaceWordVer(crossword, wePlaced, i, j);
				}
			}
		}
	}

}

vector<string> crosswordPuzzle(vector<string>& crossword, string words) {
	vector<string> w;
	string cw = "";
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == ';') {
			w.push_back(cw);
			cw = "";
			i++;
		}
		cw += words[i];
	}
	w.push_back(cw);
	solve(crossword, w, 0);
	return crossword;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<string> crossword(10);
	for (int i = 0; i < 10; i++) cin >> crossword[i];
	string words;
	cin >> words;

	vector<string> ans = crosswordPuzzle(crossword, words);
}