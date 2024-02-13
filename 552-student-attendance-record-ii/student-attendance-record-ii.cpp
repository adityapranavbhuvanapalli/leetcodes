class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int checkRecord(int n) {
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(n, 0, 0);
    }

    int solve(int n, int a, int l) {
        if(n == 0)
            return 1;

        if(dp[n][a][l] != -1)
            return dp[n][a][l];

        int res = 0;

        if(a < 1)
            res = (res + solve(n - 1, a + 1, 0)) % MOD;
        if(l < 2)
            res = (res + solve(n - 1, a, l + 1)) % MOD;
        res = (res + solve(n - 1, a, 0)) % MOD;

        return dp[n][a][l] = res;
    }
};