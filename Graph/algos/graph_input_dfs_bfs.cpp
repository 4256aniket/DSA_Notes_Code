#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    vector<TreeNode*> children;
    TreeNode(int nodeVal)
    {
        this->val = nodeVal;
    }
};

void printTree(TreeNode *root)
{
    cout << root->val << " : ";
    for (auto child : root->children) {
        cout << child->val << " ";
    }
    cout << endl;
    for (auto child : root->children) {
        printTree(child);
    }
}

TreeNode* buildTree(vector<vector<int>> &g, TreeNode *node, int parent)
{
    for (auto childId : g[node->val])
    {
        if (childId == parent) continue;
        TreeNode *child = new TreeNode(childId);
        node->children.push_back(child);
        buildTree(g, child, node->val);
    }
    return node;
}

TreeNode* rootTree(vector<vector<int>> &g, int rootId = 0)
{
    TreeNode *root = new TreeNode(rootId);
    return buildTree(g, root, -1);
}

void dfs(vector<vector<int>> &g, int s, vector<bool> &vis)
{
    vis[s] = true;
    cout << s << " ";
    for (auto adj : g[s])
    {
        if (!vis[adj])
            dfs(g, adj, vis);
    }
}

void bfs(vector<vector<int>> &g, int s, vector<bool> &vis)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto adj : g[node])
        {
            if (!vis[adj])
            {
                q.push(adj);
                vis[adj] = true;
            }
        }
    }
}

vector<vector<int>> TakeInput(bool undirected = true)
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> g(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        if (!undirected)
            continue;
        g[v].push_back(u);
    }

    return g;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> g = TakeInput();
    vector<bool> vis(g.size(), false);
    // for (int i = 0; i < g.size(); i++)
    // {
    //     if (!vis[i])
    //     {
    //         bfs(g, i, vis);
    //     }
    // }
    TreeNode *root = new TreeNode(0);
    root = rootTree(g);
    printTree(root);
}