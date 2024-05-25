class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<string>> dp(n);
        return solve(0, n, s, wordDict, dp);
    }
    
    vector<string> solve(int i, int n, string& s, vector<string>& dict, vector<vector<string>>& dp) {
        if(i >= n)
            return {""};

        // if(dp[i].size())
        //     return dp[i];

        vector<string> res;
        for(const auto& word: dict) {
            if(i + word.size() <= n) {
                string prefix = s.substr(i, word.size());
                vector<string> parts;
                if(word != prefix) 
                    continue;

                parts = solve(i + word.size(), n, s, dict, dp);

                for(const auto& part: parts) {
                    if(part == "")
                        res.push_back(prefix);
                    else
                        res.push_back(prefix + " " + part);
                }
            }
        }

        return dp[i] = res;
    }
};