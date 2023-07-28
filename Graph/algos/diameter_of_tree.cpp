#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

vector<int> graph[10001];
int vis[10001];

// to find diameter of a tree, find the farthest node from root node (any node) say this node comes out to be x
// find distance of fartherst node from x as root, this distance will be diameter of the tree

int maxD, maxNode;

void dfs(int node, int d) {
	vis[node] = 1;
	if (d > maxD){
		maxD = d;
		maxNode = node;
	}
	for (int child : graph[node]) {
		if (vis[child] == 0) {
			dfs(child, d + 1);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);

	int n, x, y;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	maxD = -1;
	dfs(1, 0);
	for(int i = 0; i <= n; i++) vis[i] = 0;
	maxD = -1;
	dfs(maxNode, 0);
	cout << maxD << endl;

}