class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        int res = 0;

        dp = vector<vector<int>>(m, vector<int>(n, -1));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                res = max(res, dfs(i, j, matrix));
            }
        }   

        return 1 + res;
    }

    int dfs(int x, int y, vector<vector<int>>& matrix) {
        if(dp[x][y] != -1)
            return dp[x][y];

        int tmp = matrix[x][y], res = 0;

        matrix[x][y] = -1;

        if(x > 0 && matrix[x - 1][y] > tmp)
            res = max(res, 1 + dfs(x - 1, y, matrix));
        if(x < m - 1 && matrix[x + 1][y] > tmp)
            res = max(res, 1 + dfs(x + 1, y, matrix));
        if(y > 0 && matrix[x][y - 1] > tmp)
            res = max(res, 1 + dfs(x, y - 1, matrix));
        if(y < n - 1 && matrix[x][y + 1] > tmp)
            res = max(res, 1 + dfs(x, y + 1, matrix));

        matrix[x][y] = tmp;

        return dp[x][y] = res;
    }
};