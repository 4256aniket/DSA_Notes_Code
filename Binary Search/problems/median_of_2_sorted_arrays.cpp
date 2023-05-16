#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size(), n2 = nums2.size();
		int lo = 0, hi = n1;
		if (n1 > n2) {
			return findMedianSortedArrays(nums2, nums1);
		}
		while (lo <= hi) {
			int cut1 = lo + (hi - lo) / 2;
			int cut2 = (n1 + n2) / 2 - cut1;
			int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
			int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
			int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
			int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

			if (l1 > r2) {
				hi = cut1 - 1;
			} else if (l2 > r1) {
				lo = cut1 + 1;
			} else {
				return ((n1 + n2 ) % 2 == 0) ? double(min(r1, r2) + max(l1, l2)) / 2.0 : min(r1, r2);
			}
		}
		return -1;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<int> v1(n), v2(m);
	for (int i = 0; i < n; i++) cin >> v1[i];
	for (int i = 0; i < m; i++) cin >> v2[i];


	Solution obj;
	cout << obj.findMedianSortedArrays(v1, v2) << endl;
}





