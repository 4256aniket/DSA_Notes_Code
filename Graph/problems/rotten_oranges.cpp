// https://leetcode.com/problems/rotting-oranges/submissions/971896564/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ppi;
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		queue<ppi> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 2) {
					q.push({i, j});
				}
			}
		}
		int v[] = { -1, 0, 1, 0, -1};
		int time = 0;
		while (q.size() > 0) {
			int size = q.size();
			time++;
			for (int i = 0; i < size; i++) {
				int r = q.front().first;
				int c = q.front().second;
				q.pop();
				for (int j = 0; j < 4; j++) {
					int nr = r + v[j];
					int nc = c + v[j + 1];

					if (nr < 0 || nc < 0 || nc >= m || nr >= n) continue;

					if (grid[nr][nc] == 1) {
						grid[nr][nc] = 2;
						q.push({nr, nc});
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					return -1;
				}
			}
		}
		return (time - 1 > 0) ? time - 1 : 0;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



}