class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string comb = "";
        solve(0, 0, n, comb);
        return res;
    }

    void solve(int open, int close, int n, string comb) {
        if(close == n) {
            res.push_back(comb);
            return;
        }

        if(open < n)
            solve(open + 1, close, n, comb + '(');

        if(close < open)
            solve(open, close + 1, n, comb + ')');
    }
};