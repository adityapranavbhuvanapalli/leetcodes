class Solution {
public:
    int numSplits(string s) {
        int n = s.size(), countL = 0, countR = 0, res = 0;
        vector<int> freqL(26, 0), freqR(26, 0);

        for(const auto& ch: s) {
            freqR[ch - 'a']++;
            if(freqR[ch - 'a'] == 1) {
                countR++;
            }
        }

        for(const auto& ch: s) {
            freqL[ch - 'a']++;
            freqR[ch - 'a']--;

            if(freqL[ch - 'a'] == 1) {
                countL++;
            }

            if(freqR[ch - 'a'] == 0) {
                countR--;
            }

            // Parse till half
            if(countL > countR)
                break;

            // If count of distinct chars is equal to half of total distinct chars
            if(countL == countR) {
                res++;
            }
        }

        return res;
    }
};

/*
aacaba

aac aba
aaca ba
*/