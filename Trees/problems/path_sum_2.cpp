/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		if (!root) return {};
		if (!root->left && !root->right) {
			if (targetSum == root->val) {
				return {{root->val}};
			}
			return {};
		}
		vector<vector<int>> left, right, ans;
		if (root->left) left = pathSum(root->left, targetSum - root->val);
		if (root->right) right = pathSum(root->right, targetSum - root->val);

		if (left.size() > 0) {
			for (auto & path : left) {
				path.insert(path.begin(), root->val);
				ans.push_back(path);
			}
		}

		if (right.size() > 0) {
			for (auto & path : right) {
				path.insert(path.begin(), root->val);
				ans.push_back(path);
			}
		}

		return ans;
	}
};

// Backtracking based solution

class Solution {
public:

    void helper(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>> & paths){
        if(!root) return;
        path.push_back(root->val);
        if(!root->left && !root->right && root->val == targetSum){
            paths.push_back(path);
        }
        helper(root->left, targetSum - root->val, path, paths);
        helper(root->right, targetSum - root->val, path, paths);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int>path;

        helper(root, targetSum, path, paths);
        return paths;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


}