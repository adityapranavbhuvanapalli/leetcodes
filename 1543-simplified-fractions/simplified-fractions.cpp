class Solution {
public:
    int dp[101][101];
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        memset(dp, -1, sizeof(dp));

        for(int i=2; i<=n; i++) {
            for(int j=1; j<i; j++) {
                if(gcd(i, j) == 1) {
                    res.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }

        return res;
    }

    int gcd(int m, int n) {
        if(dp[m][n] != -1)
            return dp[m][n];
        return dp[m][n] = dp[n][m] = n == 0 ? m : gcd(n, m%n);
    }
};

/*
2
1/2
3
1/2 1/3 2/3
*/