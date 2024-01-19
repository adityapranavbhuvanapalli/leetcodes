class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), minIdx, min1, min2, res = INT_MAX;

        if(n == 1) {
            for(const auto& e: grid[0])
                res = min(res, e);
            return res;
        }

        for(int i=1; i<n; i++) {
            min1 = min2 = INT_MAX;
            
            // Find min1, min2 of top row
            for(int j=0; j<n; j++) {
                if(min1 >= grid[i-1][j]) {
                    min2 = min1;
                    minIdx = j;
                    min1 = grid[i-1][j];
                } else if(min2 >= grid[i-1][j]) {
                    min2 = grid[i-1][j];
                }
            }

            for(int j=0; j<n; j++) {
                if(j == minIdx) {
                    grid[i][j] += min2;
                } else {
                    grid[i][j] += min1;
                }
            }
        }

        for(int i=0; i<n; i++) {
            res = min(res, grid[n-1][i]);
        }

        return res;
    }
};

/*
1   2   3   4
5   6   7   8
9   10  11  12
13  14  15  16
*/