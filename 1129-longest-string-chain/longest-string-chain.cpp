class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(), maxLen = 1;
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), [&](auto& l, auto& r) {
            return l.size() == r.size() ? l < r : l.size() < r.size();
        });

        for(int i=0; i<n; i++) {
            int j = i - 1;
            while(j >= 0 &&words[i].size() == words[j].size())
                j--;
            
            while(j >= 0) {
                if(words[i].size() - words[j].size() != 1)
                    break;

                if(isParent(words[i], words[j]))
                    dp[i] = max(dp[i], 1 + dp[j]);

                j--;
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }

    bool isParent(string& s, string& t) {
        int i = 0, j = 0, mismatch = 0, n = s.size();

        for(int i=0; i<n; i++) {
            if(s[i] == t[j]) {
                j++;
                continue;
            }

            if(mismatch++ > 0)
                return false;
        }

        return true;
    }
};