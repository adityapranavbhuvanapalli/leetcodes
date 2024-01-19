class Solution {
public:
    const int INF = 1e7;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), top, left, right;
        int minSum = INT_MAX;

        if(n == 1) {
            for(const auto& e: matrix[0])
                minSum = min(minSum, e);
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                top = matrix[i-1][j];
                left = (j > 0) ? matrix[i-1][j-1] : INF;
                right = (j < n-1) ? matrix[i-1][j+1] : INF;
                matrix[i][j] += min({left, top, right});

                if(i == n-1)
                    minSum = min(minSum, matrix[i][j]);
            }
        }

        return minSum;
    }
};