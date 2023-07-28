#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>


// Iterative preorder
vector<int> iterativePreorder(TreeNode* root) {
    vector<int> preorder;
    if (root == nullptr) return preorder;
    stack<TreeNode* > st;
    st.push(root);
    while (st.size() > 0) {
        TreeNode* node = st.top();
        st.pop();
        preorder.push_back(node->val);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return preorder;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::ios::sync_with_stdio(false);



}