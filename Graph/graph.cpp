#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> takeInput(bool isdirected) {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        if (!isdirected) adj[v].push_back(u);
    }
    return adj;
}

void printgraph(vector<vector<int>> & adj) {
    for (int i = 0; i < adj.size(); i++)
    {
        cout << i << " : ";
        for (auto e : adj[i])
        {
            cout << e << " ";
        }
        cout << endl;
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> adj = takeInput(0);
    printgraph(adj);
}
