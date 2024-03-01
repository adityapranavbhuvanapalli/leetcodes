class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size(), l = 0;

        int i = n - 2;
        while(i >= 0 && s[n - 1] == '0') {
            swap(s[n - 1], s[i]);
            i--;
        }

        while(i > l) {
            if(s[l] == '1') {
                l++;
                continue;
            }

            if(s[i] == '1') {
                swap(s[l++], s[i]);
            }

            i--;    
        }

        return s;
    }
};

/*
0101
*/