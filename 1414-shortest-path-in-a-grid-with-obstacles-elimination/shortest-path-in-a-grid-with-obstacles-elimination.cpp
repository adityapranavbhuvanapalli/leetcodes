class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int K) {
        int m = grid.size(), n = grid[0].size(), sz, steps = 0;
        queue<tuple<int, int, int>> q;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(K + 1, false)));

        q.push({0, 0, K});
        visited[0][0][K] = true;
        while(q.size()) {
            sz = q.size();
            while(sz--) {
                auto& [x, y, k] = q.front();

                cout<<x<<" "<<y<<" "<<k<<endl;

                if(x == m - 1 && y == n - 1)
                    return steps;

                if(x > 0 && k >= grid[x - 1][y] && !visited[x - 1][y][k - grid[x - 1][y]]) {
                    // cout<<"\t1. "<<x - 1<<" "<<y<<" "<<k - grid[x - 1][y]<<endl;
                    q.push({x - 1, y, k - grid[x - 1][y]});
                    visited[x - 1][y][k - grid[x - 1][y]] = true;
                }

                if(x < m - 1 && k >= grid[x + 1][y] && !visited[x + 1][y][k - grid[x + 1][y]]) {
                    // cout<<"\t2. "<<x + 1<<" "<<y<<" "<<k - grid[x + 1][y]<<endl;
                    q.push({x + 1, y, k - grid[x + 1][y]});
                    visited[x + 1][y][k - grid[x + 1][y]] = true;
                }

                if(y > 0 && k >= grid[x][y - 1] && !visited[x][y - 1][k - grid[x][y - 1]]) {
                    // cout<<"\t3. "<<x<<" "<<y - 1<<" "<<k - grid[x][y - 1]<<endl;
                    q.push({x, y - 1, k - grid[x][y - 1]});
                    visited[x][y - 1][k - grid[x][y - 1]] = true;
                }

                if(y < n - 1 && k >= grid[x][y + 1] && !visited[x][y + 1][k - grid[x][y + 1]]) {
                    // cout<<"\t4. "<<x<<" "<<y + 1<<" "<<k - grid[x][y + 1]<<endl;
                    q.push({x, y + 1, k - grid[x][y + 1]});
                    visited[x][y + 1][k - grid[x][y + 1]] = true;
                }

                q.pop();
            }

            cout<<"-------"<<endl;
            steps++;
        }

        return -1;
    }
};

/*
0   0   0   0   0   0
1   0   1   0   1   0
1   0   0   0   1   1
1   1   1   1   1   0
*/