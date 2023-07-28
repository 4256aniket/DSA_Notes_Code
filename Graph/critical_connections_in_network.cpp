#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

class Solution {
public:

    void dfs(vector<int> adj[], int node, int parent, int& timer, vector<int>& vis, vector<int>& in, vector<int>& low, vector<vector<int>>& ans) {
        vis[node] = 1;
        in[node] = low[node] = timer;
        timer++;

        for (int child : adj[node]) {
            if (child == parent) continue;

            if (vis[child] == 1) {
                // already visited -> back edge
                low[node] = min(low[node], in[child]);
            } else {
                dfs(adj, child, node, timer, vis, in, low, ans);
                if (low[child] > in[node]) {
                    ans.push_back({child, node});
                }
                low[node] = min(low[node], low[child]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            int x = connections[i][0], y = connections[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<vector<int>> ans;
        vector<int> vis(n, 0);
        vector<int> in(n, 0);
        vector<int> low(n, 0);
        int timer = 0;
        dfs(adj, 0, -1, timer, vis, in, low, ans);
        return ans;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::ios::sync_with_stdio(false);



}