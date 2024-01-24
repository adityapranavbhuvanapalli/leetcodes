class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, n = s.size(), count = 0, minLen = INT_MAX, start = -1;
        vector<int> freqS(256, 0), freqT(256, 0);

        for(const auto& ch: t)
            freqT[ch]++;

        for(const auto& x: freqT)
            count += (x > 0);

        while(r < n) {
            
            freqS[s[r]]++;
            if(freqS[s[r]] == freqT[s[r]])
                count--;
            r++;

            while(l < r && count == 0) {
                if(minLen > r - l) {
                    start = l;
                    minLen = r - l;
                }

                if(freqS[s[l]] == freqT[s[l]])
                    count++;
                freqS[s[l]]--;
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

/*
ABC

ADOBECODEBANC
-l
----------r
*/