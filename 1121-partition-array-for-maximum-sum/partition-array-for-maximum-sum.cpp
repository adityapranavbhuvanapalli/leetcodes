class Solution {
public:
    vector<int> dp;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        dp = vector<int>(n, -1);
        return solve(0, n, k, arr);
    }

    int solve(int i, int n, int k, vector<int>& arr) {
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int maxVal = 0, child = 0;
        for(int x=0; x<k && i + x < n; x++) {
            maxVal = max(maxVal, arr[i+x]);
            child = max(child, (x + 1) * maxVal + solve(i+x+1, n, k, arr));
        }

        return dp[i] = child;
    }
};

/*
k = 
1   15  7   9   2   5   10

1
-15 
-15  7
-15  7   9
1   15

1   15  7
*/