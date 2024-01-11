class Solution {
public:
    vector<vector<int>> dp;
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        dp = vector<vector<int>>(ns+1, vector<int>(np+1, -1));
        return solve(0, 0, ns, np, s, p);
    }

    bool solve(int i, int j, int ns, int np, string& s, string& p) {
        if(j == np)
            return (i == ns);

        if(dp[i][j] != -1)
            return dp[i][j];

        if(p[j] == '*') {
            // Either consider 1 or consider none
            return dp[i][j] = (i < ns && solve(i+1, j, ns, np, s, p)) || solve(i, j+1, ns, np, s, p);
        }

        return dp[i][j] = i < ns && (s[i] == p[j] || p[j] == '?') && solve(i+1, j+1, ns, np, s, p); 
    }
};