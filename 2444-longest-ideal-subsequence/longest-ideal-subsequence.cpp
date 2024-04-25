class Solution {
public:
    int dp[100005][27];
    int solve(int i, char prev, string& s, int k) {
        if (dp[i][prev-'a'] != -1)
            return dp[i][prev-'a'];
        if (i >= s.size())
            return 0;
        int pick = 0, notpick = 0;
        if (prev == '{' || abs(prev - s[i]) <= k)
            pick = 1 + solve(i + 1, s[i], s, k);
        notpick = solve(i + 1, prev, s, k);
        return dp[i][prev-'a'] = max(pick, notpick);
    }
    
    int longestIdealString(string s, int k) {
        memset(dp, -1, sizeof dp);
        return solve(0, '{', s, k);
    }
};