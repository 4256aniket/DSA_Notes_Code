int mod = 1e9 + 7;

long long dp[30][30][2];
int helper(string &s, int idx, long long cnt, bool flag) {
    if (idx == s.size()) {
        return cnt;
    }
    if (dp[idx][cnt][flag] != -1) return dp[idx][cnt][flag];
    char ub = '1';
    if (flag) ub = s[idx];
    long long count = 0;
    for (char x = '0'; x <= ub; x++) {
        bool new_flag = flag & (x == ub);
        int new_cnt = cnt;
        if (x == '1') new_cnt++;
        count = (count + 1ll*helper(s, idx + 1, new_cnt, new_flag)) % mod;
    }
    return dp[idx][cnt][flag] = count;
}


int Solution::solve(int A) {
    string s = "";
    for (int i = 0; i < 30; i++) {
        if (A & (1 << i)) {
            s += '1';
        } else s += '0';
    }
    reverse(s.begin(), s.end());
    memset(dp, -1, sizeof dp);
    return helper(s, 0, 0, true);
}
