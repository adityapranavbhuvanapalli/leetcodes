class Solution {
public:
    const int MOD = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        dp[1][0] = 1;
        for(int i=1; i<=n; i++) {
            // cout<<i<<": ";
            for(int j=0; j<=k; j++) {
                for(int x=0; x<i; x++) {
                    if(x > j)
                        break;
                    dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % MOD;
                }
                // cout<<"\t"<<dp[i][j];
            }
            // cout<<endl;
        } 

        return dp[n][k];
    }
};

/*
1 - 0
2 - 01
3 - 011223 
4 - 011223122334233445344556
*/