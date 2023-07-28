// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// add island to set<string>
	// x -> starting node of island
	// d -> moving down
	// r -> mowing right
	// z -> backtracking
	void dfs(vector<vector<int>>& grid, int r, int c, string& psf) {
		int n = grid.size(), m = grid[0].size();
		grid[r][c] = 0;
		if (r - 1 >= 0 && grid[r - 1][c] == 1) {
			psf += 'u';
			dfs(grid, r - 1, c, psf);
		}

		if (r + 1 < n && grid[r + 1][c] == 1) {
			psf += 'd';
			dfs(grid, r + 1, c, psf);
		}
		if (c - 1 >= 0 && grid[r][c - 1] == 1) {
			psf += 'l';
			dfs(grid, r, c - 1, psf);
		}
		if (c + 1 < m && grid[r][c + 1] == 1) {
			psf += 'r';
			dfs(grid, r , c + 1, psf);
		}

		psf += 'z';
	}

	int countDistinctIslands(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		set<string> st;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					string psf = "x";
					dfs(grid, i, j, psf);
					st.insert(psf);
				}
			}
		}
		return st.size();
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



}