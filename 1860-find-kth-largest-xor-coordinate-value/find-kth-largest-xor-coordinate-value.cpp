class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), top, left, diagonal;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                top = (i > 0) ? dp[i - 1][j] : 0;
                left = (j > 0) ? dp[i][j - 1] : 0;
                diagonal = (i > 0 && j > 0) ? dp[i - 1][j - 1] : 0;

                dp[i][j] = matrix[i][j] ^ top ^ left ^ diagonal;

                pq.push(dp[i][j]);
                if(pq.size() > k)
                    pq.pop();
            }
        }

        return pq.top();
    }
};

/*
5   2   
1   6

5   7
4   0

*/