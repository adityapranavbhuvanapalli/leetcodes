class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, dp);
    }
    
    int solve(int l, int r, vector<vector<int>>& dp) {
        if(l >= r)
            return 0;
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        int res = INT_MAX;
        for(int i=l; i<=r; i++) {
            res = min(res, i + max(solve(l, i-1, dp), solve(i+1, r, dp)));
        }
        
        return dp[l][r] = res;
    }
};