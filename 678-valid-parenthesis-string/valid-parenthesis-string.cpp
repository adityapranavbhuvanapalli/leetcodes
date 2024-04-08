class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, 0, n, s, dp);
    }

    bool solve(int i, int open, int n, string& s, vector<vector<int>>& dp) {
        if(i >= n)
            return open == 0;

        if(open < 0)
            return false;

        if(dp[i][open] != -1)
            return dp[i][open];

        if(s[i] == '(')
            return dp[i][open] = solve(i + 1, open + 1, n, s, dp);

        if(s[i] == ')')
            return dp[i][open] = solve(i + 1, open - 1, n, s, dp);
    
        return dp[i][open] = solve(i + 1, open, n, s, dp) || solve(i + 1, open + 1, n, s, dp) || solve(i + 1, open - 1, n, s, dp);
    }
};

/*
open = 0

s - (, ), *
* - '', '(', ')'

(*)
        (
        |
        *
      / | \
    ""  (  )
    |   |  |
    )   )  )
*/