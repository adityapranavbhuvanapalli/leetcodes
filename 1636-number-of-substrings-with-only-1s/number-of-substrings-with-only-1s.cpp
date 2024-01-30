class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSub(string s) {
        int res = 0, count = 0;
        s += '0';

        for(const auto& ch: s) {
            if(ch == '0') {
                count = 0;
                continue;
            }
            count = (count + 1) % MOD;
            res = (res + count) % MOD;
        }

        return res;
    }
};

/*
1
 1
11 - 3

1
 1
  1
11
 11
111 - 6

1
 1
  1
   1
11
 11
  11
111
 111
1111 - 10
*/