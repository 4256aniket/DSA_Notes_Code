#include <bits/stdc++.h>
using namespace std;


int v[] = { -1, 0, 1, 0, -1};
void solve(vector<vector<char>> &board, int ind, string word, int r, int c, int n, int m, vector<vector<bool>> &vis, bool& ans) {
    if (ind == word.size() - 1) {
        board[r][c] = word[ind];
        ans = true;
        return;
    }
    if (ans) return;

    vis[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + v[i];
        int nc = c + v[i + 1];

        if (nr < 0 || nc < 0 || nr >= n || nc >= m)continue;
        if (!vis[nr][nc] && ind < word.size() - 1 && board[nr][nc] == word[ind + 1])
            solve(board, ind + 1, word, nr, nc, n, m, vis, ans);
    }


    vis[r][c] = false;
}

bool present(vector<vector<char>> &board, string word, int n, int m)
{
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0] && !vis[i][j]) {
                bool ans = false;
                solve(board, 0, word, i, j, n, m, vis, ans);
                if (ans) return true;
            }
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    string word;
    cin >> n >> m >> word;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }

    cout << present(board, word, n, m) << endl;
}