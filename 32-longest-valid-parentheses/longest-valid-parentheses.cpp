class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int open = 0, close = 0, res = 0;

        for(int i=0; i<n; i++) {
            open += (s[i] == '(');
            close += (s[i] == ')');

            if(open == close) 
                res = max(res, open + close);

            if(open < close)
                open = close = 0;
        }

        open = close = 0;
        for(int i=n-1; i>=0; i--) {
            open += (s[i] == ')');
            close += (s[i] == '(');

            if(open == close) 
                res = max(res, open + close);

            if(open < close)
                open = close = 0;
        }

        return res;
    }
};

/*
(()

open = 1
open = 2
close = 1
*/