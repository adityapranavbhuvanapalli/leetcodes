class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for(int i=1; i<=n/2; i++) {
            if(&s[i] + s.substr(0, i) == s)
                return true;
        }

        return false;
    }
};

/*
abab

aba

ab + abababab == ababababab
return true
*/