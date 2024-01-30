class Solution {
public:
    map<pair<int, int>, int> dp;
    int countArrangement(int n) {
        vector<vector<int>> possible(n+1);

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i % j == 0 || j % i == 0) {
                    possible[i].push_back(j);
                }
            }
        }

        return solve(1, 0, n, possible);
    }

    int solve(int i, int mask, int n, vector<vector<int>>& possible) {
        if(i > n)
            return 1;

        if(dp.count({i, mask}))
            return dp[{i, mask}];

        int res = 0;
        for(const auto& p: possible[i]) {
            // Check if pth bit is already set
            if((mask & (1 << (p-1))))
                continue;

            // If not set, solve by setting pth bit
            int newMask = (mask | (1 << (p-1)));
            res += solve(i + 1, newMask, n, possible);
        }

        return dp[{i, mask}] = res;
    }
};