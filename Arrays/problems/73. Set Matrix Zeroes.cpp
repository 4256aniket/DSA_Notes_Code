/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        bool row = false, col = false;
        for(int i=0;i<r;i++) if(matrix[i][0]==0) col = true;
        for(int i=0;i<c;i++) if(matrix[0][i]==0) row = true;
        
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i=1;i<r;i++){
            if(matrix[i][0]==0){
                for(int j = 0;j<c;j++){
                    matrix[i][j]=0;   
                }
            }
        }
        for(int i=1;i<c;i++){
            if(matrix[0][i]==0){
                for(int j = 0;j<r;j++){
                    matrix[j][i]=0;   
                }
            }
        }
        if(row){
            for(int i = 0;i<c;i++){
                matrix[0][i] = 0;
            }
        }
        if(col){
            for(int i = 0;i<r;i++){
                matrix[i][0] = 0;
            }
        }
    }
};