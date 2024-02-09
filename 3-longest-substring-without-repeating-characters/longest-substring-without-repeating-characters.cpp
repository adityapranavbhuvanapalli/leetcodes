class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size(), maxLen = 0;
        vector<bool> found(256, 0);
        while(r < n) {
            while(found[s[r]]) {
                found[s[l]] = false;
                l++;
            }

            found[s[r]] = true;
            maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};