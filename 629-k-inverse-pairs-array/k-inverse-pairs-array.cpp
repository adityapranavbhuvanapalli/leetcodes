class Solution {
public:
    const int MOD = 1e9 + 7;
    int kInversePairs(int n, int k) {
        bool flag;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        dp[1][0] = 1;
        for(int i=1; i<=n; i++) {
            flag = false;
            for(int j=0; j<=k; j++) {
                for(int x=0; x<i; x++) {
                    if(x > j)
                        break;
                    
                    dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % MOD;
                }

                if(dp[i][j] == 0)
                    break;
            }
        } 

        return dp[n][k];
    }
};

/*
1 - 0
2 - 01
3 - 01 12 23 
4 - 011223 122334 233445 344556
    0      1      2      3  
*/