class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, n, piles, dp);
    }

    int solve(int start, int k, int n, vector<vector<int>>& piles, vector<vector<int>>& dp) {
        if(k == 0 || start >= n)
            return 0;

        if(dp[start][k] != -1)
            return dp[start][k];

        int res = 0, sum = 0;
        // Do not pick from piles[start]
        res = max(res, solve(start + 1, k, n, piles, dp));

        // Pick i coins from piles[start]
        for(int i=1; i<=min(k, (int)piles[start].size()); i++) {
            sum += piles[start][i - 1];
            res = max(res, sum + solve(start + 1, k - i, n, piles, dp));
        }

        return dp[start][k] = res;
    }
};