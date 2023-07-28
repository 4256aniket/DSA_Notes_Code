#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

vector<int> adj[100];
int in[101], low[101], vis[101];
int timer;

void dfs(int node, int parent) {
	vis[node] = 1;
	in[node] = low[node] = timer;
	timer++;

	for (int child : adj[node]) {
		if (child == parent) continue;
		if (vis[child] == 1) {
			// node-child is a back edge
			low[node] = min(low[node], in[child]);
		} else {
			// forward edge
			dfs(child, node);
			if (low[child] > in[node]) {
				cout << node << " - " << child << " is a bridge" << endl;
			}

			low[node] = min(low[node], low[child]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);

	int n, m, x, y;
	cin >> n >> m;
	while (m--) {
		cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);

		dfs(1, -1);
	}

}