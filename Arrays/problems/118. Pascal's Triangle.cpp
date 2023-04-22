/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> a = {1};
        ans.push_back(a);
        for(int i = 1;i<numRows;i++){
            int size = ans[i-1].size();
            vector<int> temp;
            temp.push_back(1);
            for(int j=0; j<size-1; j++){
                int n = ans[i-1][j] + ans[i-1][j+1];
                temp.push_back(n);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};