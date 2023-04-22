/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/


// Bottom Up DP solution
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n + 1);
		for (int i = n - 1; i >= 0; i--) {
			if (i == n - 1) dp[i] = true;
			else {
				if (nums[i] == 0)dp[i] = false;
				else {
					bool ans = false;
					for (int j = 1; j <= nums[i]; j++) {
						ans = (ans || dp[i + j]);
						if (ans)break;
					}
					dp[i] = ans;
				}
			}
		}
		return dp[0];
	}

};


// optimized solution
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int i, minjump = 0;
		for (i = nums.size() - 2; i >= 0; i--) {
			minjump++;
			if (nums[i] >= minjump)
				minjump = 0;
		}
		if (minjump == 0)
			return true;
		else
			return false;
	}
};