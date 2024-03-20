class Solution {
public:
    int characterReplacement(string s, int K) {
        int n = s.size(), maxVal = 0;

        for(char ch='A'; ch<='Z'; ch++) {
            int k = K, l = 0;
            for(int r=0; r<n; r++) {
                k -= (s[r] != ch);

                while(k < 0)
                    k += (s[l++] != ch);

                maxVal = max(maxVal, r - l + 1);
            } 
        }
        
        return maxVal;
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