class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0)
                    continue;

                // BFS
                q.push({i, j});
                int islandSize = 0;
                bool edged = false;
                grid[i][j] = 0;
                while(q.size()) {
                    auto& [x, y] = q.front();

                    islandSize++;

                    // Note: Find if edged
                    edged = edged || (x == 0 || x == m - 1 || y == 0 || y == n - 1);

                    if(x > 0 && grid[x - 1][y] == 1) {
                        grid[x - 1][y] = 0;
                        q.push({x - 1, y});
                    }
                    if(x < m - 1 && grid[x + 1][y] == 1) {
                        grid[x + 1][y] = 0;
                        q.push({x + 1, y});
                    }
                    if(y > 0 && grid[x][y - 1] == 1) {
                        grid[x][y - 1] = 0;
                        q.push({x, y - 1});
                    }
                    if(y < n - 1 && grid[x][y + 1] == 1) {
                        grid[x][y + 1] = 0;
                        q.push({x, y + 1});
                    }

                    q.pop();
                }

                if(!edged)
                    count += islandSize;
            }
        }

        return count;
    }
};
/*
0   0   0   0
1   0   1   0  
    1   1
*/