class Solution {
public:
    const int MOD = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        dp[1][0] = 1;
        for(int i=2; i<=n; i++) {
            for(int j=0; j<=k; j++) {
                for(int x=0; x<i; x++) {
                    if(j-x < 0)
                        break;
                    dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % MOD;
                }
            }
        }

        return dp[n][k];
    }
};

/*
01 - 0(1), 1(1)
011223 - 0(1), 1(2), 2(2), 3(1)
011223 122334 233445 344556 - 0(1), 1()
0      1      2      3
*/