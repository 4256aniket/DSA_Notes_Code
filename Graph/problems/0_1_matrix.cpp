// https://leetcode.com/problems/01-matrix/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ppi;
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size();
		queue<ppi> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1) mat[i][j] = -1;
				else q.push({i, j});
			}
		}

		while (q.size() > 0) {
			int r = q.front().first;
			int c = q.front().second;
			int d = mat[r][c];
			p.pop();
			int v[] = { -1, 0, 1, 0, -1};
			for (int i = 0; i < 4; i++) {
				int nr = r + v[i];
				int nc = c + v[i + 1];

				if (nr < 0 || nc < 0 || nr > n || nc > m) continue;

				mat[nr][nc] = 1 + d;
				q.push({nr, nc});
			}
		}
		return mat;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



}