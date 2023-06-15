// https://leetcode.com/problems/coloring-a-border/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	void dfs(vector<vector<int>>& grid, int r, int c) {
		int n = grid.size(), m = grid[0].size();
		grid[r][c] *= (-1);
		int count = 0;
		int v[] = { -1, 0, 1, 0, -1};
		for (int i = 0; i < 4; i++) {
			int nr = r + v[i];
			int nc = c + v[i + 1];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

			if (abs(grid[nr][nc]) == abs(grid[r][c]))count++;
			if (grid[nr][nc] > 0) {
				dfs(grid, nr, nc);
			}
		}

		if (count == 4) {
			grid[r][c] *= (-1);
		}
	}

	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
		dfs(grid, row, col);
		for (auto & r : grid) {
			for (auto & e : r) {
				if (e < 0) e = color;
			}
		}
		return grid;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



}