class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> match1 = kmp(s, a);
        vector<int> match2 = kmp(s, b);  
        vector<int> res;

        int i = 0, j = 0, n = s.size();

        for(int i=0; i<n; i++) {
            if(match1[i] == 0)
                continue;

            for(int j=max(0, i-k); j<=min(n-1, i+k); j++) {
                if(match2[j] == 1) {
                    res.push_back(i);
                    break;
                }
            }
        }
 
        return res;
    }

    vector<int> kmp(string& haystack, string& needle) {
        needle += '-';
        int m = needle.size(), n = haystack.size();
        int i, j, prevlps;
        vector<int> res(n, 0);
        vector<int> lps(m, 0);

        prevlps = 0, i = 1;
        while(i < m) {
            if(needle[i] == needle[prevlps]) {
                lps[i] = prevlps + 1;
                prevlps = lps[i];
                i++;
            } else {
                if(prevlps == 0)
                    i++;
                else
                    prevlps = lps[prevlps - 1];
            }
        }

        i = j = 0;
        while(i < n) {
            if(haystack[i] == needle[j]) {
                i++, j++;
            } else {
                if(j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }

            if(j == m-1) {
                // j = lps[j - 1];
                res[i - m + 1] = 1;
            }
        }

        return res;
    }
};

/*
abcabcabcaabc
0001234561123
*/