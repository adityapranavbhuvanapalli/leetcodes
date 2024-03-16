class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[101][101][101];
    vector<int> power2;
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        power2 = vector<int>(100, 1);
        for(int i=1; i<n; i++) {
            power2[i] = (power2[i - 1] * 2) % MOD;
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, n, nums, k, 0);
    }
    
    long long solve(int i, int n, vector<int>& nums, int k, int count) {
        if(k == 0)
            return power2[n - count] % MOD;

        if(k < 0)
            return 0;

        if(i >= n)
            return 0;

        if(dp[i][k][count] != -1)
            return dp[i][k][count];

        long long pick = solve(i + 1, n, nums, k - nums[i], count + 1);
        long long notpick = solve(i + 1, n, nums, k, count);

        return dp[i][k][count] = (pick + notpick) % MOD;
    }
};

/*
5
2   3   3

2   3 - 2
2   3 - 2


*/