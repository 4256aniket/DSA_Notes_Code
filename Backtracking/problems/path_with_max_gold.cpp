#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	int v[5] = { -1, 0, 1, 0, -1};

	int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& vis, int n, int m) {
		// if (r >= n || c >= m || r < 0 || c < 0) return;
		vis[r][c] = 1;
		int mx = grid[r][c];
		for (int i = 0; i < 4; i++) {
			int nr = r + v[i];
			int nc = c + v[i + 1];
			if (nr >= n || nc >= m || nr < 0 || nc < 0)continue;
			if (!vis[nr][nc] && grid[nr][nc] != 0) {
				int ans = grid[r][c] + dfs(grid, nr, nc, vis, n, m);
				mx = max(mx, ans);
			}
		}
		vis[r][c] = 0;
		return mx;
	}

	int getMaximumGold(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<bool>> vis(n, vector<bool>(m, 0));
		int maxGold = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (!vis[i][j] && grid[i][j] != 0) {
					int gold = dfs(grid, i, j, vis, n, m);
					maxGold = max(maxGold, gold);
				}
			}
		}
		return maxGold;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



}