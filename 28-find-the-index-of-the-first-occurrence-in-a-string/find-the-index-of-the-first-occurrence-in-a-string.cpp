class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size(), n = haystack.size();
        int i, j, prevlps;
        vector<int> lps(m, 0);

        // Pre Processing
        prevlps = 0, i = 1;
        while(i < m) {
            if(needle[i] == needle[prevlps]) {
                lps[i] = prevlps + 1;
                prevlps = lps[i];
                i++;
            } else {
                if(prevlps == 0) {
                    i++;
                } else {
                    prevlps = lps[prevlps - 1];
                }
            }
        }

        // Matching
        i = 0, j = 0;
        while(i < n) {
            if(haystack[i] == needle[j]) {
                i++, j++;
            } else {
                if(j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }

            if(j == m)
                return i - m;
        }

        return -1;
    }
};