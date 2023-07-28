// https://leetcode.com/problems/lexicographical-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// 1 10 100 ... 109 11 110 111.....

class Solution {
public:

	void dfs(int i, int n, vector<int>& ans) {
		if (i > n) return;
		ans.push_back(i);
		for (int j = 0; j < 10; j++) {
			dfs(10 * i + j, n, ans);
		}
	}

	vector<int> lexicalOrder(int n) {
		vector<int> ans;
		for (int i = 1; i <= 9; i++) {
			dfs(i, n, ans);
		}
		return ans;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	Solution obj;
	vector<int> ans =  obj.lexicalOrder(n);

	for (auto i : ans) cout << i << endl;

}