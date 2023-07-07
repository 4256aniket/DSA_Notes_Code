// https://www.interviewbit.com/problems/min-cost-path/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

struct Point {
public:
    int x;
    int y;
    int cost;
};


struct comp {
    bool operator()(Point const &p1, Point const & p2) {
        return p1.cost > p2.cost;
    }
};


int Solution::solve(int row, int col, vector<string>&mat) {

    string s = "URDL";
    vector<vector<int>> dist(row, vector<int>(col, INT_MAX - 1));
    priority_queue<Point, vector<Point>, comp> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;
    int v[] = { -1, 0, 1, 0, -1};

    while (!pq.empty()) {
        Point curr = pq.top();
        pq.pop();
        if (curr.x == row - 1 && curr.y == col - 1) return dist[row - 1][col - 1];
        for (int i = 0; i < 4; i++) {
            int newx = curr.x + v[i];
            int newy = curr.y + v[i + 1];

            int cost = dist[curr.x][curr.y];
            if (s[i] != mat[curr.x][curr.y]) cost++;
            if (newy >= 0 && newx >= 0 && newx < row && newy < col && cost < dist[newx][newy]) {
                pq.push({newx, newy, cost});
                dist[newx][newy] = cost;
            }
        }
    }
    return dist[row - 1][col - 1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    vector<string> mat(a);
    for (int i = 0; i < a; i++) cin >> mat[i];

    cout << solve(a, b, mat) << endl;

}






















