// https://leetcode.com/problems/number-of-digit-one/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

// dp state: no of 1's found in all no's having digit n, when there was an upper bound or not
// dp[idx][cnt][flag]

class Solution {
public:
    int dp[11][11][2];
    int solve(string &s, int idx,int cnt, bool flag){
        if(idx == s.size()){
            return cnt;
        }
        if(dp[idx][cnt][flag]!=-1) return dp[idx][cnt][flag];
        char ub = '9';
        if(flag) ub = s[idx];
        int count = 0;
        for(char x = '0'; x <= ub; x++){
            bool new_flag = flag & (x == ub);
            int new_cnt = cnt;
            if(x == '1') new_cnt++;
            count += solve(s,idx+1,new_cnt,new_flag);
        }
        return dp[idx][cnt][flag] = count;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof dp);
        return solve(s,0,0,true);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::ios::sync_with_stdio(false);

    

}