class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), maxLen = 0;

        for(char ch = 'A'; ch <= 'Z'; ch++) {
            int l = 0;
            for(int r=0; r<n; r++) {
                k -= (s[r] != ch);

                while(k < 0) {
                    k += (s[l] != ch);
                    l++;
                } 

                maxLen = max(maxLen, r - l + 1);
            } 

            while(l < n) {
                k += (s[l] != ch);
                l++;
            }
        }   

        return maxLen;
    }
};

/*
ABAB
l
   r

AABABBA
     l
      r
*/