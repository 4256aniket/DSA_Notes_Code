#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fboard;
void dfs(vector<vector<int>>& board, int r, int c, int move, int& total_moves) {

    if(r >= n || c >= m || r < 0 || c < 0)return;

    if(move == total_moves){
        board[r][c] = move;
        fboard = board;
        return;
    }

    board[r][c] = move++;
    int vr[] = {1, 2, -1, -2};
    int vc[] = {2, 1, -2, -1};
    bool ans = false;
    for (auto dr : vr) {
        int nr = r + dr;
        for (auto dc : vc) {
            if (abs(dr) == abs(dc)) continue;
            ans |= dfs(board, r + dr, c + dc, move, total_moves);
        }
    }
    board[r][c] = -1;
    return ans;
}

vector<vector<int>> knightTour(int n, int m) {
    int total_moves = n * m - 1;
    vector<vector<int>> board(n, vector<int> (m, -1));
    dfs(board, 0, 0, 0, total_moves);
    return fboard.size() == board.size() ? fboard : board;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



}