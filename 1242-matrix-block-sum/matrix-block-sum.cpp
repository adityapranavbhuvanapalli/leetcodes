class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        vector<vector<int>> res(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int top = i > 0 ? prefixSum[i - 1][j] : 0;
                int left = j > 0 ? prefixSum[i][j - 1] : 0;
                int diagonal = i > 0 && j > 0 ? prefixSum[i - 1][j - 1] : 0;

                prefixSum[i][j] = mat[i][j] + top + left - diagonal;
            }
        }        

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int x1 = max(i - k, 0), y1 = max(j - k, 0);
                int x2 = min(i + k, m - 1), y2 = min(j + k, n - 1);

                int top = x1 > 0 ? prefixSum[x1 - 1][y2] : 0;
                int left = y1 > 0 ? prefixSum[x2][y1 - 1] : 0;
                int diagonal = x1 > 0 && y1 > 0 ? prefixSum[x1 - 1][y1 - 1] : 0;

                res[i][j] = prefixSum[x2][y2] - top - left + diagonal;
            }
        }

        return res;
    }
};

/*
1   2   3
4   5   6
7   8   9

prefixSum:
1   3   6
5   12  21
12  27  45
*/