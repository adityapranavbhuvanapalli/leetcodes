class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size(), len = 0, maxLen = 0;
        vector<bool> freq(256, 0);
        while(r < n) {
            while(freq[s[r]]) {
                freq[s[l]] = 0;
                l++;
            }

            freq[s[r]] = 1;
            maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};