/*
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.



Example 1:

Input: k = 1, n = 2
Output: 2
Explanation:
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
Example 2:

Input: k = 2, n = 6
Output: 3
Example 3:

Input: k = 3, n = 14
Output: 4


Constraints:

1 <= k <= 100
1 <= n <= 104
*/


// Using Linear Search
class Solution {
public:
	int t[102][10004];
	int superEggDrop(int k, int n) {
		for (int i = 0; i < k + 2; i++)
			for (int j = 0; j < n + 2; j++)
				t[i][j] = -1;

		return solve(k, n);
	}
private:
	int solve(int k, int n) {
		if (n == 0 || n == 1) return n;
		if (k == 1) return n;

		if (t[k][n] != -1) return t[k][n];

		int mn = INT_MAX;

		for (int i = 1; i <= n; i++) {
			int a = (t[k - 1][i - 1] != -1) ? t[k - 1][i - 1] : t[k - 1][i - 1] = solve(k - 1, i - 1);
			int b = (t[k][n - i] != -1) ? t[k][n - i] : t[k][n - i] = solve(k, n - i);
			int temp = 1 + max(a, b);
			mn = min(mn, temp);
		}
		return t[k][n] = mn;
	}
};



// Using Binary Search
class Solution {
public:
	int t[102][10004];
	int superEggDrop(int k, int n) {
		for (int i = 0; i < k + 2; i++)
			for (int j = 0; j < n + 2; j++)
				t[i][j] = -1;

		return solve(k, n);
	}
private:
	int solve(int k, int n) {
		if (n == 0 || n == 1) return n;
		if (k == 1) return n;

		if (t[k][n] != -1) return t[k][n];


		int mn = INT_MAX, low = 0, high = n, temp = 0;

		while (low <= high)
		{

			int mid = low + (high - low) / 2;

			int left = solve(k - 1, mid - 1); //when the egg breaks
			int right = solve(k, n - mid); //when egg is not break

			temp = 1 + max(left, right);

			if (right > left) //As we want first threshold floor we move upwards
				low = mid + 1;
			else
				high = mid - 1; //move to the downward

			mn = min(mn, temp); //minimum number of attempts
		}

		return t[k][n] = mn;
	}
};