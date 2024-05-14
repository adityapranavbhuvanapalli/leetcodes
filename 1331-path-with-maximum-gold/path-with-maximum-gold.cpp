class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxGold = 0;

        // For each non-empty cell
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j])
                    maxGold = max(maxGold, dfs(i, j, m, n, grid));

        return maxGold;
    }

    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid) {
        int value = grid[i][j];
        
        grid[i][j] = 0; // Making grid[i][j] unreachable after visiting

        // DFS (TLBR)
        int top = (i>0 && grid[i-1][j]) ? dfs(i-1, j, m, n, grid) : 0;
        int left = (j>0 && grid[i][j-1]) ? dfs(i, j-1, m, n, grid) : 0;
        int bottom = (i<m-1 && grid[i+1][j]) ? dfs(i+1, j, m, n, grid) : 0;
        int right = (j<n-1 && grid[i][j+1]) ? dfs(i, j+1, m, n, grid) : 0;

        grid[i][j] = value; // Making grid[i][j] reachable after processing

        return value + max({top, left, bottom, right});
    }
};