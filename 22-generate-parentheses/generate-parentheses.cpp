class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        generate(0, 0, "", n);
        return res;
    }

    void generate(int open, int close, string comb, int n) {
        if(close == n) 
            res.push_back(comb);

        // Cases:
        // 1. add ( to comb if open < n
        // 2. add ) to comb if open > close
        if(open < n)
            generate(open + 1, close, comb + '(', n);

        if(open > close)
            generate(open, close + 1, comb + ')', n);
    }
};

/*
open, close

------
(((
  )
 )(


*/