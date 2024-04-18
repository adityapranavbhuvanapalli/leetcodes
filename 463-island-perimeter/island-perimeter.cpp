class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), perimeter = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!grid[i][j])
                    continue;
                    
                perimeter += (i == 0 || !grid[i-1][j]);
                perimeter += (i == m - 1 || !grid[i+1][j]);
                perimeter += (j == 0 || !grid[i][j-1]);
                perimeter += (j == n - 1 || !grid[i][j+1]);
            }
        }

        return perimeter;
    }
};