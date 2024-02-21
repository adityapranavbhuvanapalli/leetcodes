class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;

        for(int i=31; i>=0 ; i--) {
            if((left >> i) == (right >> i)) {
                res = (res << 1) | (left >> i);
            } else {
                res = (res << 1);
            }
        }

        return res;
    }
};

/*
101
111


10001
11100
*/