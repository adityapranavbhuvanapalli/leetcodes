class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int top, left;

        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                top = (i > 0) ? dp[i - 1][j] : 0;
                left = (j > 0) ? dp[i][j - 1] : 0;

                dp[i][j] = obstacleGrid[i][j] ? 0 : top + left;
            }
        }

        return dp[m - 1][n - 1];
    }
};