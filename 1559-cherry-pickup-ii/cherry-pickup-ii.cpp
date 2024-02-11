class Solution {
public:
    int dp[70][70][70];
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, n-1, m, n, grid);
    }

    int solve(int row, int col1, int col2, int m, int n, vector<vector<int>>& grid) {
        if(row == m)
            return 0;

        if(dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int X, Y, res = 0;
        int profit = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];

        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                X = col1 + i, Y = col2 + j;
                if(X < 0 || X >= n || Y < 0 || Y >= n)
                    continue;

                res = max(res, profit + solve(row + 1, X, Y, m, n, grid));
            }
        }

        return dp[row][col1][col2] = res;
    }
};

/*
4   1   5   7   1
6   0   4   6   4
0   9   6   3   5
*/