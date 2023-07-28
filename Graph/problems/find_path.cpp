// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<int>>& g, vector<bool>& vis, int s, int d) {
        vis[s] = true;
        if (s == d) return true; // is source == destination => path exists
        bool is_path = false;
        // if there exist a path from adj to destination
        // then there is path from source to destination
        for (auto adj : g[s]) {
            is_path |= dfs(g, vis, adj, d);
        }
        return is_path;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n); //building graph from edges
        for (auto edg : edges) {
            g[edg[0]].push_back(edg[1]);
            g[edg[1]].push_back(edg[0]);
        }

        vector<bool> vis(n, false);
        return dfs(g, vis, source, destination);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



}