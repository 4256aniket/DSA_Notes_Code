//https://leetcode.com/problems/next-greater-element-ii/submissions/984344357/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    for (int i = n - 2; i >= 0; i--) {
        while (st.size() > 0 && st.top() <= nums[i]) st.pop();
        st.push(nums[i]);
    }
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        while (st.size() > 0 && st.top() <= nums[i]) st.pop();
        if (st.size() == 0) ans[i] = -1;
        else ans[i] = st.top();
        st.push(nums[i]);
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
    vi ans = nextGreaterElements(v);
    for (auto i : ans) cout << i << " ";

}