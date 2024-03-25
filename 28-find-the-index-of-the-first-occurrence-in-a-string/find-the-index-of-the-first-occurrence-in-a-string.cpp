class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size(), n = haystack.size();
        int i, j, prevlps;
        vector<int> lps(m, 0);

        // Pre-processing
        // Find for each i, from 0 to i, the longest common prefix which is also a suffix
        i = 1, prevlps = 0;
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

        // Compare
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

            if(j == m) {
                j = lps[j - 1];
                return i - m;
            }
        }
    
        return -1;
    }
};  

/*
 p
abcdab
     i
000012

p
ab
 i
0
*/