class Solution {
public:
    int start = 0, maxLen = 1;
    string longestPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            solve(i, i, n, s);
            if (i < n - 1 && s[i] == s[i + 1])
                solve(i, i + 1, n, s);
        }

        return s.substr(start, maxLen);
    }

    void solve(int l, int r, int n, string& s) {
        while (l > 0 && r < n - 1 && s[l - 1] == s[r + 1]) {
            l--, r++;
        }

        if (r - l + 1 > maxLen) {
            start = l;
            maxLen = r - l + 1;
        }
    }
};