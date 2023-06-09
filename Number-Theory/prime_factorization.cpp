#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	for (int div = 2; div * div <= n; div++) {
		while (n % div == 0) {
			n = n / div;
			cout << div << endl;
		}
	}

	if (n != 1) {
		cout << n << endl;
	}
}