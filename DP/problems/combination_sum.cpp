// https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(vector<int>& candidates, int ind, int target, int n, vector<int>& aof, vector<vector<int>>& ans) {
        if (ind == n) {
            if (target == 0) {
                ans.push_back(aof);
            }
            return;
        }

        // take
        if (candidates[ind] <= target) {
            aof.push_back(candidates[ind]);
            helper(candidates, ind , target - candidates[ind], n, aof, ans);
            aof.pop_back();
        }
        helper(candidates, ind + 1, target, n , aof, ans);
        // not take
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> aof;
        int n = candidates.size();
        helper(candidates, 0, target, n, aof, ans);
        return ans;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    Solution obj;
    vector<vector<int>> ans =  obj.combinationSum(v, k);

    for (auto r : ans) {
        for (auto e : r) cout << e << " ";
        cout << endl;
    }


}