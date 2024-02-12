class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                res = max(res, dfs(i, j, m, n, matrix, dp));

        return res;
    }

    int dfs(int x, int y, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(dp[x][y] != -1)
            return dp[x][y];

        int res = 0, tmp = matrix[x][y];

        matrix[x][y] = -1;

        if(x > 0 && matrix[x-1][y] > tmp)
            res = max(res, dfs(x-1, y, m, n, matrix, dp));
        if(x < m-1 && matrix[x+1][y] > tmp)
            res = max(res, dfs(x+1, y, m, n, matrix, dp));
        if(y > 0 && matrix[x][y-1] > tmp)
            res = max(res, dfs(x, y-1, m, n, matrix, dp));
        if(y < n-1 && matrix[x][y+1] > tmp)
            res = max(res, dfs(x, y+1, m, n, matrix, dp));

        matrix[x][y] = tmp;

        return dp[x][y] = 1 + res;
    }
};