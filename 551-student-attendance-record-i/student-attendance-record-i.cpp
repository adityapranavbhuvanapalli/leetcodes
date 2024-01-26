class Solution {
public:
    bool checkRecord(string s) {
        int aCount = 0, n = s.size();
        for(int i=0; i<n; i++) {
            aCount += (s[i] == 'A');

            if(aCount >= 2)
                return false;

            if(i > 1 && s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L')
                return false;
        }

        return true;
    }
};