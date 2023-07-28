#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> ans(n);
    stack<int> st;
    ans[n - 1] = -1;
    for (int i = n - 1; i >= 0; i--) {
        while (st.size() > 0 && st.top() >= arr[i])st.pop();
        if (st.size() == 0) ans[i] = -1;
        else ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vi ans = nextSmallerElement(v, n);
    for (auto i : ans) cout << i << " ";

}