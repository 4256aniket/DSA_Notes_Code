#include <bits/stdc++.h>
using namespace std;

/*
implementation of segment trees (array) --> minimum in range
let parent index = i,
	--> left child index = 2*i
	--> right child index = 2*i + 1

	ss -> segment start index
	se -> segment end index
	si -> segment index (parent) or root index
	st -> segment tree
*/

int st[400004];
int arr[100001];

void buildTree(int si, int ss, int se) {
	if (ss == se) {
		// leaf node
		st[si] = arr[ss];
		return;
	}

	int mid = (ss + se) / 2;

	buildTree(2 * si, ss, mid);
	buildTree(2 * si + 1, mid + 1, se);

	st[si] = min(st[2 * si], st[2 * si + 1]);
}

int query(int si, int ss, int se, int qs, int qe) {
	if (qs > se || qe < ss) {    //completely outside
		return INT_MAX;
	}

	if (ss >= qs && se <= qe) {  // completely inside
		return st[si];
	}

	int mid = (ss + se) / 2;
	int l = query(2 * si, ss, mid, qs, qe);
	int r = query(2 * si + 1, mid + 1, se, qs, qe);

	return min(l, r);
}

// point update

void update(int si, int ss, int se, int qi) {
	if (ss == se) {
		st[si] = arr[ss];
		return;
	}

	int mid = (ss + se) / 2;
	if (qi <= mid) update(2 * si, ss, mid, qi);
	else update(2 * si + 1, mid + 1, se, qi);

	st[si] = min(st[2 * si], st[2 * si + 1]);
}



int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	buildTree(1, 1, n);
	cin >> q;
	while (q--) {
		int qs, qe;
		cin >> qs >> qe;
		cout << query(1, 1, n, qs + 1, qe + 1) << endl;
	}
}








