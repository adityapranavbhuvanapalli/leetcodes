class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[(int)1e5 + 1][2][3];
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
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