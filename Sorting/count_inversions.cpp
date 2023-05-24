#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int l, int m, int r)
{
	int inv_count = 0;
	int left_size = m - l + 1;
	int right_size = r - m;

	int left_arr[left_size];
	int right_arr[right_size];

	for (int i = 0; i < left_size; i++) {
		left_arr[i] = arr[l + i];
	}

	for (int i = 0; i < right_size; i++) {
		right_arr[i] = arr[m + 1 + i];
	}

	int i = 0, j = 0, k = l;

	while (i < left_size and j < right_size) {
		if (left_arr[i] <= right_arr[j]) {
			arr[k++] = left_arr[i++];
		} else {
			arr[k++] = right_arr[j++];
			inv_count += (left_size - i);
		}
	}

	while (i < left_size) {
		arr[k++] = left_arr[i++];
	}

	while (j < right_size) {
		arr[k++] = right_arr[j++];
	}

	return inv_count;
}

int mergeSort(int arr[], int l, int r) {
	if (l == r) return 0;
	int mid = l + (r - l) / 2;
	int inv_count = 0;
	inv_count += mergeSort(arr, l, mid);
	inv_count += mergeSort(arr, mid + 1, r);
	inv_count += merge(arr, l, mid, r);
	return inv_count;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << mergeSort(arr, 0, n - 1) << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}