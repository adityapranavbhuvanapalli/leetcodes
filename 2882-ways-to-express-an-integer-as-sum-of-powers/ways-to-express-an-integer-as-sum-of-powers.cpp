class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int numberOfWays(int n, int x) {
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return solve(1, n, x);
    }

    int solve(int i, int n, int x) {
        if(n == 0)
            return 1;

        if(n < 0 || pow(i, x) > n)
            return 0;

        if(dp[i][n] != -1)
            return dp[i][n];

        int pick = solve(i + 1, n - pow(i, x), x);
        int notpick = solve(i+1, n, x);

        return dp[i][n] = (pick + notpick) % MOD;
    }
};

/*
Unique bases

1 - 1^2 = 1 ways
2 - 0 ways
3 - 0 ways
4 - 2^2 = 1 way
5 - 2^2 + 1^2 = 1 way
*/