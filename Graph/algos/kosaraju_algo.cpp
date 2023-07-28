// to find strongly connected components

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

vector<int> adj[1001];
vector<int> tr[1001];
int vis[1001];
vector<int> order;
vector<int> SCC;

void dfs(int node) {
	vis[node] = 1;
	for (int child : adj[node]) {
		if (vis[child] == 0) {
			dfs(child);
		}
	}
	order.push_back(node);
}

void dfs1(int node) {
	vis[node] = 1;
	for (int child : tr[node]) {
		if (vis[child] == 0) {
			dfs1(child);
		}
	}
	SCC.push_back(node);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);

	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) adj[i].clear(), tr[i].clear(), vis[i] = 0;
		order.clear();
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			tr[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0) dfs(i);
		}

		for (int i = 1; i <= n; i++) vis[i] = 0;

		for (int i = 1; i <= n; i++) {
			if (vis[order[n - i]] == 0) {
				SCC.clear();
				dfs1(order[n - i]);

				// cout << "dfs1() called from " << order[n - i] << " and printing SCC" << endl;
				for (int node : SCC) {
					cout << node << " ";
				}
				cout << endl;
			}
		}
	}

}
















