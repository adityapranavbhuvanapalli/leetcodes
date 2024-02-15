class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        long long maxSoFar, maxVal = 0;
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        vector<long long> potential(n);

        for(int i=0; i<n; i++)
            dp[0][i] = points[0][i];

        for(int i=1; i<m; i++) {
            // L to R
            maxSoFar = 0;
            for(int j=0; j<n; j++) {
                maxSoFar = max(maxSoFar - 1, dp[i-1][j]);
                potential[j] = maxSoFar;
            }

            // R to L
            maxSoFar = 0;
            for(int j=n-1; j>=0; j--) {
                maxSoFar = max(maxSoFar - 1, dp[i-1][j]);
                potential[j] = max(potential[j], maxSoFar);
            }

            // Update dp[i][j]
            for(int j=0; j<n; j++)
                dp[i][j] = potential[j] + points[i][j];
        }

        for(int i=0; i<n; i++) 
            maxVal = max(maxVal, dp[m-1][i]);

        return maxVal;
    }
};

/*
maxSoFar = max(maxSoFar - 1, dp[i-1][j]) = 3
potential:
1   1   2   10   
7   8   9   10 


1   1   2   10


*/