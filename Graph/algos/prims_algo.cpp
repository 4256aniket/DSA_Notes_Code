#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;

vector<vector<ppi>> TakeInput(bool undirected = true) {
    int V, E;
    cin >> V >> E;
    vector<vector<ppi>> g(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v>> w;
        g[u].push_back({v, w});
        if (!undirected) continue;
        g[v].push_back({u,w});
    }

    return g;
}


int prims_mst(vector<vector<ppi>>& g){
    int n = g.size();
    vector<bool> vis(n, 0);
    int mst = 0;
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (vis[node]) continue;
        vis[node] = 1;
        mst += wt;

        for(auto adj : g[node]){
            int adjNode = adj.first;
            int edW = adj.second;
            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }

    }
    return mst;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<ppi>> g = TakeInput();
    int mst = prims_mst(g);
    cout << mst << endl;
    
}