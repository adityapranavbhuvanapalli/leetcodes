class Solution {
public:
    int MOD = 1e9 + 7;
    int findPaths(int m, int n, int maxMoves, int i, int j) {
        vector<vector<vector<int>>> dp(
            maxMoves + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(m, n, maxMoves, i, j, dp);
    }

    int solve(int m, int n, int M, int i, int j,
              vector<vector<vector<int>>>& dp) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 1;

        if (M == 0)
            return 0;

        if (dp[M][i][j] != -1)
            return dp[M][i][j];

        int res = 0;
        res = (res + solve(m, n, M - 1, i - 1, j, dp)) % MOD;
        res = (res + solve(m, n, M - 1, i + 1, j, dp)) % MOD;
        res = (res + solve(m, n, M - 1, i, j - 1, dp)) % MOD;
        res = (res + solve(m, n, M - 1, i, j + 1, dp)) % MOD;

        return dp[M][i][j] = res;
    }
};