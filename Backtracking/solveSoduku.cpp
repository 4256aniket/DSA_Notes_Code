#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

const int N = 9;

class Solution
{
public:
    bool solve(int board[N][N]) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == 0) {
                    for (int c = 1; c <= 9; c++) {
                        if (valid(c, board, i, j)) {
                            board[i][j] = c;
                            if (solve(board) == true) return true;
                            else board[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool valid(int c, int board[N][N], int row, int col) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false;
            if (board[row][i] == c) return false;
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c) return false;
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])
    {
        return solve(grid);
    }

    void printGrid (int grid[N][N])
    {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::ios::sync_with_stdio(false);

    int grid[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    bool ans = obj.SolveSudoku(grid);
    obj.printGrid(grid);

}












