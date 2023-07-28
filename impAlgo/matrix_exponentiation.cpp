#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

vector<vector<int>> multiplySqMatrices(vector<vector<int>>&A, vector<vector<int>>&B) {
	int n = A.size();
	vector<vector<int>> res(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; ++k) {
				res[i][j] += (A[i][k] * B[k][j]);
			}
		}
	}
	return res;
}

vector<vector<int>> matrixExponentiation(vector<vector<int>>&A, int x) {
	if (x == 1) return A;
	vector<vector<int>> resBy2 = matrixExponentiation(A, x / 2);
	vector<vector<int>> result = multiplySqMatrices(resBy2, resBy2);

	if (x & 1) {
		return multiplySqMatrices(A, result);
	}
	return result;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	vector<vector<int>> m(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> m[i][j];
	}

	vector<vector<int>> ans = matrixExponentiation(m, x);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	int res = ans[0][0] * 3 + ans[0][1] * 2;
	cout << "--------" << endl;
	cout << res << endl;

}