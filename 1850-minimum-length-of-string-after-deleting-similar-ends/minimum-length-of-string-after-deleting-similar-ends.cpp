class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), l = 0, r = n - 1;

        while(l < r) {
            if(s[l] != s[r])
                break;

            char c = s[l];
            while(l <= r && c == s[l]) {
                l++;
            }

            while(l <= r && c == s[r]) {
                r--;
            }
        }

        return r - l + 1;
    }
};

/*
aabaaabba
    l       
     r
*/