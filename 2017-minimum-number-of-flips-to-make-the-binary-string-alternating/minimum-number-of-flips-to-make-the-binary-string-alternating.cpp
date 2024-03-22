class Solution {
public:
    int minFlips(string s) {
        int l = 0, n = s.size(), minVal = n, count1 = 0, count2 = 0;
        char a = '1', b = '0';

        s += s;
        for(int r=0; r<2*n; r++) {
            count1 += (s[r] != a);
            count2 += (s[r] != b);

            // cout<<l<<" "<<r<<": "<<count1<<" "<<count2<<endl;
            // cout<<(s[r]!=a);
            // cout<<count1;
            
            if(r - l + 1 > n) {
                if(n % 2 == 0) {
                    count1 -= (s[l] != a);
                    count2 -= (s[l] != b);
                } else {
                    count1 -= (s[l] != b);
                    count2 -= (s[l] != a);
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