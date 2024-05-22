class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> comb;
        backtrack(0, s.size(), s, comb);
        return res;
    }

    void backtrack(int start, int n, string& s, vector<string>& comb) {
        if(start == n) {
            res.push_back(comb);
            return;
        }

        for(int i=start; i<n; i++) {
            if(isPalindrome(start, i, s)) {
                comb.push_back(s.substr(start, i-start+1));
                backtrack(i+1, n, s, comb);
                comb.pop_back();
            }
        }
    }

    bool isPalindrome(int l,int r, string& s){
        while(l <= r){
            if(s[l++] != s[r--]) 
                return false;
        }
        return true;
    }
};