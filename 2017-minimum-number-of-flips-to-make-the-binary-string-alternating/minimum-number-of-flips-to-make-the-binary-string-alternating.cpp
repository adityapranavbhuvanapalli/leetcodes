class Solution {
public:
    int minFlips(string s) {
        int l = 0, n = s.size(), minVal = n, count1 = 0, count2 = 0;
        char a = '1', b = '0';

        for(int r=0; r<2*n; r++) {
            count1 += (s[r % n] != a);
            count2 += (s[r % n] != b);
            
            if(r - l + 1 > n) {
                if(n % 2 == 0) {
                    count1 -= (s[l % n] != a);
                    count2 -= (s[l % n] != b);
                } else {
                    count1 -= (s[l % n] != b);
                    count2 -= (s[l % n] != a);
                }
                l++;
            }

            if(r - l + 1 == n)
                minVal = min({minVal, count1, count2});

            swap(a, b);
        }
 
        return minVal;
    }
};

/*
01001001101 01001001101
01010101010 10101010101
-----------------------
11100011000 00011100111
12333345555

00011100111 11100011000
*/