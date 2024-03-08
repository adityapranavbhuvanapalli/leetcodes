class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int minEffort = 0, m = heights.size(), n = heights[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({minEffort, 0, 0});
        effort[0][0] = 0;
        while(pq.size()) {
            while(pq.size() && effort[pq.top()[1]][pq.top()[2]] < pq.top()[0])
                pq.pop();

            auto& cur = pq.top();
            int dist = cur[0], x = cur[1], y = cur[2];
            pq.pop();
            
            minEffort = max(minEffort, dist);

            if(x == m - 1 && y == n - 1)
                return minEffort;

            for(const auto& [dx, dy]: dirs) {
                int X = x + dx, Y = y + dy;
                if(X >= 0 && Y >= 0 && X < m && Y < n) {
                    int newDist = max(dist, abs(heights[x][y] - heights[X][Y]));
                    if(newDist < effort[X][Y]) {
                        pq.push({newDist, X, Y});
                        effort[X][Y] = newDist;
                    }
                }
            }
        }    

        return minEffort;
    }
};

/*
1   2   2
3   8   2
5   3   5

1(0)
------------
2(1), 3(2)
------------
2(1), 3(2), 8(6)
------------

*/