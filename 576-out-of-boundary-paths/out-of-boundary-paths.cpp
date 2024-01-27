class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = vector<vector<vector<int>>>(
            maxMove + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        return solve(startRow, startColumn, m, n, maxMove);
    }

    int solve(int i, int j, int m, int n, int M) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 1;

        if (M == 0)
            return 0;

        if (dp[M][i][j] != -1)
            return dp[M][i][j];

        int res = 0;

        res = (res + solve(i - 1, j, m, n, M - 1)) % MOD;
        res = (res + solve(i + 1, j, m, n, M - 1)) % MOD;
        res = (res + solve(i, j - 1, m, n, M - 1)) % MOD;
        res = (res + solve(i, j + 1, m, n, M - 1)) % MOD;

        return dp[M][i][j] = res;
    }
};