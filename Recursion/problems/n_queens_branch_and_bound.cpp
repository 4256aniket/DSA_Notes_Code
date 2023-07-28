#include <bits/stdc++.h>
using namespace std;

int N = 8;
vector<vector<int>> board;
vector<int> d1;
vector<int> d2;
vector<int> col;

void printBoard() {
	for (auto r : board) {
		for (auto e : r) {
			cout << e << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < board.size(); i++) cout << "***";
	cout << endl;
}

int solve(int n, int r) {
	if (r == n) {
		printBoard();
		return 1;
	}
	int ans = 0;
	for (int c = 0; c < n; c++) {
		if (!col[c] && !d1[r + c] && !d2[r - c + n - 1]) {
			board[r][c] = 1;
			col[c] = 1;
			d1[r + c] = 1;
			d2[r - c + n - 1] = 1;
			ans += solve(n, r + 1);

			board[r][c] = 0;
			col[c] = 0;
			d1[r + c] = 0;
			d2[r - c + n - 1] = 0;
		}
	}
	return ans;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;
	col.resize(n, 0);
	d1.resize(2 * n - 1, 0);
	d2.resize(2 * n - 1, 0);
	board.resize(n, vector<int>(n, 0));

	cout << solve(n, 0) << endl;
}