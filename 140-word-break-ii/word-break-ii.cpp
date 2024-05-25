class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        return solve(0, n, s, wordDict);
    }
    
    vector<string> solve(int i, int n, string& s, vector<string>& dict) {
        if(i >= n)
            return {""};

        vector<string> res;
        for(const auto& word: dict) {
            if(i + word.size() <= n) {
                string prefix = s.substr(i, word.size());
                vector<string> parts;
                if(word != prefix) 
                    continue;

                parts = solve(i + word.size(), n, s, dict);

                for(const auto& part: parts) {
                    if(part == "")
                        res.push_back(prefix);
                    else
                        res.push_back(prefix + " " + part);
                }
            }
        }

        return res;
    }
};