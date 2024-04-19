class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '0')
                    continue;

                processIsland(i, j, grid);
                count++;
            }
        }

        return count;
    }

    void processIsland(int x, int y, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        grid[x][y] = '0';

        if(x > 0 && grid[x-1][y] == '1')
            processIsland(x-1, y, grid);
        if(y > 0 && grid[x][y-1] == '1')
            processIsland(x, y-1, grid);
        if(x < m-1 && grid[x+1][y] == '1')
            processIsland(x+1, y, grid);
        if(y < n-1 && grid[x][y+1] == '1')
            processIsland(x, y+1, grid);
    }
};