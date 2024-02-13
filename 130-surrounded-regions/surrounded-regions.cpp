class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};   //rlbt
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(visited[i][j] || board[i][j]=='X')
                    continue;

                vector<pair<int, int>> region;
                queue<pair<int, int>> q;
                bool edged = false;
                
                region.push_back({i, j});
                edged |= (i==0 || i==m-1 || j==0 || j==n-1);

                q.push({i, j});
                visited[i][j] = true;
                while(q.size()) {
                    auto& cur = q.front();
                    for(int k=0; k<4; k++) {
                        int x = cur.first + dirs[k].first;
                        int y = cur.second + dirs[k].second;
                        if(x>=0 && x<m && y>=0 && y<n) {
                            if(board[x][y]=='O' && !visited[x][y]) {
                                visited[x][y]=true;
                                edged |= (x==0 || x==m-1 || y==0 || y==n-1);
                                region.push_back({x, y});
                                q.push({x, y});
                            }
                        }
                    }
                    q.pop();
                }

                if(edged)
                    continue;
                
                for(auto reg: region)
                    board[reg.first][reg.second] = 'X';
            }
        }
    }
};