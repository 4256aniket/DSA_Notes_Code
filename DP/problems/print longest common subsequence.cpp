// Print Longest Common Subsequence of two strings

string printLCS(string& text1, string& text2, int n, int m) {
	int n = text1.size();
	int m = text2.size();
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1; j++) {
			t[i][j] = -1;
			if (i == 0 || j == 0) t[i][j] = 0;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (text1[i - 1] == text2[j - 1]) {
				t[i][j] = 1 + t[i - 1][j - 1];
			} else {
				t[i][j] = max(t[i][j - 1], t[i - 1][j]);
			}
		}
	}
	string res = "";
	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (text1[i - 1] == text2[j - 1]) {
			res += text1[i - 1];
			i--;
			j--;
		} else {
			if (t[i - 1][j] > t[i][j - 1]) {
				i--;
			} else {
				j--;
			}
		}
	}
	reverse(res.begin(), res.end());
	return res;
}