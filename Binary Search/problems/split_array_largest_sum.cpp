/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

	bool isPossible(vector<int>& nums, int s, int k) {
		int sum = 0, arr = 1;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (sum > s) {
				sum = nums[i];
				arr++;
			}
		}
		return arr <= k;
	}

	int splitArray(vector<int>& nums, int k) {
		int low = 0, high = 0;
		for (int i = 0; i < nums.size(); i++) {
			low = max(low, nums[i]);
			high += nums[i];
		}
		int ans = 0;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (isPossible(nums, mid, k)) {
				ans = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return ans;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


}