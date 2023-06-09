/*
You are given two numeric strings num1 and num2 and two integers max_sum and min_sum. We denote an integer x to be good if:

num1 <= x <= num2
min_sum <= digit_sum(x) <= max_sum.
Return the number of good integers. Since the answer may be large, return it modulo 109 + 7.

Note that digit_sum(x) denotes the sum of the digits of x.



Example 1:

Input: num1 = "1", num2 = "12", min_num = 1, max_num = 8
Output: 11
Explanation: There are 11 integers whose sum of digits lies between 1 and 8 are 1,2,3,4,5,6,7,8,10,11, and 12. Thus, we return 11.
Example 2:

Input: num1 = "1", num2 = "5", min_num = 1, max_num = 5
Output: 5
Explanation: The 5 integers whose sum of digits lies between 1 and 5 are 1,2,3,4, and 5. Thus, we return 5.


Constraints:

1 <= num1 <= num2 <= 1022
1 <= min_sum <= max_sum <= 400
*/

const int MOD = 1e9 + 7;
const int N = 23;

int dp[2][23][200];

class Solution {

	string s;
	int max_sum, min_sum;

	string SubtractOne (string x) {
		int n = x.length();

		int last_non_zero_ind = n - 1;
		while (last_non_zero_ind >= 0) {
			if (x[last_non_zero_ind] >= '1') break;
			last_non_zero_ind--;
		}

		x[last_non_zero_ind]--;
		for (int j = last_non_zero_ind + 1; j < n; j ++) x[j] = '9';

		return x;
	}

	int GoodIntegers (bool is_smaller, int ind, int sum) {
		if (ind == s.size()) {
			if (min_sum <= sum && sum <= max_sum) return 1;
			return 0;
		}

		int &ans = dp[is_smaller][ind][sum];
		if (ans != -1) return ans;

		ans = 0;
		int st = 0, ed = 9;
		if (!is_smaller) ed = s[ind] - '0';

		for (int i = st; i <= ed; i ++) {
			ans = (ans + GoodIntegers((is_smaller == false && i == ed) ? false : true, ind + 1, sum + i)) % MOD;
		}
		return ans;
	}

	void buildS (string x) {
		int x_len = x.length();
		s = "";
		for (int j = 0; j < (N - x_len); j ++) s += '0';
		s += x;
	}

	int GoodIntegersLessThanX (string x) {
		memset(dp, -1, sizeof(dp));

		buildS (x);
		return GoodIntegers(false, 0, 0);
	}

public:
	int count(string num1, string num2, int _min_sum, int _max_sum) {
		max_sum = _max_sum;
		min_sum = _min_sum;

		return (GoodIntegersLessThanX(num2) - GoodIntegersLessThanX(SubtractOne(num1)) + MOD) % MOD;
	}
};