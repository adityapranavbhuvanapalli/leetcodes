class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> visited(n, vector<int>(n, 0));

        pq.push({grid[0][0], 0, 0});
        while(pq.size()) {
            int time = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            if(x == n-1 && y == n-1)
                return time;

            for(int k=0; k<4; k++) {
                if(visited[x][y] & (1<<k))
                    continue;

                auto& [dx, dy] = dirs[k];
                int X = x + dx, Y = y + dy;

                if(X < 0 || X >= n || Y < 0 || Y >= n)
                    continue;

                visited[x][y] = visited[x][y] | (1 << k);
                pq.push({max(time, grid[X][Y]), X, Y});
            }
        }

        return -1;
    }
};

/*
       2
    0 -> 2
   1|    |1
    v    v
    1 -> 3
       2

10  12  4   6
9   11  3   5
1   7   13  8
2   0   15  14
*/