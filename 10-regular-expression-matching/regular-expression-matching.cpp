class Solution {
public:
    map<pair<int, int>, int> dp;
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        return solve(0, 0, ns, np, s, p);    
    }

    bool solve(int i, int j, int ns, int np, string& s, string& p) {
        if(j == np)
            return i == ns;

        if(dp.count({i, j}) == 1)
            return dp[{i, j}];

        bool match = (p[j] == '.' || s[i] == p[j]);

        if(j + 1 < np && p[j + 1] == '*') 
            return (i < ns && match && solve(i+1, j, ns, np, s, p)) || solve(i, j+2, ns, np, s, p); 
             
        return dp[{i, j}] = i < ns && match && solve(i+1, j+1, ns, np, s, p);
    }
}; 

/*
aa
a

a*
a

check match
check for next char 
if * is there
    1. solve for i, j+2
    2. solve for i+1, j if match

solve(i+1, j+1) if match
*/