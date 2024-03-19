class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        pq.push({grid[0][0], 0, 0});
        while(pq.size()) {
            auto& top = pq.top();
            int time = top[0], x = top[1], y = top[2];
            pq.pop();

            if(x == n - 1 && y == n - 1)
                return time;

            for(const auto& [dx, dy]: dirs) {
                int X = x + dx, Y = y + dy;

                if(X>=0 && X<n && Y>=0 && Y<n && time < dist[X][Y]) {
                    dist[X][Y] = time;
                    pq.push({max(time, grid[X][Y]), X, Y});
                }
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