/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

*/

// Brute Force Solution O(n^2)
class Solution {
public:
	int a = 0;
	void helper(TreeNode* root, long long targetSum) {
		if (root == nullptr) return;

		if (!root->left && !root->right && root->val == targetSum) {
			a++;
			return;
		}

		if (root->val == targetSum) {
			a++;
		}

		if (root->left) helper(root->left, targetSum - root->val);
		if (root->right) helper(root->right, targetSum - root->val);

	}

	void noOfPaths(TreeNode* root, int s) {
		if (root == nullptr) return;
		helper(root, s);
		noOfPaths(root->left, s);
		noOfPaths(root->right, s);

	}

	int pathSum(TreeNode* root, int targetSum) {
		noOfPaths(root, targetSum);
		return a;
	}
};



// Optimal Solution using concept similar to "no of subarrays with given sum" (hashmap approach)

class Solution {
public:

	int total = 0;

	int pathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) return 0;
		unordered_map<long long, long long> m;
		m[0] = 1;
		findPathSum(root, 0, targetSum, m);
		return total;
	}

private:

	void findPathSum(TreeNode* root, long long sum, long long target, unordered_map<long long, long long> m) {
		if (root == nullptr) return;
		sum += root->val;
		if (m.count(sum - target)) {
			total += (m[sum - target]);
		}

		m[sum]++;

		findPathSum(root->left, sum, target, m);
		findPathSum(root->right, sum, target, m);

		m[sum]--;
		if (m[sum] == 0) {
			m.erase(sum);
		}
	}
