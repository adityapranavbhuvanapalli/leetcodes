class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string comb = "";
        solve(0, 0, n, comb);
        return res;
    }

    void solve(int open, int close, int n, string& comb) {
        if(close == n) {
            res.push_back(comb);
            return;
        }

        if(open < n) {
            comb += '(';
            solve(open + 1, close, n, comb);
            comb.pop_back();
        }

        if(close < open) {
            comb += ')';
            solve(open, close + 1, n, comb);
            comb.pop_back();
        }
    }
};