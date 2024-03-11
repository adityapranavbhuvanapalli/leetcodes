class Solution {
public:
    map<pair<int, int>, int> dp; 
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        return solve(0, 0, sLen, pLen, s, p);
    }

    bool solve(int i, int j, int sLen, int pLen, string& s, string& p) {
        if(dp.count({i, j}) == 1)
            return dp[{i, j}];

        if(j == pLen)
            return dp[{i, j}] = (i == sLen);

        bool match = i<sLen && (s[i] == p[j] || p[j] == '.');

        if(j+1 < pLen && p[j+1] == '*') 
            return dp[{i, j}] = solve(i, j+2, sLen, pLen, s, p) 
                || (match && solve(i+1, j, sLen, pLen, s, p));

        return dp[{i, j}] = (match && solve(i+1, j+1, sLen, pLen, s, p));       
    }
};